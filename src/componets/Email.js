import React from "react";
import { FontAwesomeIcon } from "@fortawesome/react-fontawesome";
import { faEnvelope } from "@fortawesome/free-solid-svg-icons";
import { faHome } from "@fortawesome/free-solid-svg-icons";
import { faPhone } from "@fortawesome/free-solid-svg-icons";

const Email = () => {
   return (
      <article className="email">
         <div className="sender">
            <div className="get-in">
               <p>Get In Touch</p>
            </div>
            <div className="name-email">
               <input type="text" placeholder="Name" name="name" />
               <input type="email" placeholder="Email" name="email" />
            </div>
            <textarea placeholder="Message" className="message"></textarea>
            <div className="btn-container">
               <button className="send">Send</button>
            </div>
         </div>
         <div className="others1">
            <div className="box">
               <FontAwesomeIcon icon={faHome} />
               <p>Jeddah, Saudi Arabia</p>
            </div>
            <div className="box">
               <FontAwesomeIcon icon={faEnvelope} />

               <p>amr8644@gmail.com</p>
            </div>
            <div className="box">
               <FontAwesomeIcon icon={faPhone} />
               <p>+966 55 858 1107</p>
            </div>
         </div>
      </article>
   );
};

export default Email;
