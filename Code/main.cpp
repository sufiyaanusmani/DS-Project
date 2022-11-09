#include <iostream>
#include <string>
#include <string.h>
#include <cstdlib>
#include <time.h>
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include <windows.h>
#include <ctype.h>
#include <iomanip>
#include <cwchar>
#include <vector>
#include <sstream>
#include <typeinfo>
using namespace std;

string convertToString(char *);
void aboutUs();
int mainMenu();
void box();
void FontSize(int, int);
void currentDateAndTime();
void TextColor(int);
void loadingAnimation();
void CursorPosition(int, int);

class Property
{
// Node for CDLL
public:
    long long int propertyID;
    long int locationID;
    string pageUrl;
    string propertyType;
    long long int price;
    string priceType;
    string location;
    string city;
    string province;
    string locality;
    long double latitude;
    long double longitude;
    int baths;
    string area;
    float areaMarla;
    long double areaSqft;
    string purpose;
    int bedrooms;
    string dateAdded;
    int year;
    int month;
    int day;
    string agency;
    string agent;
    Property *next;
    Property *prev;

    Property(long long int propertyID, long int locationID, string pageUrl, string propertyType, long long int price,  string priceType, string location, string city, string province, string locality, long double latitude, long double longitude, int baths, string area, float areaMarla, long double areaSqft, string purpose, int bedrooms, string dateAdded, int year, int month, int day, string agency, string agent)
    {
        this->propertyID = propertyID;
        this->locationID = locationID;
        this->pageUrl = pageUrl;
        this->propertyType = propertyType;
        this->price = price;
        this->priceType = priceType;
        this->location = location;
        this->city = city;
        this->province = province;
        this->locality = locality;
        this->latitude = latitude;
        this->longitude = longitude;
        this->baths = baths;
        this->area = area;
        this->areaMarla = areaMarla;
        this->areaSqft = areaSqft;
        this->purpose = purpose;
        this->bedrooms = bedrooms;
        this->dateAdded = dateAdded;
        this->year = year;
        this->month = month;
        this->day = day;
        this->agency = agency;
        this->agent = agent;
        next = prev = NULL;
    }

    void print()
    {
        cout << propertyID << "  " << locationID << "  " << pageUrl << "  " << propertyType << "  " << price << "  " << priceType << "  " << location << "  " << city << "  " << province << "  " << locality << "  " << latitude << "  " << longitude << "  " << baths << "  " << area << "  " << areaMarla << "  " << areaSqft << "  " << purpose << "  " << bedrooms << "  " << dateAdded << "  " << year << "  " << month << "  " << day << "  " << agency << "  " << agent << endl;
    }
};

class Properties{
    // SDLL
    private:
        Property *head;
        Property *tail;
    public:
        Properties(){
            head = tail = NULL;
        }

        bool isEmpty(){
            if(head == NULL && tail == NULL){
                return true;
            }else{
                return false;
            }
        }

        void append(long long int propertyID, long int locationID, string pageUrl, string propertyType, long long int price,  string priceType, string location, string city, string province, string locality, long double latitude, long double longitude, int baths, string area, float areaMarla, long double areaSqft, string purpose, int bedrooms, string dateAdded, int year, int month, int day, string agency, string agent){
            Property *n = new Property(propertyID, locationID, pageUrl, propertyType, price, priceType, location, city, province, locality, latitude, longitude, baths, area, areaMarla, areaSqft, purpose, bedrooms, dateAdded, year, month, day, agency, agent);
            if(isEmpty){
                head = tail = n;
            }else{
                n->next = head;
                n->prev = tail;
                tail->next = n;
                head->prev = n;
                tail = n;
            }
        }

        void print(){
            if(isEmpty()){
                cout << "No properties" << endl;
            }else{
                Property *temp = head;
                do{
                    temp->print();
                    temp = temp->next;
                }while(temp != head);
            }
        }

        int count(){
            int count = 0;
            if(!isEmpty()){
                Property *temp = head;
                do{
                    count++;
                    temp = temp->next;
                }while(temp != head);
            }
        }

        void readCSV()
        {
            long long int propertyID;
            long int locationID;
            string pageUrl;
            string propertyType;
            long long int price;
            string priceType;
            string location;
            string city;
            string province;
            string locality;
            long double latitude;
            long double longitude;
            int baths;
            string area;
            float areaMarla;
            long double areaSqft;
            string purpose;
            int bedrooms;
            string dateAdded;
            int year;
            int month;
            int day;
            string agency;
            string agent;

            string fname = "./data/property.csv";
            vector<vector<string> > content;
            vector<string> row;
            string line, word;

            fstream file(fname.c_str(), ios::in);
            if (file.is_open())
            {
                while (getline(file, line))
                {
                    row.clear();

                    stringstream str(line);

                    while (getline(str, word, ','))
                        row.push_back(word);
                    content.push_back(row);
                }
            }
            else
                cout << "Could not open the file\n";

            for (int i = 0; i < content.size(); i++)
            {
                propertyID = stoi(content[i][0]);
                locationID = stoi(content[i][1]);
                pageUrl = content[i][2];
                propertyType = content[i][3];
                price = content[i][4];
            }
        }
};

int main()
{
    Properties properties;
    int mainMenuChoice;
    // init();
    while (1)
    {
        system("cls");
        mainMenuChoice = mainMenu();
        switch (mainMenuChoice)
        {
        case 1:
            system("cls");
            system("title Admin Login");
            // a.login();
            break;
        case 2:
            system("cls");
            system("title Customer Login");
            // c.login();
            break;
        case 3:
            system("cls");
            system("title Create New Account");
            // c.createNewAccount();
            break;
        case 4:
            system("cls");
            system("title View Properties");
            // cout << cur;
            properties.readCSV();
            getch();
            break;
        case 5:
            system("cls");
            system("title About Us");
            // aboutUs();
            break;
        case 6:
            system("cls");
            // taxationDep.showInfo();
            break;
        case 7:
            system("cls");
            CursorPosition(40, 10);
            system("title Good Bye");
            box();
            Sleep(2000);
            TextColor(7);
            exit(0);
            break;
        default:
            system("cls");
            system("title ERROR :(");
            CursorPosition(0, 0);
            system("color 4F");
            cout << "Wrong choice entered, try again!";
            Beep(1000, 300);
            Sleep(2000);
            system("color 0F");
            break;
        }
    }
    return 0;
}

string convertToString(char *a)
{
    string s = a;
    return s;
}

void CursorPosition(int x, int y)
{

    COORD c;
    c.X = x;
    c.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void loadingAnimation()
{
    int i;
    system("cls");
    system("color 0A");
    CursorPosition(56, 10);
    cout << "Loading";
    CursorPosition(40, 12);
    printf("[");
    CursorPosition(78, 12);
    printf("]");
    CursorPosition(41, 12);
    for (i = 1; i <= 37; i++)
    {
        printf("%c", 177);
    }
    CursorPosition(41, 12);
    for (i = 1; i <= 37; i++)
    {
        Sleep(30);
        printf("%c", 219);
    }
    CursorPosition(0, 0);
    system("cls");
    system("color 0F");
}

void TextColor(int ForgC)
{
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    // We use csbi for the wAttributes word.
    if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        // Mask out all but the background attribute, and add in the forgournd     color
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
}

void currentDateAndTime()
{
    time_t t; // not a primitive datatype
    time(&t);

    cout << ctime(&t);
}

void FontSize(int x, int y){

CONSOLE_FONT_INFOEX cfi;
cfi.cbSize = sizeof(cfi);
cfi.nFont = 0;
cfi.dwFontSize.X = x;                   // Width of each character in the font
cfi.dwFontSize.Y = y;                  // Height
cfi.FontFamily = FF_DONTCARE;
cfi.FontWeight = 700;                   //For normal: FW_NORMAL
std::wcscpy(cfi.FaceName, L"Courier"); // Choose your font
SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

void box(){
	CursorPosition(40,7);
	TextColor(1);
	for(int i=0;i<40;i++)
	    cout<<"-";
    TextColor(2);
    CursorPosition(44,13);
	cout<<"ThankYou for using Our Service:)";
	TextColor(1);
	for(int i=0;i<11;i++){
		CursorPosition(39,8+i);
	    cout<<"|\n";
	}
	CursorPosition(40,19);
	for(int i=0;i<40;i++)
	   cout<<"-";
	for(int i=0;i<11;i++){
	CursorPosition(80,8+i);
    cout<<"|\n";
	}
	cout<<endl;
}

int mainMenu()
{
    int choice, i;
    char ch;
    system("color 0F");
    system("cls");
    system("title FAST NUCES BANK - MAIN MENU");
    CursorPosition(0, 0);
    TextColor(10);
    currentDateAndTime();
    CursorPosition(32, 3);
    FontSize(0,21);
    TextColor(11);
    cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 FAST-NUCES BANK \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
    for (i = 1; i <= 8; i++)
    {
        CursorPosition(31, 3 + i);
        printf("|");
    }
    for (i = 1; i <= 8; i++)
    {
        CursorPosition(91, 3 + i);
        printf("|");
    }
    for (i = 1; i <= 60; i++)
    {
        CursorPosition(31 + i, 12);
        printf("-");
    }
    TextColor(15);
    CursorPosition(33, 5);
    cout << "1. Login as Admin";
    CursorPosition(33, 6);
    cout << "2. Login as Customer";
    CursorPosition(33, 7);
    cout << "3. Create new account";
    CursorPosition(33, 8);
    cout << "4. Check today's currency rates";
    CursorPosition(33, 9);
    cout << "5. About Us";
    CursorPosition(33, 10);
    cout << "6. Taxation Department";
    CursorPosition(33, 11);
    cout << "7. Exit";
    CursorPosition(32, 15);
    cout << "Enter your choice: ";
    fflush(stdin);
    i = 0;
    while(1){
        ch = getch();
        if(ch >= '1' && ch <= '7' && i == 0){
            cout << ch;
            choice = ch - '0';
            i++;
        }else if(ch == 13 && i == 1){
            break;
        }else if(ch == 8 && i != 0){
            i--;
            cout << "\b \b";
        }
    }
    return choice;
}

void aboutUs(){
    system("cls");
    int j;
    for (j = 21; j >= 0; j--)
    {
        if (j == 21)
        {
            system("color 01");
        }
        if (j == 19)
        {
            system("color 02");
        }
        if (j == 18)
        {
            system("color 03");
        }
        if (j == 17)
        {
            system("color 04");
        }
        if (j == 16)
        {
            system("color 05");
        }
        if (j == 15)
        {
            system("color 06");
        }
        if (j == 14)
        {
            system("color 07");
        }
        if (j == 13)
        {
            system("color 08");
        }
        if (j == 12)
        {
            system("color 09");
        }
        if (j == 11)
        {
            system("color 0A");
        }
        if (j == 10)
        {
            system("color 0B");
        }
        if (j == 9)
        {
            system("color 0C");
        }
        if (j == 8)
        {
            system("color 0D");
        }
        if (j == 7)
        {
            system("color 0E");
        }
        if (j == 6)
        {
            system("color 0F");
        }
        if (j == 5)
        {
            system("color 01");
        }
        if (j == 4)
        {
            system("color 02");
        }
        if (j == 3)
        {
            system("color 03");
        }
        if (j == 2)
        {
            system("color 0C");
        }
        if (j == 1)
        {
            system("color 0E");
        }
        if (j == 0)
        {
            system("color 0F");
        }
        system("cls");
        CursorPosition(46, j - 1);
        printf("THIS SYSTEM IS DESIGNED BY");
        CursorPosition(46, j + 1);
        printf("Sufiyaan Usmani  (21K-3195)");
        CursorPosition(46, j + 2);
        printf("Ahsan Ashraf     (21K-3186)");
        CursorPosition(46, j + 3);
        printf("Qasim Hasan      (21K-3210)");
        CursorPosition(0, 0);
        Sleep(600);
    }
}