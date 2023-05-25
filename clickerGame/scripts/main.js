// Dough vars
let dough = 0;
let doughAmountAdded = 6;
let doughCost = 2;

// Bread vars
let bread = 0;
let breadAmountAdded = 1;
let breadSellAmount = 1;

// Money vars
let money = 0;
let moneyAmountAdded = 1;
let moneyMulti = 1;
let moneyMultiUp = 1;

// Worker vars
let workerEFF = 0.5;
let doughWorkers = 0;
let breadWorkers = 0;
let moneyWorkers = 0;

document.addEventListener("DOMContentLoaded", function() {
    const buttonContain = document.getElementById("button-container");
    let upgrades = data.upgrades;

    function createButton(upgrade, container) {
        let button = document.createElement('button')
        button.setAttribute("data-unique-id", upgrade.id);
        button.textContent = 'UNLOCKED!';
        button.classList.add('button-container');
        setTimeout(function() {
            button.textContent = upgrade.name + ' - Cost: ' + upgrade.cost + '. Level: ' + upgrade.level;
        }, 500);
    
        button.addEventListener('click', function() {
            if (money >= upgrade.cost) {
                if (upgrade.type == "nonPerm" || "worker") {
                    upgrade.level += 1;
                    upgrade.effect();
                    getUpgrades();
                }
                else if (upgrade.type == "Perm") {
                    button.remove();
                    console.log("DIE:", button);
                    upgrade.level += 1;
                    upgrade.effect();
                    getUpgrades();
                }
                button.textContent = 'PURCHASED!';
            }
            else {
                console.log("BROKE MF");
            }
        });
    
        button.addEventListener('mouseover', function() {
            if (upgrade.type == 'worker') {
                button.innerHTML = upgrade.name + '<br>' + upgrade.description + '<br><br>New Worker Count: ' + upgrade.level + '>' + (upgrade.level+1);
            }
            else {
                button.innerHTML = upgrade.name + '<br>' + upgrade.description + '<br><br>New Level: ' + upgrade.level + '>' + (upgrade.level+1);
            }
        
        });
    
        button.addEventListener('mouseout', function() {
            button.textContent = upgrade.name + ' - Cost: ' + upgrade.cost + '. Level: ' + upgrade.level;
        });
    
        button.style.padding = '1.25rem';
        button.style.fontSize = '1rem';
        button.style.width = '20rem';
        button.style.textAlign = 'center';
        container.appendChild(button);
    }

    function getUpgrades() {
        for (let upgrade of upgrades) {
            let unlocked = true;
    
            if (upgrade.prereq.numOfPurchase == 0) {
                console.log(upgrade);
                console.log("No number of upgrades!");
                
            }
            else {
                for (let i=0;i<upgrade.prereq.numOfPurchase;i++) {
                    console.log("checking: ", upgrade);
                    console.log(i);
                    let prereqUpgrade = upgrades.find(u => u.name.toLowerCase() === upgrade.prereq.purchase[i].toLowerCase());
                    if (prereqUpgrade.level < upgrade.prereq.level) {
                        unlocked = false;
                    }
                }
            }
    
    
            let added = false;
            for (let child of buttonContain.children) {
                if (child.dataset.uniqueId == upgrade.id) {
                    added = true;
                    break;
                }
            }
    
    
            if (unlocked && !added) {
                if (upgrade.type == "Perm" && upgrade.level !== 1) {
                    createButton(upgrade, buttonContain);
                }
                else if (upgrade.type !== "Perm") {
                    createButton(upgrade, buttonContain);
                }
            }
        }
    }
    getUpgrades();

    const doughButton = document.getElementById("doughMaker");
    const breadButton = document.getElementById("breadMaker");
    const moneyButton = document.getElementById("moneyMaker");
    const doughAdded = document.getElementById("doughAdded");
    const breadAdded = document.getElementById("breadAdded");
    const moneyAdded = document.getElementById("moneyAdded");

    gameLoop();
    doughButton.addEventListener("click", function() {
        doughAdded.style.opacity = 1;
        dough += doughAmountAdded;
        setTimeout(function() {
            doughAdded.style.opacity = 0;
        }, 100);
        doughAdded.style.transition = `opacity 0.15s`
        doughAdded.innerHTML = ' +' + doughAmountAdded;
        updateVals();
    });

    breadButton.addEventListener("click", function() {
        breadAdded.style.opacity = 1;
        doughAdded.style.opacity = 1;
        if (dough - doughCost >= 0) {
            dough -= doughCost
            bread += breadAmountAdded;
        setTimeout(function() {
            breadAdded.style.opacity = 0;
            doughAdded.style.opacity = 0;
        }, 100);
        breadAdded.style.transition = `opacity 0.15s`
        doughAdded.style.transition = `opacity 0.15s`
        breadAdded.innerHTML = ' +' + breadAmountAdded;
        doughAdded.innerHTML = ' -' + doughCost;
        updateVals();
        }
        else {
            console.log("BROKE MF (in the dough department")
            breadAdded.style.opacity = 0;
            doughAdded.style.opacity = 0;
        }
    });

    moneyButton.addEventListener("click", function() {
        if (bread - breadSellAmount >= 0) {
            breadAdded.style.opacity = 1;
            moneyAdded.style.opacity = 1;
            bread -= breadSellAmount;
            const moneyToBe = (Math.round(((moneyAmountAdded * moneyMulti) * 100) / 100))*breadSellAmount;
            money += moneyToBe;
            updateVals();
            setTimeout(function() {
                moneyAdded.style.opacity = 0;
                breadAdded.style.opacity = 0;
            }, 100);
            moneyAdded.style.transition = `opacity 0.15s`
            breadAdded.style.transition = `opacity 0.15s`
            moneyAdded.innerHTML = ' +' + moneyToBe;
            breadAdded.innerHTML = ' -' + breadSellAmount;
            moneyMulti = (Math.random() * (0.8, 1.25) + moneyMultiUp).toFixed(2);
        }
        else {
            console.log("BROKE MF (in the bread department")
        }
        
    });
});

function gameLoop() {

    
    updateVals();
    updateWorkers();
    setTimeout(() => {
        gameLoop();
    }, 1000);
}

function updateVals() {
    const doughText = document.getElementById("dough");
    const breadText = document.getElementById("bread");
    const moneyText = document.getElementById("money");
    const sellRate = document.getElementById("sellRate");
    
    doughText.innerHTML = dough;
    sellRate.innerHTML = moneyMulti;
    moneyText.innerHTML = '$' + money;
    breadText.innerHTML = bread;
}

function updateWorkers() {
    // Dough worker logic
    if (doughWorkers > 0) {
        console.log("dough workers working");
        dough += Math.ceil(doughWorkers*(doughAmountAdded*workerEFF));
        doughAdded.style.opacity = 1;
        setTimeout(function() {
            doughAdded.style.opacity = 0;
        }, 100);
        doughAdded.style.transition = `opacity 0.15s`
        doughAdded.innerHTML = ' +' + Math.ceil(doughWorkers*(doughAmountAdded*workerEFF));
    }


    // Bread worker logic
    if (breadWorkers > 0) {
        console.log("bread workers working");
        breadAdded.style.opacity = 1;
        doughAdded.style.opacity = 1;
        if (dough - doughCost >= 0) {
            dough -= Math.ceil(breadWorkers*(doughCost*workerEFF));
            bread += Math.ceil(breadWorkers*(breadAmountAdded*workerEFF));
            setTimeout(function() {
                breadAdded.style.opacity = 0;
                doughAdded.style.opacity = 0;
            }, 100);
            breadAdded.style.transition = `opacity 0.15s`
            doughAdded.style.transition = `opacity 0.15s`
            breadAdded.innerHTML = ' +' + Math.ceil(breadWorkers*(breadAmountAdded*workerEFF));
            doughAdded.innerHTML = ' -' + doughCost;
        }
        else {
            breadAdded.style.opacity = 0;
            doughAdded.style.opacity = 0;
        }
    }
    

    // Money worker logic
    if (moneyWorkers > 0) {
        console.log("money workers working");
        breadAdded.style.opacity = 1;
        moneyAdded.style.opacity = 1;
        if (bread - breadSellAmount >= 0) {
            const moneyToBe = Math.ceil(moneyWorkers*(moneyAmountAdded));
            money += moneyToBe;
            bread -= Math.ceil(moneyWorkers*(breadSellAmount*workerEFF));
            setTimeout(function() {
                moneyAdded.style.opacity = 0;
                breadAdded.style.opacity = 0;
            }, 100);
            moneyAdded.style.transition = `opacity 0.15s`
            breadAdded.style.transition = `opacity 0.15s`
            moneyAdded.innerHTML = ' +' + moneyToBe;
            breadAdded.innerHTML = ' -' + breadSellAmount;
        }
        else {
            breadAdded.style.opacity = 0;
            moneyAdded.style.opacity = 0;
        }
    }
}




let data = {
    "upgrades": [
        {
            "name": "Larger Stan Mixer",
            "id": "largerstan",
            "description": "Increases the amount of dough you get.",
            "type": "nonPerm",
            "prereq": {
                "numOfPurchase": 0,
                "purchase": {
                    0:  "none"
                },
                "level": "none"
            },
            "level": 0,
            "cost": 25,
            "effect": function() { doughAmountAdded+=(1*this.level);money-=this.cost;this.cost=(this.cost*1.5).toFixed(2); }
        },
        {
            "name": "Larger Loaf Tin",
            "id": "largerloaf",
            "description": "Increases the amount of bread you get, at the cost of more dough",
            "type": "nonPerm",
            "prereq": {
                "numOfPurchase": 0,
                "purchase": {
                    0:  "none"
                },
                "level": "none"
            },
            "level": 0,
            "cost": 40,
            "effect": function() { breadAmountAdded+=(1*this.level);doughCost+=(2*this.level);money-=this.cost;this.cost=(this.cost*1.5).toFixed(2); }
        },
        {
            "name": "Better Sales Skills",
            "id": "bettersales",
            "description": "Increases the amount of bread you can sell at one time",
            "type": "nonPerm",
            "prereq": {
                "numOfPurchase": 0,
                "purchase": {
                    0:  "none"
                },
                "level": "none"
            },
            "level": 0,
            "cost": 65,
            "effect": function() { breadSellAmount+=(1*this.level);money-=this.cost;this.cost=(this.cost*1.5).toFixed(2); }
        },
        {
            "name": "Hire a Mixer",
            "id": "mixerhire",
            "description": "Automatically mixes dough for you at a reduced rate",
            "type": "worker",
            "prereq": {
                "numOfPurchase": 1,
                "purchase": {
                    0:  "Larger Stan Mixer"
                },
                "level": "1"
            },
            "level": 0,
            "cost": 200,
            "effect": function() { doughWorkers+=(1*this.level);money-=this.cost;this.cost=(this.cost*1.5).toFixed(2); }
        },
        {
            "name": "Hire a Baker",
            "id": "bakerhire",
            "description": "Automatically bakes bread for you at a reduced rate",
            "type": "worker",
            "prereq": {
                "numOfPurchase": 1,
                "purchase": {
                    0:  "Larger Loaf Tin"
                },
                "level": "1"
            },
            "level": 0,
            "cost": 225,
            "effect": function() { breadWorkers+=(1*this.level);money-=this.cost;this.cost=(this.cost*1.5).toFixed(2); }
        },
        {
            "name": "Hire a Salesperson",
            "id": "salespersonhire",
            "description": "Automatically sells bread for you, doesn't change the market sell rate of bread",
            "type": "worker",
            "prereq": {
                "numOfPurchase": 1,
                "purchase": {
                    0:  "Better Sales Skills"
                },
                "level": "1"
            },
            "level": 0,
            "cost": 250,
            "effect": function() { moneyWorkers+=(1*this.level);money-=this.cost;this.cost=(this.cost*1.5).toFixed(2); }
        },
        {
            "name": "Sales Tactics",
            "id": "salestact2",
            "description": "Increase maximum money multipler by 1, One-time purchase only!",
            "type": "Perm",
            "prereq": {
                "numOfPurchase": 0,
                "purchase": {
                    0:  "none"
                },
                "level": "none"
            },
            "level": 0,
            "cost": 450,
            "effect": function() { moneyMultiUp+=1;money-=this.cost; }
        },
        {
            "name": "Market Manipulation",
            "id": "salestact2",
            "description": "Increase maximum money multipler by 1, One-time purchase only!",
            "type": "Perm",
            "prereq": {
                "numOfPurchase": 1,
                "purchase": {
                    0:  "Sales Tactics"
                },
                "level": "1"
            },
            "level": 0,
            "cost": 1000,
            "effect": function() { moneyMultiUp+=1;money-=this.cost; }
        },
        {
            "name": "Worker Efficiency",
            "id": "workereff",
            "description": "Increases the effectiveness of workers",
            "type": "nonPerm",
            "prereq": {
                "numOfPurchase": 3,
                "purchase": {
                    0:  "Hire a Mixer",
                    1: "Hire a Baker",
                    2: "Hire a Salesperson"
                },
                "level": "1"
            },
            "level": 0,
            "cost": 500,
            "effect": function() { workerEFF+=(0.05*this.level);money-=this.cost;this.cost=(this.cost*1.5).toFixed(2); }
        }
    ]
}