#include <iostream>
#include <vector>
using namespace std;

struct Student {
    int id;
    string name;

    float math;
    float physics;
    float chemistry;
    float computer;

    int attendance;
};

vector<Student> students;

float percentage(Student s)
{
    return (s.math + s.physics + s.chemistry + s.computer) / 4;
}

string grade(float p)
{
    if(p >= 90) return "A+";
    else if(p >= 80) return "A";
    else if(p >= 70) return "B";
    else if(p >= 60) return "C";
    else return "D";
}

void addStudent()
{
    Student s;

    cout<<"Enter ID: ";
    cin>>s.id;

    cout<<"Enter Name: ";
    cin>>s.name;

    cout<<"Math Marks: ";
    cin>>s.math;

    cout<<"Physics Marks: ";
    cin>>s.physics;

    cout<<"Chemistry Marks: ";
    cin>>s.chemistry;

    cout<<"Computer Marks: ";
    cin>>s.computer;

    cout<<"Attendance (%): ";
    cin>>s.attendance;

    students.push_back(s);

    cout<<"\nStudent Added Successfully\n";
}

void displayStudents()
{
    if(students.empty())
    {
        cout<<"No Records Found\n";
        return;
    }

    for(auto s: students)
    {
        float p = percentage(s);

        cout<<"\n---------------------------\n";
        cout<<"ID: "<<s.id<<endl;
        cout<<"Name: "<<s.name<<endl;

        cout<<"Math: "<<s.math<<endl;
        cout<<"Physics: "<<s.physics<<endl;
        cout<<"Chemistry: "<<s.chemistry<<endl;
        cout<<"Computer: "<<s.computer<<endl;

        cout<<"Percentage: "<<p<<endl;
        cout<<"Grade: "<<grade(p)<<endl;

        cout<<"Attendance: "<<s.attendance<<"%"<<endl;

        if(s.attendance < 75)
        cout<<"Warning: Low Attendance"<<endl;
    }
}

void searchStudent()
{
    int id;

    cout<<"Enter ID to Search: ";
    cin>>id;

    for(auto s: students)
    {
        if(s.id == id)
        {
            float p = percentage(s);

            cout<<"\nStudent Found\n";
            cout<<"Name: "<<s.name<<endl;
            cout<<"Percentage: "<<p<<endl;
            cout<<"Grade: "<<grade(p)<<endl;
            return;
        }
    }

    cout<<"Student Not Found\n";
}

void updateStudent()
{
    int id;

    cout<<"Enter ID to Update: ";
    cin>>id;

    for(auto &s: students)
    {
        if(s.id == id)
        {
            cout<<"Enter New Marks\n";

            cout<<"Math: ";
            cin>>s.math;

            cout<<"Physics: ";
            cin>>s.physics;

            cout<<"Chemistry: ";
            cin>>s.chemistry;

            cout<<"Computer: ";
            cin>>s.computer;

            cout<<"Attendance: ";
            cin>>s.attendance;

            cout<<"Record Updated\n";
            return;
        }
    }

    cout<<"Student Not Found\n";
}

void deleteStudent()
{
    int id;

    cout<<"Enter ID to Delete: ";
    cin>>id;

    for(int i=0;i<students.size();i++)
    {
        if(students[i].id == id)
        {
            students.erase(students.begin()+i);

            cout<<"Student Deleted\n";
            return;
        }
    }

    cout<<"Student Not Found\n";
}

void showTopper()
{
    if(students.empty())
    {
        cout<<"No Records\n";
        return;
    }

    Student topper = students[0];

    for(auto s: students)
    {
        if(percentage(s) > percentage(topper))
        topper = s;
    }

    cout<<"\nClass Topper\n";
    cout<<"Name: "<<topper.name<<endl;
    cout<<"Percentage: "<<percentage(topper)<<endl;
}

void classAverage()
{
    if(students.empty())
    {
        cout<<"No Records\n";
        return;
    }

    float total = 0;

    for(auto s: students)
    total += percentage(s);

    cout<<"Class Average: "<< total / students.size() <<endl;
}

void lowAttendance()
{
    cout<<"\nStudents with Low Attendance (<75%)\n";

    for(auto s: students)
    {
        if(s.attendance < 75)
        {
            cout<<"Name: "<<s.name<<"  Attendance: "<<s.attendance<<"%"<<endl;
        }
    }
}

int main()
{
    int choice;

    do
    {
        cout<<"\n====================================\n";
        cout<<" SMART STUDENT RECORD MANAGER\n";
        cout<<"====================================\n";

        cout<<"1 Add Student\n";
        cout<<"2 Display Students\n";
        cout<<"3 Search Student\n";
        cout<<"4 Update Student\n";
        cout<<"5 Delete Student\n";
        cout<<"6 Show Topper\n";
        cout<<"7 Class Average\n";
        cout<<"8 Low Attendance Students\n";
        cout<<"9 Exit\n";

        cout<<"Enter Choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: showTopper(); break;
            case 7: classAverage(); break;
            case 8: lowAttendance(); break;
        }

    } while(choice != 9);

}
