/**********************************************************************************
* Typing Effect Script for the JH website
*
* Author: Joseph Healy
* Last Updated: 27/03/2023
*
*
**********************************************************************************/

const randomWords = ['perfect', 'extravagant', 'amazing', 'spectacular', 'excellent', 'brilliant', 'inspirational',
                    'striking', 'eye-catching', 'breathtaking', 'glorious', 'flawless', 'complete', 'dazzling',
                    'clever', 'creative', 'marvellous', 'superb', 'outstanding', 'wonderful', 'innovative', 
                    'powered by ego', 'precisely crafted', 'fresh', 'forward-thinking'];
const randomColour = [];

const typedWordSpan = document.querySelectorAll(".colouredText");
const cursorSpan = document.querySelector(".cursor")

const typingSettings = {
    typingDelay: 150, // time to type word
    erasingDelay: 100, // time to erase word
    newWordDelay: 3000 // time before word is replaced
} 
let charIndex = 0; // character index of currently selected word
let wordIndex = 0; // word index of currently selected word


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
        setTimeout(erase, typingSettings.newWordDelay);
    }
}

function erase() {
    if(charIndex > 0) {
        if(!cursorSpan.classList.contains("typing")) cursorSpan.classList.add("typing");
        typedWordSpan.forEach(function(span) {
            span.textContent = randomWords[wordIndex].substring(0, charIndex-1);
        });
        charIndex--;
        setTimeout(erase, typingSettings.erasingDelay);
    }
    else {
        const choosenColour = randomColour[Math.floor(Math.random() * randomColour.length)];
        const colourWord = document.getElementById("choosenWord");
        colourWord.style.color = choosenColour;
        cursorSpan.classList.remove("typing");
        wordIndex = Math.floor(Math.random() * randomWords.length);
        setTimeout(type, typingSettings.newWordDelay - 500);
    }
}

document.addEventListener("DOMContentLoaded", function() {
    setTimeout(type, typingSettings.newWordDelay + 250);
})