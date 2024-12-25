#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <Windows.h>
#include <cctype>
using namespace std;

void menu();
void jobmenu();
void readjobdata();
void readcandidatedata();
void candidatemenu();
void wjob();
void wcandidate();
void updatejob();
void updatecandidate();
void deletejob();
void deletecandidate();
void displaycandidates();
void displayjob();
int maxSize = 3;
int no_of_records = 0;

ofstream wfile;
ifstream rfile;

struct candidate 
{
    string Name;
    string F_Name;
    int contact=0;
    string email;
    string position;
    void getData();
    void displayData();
};
candidate c[3];

void candidate::getData()
{
    cout << "Enter Name of Candidate: ";
    cin >> Name;
    cout << "Enter Father's name of Candidate: ";
    cin >> F_Name;
    cout << "Enter contact number of Candidate: ";
    cin >> contact;
    cout << "Enter Email Address of Candidate: ";
    cin >> email;
    cout << "Enter position of Candidate: ";
    cin >> position;

}

void candidate::displayData()
{
    cout << "Name of Candidate: " << Name << endl;
    cout << "Father's Name of Candidate: " << F_Name << endl;
    cout << "Contact of Candidate: " << contact << endl;
    cout << "Email of Candidate: " << email << endl;
    cout << "Position of Candidate: " << position << endl;

}

bool login() 
{ 
    string useradmin, password;
    const string UserAdmin = "admin";
    const string Password = "12345";
    cout << "Login to access admin console of Recruitment department\n";
    cout << "Enter admin: ";
    cin >> useradmin;
    cout << "Enter Password: ";
    cin >> password;
    system("cls");
    for (int i = 0; i < 3; i++)
    {
        cout << "loading please wait ";
        for (int i = 0; i < 3; i++)
        {


            cout << ".";
            Sleep(500);
        }
        system("cls");
    }

    if (UserAdmin == useradmin && Password == password)
    {
        cout << "Access granted \nWelcome to admin console of Recruitment Department\n";
        return true;
    }
    else {
        cout << "Invalid Credentials, try again\n";
        return false;
    }
}

struct job 
{
    string job;
    void getjobdata();
    void displayjobdata();
};
job j[3];

void job::getjobdata() 
{
    cout << "Enter name of jobs available: ";
    cin >> job;
}

void job::displayjobdata()
{
    cout << "Jobs available to apply for: " << job << endl;
}

int main() 
{
    int choice;
    if (!login()) 
    {
        return 1;
    }

    while (true) 
    {

        menu();
        cin >> choice;
        if (choice == !isdigit)
        {
            cout << "Inavlid Option" << endl;
          
           return 1;
        }
        system("cls");
        switch (choice) 
        {
            int ch;
        case 1:
            x:
            jobmenu();
            cin >> ch;
             if (ch == !isdigit)
        {
            cout << "Inavlid Option" << endl;
          
           return 1;
        }
            system("cls");
            switch (ch)
            {
            case 1:
                wjob();
                goto x;
                break;
            case 2:
                displayjob();
                goto x;
                break;
            case 3:
                updatejob();
                goto x;
                break;
            case 4:
                deletejob();
                goto x;
                break;
            case 5:
                readjobdata();
                goto x;
                break;
            case 6:
                break;
            default:
                cout << "Invalid option, going back to main menu\n";
                break;
            }
            break;
        case 2:
            y:
            candidatemenu();
            cin >> ch;
             if (ch == !isdigit)
        {
            cout << "Inavlid Option" << endl;
          
           return 1;
        }
            system("cls");
            switch (ch) 
            {
            case 1:
                wcandidate();
                goto y;
                break;
            case 2:
                readcandidatedata();
                goto y;
                break;
            case 3:
                displaycandidates();
                
                goto y; 
                break;
            case 4:
                updatecandidate();
                goto y;
                break;
            case 5:
                deletecandidate();
                goto y;
                break;
            case 6:
                break;
            default:
                cout << "Invalid option, going back to main menu\n";
                break;
            }
            break;
        case 3:
            cout << "Good bye\n";
            return 0;
        default:
            cout << "Invalid option, Please select appropriate option again :\n";
            cout << endl;

            break;
        }
    }
    return 0;
}

void menu() 
{
    cout << "Enter 1 to create, update or delete job\n";
    cout << "Enter 2 to create, update or delete candidate\n";
    cout << "Enter 3 to exit\n";
}

void jobmenu() 
{
    cout << "Enter 1 to create job\n";
    cout << "Enter 2 to display job data\n";
    cout << "Enter 3 to update job\n";
    cout << "Enter 4 to delete job\n";
    cout << "Enter 5 to read job data from the file\n";
    cout << "Enter 6 to go back to main menu\n";
}

void wjob() 
{
    wfile.open("JobFile.txt");
    for (int i = 0; i < maxSize; i++) 
    {
        j[i].getjobdata();
        wfile.write((char*)&j[i], sizeof(j[i]));
    }
    wfile.close();
}

void updatejob()
{
    string jobname;
    wfile.open("JobFile.txt");
    cout << "Enter Job name you want to update: ";
    cin >> jobname;
    for (int i = 0; i < maxSize; i++) 
    {
        if (j[i].job != jobname) 
        {
            wfile.write((char*)&j[i], sizeof(j[i]));
        }
        else {
            cout << "You can only change the name of the job\n";
            cout << "Enter new name of the job: ";
            cin >> j[i].job;
            wfile.write((char*)&j[i], sizeof(j[i]));
        }
    }
    wfile.close();
    readjobdata();
}

void deletejob() 
{
    string jobname;
    int count = 0;
    wfile.open("JobFile.txt");
    cout << "Enter Job name you want to delete: ";
    cin >> jobname;
    for (int i = 0; i < maxSize; i++) 
    {
        if (j[i].job != jobname) 
        {
            wfile.write((char*)&j[i], sizeof(j[i]));
            count++;
        }
    }
    wfile.close();
    maxSize = count;
    readjobdata();
}

void readjobdata()
{
    no_of_records = 0;
    rfile.open("JobFile.txt");
    for (int i = 0; i < maxSize; i++) 
    {
        rfile.read((char*)&j[i], sizeof(j[i]));
        no_of_records++;
    }
    rfile.close();
}

void displayjob()
{
    readjobdata();
    for (int i = 0; i < no_of_records; i++) 
    {
        j[i].displayjobdata();
        cout << endl;
    }
}

void candidatemenu() 
{
    cout << "Enter 1 to create candidate\n";
    cout << "Enter 2 to read candidate data from file\n";
    cout << "Enter 3 to display data of candidates\n";
    cout << "Enter 4 to update candidate\n";
    cout << "Enter 5 to delete candidate\n";
    cout << "Enter 6 to go back to main menu\n";
}

void wcandidate() 
{
    wfile.open("CandidateFile.txt");
    for (int i = 0; i < maxSize; i++)
    {
        c[i].getData();
        wfile.write((char*)&c[i], sizeof(c[i]));
    }
    wfile.close();
}

void updatecandidate() 
{
    int candno;
    wfile.open("CandidateFile.txt");
    cout << "Enter Candidate number you want to update: ";
    cin >> candno;
    candno = candno - 1;
    for (int i = 0; i < maxSize; i++)
    {
        if (i != candno)
        {
           wfile.write((char*)&c[i], sizeof(c[i]));
        }
        else {
            cout << "Updating Candidate data\n";
            c[i].getData();
            wfile.write((char*)&c[i], sizeof(c[i]));
        }
    }
    wfile.close();
    readcandidatedata();
}

void deletecandidate()
{
    int candno, count = 0;
    wfile.open("CandidateFile.txt");
    cout << "Enter Candidate number you want to delete: ";
    cin >> candno;
    for (int i = 0; i < maxSize; i++) 
    {
        if (i != candno) 
        {
            wfile.write((char*)&c[i], sizeof(c[i]));
            count++;
        }
    }
    wfile.close();
    maxSize = count;
    readcandidatedata();
}

void readcandidatedata() 
{
    no_of_records = 0;
    rfile.open("CandidateFile.txt");
    for (int i = 0; i < maxSize; i++) 
    {
        rfile.read((char*)&c[i], sizeof(c[i]));
        no_of_records++;
    }
    rfile.close();
}

void displaycandidates() 
{
    readcandidatedata();
    for (int i = 0; i < no_of_records; i++) 
    {
        c[i].displayData();
    }
}
