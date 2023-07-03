# Login-Registration-Applicaion
A login and registration application using the C++ programming language & file handling is a program that allows users to create new accounts, log in with existing accounts, and store their information securely in files. 

### User Registration:
- The program prompts the user to enter their desired username and password.
- It checks if the username is unique and not already taken by searching through a file that stores existing usernames.
- If the username is unique, it creates a new entry in a user database file, storing the username and password securely. 
- The program informs the user that the registration is successful.

### User Login:
- The program prompts the user to enter their username and password.
- It verifies the input by comparing the entered username and password with the entries in the user database file.
- If the login credentials match an entry in the file, the program grants access to the user and displays a welcome message.
- If the login credentials are incorrect or the username is not found, the program displays an error message and prompts the user to try again.

### File Handling:
- The program uses file handling techniques to read from and write to files.
- It creates a user database file that stores the registered usernames and encrypted passwords.
- When a new user registers, their information is appended to the user database file.
- When a user logs in, the program reads the user database file and compares the entered login credentials with the stored information.

Overall, this login and registration application provides a basic authentication system using C++ programming language and file handling for storing and retrieving user information securely.
