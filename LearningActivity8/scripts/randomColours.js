/**********************************************************************************
* Random Quote Script for the JH website
*
* Author: Joseph Healy
* Last Updated: 27/03/2023
*
*
**********************************************************************************/

const randomColours = [];
const colouredElement = document.querySelectorAll(".colouredText");
const numOfColours = 6;

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

document.addEventListener("DOMContentLoaded", function() {
    colourElements();
});