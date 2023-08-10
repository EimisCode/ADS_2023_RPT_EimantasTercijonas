// CSV Files Organaiser.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <sstream>

using namespace std;

int main()
{
    ifstream johnFile, janeFile;


    johnFile.open("../SampleData/johns_leads_20.csv");
    janeFile.open("../SampleData/janes_leads_20.csv");
    
    string line = "";
    while (getline(johnFile, line ))
    {
        string firstName, lastName, company, phoneNumber;

        stringstream inputString (line);
        
        getline(inputString, firstName, ',');
        getline(inputString, lastName, ',');
        getline(inputString, company, ',');
        getline(inputString, phoneNumber, ',');

        line = "";

        /*{
            cout << "First Name: " << firstName << endl;
            cout << "Last Name: " << lastName << endl;
            cout << "Company: " << company << endl;
            cout << "Phone Number: " << phoneNumber << endl;
            cout << "_____________________________________________" << endl;
        }*/
    }
    while (getline(janeFile, line))
    {
        string firstName, lastName, company, phoneNumber;

        stringstream inputString(line);

        getline(inputString, firstName, ',');
        getline(inputString, lastName, ',');
        getline(inputString, company, ',');
        getline(inputString, phoneNumber, ',');

        line = "";

        {
            cout << "First Name: " << firstName << endl;
            cout << "Last Name: " << lastName << endl;
            cout << "Company: " << company << endl;
            cout << "Phone Number: " << phoneNumber << endl;
            cout << "_____________________________________________" << endl;
        }
    }

    return 0;
}


