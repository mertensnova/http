import React, { useState } from "react";

const Projects = () => {
   const Netflix = (e) => {
      e.preventDefault();
      window.location = "http://www.google.com/";
   };

   return (
      <article className="projects">
         <div className="title">
            <p>My Projects</p>
         </div>
         <div className="works">
            <div className="item">
               <div className="img-box">
                  <img
                     src="https://images.unsplash.com/photo-1647971447454-8093ed0f8e3d?ixlib=rb-1.2.1&ixid=MnwxMjA3fDB8MHxlZGl0b3JpYWwtZmVlZHwyMnx8fGVufDB8fHx8&auto=format&fit=crop&w=500&q=60"
                     alt="Netflix"
                     onClick={Netflix}
                  />
               </div>

               <p className="name">Netflix Clone</p>
               <p className="made">Made using: React JS and TailWind CSS</p>
            </div>
         </div>
      </article>
   );
};

export default Projects;
