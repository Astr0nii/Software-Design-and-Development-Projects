/**********************************************************************************
* 3D Hover effect for the JH website
*
* Author: Joseph Healy
* Last Updated: 27/03/2023
*
*
**********************************************************************************/

const tiltEffectSettings = {
    maxTilt: 10, // The maximum tilt in degrees.
    perspective: 62.5, // The REM value of our card's 3D perspective. Must match our value in style.css
    scale: 1.15, // Our card's scale on hover
    speed: 500, // How fast in MS should our transition be?
    easing: "cubic-bezier(0.03, 0.98, 0.52, 0.99)" // Easing property yoinked from tiltjs :)
};

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
    