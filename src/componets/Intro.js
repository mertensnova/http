import React from "react";
import Typewriter from "typewriter-effect";

export const Intro = () => {
   return (
      <article className="intro">
         <Typewriter
            onInit={(typewriter) => {
               typewriter.typeString("Hello There !").start();
            }}
         />
         <p>
            My name is Amr Ashebo. I'm a self-taught Front-end Developer from
            Saudi Arabia. I can build modern and responsive websites using HTML
            CSS JavaScript and React JS.I also have some knowledge in back-end
            development.
         </p>
         <div className="btn-container">
            <button className="learn-more">Learn More</button>
         </div>
      </article>
   );
};
