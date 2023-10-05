#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

struct User {
    string username;
    string passwordHash;
};

// Buat Hashtable
unordered_map<string, User> users;

// Metode hashing pake XOR
string hashPassword(const string& password) {
    string salt = "UserSalt";
    string hashedPassword = password;
    for (size_t i = 0; i < password.length(); i++) {
        hashedPassword[i] = password[i] ^ salt[i % salt.length()];
    }
    return hashedPassword;
}

// Tambah User
void addUser(User user) {
    user.passwordHash = hashPassword(user.passwordHash);
    users[user.username] = user;
}

// Check user terus ditampilkan
bool checkUser(string username, const string& password) {
    if (users.find(username) != users.end()) {
        string inputPasswordHash = hashPassword(password);
        cout << "Hash Key: " << users[username].passwordHash << endl; // Menampilkan hash yang disimpan
        return users[username].passwordHash == inputPasswordHash;
    }
    return false;
}

int main() {

    while (true) {
        cout << "1. Login" << endl;
        cout << "2. Add User" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            string username;
            string password;
            cout << "Enter your username: ";
            cin >> username;
            cout << "Enter your password: ";
            cin >> password;

            if (checkUser(username, password)) {
                cout << "Login successful!" << endl;
            } else {
                cout << "Login failed." << endl;
            }
        } 
        else if (choice == 2) {
            string username;
            string password;
            cout << "Enter new username: ";
            cin >> username;
            cout << "Enter new password: ";
            cin >> password;

            User newUser = {username, password};
            addUser(newUser);
        } 
        else {
        }
    }

    return 0;
}
