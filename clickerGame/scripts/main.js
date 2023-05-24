// Dough vars
let dough = 0;
let doughAmountAdded = 6;
let doughCost = 2;

// Bread vars
let bread = 0;
let breadAmountAdded = 1;
let breadSellAmount = 1;

// Money vars
let money = 1000;
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
        let button = document.createElement('button');
        button.textContent = upgrade.name + ' - Cost: ' + upgrade.cost + '. Level: ' + upgrade.level;
        button.classList.add('button-container');
    
        button.addEventListener('click', function() {
            if (money >= upgrade.cost) {
                if (upgrade.type == "nonPerm") {
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
                else if (upgrade.type == "worker") {
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
    
        button.style.padding = '2rem';
        button.style.width = '20rem'
        button.style.textAlign = 'center';
        container.appendChild(button);
    }

    function getUpgrades() {
        for (let upgrade of upgrades) {
            let unlocked = true;
    
            if (upgrade.prereq.purchase !== "none") {
                let prereqUpgrade = upgrades.find(u => u.name.toLowerCase() === upgrade.prereq.purchase.toLowerCase());
                if (prereqUpgrade.level < upgrade.prereq.level) {
                    unlocked = false;
                }
            }
    
    
            let added = false;
            for (let child of buttonContain.children) {
                if (child.textContent.includes(upgrade.name)) {
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
            const moneyToBe = Math.ceil(moneyWorkers*(moneyAmountAdded*workerEFF));
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
            "description": "Increases the amount of dough you get.",
            "type": "nonPerm",
            "prereq": {
                "purchase": "none",
                "level": "none"
            },
            "level": 0,
            "cost": 50,
            "effect": function() { doughAmountAdded+=(1*this.level);money-=this.cost;this.cost=(this.cost*1.5).toFixed(2); }
        },
        {
            "name": "Larger Loaf Tin",
            "description": "Increases the amount of bread you get, at the cost of more dough",
            "type": "nonPerm",
            "prereq": {
                "purchase": "none",
                "level": "none"
            },
            "level": 0,
            "cost": 75,
            "effect": function() { breadAmountAdded+=(1*this.level);doughCost+=(2*this.level);money-=this.cost;this.cost=(this.cost*1.5).toFixed(2); }
        },
        {
            "name": "Better Sales Skills",
            "description": "Increases the amount of bread you can sell at one time",
            "type": "nonPerm",
            "prereq": {
                "purchase": "none",
                "level": "none"
            },
            "level": 0,
            "cost": 100,
            "effect": function() { breadSellAmount+=(1*this.level);money-=this.cost;this.cost=(this.cost*1.5).toFixed(2); }
        },
        {
            "name": "Hire a Mixer",
            "description": "Automatically mixes dough for you at a reduced rate",
            "type": "worker",
            "prereq": {
                "purchase": "Larger Stan Mixer",
                "level": "1"
            },
            "level": 0,
            "cost": 200,
            "effect": function() { doughWorkers+=(1*this.level);money-=this.cost;this.cost=(this.cost*1.5).toFixed(2); }
        },
        {
            "name": "Hire a Baker",
            "description": "Automatically bakes bread for you at a reduced rate",
            "type": "worker",
            "prereq": {
                "purchase": "Larger Loaf Tin",
                "level": "1"
            },
            "level": 0,
            "cost": 225,
            "effect": function() { breadWorkers+=(1*this.level);money-=this.cost;this.cost=(this.cost*1.5).toFixed(2); }
        },
        {
            "name": "Hire a Salesman",
            "description": "Automatically sells bread for you at a reduced rate, doesn't change the market sell rate of bread",
            "type": "worker",
            "prereq": {
                "purchase": "Better Sales Skills",
                "level": "1"
            },
            "level": 0,
            "cost": 250,
            "effect": function() { moneyWorkers+=(1*this.level);money-=this.cost;this.cost=(this.cost*1.5).toFixed(2); }
        },
        {
            "name": "Sales Tactics",
            "description": "Increase overall money multipler by x1, One-time purchase only!",
            "type": "Perm",
            "prereq": {
                "purchase": "none",
                "level": "none"
            },
            "level": 0,
            "cost": 500,
            "effect": function() { moneyMultiUp+=1;money-=this.cost; }
        },
        {
            "name": "Market Manipulation",
            "description": "Increase overall money multipler by x1, One-time purchase only!",
            "type": "Perm",
            "prereq": {
                "purchase": "Sales Tactics",
                "level": "1"
            },
            "level": 0,
            "cost": 1250,
            "effect": function() { moneyMultiUp+=1;money-=this.cost; }
        }
    ]
}