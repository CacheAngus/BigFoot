//going to have our contact schema

const mongoose = require('mongoose');


const ContactSchema = mongoose.Schema({
    firstname:{
        type: String,
        required: true
    },
    lastname:{
        type: String,
        required: true
    },
    number:{
        type: String,
        required: true
    }
});

const Contact = module.exports = mongoose.model('Contact', ContactSchema);

//need to look up schema and models