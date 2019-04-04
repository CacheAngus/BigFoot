import { Component, OnInit } from '@angular/core';
import {ContactService} from '../contact.service';
import {Contact} from '../contact';


@Component({
  selector: 'app-contacts',
  templateUrl: './contacts.component.html',
  styleUrls: ['./contacts.component.css'],
  providers: [ContactService]

})
export class ContactsComponent implements OnInit {
contacts: Contact[];
contact: Contact;
firstname: string;
lastname: string;
number: string;


  //dependency injection
  constructor(private contactService: ContactService) { }

addContact(){
  const newContact = {
    firstname: this.firstname,
    lastname: this.lastname,
    number: this.number
  }
  this.contactService.addContact(newContact).subscribe(contact => {
    this.contacts.push(contact);
    this.contactService.getContacts()
      .subscribe( contacts => this.contacts = contacts);
  });
}

deleteContact(id:any){
  var contacts = this.contacts;
  this.contactService.deleteContact(id)
    .subscribe(data=>{
      if(data.n==1){
        for(var i=0; i< contacts.length; i++)
        {
          if(contacts[i]._id == id){
            contacts.splice(i,1);
          }
        }
      }
    })
}

  //this is initialted when the component is loaded
  ngOnInit() {
    this.contactService.getContacts()
      .subscribe( contacts => this.contacts = contacts);

  }
//subscribe returns an observable
}
