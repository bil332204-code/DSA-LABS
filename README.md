# DSA Labs
 
**Name:** Bilal Ahmed
**Registration Number:** 573512
**Class:** BSCS-15D
 
---
 
# DSA Lab 01 - Arrays, Basic OOP and Git
 
## Programs
 
- **task1.cpp** -Creates a numbers array, updates the third element to 7, and prints all values using a for loop
- **task2.cpp** - Reads 5 integers into an array and adds them up in a
  second loop to print the total.
- **task3.cpp** - Defines a `Student` class with `rollNumber` and
  `marks`, creates two objects, and shows that changing one object's
  data doesn't affect the other.
- **task4.cpp** - Reads 8 integers and reports the largest and smallest
  values along with the index of their first occurrence.
- **task5.cpp** -Reads 6 integers and reverses them in place (swap from both ends) without using a second array.
- **task6.cpp** - Reads 10 integers and moves the first occurrence of each distinct value to the front, preserving order, without a second array.
## Task 2 Test Results
 
| Test input       | Expected total | Actual total |
|-------------------|----------------|--------------|
| 1 2 3 4 5          | 15             | 15           |
| 0 0 0 0 0          | 0              | 0            |
| -2 4 -1 0 3        | 4              | 4            |
 
---
 
# DSA Lab 02 - Static and Dynamic Arrays, Pointers and Dynamic Memory Allocation
 
## Programs
 
- **task1.cpp** - Declares a fixed-size `sales[5]` array with a pointer `p`, reads and totals five values using pointer notation, then adds 2 to the third day's value through the pointer and displays the updated values and total.
- **task2.cpp** - Reads a runtime-sized array of student marks using `new[]`, validates the size, displays the marks, total, and average (without losing the fractional part), and counts marks greater than or equal to 50 using pointer notation.
- **task3.cpp** - Reads a 2D `sales[2][3]` array (branches x days) using a row pointer `int (*rowPtr)[3]`, displays the table, and calculates separate totals for each branch and each day using pointer notation.
- **task4.cpp** - Allocates a dynamic 2D marks matrix (`int**`) with runtime-chosen rows and columns, reads and displays marks, calculates each student's total, and reports the student with the highest total (ties go to the first student).
- **task5.cpp** - Reads `n` marks into a dynamic array, then expands it by allocating a new block of `n + 1` integers, copies the original values across using pointer notation, appends a new mark, releases the old block, and updates the pointer and size.
- **task6.cpp** - Inspects and fixes a buggy fragment containing an out-of-bounds loop, incorrect `delete` (missing `[]`), and a use-after-delete (dangling pointer) bug, then rewrites it as a correct program that reads, displays, and safely releases three integers.
## Task 2 Test Results
 
| Test input                  | Expected result                              | Actual result |
|------------------------------|-----------------------------------------------|----------------|
| n = 4; marks = 40 50 70 81   | Total 241; average 60.25; pass count 3        | Match |
| n = 1; mark = 0              | Total 0; average 0; pass count 0              | Match |
| n = 0                        | Error; no allocation or mark input            | Match |
 
## Task 3 Test Results
 
| Input by row                              | Expected totals                              | Actual result |
|--------------------------------------------|-----------------------------------------------|----------------|
| Branch 1: 2 4 6 / Branch 2: 1 3 5           | Branch totals: 12 and 9; Day totals: 3, 7, 11 | Match |
| Both rows: 0 0 0                            | Every total is 0                              | Match |
 
## Task 4 Test Results
 
| Input by row                        | Expected result                          | Actual result |
|---------------------------------------|--------------------------------------------|----------------|
| 2 x 3: 50 60 70 / 80 40 90             | Totals: 180, 210; top student: 2           | Match |
| 2 x 2: 40 60 / 50 50                   | Totals: 100, 100; top student: 1 (tie)     | Match |
| 1 x 1: 75                              | Total: 75; top student: 1                  | Match |
 
## Task 5 Test Results
 
| Test input                              | Expected result | Actual result |
|-------------------------------------------|-------------------|----------------|
| n = 3; marks 45 60 75; new mark 90         | 45 60 75 90       | Match |
| n = 1; mark 0; new mark 100                | 0 100             | Match |
 
## Task 6 Test Results
 
| Test input | Expected result | Actual result |
|-------------|--------------------|----------------|
| 4 5 6       | Values: 4 5 6      | Match |
 
---
 
# DSA Lab 03 - Structures, Pointers and Dynamic Memory Allocation
 
## Programs
 
- **Q1.cpp** - Defines a `Student` struct (`name`, `roll_no`, `marks`), reads a single student's details, and displays them via a `display()` member function.
- **Q2.cpp** - Uses a `Student*` to input a full record (name, roll no, marks), displays it through the arrow operator, updates it via an `update()` function, and displays the updated record.
- **Q3.cpp** - Allocates a single `Student` record dynamically with `new`, inputs and displays its details through the pointer, then releases the memory with `delete` and sets the pointer to `nullptr`.
- **Q4.cpp** - Implements `displayStudent(const Student*)` and `updateMarks(Student*, float)` operating on a dynamically allocated record, showing the record before and after the marks update.
- **Q5.cpp** - Implements `displayIfExists(const Student*)`, which prints the student's details if the pointer is non-null or `"No Record Available"` otherwise; tested against a null pointer, a populated record, and a deleted (nulled) pointer.
- **Q6.cpp** - A menu-driven application (Create, Display, Update Marks, Delete, Exit) managing a single dynamically allocated `Student*` via pass-by-reference (`Student*&`), with existence checks before update/delete/display.
