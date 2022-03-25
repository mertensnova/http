import React from "react";

const Email = () => {
   return (
      <article className="email">
         <div className="get-in">
            <p>Get In Touch</p>
         </div>
         <div className="sender">
            <div className="name-email">
               <input type="text" placeholder="Name" name="name" />
               <input type="email" placeholder="Email" name="email" />
            </div>
            <textarea placeholder="Message" className="message"></textarea>
            <div className="btn-container">
               <button className="send">Send</button>
            </div>
         </div>
         <div className="others"></div>
      </article>
   );
};

export default Email;
