import React from "react";
import Avater from "./Images/me1.jpg";
import "./styles/Side.css";

import { FontAwesomeIcon } from "@fortawesome/react-fontawesome";
import { faTwitter } from "@fortawesome/free-brands-svg-icons";
import { faGithub } from "@fortawesome/free-brands-svg-icons";
import { faFacebook } from "@fortawesome/free-brands-svg-icons";
import { faInstagram } from "@fortawesome/free-brands-svg-icons";

const Side = () => {
   return (
      <section className="left-section">
         <div className="first-container">
            <img src={Avater} alt="Profile" />
            <div className="social-media">
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
            <p>
               <span>I'm Amr</span> <br /> a Front-End Developer.
            </p>
         </div>

         <article className="second-container">
            <div className="others">
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

export default Side;
