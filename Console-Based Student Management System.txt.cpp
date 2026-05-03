#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

class Student
{
public:
string name;
int rollNo;
float oopsMarks;
float dsaMarks;
float mathsMarks;
float total;
float percentage;
float cgpa;
string course;
int age;
int attendance;
string address;
string phoneNumber;
char grade;
string result;
};

Student students[100];

int totalStudents = 0;
void saveToFile();
void loadFromFile();

// ADD STUDENT
void addStudent()
{
    cout << "\nEnter Name: ";
    cin.ignore();

getline(cin, students[totalStudents].name);

    cout << "Enter Roll Number: ";
    cin >> students[totalStudents].rollNo;
    for (int i = 0; i < totalStudents; i++)
{
    if (students[i].rollNo == students[totalStudents].rollNo)
    {
        cout << "\nRoll Number Already Exists!\n";

        return;
    }
}

  cout << "Enter OOPS Marks: ";
cin >> students[totalStudents].oopsMarks;

cout << "Enter DSA Marks: ";
cin >> students[totalStudents].dsaMarks;

cout << "Enter Maths Marks: ";
cin >> students[totalStudents].mathsMarks;

students[totalStudents].total =
students[totalStudents].oopsMarks +
students[totalStudents].dsaMarks +
students[totalStudents].mathsMarks;

students[totalStudents].percentage =
students[totalStudents].total / 3;

students[totalStudents].cgpa =
students[totalStudents].percentage / 9.5;
if (students[totalStudents].percentage >= 90)
{
    students[totalStudents].grade = 'A';
}

else if (students[totalStudents].percentage >= 75)
{
    students[totalStudents].grade = 'B';
}

else if (students[totalStudents].percentage >= 50)
{
    students[totalStudents].grade = 'C';
}

else if (students[totalStudents].percentage >= 33)
{
    students[totalStudents].grade = 'D';
}

else
{
    students[totalStudents].grade = 'F';
}if (students[totalStudents].oopsMarks < 33 ||
    students[totalStudents].dsaMarks < 33 ||
    students[totalStudents].mathsMarks < 33)
{
    students[totalStudents].result = "Fail";
}

else
{
    students[totalStudents].result = "Pass";
}

cout << "Enter Age: ";
cin >> students[totalStudents].age;

cout << "Enter Attendance Percentage: ";
cin >> students[totalStudents].attendance;

cout << "Enter Course: ";
cin >> students[totalStudents].course;

cout << "Enter Address: ";
cin.ignore();
getline(cin, students[totalStudents].address);

cout << "Enter Phone Number: ";
cin >> students[totalStudents].phoneNumber;

    totalStudents++;
    saveToFile();
    cout << "\nStudent Added Successfully!\n";
}


// SHOW ALL STUDENTS
void showStudents()
{
    if (totalStudents == 0)
    {
        cout << "\nNo Students Found.\n";
    }

    else
    {
      cout << "\n====================================\n";
cout << "         STUDENT RECORDS\n";
cout << "====================================\n";
        for (int i = 0; i < totalStudents; i++)
        {
cout << "\n------------------------------------\n";
cout << "Student " << i + 1 << endl;
cout << "------------------------------------\n";

            cout << "Name: "
                 << students[i].name << endl;

            cout << "Roll Number: "
                 << students[i].rollNo << endl;
cout << "OOPS Marks: "
     << students[i].oopsMarks << endl;

cout << "DSA Marks: "
     << students[i].dsaMarks << endl;

cout << "Maths Marks: "
     << students[i].mathsMarks << endl;

cout << "Total: "
     << students[i].total << endl;

cout << "Percentage: "
     << students[i].percentage << "%" << endl;
 cout << "CGPA: "
     << students[i].cgpa << endl;                
                 cout << "Grade: "
     << students[i].grade << endl;
        
        cout << "Result: "
     << students[i].result << endl;
              
                 cout << "Age: "
     << students[i].age << endl;
     
     cout << "Attendance: "
     << students[i].attendance
     << "%" << endl;
     
     cout << "Course: "
     << students[i].course << endl;
     
     cout << "Address: "
     << students[i].address << endl;

cout << "Phone Number: "
     << students[i].phoneNumber << endl;
        }
    }
}


// SEARCH STUDENT
void searchStudent()
{
    int roll;

    cout << "\nEnter Roll Number to Search: ";
    cin >> roll;

    bool found = false;

    for (int i = 0; i < totalStudents; i++)
    {
        if (students[i].rollNo == roll)
        {
            cout << "\nStudent Found!\n";

            cout << "Name: "
                 << students[i].name << endl;

            cout << "Roll Number: "
                 << students[i].rollNo << endl;

            cout << "Percentage: "
                 << students[i].percentage
                 << "%" << endl;

            found = true;

            break;
        }
    }

    if (!found)
    {
        cout << "\nStudent Not Found.\n";
    }
    }
void searchStudentByName()
{
    string searchName;

    cout << "\nEnter Name to Search: ";

    cin.ignore();

    getline(cin, searchName);

    bool found = false;

    for (int i = 0; i < totalStudents; i++)
    {
        if (students[i].name == searchName)
        {
            found = true;

            cout << "\n====================================\n";
            cout << "         STUDENT FOUND\n";
            cout << "====================================\n";

            cout << "Name: "
                 << students[i].name << endl;

            cout << "Roll Number: "
                 << students[i].rollNo << endl;

            cout << "Percentage: "
                 << students[i].percentage
                 << "%" << endl;

            cout << "CGPA: "
                 << students[i].cgpa << endl;

            cout << "Grade: "
                 << students[i].grade << endl;

            cout << "Result: "
                 << students[i].result << endl;

            break;
        }
    }

    if (!found)
    {
        cout << "\nStudent Not Found.\n";
    }
}

// DELETE STUDENT
void deleteStudent()
{
    int roll;

    cout << "\nEnter Roll Number to Delete: ";
    cin >> roll;

    bool found = false;

    for (int i = 0; i < totalStudents; i++)
    {
        if (students[i].rollNo == roll)
        {
            for (int j = i; j < totalStudents - 1; j++)
            {
                students[j] = students[j + 1];
            }

            totalStudents--;

            found = true;
            saveToFile();

            cout << "\nStudent Deleted Successfully!\n";

            break;
        }
    }

    if (!found)
    {
        cout << "\nStudent Not Found.\n";
    }
}


// UPDATE STUDENT
void updateStudent()
{
    int roll;

    cout << "\nEnter Roll Number to Update: ";
    cin >> roll;

    bool found = false;

    for (int i = 0; i < totalStudents; i++)
    {
        if (students[i].rollNo == roll)
        {
            cout << "\nEnter New Name: ";
            cin.ignore();
getline(cin, students[i].name);
            
           cout << "Enter New OOPS Marks: ";
cin >> students[i].oopsMarks;

cout << "Enter New DSA Marks: ";
cin >> students[i].dsaMarks;

cout << "Enter New Maths Marks: ";
cin >> students[i].mathsMarks;
students[i].total =
students[i].oopsMarks +
students[i].dsaMarks +
students[i].mathsMarks;
students[i].percentage =
students[i].total / 3;
students[i].cgpa =
students[i].percentage / 9.5;

if (students[i].percentage >= 90)
{
    students[i].grade = 'A';
}

else if (students[i].percentage >= 75)
{
    students[i].grade = 'B';
}

else if (students[i].percentage >= 50)
{
    students[i].grade = 'C';
}

else if (students[i].percentage >= 33)
{
    students[i].grade = 'D';
}

else
{
    students[i].grade = 'F';
}

if (students[i].oopsMarks < 33 ||
    students[i].dsaMarks < 33 ||
    students[i].mathsMarks < 33)
{
    students[i].result = "Fail";
}

else
{
    students[i].result = "Pass";
}
            found = true;
saveToFile();
            cout << "\nStudent Updated Successfully!\n";

            break;
        }
    }

    if (!found)
    {
        cout << "\nStudent Not Found.\n";
    }
}


// MAIN FUNCTION

void showTopper()
{
    if (totalStudents == 0)
    {
        cout << "\nNo Students Found.\n";
        return;
    }

    int topperIndex = 0;

    for (int i = 1; i < totalStudents; i++)
    {
        if (students[i].percentage >
            students[topperIndex].percentage)
        {
            topperIndex = i;
        }
    }

    cout << "\n====================================\n";
    cout << "         TOPPER STUDENT\n";
    cout << "====================================\n";

    cout << "Name: "
         << students[topperIndex].name << endl;

    cout << "Roll Number: "
         << students[topperIndex].rollNo << endl;

    cout << "Percentage: "
         << students[topperIndex].percentage
         << "%" << endl;

    cout << "Grade: "
         << students[topperIndex].grade << endl;
}void showRankings()
{
    if (totalStudents == 0)
    {
        cout << "\nNo Students Found.\n";
        return;
    }

    Student temp;

    for (int i = 0; i < totalStudents - 1; i++)
    {
        for (int j = i + 1; j < totalStudents; j++)
        {
            if (students[j].percentage >
                students[i].percentage)
            {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }

    cout << "\n====================================\n";
    cout << "         STUDENT RANKINGS\n";
    cout << "====================================\n";

    for (int i = 0; i < totalStudents; i++)
    {
        cout << "\nRank #" << i + 1 << endl;

        cout << "Name: "
             << students[i].name << endl;

        cout << "Percentage: "
             << students[i].percentage
             << "%" << endl;

        cout << "Grade: "
             << students[i].grade << endl;
    }
}
void saveToFile()
{
    ofstream file("students.txt");

    for (int i = 0; i < totalStudents; i++)
    {
        file << students[i].name << endl;
        file << students[i].rollNo << endl;

        file << students[i].oopsMarks << endl;
        file << students[i].dsaMarks << endl;
        file << students[i].mathsMarks << endl;

        file << students[i].total << endl;
        file << students[i].percentage << endl;
        file << students[i].cgpa << endl;

        file << students[i].grade << endl;
        file << students[i].result << endl;

        file << students[i].age << endl;
        file << students[i].attendance << endl;
        file << students[i].course << endl;
        file << students[i].address << endl;
        file << students[i].phoneNumber << endl;
    }

 file.close();
}

void loadFromFile()
{
    ifstream file("students.txt");

    while (getline(file, students[totalStudents].name))
    {
        if (students[totalStudents].name == "")
        {
            break;
        }

        file >> students[totalStudents].rollNo;

        file >> students[totalStudents].oopsMarks;
        file >> students[totalStudents].dsaMarks;
        file >> students[totalStudents].mathsMarks;

        file >> students[totalStudents].total;
        file >> students[totalStudents].percentage;
        file >> students[totalStudents].cgpa;

        file >> students[totalStudents].grade;

        file.ignore();

        getline(file, students[totalStudents].result);

        file >> students[totalStudents].age;

        file >> students[totalStudents].attendance;

        file.ignore();

        getline(file, students[totalStudents].course);

        getline(file, students[totalStudents].address);

        getline(file, students[totalStudents].phoneNumber);

        totalStudents++;
    }

    file.close();
}

// ========================================
// LOGIN SYSTEM
// ========================================
bool login()
{
    string username;
    string password;

    cout << "\n========== LOGIN SYSTEM ==========\n";

    cout << "Enter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    if (username == "admin" &&
        password == "1234")
    {
        cout << "\nLogin Successful!\n";

        return true;
    }

    else
    {
        cout << "\nInvalid Username or Password!\n";

        return false;
    }
}


void generateMarksheet()
{
    int roll;

    cout << "\nEnter Roll Number: ";
    cin >> roll;

    bool found = false;

    for (int i = 0; i < totalStudents; i++)
    {
        if (students[i].rollNo == roll)
        {
            found = true;

            cout << "\n====================================\n";
            cout << "             MARKSHEET\n";
            cout << "====================================\n";

            cout << "\nName        : "
                 << students[i].name << endl;

            cout << "Roll Number : "
                 << students[i].rollNo << endl;

            cout << "Course      : "
                 << students[i].course << endl;


            cout << "OOPS            "
                 << students[i].oopsMarks << endl;

            cout << "DSA             "
                 << students[i].dsaMarks << endl;

            cout << "Maths           "
                 << students[i].mathsMarks << endl;

            cout << "------------------------------------\n";

            cout << "\nTotal       : "
                 << students[i].total << endl;

            cout << "Percentage  : "
                 << students[i].percentage
                 << "%" << endl;
                 
            cout << "CGPA       : "
                  << students[i].cgpa << endl;


            cout << "Grade       : "
                 << students[i].grade << endl;

            cout << "Attendance : "
             << students[i].attendance
            << "%" << endl;
     
            cout << "Result      : "
                 << students[i].result << endl;

            cout << "====================================\n";

            break;
        }
    }

    if (!found)
    {
        cout << "\nStudent Not Found.\n";
    }
}
void countPassedStudents()
{
    int passCount = 0;

    for (int i = 0; i < totalStudents; i++)
    {
        if (students[i].result == "Pass")
        {
            passCount++;
        }
    }

    cout << "\nTotal Passed Students: "
         << passCount << endl;
}
void showFailedStudents()
{
    bool found = false;

    cout << "\n====================================\n";
    cout << "         FAILED STUDENTS\n";
    cout << "====================================\n";

    for (int i = 0; i < totalStudents; i++)
    {
        if (students[i].result == "Fail")
        {
            found = true;

            cout << "\nName: "
                 << students[i].name << endl;

            cout << "Roll Number: "
                 << students[i].rollNo << endl;

            cout << "Percentage: "
                 << students[i].percentage
                 << "%" << endl;

            cout << "Grade: "
                 << students[i].grade << endl;
        }
    }

    if (!found)
    {
        cout << "\nNo Failed Students Found.\n";
    }
}
void showStatistics()
{
    if (totalStudents == 0)
    {
        cout << "\nNo Students Found.\n";
        return;
    }

    int passCount = 0;
    int failCount = 0;

    float totalPercentage = 0;
    float totalOops = 0;
    float totalDsa = 0;
    float totalMaths = 0;

    int topperIndex = 0;

    for (int i = 0; i < totalStudents; i++)
{
    totalOops =
    totalOops + students[i].oopsMarks;

    totalDsa =
    totalDsa + students[i].dsaMarks;

    totalMaths =
    totalMaths + students[i].mathsMarks;

    totalPercentage =
    totalPercentage + students[i].percentage;

    if (students[i].result == "Pass")
    {
        passCount++;
    }

    else
    {
        failCount++;
    }

    if (students[i].percentage >
        students[topperIndex].percentage)
    {
        topperIndex = i;
    }
}

// ========================================
// STATISTICS FUNCTIONS
// ========================================
    float averagePercentage =
    totalPercentage / totalStudents;

    float averageOops =
    totalOops / totalStudents;

    float averageDsa =
    totalDsa / totalStudents;

    float averageMaths =
    totalMaths / totalStudents;

    cout << "\n====================================\n";
    cout << "        STUDENT STATISTICS\n";
    cout << "====================================\n";

    cout << "Total Students    : "
         << totalStudents << endl;

    cout << "Passed Students   : "
         << passCount << endl;

    cout << "Failed Students   : "
         << failCount << endl;

    cout << "Average Percentage: "
         << averagePercentage
         << "%" << endl;

    cout << "Average OOPS Marks : "
         << averageOops << endl;

    cout << "Average DSA Marks  : "
         << averageDsa << endl;

    cout << "Average Maths Marks: "
         << averageMaths << endl;

    cout << "Topper            : "
         << students[topperIndex].name << endl;

    cout << "Top Percentage    : "
         << students[topperIndex].percentage
         << "%" << endl;
}

void exportMarksheet()
{
    int roll;

    cout << "\nEnter Roll Number: ";
    cin >> roll;

    bool found = false;

    for (int i = 0; i < totalStudents; i++)
    {
        if (students[i].rollNo == roll)
        {
            found = true;

            string filename =
"marksheet_" +
to_string(students[i].rollNo) +
".txt";

ofstream file(filename);
time_t now = time(0);

char* dateTime = ctime(&now);

            file << "====================================\n";
            file << "             MARKSHEET\n";
            file << "====================================\n";
file << "Generated On : "
     << dateTime << endl;
     
            file << "\nName        : "
                 << students[i].name << endl;

            file << "Roll Number : "
                 << students[i].rollNo << endl;

            file << "Course      : "
                 << students[i].course << endl;

            file << "\n------------------------------------\n";
            file << "Subject         Marks\n";
            file << "------------------------------------\n";

            file << "OOPS            "
                 << students[i].oopsMarks << endl;

            file << "DSA             "
                 << students[i].dsaMarks << endl;

            file << "Maths           "
                 << students[i].mathsMarks << endl;

            file << "------------------------------------\n";

            file << "\nTotal       : "
                 << students[i].total << endl;

            file << "Percentage  : "
                 << students[i].percentage
                 << "%" << endl;

            file << "CGPA        : "
                 << students[i].cgpa << endl;

            file << "Grade       : "
                 << students[i].grade << endl;

            file << "Attendance  : "
                 << students[i].attendance
                 << "%" << endl;

            file << "Result      : "
                 << students[i].result << endl;

            file << "====================================\n";

            file.close();

            cout << "\nMarksheet Exported Successfully!\n";

            cout << "File Name: "
            << filename << endl;

            break;
        }
    }

    if (!found)
    {
        cout << "\nStudent Not Found.\n";
    }
}

void showDateTime()
{
    time_t now = time(0);

    char* dt = ctime(&now);

    cout << "\nCurrent Date & Time: "
         << dt << endl;
}
string systemPassword = "1234";

void changePassword()
{
    string oldPassword;
    string newPassword;

    cout << "\nEnter Old Password: ";
    cin >> oldPassword;

    if (oldPassword == systemPassword)
    {
        cout << "Enter New Password: ";
        cin >> newPassword;

        systemPassword = newPassword;

        cout << "\nPassword Changed Successfully!\n";
    }

    else
    {
        cout << "\nWrong Old Password!\n";
    }
}
// ========================================
// MAIN FUNCTION
// ========================================

int main()
{
    int choice;

    if (!login())
    {
        return 0;
    }

    loadFromFile();

    cout << "\n========================================\n";
    cout << "     ADVANCED STUDENT MANAGEMENT\n";
    cout << "========================================\n";

    cout << "Developer : Tanishq Katiyar\n";
    cout << "Language  : C++\n";
    cout << "Features  : File Handling, CGPA,\n";
    cout << "            Statistics, Ranking,\n";
    cout << "            Export Marksheet\n";

    cout << "========================================\n";

    while (true)
    {
        cout << "\n=========== MAIN MENU ===========\n";

        cout << "1.  Add Student\n";
        cout << "2.  Show Students\n";
        cout << "3.  Search Student\n";
        cout << "4.  Delete Student\n";
        cout << "5.  Update Student\n";
        cout << "6.  Search By Name\n";
        cout << "7.  Show Topper\n";
        cout << "8.  Show Ranking\n";
        cout << "9.  Generate Marksheet\n";
        cout << "10. Count Passed Students\n";
        cout << "11. Show Failed Students\n";
        cout << "12. Show Statistics\n";
        cout << "13. Export Marksheet\n";
        cout << "14. Change Password\n";
        cout << "15. Exit\n";

        cout << "=================================\n";

        cout << "Enter Your Choice: ";
        cin >> choice;
if (choice == 1)
{
    addStudent();
}

else if (choice == 2)
{
    showStudents();
}

else if (choice == 3)
{
    searchStudent();
}

else if (choice == 4)
{
    deleteStudent();
}

else if (choice == 5)
{
    updateStudent();
}

else if (choice == 6)
{
    searchStudentByName();
}

else if (choice == 7)
{
    showTopper();
}

else if (choice == 8)
{
    showRankings();
}

else if (choice == 9)
{
    generateMarksheet();
}

else if (choice == 10)
{
    countPassedStudents();
}

else if (choice == 11)
{
    showFailedStudents();
}

else if (choice == 12)
{
    showStatistics();
}

else if (choice == 13)
{
    exportMarksheet();
}

else if (choice == 14)
{
    changePassword();
}

else if (choice == 15)
{
    cout << "\n====================================\n";
    cout << " THANK YOU FOR USING THE SYSTEM\n";
    cout << " Developed By: Tanishq Katiyar\n";
    cout << "====================================\n";

    break;
}

else
{
    cout << "\nInvalid Choice!\n";
}

} 

return 0;

} 