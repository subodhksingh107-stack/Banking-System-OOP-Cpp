#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Account {
    public:
int balance, acc_number;
string name;


virtual void deposit() = 0;
virtual void withdraw() = 0;
virtual int display() = 0;
virtual void calculateinterest() = 0;
};

class SavingAccount : public Account {
public:

SavingAccount (int b, string n, int a){
    balance = b;
    name = n;
    acc_number = a;
}


void minimum (){
    if (balance < 500){
        cout << "Balance is less than minimum balance \n";
        deposit();
    } 
}

void calculateinterest(){
 int interest, year;
    cout << "Enter Interest rate per year\n";
    cin >> interest >> year;
    balance += (balance * interest * year) / 100;
}

void deposit (){
    int x;
    cout << "Enter money to deposit\n";
    cin >> x;
    balance += x;
    cout << "Amount Deposit Sucessfully\n";
}

void withdraw (){
    minimum();
    int x ;
    cout << "Enter money to withdraw\n";
    cin >> x;
  if (x <= balance)
    balance -= x;
else
    cout << "Insufficient balance\n";
    cout << "Money Withdrawn Sucessfully\n";
}

int display (){
    cout << "Account number : " << acc_number << endl;
    cout << "Name : " << name << endl;
    cout << "Balance : " << balance << endl;
    return 0;
}
};

int main (){
   vector <SavingAccount> s1;
   int x;
   int balance, acc_number;
string name;
   while (true)
   {
   cout << "1. Create Account\n" << "2. Deposit\n" << "3. Withdraw\n" << "4. Display Account\n" << "5. Calculate Interest\n" << "6. Transfer Money\n" << "7. Save to File\n" << "8. Load from File\n" << "9. Exit \n";
   cin >> x;
  if (x == 1)
  {
    cout << "Enter Account number : \n";
    cin >> acc_number;
    cout << "Enter Name: \n";
cin.ignore();
getline(cin, name);
    cout << "Enter Balance : \n";
    cin >> balance;
    s1.push_back(SavingAccount(balance, name, acc_number));
  } else if (x >= 2 && x <= 6){
    int y;
    cout << "Enter Account number : \n";
    cin >> y;
    for (int i = 0; i < s1.size(); i++)
    {
       if (s1[i].acc_number == y)
       {
        switch (x)
        {
        case 2:
            s1[i].deposit();
            break;

              case 3:
            s1[i].withdraw();
            break;

              case 4:
            s1[i].display();
            break;

             case 5:
            s1[i].calculateinterest();
            break;

            case 6:
            int z, a;
            cout << "Enter Account number to transfer money : \n";
            cin >> a;
            cout << "Enter money to transfer : \n";
            cin >> z;
          for (int j = 0; j < s1.size(); j++)
          {
            if (a == s1[j].acc_number)
            {
              s1[j].balance += z;   // receiver

               cout << "Money transferred sucessfully \n";
            } 
          }
         s1[i].balance -= z;   // sender

            break;

        default:
        cout << "Invalid Input\n";
            break;
        }
       }
       
    }
    
  } else if (x == 7 ){
   ofstream out ("Saving.txt");
   
   for (int i = 0; i < s1.size(); i++)
   {
   out << s1[i].acc_number << " "
    << s1[i].name << " "
    << s1[i].balance << endl;
   }
   out.close();
  } else if (x == 8)
  {
    string line;
   ifstream in ("Saving.txt");

  while (getline(in, line)) {
    cout << line << endl;
}
  cout << "The Saving Account Information is : \n";
  cout << line << endl;
  } else if (x == 9){
    cout << "Thanks for visiting \n";
    break;
  }
  
  
   
   }
   return 0;
   
}