import React from "react";
import Typewriter from "typewriter-effect";

export const Intro = () => {
   return (
      <section className="container">
         <article className="intro">
            <Typewriter
               onInit={(typewriter) => {
                  typewriter.typeString("Hello there!").start();
               }}
            />
            <p>
               My name is Amr Ashebo. I'm a self-taught Front-end Developer from
               Saudi Arabia. I can build modern and responsive websites using
               HTML CSS JavaScript and React JS.I also have some knowledge in
               back-end development.
            </p>
         </article>
         <article className="skills">
            <p>My Skills</p>
            <aside align="left" className="pro">
               <a
                  href="https://docs.microsoft.com/en-us/cpp/?view=msvc-170"
                  target="_blank"
                  rel="noreferrer"
               >
                  <img
                     src="https://raw.githubusercontent.com/danielcranney/readme-generator/main/public/icons/skills/c-colored.svg"
                     width="36"
                     height="36"
                     alt="C"
                  />
               </a>
               <a
                  href="https://www.typescriptlang.org/"
                  target="_blank"
                  rel="noreferrer"
               >
                  <img
                     src="https://raw.githubusercontent.com/danielcranney/readme-generator/main/public/icons/skills/typescript-colored.svg"
                     width="36"
                     height="36"
                     alt="Typescript"
                  />
               </a>
               <a
                  href="https://developer.mozilla.org/en-US/docs/Web/JavaScript"
                  target="_blank"
                  rel="noreferrer"
               >
                  <img
                     src="https://raw.githubusercontent.com/danielcranney/readme-generator/main/public/icons/skills/javascript-colored.svg"
                     width="36"
                     height="36"
                     alt="Javascript"
                  />
               </a>
               <a
                  href="https://developer.mozilla.org/en-US/docs/Glossary/HTML5"
                  target="_blank"
                  rel="noreferrer"
               >
                  <img
                     src="https://raw.githubusercontent.com/danielcranney/readme-generator/main/public/icons/skills/html5-colored.svg"
                     width="36"
                     height="36"
                     alt="HTML5"
                  />
               </a>
               <a href="https://reactjs.org/" target="_blank" rel="noreferrer">
                  <img
                     src="https://raw.githubusercontent.com/danielcranney/readme-generator/main/public/icons/skills/react-colored.svg"
                     width="36"
                     height="36"
                     alt="React"
                  />
               </a>
               <a
                  href="https://nextjs.org/docs"
                  target="_blank"
                  rel="noreferrer"
               >
                  <img
                     src="https://raw.githubusercontent.com/danielcranney/readme-generator/main/public/icons/skills/nextjs-colored.svg"
                     width="36"
                     height="36"
                     alt="NextJs"
                  />
               </a>
               <a
                  href="https://www.w3.org/TR/CSS/#css"
                  target="_blank"
                  rel="noreferrer"
               >
                  <img
                     src="https://raw.githubusercontent.com/danielcranney/readme-generator/main/public/icons/skills/css3-colored.svg"
                     width="36"
                     height="36"
                     alt="CSS3"
                  />
               </a>
               <a
                  href="https://tailwindcss.com/"
                  target="_blank"
                  rel="noreferrer"
               >
                  <img
                     src="https://raw.githubusercontent.com/danielcranney/readme-generator/main/public/icons/skills/tailwindcss-colored.svg"
                     width="36"
                     height="36"
                     alt="TailwindCSS"
                  />
               </a>
               <a
                  href="https://getbootstrap.com/"
                  target="_blank"
                  rel="noreferrer"
               >
                  <img
                     src="https://raw.githubusercontent.com/danielcranney/readme-generator/main/public/icons/skills/bootstrap-colored.svg"
                     width="36"
                     height="36"
                     alt="Bootstrap"
                  />
               </a>
               <a href="https://redux.js.org/" target="_blank" rel="noreferrer">
                  <img
                     src="https://raw.githubusercontent.com/danielcranney/readme-generator/main/public/icons/skills/redux-colored.svg"
                     width="36"
                     height="36"
                     alt="Redux"
                  />
               </a>
               <a
                  href="https://nodejs.org/en/"
                  target="_blank"
                  rel="noreferrer"
               >
                  <img
                     src="https://raw.githubusercontent.com/danielcranney/readme-generator/main/public/icons/skills/nodejs-colored.svg"
                     width="36"
                     height="36"
                     alt="NodeJS"
                  />
               </a>
               <a
                  href="https://expressjs.com/"
                  target="_blank"
                  rel="noreferrer"
               >
                  <img
                     src="https://raw.githubusercontent.com/danielcranney/readme-generator/main/public/icons/skills/express-colored.svg"
                     width="36"
                     height="36"
                     alt="Express"
                  />
               </a>
               <a
                  href="https://www.mongodb.com/"
                  target="_blank"
                  rel="noreferrer"
               >
                  <img
                     src="https://raw.githubusercontent.com/danielcranney/readme-generator/main/public/icons/skills/mongodb-colored.svg"
                     width="36"
                     height="36"
                     alt="MongoDB"
                  />
               </a>
            </aside>
         </article>
      </section>
   );
};
