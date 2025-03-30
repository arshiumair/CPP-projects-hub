#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

class student{
    private:
    int roll;
    string name, department, batch;
    char class_Section;

    public:
    //setters
    void setname(string name )              { this-> name = name; }
    void setdepartment(string department )  { this-> name = department; }
    void setroll(int roll )                 { this-> roll = roll; }
    void setbatch(string batch )            { this-> batch = batch; }
    void setsection(char class_Section)     { this-> class_Section = class_Section; }

    //getters
    string getname()            { return this->name; }
    string getdepartment()      { return this->department; }
    int getroll()               { return this->roll; }
    string getbatch()           { return this->batch; }
    char getsection()           { return this->class_Section; }

    //creat student data in a cnstructor
    student(string name, string department, char class_Section, int roll, string batch)
    {
        this-> name = name;
        this-> department = department;
        this-> roll = roll;
        this-> batch = batch;
        this-> class_Section = class_Section;
    }
    //deafult cnstructor
    student() {}


};
class studentManagementsystem{
    private:
    vector <student> students;
    public:

    //add student
    void addstudent(student& Student)
    {    
        students.push_back(Student);
    }

    //remove student
    void removestudent(int roll)
    {
        for(auto it = students.begin(); it != students.end(); it++)
        {
            if(it->getroll()== roll)
            {
                students.erase(it);
                cout << "student with roll no. " << roll<< " has been removed successfully." << endl;
                return;
            }
        }
        cout << "student with roll no. " << roll<< " NOT found!" << endl;
        return;
    }

    //display all students in the system
    void displaystudents()
    {
        if(students.empty())
        {
            cout << "There is NO student in the system." << endl;
            return;
        }else
        {  
            int Sno = 1;  
            for( auto temp : students)
            {
                cout << "Std: " << Sno<<endl;
                cout << "      Roll: " << temp.getroll()<<endl;
                cout << "      Name: " << temp.getname()<<endl;
                cout << "      Depart.: " << temp.getdepartment()<<endl;
                cout << "      class_Section: " << temp.getsection()<<endl;
                cout << "      Session: " << temp.getbatch()<<endl;
                cout << "___________________________________" << endl;
                Sno++;
            }
        }
    }

    //Show student details
    void show_Student(int roll)
    {
        for(auto it = students.begin(); it != students.end(); it++)
        {
            if(it->getroll()== roll)
            {
                cout << "Roll: " << it->getroll()<<endl;
                cout << "Name: " << it->getname()<<endl;
                cout << "Depart.: " << it->getdepartment()<<endl;
                cout << "class_Section: " << it->getsection()<<endl;
                cout << "Batch: " << it->getbatch()<<endl;
                cout << "___________________________________" << endl;
                return;
            }
        }
        return;
    }

    //check student in database
    bool check_Student(int roll)
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
    
    //verify student
    bool check_Student(int S_roll, string S_department, string S_batch, char S_class_Section)
    {   
        for(auto it = students.begin(); it != students.end(); it++)
        {
            if(it->getroll()== S_roll && it->getdepartment() == S_department && it->getbatch() == S_batch && it->getsection() == S_class_Section)
            {
                return true;
            }
        }
        return false;
    } 
    
    //Edit and push New data

    void Editinfo(int rollNumber, student Newstudent)
    {
        for(auto it = students.begin(); it != students.end(); it++)
        {
            if(it->getroll()== rollNumber)
            {   int index = distance(students.begin(),it);
                students[index]=Newstudent;
            }
        }
    }

    //Home content
    void showHeader()
    {
        cout << "ICIT Database for student record" << endl;
        cout << "___________________________________" << endl;
    }


};

int main()
{
    
    
    studentManagementsystem SMS;
    
    int choice = 0, choice2;
    string name,department,batch ;
    char class_Section;
    int rollNumber;
    while(true)
    {    
        switch(choice)
        {
            case 0:
            {
               SMS.showHeader();
                cout << "________________Home_______________" << endl;
                cout << "\nChose an operation" << endl;
                cout << "1. Add student\n2. Remove student\n3. Search\n4. Displayall\n5. Edit info\n6. Exit" << endl;
                cin >> choice;
            }break;
            case 1:
            {
               SMS.showHeader();
                cout << "______________Add Data_____________" << endl;
                cout << "\nEnter student full name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter student department: ";
                cin >> department;
                cout << "Enter student Roll No : ";
                cin >> rollNumber;
                cout << "Enter student Session (Y_From-To): ";
                cin >> batch;
                cout << "Enter student class_Section (A,B,C): ";
                cin >> class_Section;
                cout << "Verifying..."<<endl;
                if(SMS.check_Student(rollNumber, department, batch, class_Section) == true)
                {
                    cout << "Student already exist.." <<endl;
                    SMS.show_Student(rollNumber);
                    cout << "1. Add another \n0. Home" << endl;
                    cin >> choice2;
                    (choice2 == 1)? choice = 1 : choice = 0;
                }else{
                    cout << "Added successfully.."<<endl;
                    student s1(name, department, class_Section, rollNumber, batch);
                    SMS.addstudent(s1);
                    cout << "1. Add another\n0. Home" << endl;
                    cin >> choice2;
                    (choice2 == 1)? choice = 1 : choice = 0;
                }
            }break;
            case 2:
            {                
                
                cout << "___________Remove Data__________" << endl;
                cout << "\nEnter roll number > ";
                cin >> rollNumber;
                SMS.removestudent(rollNumber);
                getch();
                cout << "1. Remove another\n0. Home" << endl;
                cin >> choice2;
                (choice2 == 1)? choice = 2 : choice = 0;

            }break;
            case 3:
            {
                SMS.showHeader();
                cout << "_______________Search______________" << endl;
                cout << "\nEnter roll number > ";
                cin >> rollNumber;
                SMS.showHeader();
                cout << "_______________Search______________" << endl;
                if(SMS.check_Student(rollNumber) == true)
                {
                    cout << "Student found..."<<endl;
                    SMS.show_Student(rollNumber);
                }else
                {
                    cout<<"Student with roll number '"<<rollNumber<<"' NOT found"<<endl;
                }
                
                getch();
                cout << "1. Search another\n0. Home" << endl;
                cin >> choice2;
                (choice2 == 1)? choice = 3 : choice = 0;

            }break;
            case 4:
            {
                SMS.showHeader();
                cout << "_____________View List_____________\n" << endl;
                SMS.displaystudents();
                getch();
                top4:
                cout << "1. Add student\n9. Exit\n0. Home" << endl;
                cin >> choice2;
                if(choice2 == 9)
                {
                    choice = 6;
                }else
                {
                   (choice2 == 1)? choice = 1 : choice = 0; 
                }
                
            }break;
            case 5:
            {
                SMS.showHeader();
                cout << "____________Edit Record____________" << endl;
                cout<< "\nSearch for student!\nEnter roll no > ";
                cin >> rollNumber;
                bool status = SMS.check_Student(rollNumber);
                if(status == false )
                {
                    cout << "student with roll no. " << rollNumber<< " NOT found!" << endl;
                    cout << "1. Try another Roll no\n2. Add new Student\n0. Home" << endl;
                    
                    cin >> choice2;
                    if(choice2 == 1)
                    {
                        choice = 5;
                    }else
                    {
                       (choice2 == 2)? choice = 1 : choice = 0; 
                    }
                }else{
                    SMS.show_Student(rollNumber);
                    cout << "Enter new credentials.." << endl;
                    cout << "Enter NEW name: ";
                    int new_rollnumber;
                    cin.ignore();
                    getline(cin, name);
                    cout << "Enter NEW department: ";
                    cin >> department;
                    cout << "Enter NEW roll no: ";
                    cin >> new_rollnumber;
                    cout << "Enter NEW Session: ";
                    cin >> batch;
                    cout << "Enter NEW Setion: ";
                    cin >> class_Section;
                    student tempobj(name, department, class_Section, new_rollnumber, batch);
                    SMS.Editinfo(rollNumber ,tempobj);
                    cout << "changes have been saved successfully" << endl;
                    cout << "1. make another change\n0. Home" << endl;
                    cin >> choice2;
                    (choice2 == 1)? choice = 5 : choice = 0;
                }                

            }break;
            case 6:
            {
                SMS.showHeader();
                cout << "exiting..";
                return 0;
            }break;
            default:
            {
                SMS.showHeader();
                cout << "wrong input.! Redirecting..." << endl;
                getch();
                choice = 0;
            }
        }
    }

    return 0;
}
