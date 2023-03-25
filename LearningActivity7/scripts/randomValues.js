const randomColour = ['#e23500', '#00d3e2', '#e2a600', '#00e24b', '#8f00e2', '#cc7f19', '#cc19c3'];

const choosenColour = randomColour[Math.floor(Math.random() * randomColour.length)];


if (document.getElementById("choosenColour"))
{
    const colourWord = document.getElementById("choosenColour");
    colourWord.style.color = choosenColour;
}


