//importing modules
const express = require('express');
const  mongoose = require('mongoose');
const bodyparser = require('body-parser');
const cors = require('cors');
var path = require('path');

var app = express();

const route = require('./route/route.js');

//connect to mongodb
mongoose.connect('mongodb://localhost:27017/instaclone');
mongoose.connection.on('connected',()=>{
    console.log('Connected to database mongodb at 27017');
});

mongoose.connection.on('error',(err)=>{
    if(err){
        console.log('Error'+ err);
    }
});
//create the port & bind server
const port = 3000;

//check the server is working so our routing is proper
//use get method to define route form homepage

//add middlware
//cors
app.use(cors());
//body-parser
app.use(bodyparser.json());

//static files-the dir points to current directory
app.use(express.static(path.join(__dirname, 'public')));

//route all files
app.use('/api', route);

app.get('/', (req, res)=>{
    res.send('foobar');
});

 app.listen(port, ()=>{
     console.log('Server started at port:' + port);
 });

 