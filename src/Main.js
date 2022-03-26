import React from "react";
import Email from "./componets/Email.js";
import { Intro } from "./componets/Intro.js";
import Projects from "./componets/Projects.js";
import Avater from "./Images/me1.jpg";
import "./styles/Main.css";

import { FontAwesomeIcon } from "@fortawesome/react-fontawesome";
import { faTwitter } from "@fortawesome/free-brands-svg-icons";
import { faGithub } from "@fortawesome/free-brands-svg-icons";
import { faFacebook } from "@fortawesome/free-brands-svg-icons";
import { faInstagram } from "@fortawesome/free-brands-svg-icons";

const Main = () => {
   return (
      <section className="main-section">
         <div className="header">
            <img src={Avater} alt="Profile" />
            <p>
               <span>I'm Amr,</span> a Front-End Developer.
            </p>
         </div>
         <Intro />
         <Projects />
         <Email />
         <article className="footer">
            <div className="social">
               <a href="https://twitter.com/amr_8644">
                  <FontAwesomeIcon icon={faTwitter} />
               </a>
               <a href="https://github.com/amr8644">
                  <FontAwesomeIcon icon={faGithub} />
               </a>
               <a href="https://www.facebook.com/amr8644/">
                  <FontAwesomeIcon icon={faFacebook} />
               </a>
               <a href="https://www.instagram.com/ashebo_amr/">
                  <FontAwesomeIcon icon={faInstagram} />
               </a>
            </div>
            <div className="others2">
               <p>
                  Design: <a href="https://html5up.net/">HTML5</a>
               </p>
               <p>
                  Demo Images: <a href="https://unsplash.com/">Unsplash</a>
               </p>
            </div>
         </article>
      </section>
   );
};

export default Main;
