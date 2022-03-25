import React from "react";
import Email from "./componets/Email.js";
import { Intro } from "./componets/Intro.js";
import Projects from "./componets/Projects.js";
import "./styles/Main.css";

const Main = () => {
   return (
      <section className="main-section">
         <Intro />
         <Projects />
         <Email />
      </section>
   );
};

export default Main;
