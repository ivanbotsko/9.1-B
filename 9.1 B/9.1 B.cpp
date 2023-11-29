#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <Windows.h>

using namespace std;

enum Specialty { ComputerScience, Informatics, MathematicsAndEconomics, PhysicsAndInformatics, LaborEducation };
enum ThirdSubject { Programming, NumericalMethods, Pedagogy };

struct ThirdSubjectGrade {
    ThirdSubject subject;
    int grade;
};

struct Student {
    string surname;
    int course;
    Specialty specialty;
    int physics;
    int math;
    ThirdSubjectGrade thirdSubject;
};

Specialty getRandomSpecialty() {
    return static_cast<Specialty>(rand() % 5);
}

ThirdSubjectGrade getRandomThirdSubjectGrade(Specialty specialty) {
    ThirdSubjectGrade thirdSubject;
    switch (specialty) {
    case ComputerScience:
        thirdSubject = { Programming, rand() % 3 + 3 }; // Generating grade for Programming subject (range: 3-5)
        break;
    case Informatics:
        thirdSubject = { NumericalMethods, rand() % 3 + 3 }; // Generating grade for NumericalMethods subject (range: 3-5)
        break;
    default:
        thirdSubject = { Pedagogy, rand() % 3 + 3 }; // Generating grade for Pedagogy subject (range: 3-5)
        break;
    }
    return thirdSubject;
}

string getRandomSurname() {
    string surnames[] = { "Іванов", "Петров", "Сидоров", "Козлов", "Смірнов" };
    return surnames[rand() % 5];
}

int getRandomInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void createStudents(Student* students, int numStudents) {
    for (int i = 0; i < numStudents; ++i) {
        Specialty specialty = getRandomSpecialty();
        students[i].surname = getRandomSurname();
        students[i].course = getRandomInt(1, 4);
        students[i].specialty = specialty;
        students[i].physics = getRandomInt(3, 5);
        students[i].math = getRandomInt(3, 5);
        students[i].thirdSubject = getRandomThirdSubjectGrade(specialty);
    }
}

bool isExcellentGrade(ThirdSubjectGrade grade) {
    return grade.grade == 5;
}

int calculateExcellentStudents(Student* students, int numStudents) {
    int count = 0;
    for (int i = 0; i < numStudents; ++i) {
        if (students[i].physics == 5 && students[i].math == 5 && isExcellentGrade(students[i].thirdSubject)) {
            ++count;
        }
    }
    return count;
}

double calculatePhysicsGradePercentage(Student* students, int numStudents, int grade) {
    int count = 0;
    for (int i = 0; i < numStudents; ++i) {
        if (students[i].physics == grade) {
            ++count;
        }
    }
    return (static_cast<double>(count) / numStudents) * 100;
}

void displayStudents(Student* students, int numStudents) {
    cout << "==============================================================================================================================================\n";
    cout << "№\tПрізвище\t\tКурс\tСпеціальність\t\t\t\tФізика\tМатематика\tПрограмування\tЧисельні методи\tПедагогіка\n";
    for (int i = 0; i < numStudents; ++i) {
        cout << i + 1 << "\t" << setw(15) << students[i].surname << "\t" << setw(5) << students[i].course << "\t";
        switch (students[i].specialty) {
        case ComputerScience:
            cout << setw(25) << "ComputerScience";
            break;
        case Informatics:
            cout << setw(25) << "Informatics";
            break;
        case MathematicsAndEconomics:
            cout << setw(25) << "MathematicsAndEconomics";
            break;
        case PhysicsAndInformatics:
            cout << setw(25) << "PhysicsAndInformatics";
            break;
        case LaborEducation:
            cout << setw(25) << "LaborEducation";
            break;
        }
        cout << "\t" << setw(8) << students[i].physics << "\t" << setw(10) << students[i].math << "\t";
        switch (students[i].specialty) {
        case ComputerScience:
        case Informatics:
            cout << setw(15) << students[i].thirdSubject.grade << "\t\t\t";
            break;
        default:
            cout << "\t\t\t" << setw(15) << students[i].thirdSubject.grade << "\t";
            break;
        }
        cout << endl;
    }
}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand(static_cast<unsigned>(time(0)));

    int numberOfStudents;
    cout << "Number of students: ";
    cin >> numberOfStudents;

    Student* students = new Student[numberOfStudents];
    createStudents(students, numberOfStudents);

    int excellentStudents = calculateExcellentStudents(students, numberOfStudents);
    double physicsGradePercentage = calculatePhysicsGradePercentage(students, numberOfStudents, 5);

    cout << "Кількість студентів, які вчаться на \"відмінно\": " << excellentStudents << endl;
    cout << "Відсоток студентів, які отримали з фізики оцінку \"5\": " << fixed << setprecision(2) << physicsGradePercentage << "%" << endl;
    displayStudents(students, numberOfStudents);

    delete[] students;

    return 0;
}
