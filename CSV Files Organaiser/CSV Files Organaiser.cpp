// CSV Files Organaiser.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <sstream>
#include <vector>

using namespace std;

struct Lead
{
    string firstName;
    string lastName;
    string company;
    string phoneNumber;
};

int main()
{
    ifstream johnFile, janeFile;

    johnFile.open("../SampleData/johns_leads_20.csv");
    janeFile.open("../SampleData/janes_leads_20.csv");

    string line = "";
    unordered_set<string> johnLeadsSet;
    unordered_set<string> janeLeadsSet;
    unordered_set<string> commonLeadsSet;

    /*while (getline(johnFile, line)) 
    {
        Lead lead;
        stringstream inputString(line);

        getline(inputString, lead.firstName, ',');
        getline(inputString, lead.lastName, ',');
        getline(inputString, lead.company, ',');
        getline(inputString, lead.phoneNumber, ',');

      //  {
         //   cout << "First Name: " << firstName << endl;
          //  cout << "Last Name: " << lastName << endl;
          //  cout << "Company: " << company << endl;
         //   cout << "Phone Number: " << phoneNumber << endl;
          //  cout << "_____________________________________________" << endl;
       // }

    johnLeadsSet.insert(lead.phoneNumber);

    }*/

    while (getline(johnFile, line))
    {
        Lead lead;
        stringstream inputString(line);

        string field;
        vector<string> fields;

        while (getline(inputString, field, ','))
        {
            fields.push_back(field);
        }

        if (fields.size() == 4)
        {
            lead.firstName = fields[0];
            lead.lastName = fields[1];
            lead.company = fields[2];
            lead.phoneNumber = fields[3];

            lead.company = lead.company.substr(1, lead.company.size() - 2); 

            johnLeadsSet.insert(lead.phoneNumber);
        }
    }

    /* while (getline(janeFile, line)) 
    {
        Lead lead;
        stringstream inputString(line);

        getline(inputString, lead.firstName, ',');
        getline(inputString, lead.lastName, ',');
        getline(inputString, lead.company, ',');
        getline(inputString, lead.phoneNumber, ',');

       // {
         //   cout << "First Name: " << firstName << endl;
         //   cout << "Last Name: " << lastName << endl;
          //  cout << "Company: " << company << endl;
          //  cout << "Phone Number: " << phoneNumber << endl;
          //  cout << "_____________________________________________" << endl;
        //}

    janeLeadsSet.insert(lead.phoneNumber);
    }*/

    while (getline(janeFile, line))
    {
        Lead lead;
        stringstream inputString(line);

        string field;
        vector<string> fields;

        while (getline(inputString, field, ','))
        {
            fields.push_back(field);
        }

        if (fields.size() == 4)
        {
            lead.firstName = fields[0];
            lead.lastName = fields[1];
            lead.company = fields[2];
            lead.phoneNumber = fields[3];

            lead.company = lead.company.substr(1, lead.company.size() - 2); 

            janeLeadsSet.insert(lead.phoneNumber);
        }
    }
   
    ofstream commonCsvFile("New Files/Common.csv");
    for (const string& phoneNumber : johnLeadsSet)
    {
        if (janeLeadsSet.count(phoneNumber))
        {
            commonLeadsSet.insert(phoneNumber);
        }
    }

    cout << "Common Leads:" << endl;
    for (const string& phoneNumber : commonLeadsSet)
    {
        cout << phoneNumber << endl;
        commonCsvFile << phoneNumber << "\n";
    }
    commonCsvFile.close();


    return 0;
}




