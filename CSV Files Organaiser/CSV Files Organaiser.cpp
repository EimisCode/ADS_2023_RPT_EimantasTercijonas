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

    while (getline(johnFile, line)) 
    {
        Lead lead;
        stringstream inputString(line);

        getline(inputString, lead.firstName, ',');
        getline(inputString, lead.lastName, ',');
        getline(inputString, lead.company, ',');
        getline(inputString, lead.phoneNumber, ',');

        johnLeadsSet.insert(lead.phoneNumber);
    }

    while (getline(janeFile, line)) 
    {
        Lead lead;
        stringstream inputString(line);

        getline(inputString, lead.firstName, ',');
        getline(inputString, lead.lastName, ',');
        getline(inputString, lead.company, ',');
        getline(inputString, lead.phoneNumber, ',');

        janeLeadsSet.insert(lead.phoneNumber);
    }
   
    ofstream commonCsvFile("New Files/Common.csv");
    for (const string& phoneNumber : johnLeadsSet)
    {
        if (janeLeadsSet.count(phoneNumber))
        {
            commonLeadsSet.insert(phoneNumber);
        }
    }

    cout << "____________________________________________________" << endl;
    cout << "Common Leads:"<< "\n" << endl;
    for (const string& phoneNumber : commonLeadsSet)
    {
        cout << phoneNumber << endl;
        commonCsvFile << phoneNumber << "\n";
    }
    commonCsvFile.close();

    ofstream johnUniqueCsvFile("New Files/John's Unique.csv"); 
    cout << "____________________________________________________" << endl;
    cout << "John's Unique Files: "<< "\n" << endl;
    for (const string& phoneNumber : johnLeadsSet) 
    {
        if (!janeLeadsSet.count(phoneNumber)) 
        {
            cout << phoneNumber << endl;
            johnUniqueCsvFile << phoneNumber << "\n"; 
        }
    }
    johnUniqueCsvFile.close();

    ofstream janeUniqueCsvFile("New Files/Jane's Unique.csv");
    cout << "____________________________________________________" << endl;
    cout << "Jane's Unique Files: " <<"\n" << endl;

    for (const string& phoneNumber : janeLeadsSet) 
    {
        if (!johnLeadsSet.count(phoneNumber)) 
        {
            cout << phoneNumber << endl;
            janeUniqueCsvFile << phoneNumber << "\n"; 
        }
    }
    janeUniqueCsvFile.close();

    return 0;
}
