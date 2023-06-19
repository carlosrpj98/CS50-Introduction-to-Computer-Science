import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

# Configure application
app = Flask(__name__)
app.secret_key = 'super secret key'

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")

@app.route("/", methods=["GET", "POST"])
def index():
    birthdays_list = db.execute("SELECT name, month, day FROM birthdays ORDER BY name")
    if request.method == "POST":

        # TODO: Add the user's entry into the database
        name = request.form.get("name")
        month = request.form.get("month")
        day = request.form.get("day")

        names_added = db.execute("SELECT name FROM birthdays")
        max_day_month = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

        if not name:
            flash("Invalid name!")
            return redirect("/")

        for row in range(len(names_added)):
                if name == names_added[row]["name"]:
                    flash("Name in use!")

        if not month or month.isnumeric() == False or int(month) > 12:
            flash("invalid month!")
            return redirect("/")

        if not day or day.isnumeric() == False:
            flash("invalid day!")
            return redirect("/")

        if int(day) > max_day_month[int(month) - 1]:
            flash("Number of days exceeded for the month typed!")
            return redirect("/")

        else:
            db.execute("INSERT INTO birthdays (name, month, day) VALUES(?, ?, ?)",
                       name, month, day)
            flash("You successfully added the birthday!")
            return redirect("/")
    else:
        # TODO: Display the entries in the database on index.html
        return render_template("index.html", birthdays=birthdays_list)

    return redirect("/")



