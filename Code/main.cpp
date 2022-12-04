// Compile using:  g++ -std=c++11 main.cpp -o main.exe && ./main.exe

#include <iostream>
#include <cstring>
#include <string>
#include <string.h>
#include <cstring>
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
#include <stdexcept>
using namespace std;

string convertToString(char *);
void generateReport(string);

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
    Property *next;
    Property *prev;

    Property();
    Property(long long int, long int, string, string, long long int, string, string, string, string, string, long double, long double, int, string, float, long double, string, int, string, int, int, int);
    void print();
};

class Properties
{
    // SDLL
private:
    Property *head;
    Property *tail;

public:
    Properties();
    bool isEmpty();
    void append(long long int, long int, string, string, long long int, string, string, string, string, string, long double, long double, int, string, float, long double, string, int, string, int, int, int);
    void prepend(long long int, long int, string, string, long long int, string, string, string, string, string, long double, long double, int, string, float, long double, string, int, string, int, int, int);
    void print();
    int count();
    void readCSV();
    void search();
    Properties searchByCity(string);
    Properties searchByProvince(string);
    Properties searchByPropertyID(int);
    bool propertyExists(int);
    // void buy();
    void sellProperty(int, int, string);
    void deleteFirstNode();
    void deleteLastNode();
    void deleteNode(int);
    int partition(Property *, int, int);
    void quickSort(Property *, int, int);
    Properties sort(string);
    Properties filterByPrice(long long int, long long int);
    Properties filterByArea(long double, long double);
    Properties filterByBeds(int);
    Properties filterByType(string);
    Properties filterByCity(string);
    long long int predictPrice(string, string, int, long double, int, int);
    void generateGraphs(int);
};
Properties properties;

class User
{
protected:
    int accountNumber;
    char name[40];
    int age;
    char gender;
    char email[30];
    char password[20];
    virtual int generateAccountNumber() = 0;

public:
    virtual void createNewAccount(char [20], int, char, char [30], char[20]) = 0;
    char *getName();
    int getAccountNumber();
    char getGender();
    int getAge();
    char *getEmail();
    virtual void storeData() = 0;
    void readData();
    virtual bool login(char [30], char [20]) = 0;
};

class Customer : public User
{
private:
    int generateAccountNumber();

public:
    void createNewAccount(char [20], int, char, char [30], char[20]);
    bool login(char [30], char [20]);
    void storeData();
    void addData();
    void buy();
    void sendEmailToAll(string, string);
    void sendEmail(string, string, string);
};

class EmailNode{
    public:
        int accountNumber;
        string name;
        string email;
        EmailNode *next;

        EmailNode(int, string, string);
};


class EmailQueue{
    private:
        EmailNode *front;
        EmailNode *rear;
    public:
        EmailQueue();
        bool isEmpty();
        void enqueue(int, string, string);
        void dequeue();
        EmailNode * getFront();
        string getFrontEmail();
        void sendEmailToAll();
        void printQueue();
};

int main()
{
    
    return 0;
}

string convertToString(char *a)
{
    string s = a;
    return s;
}

// PROPERTY

Property::Property(){
    next = prev = NULL;
}

Property::Property(long long int propertyID, long int locationID, string pageUrl, string propertyType, long long int price, string priceType, string location, string city, string province, string locality, long double latitude, long double longitude, int baths, string area, float areaMarla, long double areaSqft, string purpose, int bedrooms, string dateAdded, int year, int month, int day)
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
    next = prev = NULL;
}

// PROPERTIES

Properties::Properties()
{
    head = tail = NULL;
}

bool Properties::isEmpty()
{
    if (head == NULL && tail == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Properties::append(long long int propertyID, long int locationID, string pageUrl, string propertyType, long long int price, string priceType, string location, string city, string province, string locality, long double latitude, long double longitude, int baths, string area, float areaMarla, long double areaSqft, string purpose, int bedrooms, string dateAdded, int year, int month, int day)
{
    Property *n = new Property(propertyID, locationID, pageUrl, propertyType, price, priceType, location, city, province, locality, latitude, longitude, baths, area, areaMarla, areaSqft, purpose, bedrooms, dateAdded, year, month, day);
    if (isEmpty())
    {
        head = tail = n;
    }
    else
    {
        n->next = head;
        n->prev = tail;
        tail->next = n;
        head->prev = n;
        tail = n;
    }
}

void Properties::prepend(long long int propertyID, long int locationID, string pageUrl, string propertyType, long long int price, string priceType, string location, string city, string province, string locality, long double latitude, long double longitude, int baths, string area, float areaMarla, long double areaSqft, string purpose, int bedrooms, string dateAdded, int year, int month, int day)
{
    Property *n = new Property(propertyID, locationID, pageUrl, propertyType, price, priceType, location, city, province, locality, latitude, longitude, baths, area, areaMarla, areaSqft, purpose, bedrooms, dateAdded, year, month, day);
    if (isEmpty())
    {
        head = tail = n;
    }
    else
    {
        n->next = head;
        n->prev = tail;
        tail->next = n;
        head->prev = n;
        head = n;
    }
}

int Properties::count()
{
    int count = 0;
    if (!isEmpty())
    {
        Property *temp = head;
        do
        {
            count++;
            temp = temp->next;
        } while (temp != head);
    }
    return count;
}

void Properties::readCSV()
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

    file.close();

    for (int i = 1; i < content.size(); i++)
    {
        propertyID = stoll(content[i][0]);
        locationID = stol(content[i][1]);
        pageUrl = content[i][2];
        propertyType = content[i][3];
        price = stoi(content[i][4]);
        priceType = content[i][5];
        location = content[i][6];
        city = content[i][7];
        province = content[i][8];
        locality = content[i][9];
        locality += content[i][10];
        locality += content[i][11];
        latitude = stold(content[i][12]);
        longitude = stoi(content[i][13]);
        baths = stoi(content[i][14]);
        area = content[i][15];
        areaMarla = stof(content[i][16]);
        areaSqft = stold(content[i][17]);
        purpose = content[i][18];
        bedrooms = stoi(content[i][19]);
        dateAdded = content[i][20];
        year = stoi(content[i][21]);
        month = stoi(content[i][22]);
        day = stoi(content[i][23]);
        append(propertyID, locationID, pageUrl, propertyType, price, priceType, location, city, province, locality, latitude, longitude, baths, area, areaMarla, areaSqft, purpose, bedrooms, dateAdded, year, month, day);
        
    }
}

void Properties::search(){
    int choice, propID;
    string str;
    while(1){
        system("cls");
        fflush(stdin);
        cout << "1. Search by city" << endl;
        cout << "2. Search by province" << endl;
        cout << "3. Search by property ID" << endl;
        cout << "4. Go back" << endl;
        cout << "\n\nEnter your choice: ";
        // cin >> choice;
        system("cls");
        fflush(stdin);
        if(choice == 1){
            cout << "Enter city: ";
            // getline(cin, str);
            searchByCity(str);
        }else if(choice == 2){
            cout << "Enter province: ";
            // getline(cin, str);
            searchByProvince(str);
        }else if(choice == 3){
            cout << "Enter property ID: ";
            // cin >> propID;
            searchByPropertyID(propID);
        }else if(choice == 4){
            break;
        }else{
            cout << "Wrong choice entered, please enter a correct choice" << endl;
            Sleep(1000);
        }
    }
    
}

Properties Properties::searchByCity(string city){
    // Linear Search
    Property *p = head;
    Properties temp;
    do{
        if(p->city == city){
            temp.append(p->propertyID, p->locationID, p->pageUrl, p->propertyType, p->price, p->priceType, p->location, p->city, p->province, p->locality, p->latitude, p->longitude, p->baths, p->area, p->areaMarla, p->areaSqft, p->purpose, p->bedrooms, p->dateAdded, p->year, p->month, p->day);
        }
        p = p->next;
    }while(p != head);
    return temp;
}

Properties Properties::searchByProvince(string province){
    // Linear Search
    Property *p = head;
    Properties temp;
    do{
        if(p->province == province){
            temp.append(p->propertyID, p->locationID, p->pageUrl, p->propertyType, p->price, p->priceType, p->location, p->city, p->province, p->locality, p->latitude, p->longitude, p->baths, p->area, p->areaMarla, p->areaSqft, p->purpose, p->bedrooms, p->dateAdded, p->year, p->month, p->day);
        }
        p = p->next;
    }while(p != head);
    return temp;
}

Properties Properties::searchByPropertyID(int ID){
    // Linear Search
    Property *p = head;
    Properties temp;
    do{
        if(p->propertyID == ID){
            temp.append(p->propertyID, p->locationID, p->pageUrl, p->propertyType, p->price, p->priceType, p->location, p->city, p->province, p->locality, p->latitude, p->longitude, p->baths, p->area, p->areaMarla, p->areaSqft, p->purpose, p->bedrooms, p->dateAdded, p->year, p->month, p->day);
            break;
        }
        p = p->next;
    }while(p != head);
    return temp;
}

bool Properties::propertyExists(int ID){
    Property *p = head;
    do{
        if(p->propertyID == ID){
            return true;
        }
        p = p->next;
    }while(p != head);
    return false;
}


void Properties::sellProperty(int propID, int buyer, string name){
     // Open File pointers
    fstream fin, fout, sold;
  
    // Open the existing file
    fin.open("./data/property.csv", ios::in);
  
    // Create a new file to store the non-deleted data
    fout.open("temp.csv", ios::out);
  
    int id, count = 0, i;
    int index;
    string line, word;
    vector<string> row;
    getline(fin, line);
    row.clear();
    stringstream first(line);
    while(getline(first, word, ',')){
        row.push_back(word);
    }
    int first_size = row.size();
    for(int i=0;i<first_size - 1;i++){
        fout << row[i] << ",";
    }
    fout << row[first_size-1] << "\n";
    // Check if this record exists
    // If exists, leave it and
    // add all other data to the new file
    while (!fin.eof()) {
  
        row.clear();
        getline(fin, line);
        stringstream s(line);
  
        while (getline(s, word, ',')) {
            row.push_back(word);
        }
        int row_size = row.size();
        id = stoi(row[0]);
  
        if (id != propID) {
            if (!fin.eof()) {
                for (i = 0; i < row_size - 1; i++) {
                    fout << row[i] << ",";
                }
                fout << row[row_size - 1] << "\n";
            }
        }
        else {
            count = 1;
            sold.open("./data/sold.csv", ios::out | ios::app);
            for(int i=0;i<row_size;i++){
                sold << row[i] << ",";
            }
            sold << buyer << "," << name << "\n";
            sold.close();
        }
        if (fin.eof())
            break;
    }
    if (count == 1)
        cout << "Record deleted\n";
    else
        cout << "Record not found\n";
  
    // Close the pointers
    fin.close();
    fout.close();
  
    // removing the existing file
    remove("./data/property.csv");
  
    // renaming the new file with the existing file name
    rename("temp.csv", "./data/property.csv");
}

void Properties::deleteNode(int propID){
    if(isEmpty()){
        return;
    }else{
        if(head->propertyID == propID){
            deleteFirstNode();
        }else{
            Property *temp = head;
            do{
                temp = temp->next;
            }while(temp != head && temp->propertyID != propID);
            if(temp->propertyID == propID){
                if(temp == tail){
                    deleteLastNode();
                }else{
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    delete temp;
                }
            }
        }
    }
}

void Properties::deleteFirstNode(){
    if(isEmpty()){
        return;
    }else{
        if(head == tail){
            delete head;
            head = tail = NULL;
        }else{
            Property *temp = head;
            head = head->next;
            tail->next = head;
            head->prev = tail;
            delete temp;
        }
    }
}

void Properties::deleteLastNode(){
    if(isEmpty()){
        return;
    }else{
        if(head == tail){
            delete head;
            head = tail = NULL;
        }else{
            Property *temp = tail;
            tail = tail->prev;
            tail->next = head;
            head->prev = tail;
            delete temp;
        }
    }
}

Properties Properties::sort(string type){
    Properties sorted;
    int n = count();
    Property *arr = new Property[n];
    Property *temp = head;
    for(int i=0;i<n;i++){
        arr[i] = *temp;
        temp = temp->next;
    }
    quickSort(arr, 0, n-1);
    for(int i=0;i<n;i++){
        if(type == "descending"){
            sorted.append(arr[i].propertyID, arr[i].locationID, arr[i].pageUrl, arr[i].propertyType, arr[i].price, arr[i].priceType, arr[i].location, arr[i].city, arr[i].province, arr[i].locality, arr[i].latitude, arr[i].longitude, arr[i].baths, arr[i].area, arr[i].areaMarla, arr[i].areaSqft, arr[i].purpose, arr[i].bedrooms, arr[i].dateAdded, arr[i].year, arr[i].month, arr[i].day);
        }else{
            sorted.prepend(arr[i].propertyID, arr[i].locationID, arr[i].pageUrl, arr[i].propertyType, arr[i].price, arr[i].priceType, arr[i].location, arr[i].city, arr[i].province, arr[i].locality, arr[i].latitude, arr[i].longitude, arr[i].baths, arr[i].area, arr[i].areaMarla, arr[i].areaSqft, arr[i].purpose, arr[i].bedrooms, arr[i].dateAdded, arr[i].year, arr[i].month, arr[i].day);
        }
    }
    delete[] arr;
    return sorted;
}

void Properties::quickSort(Property *arr, int low, int high)
{
    if (low < high) {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);
  
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int Properties::partition(Property *arr, int low, int high)
{
    int pivot = arr[high].price; // pivot
    Property temp;
    int i
        = (low
           - 1); // Index of smaller element and indicates
                 // the right position of pivot found so far
  
    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot
        if (arr[j].price < pivot) {
            i++; // increment index of smaller element
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

Properties Properties::filterByPrice(long long int from, long long int to){
    Property *temp = head;
    Properties filter;
    do{
        if(temp->price >= from && temp->price <= to){
            filter.append(temp->propertyID, temp->locationID, temp->pageUrl, temp->propertyType, temp->price, temp->priceType, temp->location, temp->city, temp->province, temp->locality, temp->latitude, temp->longitude, temp->baths, temp->area, temp->areaMarla, temp->areaSqft, temp->purpose, temp->bedrooms, temp->dateAdded, temp->year, temp->month, temp->day);
        }
        temp = temp->next;
    }while(temp != head);
    return filter;
}

Properties Properties::filterByArea(long double from, long double to){
    Property *temp = head;
    Properties filter;
    do{
        if(temp->areaSqft >= from && temp->areaSqft <= to){
            filter.append(temp->propertyID, temp->locationID, temp->pageUrl, temp->propertyType, temp->price, temp->priceType, temp->location, temp->city, temp->province, temp->locality, temp->latitude, temp->longitude, temp->baths, temp->area, temp->areaMarla, temp->areaSqft, temp->purpose, temp->bedrooms, temp->dateAdded, temp->year, temp->month, temp->day);
        }
        temp = temp->next;
    }while(temp != head);
    return filter;
}

Properties Properties::filterByBeds(int beds){
    Property *temp = head;
    Properties filter;
    do{
        if(temp->bedrooms == beds){
            filter.append(temp->propertyID, temp->locationID, temp->pageUrl, temp->propertyType, temp->price, temp->priceType, temp->location, temp->city, temp->province, temp->locality, temp->latitude, temp->longitude, temp->baths, temp->area, temp->areaMarla, temp->areaSqft, temp->purpose, temp->bedrooms, temp->dateAdded, temp->year, temp->month, temp->day);
        }
        temp = temp->next;
    }while(temp != head);
    return filter;
}

Properties Properties::filterByType(string type){
    Property *temp = head;
    Properties filter;
    do{
        if(temp->propertyType == type){
            filter.append(temp->propertyID, temp->locationID, temp->pageUrl, temp->propertyType, temp->price, temp->priceType, temp->location, temp->city, temp->province, temp->locality, temp->latitude, temp->longitude, temp->baths, temp->area, temp->areaMarla, temp->areaSqft, temp->purpose, temp->bedrooms, temp->dateAdded, temp->year, temp->month, temp->day);
        }
        temp = temp->next;
    }while(temp != head);
    return filter;
}

Properties Properties::filterByCity(string city){
    Property *temp = head;
    Properties filter;
    do{
        if(temp->city == city){
            filter.append(temp->propertyID, temp->locationID, temp->pageUrl, temp->propertyType, temp->price, temp->priceType, temp->location, temp->city, temp->province, temp->locality, temp->latitude, temp->longitude, temp->baths, temp->area, temp->areaMarla, temp->areaSqft, temp->purpose, temp->bedrooms, temp->dateAdded, temp->year, temp->month, temp->day);
        }
        temp = temp->next;
    }while(temp != head);
    return filter;
}

long long int Properties::predictPrice(string propertyType, string city, int baths, long double area, int bedrooms, int year){
    Properties searched = searchByCity(city);
    int propType, c;

    // storing data in csv file
    fstream fout;
    fout.open("./python-predict/data.csv", ios::out);
    fout << "property_type,price,city,bath,area_sqft,bedrooms,year" << endl;
    Property *temp = searched.head;
    do{
        propType = 1;   // house
        if(temp->propertyType == "Flat"){
            propType = 2;
        }
        if(temp->city == "Karachi"){
            c = 1;
        }else if(temp->city == "Lahore"){
            c = 2;
        }
        fout << propType << "," << temp->price << "," << c << "," << temp->baths << "," << temp->areaSqft << "," << temp->bedrooms << "," << temp->year << endl;
        temp = temp->next;
    }while(temp != searched.head);
    fout.close();

    // calling python program to do prediction
    propType = 1;   // house
    if(propertyType == "Flat"){
        propType = 2;
    }
    if(city == "Karachi"){
        c = 1;
    }else if(city == "Lahore"){
        c = 2;
    }
    string command = "python ./python-predict/app.py " + to_string(propType);
    command = command + " ";
    command = command + to_string(c);
    command = command + " ";
    command = command + to_string(baths);
    command = command + " ";
    command = command + to_string(area);
    command = command + " ";
    command = command + to_string(bedrooms);
    command = command + " ";
    command = command + to_string(year);
    const char* str = command.c_str();
    system(str);

    // reading the predicted price
    fstream fin;
    fin.open("./python-predict/price.txt", ios::in);
    long long int predictedPrice;
    fin >> predictedPrice;
    fin.close();
    return predictedPrice;
}

void Properties::generateGraphs(int year){
    fstream fout;
    fout.open("./python-graphs/data.csv", ios::out);
    fout << "property_type,price,city,bath,area_sqft,bedrooms,year,month,price_type" << endl;
    Property *temp = head;
    do{
        if(temp->year == year){
            fout << temp->propertyType << "," << temp->price << "," <<  temp->city << "," << temp->baths << "," << temp->areaSqft << "," << temp->bedrooms << "," << temp->year << "," << temp->month << "," << temp->priceType << endl;
        }
        temp = temp->next;
    }while(temp != head);
    fout.close();

    system("python ./python-graphs/app.py");
}

// USER

void User::readData()
{
    ifstream fin;
    system("cls");
    fin.open("./data/customer.bank", ios::in | ios::binary);
    fin.read((char *)this, sizeof(*this));
    while (fin.eof() == 0)
    {
        cout << "Acc No: " << this->accountNumber << endl;
        cout << "Name: " << this->name << endl;
        cout << "Email: " << this->email << endl;
        cout << endl;
        fin.read((char *)this, sizeof(*this));
    }
    fin.close();
}

int User::getAccountNumber()
{
    return accountNumber;
}

char *User::getName()
{
    return name;
}

int User::getAge()
{
    return age;
}

char User::getGender()
{
    return gender;
}

char *User::getEmail()
{
    return email;
}

// CUSTOMER

void Customer::createNewAccount(char n[20], int age, char gender, char e[30], char p[20])
{
    Customer c;
    c.accountNumber = c.generateAccountNumber();
    strcpy(c.name, n);
    c.age = age;
    c.gender = gender;
    strcpy(c.email, e);
    strcpy(c.password, p);
    c.storeData();
}

int Customer::generateAccountNumber()
{
    ifstream fin;
    int num;
    bool isFound = false;
    srand(time(0));
    fin.open("./data/customer.bank", ios::in | ios::binary);
    if (!fin)
    {
        perror("Error");
        Sleep(2000);
        // exit(1);
    }
    else
    {
        while (1)
        {
            num = (rand() % 10000) + 100000;
            fin.read((char *)this, sizeof(*this));
            while (fin.eof() == 0)
            {
                if (this->accountNumber == num)
                {
                    isFound = true;
                    break;
                }
                fin.read((char *)this, sizeof(*this));
            }
            if (isFound == false)
            {
                break;
            }
        }
    }
    fin.close();
    return num;
}

void Customer::storeData()
{
    ofstream fout;
    fout.open("./data/customer.bank", ios::app | ios::binary);
    if (!fout)
    {
        perror("Error");
        Sleep(2000);
    }
    fout.write((char *)this, sizeof(*this));
    fout.close();
}

bool Customer::login(char e[30], char pass[20])
{
    bool idFound = false;
    ifstream fin;
    fin.open("./data/customer.bank", ios::in | ios::binary);
    if (!fin)
    {
        cout << "ERROR, file does not exist" << endl;
    }
    else
    {
        fin.read((char *)this, sizeof(*this));
        while (fin.eof() == 0)
        {
            if (strcmp(e, email) == 0)
            {
                idFound = true;
                if (strcmp(password, pass) == 0)
                {
                    fin.close();
                    return true;
                }
                else
                {
                    return false;
                }
            }
            fin.read((char *)this, sizeof(*this));
        }
        fin.close();
        return false;
    }
}

void Customer::buy(){
    int propID;
    while(1){
        cout << "Enter property ID (-1 to go back): ";
        fflush(stdin);
        cin >> propID;
        if(propID == -1){
            return;
        }
        if(properties.propertyExists(propID)){
            properties.sellProperty(propID, accountNumber, name);
            cout << "Property bought successfully" << endl;
            properties.deleteNode(propID);
            Sleep(1000);
            return;
        }
    }
    cout << "This property does not exists" << endl;
    Sleep(1000);
}

void Customer::sendEmailToAll(string subject, string content){
    EmailQueue emailQueue;
    ifstream fin;
    Customer customer;
    system("cls");
    fin.open("./data/customer.bank", ios::in | ios::binary);
    fin.read((char *)&customer, sizeof(customer));
    while (fin.eof() == 0)
    {
        emailQueue.enqueue(customer.accountNumber, customer.name, customer.email);
        fin.read((char *)&customer, sizeof(customer));
    }
    fin.close();
    
    // storing emails in receiver.txt
    ofstream fout;
    // storing subject in subject.txt
    fout.open("./python-email/subject.txt", ios::out);
    fout << subject;
    fout.close();

    // storing content in content.txt
    fout.open("./python-email/content.txt", ios::out);
    fout << content;
    fout.close();


    while(!emailQueue.isEmpty()){
        fout.open("./python-email/receiver.txt", ios::out);
        fout << emailQueue.getFrontEmail() << "\n";
        emailQueue.dequeue();
        fout.close();
        system("python send_email.py");
    }


}

void Customer::sendEmail(string email, string subject, string content){
    ofstream fout;
    fout.open("./python-email/subject.txt", ios::out);
    fout << subject;
    fout.close();

    fout.open("./python-email/content.txt", ios::out);
    fout << content;
    fout.close();

    fout.open("./python-email/receiver.txt", ios::out);
    fout << email;
    fout.close();

    system("python send_email.py");
}

// EMAILNODE

EmailNode::EmailNode(int accountNumber, string name, string email){
    this->accountNumber = accountNumber;
    this->name = name;
    this->email = email;
    next = NULL;
}

// EMAILQUEUE

EmailQueue::EmailQueue(){
    front = rear = NULL;
}

bool EmailQueue::isEmpty(){
    if(front == NULL && rear == NULL){
        return true;
    }else{
        return false;
    }
}

void EmailQueue::enqueue(int accountNumber, string name, string email){
    EmailNode *e = new EmailNode(accountNumber, name, email);
    if(isEmpty()){
        front = rear = e;
    }else{
        rear->next = e;
        rear = e;
    }
}

void EmailQueue::dequeue(){
    if(isEmpty()){
        return;
    }
    if(front == rear){
        delete front;
        front = rear = NULL;
    }else{
        EmailNode *temp = front;
        front = front->next;
        delete temp;
    }
}

void EmailQueue::printQueue(){
    if(!isEmpty()){
        EmailNode *temp = front;
        while(temp != NULL){
            cout << temp->accountNumber << "  " << temp->name << "  " << temp->email << endl;
            temp = temp->next;
        }
    }
    cout << endl;
}

string EmailQueue::getFrontEmail(){
    if(!isEmpty()){
        return (front->email);
    }
}

void generateReport(string arg){
    string command = "python ./python-generate-report/app.py " + arg;
    const char* str = command.c_str();
    system(str);
}