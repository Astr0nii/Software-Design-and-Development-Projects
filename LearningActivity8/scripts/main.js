/**********************************************************************************
* main js file for the JH website
*
* Author: Joseph Healy
* Last Updated: 31/03/2023
*
* TODO:
* The typing effect replay on hover triggers whenever the user hovers over,
* I want a delay so they cannot spam it.
*
**********************************************************************************/

const tiltEffectSettings = {
    maxTilt: 10, // The maximum tilt in degrees.
    perspective: 62.5, // The REM value of our card's 3D perspective. Must match our value in style.css
    scale: 1.15, // Our card's scale on hover
    speed: 500, // How fast in MS should our transition be?
    easing: "cubic-bezier(0.03, 0.98, 0.52, 0.99)" // Easing property yoinked from tiltjs :)
};


// Random colour variables
const randomColours = [];
const colouredElement = document.querySelectorAll(".colouredText");
const numOfColours = 6;

// Typing Effect Variables
const randomWords = ['perfect', 'extravagant', 'amazing', 'spectacular', 'excellent', 'brilliant', 'inspirational',
                    'striking', 'eye-catching', 'breathtaking', 'glorious', 'flawless', 'complete', 'dazzling',
                    'clever', 'creative', 'marvellous', 'superb', 'outstanding', 'wonderful', 'innovative', 
                    'powered by ego', 'precisely crafted', 'fresh', 'forward-thinking'];

const typedWordSpan = document.querySelectorAll(".colouredText");
const cursorSpan = document.querySelector(".cursor");

const typingSettings = {
    typingDelay: 150, // time to type word
    erasingDelay: 100, // time to erase word
    newWordDelay: 3000 // time before word is replaced
} 
let charIndex = 0; // character index of currently selected word
let wordIndex = 0; // word index of currently selected word


window.onload = function() {
    const cards = document.querySelectorAll(".card");

    // Cool little function to loop through every card and apply this effect.
    cards.forEach((card) => {
        
        // Adding a mouse move, leave and enter listener and getting the exact size of our card.
        card.addEventListener("mouseenter", cardMouseEnter);
        card.addEventListener("mousemove", cardMouseMove);
        card.addEventListener("mouseleave", cardMouseLeave);
        

        function cardMouseMove(event) {

            // Boring variables to get; our card's centre, mouse coords and rotation angle.
            const cardBound = card.getBoundingClientRect();
            const cardWidth = card.offsetWidth;
            const cardHeight = card.offsetHeight;
            const centerX = cardBound.left + cardWidth / 2;
            const centerY = cardBound.top + cardHeight / 2;
            const mouseX = event.clientX - centerX;
            const mouseY = event.clientY - centerY;
            const rotateX = (1* tiltEffectSettings.maxTilt * mouseY / (cardHeight / 2)).toFixed(2);
            const rotateY = (-1) * tiltEffectSettings.maxTilt * mouseX / (cardWidth / 2).toFixed(2);

            // Here we do the cool transformation process using all of our juicy calculations above.
            card.style.transform = `perspective(${tiltEffectSettings.perspective}rem) rotateX(${rotateX}deg) rotateY(${rotateY}deg) 
                                    scale3d(${tiltEffectSettings.scale}, ${tiltEffectSettings.scale}, ${tiltEffectSettings.scale})`;
        }

        function cardMouseEnter(event) {
            setTransition();
        }

        function cardMouseLeave(event) {
            card.style.transform = `perspective(${tiltEffectSettings.perspective}rem) rotateX(0deg) rotateY(0deg) scale3d(1, 1, 1)`
            setTransition();
        }

        // Handling animation stuff for when the mouse enters/exits the card
        function setTransition() {
            clearTimeout(card.transitionTimeoutId);
            card.style.transition = `transform ${tiltEffectSettings.speed}ms ${tiltEffectSettings.easing}`;
            card.transitionTimeoutId = setTimeout(() => {
                card.style.transition = "";
            }, tiltEffectSettings.speed);
        }
    });
};


// Function to get a set number of random colour and add them to an array
function colourElements() {
    var newColour = '#';
    if (randomColours.length < numOfColours) {
        for(i=0;i<6;i++) {
            newColour += Math.floor((Math.random() * 7) + 3);
        }
        randomColours.push(newColour);
        colourElements();
    }
    for (i=0;i<colouredElement.length;i++) {
        colouredElement[i].style.color = randomColours[Math.floor(Math.random() * randomColours.length)];
    }
}


// Typing Function for typing effect
function type() {
    if (charIndex < randomWords[wordIndex].length) {
        if(!cursorSpan.classList.contains("typing")) cursorSpan.classList.add("typing");
        typedWordSpan.forEach(function(span) {
            span.textContent += randomWords[wordIndex].charAt(charIndex);
        });
        charIndex++;
        
        setTimeout(type, typingSettings.typingDelay);
    }
    else {
        cursorSpan.classList.remove("typing");
        cursorSpan.classList.add("notTyping");
    }
}


// Erasing Function for typing effect
function erase() {
    cursorSpan.classList.remove("notTyping");
    if(charIndex > 0) {
        
        if(!cursorSpan.classList.contains("typing")) cursorSpan.classList.add("typing");
        typedWordSpan.forEach(function(span) {
            span.textContent = randomWords[wordIndex].substring(0, charIndex-1);
        });
        charIndex--;
        setTimeout(erase, typingSettings.erasingDelay);
    }
    else {
        require('./randomColours.js');
        cursorSpan.classList.remove("typing");
        wordIndex = Math.floor(Math.random() * randomWords.length);
        setTimeout(type, typingSettings.newWordDelay);
    }
}

// A function that yoinks quotes from an API
async function getAPI()
{
    const api_url ="https://corsanywhere.herokuapp.com/https://zenquotes.io/api/today/";
    const response = await fetch(api_url);
    const data = await response.json();   

    /* From our url fetch we are returned a JSONObject, from there we can,
    *  grab the data inside of section '0', mainly q (the quote) and a (the author).
    */
    const quote = data[0].q;
    const author = data[0].a;
    const fullQuote = quote + " - " + author;

    document.getElementById("quote").innerHTML = fullQuote;
}

// Add an event listener to play the typing effect when the user hovers over.
typedWordSpan.forEach(function(span) {
    span.addEventListener("mouseover", event => {
        erase();
    });
});