

// include standard library files

//for cout and cin commands and more
#include <iostream>

// this 2 for generating random numbers
#include <cctype>
#include <ctime>

// for strings
#include <string>

//this is std container
#include <vector>

//this header file for using std algorithms like std::for_each and std::find and much more
#include <algorithm>

//this is std container
#include <list>

//this header file helps <algorithm> file
#include <iterator>

//this is std container
#include <set>

//this is std container
#include <deque>

// this 2 used for making program sleep like printing words in slow motion
#include <thread>
#include <chrono>

//this header file for controling our output like making int only show 6 numbers and much more
#include <iomanip>

// //this header file for using smart pointers <important>
#include <memory>

////this header file for checking if user entered string or int and much more
#include <sstream>

//this is std container
#include <unordered_set>

//this is std container
#include <array>

//this header file for math operations
#include <cmath>

//this is std container
#include <map>

//this header file for std::pair its for compaining 2 different type of variabled together examlpe(std::pair<int,std::string>_variable_name_ = std::make_pair(num,str))) and much more
#include <utility>

//this header file for constrolling files on system like saving or loading files
#include <fstream>

//this header file for creating directory
#include <direct.h>

//this is std container
#include <stack>

//this is std container
#include <queue>

///////////////////////////////////////////////////////////////////[Classes Definitions]//////////////////////////////////////////////////////////////////////////
//Classes Definitions first so it can see vector below
class Abstract;
class Account;
class Checking;
class Saving;

///////////////////////////////////////////////////////[define vector of smart pointer that holds all the accounts]///////////////////////////////////////////////////////////////
std::unique_ptr<std::vector<Account>>vec_checking{ nullptr }; //holds checking accounts
std::unique_ptr<std::vector<Account>>vec_saving{ nullptr };//holds saving accounts
/////////////////////////////////////////////////////////////////[Functions prototype]////////////////////////////////////////////////////////////////////////
//its very important to use Functions prototypes so u dont have to worry if Functions can see each other
//also makes ur code cleaner
//display Accounts inside any vec we pass here by refrence so it doesn't make copy
void display(std::unique_ptr<std::vector<Account>>&vec);

//it adds the created account to vector
bool add(std::unique_ptr<std::vector<Account>>& vec,Account& acc);

//create account 
void create_acc(std::unique_ptr<std::vector<Account>>&vec);

//find if account exist
int find_account(std::unique_ptr<std::vector<Account>>&vec,std::string name);

//sends user to main menu
void main_menu();

//sends user to options menu
void options();

//sends user back
void go_back();

//display accounts of any vec we send by refrence
void show_accounts(std::unique_ptr<std::vector<Account>>& vec);

// to check if user entred numbers or letters
bool is_string(std::string str);

//for creating temporary account to add it to vector later on then we delete the temporary account
Account* temp_Account(Account* acc);

//for manage account options
void manage_account(std::unique_ptr<std::vector<Account>>& vec);

// sends user back if there are no accounts created
void empty_account();

//to show only the accounts name
void show_accounts_name(std::unique_ptr<std::vector<Account>>&vec);

//for selecting different account to manage
int select_account(std::unique_ptr<std::vector<Account>>& vec);

//for transfering money
void transfer(std::unique_ptr<std::vector<Account>>& vec,int index,std::string name, double amount);

// for generating random credit card (not real)
long long generate_cc(int &&choose);

//for modifying account options
void Modify_Account(std::unique_ptr<std::vector<Account>>& vec,int index);

// to display all the accounts in vector of checking and saving accounts(helps display_all function )
std::shared_ptr<std::vector<std::pair<std::string, double>>> list_of_all(std::unique_ptr<std::vector<Account>>& vec_1, std::unique_ptr<std::vector<Account>>& vec_2);

// to display all the accounts in vector of checking and saving accounts
void display_all(std::unique_ptr<std::vector<Account>>& vec_1, std::unique_ptr<std::vector<Account>>& vec_2);

//for deleting account 
void delete_account(std::unique_ptr<std::vector<Account>>& vec, int index);

//check if user entred valid name like if they try to change account name to already used name
bool valid_name(std::unique_ptr<std::vector<Account>>& vec, std::string name);

// sends user to the first menu
void menu();

// for option to enter program with preloaded accounts
void create_preloaded_accounts();

//for auto creating directory for saving data inside it
static std::string auto_create_dir();

// manual create directory if auto fail
static std::string manual_create_dir();

// for geting the path any time we call it
//i made it return pointer so we can contrill it every where im our program
static std::string *get_my_path(int path);

//for saving data of accounts like name and age and balance and more
void save(std::unique_ptr<std::vector<Account>>& vec);

//for loading data of accounts like name and age and balance and more
void load(std::unique_ptr<std::vector<Account>>& vec);

//this func filter the accounts before we save it on the harddisk
std::vector<Account> filter(std::array<Account, 1000>& arr);

///////////////////////////////////////////////////////////////////[Abstract Class]//////////////////////////////////////////////////////////////////////////
//using polymorphism all the methods are inherited to the main account class
//we use abstract class to make all methods work on any object created on all classes also it saves a lot of coding and makes ur code much readable
// NOTE :  abstract class cannot have a variables data we use it just to control our classes
class Abstract {

public:
    //seters to set names and other data we need them cuz we can't change any data using objects menu as the variables are private so we dont have access to them
    //the only way is to create a public methods for setting and getting or we could make our variable public but you really dont wanna do that!!!
    virtual void set_name(std::string set) = 0;
    virtual void set_phone_num(std::string set) = 0;
    virtual void set_address(std::string set) = 0;
    virtual void set_age(int set) = 0;
    virtual void set_balance(double set) = 0;
    virtual void set_id(int set) = 0;

    //////////////////////////////////////
    //geters same purpose of setters
    virtual const std::string get_name()const = 0;
    virtual const std::string get_phone_num() const = 0;
    virtual const std::string get_address()const  = 0;
    virtual const int get_age() const = 0;
    virtual const double get_balance() const = 0;
    virtual const int get_id() const = 0;

     //bool deposit, withdraw
     // just a booleans to tell if deposit or withdraw was successful
     virtual bool deposit(double d) = 0;
     virtual bool withdraw(double d) = 0;

     //no virtual constructors are allowed in abstract class so we implement them each class

     //defalut destructor
     //this is the default destructor will be responsible for deleting all object on any class as its virtual
      virtual~Abstract() {}
};

///////////////////////////////////////////////////////////////////[Main Account Class]//////////////////////////////////////////////////////////////////////////

// this is the main account class that control and initialize all the other classes we inherite data from abstract class so we put the name after the Account class
class Account: public Abstract{

public:
    
    // implement seters that we inherited from the abstract class 
    // we use override so we let the compiler help us if there is an error it will show that inheriting is not working well
    //if we dont use override it will work too but the compiler wont show an erorr if by any chance some data is not inherited
     void set_name(std::string set) override {
         this->name = set;
    }
     void set_phone_num(std::string set) override {
         this->phone_num = set;
     }
     void set_address(std::string set) override {

        const char* copy = set.c_str();
        for (int i = 0; copy[i] != '\0'; i++) {
            address[i] = copy[i];
          
        }
     }
     void set_age(int set)override {
         this->age = set;
     }
     void set_balance(double set)override {
         this->balance = set;
     }
     void set_id(int set) override {
         this->id = set;
     }
     ///////////////////////////////////////////////////
     // always make ur geters const so by any chance no data changes u only need to get data here
     // implement geters same as above
     const std::string get_name()const override {
         return this->name;
      }
     const std::string get_phone_num() const override {
         return this->phone_num;
     }
     const std::string get_address()const override {
         return this->address;
      }
     const int get_age() const override {
         return this->age;
      }
     const double get_balance() const override {
         return this->balance;
      }
     const int get_id() const override {
         return this->id;
      }
     //////////////////////////////////////////////
     // ((( This operator are really important declare them even if u dont use them, some std algorithm wont work without them
     // like if u want to add data to set array using std::for_each then u need (operator<) to compare names before adding them as set doesn't accept duplicate
     // implement bool operators binary
     bool operator==(const Account& rhs) const {
         return this->name == rhs.get_name();
     }
      bool operator<(const Account& rhs)const  {
          return name < rhs.name;
      }
      bool operator>(const Account& rhs) const {
          return this->balance > rhs.get_balance();
      }
     //////////////////////////////////////////////
      //bool deposit, withdraw
     bool deposit(double d) override {
         if (d <= 0) {
             std::cout << "Can't Deposite [0$]!!!\n\n";
             return false;
         }
         else {
             std::cout << "[" << std::showpos << d << std::noshowpos << "$], Has Been Added To :[" << this->name << "] Account\n\n";
             this->balance += d;
             std::cout << "Corrent Balance Is:[" << std::fixed << std::setprecision(2)  << this->get_balance() << "$],\n\n";
             return true;
         }
      }
     bool withdraw(double d)override {
         if (d <= this->balance && d > 0) {
                 std::cout << "[-" << d << std::noshowpos << "$], Has Been Withdrawn from :[" << this->name << "] Account\n\n";
                 this->balance -= d;
                 std::cout << "Corrent Balance Is:[" << std::fixed << std::setprecision(2) << this->get_balance() << "$],\n\n";
                 return true;
             }
             else if (d <= 0) {
                 std::cout << "Can't Withdraw [0$]!!!\n\n";
                 return false;
             }
         else {
             std::cout << "Can't Withdraw! [Insufficient Funds]!!!\n\n";
             return false;
         }
      }
     //////////////////////////////////////////////
     //friends of a class its responsible for printing all the info of an object by just saying (std::cout << obj1;)
     // without it we wont be able to print objects data all in one place
     //its called operator <<
     friend std::ostream& operator<<(std::ostream& os, Account& A) {
         os << "\n================Account Info================\n"
             << "Name:[" << A.name << "], Age:[" << A.age << "], "
             << "PhoneNumber:[" << A.phone_num << "]\nAddress:[" << A.address << "]\n"
             << "Balance:[" <<std::fixed<< std::setprecision(2) <<  A.get_balance()  << "$], ID:[" << A.id << "]\n==================<<End>>===================\n";
         return os;
     }

 
//we made it protected so other classes can have access to them but object cant(in main)
protected:
    //protected Data
    std::string name;
    std::string phone_num;
    int age;
    double balance;
    // its important to make address variable as (char) it will have a lot of spaces and u will have problem with string if u try to save address data on hardisk with more than spaces between each
    char address[50];
    int id;
   

 public:

     // constructors->
     // 
     // no Args constructor
     //only initialization to avoid garbage data
     Account() :name{ "" }, phone_num{ "" },age{ NULL }, balance{ NULL }, address{ "" }, id{ NULL } { }

     // full Arg constructor(usually not used!) but good practise to implement them
     Account (std::string name,std::string phone_num,int age,double balance,char address,int id):name{name},phone_num{phone_num},age{age},balance{balance},address{"Unkown"}, id{id} {}

     // no destroctors the Abstract class destructor will be called as its virtual
     
};

///////////////////////////////////////////////////////////////////[Checking Account Class]//////////////////////////////////////////////////////////////////////////
// checking class its inherited from Account class so it has all data that Account class has but with its own version of limitations
// like we added cc variable here so this class can create credit card but saving account class cant
class Checking : public Account {



public:


    //constructors
    
    // passing Args to the base class
    Checking(std::string name, std::string phone_num, int age, double balance, char address, int id) :Account{ name , phone_num , age , balance , address , id } {}

    //pointer to Account Class constructor its needed if we gonna create an object on the heap from checking class to Account class so pointer will point to the chiking account object from the account class object
    Checking(Account* checking = new Account)
    {
        // creating vector of smart unique pointer that point to checking account data on the heap
        //checking if its not on the heap we dont want to create it twoise it will delete the fist data 
        if (vec_checking == nullptr) {
            vec_checking = std::make_unique<std::vector<Account>>();
        }
      
    }
   
    // no destroctors the Abstract class destructor will be called as its virtual

};

///////////////////////////////////////////////////////////////////[Saving Account Class]//////////////////////////////////////////////////////////////////////////

class Saving : public Account{

public:

    // passing Args to the base class
    Saving(std::string name, std::string phone_num, int age, double balance, char address, int id) :Account{ name , phone_num , age , balance , address , id } {}
    //pointer to Account Class constructor its needed if we gonna create an object on the heap from Saving class to Account class so pointer will pointing to the Saving account object from the account class object
    Saving(Account* saving = new Account)
    {
        // creating vector of smart unique pointer that point to saving account data on the heap
        //checking if its not on the heap we dont want to create it twoise it will delete the fist data 
        if (vec_saving == nullptr) {
            vec_saving = std::make_unique<std::vector<Account>>();
        }
    }



    // no destroctors the Abstract class destructor will be called as its virtual

};

/////////////////////////////////////////////////////////////////[Functions implementations]////////////////////////////////////////////////////////////////////////
//refer to function prototype for explanation
bool add(std::unique_ptr<std::vector<Account>>& vec,Account& acc) {

    std::string name = acc.get_name();

    // transfer from uppercase to lowercase
    std::transform(name.begin(), name.end(), name.begin(), std::tolower);

    acc.set_name(name);

    if (vec != nullptr) {
        for (int i = 0; i < vec->size(); i++) {
            if (vec->at(i).get_name() == acc.get_name()) {
                system("CLS");
                std::cout << "Account With Name[" << acc.get_name() << "], Already Exist!\n";
                return false;
            }
        }
    }
    //push account to vector
    vec->emplace_back(acc);

    //save data to harddisk after changes been made
    save(vec);

    return true;
}

//refer to function prototype for explanation
void display(std::unique_ptr<std::vector<Account>>& vec) {

    if (&vec == &vec_checking) {
        std::cout << "\n============================================\nAccounts Type[ << Checking Accounts >> ]\n\n";
    }
    else {
        std::cout << "\n============================================\nAccounts Type[ << Saving Accounts >> ]\n\n";
    }


    std::for_each(vec->begin(), vec->end(), [&](auto& x) {

        std::cout << x;

        });
   
}

//refer to function prototype for explanation
bool is_string(std::string str) {

    int integer{};
    std::stringstream ss{ str };
    if (ss >> integer) {
        return false;
    }
    else {
        return true;
    }
}

//refer to function prototype for explanation
Account* temp_Account(Account* acc)
{
    std::string str{};
    int integer{};
    while (1) {

        std::cout << "\nEnter name:";
        std::cin >> str;
        std::cout << std::endl;
        if (!is_string(str)) {
            system("CLS");
            std::cout << "Name Cannot Contain a Number!!";
        }
        else {
            acc->set_name(str);
            break;
        }
    }

    while (1) {

        std::cout << "\nEnter Age:";
        std::cin >> str;
        std::cout << std::endl;
        if (is_string(str)) {
            system("CLS");
            std::cout << "Age Cannot Contain a String!!";
        }
        else {
            integer = std::stoi(str);
            acc->set_age(integer);
            break;
        }
    }
    while (1) {

        std::cout << "\nEnter Phone Number:";
        std::cin >> str;
        std::cout << std::endl;
        if (is_string(str)) {
            system("CLS");
            std::cout << "Phone Number Cannot Contain a String!!";
        }
        else {
            acc->set_phone_num(str);
            break;
        }
    }
    while (1) {

        std::cout << "\nEnter Address:";
        std::getline(std::cin >> std::ws, str);
        std::cout << std::endl;
        if (!is_string(str)) {
            system("CLS");
            std::cout << "Address Cannot start with number!!";
        }
        else {
            acc->set_address(str);
            break;
        }
    }
    while (1) {

        std::cout << "\nEnter ID Number:";
        std::cin >> str;
        std::cout << std::endl;
        if (is_string(str)) {
            system("CLS");
            std::cout << "ID Number Cannot Contain A String!!";
        }
        else {
            integer = std::stoi(str);
            acc->set_id(integer);
            break;
        }
    }

    return acc;
}

//refer to function prototype for explanation
void create_acc(std::unique_ptr<std::vector<Account>>& vec) {


    Account* acc{nullptr};

    if (&vec == &vec_checking)
    {
        acc = new Checking;
    }
    else
    {
        acc = new Saving;
    }
   

    acc = temp_Account(acc);

    // caling func add to add account to vector
    if (add(vec,*acc)) {
        system("CLS");
        std::cout << "\nAccount Created successfully\n\n";
    }
    else {
        std::cout << "\nFailed To Create The Account!\n\n";
    }

    //delete pointer so we dont have memory leak
    delete acc;

    char selection{};

    while (1) {
        std::cout << "\nDo You Want To Create Another Account?\n\n";
        std::cout << "Enter y(yes) Or n(no): ";
        std::cin >> selection;

        if (selection == 'y' ||selection == 'Y') {
            system("CLS");
             create_acc(vec);
            return;
        }
        else if (selection == 'n' || selection == 'N') {
            system("CLS");
            main_menu();
            return;
        }
        else {
            system("CLS");
            std::cout << "\nInvalid Option!\n";
        }
   
    }

}

//refer to function prototype for explanation
int find_account(std::unique_ptr<std::vector<Account>>& vec, std::string name) {

    for (int index{ 0 }; index < vec->size(); index++) {
        if (vec->at(index).get_name() == name) {
            return index;
        }
    }

    // we can use it to check if function was successfull or not lke if(find_account(__) == -1) then its not successfull
    return -1;
}

//refer to function prototype for explanation
void main_menu() {
    if (vec_checking == nullptr) {
        vec_checking = std::make_unique<std::vector<Account>>();
    }
    if (vec_saving == nullptr) {
        vec_saving = std::make_unique<std::vector<Account>>();
    }

    bool quit{ false };
    std::string str{};
    int selection{ 0 };
    std::fstream f1;
    std::fstream f2;
    std::string* my_c_path = new std::string;
    std::string* my_s_path = new std::string;
    my_c_path = get_my_path(1);
    my_s_path = get_my_path(2);
    do {
        f1.open(*my_c_path, std::ios::in | std::ios::binary);
        f2.open(*my_s_path, std::ios::in | std::ios::binary);
        if (f1.is_open() || f2.is_open())
        {
            f1.close();
            f2.close();
            std::cout << "Auto Save Is:[ON](-_-)\n________________________________\n";
            std::cout << "\nEnter 0 To Restore Data Manually (Optional)\n\n";
        }
        else {
            std::cout << "Auto Save Is:[OFF](0_0) You May Need To Create An Account\n\n________________________________\n";
        }
        if (vec_checking->size() > 0) {
            std::cout << "Number Of Checking Accounts:[" << vec_checking->size() << "]\n\n";
        }
        if (vec_saving->size() > 0) {
            std::cout << "Number Of Saving Accounts:[" << vec_saving->size() << "]\n\n";
        }
        std::cout << "================================\n";
        std::cout << "[[[[WELCOME TO BANK OF LIBYA]]]]\n";
        std::cout << "================================\n";
        std::cout << std::endl;
        std::cout << "1*[Create Checking Account]\n\n";
        std::cout << "2*[Create Saving Account]\n\n";
        std::cout << "3*[*Options & Modify Account]\n\n";
        std::cout << "4*[Manage Account]\n\n";
        std::cout << "5*[Display Checking Accounts]\n\n";
        std::cout << "6*[Display Saving Accounts]\n\n";
        std::cout << "7*[Display All Accounts (C&S) Sorted By Name]\n\n";
        std::cout << "8*[Exit]\n\nChoose From Menu:";

        std::cin >> str;

        if (!is_string(str)) {
            system("CLS");
            selection = std::stoi(str);

            if (selection == 1) {
                create_acc(vec_checking);
                return;
            }
            else if (selection == 2) {
                create_acc(vec_saving);
                return;
            }
            else if (selection == 3) {
                if (vec_checking->size() <= 0 && vec_saving->size() <= 0) {
                    go_back();
                    return;
                }
                else if (vec_checking->size() <= 0) {
                    auto index = select_account(vec_saving);
                    Modify_Account(vec_saving, index);

                    return;
                }
                
                else if (vec_checking->size() > 0 && vec_saving->size() > 0) {
                    system("CLS");
                    std::cout << "\nWhat Type Of Account You Want To Modify?\n\n";
                    std::cout << "1* Checking Account\n\n";
                    std::cout << "2* Saving Account\n\n";
                    std::cout << "3* Go Back\n\n";
                    std::cout << "Select :";
                    std::cin >> str;
                    if (is_string(str)) {
                        system("CLS");
                        std::cout << "Invalid Option!!\n\n";
                    }
                    else {
                        selection = std::stoi(str);
                        if (selection == 1) {
                            system("CLS");
                            auto index = select_account(vec_checking);
                            Modify_Account(vec_checking, index);
                            return;
                        }
                        else if (selection == 2) {
                            system("CLS");
                            auto index = select_account(vec_saving);
                            Modify_Account(vec_saving, index);
                            return;
                        }
                        else if (selection == 3) {
                            system("CLS");
                            main_menu();
                            return;
                        }
                        else {
                            system("Cls");
                            std::cout << "Inavild Option!!\n\n";
                        }
                    }

                }
                else {
                    auto index = select_account(vec_checking);
                    Modify_Account(vec_checking, index);
                    return;
                }
            }
            else if (selection == 4) {

                options();
                return;
            }
            else if (selection == 5) {

                if (vec_checking->size() > 0) {

                    show_accounts(vec_checking);
                    return;
                }
                else {
                    go_back();
                    return;
                }
            }
            else if (selection == 6) {

                if (vec_saving->size() >0) {

                    show_accounts(vec_saving);
                    return;
                }
                else {
                    go_back();
                    return;
                }

            }
            else if (selection == 7) {

                display_all(vec_checking, vec_saving);
                return;
            }
            else if (selection == 8) {
                quit = true;
            }
            else if (selection == 0) {
                if (vec_checking->size() <= 0 && vec_saving->size() <= 0) {
                    system("CLS");
                    std::cout << "Nothing To Restore Data Is Empty!! (0)\n\n";
                }
                else {
                    //manuall data restore
                    load(vec_checking);
                    load(vec_saving);
                    std::cout << "Restored Successfully!\n\n";
                }
            }
            else {
                system("CLS");
                std::cerr << "\n!!!!!Only Numbers From 0-8 Are Accepted!!!!!\n\n";
            }
        }
        else {
            system("CLS");
            std::cerr << "\n!!!!!Only Numbers From 0-8 Are Accepted!!!!!\n\n";
        }
    } while (!quit || selection != 8);

    system("CLS");
    std::cout << "\n[[[[[  GoodBy!  ]]]]\n\n";
    std::cout << "\nPress Enter To Exit Window!\n\n";
    std::cin.get();
    while (1) {
        if (std::cin.get() == '\n') {
            break;
        }
    }
}

//refer to function prototype for explanation
void go_back() {

    std::cout << "\n================================\n";
    std::cout << "There Are No Accounts To Manage!\n\n";
    std::cout << "Please Go Back And Create An Account!\n\n";

    char draw[11]{ 'G', 'o', 'i', 'n', 'g', ' ', 'B', 'a', 'c', 'k', '\0' };
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    for (int i{ 0 }; draw[i] != '\0'; i++) {
        std::cout << draw[i];
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
    }
    system("CLS");
    main_menu();
    //we have to put return; after we call another func within func cuz if we dont then after we try to shut the programe from exit option in user menu it will not shut from first time
    //cuz it has to go back from func call and continue read the codes after the func call
    //return will make the code end here in this function anything after return; wont execute
    return;
}

//refer to function prototype for explanation
void options() {

    system("CLS");

    bool quit{ false };
    std::string str{};
    int selection{ 0 };


    if (vec_checking->size() > 0 || vec_saving->size() > 0) {
        do {
            std::cout << "================================\n";
            std::cout << "[[[[WELCOME TO BANK OF LIBYA]]]]\n";
            std::cout << "================================\n";
            std::cout << "Please Choose An Option:>\n\n";
            std::cout << "1*[Manage Checking Account]\n\n";
            std::cout << "2*[Manage Saving Account]\n\n";
            std::cout << "3*[Go Back]\n\n";
            std::cout << "4*[Exit]\n\nChoose From Menu:";

            std::cin >> str;
            if (!is_string(str)) {
                system("CLS");
                selection = std::stoi(str);
                if (selection == 1) {
                    system("CLS");
                    manage_account(vec_checking);
                    return;
                }
                else if (selection == 2) {
                    system("CLS");
                    manage_account(vec_saving);
                    return;
                }
                else if (selection == 3) {
                    system("CLS");
                    main_menu();
                    return;
                }
                else if (selection == 4) {
           
                    quit = true;

                }

                else {
                    system("CLS");
                    std::cerr << "\n!!!!!Invalid Option!!!!!\n\n";
                    
                }
            }
            else {
                system("CLS");
                std::cerr << "\n!!!!!Only Numbers From 1-4 Are Accepted!!!!!\n\n";
            }
            
        } while (!quit || selection != 4);
    }
    else {
        go_back();
 //we have to put return; after we call another func within func cuz if we dont then after we try to shut the programe from exit option in user menu it will not shut from first time
//cuz it has to go back from func call and continue read the codes after the func call
//return will make the code end here in this function anything after return; wont execute
        return;
    }

    system("CLS");
    std::cout << "\n[[[[[  GoodBy!  ]]]]\n\n";
    std::cout << "\nPress Enter To Exit Window!\n\n";
    std::cin.get();
    while (1) {
        if (std::cin.get() == '\n') {
            break;
        }
    }

}

//refer to function prototype for explanation
void show_accounts(std::unique_ptr<std::vector<Account>>& vec) {

    system("CLS");
    bool quit{ false };
    std::string str{};
    int selection{ 0 };
    

    do {
        display(vec);
        std::cout << "\n===============================\nPlease Choose An Option:>\n\n";
        std::cout << "1*[Go Back]\n\n";
        std::cout << "2*[Exit]\n\nChoose From Menu:";
        std::cin >> str;
        std::stringstream ss{ str };
        if (ss >> selection) {

            selection = std::stoi(str);

            if (selection == 1) {
                system("CLS");
                main_menu();
                //we have to put return; after we call another func within func cuz if we dont then after we try to shut the programe from exit option in user menu it will not shut from first time
               //cuz it has to go back from func call and continue read the codes after the func call
             //return will make the code end here in this function anything after return; wont execute
                return;
            }
            else if (selection == 2) {
            
                quit = true;

            }
            else {
                system("CLS");
                std::cerr << "\n!!!!!Invalid Option!!!!!\n\n";
            }
        }
        else {
            system("CLS");
            std::cerr << "\n!!!!!Only Numbers From 1-2 Are Accepted!!!!!\n\n";
        }

    } while (!quit || selection != 2);

    system("CLS");
    std::cout << "\n[[[[[  GoodBy!  ]]]]\n\n";
    std::cout << "\nPress Enter To Exit Window!\n\n";
    std::cin.get();
    while (1) {
        if (std::cin.get() == '\n') {
            break;
        }
    }
}

//refer to function prototype for explanation
void empty_account(){
    std::cout << "\n================================\n";
    std::cout << "There Are No Accounts To Manage!\n\n";
    std::cout << "Please Go Back And Create An Account!\n\n";

    char draw[11]{ 'G', 'o', 'i', 'n', 'g', ' ', 'B', 'a', 'c', 'k', '\0' };
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    for (int i{ 0 }; draw[i] != '\0'; i++) {
        std::cout << draw[i];
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
    }
    system("CLS");

    options();
    //we have to put return; after we call another func within func cuz if we dont then after we try to shut the programe from exit option in user menu it will not shut from first time
   //cuz it has to go back from func call and continue read the codes after the func call
   //return will make the code end here in this function anything after return; wont execute
    return;
}

//refer to function prototype for explanation
void show_accounts_name(std::unique_ptr<std::vector<Account>>&vec) {
    for (auto& i : *vec) {
        std::cout << "[";
        std::cout << i.get_name() << "],";

    }
}

//refer to function prototype for explanation
int select_account(std::unique_ptr<std::vector<Account>>& vec) {

    static int index{};
    std::string name{};
    while (1) {
        show_accounts_name(vec);
        std::cout << "\n================================\n";
        std::cout << "Enter Name Of Any Account To Manage:";
        std::cin >> name;
        std::transform(name.begin(), name.end(), name.begin(), std::tolower);
        if (!is_string(name)) {
            system("CLS");
            std::cout << "Name Cannot Contain a Number!!\n\n";
        }
        else {
            index = find_account(vec,name);
            if (index == -1) {
                system("CLS");
                std::cout << "{Account With Name[" << name << "] Not Found!}\n Are You Sure This Account Exist?\n\n";
            }
            else {
                return index;
            }
        }
    }
}

//refer to function prototype for explanation
void transfer(std::unique_ptr<std::vector<Account>>& vec, int index, std::string name, double amount) {

     int index_2 = find_account(vec, name);

    if (index_2 == -1) {
        system("CLS");
        std::cout << "Account With Name[" << name << "] Not Found!\n\n <<< Transfer Failed!! >>>\n\n";
    
    }
    else if (index == index_2) {
        system("CLS");
        std::cout << "\nSelf Transfer Not Accepted!\n\n";
      
    }
    else if (vec->at(index).get_balance() < amount) {
        system("CLS");
        std::cout << "\nCan't Transfer! [Insufficient Funds]!!!\n\n";
      
    }
    else if (amount <= 0) {
        system("CLS");
        std::cout << "\nCan't Transfer! [0$]!!!\n\n";

    }
    else {

        system("CLS");
        std::cout << "\n[" << amount << "$] Has Been Transfered From[" << vec->at(index).get_name() << "] To [" << vec->at(index_2).get_name() << "]" << "\n\n";
        vec->at(index).set_balance(vec->at(index).get_balance() - amount);
        vec->at(index_2).set_balance(vec->at(index_2).get_balance() + amount);
        save(vec);
        return;
    }
}

//refer to function prototype for explanation
long long generate_cc(int &&choose) {

    srand((unsigned int)time(NULL));

    long long visa{};
    std::vector<unsigned int> v{};
    v.emplace_back(4);
    v.emplace_back(5);
    v.emplace_back(0);
    v.emplace_back(0);
    while (v.size() < 16) {
     
        if (v.size() >= 10) {
            unsigned int r = rand() % 9 + 1;
            v.emplace_back(r);
       }
        unsigned int r = rand() % 9 + 1;
        std::vector<unsigned int>::iterator find = std::find(v.begin(), v.end(), r);
        if (find == v.end()) {
            v.emplace_back(r);
        }
        else {
            continue;
        }
    }

    std::string fill;

   for(int i = 0 ; i < v.size(); i++){

       visa = v.at(i);
       std::stringstream ss;
       ss << visa;
       fill.append(ss.str());
    
    }

   visa = std::stoll(fill);


    long long master{};
    std::vector<unsigned int> m{};
    m.emplace_back(5);
    m.emplace_back(5);
    m.emplace_back(6);
    m.emplace_back(9);
    while (m.size() < 16) {

        if (m.size() >= 10) {
            unsigned int s = rand() % 9 + 1;
            m.emplace_back(s);
        }
        unsigned int s = rand() % 9 + 1;
        std::vector<unsigned int>::iterator find_m = std::find(m.begin(), m.end(), s);
        if (find_m == m.end()) {
            m.emplace_back(s);
        }
        else {
            continue;
        }
    }

    std::string fill_m;

    for (int i = 0; i < m.size(); i++) {

        master = m.at(i);
        std::stringstream ss_m;
        ss_m << master;
        fill_m.append(ss_m.str());

    }
    master = std::stoll(fill_m);


    switch (choose)
    {
    case 1: {
        return visa;
        break;
        }

    case 2: {
        return master;
        break;
    }

    default:
        return -1;
        break;
    }
}

//refer to function prototype for explanation
std::shared_ptr<std::vector<std::pair<std::string, double>>> list_of_all(std::unique_ptr<std::vector<Account>>& vec_1, std::unique_ptr<std::vector<Account>>& vec_2) {

    //we pair every checking and saving accounts name and balance only  
        std::shared_ptr<std::vector<std::pair<std::string, double>>>my_pair_c;
        std::shared_ptr<std::vector<std::pair<std::string, double>>>my_pair_s;

        my_pair_c = std::make_shared<std::vector<std::pair<std::string, double>>>();

        my_pair_s = std::make_shared<std::vector<std::pair<std::string, double>>>();

        //useing loop to get name and balance and add it to new vector
        for (int x{ 0 }; x < vec_1->size(); x++) {

            auto p_c = std::make_pair(vec_1->at(x).get_name(), vec_1->at(x).get_balance());
            my_pair_c->emplace_back(p_c);

        }

        for (int x{ 0 }; x < vec_2->size(); x++) {

            auto p_s = std::make_pair(vec_2->at(x).get_name(), vec_2->at(x).get_balance());
            my_pair_s->emplace_back(p_s);

        }

        std::shared_ptr<std::vector<std::pair<std::string, double>>>list;
        list = std::make_shared<std::vector<std::pair<std::string, double>>>();
        for (auto& i : *my_pair_c) {

            list->emplace_back(i);

        }
       
        for (auto& i : *my_pair_s) {

            list->emplace_back(i);

        }
        if (vec_1->size() == 0) {
            vec_1 = nullptr;
        }
        else if (vec_2->size() == 0) {
            vec_2 = nullptr;
        }

        //return the list after we pair name and balance
  return list;

}

//refer to function prototype for explanation
void display_all(std::unique_ptr<std::vector<Account>>& vec_1, std::unique_ptr<std::vector<Account>>& vec_2) {

    if (vec_1->size() <= 0 && vec_2->size() <= 0) {
        system("CLS");
        go_back();
        return;
    }
    else if (vec_1 == nullptr) {
        vec_1 = std::make_unique<std::vector<Account>>();
    }
    else if (vec_2 == nullptr) {
        vec_2 = std::make_unique<std::vector<Account>>();
    }

    // we use auto to make compiler detect variable type(good to save writing time)
    auto list = std::make_shared<std::vector<std::pair<std::string, double>>>();

    // call function to pair name and balance and assigning it to list container
    list = list_of_all(vec_checking, vec_saving);

    // sort list by name
    std::sort(list->begin(), list->end());

    //for clearing the screen
    system("CLS");

    std::cout << "All The Checking And Saving Accounts\n\n[Sorted By Name]\n__________________________________\n";

    //ranged based for loop to print the list saves time
    for (auto& i : *list) {

        std::cout << "Name:" << "[" << i.first << "]\tBalance:[" << i.second << "$]\n";

    }

    bool quit{ false };
    int selection{};
    std::string str;

    do {
        std::cout << "\n===============================\nPlease Choose An Option:>\n\n";
        std::cout << "1*[Go Back]\n\n";
        std::cout << "2*[Exit]\n\nChoose From Menu:";
        std::cin >> str;
        std::stringstream ss{ str };
        if (ss >> selection) {

            // to convert string to int
            selection = std::stoi(str);

            if (selection == 1) {
                system("CLS");
                main_menu();
                return;
            }
            else if (selection == 2) {

                quit = true;

            }
            else {
                system("CLS");
                std::cerr << "\n!!!!!Invalid Option!!!!!\n\n";
            }
        }
        else {
            system("CLS");
            std::cerr << "\n!!!!!Only Numbers From 1-2 Are Accepted!!!!!\n\n";
        }

    } while (!quit || selection != 2);
    system("CLS");
    std::cout << "\n[[[[[  GoodBy!  ]]]]\n\n";
    std::cout << "\nPress Enter To Exit Window!\n\n";
    std::cin.get();
    while (1) {
        if (std::cin.get() == '\n') {
            break;
        }
    }
}

//refer to function prototype for explanation
bool valid_name(std::unique_ptr<std::vector<Account>>& vec, std::string name) {
    // loop to see if name is already there
    for (int i = 0; i < vec->size(); i++) {
        if (vec->at(i).get_name() == name) {
            return false;
        }
        else {
            continue;
        }
    }

    return true;
}

//refer to function prototype for explanation
void Modify_Account(std::unique_ptr<std::vector<Account>>& vec, int index) {


    system("CLS");

    bool quit{ false };
    std::string str{};
    int selection{ 0 };

 do{
     if (&vec == &vec_checking) {
         std::cout << "\tChecking Account:>\n\n";
     }
     else {
         std::cout << "\tSaving Account:>\n\n";
     }
        std::cout << "The Account With Name:[" << vec->at(index).get_name() << "], Is Selected\n\n";
        std::cout << "<<<<<<<<<< Modify Account & Options >>>>>>>>>>\n\n";
        std::cout << "1* Change [Name]\n\n";
        std::cout << "2* Change [Age]\n\n";
        std::cout << "3* Change [Phone Number]\n\n";
        std::cout << "4* Change [Address]\n\n";
        std::cout << "5* Change [ID]\n\n";
        std::cout << "6* Delete Account\n\n";
        std::cout << "7* Change Selected Account\n\n";
        std::cout << "8* Go Back\n\n";
        std::cout << "9* Exit\n\n";
        std::cout << "Select :";
        std::cin >> str;
        if (is_string(str)) {
            system("CLS");
            std::cout << "\nOnly Numbers From 1-9 Is Accepted!\n\n";
        }
        else {
            selection = std::stoi(str);

            switch (selection)
            {

            case 1: {
                system("CLS");
                std::cout << "Enter a To Abort\n\n\n\n";
                std::cout << "Enter The New Name: ";
                std::cin >> str;
                if (!is_string(str)) {
                    system("CLS");
                    std::cout << "Name Cannot Contain A Number\n\n";
                }
                else {
                    if (str == "a") {
                        system("CLS");
                        break;
                    }
                    else {
                        if (vec->at(index).get_name() == str)
                        {
                            system("CLS");
                            std::cout << "Cannot Change Its Same Name!\n\n";
                        }else if (!valid_name(vec,str))
                        {
                            system("CLS");
                            std::cout << "Account With The Same Name Already Exist!\n\nTry Another Name\n\n";
                        }
                        else {
                          system("CLS");
                            std::cout << "Name Updated From:[" << vec->at(index).get_name() << "] To:[" << str << "]\n\n";
                            vec->at(index).set_name(str);
                            save(vec);
                            break;
                        }
                    }
                }
                continue;
            }
            case 2: {
                system("CLS");
                std::cout << "Enter 0 To Abort\n\n\n\n";
                std::cout << "Enter The New Age: ";
                std::cin >> str;

                // call func to check user input if its number or letters
                if (is_string(str)) {
                    system("CLS");
                    std::cout << "Age Cannot Contain A String\n\n";
                }
                else {
                    auto age = std::stoi(str);
                    if (age == 0) {
                        system("CLS");
                        break;
                    }
                    else {
                        if (vec->at(index).get_age() == age)
                        {
                            system("CLS");
                            std::cout << "Cannot Change Its Same Age!\n\n";
                        }
                        else {
                            system("CLS");
                            std::cout << "Age Updated From[" << vec->at(index).get_age() << "] To [" << age << "]\n\n";
                            vec->at(index).set_age(age);
                            save(vec);
                            break;
                        }
                    }
                }
                continue;
            }
            case 3: {
                system("CLS");
                std::cout << "Enter 0 To Abort\n\n\n\n";
                std::cout << "Enter The New Phone Number: ";
                std::cin >> str;
                if (is_string(str)) {
                    system("CLS");
                    std::cout << "Phone Number Cannot Contain A String\n\n";
                }
                else {
                    if (str == "0") {
                        system("CLS");
                        break;
                    }
                    else {
                        if (vec->at(index).get_phone_num() == str)
                        {
                            system("CLS");
                            std::cout << "Cannot Change Its Same Phone Number!\n\n";
                        }
                        else {
                            system("CLS");
                            std::cout << "Phone Number Updated From[" << vec->at(index).get_phone_num() << "] To [" << str << "]\n\n";
                            vec->at(index).set_phone_num(str);
                            save(vec);
                            break;
                        }
                    }
                }
                continue;

            }
            case 4: {
                system("CLS");
                std::cout << "Enter a To Abort\n\n\n\n";
                std::cout << "Enter The New Address: ";
                std::getline(std::cin >> std::ws, str);
                if (!is_string(str)) {
                    system("CLS");
                    std::cout << "Address Cannot Start With A Number\n\n";
                }
                else {
                    if (str == "a") {
                        system("CLS");
                        break;
                    }
                    else {
                        if (vec->at(index).get_address() == str)
                        {
                            system("CLS");
                            std::cout << "Cannot Change Its Same Address!\n\n";
                        }
                        else {
                            system("CLS");
                            std::cout << "Address Updated From[" << vec->at(index).get_address() << "] To [" << str << "]\n\n";
                            vec->at(index).set_address(str);
                            save(vec);
                            break;
                        }
                    }
                }
                continue;

            }
            case 5: {

                system("CLS");
                std::cout << "Enter 0 To Abort\n\n\n\n";
                std::cout << "Enter The New ID: ";
                std::cin >> str;
                if (is_string(str)) {
                    system("CLS");
                    std::cout << "ID Cannot Contain A String\n\n";
                }
                else {
                    auto id = std::stoi(str);
                    if (id == 0) {
                        system("CLS");
                        break;
                    }
                    else {
                        if (vec->at(index).get_id() == id)
                        {
                            system("CLS");
                            std::cout << "Cannot Change Its Same ID!\n\n";
                        }
                        else {
                            system("CLS");
                            std::cout << "ID Updated From[" << vec->at(index).get_id() << "] To [" << id << "]\n\n";
                            vec->at(index).set_id(id);
                            save(vec);
                            break;
                        }
                    }
                }
                continue;

            }
            case 6: {

                delete_account(vec,index);
                return;
            }
            case 7: {
                system("CLS");
                index = select_account(vec);
                system("CLS");
                break;
            }
            case 8: {
                system("CLS");
                main_menu();
                return;
            }
            case 9: {

                quit = true;
            }

            default:
                system("CLS");
                std::cout << "Invalid Option!!\n\n";
                break;
            } // end of switch
        }// end of last else
 } while (!quit || selection != 9); // end of while
 system("CLS");
 std::cout << "\n[[[[[  GoodBy!  ]]]]\n\n";
 std::cout << "\nPress Enter To Exit Window!\n\n";
 std::cin.get();
 while (1) {
     if (std::cin.get() == '\n') {
         break;
     }
 }
}

//refer to function prototype for explanation
void delete_account(std::unique_ptr<std::vector<Account>>& vec, int index) {
    std::string* p_c = get_my_path(1);
    std::string* p_s = get_my_path(2);
    system("CLS");

    char selection{};

    while (1) {
        std::cout << "Are You Sure You Want To Delete This Account?\n\n";
        std::cout << "Enter y(yes), n(No) :";
        std::cin >> selection;

        if (selection == 'y' || selection == 'Y') {
            if (vec->size() <= 1) {
              
                if (&vec == &vec_checking) {
                    //there was only 1 account in this case we need to clear the .csv to wipe data
                    std::fstream f;
                    f.open(*p_c, std::ios::out | std::ios::binary);
                    if (f.is_open()) {
                        f.clear();
                        f.close();
                    }
                }
                else {
                    //there was only 1 account in this case we need to clear the .csv to wipe data
                    std::fstream f;
                    f.open(*p_s, std::ios::out | std::ios::binary);
                    if (f.is_open()) {
                        f.clear();
                        f.close();
                    }
                }
                vec->clear();
                vec = nullptr;
                system("CLS");
                std::cout << "Account Deleted successfully!\n\nThere Was Only 1 Account And Now The List Is Empty!\n\n";
                std::cout << "Goin Back To Main Menu in 7 sec\n\n\n\nPlease Wait...";

                // sleep for 7 sec
                std::this_thread::sleep_for(std::chrono::milliseconds(7000));
                system("CLS");
                main_menu();
                return;
            }
            else {
                std::vector<Account>* temp = new std::vector<Account>(vec->begin(), vec->end());

                auto name = vec->at(index).get_name();

                vec->clear();

                for (int i = 0; i < temp->size(); i++) {
                    if (temp->at(i).get_name() == name) {
                        continue;
                    }
                    else {
                        vec->push_back(temp->at(i));
                    }
                }
                delete temp;
                save(vec);
                system("CLS");
                std::cout << "Account Deleted successfully!\n\n";
                std::cout << "Goin Back in 5sec\n\n\n\nPlease Wait...\n\n\n";
                std::this_thread::sleep_for(std::chrono::milliseconds(5000));
                index = select_account(vec);
                Modify_Account(vec, index);
                return;
            }
        }
        else if (selection == 'n' || selection == 'N') {
            system("CLS");
            Modify_Account(vec, index);
            return;

        }
        else {
            system("CLS");
            std::cout << "Invalid Option!\n\n";
        }

    }

}

//refer to function prototype for explanation
void manage_account(std::unique_ptr<std::vector<Account>>& vec) {

    std::string name;
    static int index{};
    double bal{};
    std::string str{};
    int selection{};
    bool quit{ false };

    if (vec->size() <= 0) {
        empty_account();
        return;
    }
    else {
        index = select_account(vec);
        system("CLS");

        do {
            std::cout << "The Account With Name:[" << vec->at(index).get_name() << "], Is Being Managed\n";
            std::cout << "\n===============================\nPlease Choose An Option:>\n\n";
            if (&vec == &vec_checking) {
                std::cout << "[Checking Accounts Options]\n\n";
                std::cout << "1*[Deposite]\n\n";
                std::cout << "2*[Withdraw]\n\n";
                std::cout << "3*[Transfer Money]\n\n";
                std::cout << "4*[Get New Credit Card]\n\n";
                std::cout << "5*[Show My Balance]\n\n";
                std::cout << "6*[Manage Another Account]\n\n";
                std::cout << "7*[Go Back]\n\n";
                std::cout << "8*[Exit]\n\n";
                std::cout << "\nSelect :";
            }
            else {
                std::cout << "[Saving Accounts Options]\n\n";
                std::cout << "Note: [Some Limits Applies]\n\n";
                std::cout << "1*[Deposite * Only 3 Times A Month]\n\n";
                std::cout << "2*[Withdraw * Only 3 Times A Month]\n\n";
                std::cout << "3*[Transfer Money * Only 3 Times A Month]\n\n";
                std::cout << "4*[Show My Balance]\n\n";
                std::cout << "5*[Manage Another Account]\n\n";
                std::cout << "6*[Go Back]\n\n";
                std::cout << "7*[Exit]\n\n";
                std::cout << "\nSelect :";
            }

            std::cin >> str;

            if (!is_string(str)) {
                selection = std::stoi(str);
                switch (selection)
                {
                case 1: {
                    system("CLS");
                    while (1) {
                        std::cout << "\nEnter Amount Of Money To Deposit:";
                        std::cin >> str;

                        if (is_string(str)) {
                            system("CLS");
                            std::cout << "\nBalance Can Cointain Only Numbers!!!\n\n";
                        }
                        else {
                            bal = std::stod(str);
                            system("CLS");
                            vec->at(index).deposit(bal);
                            save(vec);
                            break;
                        }
                    }

                    continue;
                }
                case 2: {
                    system("CLS");
                    while (1) {
                        std::cout << "\nEnter Amount Of Money To Withdraw:";
                        std::cin >> str;

                        if (is_string(str)) {
                            system("CLS");
                            std::cout << "\nBalance Can Cointain Only Numbers!!!\n\n";
                        }
                        else {
                            bal = std::stod(str);
                            system("CLS");
                            vec->at(index).withdraw(bal);
                            save(vec);
                            break;
                        }
                    }

                    continue;
                }
                case 3: {
                    system("CLS");
                    str = "";
                    bal = 0;
                    while (1) {
                      
                        show_accounts_name(vec);
                        std::cout << "\n\nEnter Account Name  To Transfer Money To:";
                        std::cin >> name;
                        if (!is_string(name)) {
                            system("CLS");
                            std::cout << "Name Cannot Contain a Number!!\n\n";
                        }
                        else {
                            system("CLS");
                            std::cout << "Enter Amount Of Money To Transfer:";
                            std::cin >> str;
                            if (is_string(str)) {
                                system("CLS");
                                std::cout << "Amount Accepts Only Numbers!!\n\n";
                            }
                            else {
                                bal = std::stod(str);
                                int ind = find_account(vec, vec->at(index).get_name());
                                transfer(vec,ind, name, bal);
                                save(vec);
                                break;
                            }
                        }
                    }

                    continue;
                }
                case 4: {
                    system("CLS");
                    if (&vec == &vec_saving) {
                        system("CLS");
                        std::cout << std::endl;
                        std::cout << "[" << vec->at(index).get_name() << "], Account Balance Is:[" << vec->at(index).get_balance() << "$]";
                        std::cout << std::endl;
                        std::cout << std::endl;
                        break;
                    }
                    else {
                        while (1) {

                            std::cout << "\n[[[ Choose Credit Card Type ]]]\n\n";
                            std::cout << "\n1* VISA\n\n";
                            std::cout << "\n2* MASTER CARD\n\n";
                            std::cout << "\n3* Abort\n\n";
                            std::cout << "\nSelect :";
                            std::cin >> str;
                            if (is_string(str)) {
                                system("CLS");
                                std::cout << "String Not Accepted Please Enter Number From 1-3!\n\n";
                            }
                            else {
                                int cc = std::stoi(str);

                                if (cc == 1) {
                                    system("CLS");
                                    std::cout << "Generating Visa For[" << vec->at(index).get_name() << "], Account\n\n";
                                    std::cout << "Please Wait";
                                    std::this_thread::sleep_for(std::chrono::milliseconds(500));
                                    std::cout << ".";
                                    std::this_thread::sleep_for(std::chrono::milliseconds(350));
                                    std::cout << ".";
                                    std::this_thread::sleep_for(std::chrono::milliseconds(350));
                                    std::cout << ".";
                                    std::this_thread::sleep_for(std::chrono::milliseconds(350));
                                    std::cout << ".";
                                    std::this_thread::sleep_for(std::chrono::milliseconds(350));
                                    std::cout << ".";
                                    std::this_thread::sleep_for(std::chrono::milliseconds(350));
                                    std::cout << ".";
                                    std::this_thread::sleep_for(std::chrono::milliseconds(350));
                                    std::cout << ".";
                                    std::cout << std::endl << std::endl;
                                    system("CLS");
                                    std::cout << "[Visa Card]" << ": [";
                                    std::cout << generate_cc(1);
                                    std::cout << "]\n\n";
                                    break;

                                }
                                else if (cc == 2) {
                                    system("CLS");
                                    std::cout << "Generating Master Card For[" << vec->at(index).get_name() << "], Account\n\n";
                                    std::cout << "Please Wait";
                                    std::this_thread::sleep_for(std::chrono::milliseconds(500));
                                    std::cout << ".";
                                    std::this_thread::sleep_for(std::chrono::milliseconds(350));
                                    std::cout << ".";
                                    std::this_thread::sleep_for(std::chrono::milliseconds(350));
                                    std::cout << ".";
                                    std::this_thread::sleep_for(std::chrono::milliseconds(350));
                                    std::cout << ".";
                                    std::this_thread::sleep_for(std::chrono::milliseconds(350));
                                    std::cout << ".";
                                    std::this_thread::sleep_for(std::chrono::milliseconds(350));
                                    std::cout << ".";
                                    std::this_thread::sleep_for(std::chrono::milliseconds(350));
                                    std::cout << ".";
                                    std::cout << std::endl << std::endl;
                                    system("CLS");
                                    std::cout << "[Master Card]" << ": [";
                                    std::cout << generate_cc(2);
                                    std::cout << "]\n\n";
                                    break;
                                }
                                else if (cc == 3) {
                                    system("CLS");
                                    break;
                                }
                                else if (cc >= 4) {
                                    system("CLS");
                                    std::cout << "\nInvalid Option!\n\nPlease Choose From <1-3>\n\n";
                                }

                            }
                        }
                    }
                    continue;
                }
                
                case 5: {
                    if (&vec == &vec_saving) {
                        system("CLS");
                        index = select_account(vec);
                        system("CLS");
                        break;
                    }
                    else {
                        system("CLS");
                        std::cout << std::endl;
                        std::cout << "[" << vec->at(index).get_name() << "], Account Balance Is:[" << vec->at(index).get_balance() << "$]";
                        std::cout << std::endl;
                        std::cout << std::endl;
                        break;
                    }
                }
                case 6: {
                    if (&vec == &vec_saving) {
                        system("CLS");
                        options();
                        return;
                      
                    }
                    else {

                        system("CLS");
                        index = select_account(vec);
                        system("CLS");
                        break;
                    }
                }
                case 7: {
                    if (&vec == &vec_saving) {
                        quit = true;
                    }
                    else {
                       
                        system("CLS");
                        options();
                        return;

                    }
                }
                case 8: {
                    if (&vec == &vec_saving) {
                        system("CLS");
                        std::cerr << "\n!!!!!Invalid Option!!!!!\n\n";
                    }
                    else {
                        quit = true;
                    }
                }

                default: {
                    system("CLS"); 
                    std::cerr << "\n!!!!!Invalid Option!!!!!\n\n";
                }

                }
            }
            else {
                system("CLS");
                if (&vec == &vec_saving) {
                    std::cerr << "\n!!!!!Only Numbers From 1-7 Are Accepted!!!!!\n\n";
                }
                else {
                    std::cerr << "\n!!!!!Only Numbers From 1-8 Are Accepted!!!!!\n\n";
                }
            }
        } while (!quit);
    }
    system("CLS");
    std::cout << "\n[[[[[  GoodBy!  ]]]]\n\n";
    std::cout << "\nPress Enter To Exit Window!\n\n";
    std::cin.get();
    while (1) {
        if (std::cin.get() == '\n') {
            break;
        }
    }
  
}

//refer to function prototype for explanation
void create_preloaded_accounts() {
    //creating preloaded accounts on the heap then deleting them
    ///////////////////////////////
    Account* c_acc1 = new Checking;
    Account* c_acc2 = new Checking;
    Account* c_acc3 = new Checking;
    Account* c_acc4 = new Checking;
    Account* c_acc5 = new Checking;
    Account* c_acc6 = new Checking;
    Account* c_acc7 = new Checking;
    Account* c_acc8 = new Checking;
    Account* c_acc9 = new Checking;
    Account* c_acc10 = new Checking;
    ////////////////////////////////
    Account* s_acc1 = new Saving;
    Account* s_acc2 = new Saving;
    Account* s_acc3 = new Saving;
    Account* s_acc4 = new Saving;
    Account* s_acc5 = new Saving;
    Account* s_acc6 = new Saving;
    Account* s_acc7 = new Saving;
    Account* s_acc8 = new Saving;
    Account* s_acc9 = new Saving;
    Account* s_acc10 = new Saving;
    //////////////////////////////
    c_acc1->set_name("saif");
    c_acc1->set_age(22);
    c_acc1->set_address("UNKOWN");
    c_acc1->set_balance(199.20);
    c_acc1->set_phone_num("0910000000");
    c_acc1->set_id(101010);
    ///////////////////////////////////
    c_acc2->set_name("ahmed");
    c_acc2->set_age(18);
    c_acc2->set_address("UNKOWN");
    c_acc2->set_balance(22.54);
    c_acc2->set_phone_num("0920000000");
    c_acc2->set_id(79873);
    ///////////////////////////////////
    c_acc3->set_name("mosa");
    c_acc3->set_age(32);
    c_acc3->set_address("UNKOWN");
    c_acc3->set_balance(1053.22);
    c_acc3->set_phone_num("0910000000");
    c_acc3->set_id(324234);
    ///////////////////////////////////
    c_acc4->set_name("ali");
    c_acc4->set_age(30);
    c_acc4->set_address("UNKOWN");
    c_acc4->set_balance(233.32);
    c_acc4->set_phone_num("0920000000");
    c_acc4->set_id(243543);
    ///////////////////////////////////
    c_acc5->set_name("nedal");
    c_acc5->set_age(23);
    c_acc5->set_address("UNKOWN");
    c_acc5->set_balance(5038.23);
    c_acc5->set_phone_num("0910000000");
    c_acc5->set_id(23423);
    ///////////////////////////////////
    c_acc6->set_name("salim");
    c_acc6->set_age(44);
    c_acc6->set_address("UNKOWN");
    c_acc6->set_balance(8032.44);
    c_acc6->set_phone_num("0920000000");
    c_acc6->set_id(2326665);
    ///////////////////////////////////
    c_acc7->set_name("mohammed");
    c_acc7->set_age(35);
    c_acc7->set_address("UNKOWN");
    c_acc7->set_balance(900);
    c_acc7->set_phone_num("0910000000");
    c_acc7->set_id(232446);
    ///////////////////////////////////
    c_acc8->set_name("khalifa");
    c_acc8->set_age(29);
    c_acc8->set_address("UNKOWN");
    c_acc8->set_balance(2230.22);
    c_acc8->set_phone_num("0910000000");
    c_acc8->set_id(220933);
    ///////////////////////////////////
    c_acc9->set_name("tariq");
    c_acc9->set_age(26);
    c_acc9->set_address("UNKOWN");
    c_acc9->set_balance(20);
    c_acc9->set_phone_num("0910000000");
    c_acc9->set_id(867533);
    ///////////////////////////////////
    c_acc10->set_name("omar");
    c_acc10->set_age(55);
    c_acc10->set_address("UNKOWN");
    c_acc10->set_balance(10230.44);
    c_acc10->set_phone_num("0920000000");
    c_acc10->set_id(8978433);
    ////////////////////////////////////////////
    s_acc1->set_name("osama");
    s_acc1->set_age(39);
    s_acc1->set_address("UNKOWN");
    s_acc1->set_balance(50);
    s_acc1->set_phone_num("0910000000");
    s_acc1->set_id(56346);
    ///////////////////////////////////
    s_acc2->set_name("bilal");
    s_acc2->set_age(41);
    s_acc2->set_address("UNKOWN");
    s_acc2->set_balance(2340.3);
    s_acc2->set_phone_num("0920000000");
    s_acc2->set_id(346555);
    ///////////////////////////////////
    s_acc3->set_name("kamal");
    s_acc3->set_age(48);
    s_acc3->set_address("UNKOWN");
    s_acc3->set_balance(29032.34);
    s_acc3->set_phone_num("0910000000");
    s_acc3->set_id(675645);
    ///////////////////////////////////
    s_acc4->set_name("sami");
    s_acc4->set_age(31);
    s_acc4->set_address("UNKOWN");
    s_acc4->set_balance(9923.2);
    s_acc4->set_phone_num("0920000000");
    s_acc4->set_id(45466);
    ///////////////////////////////////
    s_acc5->set_name("salah");
    s_acc5->set_age(17);
    s_acc5->set_address("UNKOWN");
    s_acc5->set_balance(250);
    s_acc5->set_phone_num("0910000000");
    s_acc5->set_id(56453);
    ///////////////////////////////////
    s_acc6->set_name("ibrahim");
    s_acc6->set_age(29);
    s_acc6->set_address("UNKOWN");
    s_acc6->set_balance(1503.2);
    s_acc6->set_phone_num("0920000000");
    s_acc6->set_id(2774334);
    ///////////////////////////////////
    s_acc7->set_name("moez");
    s_acc7->set_age(25);
    s_acc7->set_address("UNKOWN");
    s_acc7->set_balance(750);
    s_acc7->set_phone_num("0920000000");
    s_acc7->set_id(67543);
    ///////////////////////////////////
    s_acc8->set_name("mussab");
    s_acc8->set_age(27);
    s_acc8->set_address("UNKOWN");
    s_acc8->set_balance(122.54);
    s_acc8->set_phone_num("0920000000");
    s_acc8->set_id(487933);
    ///////////////////////////////////
    s_acc9->set_name("jamal");
    s_acc9->set_age(51);
    s_acc9->set_address("UNKOWN");
    s_acc9->set_balance(1932.43);
    s_acc9->set_phone_num("0910000000");
    s_acc9->set_id(897983);
    ///////////////////////////////////
    s_acc10->set_name("idrees");
    s_acc10->set_age(47);
    s_acc10->set_address("UNKOWN");
    s_acc10->set_balance(6500);
    s_acc10->set_phone_num("0920000000");
    s_acc10->set_id(774775);
    //////////////////////////////////////////////////
    vec_checking = std::make_unique<std::vector<Account>>();
    vec_saving = std::make_unique<std::vector<Account>>();
    //////////////////////////////////////
    vec_checking->emplace_back(*c_acc1);
    vec_checking->emplace_back(*c_acc2);
    vec_checking->emplace_back(*c_acc3);
    vec_checking->emplace_back(*c_acc4);
    vec_checking->emplace_back(*c_acc5);
    vec_checking->emplace_back(*c_acc6);
    vec_checking->emplace_back(*c_acc7);
    vec_checking->emplace_back(*c_acc8);
    vec_checking->emplace_back(*c_acc9);
    vec_checking->emplace_back(*c_acc10);
    ///////////////////////////////////
    vec_saving->emplace_back(*s_acc1);
    vec_saving->emplace_back(*s_acc2);
    vec_saving->emplace_back(*s_acc3);
    vec_saving->emplace_back(*s_acc4);
    vec_saving->emplace_back(*s_acc5);
    vec_saving->emplace_back(*s_acc6);
    vec_saving->emplace_back(*s_acc7);
    vec_saving->emplace_back(*s_acc8);
    vec_saving->emplace_back(*s_acc9);
    vec_saving->emplace_back(*s_acc10);
    ///////////////////////////////////
    delete c_acc1;
    delete c_acc2;
    delete c_acc3;
    delete c_acc4;
    delete c_acc5;
    delete c_acc6;
    delete c_acc7;
    delete c_acc8;
    delete c_acc9;
    delete c_acc10;
    ///////////////////////////////////
    delete s_acc1;
    delete s_acc2;
    delete s_acc3;
    delete s_acc4;
    delete s_acc5;
    delete s_acc6;
    delete s_acc7;
    delete s_acc8;
    delete s_acc9;
    delete s_acc10;
    ///////////////////////////////////
    system("CLS");
    //save changes
    save(vec_checking);
    save(vec_saving);
    main_menu();
    return;
}

//refer to function prototype for explanation
void menu() {
    //first window 
        vec_checking = std::make_unique<std::vector<Account>>();
        vec_saving = std::make_unique<std::vector<Account>>();
        //load data if it exist
        load(vec_checking);
        load(vec_saving);

        //if data exist then its not first run we wont show this menu we skip it
    if (vec_checking->size() > 0 || vec_saving->size() > 0) {
        system("CLS");
        main_menu();
        return;
    }
    std::string str{};
    int selection{};
    
    while (1) {
        std::cout << "____________________________________________\n# This Option Will Show Only During First Run\n Or If There Are No Account Created #\n____________________________________________\n\n";
        std::cout << "\n\nPlease Choose An Option:>\n\n\n";
        std::cout << "1* [[ Enter With PreLoaded Accounts ]]\n\n";
        std::cout << "2* [[ I Want To Create Accounts By MySelf ]]\n\n";
        std::cout << "3* [[ Exit ]]\n\n\n\n\n\n";
        std::cout << "Select :";
        std::cin >> str;
        if (is_string(str)) {
            system("CLS");
            std::cout << "String Not Accepted!!\n\n";
        }
        else {
            selection = std::stoi(str);

            if (selection == 1) {
                system("CLS");
                create_preloaded_accounts();
                return;
            }
            else if (selection == 2) {
                system("CLS");
                main_menu();
                return;
            }
            else if (selection == 3) {
                break;
            }
            else {
                system("CLS");
                std::cout << "Invalid Option!!\n\n";

            }

        }



    }

    system("CLS");
    std::cout << "\n[[[[[  GoodBy!  ]]]]\n\n";
    std::cout << "\nPress Enter To Exit Window!\n\n";
    std::cin.get();
    while (1) {
        if (std::cin.get() == '\n') {
            break;
        }
    }

}

//refer to function prototype for explanation
static std::string auto_create_dir() {

    // we call fstream and create variable f to control in and out files on hardisk
    std::fstream f;


    static char path[50] = "C:\\\\Bank_Data_Backup";

     while (1) {
         // crearte folder with _mkdir
         if (_mkdir(path) == -1) {
             std::string error = strerror(errno);
             if (error == "File exists") {
                 break;
             }
             else {
                 for (int x = 0; x < 50; x++) {
                     path[x] = '\0';
                 }
                 // if auto create fail we call manual func
                 std::string my_path = manual_create_dir();

                 const char* p = my_path.c_str();
                 for (int i = 0; p[i] != '\0'; i++) {
                     path[i] = p[i];
                 }
             }
         }
         else {
             break;
         }
     }
     return path;
}

//refer to function prototype for explanation
static std::string manual_create_dir() {

    std::fstream f;

    system("CLS");
    static char path[49] = "";
    static int length{0};
 
    while (1) {
        std::cout << "\nAn Error Occurred While Attempting To Create The Directory To Save Data\n\n Please Enter Path To Save Data Manually\n\n Example:(c:\\\\Backup\\\\)\n\n\nEnter Only Path And Folder Name :";
        std::cin >> path;
     
        if (is_string(path)) {
            for (int x = 0; path[x] != '\0'; x++)
            {
                length++;
            }
            if (length < 5) {
                system("CLS");
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cerr << "Path Cannot Have Less Than 5 Characters!!!\n\n\n";
                length = 0;
            }
            else {
                system("CLS");
           
                return path;
            }
           
        }
        else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            system("CLS");
            std::cerr << "Please Make Sure You Entered Valid Path!!!\n\n\n";
        }
    }

}

//refer to function prototype for explanation
static std::string* get_my_path(int path) {

    //storing 2 path 1 for vector of checking accounts anthe 2 for vector of saving accounts
    static std::string* my_path;
    static std::string* my_path2;
    if (my_path2 == nullptr) {
        my_path2 = new std::string;
    }

    if (my_path == nullptr) {
       my_path = new std::string;
    }
    
    // we call func to create folder and return folder path
    *my_path = auto_create_dir();
    *my_path2 = auto_create_dir();

    
    char copy = my_path->back();
    char copy2 = my_path2->back();

    //check if path has \\ in the end if not we add it
    if (copy != '\\') {
        my_path->append("\\\\");
    }
    if (copy2 != '\\') {
        my_path2->append("\\\\");
    }
    my_path->append("c_do_not_edit.csv");
    my_path2->append("s_do_not_edit.csv");

    switch (path)
    {
    case 1: {

      
        return my_path;
        break;
    }

    case 2: {
       
        return my_path2;
        break;
    }

    default:
        return 0;
        break;
    }


}

//refer to function prototype for explanation
std::vector<Account> filter(std::array<Account, 1000>& arr) {

    //here we adding accounts that std::array holds to a set container so we avoid duplicated accounts and it also filter empty data
    //it give us clean accounts list to then we can return it from this func and save it on hardisk
    std::set<Account>set;
    for (int i = 0; i < arr.size(); i++) {

        set.insert(arr.at(i));
        
 }
    //here we add account from set to vector
    std::vector<Account>vec(set.begin(), set.end());

    //we will always have 1 account in front that its garbage so we want to delete it but vector only pop from back so we reverse and delete it then we reverse back 
    std::reverse(vec.begin(), vec.end());
    vec.pop_back();
    std::reverse(vec.begin(), vec.end());

    return vec;
}

//refer to function prototype for explanation
void save(std::unique_ptr<std::vector<Account>>& vec) {
    //fstream to control files on hardisk
    std::fstream f;
    
    //////////////////////////////////////////////////////
    static std::string* my_c_path = new std::string;
    static std::string* my_s_path = new std::string;
    my_c_path = get_my_path(1);
    my_s_path = get_my_path(2);
    //////////////////////////////////////////////////////
    if (vec != nullptr) 
    {
    //////////////////////////////////////////////////////
        //here we adding all the accounts of vector to an std::array cuz i had issues with vector when it comes to save accounts to hardisk
        std::array<Account, 1000>* arr = nullptr;
        if (arr == nullptr) {
            arr = new  std::array<Account, 1000>;
        }
        for (int i = 0; i < vec->size(); i++) {
            arr->at(i) = vec->at(i);
        }
    //////////////////////////////////////////////////////
        if (&vec == &vec_checking) 
        {
            //open file in binary mode 
            f.open(*my_c_path, std::ios::out | std::ios::binary);
            if(f.is_open())
            {
                //we write accounts data that array has like name and more to the hardisk
                //we have to specify the size in byte so we use array size * sizeof Account class, you have to put the write size here otherwise u endup with bad error some times even in run time
                f.write((char*)arr, arr->size() * sizeof(Account));
                    f.close();
            }
            else {
              
                    system("CLS");
                    std::cout << "\nError Saving Checking Accounts Data!\n\nAuto BackUp Is Not Activated!\n\n";
                
            }


        }
        else {
            f.open(*my_s_path, std::ios::out | std::ios::binary);
            if (f.is_open())
            {
                //we have to specify the size in byte so we use array size * sizeof Account class, you have to put the write size here otherwise u endup with bad error some times even in run time
                f.write((char*)arr, arr->size() * sizeof(Account));
                f.close();
               
            }
            else {
             
                    system("CLS");
                    std::cout << "\nError Saving Saving Accounts Data!\n\nAuto BackUp Is Not Activated!\n\n";
                
            }
        }
    }
    

}

//refer to function prototype for explanation
void load(std::unique_ptr<std::vector<Account>>& vec) {

    std::fstream f;

    //////////////////////////////////////////////////////
    static std::string* my_c_path = new std::string;
    static std::string* my_s_path = new std::string;
    my_c_path = get_my_path(1);
    my_s_path = get_my_path(2);
    //////////////////////////////////////////////////////
    if (vec == nullptr) {
        vec = std::make_unique<std::vector<Account>>();
    }
        //////////////////////////////////////////////////////
    std::array<Account, 1000>* arr = nullptr;
    if (arr == nullptr) {
        arr = new  std::array<Account, 1000>;
    }
        //////////////////////////////////////////////////////
        if (&vec == &vec_checking)
        {
            f.open(*my_c_path, std::ios::in | std::ios::binary);
            if (f.is_open())
            {
                //reding the dada we have stored from hardisk
                f.read((char*)arr, arr->size() * sizeof(Account));
                f.close();
               
                auto v_filter = filter(*arr);
                if (vec->size() < v_filter.size()) {
                    vec_checking->clear();
                    for (int i = 0; i < v_filter.size(); i++) {
                        vec_checking->emplace_back(v_filter.at(i));
                    }
                }
             
            }
            else {
                if (vec_checking->size() > 0) {
                    system("CLS");
                    std::cout << "\nError Restoring Checking Accounts Data!!!\n\n";
                }
            }


        }
        else {
            f.open(*my_s_path, std::ios::in | std::ios::binary);
            if (f.is_open())
            {
                f.read((char*)arr, arr->size() * sizeof(Account));
                f.close();

                auto v_filter = filter(*arr);
                if (vec_saving->size() < v_filter.size()) {
                    vec_saving->clear();
                    for (int i = 0; i < v_filter.size(); i++) {
                        vec_saving->emplace_back(v_filter.at(i));
                    }
                }
         
            }
            else {
                if (vec_saving->size() > 0) {
                    system("CLS");
                    std::cout << "\nError Restoring Saving Accounts Data!!!\n\n";
                }
            }
        }
}

//////////////////////////////////////////////////////////////////////[<<<< Main >>>>]////////////////////////////////////////////////////////////////////////////////

int main()
{
   
    //calling first menu to show
    menu();







    return 0;
}
