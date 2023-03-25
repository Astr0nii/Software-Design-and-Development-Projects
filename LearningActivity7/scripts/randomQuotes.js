const api_url ="https://corsanywhere.herokuapp.com/https://zenquotes.io/api/today/";

async function getapi(url)
{
    const response = await fetch(url);
    var data = await response.json();   
    var quote = data[0].q;
    var author = data[0].a;
    var fullQuote = quote + " - " + author;
    document.getElementById("quote").innerHTML = fullQuote;
}

getapi(api_url)