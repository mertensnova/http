import React from "react";
import NetflixImg from "../Images/Desktop.png";
import RESTImg from "../Images/color.jpg";
import SpaceImg from "../Images/space.png";
import ManageImg from "../Images/Modern.jpg";

const Projects = () => {
   const Netflix = (e) => {
      e.preventDefault();
      window.location = "https://netflix-2-0-ten.vercel.app/";
   };

   const REST = (e) => {
      e.preventDefault();
      window.location = "https://optimistic-lovelace-ea9a29.netlify.app/";
   };
   const Space = (e) => {
      e.preventDefault();
      window.location = "https://jolly-turing-08c5a4.netlify.app/";
   };
   const Manage = (e) => {
      e.preventDefault();
      window.location = "https://modern-website-4xsmr7m8b-amr8644.vercel.app/";
   };

   const seeMore = (e) => {
      e.preventDefault();
      window.location = "https://github.com/amr8644";
   };

   return (
      <article className="projects">
         <div className="title">
            <p>My Projects</p>
         </div>
         <div className="works">
            {/* One Item */}
            <div className="item">
               <div className="img-box">
                  <img src={NetflixImg} alt="Netflix" onClick={Netflix} />
               </div>

               <p className="name">Netflix Clone</p>
               <p className="made">Made using: React JS and TailWind CSS</p>
            </div>
            {/* One Item */}
            <div className="item">
               <div className="img-box">
                  <img src={RESTImg} alt="Color" onClick={REST} />
               </div>

               <p className="name">REST Countries API</p>
               <p className="made">Made using: HTML, CSS, and,JavaScript</p>
            </div>
            {/* One Item */}
            <div className="item">
               <div className="img-box">
                  <img src={SpaceImg} alt="Netflix" onClick={Space} />
               </div>

               <p className="name">Space tourism </p>
               <p className="made">Made using: HTML, CSS, and,JavaScript</p>
            </div>
            {/* One Item */}
            <div className="item">
               <div className="img-box">
                  <img src={ManageImg} alt="Manage" onClick={Manage} />
               </div>

               <p className="name">GPT-3 Landing Page</p>
               <p className="made">Made using: React JS and CSS</p>
            </div>
         </div>
         <div className="btn-container">
            <button className="see-more" onClick={seeMore}>
               See More
            </button>
         </div>
      </article>
   );
};

export default Projects;
