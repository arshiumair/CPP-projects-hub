# Student Management System (C++ Binary File Database)

## About the Project

This project is a console-based **Student Management System** written in C++. It allows you to store, organize, and manage student records using a binary file (`student.bin`). The system provides a menu-driven interface for adding, removing, searching, editing, displaying, and exporting student data. You can also export the records to a human-readable `.txt` file for backup or reporting purposes.

---

## Features

- **Add Student:** Add new student records with roll number, name, program, batch (session), and section.
- **Remove Student:** Remove a student by roll number.
- **Search Student:** Search for a student by roll number and view their details.
- **Display All:** View all students filtered by program, batch, and section.
- **Edit Info:** Edit an existing student's information.
- **Erase All:** Clear all student records from the database.
- **Export Data:** Export all student records to a formatted text file (`student_record.txt`).
- **Persistent Storage:** All records are stored in a binary file (`student.bin`) for data persistence.

---

## How It Works

- The program uses a `Student` class to represent each student and a `StudentManagementSystem` class to handle all operations.
- Data is serialized and deserialized to/from a binary file using custom methods.
- The menu-driven interface allows you to perform all operations interactively.
- Input validation is performed for all fields to ensure data integrity.
- The program uses standard C++ and file I/O, and is compatible with Windows and Linux.

---

## Usage

1. **Compile the program:**
   ```sh
   g++ main.cpp -o StudentManagementSystem
   ```
2. **Run the program:**
   ```sh
   ./StudentManagementSystem
   ```
3. Follow the on-screen menu to add, remove, search, edit, display, or export student records.

---

## File Structure

- `main.cpp` — Main source file containing all logic and menu interface.
- `student.bin` — Binary file used for persistent storage of student records (created automatically).
- `student_record.txt` — Text file generated when exporting data.

---



## Requirements

- C++11 or later
- Windows or Linux (uses only standard C++ and file I/O)

---

## Notes

- Do not edit `student.bin` manually; always use the program's menu.
- When exporting, the data is written in a readable, tabular format to `student_record.txt`.
- The program uses simple input validation and error messages to guide the user.

---

## Example Menu
__________ ICIT RECORDS ___________
________________Home_______________

Chose an operation
1. Add Student
2. Remove Student
3. Search
4. Display all
5. Edit info
6. Erase all
7. Export data
8. Exit

---

## License

This project is provided for educational purposes. You are free to use, modify, and distribute it as you wish.

Enjoy managing your student records!