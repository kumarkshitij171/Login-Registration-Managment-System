#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
// #include<ctime>
#include <conio.h>
using namespace std;
class Regis
{
    char name[50], emailid[60], address[100];
    unsigned int mobile;
    char password[40];

public:
    void SetData();
    void show();
};

void Regis::SetData()
{
    cout << "Enter your name ";
    cin.ignore();
    cin.getline(name, 50);
    cout << "enter email id ";
    cin >> emailid;
    cout << "Enter your Mobile Number ";
    cin >> mobile;
    cout << "Enter your Address ";
    cin.ignore();
    cin.getline(address, 100);
    cout << "\nEnter password: ";
    cin >> password;
    show();
    ofstream fout("Data-for-login-Registration.txt", ios::app);
    fout << emailid << endl
         << password << endl;
    ofstream out("Information.txt", ios::app);
    out << name << endl
        << emailid << endl
        << mobile << endl
        << address << endl
        << password << endl
        << endl;

    ofstream forget("forgot.txt", ios::app);
    forget << emailid << endl
           << mobile << endl
           << password << endl;
}
void Regis::show()
{
    cout << "Thank you for Registration\n";
    cout << "your login id is " << emailid << "\nPassword " << password;
}
void Registration();
void Login();
void Forgot();

int main()
{
loop:
    system("cls"); // clear screen (to clean old output) like clrscr();
    int a;
    cout << "1)  login" << endl
         << "2)  Registration" << endl
         << "3)  Forgot Password" << endl
         << "4)  Exit!\n"
         << endl
         << "Enter your choice ";
    cin >> a;

    switch (a)
    {
    case 1:
        Login();
        getch();
        break;
    case 2:
        Regis r;
        r.SetData();
        getch();
        break;
    case 3:
        Forgot();
        getch();
        break;
    case 4:
        return -1;
    default:
        cout << "Wrong option chosen";
        getch();
    }
    goto loop;
    getch();
    return 0;
}

void Login()
{
    ifstream in;
    char id[50], passkey[50];
    char loginId[50], password[50];
    cout << "Login ID: ";
    cin >> loginId;
    cout << "Password: ";
    cin >> password;
    in.open("Data-for-login-Registration.txt");
    while (in.eof() == 0)
    {

        in.getline(id, 50);
        in.getline(passkey, 50);
        // cout<<"ID "<<id<<endl<<"password "<<passkey<<endl;
        if (strcmp(loginId, id) == 0 && strcmp(password, passkey) == 0)
        {
            cout << "login verified";
            _sleep(700);
            system("cls");
            cout << "Welcome Back!";
            break;
        }
    }
    in.close();
}

void Forgot()
{
    ifstream fin;
    char loginId[30];
    char name[50], address[100];
    char MNo[10];
    cout << "Enter Login ID ";
    cin >> loginId;
    // cout << "Enter your name ";
    // cin.ignore();
    // cout << "";
    // cin.getline(name, 50);
    cout << "Enter Registered mobile number ";
    cin >> MNo; // can`t typecast to unsigned int
    // cout << "Enter your address ";
    // cin.ignore();
    // cin.getline(address, 100);
    fin.open("forgot.txt");
    cout << endl;
    char email[30], NAME[50], addr[100], password[30];
    char Mobile[10];
    while (fin.eof() == 0)
    {

        // fin.getline(NAME, 50);
        fin.getline(email, 30);
        // fin.getline(addr, 100);
        fin.getline(Mobile, 10);
        // fin.ignore();
        fin.getline(password, 30);
        // cout << NAME << email << addr << Mobile << password;
        if (strcmp(MNo, Mobile) == 0 && strcmp(loginId, email) == 0)
        {

            cout << "your password is " << password;
            getch();
            break;
        }
    }
    fin.close();
}
