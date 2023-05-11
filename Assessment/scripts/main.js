const randomWords = ['perfect', 'extravagant', 'amazing', 'spectacular', 'excellent', 'brilliant', 'inspirational',
                    'striking', 'eye-catching', 'breathtaking', 'glorious', 'flawless', 'complete', 'dazzling',
                    'clever', 'creative', 'marvellous', 'superb', 'outstanding', 'wonderful', 'innovative', 
                    'elegant', 'precisely crafted', 'fresh', 'forward-thinking', 'remarkable', 'sublime', 'polished',
                    'stunning', 'impressive', 'gorgeous', 'refined'];

const introPhrases = ["How do you do", "G'day", "Welcome", "Nice to meet you", "Looking great today", "Hi",
                     "Hi there", "Today is the day", "Feed your curiosity", "New dawn, new day"];

let request = indexedDB.open('usernameStorage', 1);
let username;
let i = -1;

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
            storeUser(" " + document.getElementById("name").value);
            document.location.href = "../index.html";
        });
        document.getElementById("noNameButton").addEventListener("click", function() {
            event.preventDefault();
            storeUser("");
            document.location.href = "../index.html";
        });
        fadeText(["welcomeText", "welcomeText2", "welcomeText3", "welcomeText4", "welcomeText5"])
    }
});

// Function for storing a username
function storeUser(username) {
    const db = request.result;
    const transaction = db.transaction('users', 'readwrite');
    const usersObjectStore = transaction.objectStore('users');
    usersObjectStore.put({ id: 1, username });

}

// Function for grabbing a username
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


// Function for fading an array of elements
function fadeText(elements) {
    
    function nextElement() {
        console.log(i);
        let randElement = document.getElementById(elements[i]);
        let opacity = 0;

        console.log("Fading element:", randElement);
        const inInterval = setInterval(() => {
            if (opacity >= 1) {
                console.log("done");
                clearInterval(inInterval);
            }
            else {
                console.log("fade in");
                opacity += 0.025;
                randElement.style.opacity = opacity;
            }
        }, 50);
    
        setTimeout(() => {
            const outInterval = setInterval(() => {
                if (opacity <= 0) {
                    console.log("done");
                    clearInterval(outInterval);
                }
                else {
                    console.log("fade out");
                    opacity -= 0.025;
                    randElement.style.opacity = opacity;
                }
            }, 50);
            fadeText(elements);
        }, 4000);
    }
    setTimeout(() => {
        i++;
        nextElement();
    }, 2500);
}
