/**********************************************************************************
* Random Quote Script for the JH website
*
* Author: Joseph Healy
* Last Updated: 27/03/2023
*
*
**********************************************************************************/

const api_url ="https://corsanywhere.herokuapp.com/https://zenquotes.io/api/today/";


async function getapi(url)
{
    const response = await fetch(url);
    const data = await response.json();   

    /* From our url fetch we are returned a JSONObject, from there we can,
    *  grab the data inside of section '0', mainly q (the quote) and a (the author).
    */
    const quote = data[0].q;
    const author = data[0].a;
    const fullQuote = quote + " - " + author;

    document.getElementById("quote").innerHTML = fullQuote;
}

getapi(api_url)