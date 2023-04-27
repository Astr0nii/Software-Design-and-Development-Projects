const randomWords = ['perfect', 'extravagant', 'amazing', 'spectacular', 'excellent', 'brilliant', 'inspirational',
                    'striking', 'eye-catching', 'breathtaking', 'glorious', 'flawless', 'complete', 'dazzling',
                    'clever', 'creative', 'marvellous', 'superb', 'outstanding', 'wonderful', 'innovative', 
                    'elegant', 'precisely crafted', 'fresh', 'forward-thinking', 'remarkable', 'sublime', 'polished',
                    'stunning', 'impressive', 'gorgeous', 'refined'];


document.addEventListener("DOMContentLoaded", function() {
    document.getElementById("nameButton").addEventListener("click", function() {
        event.preventDefault();
        var username = document.getElementById("name").value;
        document.getElementById("replaceName").innerHTML = username;
        document.getElementById("fadingText").style.opacity = 1;
        document.getElementById("choosenWord").innerHTML = randomWords[Math.floor(Math.random() * randomWords.length)];
        document.getElementById("nameForm").remove();
    });
});
