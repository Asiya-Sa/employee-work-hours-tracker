# Employee Work Hours Tracker 👨‍💼

A C++ console application that tracks employee weekly work hours, automatically adjusts under-time hours, calculates salaries, and provides employee statistics. This was a collaborative team project.

## ✨ Features

- **Pre-loaded Data** - 4 employees with weekly hours (Sun-Thu)
- **Auto-correction** - Automatically adjusts hours less than 6 to 6 hours
- **Interactive Menu** - Three options for user interaction
- **Add New Employee** - Dynamically add employees with their hours
- **Employee Search** - Find employees by name (case-insensitive)
- **Salary Calculation** - Calculates weekly salary with overtime rates
- **Statistics** - Shows highest/lowest total hours by day
- **Individual Reports** - For each employee shows:
  - Total weekly hours
  - Day with highest hours
  - Weekly salary

## 💰 Salary Calculation

- **Regular hours (≤9 hours/day):** 100 SAR per hour
- **Overtime (>9 hours/day):** 200 SAR per hour for extra hours

Example: If an employee works 11 hours in a day:
- First 9 hours: 9 × 100 = 900 SAR
- Extra 2 hours: 2 × 200 = 400 SAR
- Daily total: 1,300 SAR

## 🛠️ Technologies Used

- **C++** - Core programming language
- **iomanip** - Table formatting with setw()
- **Arrays** - 2D arrays for hours tracking
- **String manipulation** - Case-insensitive search
- **Loops & Conditionals** - Program logic and calculations

## 📋 Prerequisites

- Any C++ compiler (G++, Visual Studio, CodeBlocks)
- Basic command line knowledge

- <h2>📌 Note</h2>

<p>This was a team project from our introductory C++ course. 
  It demonstrates working with 2D arrays, table formatting, and menu-driven programs. 
  The code has a fixed array size of 20 employees and does not save data to files. Pre-loaded with 4 sample employees.</p>
