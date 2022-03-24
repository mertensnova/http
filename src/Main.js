import React from "react";
import { Intro } from "./componets/Intro.js";
import Projects from "./componets/Projects.js";
import "./styles/Main.css";

const Main = () => {
   return (
      <section className="main-section">
         <Intro />
         <Projects />
      </section>
   );
};

export default Main;
