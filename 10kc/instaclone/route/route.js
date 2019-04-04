const express = require('express');
const router = express.Router();


const Contact = require('./models/contacts');

//CUDA commands
//retrieve
router.get('/contacts', (req,  res, next)=>{
    
    //were gonna connect to database and then write logic
    //all contacts in the list will be saved in Contact variable
    Contact.find((function(err, contacts){
        res.json(contacts);
    }))
});

//add contact
router.post('/contact', (req, res, next)=>{
    let newContact = new Contact({
        firstname: req.body.firstname,
        lastname: req.body.lastname,
        number: req.body.number
    });

    newContact.save((err, contact)=>{
        if(err){
            res.json({msg: "Failed"});
        }
        else {
            res.json({msg: 'Success'});
        }
    });
});


//deleting
//mongodb greates an id for each contact/insertion
router.delete('/contact/:id', (req, res, next)=>{
    //refer to contact by id
    Contact.remove({_id: req.params.id}, function(err, result){
        if(err)
        {
            res.json(err);
        }
        else{
            res.json(result);
        }
    });
});








//export the router
//goes to the package.json and finds nodemon finds that main entry is app.js
//starts server using particular file
module.exports = router;