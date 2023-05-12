#include <fstream>
#include <iostream>
#include <iomanip>
#include <time.h>
#include <conio.h>
#include <cstring>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
using namespace std;
//=================================================================================================
class Bank
{
public:
    string Branch;
    string retaccbr()
    {
        return Branch;
    }
    Bank()
    {
        cout << "\n\t\t\t\t\t       Bank Open\n\n\n";
    }
};


//=================================================================================================


class ATM : public Bank
{
    string bank;


public:
    ATM()
    {
        int i, j, k = 0;
        for (i = 3; i >= 0; i--)
        {
            cout << "\t\t\t\t\t\t";
            for (j = 3; j > k; j--)
            {
                cout << " ";
            }
            cout << "*";
            for (j = 1; j < (k * 2); j++)
                cout << " ";
            if (i < 3)
                cout << "*";
            cout << "\n";
            k++;
        }
        cout << "\n\t\t\t\t\t     W E L C O M E\n";
        cout << "\t\t\t\t\t\t  T O\n";
        cout << "\t\t\t\t\t\t A T M\n\n";
        for (i = 3; i >= 0; i--)
        {
            cout << "\t\t\t\t\t\t";
            for (j = 3; j > i; j--)
            {
                cout << " ";
            }
            cout << "*";
            for (j = 1; j < (i * 2); j++)
                cout << " ";
            if (i >= 1)
                cout << "*";
            cout << "\n";
        }
        cout << "\n\n";
        time_t now; //Show date and time function
        time(&now);
        cout << " \n\t\t\t\t\t" << ("%s\n", ctime(&now));
        cout << endl;
        cout << endl;
    }
    getchar();
};


//==================================================================================================


class Customer : public ATM
{
public:
    string Customer_Name;
    string retaccna()
    {
        return Customer_Name;
    }
    string Pin;
    string retaccpi()
    {
        return Pin;
    }
};


//==================================================================================================


class Account : public Customer
{
public:
    long long int Account_Number;
    double Account_Balance;
    void input();
    void create_account();
    void details();
    void accountExit();
    void interest();
    long long int retaccno()
    {
        return Account_Number;
    }
    double retaccba()
    {
        return Account_Balance;
    }
};


//==================================================================================================
class Transaction : public Account
{
    double amount;


public:
    virtual void pin_Validation() {}
    virtual void deposit() {}
    virtual void withdraw() {}
};
//==================================================================================================
class Deposit : virtual public Transaction
{
public:
    double amountd;
    void deposit()
    {
        cout << "\n\t\t\t\tDEPOSIT SYSTEM \n\n";
        cout << "\tAccount Holder Name is : " << Customer_Name << "\n";
        cout << "\tBranch location is : " << Branch << "\n";
        cout << "\tAccount number is : " << Account_Number << "\n";
        cout << "\tPresent available balance is Rs" << Account_Balance << "\n";
        cout << "\tEnter the Amount to be Deposited Rs : ";
        cin >> amountd;
        Account_Balance = Account_Balance + amountd;
        cout << "\n\tYour new available Balanced Amount is Rs: " << Account_Balance << endl;
    }
};
//==================================================================================================
class Withdraw : virtual public Transaction
{
public:
    double amountw;
    void withdraw()
    {
        cout << "\n\t\t\t\tWITHDRAW SYSTEM \n\n";
        cout << "\tAccount Holder Name is : " << Customer_Name << "\n";
        cout << "\tBranch location is : " << Branch << "\n";
        cout << "\tAccount number : " << Account_Number << "\n";
        cout << "\tPresent available balance is Rs " << Account_Balance << "\n";
        cout << "\tEnter the Amount to be Withdrawn (Limit set at 5000 maximum) : Rs ";
        cin >> amountw;
        if (amountw > Account_Balance || amountw > 5000) //Limit set at Rs5000 maximum after paying bills
        {
            amountw = 0;
            cout << "\tAccount Holders Name is : " << Customer_Name << "\n";
            cout << "\tBranch location is : " << Branch << "\n";
            cout << "\tAccount number is : " << Account_Number << "\n";
            cout << "\n\t\t\tNot Possible" << endl;
            cout << "\t\t\tSorry !!\n"
                 << endl;
        }
        else
        {
            Account_Balance = Account_Balance - amountw;
            cout << "\tThe Names of the Account Holder is :" << Customer_Name << "\n";
            cout << "\tThe Branch location is :" << Branch << "\n";
            cout << "\tAccount number :" << Account_Number << "\n\n";
            cout << "\tYour new available Balanced Amount is Rs " << Account_Balance << endl;
        }
    }
};
//==================================================================================================
class Pin_Validation : virtual public Transaction
{
public:
    string Old_Pin, New_Pin, New_Pin1;
    void pin_Validation()
    {
        cout << "Enter Your Current Pin ";
        const char BACKSPACE = 8;
        const char RETURN = 13;
        const char SPACE = 32;
        int j;
        while ((j = getch()) != RETURN)
        {
            if (j == BACKSPACE)
            {
                if (Old_Pin.size() > 0)
                {
                    Old_Pin.erase(Old_Pin.size() - 1, 1);
                    cout << "\b \b";
                }
            }
            else
            {
                Old_Pin.push_back(j);
                cout << "*";
            }
        }
        if (Pin == Old_Pin)
        {
            cout << endl;
            cout << "Enter Your New Pin : ";
            int h;
            while ((h = getch()) != RETURN)
            {
                if (h == BACKSPACE)
                {
                    if (New_Pin.size() > 0)
                    {
                        New_Pin.erase(New_Pin.size() - 1, 1);
                        cout << "\b \b";
                    }
                }
                else
                {
                    New_Pin.push_back(h);
                    cout << "*";
                }
            }
            cout << endl;
            cout << "Again Enter Your New Pin : ";
            int t = 0;
            while ((t = getch()) != RETURN)
            {
                if (t == BACKSPACE)
                {
                    if (New_Pin1.size() > 0)
                    {
                        New_Pin1.erase(New_Pin1.size() - 1, 1);
                        cout << "\b \b";
                    }
                }
                else
                {
                    New_Pin1.push_back(t);
                    cout << "*";
                }
            }
            if (New_Pin == New_Pin1)
            {
                Pin = New_Pin1;
                cout << endl;
                cout << "\nYour Pin Is Successfully Updated\n";
            }
            else
            {
                cout << endl;
                cout << "Wrong Input\nRetry\n";
            }
        }
        else
        {
            cout << endl;
            cout << "\nWrong Attempt\n";
        }
    }
};
//==================================================================================================
class Receipt : public Deposit, public Withdraw, public Pin_Validation
{
    const string receipt;


public:
    void withdrawreceipt()
    {
        ofstream fout;
        fout.open("Withdraw.txt", ios::out);
        time_t now; //Show date and time function
        time(&now);
        fout << " \n\t\t\t\t\t" << ("%s\n", ctime(&now));
        fout << "\n\n\t\tWITHDRAWAL RECEIPT\n\n";
        fout << "====================================================\n";
        fout << "A/c no.        NAME    Branch      \n";
        fout << "====================================================\n";
        fout << Account_Number << "   " << Customer_Name << "    " << Branch << endl;
        fout << "====================================================\n";
        fout << "Amount withdrawn Rs " << amountw << endl;
        fout << "====================================================\n";
        fout << "Your Account Balance is Rs " << Account_Balance << endl;
        fout << "====================================================\n";
        fout << "\n\t\tThank You!\n\n";
        fout.close();
    }
    void depositreceipt()
    {
        ofstream fout;
        fout.open("Deposit.txt", ios::out);
        time_t now; //Show date and time function
        time(&now);
        fout << " \n\t\t\t\t\t" << ("%s\n", ctime(&now));
        fout << "\n\n\t\tDEPOSIT RECEIPT\n\n";
        fout << "====================================================\n";
        fout << "A/c no.        NAME    Branch      \n";
        fout << "====================================================\n";
        fout << Account_Number << "   " << Customer_Name << "    " << Branch << endl;
        fout << "====================================================\n";
        fout << "Amount Deposited Rs " << amountd << endl;
        fout << "====================================================\n";
        fout << "Your Amount Balance is Rs " << Account_Balance << endl;
        fout << "====================================================\n";
        fout << "\n\t\tThank You!\n\n";
        fout.close();
    }
    void detailreceipt()
    {
        ofstream fout;
        fout.open("Details.txt", ios::out);
        time_t now; //Show date and time function
        time(&now);
        fout << " \n\t\t\t\t\t" << ("%s\n", ctime(&now));
        fout << "\n\n\tACCOUNT DETAILS RECEIPT\n\n";
        fout << "====================================================\n";
        fout << "A/c no.        NAME    Branch      \n";
        fout << "====================================================\n";
        fout << Account_Number << "   " << Customer_Name << "    " << Branch << endl;
        fout << "====================================================\n";
        fout << "Your Amount Balance is Rs " << Account_Balance << endl;
        fout << "====================================================\n";
        fout << "\n\t\tThank You!\n\n";
        fout.close();
    }
};
//==================================================================================================


void Account ::create_account() //To create new account
{
    double n;
    cout << "\n\tEnter the Branch : ";
    cin.ignore();
    getline(cin, Branch);
    for (int x = 0; x < Branch.size(); x++)
    {
        Branch[x] = toupper(Branch[x]);
    }
    cout << "\n\tEnter The account No. : ";
    cin >> Account_Number;
    cout << "\n\tEnter The Name of The account Holder : ";
    cin.ignore();
    getline(cin, Customer_Name);
    for (int x = 0; x < Customer_Name.size(); x++)
    {
        Customer_Name[x] = toupper(Customer_Name[x]);
    }
    cout << "\n\tEnter The Initial amount you want to deposit(min amt 2500) : ";
    cin >> n;
    if (n >= 5000)
        Account_Balance = n;
    else
    {
        cout << "\n\t\t\t SORRY! NOT POSSIBLE\n\n";
        exit(1);
    }
    cout << "\n\tEnter pin: ";
    const char BACKSPACE = 8;
    const char RETURN = 13;
    const char SPACE = 32;
    int j;
    while ((j = getch()) != RETURN)
    {
        if (j == BACKSPACE)
        {
            if (Pin.size() > 0)
            {
                Pin.erase(Pin.size() - 1, 1);
                cout << "\b \b";
            }
        }
        else
        {
            Pin.push_back(j);
            cout << "*";
        }
    }
}


//==================================================================================================
void Account::interest() //To Calculate Interest
{
    int y;
    cout << "\nATM ACCOUNT INTEREST PAYMENT\n\n";
    cout << "\tThe Interest is calculate over the last SIX months on the average account balance\n";
    cout << "\n\t\tInterest Rate payable is 10% per annum." << endl;
    cout << "\t\tView the accumulated interest? Press 1 for Yes OR 0 for NO.\n";
    cin >> y;
    if (y == 1)
    {
        cout << "\tAccount Holder Name is : " << Customer_Name << "\n";
        cout << "\tBranch location is : " << Branch << "\n";
        cout << "\tAccount number is : " << Account_Number << "\n";
        cout << "\tPresent available balance is Rs" << Account_Balance << "\n";
        double Account_Interest = Account_Balance * 1.50;
        cout << "\tPresent available balance + interest for 6 months : " << Account_Interest << "\n";
    }
}
//==================================================================================================
void Account::accountExit() //To Exit from program
{
    cout << "\nATM ACCOUNT EXIT \n";
    exit(1);
}
//==================================================================================================
void Account::details() //To Print Bank Details
{
    cout << "\n\t\t\t\t ATM ACCOUNT DETAILS \n\n";
    cout << "\tAccount Holder Name is : " << Customer_Name << "\n";
    cout << "\tBranch location is : " << Branch << "\n";
    cout << "\tAccount number is : " << Account_Number << "\n";
    cout << "\tAccount Balance is : " << Account_Balance << "\n";
}
//==================================================================================================
int main()
{
    string branch, name;
    long long int no;
    string pin;
    int e;
    char x, y, z;
    system("color 9");
    Receipt r;
    while (1)
    {
        cout << "\n\tPress 1 and Then Enter to Create New Account\n\n";
        cout << "\tPress 2 and Then Enter to Access Your Account\n\n";
        cout << "\tPress 3 and Then Enter to get Help.\n\n";
        cout << "\t\t\t\t\t or \n\n";
        cout << "\tPress 0 and Then Enter to exit the system\n\n";
        int f;
        cin >> f;
        switch (f)
        {
        case 1:
        {
            char c;
            ofstream fout;
            fout.open("account.txt", ios::binary | ios::app | ios::out);
            r.create_account();
            cout << "\n\n\tAre you sure? (Y for Yes/N for No) : ";
            cin >> c;
            if (c == 'Y' || c == 'y')
            {
                fout.write((char *)&r, sizeof(r));
                cout << "\n\n\t\t\t\t\t\t\tAccount Created..\n";
                getchar();
                getchar();
            }
            fout.close();
            break;
        }
        case 2:
        {
            int l = 0;
            while (1)
            {
                char c;
                cout << "\n\t\t\t\tENTER YOUR NAME\t\t\t\t";
                cin.ignore();
                getline(cin, name);
                for (int x = 0; x < name.size(); x++)
                {
                    name[x] = toupper(name[x]);
                }
                cout << "\t\t\t\tENTER ACCOUNT NUMBER\t\t\t";
                cin >> no;
                ifstream fin;
                fin.open("account.txt", ios::binary | ios::in);
                if (!fin)
                {
                    cout << "\nError in opening! File Not Found!!" << endl;
                    return 0;
                }
                while (!fin.eof())
                {
                    fin.read((char *)&r, sizeof(r));
                    if ((r.retaccna() == name) && (r.retaccno() == no))
                    {
                        l = 1;
                        break;
                    }
                }
                fin.close();
                if (l == 0)
                {
                    cout << "\n\tWrong input \n";
                    cout << "\tEnter Again!";
                    cout << endl;
                }
                else if (l == 1)
                    break;
            }
            for (int i = 0; i < 2; i++)
            {
                cout << "\t\t\t\tENTER PIN\t\t\t\t";
                const char BACKSPACE = 8;
                const char RETURN = 13;
                const char SPACE = 32;
                int j;
                while ((j = getch()) != RETURN)
                {
                    if (j == BACKSPACE)
                    {
                        if (pin.size() > 0)
                        {
                            pin.erase(pin.size() - 1, 1);
                            cout << "\b \b";
                        }
                    }
                    else
                    {
                        pin.push_back(j);
                        cout << "*";
                    }
                }
                int p = 0;
                ifstream fin;
                fin.open("account.txt", ios::in);
                if (!fin)
                {
                    cout << "\nError in opening! File Not Found!!" << endl;
                    return 0;
                }
                while (!fin.eof())
                {
                    fin.read((char *)&r, sizeof(r));
                    if (r.retaccno() == no && r.retaccna() == name && r.retaccpi() == pin)
                    {
                        p = 1;
                        break;
                    }
                }
                fin.close();
                if (p == 0)
                {
                    if (i == 0)
                    {
                        cout << "\n\t\t\t\t\t\t\tWRONG PIN!" << endl;
                        cout << "\t\t\t\t\t\t\tTRY AGAIN!" << endl;
                    }
                    if (i == 1)
                    {
                        cout << "\n\t\t\t\t\t\t\tWRONG PIN!!";
                        cout << "\n\t\t\t\t\tYou had made your last attempt which failed!";
                        cout << "\n\t\t\t\t\t     Sorry No More attempts allowed!\n\n";
                        exit(1);
                    }
                }
                else if (p == 1)
                {
                    cout << "\n\n\t\t\t\t\t\t\tWELCOME\n\n";
                    break;
                }
            }
            fstream f;
            f.open("account.txt", ios::binary | ios::in | ios::out);
            if (!f)
            {
                cout << "\nError in opening! File Not Found!!" << endl;
                return 0;
            }
            bool found = false;
            while (found == false && (f.read((char *)&r, sizeof(r))))
            {
                if (r.retaccno() == no)
                {
                    found = true;
                    int pos = f.tellg();
                    while (1)
                    {
                        cout << endl
                             << "\nATM Main Menu Screen \n\n";
                        cout << "\t\t1. To Deposit Cash" << endl;
                        cout << "\t\t2. To Withdraw Cash" << endl;
                        cout << "\t\t3. To Balance Inquiry" << endl;
                        cout << "\t\t4. To Pay Account Interest" << endl;
                        cout << "\t\t5. To Change Pin" << endl;
                        cout << "\t\t0. To Exit ATM" << endl
                             << endl;
                        cout << "\tPLEASE ENTER A SELECTION AND PRESS RETURN KEY: \n\n";
                        cin >> e;
                        switch (e)
                        {
                        case 1:
                            r.deposit();
                            f.seekp(pos);
                            f.write((char *)&r, sizeof(r));
                            cout << "\n\t\tDo you want a receipt? (Y for Yes/N for No) : ";
                            cin >> x;
                            if (x == 'Y' || x == 'y')
                            {
                                r.depositreceipt();
                                cout << "\nPlease Wait a Moment\nProcessing...\n";
                                cout << "\n\tPlease Collect Your Receipt\n";
                            }
                            break;
                        case 2:
                            r.withdraw();
                            if (r.amountw != 0)
                            {
                                f.seekp(pos);
                                f.write((char *)&r, sizeof(r));
                                cout << "\n\t\tDo you want a receipt? (Y for Yes/N for No) :  ";
                                cin >> y;
                                if (y == 'Y' || y == 'y')
                                {
                                    r.withdrawreceipt();
                                    cout << "\nPlease Wait a Moment\nProcessing...\n";
                                    cout << "\n\tPlease Collect Your Receipt\n";
                                }
                            }
                            break;
                        case 3:
                            r.details();
                            cout << "\n\t\tDo you want a receipt? (Y for Yes/N for No) :  ";
                            cin >> z;
                            if (z == 'Y' || z == 'y')
                            {
                                r.detailreceipt();
                                cout << "\nPlease Wait a Moment\nProcessing...\n";
                                cout << "\n\tPlease Collect Your Receipt\n";
                            }
                            break;
                        case 4:
                            r.interest();
                            break;
                        case 5:
                            r.pin_Validation();
                            f.seekp(pos);
                            f.write((char *)&r, sizeof(r));
                            break;
                        case 0:
                            cout << "\n\t\t\t\t\t       Thank You!\n\n";
                            r.accountExit();
                            break;
                        default:
                            cout << "Please Enter the Correct Number Choice" << endl;
                            break;
                        }
                    }
                }


                f.close();
            }
        }
        case 3:
        {
            cout << "\n ATM ACCOUNT STATUS \n\n";
            cout << "\tYou must have the correct pin number to access this acount. See your\n\n";
            cout << "\t  bank representative for assistance during bank opening hours\n\n";
            exit(1);
            break;
        }
        case 0:
        {
            cout << "\n\t\t\t\t\t       Thank You!\n\n";
            exit(1);
        }
        default:
            cout << "Please Enter the Correct Number Choice" << endl;
            break;
        }
        system("cls");
    }


    return 0;
}

