function getRandomInt(max) {
    return Math.floor(Math.random() * max);
}

let rndArray = [];

for(let i = 0; i < 100; i++) {
    rndArray.push(getRandomInt(100));
}

console.log(rndArray);