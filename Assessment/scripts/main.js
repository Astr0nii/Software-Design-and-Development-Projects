const randomWords = ['perfect', 'extravagant', 'amazing', 'spectacular', 'excellent', 'brilliant', 'inspirational',
                    'striking', 'eye-catching', 'breathtaking', 'glorious', 'flawless', 'complete', 'dazzling',
                    'clever', 'creative', 'marvellous', 'superb', 'outstanding', 'wonderful', 'innovative', 
                    'elegant', 'precisely crafted', 'fresh', 'forward-thinking', 'remarkable', 'sublime', 'polished',
                    'stunning', 'impressive', 'gorgeous', 'refined'];

const request = indexedDB.open('usernameStorage');

document.addEventListener("DOMContentLoaded", function() {
    checkUser();
    if (document.title == "Astron") {
        document.getElementById("replaceName").innerHTML = "";
        document.getElementById("choosenWord").innerHTML = randomWords[Math.floor(Math.random() * randomWords.length)];
    }
    else if (document.title == "Welcome to Camden Learning!") {
        document.getElementById("nameButton").addEventListener("click", function() {
            event.preventDefault();
            storeUser(document.getElementById("name").value);
            checkUser();
        });
    }
});

function checkUser() {
    getUsername(username => {
        const uname = username;

        console.log("Checking username!")
        console.log(uname);

        if (uname != "" && document.title != "Astron") {
            console.log("Username found!");
            document.location.href = "../index.html";
        }
        else if (document.title != "Welcome to Astron") {
            console.log("Username not found!");
            document.location.href = "pages/welcome.html";
        }
    });
}

// Function for username storing
function storeUser(user) {

    // Creates an object store in the onupgradeneeded event handler
    request.onupgradeneeded = event => {
        const db = event.target.result;
        db.createObjectStore('users', { keypath: 'id' });
    };

    // Error handling when opening the database
    request.onerror = event => {
        console.error("Error opening databate:", event.target.error);
    };

    // Add our username to the database
    request.onsuccess = event => {
        const db = event.target.result;
        const transaction = db.transaction('users', 'readwrite');
        const usersObjectStore = transaction.objectStore('users');
        usersObjectStore.add({ id: 1, username: user });
    }

}

// Function for handling username fetching
function getUsername(callback) {

    // Check if our DB even exists
    request.onsuccess = event => {
        const db = event.target.result;
        if (db.objectStoreNames.contains('users')) {
            const db = event.target.result;
            const transaction = db.transaction('users', 'readonly');
            const usersObjectStore = transaction.objectStore('users');
            const getRequest = usersObjectStore.get(1);

            

            getRequest.onsuccess = event => {
                if (getRequest.result) {
                    callback(getRequest.result.username);
                }
                else {
                    switch(document.title) {
                        case "Astron":
                            console.log("Username not found!");
                            document.location.href = "pages/welcome.html";
                            break;
                        default:
                            break;
                    }
                }
            };
        }
    };
}
