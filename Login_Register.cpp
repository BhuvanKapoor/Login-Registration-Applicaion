#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std ;

int main() ;
void Register() ;
void LogIn() ;

// generating unique username
string user_name(string user_name) {
    for (int i = 0; i < user_name.length(); i++)
  		user_name[i] = tolower(user_name[i]);
    return user_name;
}

// function to reset password
void resetPassword() {

    string username, password, uname, pass, newpass, confirmNewpass, HintQues, Hint_Ans, Ans ; int choice ;
    
    system("cls");
    
    cout << "******************************" ;
    cout << "\n\tReset Password" << endl ;
    cout << "******************************" ;
    cout << "\nUsername : " ; cin >> username ;
    
    username = user_name(username);

    // opening user file for acquiring credentials  
    ifstream reset(username + ".txt") ;
    if (reset.is_open()) {
        getline(reset, uname) ;
        getline(reset, pass) ;
        getline(reset, HintQues) ;
        getline(reset, Hint_Ans) ;
        reset.close() ;
        
        cout << "Question : " << HintQues << endl << "Answer : " ; cin >> Ans ;
        
        if (Hint_Ans == Ans) {
            cout << "New Password : " ; cin >> newpass ;
            cout << "Confirm New Password : " ; cin >> confirmNewpass ;
            
            if(newpass == confirmNewpass) {
                if (newpass == pass) {
                    cout << "New password cannot be same as old password !!" << endl ;
                    cout << "Press 0 to Retry | Press 1 for Main Menu : " ; cin >> choice ;
                    
                    if (choice == 0)
                        resetPassword() ;
                    else
                        main() ;
                }
                
                else {
                    ofstream resetPassword(username + ".txt") ;
                    resetPassword << username << endl << newpass ;
                    resetPassword.close() ;
                
                    cout << "\nPassword has been changed successfully !!" ;
                    cout << "\n\nPress 0 to Main Menu | Press 1 for LogIn : " ; cin >> choice ;
                
                    if (choice == 0)
                        LogIn() ;
                    else
                        main() ;
                }
            }
            
            else {
                cout << "\nPassword does not match !!" << endl ;
                system("PAUSE") ;
                resetPassword() ;
            }
        }
        
        else {
            cout << "\nYour answer does't match !!" << endl ;
            cout << "Press 0 to Retry | 1 for Main Menu : " ; cin >> choice ;
        
            if (choice == 0)
                resetPassword() ;
            else if (choice == 1)
                main() ;
        }
    }
    
    else {
        cout << "\n\tInvalid Username !!" ;
        cout << "Press 0 to Retry | 1 for Main Menu : " ; cin >> choice ;
    
        if (choice == 0)
            resetPassword() ;
        else if (choice == 1)
            main() ;
    }
}

// function to login user
void LogIn() {
    
    string username, password, uname, pass ; int choice ;
    
    system("cls") ;
    
    cout << "*********************" ;
    cout << "\n\tLogIn" << endl ;
    cout << "*********************" ;
    cout << "\n\nUsername: " ; cin >> username ;
    
    username = user_name(username);
    
    ifstream user(username + ".txt") ;
    if (user.is_open()) {
        cout << "Password: " ; cin >> password ;
        getline(user, uname) ;
        getline(user, pass) ;
   
        if (strcmp(username.c_str(),uname.c_str()) == 0 && password == pass) {    
            cout << "\n\tLogin Successful !!" ;
            //system("PAUSE") ;
            user.close() ;
        }
        
        else if (strcmp(username.c_str(),uname.c_str()) == 0 && password != pass) {
            cout << "\n\tIncorrect Password !! " << endl ;
            cout << "Press 0 to Retry | Press 1 to Reset : " ; cin >> choice ;
    
            if (choice == 0)
                LogIn() ;
            else
                resetPassword() ;
        }
    }
    
    else {
        cout << "User not found !!" << endl ;
        cout << "Press 0 to Retry | Press 1 to Register : " ; cin >> choice ;
    
        if (choice == 1)
            Register() ;
        else
            LogIn() ;
    }
}

// function to register user
void Register() {
    
    string username, password, confirmPassword, uname, pass, HintQuestion, Answer ; int choice_LogIn, choice ;
    
    system("cls") ;
    
    cout << "************************" ;
    cout << "\n\tRegister" << endl ;
    cout << "************************" ;
    cout << "\n\nEnter a Username : " ; cin >> username ;
    
    username = user_name(username);

    ifstream user(username + ".txt") ;
    getline(user, uname) ;
    if (username == uname) {
        cout << "\nUsername already exists" << endl ;
        cout << "Press 0 to Retry | Press 1 to LogIn : " ; cin >> choice ;
    
        if (choice == 1)
            LogIn() ;
        else   
            Register() ;
    }
    
    else {
        cout << "Enter a Password : " ; cin >> password ;
        cout << "Confirm Password : " ; cin >> confirmPassword ;
    
        if(password == confirmPassword) {
            cout << "\nSelect a Hint Question : " << endl ;
            cout << "1. What is your first pet's name ?" << endl ;
            cout << "2. What is your nick name ?" << endl ;
            cout << "3. Which is your favourite colour ?" << endl ;
            cout << "4. Where is your Home Town ?" << endl ;
            cout << "5. What is your first school name ?" << endl ;
            cout << "Enter your choice : " ; cin >> choice ;
            cout << "Answer : " ; cin >> Answer ;

            switch (choice) {
                case 1: HintQuestion = "What is your first pet's name ?" ;
                    break ;

                case 2: HintQuestion = "What is your nick name ?" ;
                    break ;

                case 3: HintQuestion = "Which is your favourite colour ?" ;
                    break ;

                case 4: HintQuestion = "Where is your Home Town ?" ;
                    break ;

                case 5: HintQuestion = "What is your first school name ?" ;
                    break ;

                default: cout << "\nWrong choice entered !!" ;
                    system("PAUSE") ;
                    Register() ; 
                    break ;
            }
            
            ofstream file ;
            file.open(username + ".txt") ;
            file << username << endl << password << endl << HintQuestion << endl << Answer ;
            file.close() ;
    
            cout << "\tRegistered Successfully !!" << endl ;
            cout << "Press 0 for Main Menu | Press 1 to LogIn : " ; cin >> choice_LogIn ;
    
            if (choice_LogIn == 1)
                LogIn() ;
            else
                main() ;
        }
    
        else {
            cout << "\nPassword does not match !!" ;
            system("PAUSE") ;
            Register() ;
        }
    }
}

// Main function
int main() {

    int choice ;
    
    system("cls") ;
    
    cout << "1. LogIn" ;
    cout << "\n2. Register" ;
    cout << "\n3. EXIT" ;
    cout << "\nEnter your choice : " ; cin >> choice ;

    switch (choice) {
        case 1: LogIn() ;
            break ;

        case 2: Register() ;
            break ;
        
        case 3: cout << "\nExitting!!" ;
            exit(0) ;
            break ;

        default: cout << "\nWarning: Please enter a valid choice !! " ;
            system("PAUSE") ;
            main() ;
            break ;
    }
    return 0 ;
}

// END OF PROGRAM