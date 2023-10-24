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
const randWordElement = document.getElementsByClassName("choosenWord")
let colouredElement = document.getElementById("colouredText");

document.addEventListener("DOMContentLoaded", function() {
    if (document.title == "Astron") {
        colourElements();
        console.log(randWordElement.length);
        for (i=0;i<randWordElement.length;i++) {
            randWordElement[i].innerHTML = randomWords[Math.floor(Math.random() * randomColours.length)]
        }
        
        document.getElementById("introduction").innerHTML = introPhrases[Math.floor(Math.random() * introPhrases.length)];

        // Add an event listener to change the colour of our random word when hovered over
        colouredElement.addEventListener("mouseover", function() { 
            colourElements();
        });
    }
});

// Random Colour Function grabbed from my previous website
function colourElements() {
    var newColour = '#';
    for(i=0;i<6;i++) {
        newHexValue = Math.floor(Math.random() * 13 + 1);
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
            default:
                break;
        }
        newColour += newHexValue;
    }
    console.log("Colour:", newColour);

    colouredElement = document.getElementById("colouredText");

    colouredElement.style.transition = `1s ease-out`;
    colouredElement.style.color = newColour;
    
}
