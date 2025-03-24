#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

class student{
    private:
    string name ;
    string department;
    int roll;
    string batch;
    char section;

    public:
    //setters
    void setname(string name )              { this-> name = name; }
    void setdepartment(string department )  { this-> name = department; }
    void setroll(int roll )                 { this-> roll = roll; }
    void setbatch(string batch )               { this-> batch = batch; }
    void setsection(char section)           { this-> section = section; }

    //getters
    string getname()        { return this->name; }
    string getdepartment()  { return this->department; }
    int getroll()           { return this->roll; }
    string getbatch()          { return this->batch; }
    char getsection()       { return this->section; }

    //creat student data in a cnstructor
    student(string name, string department, char section, int roll, string batch)
    {
        this-> name = name;
        this-> department = department;
        this-> roll = roll;
        this-> batch = batch;
        this-> section = section;
    }
    //deafult cnstructor
    student() {}


};

class studentManagementsystem{
    private:
    vector <student> students;

    public:

    //add student

    void addstudent(student& studentA)
    {    
        students.push_back(studentA);
    }

    //remove student

    void removestudent(int roll)
    {
        for(auto it = students.begin(); it != students.end(); it++)
        {
             
            if(it->getroll()== roll)
            {
                students.erase(it);
                cout <<"student with roll no. "<<roll<<" has been removed successfully."<<endl;
                return;
            }
        }
        cout <<"student with roll no. "<<roll<<" NOT found!"<<endl;
        return;
    }

    //display all students in the system

    void displaystudents()
    {
        if(students.empty())
        {
            cout <<"There are no students in the system."<<endl;
            return;
        }else
        {  
            int Sno = 1;  
            for( auto temp : students)
            {
                cout <<"Std#"<<Sno<<endl;
                cout <<"      Roll: "<<temp.getroll()<<endl;
                cout <<"      Name: "<<temp.getname()<<endl;
                cout <<"      Depart.: "<<temp.getdepartment()<<endl;
                cout <<"      Section: "<<temp.getsection()<<endl;
                cout <<"      Session: "<<temp.getbatch()<<endl;
                cout <<"___________________________________"<<endl;
                Sno++;
            }
        }
    }

    //search student

    void searchstudent(int roll)
    {
        cout <<"Searching..."<<endl;
        for(auto it = students.begin(); it != students.end(); it++)
        {
            
             
            if(it->getroll()== roll)
            {
                cout <<"student found."<<endl;
                cout <<"Roll: "<<it->getroll()<<endl;
                cout <<"Name: "<<it->getname()<<endl;
                cout <<"Depart.: "<<it->getdepartment()<<endl;
                cout <<"Section: "<<it->getsection()<<endl;
                cout <<"Batch: "<<it->getbatch()<<endl;
                cout <<"___________________________________"<<endl;
                return;
            }
        }
        cout <<"student with roll no. "<<roll<<" NOT found!"<<endl;
        return;
    }

    //check student in database
    bool checkstudent(int roll)
    {   
        for(auto it = students.begin(); it != students.end(); it++)
        {
            if(it->getroll()== roll)
            {
                return true;
            }
        }
        return false;
    }    
    
    //Show studnet data
    void showinfo(int rolln)
    {
        for(auto it = students.begin(); it != students.end(); it++)
        {
            if(it->getroll()== rolln)
            {
                cout <<"Current credentials"<<endl;
                cout <<"Roll: "<<it->getroll()<<endl;
                cout <<"Name: "<<it->getname()<<endl;
                cout <<"Depart.: "<<it->getdepartment()<<endl;
                cout <<"Section: "<<it->getsection()<<endl;
                cout <<"Batch: "<<it->getbatch()<<endl;
                cout <<"___________________________________"<<endl;
            }
        }
    }

    //Edit and push New data
    void Editinfo(int rolln, student Newstudent)
    {
        for(auto it = students.begin(); it != students.end(); it++)
        {
            if(it->getroll()== rolln)
            {   int index = distance(students.begin(),it);
                students.erase(it); //remove previous data
                students.insert(students.begin() + index,Newstudent);
            }
        }
    }


};

int main()
{
    system("cls");
    studentManagementsystem SMS;
    
    int choice = 0;
    while(true)
    {    
        switch(choice)
        {
            case 0:
            {
                system("cls");
                cout <<"ICIT Database for student record"<<endl;
                cout <<"___________________________________"<<endl;
                cout <<"________________Home_______________"<<endl;
                cout <<"\nChose an operation"<<endl;
                cout <<"1. Add student\n2. Remove student\n3. Search\n4. Displayall\n5. Edit info\n6. Exit"<<endl;
                cin >>choice ;
            }break;
            case 1:
            {
                system("cls");
                cout <<"ICIT Database for student record"<<endl;
                cout <<"___________________________________"<<endl;
                cout <<"______________Add Data_____________"<<endl;
                string name;
                string department;
                string batch;
                char section;
                int rolln;
                cout <<"\nEnter student full name: ";
                cin.ignore();
                getline(cin, name);
                cout <<"Enter student department: ";
                cin >> department;
                cout << "Enter student Roll No : ";
                cin >> rolln;
                cout << "Enter student Session (Y_From-To): ";
                cin >> batch;
                cout << "Enter student Section (A,B,C): ";
                cin >> section;
                student s1(name, department, section, rolln, batch);
                SMS.addstudent(s1);
                top1:
                cout <<"1. Add another\n0. Home"<<endl;
                int choice2;
                cin >> choice2;
                if(choice2 == 1)
                {
                    choice = choice2;
                }else if(choice2 == 0)
                {
                    choice = 0;
                }else
                {
                    cout<<"Error..! wrong input"<<endl;
                    goto top1;
                }

            }break;
            case 2:
            {
                system("cls");
                cout <<"ICIT Database for student record"<<endl;
                cout <<"___________Remove Data__________"<<endl;
                cout <<"\nEnter roll number > ";
                int rolln;
                cin >> rolln;
                SMS.removestudent(rolln);
                getch();
                top2:
                cout <<"1. Remove another\n0. Home"<<endl;
                int choice2;
                cin >> choice2;
                if(choice2 == 1)
                {
                    choice = 2;
                }else if(choice2 == 0)
                {
                    choice = 0;
                }else
                {
                    cout<<"Error..! wrong input"<<endl;
                    goto top2;
                }

            }break;
            case 3:
            {
                system("cls");
                cout <<"ICIT Database for student record"<<endl;
                cout <<"___________________________________"<<endl;
                cout <<"_______________Search______________"<<endl;
                cout <<"\nEnter roll number > ";
                int rolln;
                cin >> rolln;
                system("cls");
                cout <<"ICIT Database for student record"<<endl;
                cout <<"___________________________________"<<endl;
                cout <<"_______________Search______________"<<endl;
                SMS.searchstudent(rolln);
                getch();
                top3:
                cout <<"1. Search another\n0. Home"<<endl;
                int choice2;
                cin >> choice2;
                if(choice2 == 1)
                {
                    choice = 3;
                }else if(choice2 == 0)
                {
                    choice = 0;
                }else
                {
                    cout<<"Error..! wrong input"<<endl;
                    goto top3;
                }
            }break;
            case 4:
            {
                system("cls");
                cout <<"ICIT Database for student record"<<endl;
                cout <<"___________________________________"<<endl;
                cout <<"_____________View List_____________\n"<<endl;
                SMS.displaystudents();
                getch();
                top4:
                cout <<"1. Add student\n9. Exit\n0. Home"<<endl;
                int choice2;
                cin >> choice2;
                if(choice2 == 1)
                {
                    choice = 1;
                }else
                if(choice2 == 9)
                {
                    cout <<"exiting..";
                    return 0;
                }else if(choice2 == 0)
                {
                    choice = 0;
                }else
                {
                    cout<<"Error..! wrong input"<<endl;
                    goto top4;
                }
            }break;
            case 5:
            {
                system("cls");
                cout <<"ICIT Database for student record"<<endl;
                cout <<"___________________________________"<<endl;
                cout <<"____________Edit Record____________"<<endl;
                cout<<"\nSearch for student!\nEnter roll no > ";
                int rolln;
                cin >> rolln;
                bool status = SMS.checkstudent(rolln);
                if(status == false )
                {
                    cout <<"student with roll no. "<<rolln<<" NOT found!"<<endl;
                    getch();
                    top5:
                    cout <<"1. Try another Roll no\n2. Add new Student\n0. Home"<<endl;
                    int choice2;
                    cin >> choice2;
                    if(choice2 == 1)
                    {
                        choice = 5;
                    }else if(choice2 == 2)
                    {
                        choice = 1;
                    }else if(choice2 == 0)
                    {
                        choice = 0;
                    }else
                    {
                        cout<<"Error..! wrong input"<<endl;
                        goto top5;
                    }
                }else{
                    SMS.showinfo(rolln);
                    cout <<"Enter new credentials.."<<endl;
                    cout <<"Enter NEW name: ";
                    string name;
                    string department;
                    string batch;
                    char section;
                    int rollno;
                    cin.ignore();
                    getline(cin, name);
                    cout <<"Enter NEW department: ";
                    cin >> department;
                    cout <<"Enter NEW roll no: ";
                    cin >> rollno;
                    cout << "Enter NEW Session: ";
                    cin >> batch;
                    cout << "Enter NEW Setion: ";
                    cin >> section;
                    student tempobj(name, department, section, rollno, batch);
                    SMS.Editinfo(rollno ,tempobj);
                    cout <<"changes have been saved successfully"<<endl;
                    getch();
                    top6:
                    cout <<"1. make another change\n0. Home"<<endl;
                    int choice2;
                    cin >> choice2;
                    if(choice2 == 1)
                    {
                        choice = 5;
                    }else if(choice2 == 0)
                    {
                        choice = 0;
                    }else
                    {
                        cout<<"Error..! wrong input"<<endl;
                        goto top6;
                    }
                }
                
                

            }break;
            case 6:
            {
                system("cls");
                cout <<"ICIT Database for student record"<<endl;
                cout <<"___________________________________"<<endl;
                cout <<"exiting..";
                return 0;
            }break;
            default:
            {
                cout <<"wrong input.! Redirecting..."<<endl;
                getch();
                choice = 0;
            }
        }
    }

    return 0;
}