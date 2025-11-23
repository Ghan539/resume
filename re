from flask import Flask, send_file, render_template_string, abort
import os
import threading
import webbrowser

app = Flask(__name__)

# ---- PHOTO PATH ----
USER_PHOTO_PATH = r"C:\Users\ghans\Documents\WhatsApp Image 2024-12-23 at 20.50.54_2bf4ff03.jpg"

@app.route("/")
def home():
    return '<p>Open <a href="/resume">/resume</a> to view the resume.</p>'

@app.route("/photo")
def photo():
    if not os.path.isfile(USER_PHOTO_PATH):
        abort(404, description="Photo file not found")
    return send_file(USER_PHOTO_PATH, mimetype="image/jpeg")

@app.route("/resume")
def resume():
    return render_template_string("""
    <!DOCTYPE html>
    <html>
    <head>
    <meta charset="UTF-8">
    <title>Resume - Ghanshyam</title>

    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 0;
            padding: 0;
            background: #ffffff;
        }
        .container {
            display: grid;
            grid-template-columns: 30% 70%;
            width: 900px;
            margin: auto;
            background: white;
            box-shadow: 0 0 20px rgba(0,0,0,0.1);
        }
        .left {
            background: #f5fafb;
            padding: 20px;
        }
        .right {
            padding: 30px;
        }
        .photo {
            width: 150px;
            height: 150px;
            border-radius: 50%;
            display: block;
            margin: auto;
            object-fit: cover;
        }
        h2 {
            margin-bottom: 5px;
            color: #08818a;
        }
        h3 { margin-top: 25px; color: #0b1a1f; }
        .section-title {
            border-bottom: 3px solid #08818a;
            padding-bottom: 5px;
            display: inline-block;
            margin-bottom: 10px;
            text-transform: uppercase;
            font-weight: bold;
        }
    </style>
    </head>
    <body>

    <div class="container">

        <!-- LEFT SIDE -->
        <div class="left">
            <img src="/photo" class="photo">

            <h3 class="section-title">Contact</h3>
            <p><b>Email:</b> ghanshyamsingh@gmail.com</p>
            <p><b>Phone:</b> 7297979337</p>
            <p><b>Location:</b> Jaipur, Rajasthan</p>

            <h3 class="section-title">Skills</h3>
            <ul>
                <li>Python</li>
                <li>Flask</li>
                <li>AI & Machine Learning</li>
                <li>Web Development</li>
            </ul>

            <h3 class="section-title">Languages</h3>
            <ul>
                <li>English</li>
                <li>Hindi</li>
            </ul>
        </div>

        <!-- RIGHT SIDE -->
        <div class="right">
            <h1>Ghanshyam</h1>
            <h2>B.Tech CSE Student</h2>

            <h3 class="section-title">Profile Summary</h3>
            <p>Passionate CSE student experienced in Python, Flask, AI, and real-world project development. 
               Built Smart Attendance Systems and Health Assistant apps.</p>

            <h3 class="section-title">Projects</h3>
            <ul>
                <li><b>Smart Attendance System:</b> Face recognition, fingerprint, dashboard.</li>
                <li><b>AI Virtual Health Assistant:</b> Tracks food, sleep, glucose & provides reports.</li>
            </ul>

            <h3 class="section-title">Education</h3>
            <p><b>B.Tech CSE</b>, Vivekananda Global University, Jaipur</p>
        </div>

    </div>

    </body>
    </html>
    """)

def run_flask():
    app.run(host="127.0.0.1", port=5000, debug=False, use_reloader=False)


webbrowser.open("http://127.0.0.1:5000/resume")
