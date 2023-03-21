const api_url ="https://corsanywhere.herokuapp.com/https://zenquotes.io/api/today/";

async function getapi(url)
{
    const response = await fetch(url);
    var data = await response.json();
    var quoteList = data['json:"q"'];
    console.log(data)
    console.log(quoteList)
}

getapi(api_url)