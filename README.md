# Bank Management System

---

## Table of Contents
1. Project Structure
2. Introduction
3. Features & Modules
4. How to Run
5. Learnings & Reflections
6. Future Scope

---

## Project Structure

---

## Introduction
Welcome to my Bank Management System project, built entirely by me as a hands-on learning experience in C programming. This project wasn't just about writing code for marks; it was about actually understanding how software in the real world gets made—from managing structures and files, to handling user options, and thinking how a real bank might work inside a computer.
---

## Features & Modules

- **Account Management**
    - Create new accounts with student/work details
    - Unique prime account number generated for each
    - Secure data saved in binary file

- **Deposit Money**
    - Add funds to an account
    - Quick balance updates

- **Balance Check**
    - Instant balance and account holder view

- **Apply for Loan**
    - Loan credited as per yearly salary eligibility

- **Life Insurance**
    - Enroll for Basic or Premium plan if eligible (above 18 years)
    - Inputs and eligibility clearly reflected

- **Bank Card Renewation**
    - Renew debit/credit cards
    - Update validity year and card details

- **Student & Govt Schemes**
    - Add multiple student records, sorted by marks
    - Scholarships: Rs 25000 (<18, >91%), Rs 60000 (18-23)
    - Search student by name for eligibility

---

## How to Run

1. **Clone/download all files** to your system.
2. **Compile with GCC:**
    ```
    gcc main.c account.c card.c insurance.c schemes.c -o bank
    ```
3. **Run:**
    ```
    ./bank
    ```
4. Follow each menu step on screen!

---

## Learnings & Reflections

- Designed and modularized multi-file C programs using headers and typedefs.
- Built routines for real-life banking use-cases.
- Mastered file I/O with binary files for persistent data.
- Improved logic for sorting & searching structures.
- Gained clarity on enums, custom types and safe coding style.

---

## Future Scope

- Password/PIN protection for sensitive tasks
- Transaction history for every account
- Inter-account fund transfer option
- TUI/GUI interface for friendlier experience
- SQLite or other database backend for scaling
- More complete government benefit checks

---






