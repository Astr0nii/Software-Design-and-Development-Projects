const randomWords = ['perfect', 'extravagant', 'amazing', 'spectacular', 'excellent', 'brilliant', 'inspirational',
                    'striking', 'eye-catching', 'breathtaking', 'glorious', 'flawless', 'complete', 'dazzling',
                    'clever', 'creative', 'marvellous', 'superb', 'outstanding', 'wonderful', 'innovative', 
                    'elegant', 'precisely crafted', 'fresh', 'forward-thinking', 'remarkable', 'sublime', 'polished',
                    'stunning', 'impressive', 'gorgeous', 'refined'];

const introPhrases = ["How do you do", "G'day", "Welcome", "Nice to meet you", "Looking great today", "Hi",
                     "Hi there", "Today is the day", "Feed your curiosity", "New dawn, new day"];


// Random colour variables
const randomColours = [];
const numOfColours = 10;
const colouredElement = document.getElementsByClassName("colouredText");

document.addEventListener("DOMContentLoaded", function() {
    if (document.title == "Astron") {
        colourElements();
        document.getElementById("choosenWord").innerHTML = randomWords[Math.floor(Math.random() * randomWords.length)];
        document.getElementById("introduction").innerHTML = introPhrases[Math.floor(Math.random() * introPhrases.length)];

        // Add an event listener to change the colour of our random word when hovered over
        for(i=0;i<colouredElement.length;i++) {
            colouredElement[i].addEventListener("mouseover", function() { 
                colourElements();
            });
        }
    }
});

// Random Colour Function grabbed from my previous website
function colourElements() {
    var newColour = '#';
    for(i=0;i<6;i++) {
        newHexValue = Math.floor(Math.random() * 15 + 1);
        switch (newHexValue) {
            case 10:
                newHexValue = 'A'
                break;
            case 11:
                newHexValue = 'B'
                break;
            case 12:
                newHexValue = 'C'
                break;
            case 13:
                newHexValue = 'D'
                break;
            case 14:
                newHexValue = 'E'
                break;
            case 15:
                newHexValue = 'F'
                break;
            default:
                break;
        }
        newColour += newHexValue;
    }
    randomColours.push(newColour);

    for (i=0;i<colouredElement.length;i++) {
        colouredElement[i].style.color = randomColours[Math.floor(Math.random() * randomColours.length)];
    }
}



