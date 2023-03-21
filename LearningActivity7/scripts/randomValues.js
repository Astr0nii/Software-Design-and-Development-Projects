var randomWords = ['perfect', 'extravagant', 'amazing', 'spectacular', 'excellent', 'brilliant', 'inspirational',
                    'striking', 'eye-catching', 'breathtaking', 'glorious', 'flawless', 'complete', 'dazzling',
                    'clever', 'creative', 'marvellous', 'superb', 'outstanding', 'wonderful', 'innovative'];
var randomColour = ['#e23500', '#00d3e2', '#e2a600', '#00e24b', '#8f00e2', '#cc7f19', '#cc19c3'];

var choosenWord = randomWords[Math.floor(Math.random() * randomWords.length)];
var choosenColour = randomColour[Math.floor(Math.random() * randomColour.length)];

if (document.getElementById("choosenWord"))
{
    var colourWord = document.getElementById("choosenWord");
    colourWord.style.color = choosenColour;
    document.getElementById("choosenWord").innerHTML = choosenWord;
}
else if (document.getElementById("choosenColour"))
{
    var colourWord = document.getElementById("choosenColour");
    colourWord.style.color = choosenColour;
}


