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

class Property
{
private:
    long long int propertyID;
    long int locationID;
    char pageUrl[200];
    char propertyType[20];
    long long int price;
    char priceType[20];
    char location[50];
    char city[20];
    char province[20];
    char locality[50];
    long double latitude;
    long double longitude;
    int baths;
    char area[20];
    float areaMarla;
    long double areaSqft;
    char purpose[20];
    int bedrooms;
    char dateAdded[20];
    int year;
    int month;
    int day;
    char agency[50];
    char agent[50];

public:
    Property()
    {
    }

    void print()
    {
        cout << propertyID << "  " << locationID << "  " << convertToString(pageUrl) << "  " << convertToString(propertyType) << "  " << price << "  " << convertToString(priceType) << "  " << convertToString(location) << "  " << convertToString(city) << "  " << convertToString(province) << "  " << convertToString(locality) << "  " << latitude << "  " << longitude << "  " << baths << "  " << convertToString(area) << "  " << areaMarla << "  " << areaSqft << "  " << convertToString(purpose) << "  " << bedrooms << "  " << convertToString(dateAdded) << "  " << year << "  " << month << "  " << day << "  " << convertToString(agency) << "  " << convertToString(agent) << endl;
    }

    void readCSV()
    {
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
            for (int j = 0; j < content[i].size(); j++)
            {
                cout << content[i][j] << " ";
            }
            cout << "\n";
        }
    }
};

int main()
{
    Property property;
    property.convertCSVToObj();
    return 0;
}

string convertToString(char *a)
{
    string s = a;
    return s;
}