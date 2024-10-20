from flask import Flask, render_template, request

app = Flask(__name__)


@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "GET" or request.form.get("color") != "red" and request.form.get("color") != "blue":
        return render_template("index.html")
    else:
        print("Form submitted!")
        color = request.form.get("color")
        return render_template("color.html", color=color)