import React, { useState } from "react";
import { FontAwesomeIcon } from "@fortawesome/react-fontawesome";
import { faEnvelope } from "@fortawesome/free-solid-svg-icons";
import { faHome } from "@fortawesome/free-solid-svg-icons";
import { faPhone } from "@fortawesome/free-solid-svg-icons";
import axios from "axios";

const Email = () => {
   const [sent, setSent] = useState(false);
   const [name, setName] = useState("");
   const [email, setEmail] = useState("");
   const [text, setText] = useState("");

   const handleSubmit = async () => {
      setSent(true);
      try {
         await axios.post("http://localhost:4000/send_mail", {
            text,
            name,
            email,
         });
      } catch (error) {
         console.log(error);
      }
   };

   return (
      <article className="email">
         <div className="sender">
            <div className="get-in">
               <p>Get In Touch</p>
            </div>
            <form className="form" onSubmit={handleSubmit}>
               <div className="name-email">
                  <input
                     type="text"
                     placeholder="Name"
                     name="name"
                     onChange={(e) => setName(e.target.value)}
                  />
                  <input
                     type="email"
                     placeholder="Email"
                     name="email"
                     onChange={(e) => setEmail(e.target.value)}
                  />
               </div>
               <textarea
                  placeholder="Message"
                  className="message"
                  onChange={(e) => setText(e.target.value)}
               ></textarea>

               <div className="btn-container">
                  <button className="send" type="submit">
                     Send
                  </button>
               </div>
            </form>
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
