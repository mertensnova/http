const express = require("express");
const app = express();

require("dotenv").config();

const bodyParser = require("body-parser");
const cors = require("cors");
const nodemailer = require("nodemailer");

app.use(bodyParser.urlencoded({ extended: true }));

app.use(bodyParser.json());

app.post("/send_mail", cors(), async (req, res) => {
   let { text } = req.body;
   let { email } = req.body;
   let { name } = req.body;
   console.log(req.body);
   const transport = nodemailer.createTransport({
      service: "gmail",
      auth: {
         user: process.env.MAIL_USER,
         pass: process.env.MAIL_PASS,
      },
   });

   await transport.sendMail({
      from: email,
      to: process.env.MAIL_FROM,
      subject: "Job Oppertunity",
      html: `<div style="
      border: 1px solid black;
      padding: 20px;
      Font-family: sans-serif;
      line-height: 2;
      font-size: 20px;"
      <h1>Here is your email!</h1>
      <p>${text}</p>
      <p>All the best, ${name}</p>
       </div>`,
   });
});

app.use(cors());
app.listen(4000, () => {
   console.log("Server is listening on port 4000");
});
