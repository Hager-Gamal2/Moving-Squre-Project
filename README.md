# OpenGL Interactive Square

## 📌 Project Overview
A simple interactive graphics application built using **C++** and **OpenGL (GLUT)**.  
The project demonstrates basic **2D transformations** including translation and rotation, as well as dynamic color changes through keyboard interaction.

---

## 🎯 Features
- Move a square using **arrow keys**
- Rotate the square using keyboard input
- Change the square color dynamically
- Boundary checking to prevent the square from leaving the window
- Double buffering for smooth rendering

---

## 🕹 Controls
| Key | Action |
|----|-------|
| ⬅️ Left Arrow | Move square left |
| ➡️ Right Arrow | Move square right |
| ⬆️ Up Arrow | Move square up |
| ⬇️ Down Arrow | Move square down |
| `1` | Rotate the square (10 degrees per press) |
| `Space` | Change square color (Red → Green → Blue) |
| `Esc` | Exit the application |

---

## 🛠 Technologies Used
- **C++**
- **OpenGL**
- **GLUT (OpenGL Utility Toolkit)**

---

## 📷 Demo
[Watch Demo](run.mp4)  
*Make sure the file `run.mp4` is uploaded to the same repository.*

---

## 🚀 How to Run
1. Install OpenGL and GLUT on your system  
2. Compile the project using a C++ compiler  
   ```bash
   g++ main.cpp -lglut -lGL -lGLU -o OpenGLSquare
