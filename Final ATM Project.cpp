#include <iostream>
using namespace std;
void login();
void menu();
void data_in();
void input();
void inquire();
void withdraw();
void deposit();
void quit();
void retrylogin();
void reloadmenu();

struct user
{
    string name;
    int pin;
    int balance;
};
// Number of users is 10;
int num = 2, cu;
user d[2];

int main()
{
    data_in();
    login();
}
void menu()
{
    cout << "\t\t        ||  ATM Machine By Sana Tahir & Afsheen Ishaq  ||        " << endl;
    cout << "\t\t ================================================================" << endl;
    cout << "\t\t ================================================================\n\n";
    cout << "\t\t ================================================================\n\n"
         << endl;
    cout << "\t\t MAIN SCREEN \n";
    cout << "\t\t [1] Inquire Balance" << endl;
    cout << "\t\t [2] Withdraw" << endl;
    cout << "\t\t [3] Deposit" << endl;
    cout << "\t\t [4] Quit " << endl<<endl;

    input();
}

void data_in()
{
    cout << "First of all we will add data of users like there names, security pin and balances...!" << endl
         << endl;

    for (int i = 0; i <= num - 1; i++)
    {
        cout << "Enter the username (without spaces) of the user no " << i + 1 << " : ";
        cin >> d[i].name;
        cout << "Enter the balance of the user no " << i + 1 << " : ";
        cin >> d[i].balance;
        cout << "Enter the 4-digit Pin of the user no " << i + 1 << " : ";
        cin >> d[i].pin;
        cout << endl;
        while (d[i].pin < 1000 || d[i].pin > 9999)
        {
            cout << "Error...! Please use 4-digit Pin... Try Again...!" << endl;
            cin >> d[i].pin;
        }
    }
}

void login()
{

    string username;
    int pin, s = 0;
    cout << "Enter the username: ";
    cin >> username;
    for (int i = 0; i < num; i++)
    {
        if (username == d[i].name)
        {
            s = i;
        }
    }

    if (d[s].name == username)
    {
        cout << "Enter Your 4-Digit Pin: ";
        cin >> pin;
        while (pin < 1000 || pin > 9999)
        {
            cout << "Error...! Please use 4-digit Pin... Try Again...!" << endl;
            cin >> pin;
        }
        if (pin == d[s].pin)
        {
            cout << "Logged in successful" << endl;
            cu = s;
            menu();
        }
        else
        {
            retrylogin();
        }
    }
    else
    {
        retrylogin();
    }
}

void input()
{
    int choice;
    cout << "Enter your choice: ";
    cin >> choice;
    while (choice < 1 || choice > 4)
    {
        cout << "Error... Try Again...!" << endl;
        cin >> choice;
    }

    switch (choice)
    {
    case 1:
        inquire();
        break;
    case 2:
        withdraw();
        break;
    case 3:
        deposit();
        break;

    case 4:
        quit();
        break;

    default:
        break;
    }
}

void inquire()
{
    cout << "Available Balance :" << d[cu].balance<<endl;
    reloadmenu();
}
void withdraw()
{
    int wd;
    cout << "Enter the amount to withdraw: " << endl;
    cin >> wd;
    while (wd < 0)
    {
        cout << "Invalid Entry... Please Try Again...!" << endl;
        cin >> wd;
    }
    if (d[cu].balance >= wd)
    {
        cout << "Withdrawal Successful!" << endl;
        d[cu].balance = d[cu].balance - wd;
        cout << "Remaining Balance: " << d[cu].balance << endl;
    }
    else {
        cout<<" Insufficient Balance "<<endl;
    }
    reloadmenu();
}
void deposit(){
int dp;
cout<<"Enter the amount to deposit: ";
cin>>dp;
    d[cu].balance = d[cu].balance + dp;
    cout << "verifying..." << endl
         << "Deposited Successfully...! Thank you" << endl
         << "Your new balance: " << d[cu].balance << endl;
    reloadmenu();
}
void quit()
{
    cout << "Thank you for using our services." << endl;
    exit(0);
}

void retrylogin()
{
    cout << "Wrong PIN...! Try again later...!" << endl;
    char x;
    cout << "[Y]: Try Again" << endl;
    cout << "[X]: Quit" << endl;
    cin >> x;

    if (x == 'Y' || x == 'y')
    {
        login();
    }
    else if (x == 'X' || x == 'x')
    {
        quit();
    }
}

void reloadmenu()
{
    char x;
    cout << "[Y]: Return to main manu" << endl;
    cout << "[X]: Quit" << endl;
    cin >> x;

    if (x == 'Y' || x == 'y')
    {
        menu();
    }
    else if (x == 'X' || x == 'x')
    {
        quit();
    }
}
