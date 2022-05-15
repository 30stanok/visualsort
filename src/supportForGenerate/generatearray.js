const text = document.getElementById('text');
const btn = document.getElementById('button');

function getRandomInt(max) {
    return Math.floor(Math.random() * max);
}

const rndArray = [];
const generate = () => {
    rndArray.length = 0
    for(let i = 0; i < 100; i++) {
        rndArray.push(getRandomInt(100));
    }
    text.innerHTML = rndArray;
}

btn.addEventListener('click', generate);
console.log(rndArray);