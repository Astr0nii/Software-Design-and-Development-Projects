const randomWords = ['perfect', 'extravagant', 'amazing', 'spectacular', 'excellent', 'brilliant', 'inspirational',
                    'striking', 'eye-catching', 'breathtaking', 'glorious', 'flawless', 'complete', 'dazzling',
                    'clever', 'creative', 'marvellous', 'superb', 'outstanding', 'wonderful', 'innovative', 
                    'elegant', 'precisely crafted', 'fresh', 'forward-thinking', 'remarkable', 'sublime', 'polished',
                    'stunning', 'impressive', 'gorgeous', 'refined'];

const introPhrases = ["How do you do", "G'day", "Welcome", "Nice to meet you", "Looking great today", "Hi",
                     "Hi there", "Today is the day", "Feed your curiosity", "New dawn, new day"];

let request = indexedDB.open('usernameStorage', 1);
let username;

request.onupgradeneeded = function() {
    const db = request.result;
    if (!db.objectStoreNames.contains('users')) {
        db.createObjectStore("users", { keyPath: 'id' });
    }
}

request.onsuccess = function() {
    db = request.result;
};

document.addEventListener("DOMContentLoaded", function() {
    if (document.title == "Astron") {
        getUser(function(username){
            document.getElementById("replaceName").innerHTML = username;
        });
        document.getElementById("choosenWord").innerHTML = randomWords[Math.floor(Math.random() * randomWords.length)];
        document.getElementById("introduction").innerHTML = introPhrases[Math.floor(Math.random() * introPhrases.length)];
    }
    else if (document.title == "Welcome to Astron") {
        document.getElementById("nameButton").addEventListener("click", function() {
            event.preventDefault();
            storeUser(document.getElementById("name").value);
            document.location.href = "../index.html";
        });
    }
});

function storeUser(username) {
    const db = request.result;
    const transaction = db.transaction('users', 'readwrite');
    const usersObjectStore = transaction.objectStore('users');
    usersObjectStore.put({ id: 1, username });

}

// Function for username storing
function getUser(callback) {
        request.onsuccess = function() {
            const db = request.result;
            const transaction = db.transaction('users', 'readonly');
            const usersObjectStore = transaction.objectStore('users');
            const getRequest = usersObjectStore.get(1);

            getRequest.onsuccess = function() {
                if (getRequest.result) {
                    username = getRequest.result.username;
                    callback(username);
                }
                else if (!getRequest.result && document.title != "Welcome to Astron") {
                        document.location.href = "pages/welcome.html";
                    } 
            }
        }
}
