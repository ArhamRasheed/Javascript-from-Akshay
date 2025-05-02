console.log('Start');

setTimeout( function cbT(){
    console.log("CB setTimeout");
    
}, 5000);


fetch("https://jsonplaceholder.typicode.com/users")
.then( function cbF() {
    console.log("CB Netflix");
});

console.log("End");