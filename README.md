Lab 03 — Structures, Pointers & Dynamic Memory Allocation
Overview

This lab covers structures, pointer-based access, dynamic memory management with new/delete, and building a small menu-driven application in C++. It consists of six tasks (Q1–Q6), each in its own .cpp file.

Files
File	Task
Q1.cpp	Creating a Structure
Q2.cpp	Accessing a Structure Through a Pointer
Q3.cpp	Creating a Record Dynamically
Q4.cpp	Using Functions with Pointers
Q5.cpp	Checking Whether a Record Exists
Q6.cpp	Building a Student Record Application (menu-driven)
Requirements
A C++ compiler supporting C++11 or later (e.g. g++)
No external libraries — only <iostream> and <string> are used
How to Compile & Run

Each file can be compiled independently:

bash
g++ -std=c++11 Q1.cpp -o Q1 && ./Q1
g++ -std=c++11 Q2.cpp -o Q2 && ./Q2
g++ -std=c++11 Q3.cpp -o Q3 && ./Q3
g++ -std=c++11 Q4.cpp -o Q4 && ./Q4
g++ -std=c++11 Q5.cpp -o Q5 && ./Q5
g++ -std=c++11 Q6.cpp -o Q6 && ./Q6
Task Summaries

Q1 — Creating a Structure
Defines a Student struct (name, roll_no, marks), takes input, and displays it via a display() member function.

Q2 — Accessing via Pointer
Uses a Student* to input a full record, display it with ->, update it, and display the updated record.

Q3 — Dynamic Record Creation
Allocates a Student with new, inputs/displays through the pointer, then cleans up with delete and sets the pointer to nullptr.

Q4 — Functions with Pointers
Implements displayStudent(const Student*) and updateMarks(Student*, float) operating on a dynamically allocated record.

Q5 — Existence Check
Implements displayIfExists(const Student*), which prints the record if the pointer is non-null, or "No Record Available" otherwise.

Q6 — Menu-Driven Application
A full CRUD-style menu (Create, Display, Update Marks, Delete, Exit) built around a single dynamically allocated Student*, using pass-by-reference (Student*&) so functions can modify the caller's pointer directly.
