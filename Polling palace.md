# Polling System

## Introduction
The provided code is a program for a polling system. It allows users to log votes, access an admin panel, view winners, and exit the program. The program manages a linked list of voter information, including roll number, name, and birth date. Users need to provide their credentials to vote, and the program checks if the provided information matches the voter list.

## Program Flow
Upon execution, the program presents a welcome message and options for the user. The user can enter 1 to log votes, 2 to access the admin panel, 3 to view the winners, or 4 to exit the program.

### Logging Votes
If the user chooses to log votes (1), the program prompts the user to enter their roll number, name, and birth date. It then compares the provided information with the voter list to determine if the user is eligible to vote. If the credentials match, the user can proceed with voting. Otherwise, they are not allowed to vote.

### Admin Panel
Choosing the admin panel option (2) allows the user to access administrative features. This functionality is not included in the provided code snippet and should be implemented separately.

### Viewing Winners
Selecting the winners option (3) displays the winners of the poll. The details of how the winners are determined and displayed are not included in the provided code snippet.

### Exiting the Program
Choosing the exit option (4) terminates the program.

## Additional Notes
- The code includes various header files for standard input/output, string manipulation, Windows API, and boolean data type.
- The code uses predefined macros for text formatting in the console.
- The program uses a linked list to store voter information.
- The `main()` function contains an infinite loop that continues until the program is manually terminated.
- The program reads voter information from a CSV file named "voters.csv". The format of the file is assumed to be roll number, name, and birth date separated by commas.

> **Note:** The provided code snippet is incomplete and lacks certain functionalities like the admin panel and winner determination. You need to implement those parts separately based on your requirements.
