#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<fstream>
#include<windows.h>
#include <limits>
#include <ctime>
#include <sstream>
#include <regex> 
#include <iomanip>
#include <vector>
#include <chrono>
#include <thread>

using namespace std;


class bank{ 
private:
	float balance;
	string id,pass,name,fname,address,phone,pin;
	const string RESET = "\033[0m";
    const string WHITE = "\033[1;37m";       
    const string OFF_WHITE = "\033[1;97m";  
    const string GREEN = "\033[1;32m";      
    const string RED = "\033[1;31m";       
	public:
	void menu();
	void bank_management();
	void atm_management();
	void new_user();
	void already_user();
	void deposit();
	void withdraw();
	void transfer(); 
    void payment();
    void search();
	void edit();
	void del();
	void show_records();
	void show_payment();
	void user_balance();
	void withdraw_atm();
	void check_detail();
	void setColor(const string& color);
    void printHeader();
    void printDivider();
    bool isValidPhoneNumber(const string& phone);
    bool isValidPinOrPassword(const string& value);	
    void viewHistory();
	void sendFakeSMS(const string& phoneNumber, const string& message);
	void calculateBankStats();
	void morefeatures();
	void loansystem();
	void loan_application();
	void manage_loans();
	void view_loan_status();	}; 
    
	
	
void bank::setColor(const string& color) {
    cout << color;
};

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}


#define RESET "\033[0m"
#define WHITE "\033[1;37m"
#define OFF_WHITE "\033[1;97m"
#define GREEN "\033[1;32m"

void setColor(const string& color) {
    cout << color;
}




void printLine(int length, const string& color) {
    setColor(color);
    for (int i = 0; i < length; i++) {
        cout << "=";
        std::this_thread::sleep_for(std::chrono::milliseconds(1)); 
    }
    cout << RESET << endl;
}


void introduction() {
    system("cls");

    cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t  ";
    printLine(30, WHITE);
    cout << "\t\t\t\t\t   ";
    printLine(28, OFF_WHITE);
    cout << "\t\t\t\t\t    ";
    printLine(26, GREEN);

    
    setColor(GREEN);
    cout << "\n\n\t\t\t\t\t        BANKING APPLICATION";
    PlaySound(TEXT("sound\\well-banking.wav"), NULL, SND_FILENAME | SND_ASYNC);
    cout << "\n\n\t\t\t\t\t\t   PROJECT IN C++";
    setColor(RESET);

    cout << "\n\n\t\t\t\t\t    ";
    printLine(26, GREEN);
    cout << "\t\t\t\t\t   ";
    printLine(28, OFF_WHITE);
    cout << "\t\t\t\t\t  ";
    printLine(30, WHITE);

    getch();  
    system("cls");

    cout << "\n\n\n\n\n\n\n\t\t\t\t\t  ";
    printLine(30, WHITE);
    cout << "\t\t\t\t\t   ";
    printLine(28, OFF_WHITE);
    cout << "\t\t\t\t\t    ";
    printLine(26, GREEN);

    
    setColor(GREEN);
    PlaySound(TEXT("sound\\creators.wav"), NULL, SND_FILENAME | SND_ASYNC);
    cout << "\n\n\t\t\t\t\t      CREATED BY ZAIN ALI SHAH";
    cout << "\n\n\t\t\t\t\t            TEAM VISION";
    cout << "\n\n\t\t\t\t\t\tPAK ASKARI COLLEGE";
    setColor(RESET);

    cout << "\n\n\t\t\t\t\t    ";
    printLine(26, GREEN);
    cout << "\t\t\t\t\t   ";
    printLine(28, OFF_WHITE);
    cout << "\t\t\t\t\t  ";
    printLine(30, WHITE);

    getch();  
    
    
	system("cls");

    cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t  ";
    printLine(30, WHITE);
    cout << "\t\t\t\t\t   ";
    printLine(28, OFF_WHITE);
    cout << "\t\t\t\t\t    ";
    printLine(26, GREEN);

   
    setColor(GREEN);
    cout << "\n\n\t\t\t\t\t           WELLCOME TO";
    PlaySound(TEXT("sound\\wellzs.wav"), NULL, SND_FILENAME | SND_ASYNC);
    cout << "\n\n\t\t\t\t\t\t     ZS BANK";
    setColor(RESET);

    cout << "\n\n\t\t\t\t\t    ";
    printLine(26, GREEN);
    cout << "\t\t\t\t\t   ";
    printLine(28, OFF_WHITE);
    cout << "\t\t\t\t\t  ";
    printLine(30, WHITE);

    getch();  
	
};


void bank::menu() {  
p:
    system("cls");
    int choice;
    char ch;
    string email, pin, pass;
    
    setColor(GREEN);
    PlaySound(TEXT("sound\\where-go.wav"), NULL, SND_FILENAME | SND_ASYNC);
    cout << "\n\n\n\n\n\n\t\t\t\t\t      ====================";
    cout << "\n\t\t\t\t\t          CONTROL PANEL";
    cout << "\n\t\t\t\t\t      ====================";
    
    setColor(OFF_WHITE);
    cout << "\n\n\t\t\t    1. Bank Management";
    cout << "\n\t\t\t    2. ATM Management";
    cout << "\n\t\t\t    3. Loan System";
    cout << "\n\t\t\t    4. Exit";
    
    setColor(GREEN);
    cout << "\n\n\t\t\t    Enter Your Choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
    	
     system("cls");
    setColor(GREEN);
    cout << "\n\n\n\n\n\n\t\t\t\t\t      ====================";
    cout << "\n\t\t\t\t\t          ADMIN LOGIN";
    cout << "\n\t\t\t\t\t      ====================";
    PlaySound(TEXT("sound\\admin-lo.wav"), NULL, SND_FILENAME | SND_SYNC);
    PlaySound(TEXT("sound\\enemail.wav"), NULL, SND_FILENAME | SND_ASYNC);
    
        setColor(OFF_WHITE);
        cout << "\n\n\t\t\t    E-mail : ";
        cin >> email;
        PlaySound(TEXT("sound\\enterpin.wav"), NULL, SND_FILENAME | SND_ASYNC);
        cout << "\n\t\t\t    Pin Code : ";
        for (int i = 1; i <= 5; i++) {
            ch = getch();
            pin += ch;
            cout << "*";
        }
        PlaySound(TEXT("sound\\enterpass.wav"), NULL, SND_FILENAME | SND_ASYNC);
        cout << "\n\t\t\t    Password : ";
        for (int i = 1; i <= 5; i++) {
            ch = getch();
            pass += ch;
            cout << "*";
        }
        
        if (email == "zain@gmail.com" && pin == "11111" && pass == "00000") {
            setColor(GREEN);
            cout << "\n\n\t\t\t    Login Successful!";
            bank_management();
        } else {
        	PlaySound(TEXT("sound\\incorrect-id.wav"), NULL, SND_FILENAME | SND_ASYNC);
           setColor(RED);
            cout << "\n\n\t\t\t    ERROR: Your E-mail, Pin & Password are Incorrect!";
        }
    break;
        
    case 2:
    atm_management();
    break;
        
    case 3:
    loansystem();
    break;
        
    case 4:
    PlaySound(TEXT("sound\\exist.wav"), NULL, SND_FILENAME | SND_ASYNC);
    exit(0);
        
    default:
    	PlaySound(TEXT("sound\\inva-choice.wav"), NULL, SND_FILENAME | SND_ASYNC);
        setColor(RED);
        cout << "\n\t\t\t    ERROR: Invalid Choice! Please Try Again...";
    };
    
    getch();
    goto p;
};   


		
void bank::bank_management() {
p:
    system("cls");
    int choice;
    PlaySound(TEXT("sound\\ba-manage.wav"), NULL, SND_FILENAME | SND_ASYNC);
    setColor(GREEN);
    cout << "\n\n\n\n\n\t\t\t\t        ================================";
    cout << "\n\t\t\t\t             BANK MANAGEMENT SYSTEM";
    cout << "\n\t\t\t\t        ================================";

    setColor(OFF_WHITE);
    cout << "\n\t\t\t       1. New User";
    cout << "\n\t\t\t       2. Already User";
    cout << "\n\t\t\t       3. Deposit Option";
    cout << "\n\t\t\t       4. Withdraw Option";
    cout << "\n\t\t\t       5. Transfer Option";
    cout << "\n\t\t\t       6. Payment Option";
    cout << "\n\t\t\t       7. Search User";
    cout << "\n\t\t\t       8. Edit User Record";
    cout << "\n\t\t\t       9. Delete User Record";
    cout << "\n\t\t\t       10. Show All Records";
    cout << "\n\t\t\t       11. Show All Payments";
    cout << "\n\t\t\t       12. More Features";  
    cout << "\n\t\t\t       13. Go Back";

    setColor(GREEN);
    cout << "\n\t\t\t       Enter Your Choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
        new_user();
        break;
    case 2:
        already_user();
        break;
    case 3:
        deposit();
        break;
    case 4:
        withdraw();
        break;
    case 5:
        transfer();
        break;
    case 6:
        payment();
        break;
    case 7:
        search();
        break;
    case 8:
        edit();
        break;
    case 9:
        del();
        break;
    case 10:
        show_records();
        break;
    case 11:
        show_payment();
        break;
    case 12:
        morefeatures();  
        break;
    case 13:
        menu();
        break;
    default:
    	PlaySound(TEXT("sound\\inva-choice.wav"), NULL, SND_FILENAME | SND_ASYNC);
        setColor(RED);
        cout << "\t\t\t            ERROR: Invalid Choice! Please Try Again...";
    }

    getch();
    goto p;
};


void bank::atm_management() { 
p:
    system("cls");
    int choice;
    PlaySound(TEXT("sound\\Well-atm.wav"), NULL, SND_FILENAME | SND_ASYNC);
    setColor(GREEN);
    cout << "\n\n\n\n\n\t\t\t\t        ================================";
    cout << "\n\t\t\t\t              ATM MANAGEMENT SYSTEM";
    cout << "\n\t\t\t\t        ================================";

    setColor(OFF_WHITE);
    cout << "\n\n\t\t\t    1. User Login & Check Balance";
    cout << "\n\t\t\t    2. Withdraw Amount";
    cout << "\n\t\t\t    3. Account Details";
    cout << "\n\t\t\t    4. Go Back";
    
    setColor(GREEN);
    cout << "\n\n\t\t\t    Enter Your Choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
        user_balance();
        break;
    case 2:
        withdraw_atm();
        break;
    case 3:
        check_detail();
        break;
    case 4:
        menu();
        break;
    default:
    	PlaySound(TEXT("sound\\inva-choice.wav"), NULL, SND_FILENAME | SND_ASYNC);
        setColor(RED);
        cout << "\t\t\t    ERROR: Invalid Choice! Please Try Again...";
    }

    getch();
    goto p;
};

void bank::loansystem() { 
p:
    system("cls");
    int choice;
    
    PlaySound(TEXT("sound\\loan&status.wav"), NULL, SND_FILENAME | SND_ASYNC);
    setColor(GREEN);
    cout << "\n\n\n\n\n\t\t\t\t          ==============================";
    cout << "\n\t\t\t\t            LOAN REQUEST & LOAN STATUS";
    cout << "\n\t\t\t\t          ==============================";

    setColor(OFF_WHITE);
    cout << "\n\n\t\t\t    1. Loan Application";
    cout << "\n\t\t\t    2. Loan Status";
    cout << "\n\t\t\t    3. Go Back";
    
    setColor(GREEN);
    cout << "\n\n\t\t\t    Enter Your Choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
    loan_application();
    break;
    
    case 2:
    view_loan_status();
    break;
    
    case 3:
    menu();
    break;
        
    default:
    	PlaySound(TEXT("sound\\inva-choice.wav"), NULL, SND_FILENAME | SND_ASYNC);
        setColor(RED);
        cout << "\t\t\t    ERROR: Invalid Choice! Please Try Again...";
    }

    getch();
    goto p;
};


void bank::morefeatures() { 
p:
    system("cls");
    int choice;
    
    PlaySound(TEXT("sound\\mfeatures.wav"), NULL, SND_FILENAME | SND_ASYNC);
    setColor(GREEN);
    cout << "\n\n\n\n\n\t\t\t\t                =================";
    cout << "\n\t\t\t\t                  MORE FEATURES";
    cout << "\n\t\t\t\t                =================";

    setColor(OFF_WHITE);
    cout << "\n\n\t\t\t    1. Manage Loan";
    cout << "\n\t\t\t    2. Bank Histories";
    cout << "\n\t\t\t    3. Transaction History";
    cout << "\n\t\t\t    4. Go Back";
    
    setColor(GREEN);
    cout << "\n\n\t\t\t    Enter Your Choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
    manage_loans();
        break;
         case 2:
        calculateBankStats();
        break;
         case 3:
        viewHistory();
        break;
    case 4:
        bank_management();
        break;
    default:
    	PlaySound(TEXT("sound\\inva-choice.wav"), NULL, SND_FILENAME | SND_ASYNC);
        setColor(RED);
        cout << "\t\t\t    ERROR: Invalid Choice! Please Try Again...";
    }

    getch();
    goto p;
};

void bank::printHeader() {
    cout << "\n\n\n\n\n\t\t\t\t        ================================";
    cout << "\n\t\t\t\t             BANK MANAGEMENT SYSTEM";
    cout << "\n\t\t\t\t        ================================";
    setColor(RESET);
};

void bank::printDivider() {
    setColor(OFF_WHITE);
    cout << "\t\t\t        -----------------------------------------" << endl;
    setColor(RESET);
};



bool bank::isValidPhoneNumber(const string& phone) {
    regex phone_regex("^\\d{10,15}$");
    return regex_match(phone, phone_regex);
}


bool bank::isValidPinOrPassword(const string& value) {
    return value.length() == 5 && all_of(value.begin(), value.end(), ::isdigit);
};



void bank::sendFakeSMS(const string& phoneNumber, const string& message) {

    cout << "\t\t\t       Connecting to ZS Bank SMS Gateway...";
    PlaySound(TEXT("sound\\gateway.wav"), NULL, SND_FILENAME | SND_SYNC);
    setColor(WHITE);
    
    this_thread::sleep_for(chrono::seconds(4));
    PlaySound(TEXT("sound\\sending-sms.wav"), NULL, SND_FILENAME | SND_ASYNC);
    setColor(GREEN);
    
    cout << "\n\t\t\t       Sending SMS";
    setColor(WHITE);
    
    for (int i = 0; i < 3; i++) {
        cout << ".";
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(9000));
    }
    cout << "\n";

    this_thread::sleep_for(chrono::seconds(4));
	
    setColor(GREEN);
    cout << "\n\t\t\t       SMS Sent Successfully!";
    cout << "\n\t\t\t       -------------------------------------------------";
    PlaySound(TEXT("sound\\sms-sendet.wav"), NULL, SND_FILENAME | SND_SYNC);
    
    setColor(GREEN);
    cout << "\n\t\t\t       From: ";
    setColor(WHITE);
    cout << "ZS Bank";

    setColor(GREEN);
    cout << "\n\t\t\t       To: ";
    setColor(WHITE);
    cout << phoneNumber;

    setColor(GREEN);
    cout << "\n\t\t\t       Time: ";
    setColor(WHITE);
    cout << __TIME__;

    setColor(GREEN);
    cout << "\n\t\t\t       Message: ";
    setColor(WHITE);
    cout << message;

    setColor(GREEN);
    cout << "\n\t\t\t       -------------------------------------------------\n";
    setColor(RESET);
};


void sendWhatsAppMessage(const std::string& phone, const std::string& message) {

    std::ofstream outFile("message.txt");
    outFile << message;
    outFile.close();

    std::string command = "python whatsapp_sender.py " + phone;
    system(command.c_str());  
}



void bank::new_user() {
    system("cls"); 
    cout << "\n\n\n\n\n\t\t\t\t        ================================";
    cout << "\n\t\t\t\t          CREATE NEW USER BANK ACCOUNT";
    cout << "\n\t\t\t\t        ================================";
    PlaySound(TEXT("sound\\new-user.wav"), NULL, SND_FILENAME | SND_SYNC);

    
    fstream file;
    string id, name, fname, address, pin, pass, phone;
    float balance;

    cin.ignore();

    
    while (true) {
    	
        setColor(OFF_WHITE);
        cout << "\n\t\t\t       Enter the following details:\n";
        PlaySound(TEXT("sound\\followingdetal.wav"), NULL, SND_FILENAME | SND_SYNC);
        setColor(RESET);
        
        PlaySound(TEXT("sound\\enterid.wav"), NULL, SND_FILENAME | SND_ASYNC);
        setColor(WHITE);
        
        cout << "\t\t\t       User ID: ";
        getline(cin, id);
        while (id.empty()) {
            	PlaySound(TEXT("sound\\idempty.wav"), NULL, SND_FILENAME | SND_ASYNC);
                setColor(RED);
                cout << "\n\t\t\t       Error: User ID cannot be empty! Re-enter: ";
                setColor(OFF_WHITE);
                getline(cin, id);
        };
        
        
        PlaySound(TEXT("sound\\entername.wav"), NULL, SND_FILENAME | SND_ASYNC);
        cout << "\t\t\t       Name: ";
        getline(cin, name);  
        while (name.empty()) {
            	PlaySound(TEXT("sound\\nameempty.wav"), NULL, SND_FILENAME | SND_ASYNC);
                setColor(RED);
                cout << "\t\t\t       Error: Name cannot be empty! Re-enter: ";
                setColor(OFF_WHITE);
                getline(cin, name);
        };
        
        
        PlaySound(TEXT("sound\\enterfname.wav"), NULL, SND_FILENAME | SND_ASYNC);
        cout << "\t\t\t       Father's Name: ";
        getline(cin, fname);
        while (fname.empty()) {
            	PlaySound(TEXT("sound\\fnameempty.wav"), NULL, SND_FILENAME | SND_ASYNC);
                setColor(RED);
                cout << "\t\t\t       Error: Father's Name cannot be empty! Re-enter: ";
                setColor(OFF_WHITE);
                getline(cin, fname);
        };
        
        PlaySound(TEXT("sound\\enteraddress.wav"), NULL, SND_FILENAME | SND_ASYNC);
        cout << "\t\t\t       Address: ";
        getline(cin, address);
            while (address.empty()) {
            	PlaySound(TEXT("sound\\addressempty.wav"), NULL, SND_FILENAME | SND_ASYNC);
                setColor(RED);
                cout << "\t\t\t       Error: Address cannot be empty! Re-enter: ";
                setColor(OFF_WHITE);
                getline(cin, address);
            };

    
        PlaySound(TEXT("sound\\enterpin.wav"), NULL, SND_FILENAME | SND_ASYNC);
        cout << "\t\t\t       Pin Code (5 digits): ";
        cin >> pin;
        if (!isValidPinOrPassword(pin)) {
        	
            system("cls");
            setColor(RED);
            cout << "\n\n\n\n\n\t\t\t    Error: Pin Code must be exactly 5 digits. Try again.\n";
            PlaySound(TEXT("sound\\errorpin.wav"), NULL, SND_FILENAME | SND_SYNC);
            setColor(RESET);
            setColor(GREEN);
            
    cout << "\t\t\t\t        ================================";
    cout << "\n\t\t\t\t          CREATE NEW USER BANK ACCOUNT";
    cout << "\n\t\t\t\t        ================================";
    setColor(RESET);
            continue;
        }
        
        PlaySound(TEXT("sound\\enterpass.wav"), NULL, SND_FILENAME | SND_ASYNC);
        cout << "\t\t\t       Password (5 digits): ";
        cin >> pass;
        if (!isValidPinOrPassword(pass)) {
        	
            system("cls");
            setColor(RED);
            cout << "\n\n\n\n\n\t\t\t    Error: Password must be exactly 5 digits. Try again.\n";
            PlaySound(TEXT("sound\\errorpassword.wav"), NULL, SND_FILENAME | SND_SYNC);
            setColor(RESET);
            setColor(GREEN);
    cout << "\t\t\t\t        ================================";
    cout << "\n\t\t\t\t          CREATE NEW USER BANK ACCOUNT";
    cout << "\n\t\t\t\t        ================================";
    setColor(RESET);
            continue;
        }
        PlaySound(TEXT("sound\\enternum.wav"), NULL, SND_FILENAME | SND_ASYNC);

        cout << "\t\t\t       Phone No. (10-15 digits): ";
        cin >> phone;
        if (!isValidPhoneNumber(phone)) {
        	
            system("cls");
            setColor(RED);
            cout << "\n\n\n\n\n\t\t\t  Error: Phone number must be between 10 & 15 digits. Try again\n";
            PlaySound(TEXT("sound\\phoneerror.wav"), NULL, SND_FILENAME | SND_SYNC);
            setColor(RESET);
            setColor(GREEN);
    cout << "\t\t\t\t        ================================";
    cout << "\n\t\t\t\t          CREATE NEW USER BANK ACCOUNT";
    cout << "\n\t\t\t\t        ================================";
    setColor(RESET);
            continue;
        }
        
        PlaySound(TEXT("sound\\enterbal.wav"), NULL, SND_FILENAME | SND_ASYNC);
        cout << "\t\t\t       Current Balance (Minimum $1000): ";
        cin >> balance;
        if (cin.fail() || balance < 1000) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("cls");
            setColor(RED);
            cout << "\n\n\n\n\n\t\t\t    Error: Minimum balance must be at least $1000. Try again.\n";
            PlaySound(TEXT("sound\\mimi-bal.wav"), NULL, SND_FILENAME | SND_SYNC);
            setColor(RESET);
            setColor(GREEN);
    cout << "\t\t\t\t        ================================";
    cout << "\n\t\t\t\t          CREATE NEW USER BANK ACCOUNT";
    cout << "\n\t\t\t\t        ================================";
    setColor(RESET);
            continue;
        }
        
        file.open("bank.txt", ios::in);
        if (file) {
            string i, n, f, a, p, pa, ph;
            float b;
            bool duplicate = false;
            while (file >> i >> n >> f >> a >> p >> pa >> ph >> b) {
                if (i == id) {
                    duplicate = true;
                    break;
                }
            }
            file.close();
            if (duplicate) {
                system("cls");
                setColor(RED);
                cout << "\n\n\n\n\n\t\t\t      Error: User ID already exists! Please try again.\n";
                PlaySound(TEXT("sound\\usererror.wav"), NULL, SND_FILENAME | SND_SYNC);
                setColor(RESET);
                setColor(GREEN);
    cout << "\t\t\t\t        ================================";
    cout << "\n\t\t\t\t          CREATE NEW USER BANK ACCOUNT";
    cout << "\n\t\t\t\t        ================================";
    setColor(RESET);
                continue;
            }
        }

        file.open("bank.txt", ios::app);
        file << id << " " << name << " " << fname << " " << address << " "
             << pin << " " << pass << " " << phone << " " << balance << "\n";
        file.close();

        system("cls");
        setColor(GREEN);
        cout << "\n\n\n\n\n\t\t\t           -----------------------------------------" << endl;
        cout << "\t\t\t             New User Account Created Successfully!" << endl;
        cout << "\t\t\t           -----------------------------------------" << endl;
        PlaySound(TEXT("sound\\newacreated.wav"), NULL, SND_FILENAME | SND_SYNC);
        setColor(RESET);


    string smsMessage = "\n\t\t\t       Dear " + name + "," +  
                    "\n\t\t\t       your ZS Bank account has been successfully created!" + 
                    "\n\t\t\t       Account ID: " + id + 
                    "\n\t\t\t       Available Balance: $" + to_string(balance) + 
                    "\n\t\t\t       Thank you for banking with us.";
    sendFakeSMS(phone, smsMessage);
	PlaySound(TEXT("sound\\thanksbanking.wav"), NULL, SND_FILENAME | SND_ASYNC);
	
	
	string message = "Dear " + name + ",\n"
                          "Your ZS Bank account has been successfully created!\n"
                          "Account ID: " + id + "\n"
                          "Available Balance: $" + to_string(balance) + "\n"
                          "Thank you for banking with us.";
	sendWhatsAppMessage(phone, message);
        break;
    }
}



bool isValidPinOrPassword(const string &input) {
    return input.length() == 5 && all_of(input.begin(), input.end(), ::isdigit);
}

bool isValidPhoneNumber(const string &phone) {
    return phone.length() >= 10 && phone.length() <= 15 && all_of(phone.begin(), phone.end(), ::isdigit);
}




void bank::already_user() {
	
    system("cls");
    
    setColor(GREEN);
    cout << "\n\n\n\n\n\t\t\t\t\t      ====================";
    cout << "\n\t\t\t\t\t       CHECK ALREADY USER";
    cout << "\n\t\t\t\t\t      ====================";
    PlaySound(TEXT("sound\\checkallready.wav"), NULL, SND_FILENAME | SND_SYNC);
    cout << "\n\t\t\t    Check Already User Option\n";
    cout << "\t\t\t    -------------------------------------------------------";
    setColor(RESET);
    
    fstream file;
    string t_id, id, name, fname, address, pin, pass, phone;
    float balance;
    bool found = false;

    
    file.open("bank.txt", ios::in);
    if (!file) {
    	PlaySound(TEXT("sound\\error.wav"), NULL, SND_FILENAME | SND_ASYNC);
        setColor(RED);
        cout << "\n\n\t\t\t    Error: Unable to open the file. No accounts found!\n";
        setColor(RESET);
        return;
    }
    PlaySound(TEXT("sound\\enterid.wav"), NULL, SND_FILENAME | SND_ASYNC);
    
    cout << "\n\n\t\t\t    Enter User ID: ";
    cin >> t_id;

    
    while (file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance) {
    if (t_id == id) {
    	
    system("cls");
    
    setColor(GREEN);
    cout << "\n\n\n\n\n\t\t\t\t\t      ====================";
    cout << "\n\t\t\t\t\t          ALREADY USER";
    cout << "\n\t\t\t\t\t      ====================";
    PlaySound(TEXT("sound\\idfound.wav"), NULL, SND_FILENAME | SND_ASYNC);
    setColor(GREEN);
    
    cout << "\n\t\t\t    User Found!\n";
    cout << "\t\t\t    -------------------------------------------------------";
    setColor(RESET);
            setColor(RESET);
            setColor(WHITE);
            cout << "\n\t\t\t    User ID   : " << id;
            cout << "\n\t\t\t    Pin Code  : " << pin;
            cout << "\n\t\t\t    Password  : " << pass;
            cout << "\n\n";
            found = true;
            break;
        }
    }
    file.close();

    if (!found) {
    	PlaySound(TEXT("sound\\idnotfound.wav"), NULL, SND_FILENAME | SND_ASYNC);
        setColor(RED);
        cout << "\n\n\t\t\t          Error: User ID not found. Please try again.\n";
    }

    setColor(OFF_WHITE);
    cout << "\t\t\t    -------------------------------------------------------";
    setColor(RESET);
};







void bank::deposit() {
	
    system("cls");
    
    setColor(GREEN);
    cout << "\n\n\n\n\n\t\t\t\t\t      ====================";
    cout << "\n\t\t\t\t\t         DEPOSIT AMOUNT";
    cout << "\n\t\t\t\t\t      ====================";
    setColor(RESET);
    PlaySound(TEXT("sound\\depositop.wav"), NULL, SND_FILENAME | SND_SYNC);

    fstream file, file1, depositHistoryFile;
    string t_id;
    float dep;
    int found = 0;

    setColor(GREEN);
    cout << "\n\t\t\t    Deposit Amount Option\n";
    cout << "\t\t\t    -------------------------------------------------------";
    setColor(RESET);

    file.open("bank.txt", ios::in);
    if (!file) {
    	PlaySound(TEXT("sound\\error.wav"), NULL, SND_FILENAME | SND_ASYNC);
        setColor(RED);
        cout << "\n\n\t\t\t    Error: Unable to open the file. No accounts found!\n";
        setColor(RESET);
        return;
    }
    
    PlaySound(TEXT("sound\\enterid.wav"), NULL, SND_FILENAME | SND_ASYNC);
    cout << "\n\t\t\t    Enter User ID: ";
    cin >> t_id;

    file1.open("bank1.txt", ios::out);
    if (!file1) {
    	PlaySound(TEXT("sound\\error.wav"), NULL, SND_FILENAME | SND_ASYNC);
        setColor(RED);
        cout << "\n\n\t\t\t    Error: Temporary file creation failed!\n";
        setColor(RESET);
        file.close();
        return;
    }

   
    depositHistoryFile.open("deposit_history.txt", ios::app); 
    if (!depositHistoryFile) {
    	PlaySound(TEXT("sound\\error.wav"), NULL, SND_FILENAME | SND_ASYNC);
        setColor(RED);
        cout << "\n\n\t\t\t    Error: Unable to open deposit history file.\n";
        setColor(RESET);
        file.close();
        file1.close();
        return;
    }

    bool validInput = true;
    while (file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance) {
    if (t_id == id) {
    PlaySound(TEXT("sound\\enterdepo.wav"), NULL, SND_FILENAME | SND_ASYNC);
    cout << "\n\t\t\t    Enter Amount to Deposit: ";
    cin >> dep;
            
    if (cin.fail() || dep <= 0) {
    setColor(RED);
    PlaySound(TEXT("sound\\depoerrorxyz.wav"), NULL, SND_FILENAME | SND_ASYNC);
    cout << "\n\n\t\t\t   Error: Invalid deposit amount! Please enter a valid number.\n";
    setColor(RESET);
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    validInput = false;
    break;
    }

        
            balance += dep;
            file1 << id << " " << name << " " << fname << " " << address << " " << pin << " "
                  << pass << " " << phone << " " << balance << "\n";
            found++;

           
            time_t now = time(0); 
            tm *ltm = localtime(&now); 

            
            depositHistoryFile << "Date: " << 1900 + ltm->tm_year << "-" << 1 + ltm->tm_mon << "-" << ltm->tm_mday
                               << " Time: " << 1 + ltm->tm_hour << ":" << 1 + ltm->tm_min << ":" << 1 + ltm->tm_sec
                               << " | User ID: " << id << " | Name: " << name << " | Amount Deposited: " << dep
                               << " | New Balance: " << balance << "\n";
            PlaySound(TEXT("sound\\depsuc.wav"), NULL, SND_FILENAME | SND_ASYNC);
            setColor(GREEN);
            
            cout << "\n\n\t\t\t    Success! " << dep << " has been deposited into your account.\n";
            setColor(RESET);
            
        } else {
            file1 << id << " " << name << " " << fname << " " << address << " " << pin << " "
                  << pass << " " << phone << " " << balance << "\n";
        }
    }

    file.close();
    file1.close();
    depositHistoryFile.close();

    if (validInput) {
    remove("bank.txt");
    rename("bank1.txt", "bank.txt");
    }

    if (found == 0 && validInput) {
    PlaySound(TEXT("sound\\idnotfound.wav"), NULL, SND_FILENAME | SND_ASYNC);
    setColor(RED);
    cout << "\n\n\t\t\t    Error: User ID not found! Please try again.\n";
    setColor(RESET);
    }

    setColor(OFF_WHITE);
    cout << "\t\t\t    -------------------------------------------------------";
    setColor(RESET);
};



void bank::withdraw() {
	
    system("cls");
    
    setColor(GREEN);
    cout << "\n\n\n\n\n\t\t\t\t\t      ====================";
    cout << "\n\t\t\t\t\t         WITHDRAW AMOUNT";
    cout << "\n\t\t\t\t\t      ====================";
    PlaySound(TEXT("sound\\withamount.wav"), NULL, SND_FILENAME | SND_SYNC);
    setColor(RESET);

    fstream file, file1, withdrawHistoryFile;
    string t_id;
    float with;
    int found = 0;

    setColor(GREEN);
    cout << "\n\t\t\t    Withdraw Amount Option\n";
    cout << "\t\t\t    -------------------------------------------------------";
    setColor(RESET);

    file.open("bank.txt", ios::in);
    if (!file) {
    PlaySound(TEXT("sound\\error.wav"), NULL, SND_FILENAME | SND_ASYNC);
    setColor(RED);
    cout << "\n\n\t\t\t    Error: Unable to open the file. No accounts found!\n";
    setColor(RESET);
    return;
    }
    
    PlaySound(TEXT("sound\\enterid.wav"), NULL, SND_FILENAME | SND_ASYNC);
    cout << "\n\t\t\t    Enter User ID: ";
    cin >> t_id;

    file1.open("bank1.txt", ios::out);
    if (!file1) {
    PlaySound(TEXT("sound\\error.wav"), NULL, SND_FILENAME | SND_ASYNC);
    setColor(RED);
    cout << "\n\n\t\t\t    Error: Temporary file creation failed!\n";
    setColor(RESET);
    file.close();
    return;
    }

    
    withdrawHistoryFile.open("withdraw_history.txt", ios::app);
    if (!withdrawHistoryFile) {
    	PlaySound(TEXT("sound\\error.wav"), NULL, SND_FILENAME | SND_ASYNC);
        setColor(RED);
        cout << "\n\n\t\t\t    Error: Unable to open withdraw history file.\n";
        setColor(RESET);
        file.close();
        file1.close();
        return;
    }

    bool validInput = true;
    while (file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance) {
    if (t_id == id) {
    PlaySound(TEXT("sound\\enterwitham.wav"), NULL, SND_FILENAME | SND_ASYNC);
    cout << "\n\t\t\t    Enter Amount to Withdraw: ";
    cin >> with;

    if (cin.fail() || with <= 0) {
    PlaySound(TEXT("sound\\withinvam.wav"), NULL, SND_FILENAME | SND_ASYNC);
    setColor(RED);
    cout << "\n\n\t\t\t  Error: Invalid withdrawal amount! Please enter a valid number.\n";
    setColor(RESET);
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    validInput = false;
    break;
    }

            if (with <= balance) {
                balance -= with;  
                file1 << id << " " << name << " " << fname << " " << address << " " << pin << " "
                      << pass << " " << phone << " " << balance << "\n";

              
                time_t now = time(0);  
                tm *ltm = localtime(&now); 

                
                withdrawHistoryFile << "Date: " << 1900 + ltm->tm_year << "-" << 1 + ltm->tm_mon << "-" << ltm->tm_mday
                                    << " Time: " << 1 + ltm->tm_hour << ":" << 1 + ltm->tm_min << ":" << 1 + ltm->tm_sec
                                    << " | User ID: " << id << " | Name: " << name << " | Amount Withdrawn: " << with
                                    << " | New Balance: " << balance << "\n";
                PlaySound(TEXT("sound\\withsuc.wav"), NULL, SND_FILENAME | SND_ASYNC);
                setColor(GREEN);
                cout << "\n\n\t\t\t    Success! " << with << " has been withdrawn from your account.\n";
                setColor(RESET);
            } else {
                file1 << id << " " << name << " " << fname << " " << address << " " << pin << " "
                      << pass << " " << phone << " " << balance << "\n";
                PlaySound(TEXT("sound\\inshbal.wav"), NULL, SND_FILENAME | SND_ASYNC);
                setColor(RED);
                cout << "\n\n\t\t\t    Error: Insufficient balance! Your Current Balance: " << balance << "\n";
                setColor(RESET);
            }
            found++;
        } else {
            file1 << id << " " << name << " " << fname << " " << address << " " << pin << " "
                  << pass << " " << phone << " " << balance << "\n";
        }
    }

    file.close();
    file1.close();
    withdrawHistoryFile.close();

    if (validInput) {
    remove("bank.txt");
    rename("bank1.txt", "bank.txt");
    }

    if (found == 0 && validInput) {
    	PlaySound(TEXT("sound\\idnotfound.wav"), NULL, SND_FILENAME | SND_ASYNC);
        setColor(RED);
        cout << "\n\n\t\t\t    Error: User ID not found! Please try again.\n";
        setColor(RESET);
    }

    setColor(OFF_WHITE);
    cout << "\t\t\t    -------------------------------------------------------";
    setColor(RESET);
};
#include <iostream>
#include <fstream>
#include <limits>
#include <ctime>
using namespace std;
void bank::transfer() {
	
    system("cls");
    
    setColor(GREEN);
    cout << "\n\n\n\n\n\t\t\t\t\t      ====================";
    cout << "\n\t\t\t\t\t        PAYMENT TRANSFER";
    cout << "\n\t\t\t\t\t      ====================";
    PlaySound(TEXT("sound\\paytran.wav"), NULL, SND_FILENAME | SND_SYNC);
    cout << "\n\t\t\t    -------------------------------------------------------";
    setColor(RESET);

    fstream file, file1, transferHistoryFile;
    string s_id, r_id;
    int foundSender = 0, foundReceiver = 0;
    float amount, senderBalance = 0, receiverBalance = 0;
    string id, name, fname, address, pin, pass, phone;
    float balance;

    file.open("bank.txt", ios::in);
    if (!file) {
    	PlaySound(TEXT("sound\\error.wav"), NULL, SND_FILENAME | SND_ASYNC);
        setColor(RED);
        cout << "\n\n\t\t\t    Error: Unable to open the file. No accounts found!\n";
        setColor(RESET);
        return;
    }
    
	PlaySound(TEXT("sound\\ensendid.wav"), NULL, SND_FILENAME | SND_ASYNC);
    cout << "\n\n\t\t\t    Enter Sender User ID: ";
    cin >> s_id;
    PlaySound(TEXT("sound\\enrecid.wav"), NULL, SND_FILENAME | SND_ASYNC);
    cout << "\t\t\t    Enter Receiver User ID: ";
    cin >> r_id;
    cout << "\t\t\t    Enter Transaction Amount: ";
    PlaySound(TEXT("sound\\eta.wav"), NULL, SND_FILENAME | SND_ASYNC);
    cin >> amount;

    if (cin.fail() || amount <= 0) {
    PlaySound(TEXT("sound\\intranam.wav"), NULL, SND_FILENAME | SND_ASYNC);
    setColor(RED);
    cout << "\n\n\t\t\t Error: Invalid transaction amount! Please enter a valid number.\n";
    cout << "\n\t\t\t    -------------------------------------------------------";
        setColor(RESET);
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        file.close();
        return;
    }

    file1.open("bank1.txt", ios::out);
    if (!file1) {
    	PlaySound(TEXT("sound\\error.wav"), NULL, SND_FILENAME | SND_ASYNC);
        setColor(RED);
        cout << "\n\n\t\t\t    Error: Temporary file creation failed!\n";
        setColor(RESET);
        file.close();
        return;
    }

    transferHistoryFile.open("transfer_history.txt", ios::app);
    if (!transferHistoryFile) {
    	PlaySound(TEXT("sound\\error.wav"), NULL, SND_FILENAME | SND_ASYNC);
        setColor(RED);
        cout << "\n\n\t\t\t    Error: Unable to open transfer history file.\n";
        setColor(RESET);
        file.close();
        file1.close();
        return;
    }

    while (file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance) {
        if (s_id == id) {
            foundSender = 1;
            senderBalance = balance;
        }
        if (r_id == id) {
            foundReceiver = 1;
            receiverBalance = balance;
        }
    }
    file.clear();
    file.seekg(0);

    if (!foundSender || !foundReceiver) {
        setColor(RED);
        PlaySound(TEXT("sound\\sendernotfound.wav"), NULL, SND_FILENAME | SND_ASYNC);
        if (!foundSender) cout << "\n\t\t\t    Error: Sender User ID not found!";
        sleep(2);
        PlaySound(TEXT("sound\\recnotfound.wav"), NULL, SND_FILENAME | SND_ASYNC);
        if (!foundReceiver) cout << "\n\t\t\t    Error: Receiver User ID not found!";
    cout << "\n\t\t\t    -------------------------------------------------------";
        setColor(RESET);
        file.close();
        file1.close();
        remove("bank1.txt");
        return;
    }

    if (senderBalance < amount) {
    	PlaySound(TEXT("sound\\inshtran.wav"), NULL, SND_FILENAME | SND_ASYNC);
        setColor(RED);
        cout << "\n\t\t\t   Error: Insufficient balance for transaction! Available: " << senderBalance << "\n";
    cout << "\n\t\t\t    -------------------------------------------------------";
        setColor(RESET);
        file.close();
        file1.close();
        remove("bank1.txt");
        return;
    }

    while (file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance) {
        if (s_id == id) balance -= amount;
        if (r_id == id) balance += amount;
        file1 << id << " " << name << " " << fname << " " << address << " " << pin << " "
              << pass << " " << phone << " " << balance << "\n";
    }

    file.close();
    file1.close();
    remove("bank.txt");
    rename("bank1.txt", "bank.txt");

    time_t now = time(0);
    tm *ltm = localtime(&now);
    transferHistoryFile << "Date: " << 1900 + ltm->tm_year << "-" << 1 + ltm->tm_mon << "-" << ltm->tm_mday
                        << " Time: " << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec
                        << " | Sender ID: " << s_id << " | Receiver ID: " << r_id
                        << " | Amount Transferred: " << amount << "\n";
    transferHistoryFile.close();
    PlaySound(TEXT("sound\\transuc.wav"), NULL, SND_FILENAME | SND_ASYNC);
    setColor(GREEN);
    cout << "\n\n\t\t\t  Transaction Successful! " << amount << " transferred from " << s_id << " to " << r_id << ".\n";
    setColor(RESET);
    setColor(GREEN);
    cout << "\n\t\t\t    -------------------------------------------------------";
    setColor(RESET);
};


void bank::payment()
{
    system("cls");
    fstream file, file1;
    int found = 0;
    float amount;
    string t_id, b_name;
    time_t now = time(0); 
    tm *ltm = localtime(&now);

    setColor(GREEN);
    cout << "\n\n\n\n\n\t\t\t\t        ================================";
    cout << "\n\t\t\t\t              BILL PAYMENT SYSTEM";
    cout << "\n\t\t\t\t        ================================";
    cout << "\n\t\t\t    -------------------------------------------------------";
    PlaySound(TEXT("sound\\billpasa.wav"), NULL, SND_FILENAME | SND_SYNC);
    setColor(RESET);

    file.open("bank.txt", ios::in);
    if (!file)
    {
    	PlaySound(TEXT("sound\\error.wav"), NULL, SND_FILENAME | SND_ASYNC);
        setColor(RED);
        cout << "\n\n\t\t\t    Error: Unable to open the bank records file!" << endl;
        cout << "\n\t\t\t    -------------------------------------------------------";
        setColor(RESET);
        return;
    }
    PlaySound(TEXT("sound\\enterid.wav"), NULL, SND_FILENAME | SND_ASYNC);
    setColor(OFF_WHITE);
    cout << "\n\t\t\t       User ID: ";
    cin >> t_id;
    setColor(RESET);

    PlaySound(TEXT("sound\\sebiilta.wav"), NULL, SND_FILENAME | SND_ASYNC);
    cout << "\n\t\t\t       Select Bill Type: \n";
    cout << "\t\t\t       1. Electricity Bill\n";
    cout << "\t\t\t       2. Gas Bill\n";
    cout << "\t\t\t       3. Water Bill\n";
    cout << "\t\t\t       4. Internet Bill\n";
    cout << "\t\t\t       5. Other (Enter Manually)\n";

    
    int choice;
    cout << "\n\t\t\t       Enter Choice (1-5): ";
    cin >> choice;

    switch (choice)
    {
        case 1: b_name = "Electricity";
        system("cls");
		setColor(GREEN);
		    
    cout << "\n\n\n\n\n\t\t\t\t\t      ====================";
    cout << "\n\t\t\t\t\t        ELECTRICITY BILL";
    cout << "\n\t\t\t\t\t      ====================";
    cout << "\n\t\t\t    -------------------------------------------------------";
    PlaySound(TEXT("sound\\electricity.wav"), NULL, SND_FILENAME | SND_SYNC);
    setColor(RESET);
	break;
    case 2: b_name = "Gas"; 
    
	system("cls");
	setColor(GREEN);
    cout << "\n\n\n\n\n\t\t\t\t\t         ===============";
    cout << "\n\t\t\t\t\t            GASS BILL";
    cout << "\n\t\t\t\t\t         ===============";
    cout << "\n\t\t\t    -------------------------------------------------------";
    PlaySound(TEXT("sound\\gas.wav"), NULL, SND_FILENAME | SND_SYNC);
    setColor(RESET);
	break;
	
    case 3: b_name = "Water";
    
	system("cls");
	setColor(GREEN);
    cout << "\n\n\n\n\n\t\t\t\t\t         ===============";
    cout << "\n\t\t\t\t\t           WATER BILL";
    cout << "\n\t\t\t\t\t         ===============";
    cout << "\n\t\t\t    -------------------------------------------------------";
    PlaySound(TEXT("sound\\water.wav"), NULL, SND_FILENAME | SND_SYNC);
    setColor(RESET);
	break;
	
    case 4: b_name = "Internet"; 
    
    system("cls");
	setColor(GREEN);
    cout << "\n\n\n\n\n\t\t\t\t\t       ====================";
    cout << "\n\t\t\t\t\t          INTERNET BILL";
    cout << "\n\t\t\t\t\t       ====================";
    cout << "\n\t\t\t    -------------------------------------------------------";
    PlaySound(TEXT("sound\\internet.wav"), NULL, SND_FILENAME | SND_SYNC);
    setColor(RESET);
	break;
	
    case 5:
    system("cls");
    setColor(GREEN);
    cout << "\n\n\n\n\n\t\t\t\t        ================================";
    cout << "\n\t\t\t\t              BILL PAYMENT SYSTEM";
    cout << "\n\t\t\t\t        ================================";
    cout << "\n\t\t\t    -------------------------------------------------------";
    PlaySound(TEXT("sound\\billpasa.wav"), NULL, SND_FILENAME | SND_SYNC);
    setColor(RESET);
    PlaySound(TEXT("sound\\enbill.wav"), NULL, SND_FILENAME | SND_ASYNC);
    cout << "\n\t\t\t    Enter Bill Name: ";
    cin >> b_name;
    break;
    
    default:
        	PlaySound(TEXT("sound\\inva-choice.wav"), NULL, SND_FILENAME | SND_ASYNC);
            setColor(RED);
            cout << "\n\t\t\t       Invalid choice! Please try again.\n";
            setColor(RESET);
            file.close();
            return;
    }
    PlaySound(TEXT("sound\\enbillam.wav"), NULL, SND_FILENAME | SND_ASYNC);
    cout << "\n\t\t\t    Bill Amount: ";
    cin >> amount;

    if (cin.fail() || amount <= 0)
    {
    	PlaySound(TEXT("sound\\inbill.wav"), NULL, SND_FILENAME | SND_ASYNC);
        setColor(RED);
        cout << "\n\n\t\t\t    Error: Invalid bill amount! Please enter a valid number.\n";
        setColor(RESET);
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        file.close();
        return;
    }

    file1.open("bank1.txt", ios::out);
    if (!file1)
    {
	PlaySound(TEXT("sound\\error.wav"), NULL, SND_FILENAME | SND_ASYNC);
        setColor(RED);
        cout << "\n\n\t\t\t    Error: Temporary file creation failed!\n";
        setColor(RESET);
        file.close();
        return;
    }

    while (file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance)
    {
        if (t_id == id)
        {
            if (amount <= balance)
            {
                balance -= amount;
                file1 << id << " " << name << " " << fname << " " << address << " " << pin << " "
                      << pass << " " << phone << " " << balance << "\n";
                found = 1;
            }
            else
            {
            	PlaySound(TEXT("sound\\insufbill.wav"), NULL, SND_FILENAME | SND_ASYNC);
                setColor(RED);
                cout << "\n\n\t\t\t    Error: Insufficient balance to pay " << b_name << " bill!\n";
                setColor(RESET);
                file1 << id << " " << name << " " << fname << " " << address << " " << pin << " "
                      << pass << " " << phone << " " << balance << "\n";
                found = -1;
            }
        }
        else
        {
            file1 << id << " " << name << " " << fname << " " << address << " " << pin << " "
                  << pass << " " << phone << " " << balance << "\n";
        }
    }

    file.close();
    file1.close();

    if (found == 1)
    {
        remove("bank.txt");
        rename("bank1.txt", "bank.txt");

        file.open("bill.txt", ios::app);
        if (file)
        {
            file << t_id << " " << b_name << " " << amount << " "
                 << 1900 + ltm->tm_year << "/" << 1 + ltm->tm_mon << "/" << ltm->tm_mday << "\n";
            file.close();
        }
        PlaySound(TEXT("sound\\billpaid.wav"), NULL, SND_FILENAME | SND_ASYNC);
        setColor(GREEN);      
        cout << "\n\n\t\t\t           ==========================================";
        cout << "\n\t\t\t              " << b_name << " Bill Paid Successfully!";
        cout << "\n\t\t\t           ==========================================";
        setColor(RESET);
    }
    else if (found == -1)
    {
        remove("bank1.txt");
    }
    else
    {
    	PlaySound(TEXT("sound\\idnotfound.wav"), NULL, SND_FILENAME | SND_ASYNC);
        remove("bank1.txt");
        setColor(RED);
        cout << "\n\n\t\t\t    Error: User ID Not Found!\n";
        setColor(RESET);
    }

    setColor(OFF_WHITE);
            cout << "\n\t\t\t    -------------------------------------------------------";
    setColor(RESET);
};



void bank::search(){
	
    system("cls");
    fstream file;
    string t_id;
    int found = 0;
    setColor(GREEN);
    cout << "\n\n\n\n\n\t\t\t\t        ================================";
    cout << "\n\t\t\t\t              SEARCH USER RECORD";
    cout << "\n\t\t\t\t        ================================";
    cout << "\n\t\t\t    -------------------------------------------------------";
    PlaySound(TEXT("sound\\sereachid.wav"), NULL, SND_FILENAME | SND_SYNC);
    setColor(RESET);

    file.open("bank.txt", ios::in);
    if (!file)
    {
    	PlaySound(TEXT("sound\\error.wav"), NULL, SND_FILENAME | SND_ASYNC);
        setColor(RED);
        cout << "\n\n\t\t\t    Error: Unable to open the bank records file!" << endl;
        setColor(RESET);
        return;
    }
    PlaySound(TEXT("sound\\enterid.wav"), NULL, SND_FILENAME | SND_ASYNC);
    setColor(OFF_WHITE);
    cout << "\n\n\t\t\t    Enter User ID: ";
    cin >> t_id;
    setColor(RESET);

    file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
    while (!file.eof())
    {
        if (t_id == id)
        {
        	
    system("cls");
    PlaySound(TEXT("sound\\idfound.wav"), NULL, SND_FILENAME | SND_ASYNC);
    setColor(GREEN);
    cout << "\n\n\n\n\n\t\t\t\t        ================================";
    cout << "\n\t\t\t\t               USER RECORD FOUND";
    cout << "\n\t\t\t\t        ================================";
    cout << "\n\t\t\t    -------------------------------------------------------";
    setColor(RESET);

            setColor(GREEN);
            cout << "\n\n\t\t\t    User ID      : "; setColor(WHITE); cout << id;
            setColor(GREEN);
            cout << "\n\t\t\t    Name         : "; setColor(WHITE); cout << name;
            setColor(GREEN);
            cout << "\n\t\t\t    Father's Name: "; setColor(WHITE); cout << fname;
            setColor(GREEN);
            cout << "\n\t\t\t    Address      : "; setColor(WHITE); cout << address;
            setColor(GREEN);
            cout << "\n\t\t\t    Pin          : "; setColor(WHITE); cout << pin;
            setColor(GREEN);
            cout << "\n\t\t\t    Phone No.    : "; setColor(WHITE); cout << phone;
            setColor(GREEN);
            cout << "\n\t\t\t    Current Balance: "; setColor(WHITE); cout << balance;
            setColor(RESET);

            found++;
            break; 
        }
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
    }

    file.close();

    if (found == 0)
    {
    	PlaySound(TEXT("sound\\idnotfound.wav"), NULL, SND_FILENAME | SND_ASYNC);
        setColor(RED);
        cout << "\n\n\t\t\t    Error: User ID Not Found!" << endl;
        setColor(RESET);
    }

    setColor(OFF_WHITE);
    cout << "\n\t\t\t    -------------------------------------------------------";
    setColor(RESET);
};



void bank::edit() {
    system("cls");
    fstream file, file1;
    string t_id, n, f, a, p, ph;
    string id, name, fname, address, pass, phone;
    int found = 0, pi, pin;
    float balance;

    setColor(GREEN);
    cout << "\n\n\n\n\n\t\t\t\t\t      ====================";
    cout << "\n\t\t\t\t\t        EDIT USER RECORD";
    cout << "\n\t\t\t\t\t      ====================";
    cout << "\n\t\t\t    -------------------------------------------------------";
    PlaySound(TEXT("sound\\editid.wav"), NULL, SND_FILENAME | SND_SYNC);
    setColor(RESET);

    file.open("bank.txt", ios::in);
    if (!file) {
    	PlaySound(TEXT("sound\\error.wav"), NULL, SND_FILENAME | SND_ASYNC);
        setColor(RED);
        cout << "\n\n\t\t\t    Error: Unable to open the bank records file!" << endl;
        setColor(RESET);
        return;
    }
    PlaySound(TEXT("sound\\enterid.wav"), NULL, SND_FILENAME | SND_ASYNC);
    setColor(OFF_WHITE);
    cout << "\n\n\t\t\t    Enter User ID: ";
    cin >> t_id;
    setColor(RESET);

    file1.open("bank1.txt", ios::out);
    if (!file1) {
    	PlaySound(TEXT("sound\\error.wav"), NULL, SND_FILENAME | SND_ASYNC);
        setColor(RED);
        cout << "\t\t\t    Error: Unable to create a temporary file!" << endl;
        setColor(RESET);
        file.close();
        return;
    }

    while (file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance) {
        if (t_id == id) {
            system("cls");

            setColor(GREEN);
            cout << "\n\n\n\n\n\t\t\t\t        ================================";
            cout << "\n\t\t\t\t            EDITING USER INFORMATION";
            cout << "\n\t\t\t\t        ================================";
            cout << "\n\t\t\t    -------------------------------------------------------";
            PlaySound(TEXT("sound\\editinginfo.wav"), NULL, SND_FILENAME | SND_SYNC);
            setColor(RESET);

            
            PlaySound(TEXT("sound\\ennewname.wav"), NULL, SND_FILENAME | SND_ASYNC);
            setColor(OFF_WHITE);
            cout << "\t\t\t         \t\t\t       Enter New Name: ";
            cin.ignore();
            getline(cin, n);
            while (n.empty()) {
            	PlaySound(TEXT("sound\\nameempty.wav"), NULL, SND_FILENAME | SND_ASYNC);
                setColor(RED);
                cout << "\t\t\t       Error: Name cannot be empty! Re-enter: ";
                setColor(OFF_WHITE);
                getline(cin, n);
            }
            
	        PlaySound(TEXT("sound\\newfname.wav"), NULL, SND_FILENAME | SND_ASYNC);
            cout << "\t\t\t       Enter New Father's Name: ";
            getline(cin, f);
            while (f.empty()) {
            	PlaySound(TEXT("sound\\fnameempty.wav"), NULL, SND_FILENAME | SND_ASYNC);
                setColor(RED);
                cout << "\t\t\t       Error: Father's Name cannot be empty! Re-enter: ";
                setColor(OFF_WHITE);
                getline(cin, f);
            }
            
            PlaySound(TEXT("sound\\newaddress.wav"), NULL, SND_FILENAME | SND_ASYNC);
            cout << "\t\t\t       Enter New Address: ";
            getline(cin, a);
            while (a.empty()) {
            PlaySound(TEXT("sound\\addressempty.wav"), NULL, SND_FILENAME | SND_ASYNC);
            setColor(RED);
            cout << "\t\t\t       Error: Address cannot be empty! Re-enter: ";
            setColor(OFF_WHITE);
            getline(cin, a);
            }
            
            PlaySound(TEXT("sound\\enterpin.wav"), NULL, SND_FILENAME | SND_ASYNC);
            cout << "\t\t\t       Enter New 5-Digit Pin Code: ";
            cin >> pi;
            while (cin.fail() || pi < 10000 || pi > 99999) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                setColor(RED);
                cout << "\t\t\t       Error: Pin must be exactly 5 digits! Re-enter: ";
                PlaySound(TEXT("sound\\errorpin.wav"), NULL, SND_FILENAME | SND_ASYNC);
                setColor(OFF_WHITE);
                cin >> pi;
            }
            
            PlaySound(TEXT("sound\\enterpass.wav"), NULL, SND_FILENAME | SND_ASYNC);
            cout << "\t\t\t       Enter New 5-Digit Password: ";
            cin >> p;
            while (p.length() != 5 || !all_of(p.begin(), p.end(), ::isdigit)) {
            	PlaySound(TEXT("sound\\errorpassword.wav"), NULL, SND_FILENAME | SND_ASYNC);
                setColor(RED);
                cout << "\t\t\t       Error: Password must be exactly 5 digits! Re-enter: ";
                setColor(OFF_WHITE);
                cin >> p;
            }
            
            PlaySound(TEXT("sound\\enternum.wav"), NULL, SND_FILENAME | SND_ASYNC);
            cout << "\t\t\t       Enter New Phone Number (10-15 digits): ";
            cin >> ph;
            while (ph.length() < 10 || ph.length() > 15 || !all_of(ph.begin(), ph.end(), ::isdigit)) {
            	PlaySound(TEXT("sound\\phoneerror.wav"), NULL, SND_FILENAME | SND_ASYNC);
                setColor(RED);
                cout << "\t\t\t       Error: Phone number must be 10-15 digits! Re-enter: ";
                setColor(OFF_WHITE);
                cin >> ph;
            }
			              
    setColor(GREEN);
    cout << "\n\t\t\t\t               Updating Record";
    PlaySound(TEXT("sound\\updating.wav"), NULL, SND_FILENAME | SND_ASYNC);
    setColor(WHITE);
    for (int i = 0; i < 3; i++) {
        cout << ".";
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
    cout << "\n";

    this_thread::sleep_for(chrono::seconds(4));
            setColor(RESET);

            file1 << id << " " << n << " " << f << " " << a << " " << pi << " "
                  << p << " " << ph << " " << balance << "\n";

            setColor(GREEN);
            cout << "\n\t\t\t\t        ================================";
            cout << "\n\t\t\t\t           Record Updated Successfully!";
            cout << "\n\t\t\t\t        ================================";
            PlaySound(TEXT("sound\\sucupdated.wav"), NULL, SND_FILENAME | SND_ASYNC);
            setColor(RESET);

            found = 1;
        } else {
            file1 << id << " " << name << " " << fname << " " << address << " " << pin << " "
                  << pass << " " << phone << " " << balance << "\n";
        }
    }

    file.close();
    file1.close();

    if (found) {
        remove("bank.txt");           
        rename("bank1.txt", "bank.txt"); 
    } else {
        remove("bank1.txt");
        PlaySound(TEXT("sound\\idnotfound.wav"), NULL, SND_FILENAME | SND_ASYNC);
        setColor(RED);
        cout << "\n\n\t\t\t    Error: User ID not found!";
        setColor(RESET);
    }

    setColor(OFF_WHITE);
    cout << "\n\t\t\t           -----------------------------------------";
    setColor(RESET);
};






void bank::del()
{
    system("cls");

    fstream file, file1;
    string t_id, id, name, fname, address, pass, phone, pi;
    float balance;
    int found = 0;

    setColor(GREEN);
    cout << "\n\n\n\n\n\t\t\t\t\t      ====================";
    cout << "\n\t\t\t\t\t       DELETE USER RECORD";
    cout << "\n\t\t\t\t\t      ====================";
    cout << "\n\t\t\t    -------------------------------------------------------";
    PlaySound(TEXT("sound\\deleteid.wav"), NULL, SND_FILENAME | SND_SYNC);
    setColor(RESET);

    file.open("bank.txt", ios::in);
    if (!file) {
    	PlaySound(TEXT("sound\\error.wav"), NULL, SND_FILENAME | SND_ASYNC);
        setColor(RED);
        cout << "\n\n\t\t\t    Error: Unable to open the bank records file!" << endl;
        setColor(RESET);
        return;
    }
    PlaySound(TEXT("sound\\enterid.wav"), NULL, SND_FILENAME | SND_ASYNC);
    setColor(OFF_WHITE);
    cout << "\n\t\t\t    Enter User ID to Delete: ";
    cin >> t_id;
    setColor(RESET);

    file1.open("bank1.txt", ios::out);
    if (!file1) {
    	PlaySound(TEXT("sound\\error.wav"), NULL, SND_FILENAME | SND_ASYNC);
        setColor(RED);
        cout << "\n\t\t\t    Error: Unable to create a temporary file!" << endl;
        setColor(RESET);
        file.close();
        return;
    }

    while (file >> id >> name >> fname >> address >> pi >> pass >> phone >> balance) {
        if (t_id == id) {
            
            PlaySound(TEXT("sound\\deletedsuc.wav"), NULL, SND_FILENAME | SND_ASYNC);
            setColor(RED);
            cout << "\n\t\t\t\t           Record Deleted Successfully" << endl;
            setColor(RESET);
            setColor(GREEN);
            cout << "\n\t\t\t    -------------------------------------------------------";
            setColor(RESET);
                
            found++;
        } else {
            
            file1 << id << " " << name << " " << fname << " " << address << " " << pi << " "
                  << pass << " " << phone << " " << balance << "\n";
        }
    }

    file.close();
    file1.close();

    remove("bank.txt");
    rename("bank1.txt", "bank.txt");

    if (found == 0) {
    	PlaySound(TEXT("sound\\idnotfound.wav"), NULL, SND_FILENAME | SND_ASYNC);
        setColor(RED);
        cout << "\n\n\t\t\t    Error: User ID not found..." << endl;
        setColor(RESET);
    }

    setColor(OFF_WHITE);
                cout << "\n\t\t\t    -------------------------------------------------------";
    setColor(RESET);
};






void bank::show_records() {
    system("cls");

    fstream file;
    string id, name, fname, address, pi, pass, phone;
    float balance;
    int found = 0;
    
            PlaySound(TEXT("sound\\showingacc.wav"), NULL, SND_FILENAME | SND_ASYNC);
            setColor(GREEN);
            cout << "\n\n\n\n\n\t\t\t\t        ================================";
            cout << "\n\t\t\t\t            SHOW ALL USERS RECORD";
            cout << "\n\t\t\t\t        ================================";
            cout << "\n\t\t\t    -------------------------------------------------------";
            setColor(RESET);

    file.open("bank.txt", ios::in);
    if (!file) {
    	PlaySound(TEXT("sound\\error.wav"), NULL, SND_FILENAME | SND_ASYNC);
        setColor(RED);
        cout << "\n\n\t\t\t    Error: Unable to open the bank records file!" << endl;
        setColor(RESET);
        return;
    }

    while (file >> id >> name >> fname >> address >> pi >> pass >> phone >> balance) {
        setColor(OFF_WHITE);
        cout << "\n\t\t\t         +--------------------------------------------+" << endl;
        
        setColor(GREEN);
        cout << "\t\t\t          User ID      : "; setColor(WHITE); cout << id << endl;
        setColor(GREEN);
        cout << "\t\t\t          Name         : "; setColor(WHITE); cout << name << endl;
        setColor(GREEN);
        cout << "\t\t\t          Father's Name: "; setColor(WHITE); cout << fname << endl;
        setColor(GREEN);
        cout << "\t\t\t          Address      : "; setColor(WHITE); cout << address << endl;
        setColor(GREEN);
        cout << "\t\t\t          Pin          : "; setColor(WHITE); cout << pi << endl;
        setColor(GREEN);
        cout << "\t\t\t          Password     : "; setColor(WHITE); cout << pass << endl;
        setColor(GREEN);
        cout << "\t\t\t          Phone No.    : "; setColor(WHITE); cout << phone << endl;
        setColor(GREEN);
        cout << "\t\t\t          Balance      : "; setColor(WHITE); cout << "$" << balance << endl;

        setColor(OFF_WHITE);
        cout << "\t\t\t         +--------------------------------------------+" << endl;
        setColor(RESET);

        found++;
    }

    if (found == 0) {
        setColor(RED);
        PlaySound(TEXT("sound\\error.wav"), NULL, SND_FILENAME | SND_ASYNC);
        cout << "\n\n\t\t\t     No records found in the database!" << endl;
        setColor(RESET);
    }

    file.close();
    cout<<"\n\n";
};



void bank::show_payment() {
    system("cls");

    fstream file;
    string id, name, date;
    float amount;
    int c_year, c_month, c_date;
    int found = 0;
    
            PlaySound(TEXT("sound\\showingbillre.wav"), NULL, SND_FILENAME | SND_ASYNC);
            setColor(GREEN);
            cout << "\n\n\n\n\n\t\t\t\t        ================================";
            cout << "\n\t\t\t\t            SHOW ALL BILL RECORD";
            cout << "\n\t\t\t\t        ================================";
            cout << "\n\t\t\t    -------------------------------------------------------";
            setColor(RESET);

    file.open("bill.txt", ios::in);
    if (!file) {
    	PlaySound(TEXT("sound\\error.wav"), NULL, SND_FILENAME | SND_ASYNC);
        setColor(RED);
        cout << "\n\n\t\t\t    Error: Unable to open the bill records file!" << endl;
        setColor(RESET);
        return;
    }

    while (file >> id >> name >> amount >> date) {
        stringstream dateStream(date);
        char delimiter;
        dateStream >> c_year >> delimiter >> c_month >> delimiter >> c_date;

        setColor(OFF_WHITE);
        cout << "\n\t\t\t         +--------------------------------------------+" << endl;

        setColor(GREEN);
        cout << "\t\t\t          User ID    : "; setColor(WHITE); cout << id << endl;
        setColor(GREEN);
        cout << "\t\t\t          Bill Name  : "; setColor(WHITE); cout << name << endl;
        setColor(GREEN);
        cout << "\t\t\t          Amount     : "; setColor(WHITE); cout << "$" << amount << endl;
        setColor(GREEN);
        cout << "\t\t\t          Date       : "; setColor(WHITE); cout << c_date << "/" << c_month << "/" << c_year << endl;

        setColor(OFF_WHITE);
        cout << "\t\t\t         +--------------------------------------------+" << endl;
        setColor(RESET);

        found++;
    }

    if (found == 0) {
    	PlaySound(TEXT("sound\\error.wav"), NULL, SND_FILENAME | SND_ASYNC);
        setColor(RED);
        cout << "\n\n\t\t\t    No bill records found in the database!" << endl;
        setColor(RESET);
    }

    file.close();
    cout<<"\n\n";
};





void bank::user_balance() {
    system("cls");
    fstream file;
    int found = 0;
    string t_id, t_pin, t_pass;
    char ch;
            setColor(GREEN);
            cout << "\n\n\n\n\n\t\t\t\t        ================================";
            cout << "\n\t\t\t\t            USER LOGIN & CHECK BALANCE";
            cout << "\n\t\t\t\t        ================================";
            cout << "\n\t\t\t    -------------------------------------------------------";
            PlaySound(TEXT("sound\\user-check.wav"), NULL, SND_FILENAME | SND_SYNC);
            setColor(RESET);

    file.open("bank.txt", ios::in);
    if (!file) {
    	PlaySound(TEXT("sound\\error.wav"), NULL, SND_FILENAME | SND_ASYNC);
        setColor(RED);
        cout << "\n\n\t\t\t     ERROR: File Opening Failed!";
    } else {
    	 PlaySound(TEXT("sound\\enid.wav"), NULL, SND_FILENAME | SND_ASYNC);
        setColor(OFF_WHITE);
        cout << "\n\n\t\t\t    User ID: ";
        cin >> t_id;
          PlaySound(TEXT("sound\\enterpin.wav"), NULL, SND_FILENAME | SND_ASYNC);
        cout << "\n\n\t\t\t    Pin Code: ";
        for (int i = 1; i <= 5; i++) {
            ch = getch();
            t_pin += ch;
            cout << "*";
        }
          PlaySound(TEXT("sound\\enterpass.wav"), NULL, SND_FILENAME | SND_ASYNC);
        cout << "\n\t\t\t    Password: ";
        for (int i = 1; i <= 5; i++) {
            ch = getch();
            t_pass += ch;
            cout << "*";
        }

        while (file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance) {
            if (t_id == id && t_pin == pin && t_pass == pass) {
            	PlaySound(TEXT("sound\\atmsuc.wav"), NULL, SND_FILENAME | SND_ASYNC);
                setColor(GREEN);
                cout << "\n\n\t\t\t    SUCCESS: Your Current Balance is: " << balance;
                found++;
                break;
            }
        }
        file.close();

        if (found == 0) {
        	PlaySound(TEXT("sound\\incorrect-id.wav"), NULL, SND_FILENAME | SND_ASYNC);
            setColor(RED);
            cout << "\n\n\t\t\t    ERROR: User ID, Pin & Password are Invalid!";
        }
    }
    getch();
};



void bank::withdraw_atm() {
    fstream file, file1, withdrawHistoryFile;
    string t_id, t_pass, t_pin;
    float with;
    int found = 0;
    char ch;
    system("cls");
    setColor(GREEN);
    cout << "\n\n\n\n\n\t\t\t\t        ================================";
    cout << "\n\t\t\t\t            WITHDRAW AMOUNT OPTION";
    cout << "\n\t\t\t\t        ================================";
    cout << "\n\t\t\t    -------------------------------------------------------";
    setColor(RESET);
    PlaySound(TEXT("sound\\withamount.wav"), NULL, SND_FILENAME | SND_SYNC);

    file.open("bank.txt", ios::in);
    if (!file) {
        setColor(RED);
        PlaySound(TEXT("sound\\error.wav"), NULL, SND_FILENAME | SND_ASYNC);
        cout << "\n\n\t\t\t    ERROR: File Opening Failed!";
        return;
    }

    PlaySound(TEXT("sound\\enid.wav"), NULL, SND_FILENAME | SND_ASYNC);
    setColor(OFF_WHITE);
    cout << "\n\t\t\t    User ID: ";
    cin >> t_id;
    PlaySound(TEXT("sound\\enterpin.wav"), NULL, SND_FILENAME | SND_ASYNC);
    cout << "\n\t\t\t    Pin Code: ";
    for (int i = 1; i <= 5; i++) {
        ch = getch();
        t_pin += ch;
        cout << "*";
    }
    PlaySound(TEXT("sound\\enterpass.wav"), NULL, SND_FILENAME | SND_ASYNC);
    cout << "\n\t\t\t    Password: ";
    for (int i = 1; i <= 5; i++) {
        ch = getch();
        t_pass += ch;
        cout << "*";
    }

    file1.open("bank1.txt", ios::out);
    if (!file1) {
        setColor(RED);
        PlaySound(TEXT("sound\\error.wav"), NULL, SND_FILENAME | SND_ASYNC);
        cout << "\n\n\t\t\t     ERROR: Could Not Create Temporary File!";
        file.close();
        return;
    }

    withdrawHistoryFile.open("withdraw_history.txt", ios::app);
    if (!withdrawHistoryFile) {
        PlaySound(TEXT("sound\\error.wav"), NULL, SND_FILENAME | SND_ASYNC);
        setColor(RED);
        cout << "\n\n\t\t\t    Error: Unable to open withdraw history file.\n";
        setColor(RESET);
        file.close();
        file1.close();
        return;
    }

    bool validInput = true;
    while (file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance) {
        if (t_id == id && t_pin == pin && t_pass == pass) {
            PlaySound(TEXT("sound\\enterwithamount.wav"), NULL, SND_FILENAME | SND_ASYNC);
            setColor(GREEN);
            cout << "\n\n\t\t\t    Amount to Withdraw: ";
            cin >> with;

            if (cin.fail() || with < 500) { 
                PlaySound(TEXT("sound\\invalidwithdraw.wav"), NULL, SND_FILENAME | SND_ASYNC);
                setColor(RED);
                cout << "\n\t\t\t       ERROR: Invalid Withdrawal Amount!";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                validInput = false;
                break;
            }

           
            if (with > balance * 0.8) {
                setColor(RED);
                cout << "\t\t\t       WARNING: Suspicious Large Withdrawal Detected!";
                PlaySound(TEXT("sound\\sw.wav"), NULL, SND_FILENAME | SND_SYNC);
                PlaySound(TEXT("sound\\wlarge.wav"), NULL, SND_FILENAME | SND_SYNC);
            
                if (with == balance) {
                    cout << "\n\t\t\t       ERROR: Full Balance Withdrawal is Not Allowed!";
                    PlaySound(TEXT("sound\\notallowed.wav"), NULL, SND_FILENAME | SND_ASYNC);
                    
                    return;
                }

               
                cout << "\n\t\t\t       Security Check Required!";
                PlaySound(TEXT("sound\\security.wav"), NULL, SND_FILENAME | SND_SYNC);
                string ans_fname, ans_address;
                float ans_balance;

                PlaySound(TEXT("sound\\enterfname.wav"), NULL, SND_FILENAME | SND_ASYNC);
                cout << "\n\t\t\t       1 Father's Name: ";
                cin >> ans_fname;
                
                PlaySound(TEXT("sound\\enteraddress.wav"), NULL, SND_FILENAME | SND_ASYNC);
                cout << "\t\t\t       2 Address: ";
                cin >> ans_address;
                
                PlaySound(TEXT("sound\\enterbal.wav"), NULL, SND_FILENAME | SND_ASYNC);
                cout << "\t\t\t       3 Your Current Balance: ";
                cin >> ans_balance;

                if (ans_fname != fname || ans_address != address || ans_balance != balance) {
                    PlaySound(TEXT("sound\\fraud_blocked.wav"), NULL, SND_FILENAME | SND_ASYNC);
                    cout << "\t\t\t       TRANSACTION BLOCKED: Security Check Failed!";
                    return;
                }

                setColor(GREEN);
                cout << "\t\t\t       Security Check Passed!";
                PlaySound(TEXT("sound\\sepassed.wav"), NULL, SND_FILENAME | SND_SYNC);
            }

            balance -= with;
            file1 << id << " " << name << " " << fname << " " << address << " " << pin << " "
                  << pass << " " << phone << " " << balance << "\n";

            time_t now = time(0);
            tm *ltm = localtime(&now);
            withdrawHistoryFile << "Date: " << 1900 + ltm->tm_year << "-" << 1 + ltm->tm_mon << "-" << ltm->tm_mday
                                << " Time: " << 1 + ltm->tm_hour << ":" << 1 + ltm->tm_min << ":" << 1 + ltm->tm_sec
                                << " | User ID: " << id << " | Name: " << name << " | Amount Withdrawn: " << with
                                << " | New Balance: " << balance << "\n";

            setColor(GREEN);
            PlaySound(TEXT("sound\\withsucatm.wav"), NULL, SND_FILENAME | SND_ASYNC);
            cout << "\n\t\t\t         SUCCESS: Amount " << with << " Withdrawn Successfully!";
            cout << "\n\t\t\t                   Your Current Balance: " << balance;
            found++;
        } else {
            file1 << id << " " << name << " " << fname << " " << address << " " << pin << " "
                  << pass << " " << phone << " " << balance << "\n";
        }
    }

    file.close();
    file1.close();
    withdrawHistoryFile.close();

    if (validInput) {
        remove("bank.txt");
        rename("bank1.txt", "bank.txt");
    }

    if (found == 0 && validInput) {
        PlaySound(TEXT("sound\\incorrect-id.wav"), NULL, SND_FILENAME | SND_ASYNC);
        setColor(RED);
        cout << "\n\n\t\t\t    ERROR: User ID, Pin & Password are Invalid!";
    }

    getch();
};




void bank::check_detail() {
    fstream file;
    string id, name, fname, address, pin, pass, phone;
    float balance;
    string t_id, t_pass = "", t_pin = "";
    int found = 0;
    char ch;

    system("cls");
            setColor(GREEN);
            cout << "\n\n\n\n\n\t\t\t\t           ==========================";
            cout << "\n\t\t\t\t               CHECK DETAIL OPTION";
            cout << "\n\t\t\t\t           ==========================";
            cout << "\n\t\t\t    -------------------------------------------------------";
            PlaySound(TEXT("sound\\checkdetail.wav"), NULL, SND_FILENAME | SND_SYNC);
            setColor(RESET);

    file.open("bank.txt", ios::in);
    if (!file) {
    	PlaySound(TEXT("sound\\error.wav"), NULL, SND_FILENAME | SND_ASYNC);
        setColor(RED);
        cout << "\n\n\t\t\t    ERROR: File Opening Failed!";
        return;
    }
PlaySound(TEXT("sound\\enid.wav"), NULL, SND_FILENAME | SND_ASYNC);
    setColor(OFF_WHITE);
    cout << "\n\n\t\t\t    User ID: ";
    cin >> t_id;
PlaySound(TEXT("sound\\enterpin.wav"), NULL, SND_FILENAME | SND_ASYNC);
    cout << "\n\t\t\t    Pin Code: ";
    for (int i = 0; i < 5; i++) {
        ch = getch(); 
        t_pin += ch;
        cout << "*"; 
    }
PlaySound(TEXT("sound\\enterpass.wav"), NULL, SND_FILENAME | SND_ASYNC);
    cout << "\n\t\t\t    Password: ";
    for (int i = 0; i < 5; i++) {
        ch = getch(); 
        t_pass += ch;
        cout << "*"; 
    }

    while (file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance) {
        if (t_id == id && t_pin == pin && t_pass == pass) {
        	system("cls");
        	PlaySound(TEXT("sound\\checkdetail.wav"), NULL, SND_FILENAME | SND_ASYNC);
    setColor(GREEN);
    cout << "\n\n\n\n\n\t\t\t\t\t      ====================";
    cout << "\n\t\t\t\t\t          USER DETAILS";
    cout << "\n\t\t\t\t\t      ====================";
    cout << "\n\t\t\t    -------------------------------------------------------";
        cout << "\n\n\t\t\t    User ID: ";setColor(WHITE); cout<< id;
        setColor(GREEN); cout << "\n\t\t\t    Name: ";setColor(WHITE); cout<< name;
        setColor(GREEN); cout << "\n\t\t\t    Father Name: "; setColor(WHITE); cout<< fname;
        setColor(GREEN); cout<<  "\n\t\t\t    Address: " ;setColor(WHITE); cout<< address;
        setColor(GREEN); cout<<  "\n\t\t\t    Phone No.: " ;setColor(WHITE); cout<< phone;
        setColor(GREEN); cout<<  "\n\t\t\t    Balance: " ;setColor(WHITE); cout<< balance;
        setColor(GREEN);
            cout << "\n\n\t\t\t                     SUCCESS: Details Found!";
     cout << "\n\t\t\t       -------------------------------------------------";
            found = 1;
            break;
        }
    }

    file.close();

    if (found == 0) {
    	PlaySound(TEXT("sound\\incorrect-id.wav"), NULL, SND_FILENAME | SND_ASYNC);
        setColor(RED);
        cout << "\n\n\t\t\t    ERROR: Invalid User ID, Pin Code, or Password!";
    }

    getch();
};




void bank::viewHistory() {
    system("cls");
            PlaySound(TEXT("sound\\thistory.wav"), NULL, SND_FILENAME | SND_ASYNC);
            setColor(GREEN);
            cout << "\n\n\n\n\n\t\t\t\t        ================================";
            cout << "\n\t\t\t\t              TRANSACTION HISTORY";
            cout << "\n\t\t\t\t        ================================";
            cout << "\n\t\t\t    -------------------------------------------------------";
            setColor(RESET);

    int choice;
    setColor(GREEN);
    cout << "\n\t\t\t    Select Transaction History to View:" << endl;
    cout << "\t\t\t    -------------------------------------------------------"<< endl;
    setColor(RESET);
    setColor(OFF_WHITE);
    cout << "\t\t\t       1. View Deposit History"<< endl;
    cout << "\t\t\t       2. View Withdrawal History" << endl;
    cout << "\t\t\t       3. View Transfer History" << endl;
    cout << "\t\t\t       4. View All Transaction History" << endl;
    cout << "\t\t\t       Enter your choice: ";
    cin >> choice;
    setColor(RESET);

    if (cin.fail() || choice < 1 || choice > 4) {
    	PlaySound(TEXT("sound\\inva-choice.wav"), NULL, SND_FILENAME | SND_ASYNC);
        setColor(RED);
        cout << "\n\t\t\t       Error: Invalid choice! Please try again.\n";
        setColor(RESET);
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
    system("cls");
     setColor(GREEN);
            cout << "\n\n\n\n\n\t\t\t\t            ========================";
            cout << "\n\t\t\t\t               CHECK TRANSACTIONS";
            cout << "\n\t\t\t\t            ========================";
            cout << "\n\t\t\t    -------------------------------------------------------";
            PlaySound(TEXT("sound\\checktran.wav"), NULL, SND_FILENAME | SND_SYNC);
            setColor(RESET);
    string userID;
    PlaySound(TEXT("sound\\enid.wav"), NULL, SND_FILENAME | SND_ASYNC);
    cout << "\n\t\t\t       Enter User ID to View History: ";
    cin >> userID;

    vector<string> files;
    if (choice == 1) files.push_back("deposit_history.txt");
    else if (choice == 2) files.push_back("withdraw_history.txt");
    else if (choice == 3) files.push_back("transfer_history.txt");
    else {
        files.push_back("deposit_history.txt");
        files.push_back("withdraw_history.txt");
        files.push_back("transfer_history.txt");
    }

    bool found = false;
    PlaySound(TEXT("sound\\thid.wav"), NULL, SND_FILENAME | SND_SYNC);
    setColor(GREEN);
    cout << "\n\n\t\t\t       Transaction History for User ID: ";
    cout << userID;
    cout << "\n\t\t\t    -------------------------------------------------------";
    setColor(RESET);
    for (const string &fileName : files) {
        fstream historyFile(fileName, ios::in);
        if (!historyFile) continue;

        string line;
        while (getline(historyFile, line)) {
            if (line.find("User ID: " + userID) != string::npos || 
                (fileName == "transfer_history.txt" && (line.find("Sender ID: " + userID) != string::npos || line.find("Receiver ID: " + userID) != string::npos))) {
                
                found = true;

                stringstream ss(line);
                string key, value, date, time, user, name, amount, balance, sender, receiver;

               
                while (ss >> key) {
                    if (key == "Date:") ss >> date;
                    else if (key == "Time:") ss >> time;
                    else if (key == "|") continue;
                    else if (key == "User") { ss >> key; ss >> user; } 
                    else if (key == "Sender") { ss >> key; ss >> sender; } 
                    else if (key == "Receiver") { ss >> key; ss >> receiver; } 
                    else if (key == "Name:") ss >> name;
                    else if (key == "Amount") {
                        ss >> key; 
                        ss >> amount;
                    }
                    else if (key == "New") { 
                        ss >> key;
                        ss >> balance; 
                    }
                }

            
                setColor(OFF_WHITE);
                cout << "\n\t\t\t          +-------------------------------------------+" << endl;
                setColor(GREEN);

                if (fileName == "deposit_history.txt") {
                    cout << "\t\t\t             Transaction Type : "; setColor(WHITE); cout << "Deposit" << endl;
                    setColor(GREEN);
                    cout << "\t\t\t             Date & Time      : "; setColor(WHITE); cout << date << " " << time << endl;
                    setColor(GREEN);
                    cout << "\t\t\t             User ID          : "; setColor(WHITE); cout << user << endl;
                    setColor(GREEN);
                    cout << "\t\t\t             Name             : "; setColor(WHITE); cout << name << endl;
                    setColor(GREEN);
                    cout << "\t\t\t             Amount Deposited : "; setColor(WHITE); cout << "$" << amount << endl;
                    setColor(GREEN);
                    cout << "\t\t\t             New Balance      : "; setColor(WHITE); cout << "$" << balance << endl;
                }
                else if (fileName == "withdraw_history.txt") {
                    cout << "\t\t\t            Transaction Type : "; setColor(WHITE); cout << "Withdrawal" << endl;
                    setColor(GREEN);
                    cout << "\t\t\t             Date & Time      : "; setColor(WHITE); cout << date << " " << time << endl;
                    setColor(GREEN);
                    cout << "\t\t\t             User ID          : "; setColor(WHITE); cout << user << endl;
                    setColor(GREEN);
                    cout << "\t\t\t             Name             : "; setColor(WHITE); cout << name << endl;
                    setColor(GREEN);
                    cout << "\t\t\t             Amount Withdrawn : "; setColor(WHITE); cout << "$" << amount << endl;
                    setColor(GREEN);
                    cout << "\t\t\t             New Balance      : "; setColor(WHITE); cout << "$" << balance << endl;
                }
                else if (fileName == "transfer_history.txt") {
                    cout << "\t\t\t             Transaction Type : "; setColor(WHITE); cout << "Transfer" << endl;
                    setColor(GREEN);
                    cout << "\t\t\t             Date & Time      : "; setColor(WHITE); cout << date << " " << time << endl;
                    setColor(GREEN);
                    cout << "\t\t\t             Sender ID        : "; setColor(WHITE); cout << sender << endl;
                    setColor(GREEN);
                    cout << "\t\t\t             Receiver ID      : "; setColor(WHITE); cout << receiver << endl;
                    setColor(GREEN);
                    cout << "\t\t\t             Amount Transferred: "; setColor(WHITE); cout << "$" << amount << endl;
                }

                setColor(OFF_WHITE);
                cout << "\t\t\t          +-------------------------------------------+" << endl;
                setColor(RESET);
            }
        }
        historyFile.close();
    }

    if (!found) {
    	PlaySound(TEXT("sound\\error.wav"), NULL, SND_FILENAME | SND_SYNC);
        setColor(RED);
        cout << "\n\n\t\t\t       Error: No history found for User ID: " << userID << endl;
        setColor(RESET);
    }

    cout<<"\n\n";
}
void bank::calculateBankStats() {
    system("cls");
    
    PlaySound(TEXT("sound\\mmenu.wav"), NULL, SND_FILENAME | SND_ASYNC);
    int choice;
    setColor(GREEN);
    cout << "\n\n\n\n\n\t\t\t\t        ================================";
    cout << "\n\t\t\t\t               BANK MANAGER MENU";
    cout << "\n\t\t\t\t        ================================";
    cout << "\n\t\t\t    -------------------------------------------------------";
    setColor(RESET);

    setColor(GREEN);
    cout << "\n\t\t\t    Select an Option:" << endl;
    cout << "\t\t\t    -------------------------------------------------------" << endl;
    setColor(RESET);
    setColor(WHITE);
    cout << "\t\t\t       1. View Bank Statistics Summary" << endl;
    cout << "\t\t\t       2. View Accounts Sorted by Balance" << endl;
    cout << "\t\t\t       Enter your choice: ";
    cin >> choice;
    setColor(RESET);

    if (cin.fail() || choice < 1 || choice > 2) {
    	PlaySound(TEXT("sound\\inva-choice.wav"), NULL, SND_FILENAME | SND_ASYNC);
        setColor(RED);
        cout << "\n\t\t\t       Error: Invalid choice! Please try again.\n";
        setColor(RESET);
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    system("cls");

    int totalAccounts = 0;
    double totalBalance = 0.0;
    int totalTransactions = 0;
    vector<pair<double, string>> accounts;

    
    fstream file("bank.txt", ios::in);
    if (!file.is_open()) {
        setColor(RED);
        PlaySound(TEXT("sound\\error.wav"), NULL, SND_FILENAME | SND_ASYNC);
        cout << "\n\n\t\t\t       Error: Bank account file not found!" << endl;
        setColor(RESET);
        return;
    }

    string id, name, fname, address, pin, pass, phone;
    double balance;

    while (file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance) {
    
        totalAccounts++;
        totalBalance += balance;
        string accountInfo = "\n\t\t\t           ID: " + id + "\n\t\t\t           Name: " + name + "\n\t\t\t           Balance: " + to_string(balance) + "\n";
        accounts.push_back({balance, accountInfo});
    }
    file.close();

    
    vector<string> historyFiles = {"deposit_history.txt", "withdraw_history.txt", "transfer_history.txt", "bill.txt"};
    for (const string& historyFile : historyFiles) {
        fstream history(historyFile, ios::in);
        if (history.is_open()) {
            string line;
            while (getline(history, line)) {
                if (!line.empty()) totalTransactions++;
            }
            history.close();
        }
    }

    
    if (choice == 1) {
        setColor(GREEN);
        cout << "\n\n\n\n\n\t\t\t\t        ================================";
        cout << "\n\t\t\t\t             BANK STATISTICS SUMMARY";
        cout << "\n\t\t\t\t        ================================";
        cout << "\n\t\t\t    -------------------------------------------------------";
        PlaySound(TEXT("sound\\summary.wav"), NULL, SND_FILENAME | SND_ASYNC);
        setColor(RESET);

        setColor(WHITE);
        cout << fixed << setprecision(2);
        cout << "\n\t\t\t       Total Bank Accounts  : " << totalAccounts;
        cout << "\n\t\t\t       Total Money in Bank  : " << totalBalance;
        cout << "\n\t\t\t       Total Transactions   : " << totalTransactions;
        setColor(RESET);
    }

    
    if (choice == 2) {
    
        sort(accounts.rbegin(), accounts.rend());
        
        PlaySound(TEXT("sound\\sorted.wav"), NULL, SND_FILENAME | SND_ASYNC);
        setColor(GREEN);
        cout << "\n\n\n\n\n\t\t\t\t        ================================";
        cout << "\n\t\t\t\t          ACCOUNTS SORTED BY BALANCE";
        cout << "\n\t\t\t\t        ================================";
        cout << "\n\t\t\t    -------------------------------------------------------";
        setColor(RESET);
    
        for (const auto& acc : accounts) {
        	        setColor(GREEN);
        cout << "\n\t\t\t          +-------------------------------------------+";
            cout << acc.second << endl;
            cout << "\t\t\t          +-------------------------------------------+";
        setColor(RESET);
        }
    }

    setColor(WHITE);
    cout << "\n\t\t\t    -------------------------------------------------------" << endl;
    setColor(RESET);
}


void bank::loan_application() {
    fstream file, loanRequestFile;
    string t_id, t_pass, t_pin;
    float loanAmount;
    string loanReason;
    int found = 0;
    char ch;

    system("cls");
    setColor(GREEN);
    cout << "\n\n\n\n\n\t\t\t\t        ================================";
    cout << "\n\t\t\t\t             LOAN APPLICATION FORM";
    cout << "\n\t\t\t\t        ================================";
    cout << "\n\t\t\t    -------------------------------------------------------";
    setColor(RESET);
    PlaySound(TEXT("sound\\loanapp.wav"), NULL, SND_FILENAME | SND_SYNC);

    
    file.open("bank.txt", ios::in);
    if (!file) {
        setColor(RED);
        PlaySound(TEXT("sound\\error.wav"), NULL, SND_FILENAME | SND_ASYNC);
        cout << "\n\n\t\t\t    ERROR: File Opening Failed!";
        return;
    }

    
    loanRequestFile.open("loan_requests.txt", ios::app);
    if (!loanRequestFile) {
        setColor(RED);
        PlaySound(TEXT("sound\\error.wav"), NULL, SND_FILENAME | SND_ASYNC);
        cout << "\n\n\t\t\t    ERROR: Loan Request File Opening Failed!";
        return;
    }
    
    PlaySound(TEXT("sound\\enterid.wav"), NULL, SND_FILENAME | SND_ASYNC);
    cout << "\n\t\t\t    User ID: ";
    cin >> t_id;
    PlaySound(TEXT("sound\\enterpin.wav"), NULL, SND_FILENAME | SND_ASYNC);
    cout << "\n\t\t\t    Pin Code: ";
    for (int i = 1; i <= 5; i++) {
        ch = getch();
        t_pin += ch;
        cout << "*";
    }
    PlaySound(TEXT("sound\\enterpass.wav"), NULL, SND_FILENAME | SND_ASYNC);
    cout << "\n\t\t\t    Password: ";
    for (int i = 1; i <= 5; i++) {
        ch = getch();
        t_pass += ch;
        cout << "*";
    }

    
    while (file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance) {
        if (t_id == id && t_pin == pin && t_pass == pass) {
            found++;
            PlaySound(TEXT("sound\\enterloanamount.wav"), NULL, SND_FILENAME | SND_ASYNC);
            setColor(GREEN);
            cout << "\n\n\t\t\t    Loan Amount: ";
            cin >> loanAmount;
            PlaySound(TEXT("sound\\reason.wav"), NULL, SND_FILENAME | SND_ASYNC);
            cout << "\n\t\t\t    Loan Reason: ";
            cin.ignore();  
            getline(cin, loanReason);

            if (loanAmount > balance) {
                setColor(RED);
                PlaySound(TEXT("sound\\insuffbalance.wav"), NULL, SND_FILENAME | SND_ASYNC);
                cout << "\n\t\t\t       ERROR: Insufficient Balance for Loan!";
            } else {
                
                loanRequestFile << "User ID: " << id << " | Loan Amount: " << loanAmount << " | Reason: " << loanReason << "\n";
                setColor(GREEN);
                PlaySound(TEXT("sound\\loanappsuccess.wav"), NULL, SND_FILENAME | SND_ASYNC);
                cout << "\n\n\t\t\t       SUCCESS: Loan Application Submitted Successfully!";
            }
        }
    }

    file.close();
    loanRequestFile.close();

    if (found == 0) {
        PlaySound(TEXT("sound\\incorrect-id.wav"), NULL, SND_FILENAME | SND_ASYNC);
        setColor(RED);
        cout << "\n\n\t\t\t       ERROR: User ID, Pin & Password are Invalid!";
    }

    getch();
}

void bank::manage_loans() {
    fstream loanRequestFile, tempLoanRequestFile;
    string loanRequest, loanStatus, decision;
    string userId, loanAmount, loanReason;
    bool foundRequest = false;

    system("cls");
    setColor(GREEN);
    cout << "\n\n\n\n\n\t\t\t\t        ================================";
    cout << "\n\t\t\t\t            LOAN REQUESTS FOR MANAGER";
    cout << "\n\t\t\t\t        ================================";
    cout << "\n\t\t\t    -------------------------------------------------------";
    setColor(RESET);
    PlaySound(TEXT("sound\\managerloan.wav"), NULL, SND_FILENAME | SND_SYNC);


    loanRequestFile.open("loan_requests.txt", ios::in);
    if (!loanRequestFile) {
        setColor(RED);
        PlaySound(TEXT("sound\\error.wav"), NULL, SND_FILENAME | SND_ASYNC);
        cout << "\n\n\t\t\t    ERROR: Loan Request File Opening Failed!";
        return;
    }


    tempLoanRequestFile.open("temp_loan_requests.txt", ios::out);
    if (!tempLoanRequestFile) {
        setColor(RED);
        PlaySound(TEXT("sound\\error.wav"), NULL, SND_FILENAME | SND_ASYNC);
        cout << "\n\n\t\t\t    ERROR: Temporary Loan Request File Opening Failed!";
        return;
    }
    
    PlaySound(TEXT("sound\\pend.wav"), NULL, SND_FILENAME | SND_ASYNC);
    cout << "\n\t\t\t    Pending Loan Applications:\n";
    

    while (getline(loanRequestFile, loanRequest)) {

        stringstream ss(loanRequest);
        getline(ss, userId, '|');
        getline(ss, loanAmount, '|');
        getline(ss, loanReason, '|');


        
        cout << "\n\t\t\t          +-------------------------------------------+";
        setColor(GREEN);
        cout << "\n\t\t\t             User ID: " << userId.substr(userId.find(":") + 1);
        cout << "\n\t\t\t             Loan Amount: " << loanAmount.substr(loanAmount.find(":") + 1);
        cout << "\n\t\t\t             Reason: " << loanReason.substr(loanReason.find(":") + 1);
        setColor(RESET);
        cout << "\n\t\t\t          +-------------------------------------------+";


        cout << "\n\t\t\t   Approve this loan? (y/n), or press 'b' to go back: ";
        cin >> decision;

        if (decision == "y" || decision == "Y") {
            loanStatus = "Approved";
        } else if (decision == "n" || decision == "N") {
            loanStatus = "Rejected";
        } else if (decision == "b" || decision == "B") {

            break;
        } else {
        	PlaySound(TEXT("sound\\error.wav"), NULL, SND_FILENAME | SND_ASYNC);
            cout << "\n\t\t\t      Invalid input! Please enter 'y', 'n' or 'b'.\n";
            continue;
        }
    system("cls");
    setColor(GREEN);
    cout << "\n\n\n\n\n\t\t\t\t        ================================";
    cout << "\n\t\t\t\t            LOAN REQUESTS FOR MANAGER";
    cout << "\n\t\t\t\t        ================================";
    cout << "\n\t\t\t    -------------------------------------------------------";
    setColor(RESET);

        fstream loanDecisionFile;
        loanDecisionFile.open("loan_decisions.txt", ios::app);
        if (loanDecisionFile) {
            loanDecisionFile << loanRequest << " | Status: " << loanStatus << "\n";
            loanDecisionFile.close();
        }


        if (loanStatus == "Approved") {
            tempLoanRequestFile << loanRequest << "\n";
        }

        cout << "\n\t\t\tLoan " << loanStatus << ".\n";
        foundRequest = true;
    }

    loanRequestFile.close();
    tempLoanRequestFile.close();

    if (!foundRequest) {
    	PlaySound(TEXT("sound\\error.wav"), NULL, SND_FILENAME | SND_ASYNC);
        setColor(RED);
        cout << "\n\n\t\t\t       ERROR: No Loan Requests Found!";
        return;
    }


    remove("loan_requests.txt");
    rename("temp_loan_requests.txt", "loan_requests.txt");

    getch();
}

void bank::view_loan_status() {
    fstream loanDecisionFile;
    string loanDecision;
    string userId, loanAmount, loanReason, loanStatus;

    system("cls");
    setColor(GREEN);
    cout << "\n\n\n\n\n\t\t\t\t             ====================";
    cout << "\n\t\t\t\t               LOAN STATUS VIEW";
    cout << "\n\t\t\t\t             ====================";
    cout << "\n\t\t\t    -------------------------------------------------------";
    setColor(RESET);
    PlaySound(TEXT("sound\\viewloanstatus.wav"), NULL, SND_FILENAME | SND_SYNC);


    loanDecisionFile.open("loan_decisions.txt", ios::in);
    if (!loanDecisionFile) {
        setColor(RED);
        PlaySound(TEXT("sound\\error.wav"), NULL, SND_FILENAME | SND_ASYNC);
        cout << "\n\n\t\t\t    ERROR: Loan Decision File Opening Failed!";
        return;
    }

    cout << "\n\t\t\t    Your Loan Status:\n";
    

    while (getline(loanDecisionFile, loanDecision)) {

        stringstream ss(loanDecision);
        getline(ss, userId, '|');
        getline(ss, loanAmount, '|');
        getline(ss, loanReason, '|');
        getline(ss, loanStatus, '|');

        cout << "\n\t\t\t          +-------------------------------------------+";
        setColor(GREEN);
        cout << "\n\t\t\t           User ID: " << userId.substr(userId.find(":") + 1);
        cout << "\n\t\t\t           Loan Amount: " << loanAmount.substr(loanAmount.find(":") + 1);
        cout << "\n\t\t\t           Reason: " << loanReason.substr(loanReason.find(":") + 1);
        cout << "\n\t\t\t           Status: " << loanStatus.substr(loanStatus.find(":") + 1);
        setColor(RESET);
        cout << "\n\t\t\t          +-------------------------------------------+";
    }
    setColor(RESET);

    loanDecisionFile.close();
    cout<<"\n\n\n";
    getch();
}

 main(){  
	
	bank obj;
	introduction();
	obj.menu();  };  
