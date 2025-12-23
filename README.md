# Arbitrary-Precision-Calculator-APC:
🔹 Project Overview

This project implements an Arbitrary Precision Calculator (APC) using C programming and Doubly Linked Lists.
It allows arithmetic operations on very large numbers that cannot be stored using standard C data types like int or long long.

Each digit of a number is stored in a separate node of a doubly linked list, enabling calculations on numbers of any length.

🔹 Features

Handles large integers of unlimited size

Supports the following operations:

Addition (+)

Subtraction (-)

Multiplication (*)

Division (/)

Uses manual arithmetic logic (same as pen-and-paper method)

Dynamic memory allocation (no fixed size limits)

🔹 Technologies Used

Language: C

Data Structure: Doubly Linked List

Concepts: Pointers, Dynamic Memory, Modular Programming

🔹 File Structure
.
├── main.c        // Input handling and operation selection
├── dll.h         // Doubly linked list structure & prototypes
├── dll.c         // Linked list helper functions
├── maths.h       // Arithmetic function prototypes
├── maths.c       // Add, Subtract, Multiply, Divide logic
└── README.md     // Project documentation

🔹 How the Project Works

Each digit of the input number is stored as a character in a node.

Arithmetic operations are performed digit-by-digit:

Addition & Subtraction: From right to left using carry/borrow

Multiplication: Long multiplication method

Division: Long division using repeated subtraction

Helper functions are used to compare numbers, remove leading zeros, and free memory.

🔹 Compilation & Execution
Compile:
gcc main.c dll.c maths.c

Run:
./a.out <number1> <operator> <number2>

Example:
./a.out 1010 / 10

🔹 Sample Output
Digits of num1: 1 0 1 0
Digits of num2: 1 0
Result: 1 0 1

🔹 Advantages

No overflow issues

Works for very large numbers

Demonstrates strong understanding of data structures

🔹 Limitations

Slower than built-in data types

Division uses repeated subtraction (can be optimized)
