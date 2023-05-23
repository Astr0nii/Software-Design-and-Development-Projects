



let bread = 0;
let money = 0;
let moneyMulti = 1;

document.addEventListener("DOMContentLoaded", function(){
    const breadButton = document.getElementById("breadMaker");
    const moneyButton = document.getElementById("moneyMaker");

    gameLoop();
    breadButton.addEventListener("click", function() {
        console.log("Bread Pressed!");
        bread += 1;
        updateVals();
    });

    moneyButton.addEventListener("click", function() {
        if (bread != 0) {
            console.log("Money Pressed!");
            bread -= 1;
            money += Math.round(((1 + moneyMulti) * 100) /100);
            console.log(money);
            updateVals();
            moneyMulti = (Math.random() * (1, 1.5) + 1).toFixed(2);
        }
        else {
            console.log("NOT ENOUGH BREAD IDOT!")
        }
        
    });
});

function gameLoop() {

    updateVals();

    setTimeout(() => {
        gameLoop();
    }, 250);
}

function updateVals() {
    const breadText = document.getElementById("bread");
    const moneyText = document.getElementById("money");
    const sellRate = document.getElementById("sellRate");
    const breadAdded = document.getElementById("breadAdded");
    const moneyAdded = document.getElementById("moneyAdded");

    sellRate.innerHTML = moneyMulti;
    moneyText.innerHTML = '$' + money;
    breadText.innerHTML = bread;
    breadAdded.innerHTML = '+' + 1;
    moneyAdded.innerHTML = '+' + money;
}
