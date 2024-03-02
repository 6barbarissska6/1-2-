#include <iostream>
#include <string>
#include <windows.h>

struct Student {
    std::string fullName;
    char gender;
    int groupNumber;
    int listNumber;
    int examGrades[3];
    int zachetGrades[5];
};
struct Applicant {
    std::string fullName;
    char gender;
    int age;
    std::string city;
    double averageEGEScore;
    bool hasOriginalCertificate;
    double averageCertificateScore;
};
//������� ���������� ����� ����������
void addNewStudent(Student* students, int& numStudents) {
   

    std::cout << "������� ��� ������ ��������: ";
    std::cin >> std::ws;
    std::getline(std::cin, students[numStudents].fullName);

    std::cout << "������� ��� (�/�) ������ ��������: ";
    std::cin >> students[numStudents].gender;

    std::cout << "������� ����� ������ ������ ��������: ";
    std::cin >> students[numStudents].groupNumber;

    std::cout << "������� ����� � ������ ������ ������ ��������: ";
    std::cin >> students[numStudents].listNumber;

    std::cout << "������� ������ �� �������� (3 ������ ����� ������) ������ ��������: ";
    for (int i = 0; i < 3; ++i) {
        std::cin >> students[numStudents].examGrades[i];
    }

    std::cout << "������� ������ �� ������ (5 ������ ����� ������) ������ ��������: ";
    for (int i = 0; i < 5; ++i) {
        std::cin >> students[numStudents].zachetGrades[i];
    }

    ++numStudents;
}

// ������� ��� ��������� ������ � ��������
void updateStudentInfo(Student & student) {
    std::cout << "������� ����� ������ ��� �������� " << student.fullName << ":" << std::endl;

    std::cout << "���: ";
    std::getline(std::cin >> std::ws, student.fullName);

    std::cout << "��� (�/�): ";
    std::cin >> student.gender;

    std::cout << "����� ������: ";
    std::cin >> student.groupNumber;

    std::cout << "����� � ������ ������: ";
    std::cin >> student.listNumber;

    std::cout << "������ �� �������� (3 ������ ����� ������): ";
    for (int i = 0; i < 3; ++i) {
        std::cin >> student.examGrades[i];
    }

    std::cout << "������ �� ������ (5 ������ ����� ������): ";
    for (int i = 0; i < 5; ++i) {
        std::cin >> student.zachetGrades[i];
    }
}

// ������� ������ ���� ���������� � ���������
void printAllStudents(const Student* students, int numStudents) {
    for (int i = 0; i < numStudents; ++i) {
        std::cout << "������� " << i + 1 << ":" << std::endl;
        std::cout << "���: " << students[i].fullName << std::endl;
        std::cout << "���: " << students[i].gender << std::endl;
        std::cout << "����� ������: " << students[i].groupNumber << std::endl;
        std::cout << "����� � ������ ������: " << students[i].listNumber << std::endl;

        std::cout << "������ �� ��������: ";
        for (int j = 0; j < 3; ++j) {
            std::cout << students[i].examGrades[j] << " ";
        }
        std::cout << std::endl;

        std::cout << "������ �� ������: ";
        for (int j = 0; j < 5; ++j) {
            std::cout << students[i].zachetGrades[j] << " ";
        }
        std::cout << std::endl;

        std::cout << std::endl;
    }
}
// ������� ��� ������ ���������� ��� ���� ��������� ������ N
void printStudentsOfGroup(const Student* students, int numStudents, int groupNumber) {
    std::cout << "�������� ������ " << groupNumber << ":" << std::endl;
    for (int i = 0; i < numStudents; ++i) {
        if (students[i].groupNumber == groupNumber) {
            std::cout << "������� " << i + 1 << ":" << std::endl;
            std::cout << "���: " << students[i].fullName << std::endl;
            std::cout << "���: " << students[i].gender << std::endl;
            std::cout << "����� ������: " << students[i].groupNumber << std::endl;
            std::cout << "����� � ������ ������: " << students[i].listNumber << std::endl;
            std::cout << "������ �� ��������: ";
            for (int j = 0; j < 3; ++j) {
                std::cout << students[i].examGrades[j] << " ";
            }
            std::cout << std::endl;
            std::cout << "������ �� ������: ";
            for (int j = 0; j < 5; ++j) {
                std::cout << students[i].zachetGrades[j] << " ";
            }
            std::cout << std::endl;
        }
    }
}
void printTopStudents(const Student* students, int numStudents) {
    struct StudentRating {
        std::string fullName;
        double averageGrade;
    };

    StudentRating* rating = new StudentRating[numStudents];

    // ������������ ������� ������� ��������
    for (int i = 0; i < numStudents; ++i) {
        int totalExamGrades = 0;
        for (int j = 0; j < 3; ++j) {
            totalExamGrades += students[i].examGrades[j];
        }

        int totalZachetGrades = 0;
        for (int j = 0; j < 5; ++j) {
            totalZachetGrades += students[i].zachetGrades[j];
        }

        double averageGrade = (static_cast<double>(totalExamGrades) / 3 + static_cast<double>(totalZachetGrades) / 5) / 2;
        rating[i] = { students[i].fullName, averageGrade };
    }

    // ��������� ������ �������� �� �������� �������� �����
    for (int i = 0; i < numStudents; ++i) {
        for (int j = i + 1; j < numStudents; ++j) {
            if (rating[i].averageGrade < rating[j].averageGrade) {
                std::swap(rating[i], rating[j]);
            }
        }
    }

    // ������� ���-3 ���������
    std::cout << "��� ����� �������� ���������:" << std::endl;
    for (int i = 0; i < numStudents && i < 3; ++i) {
        std::cout << "����� " << i + 1 << ": " << rating[i].fullName << " - ������� ����: " << rating[i].averageGrade << std::endl;
    }
    delete[] rating;
}
// ������� ��� ������ ���������� �������� �������� � �������� ����
void countStudentsByGender(const Student* students, int numStudents) {
    int maleCount = 0;
    int femaleCount = 0;

    for (int i = 0; i < numStudents; ++i) {
        if (students[i].gender == '�' || students[i].gender == '�') {
            ++maleCount;
        }
        else if (students[i].gender == '�' || students[i].gender == '�') {
            ++femaleCount;
        }
    }

    std::cout << "���������� ��������� �������� ����: " << maleCount << std::endl;
    std::cout << "���������� ��������� �������� ����: " << femaleCount << std::endl;
}
// ������� ��� ��� ����� ����� ������
void printStudentsScholarshipStatus(const Student* students, int numStudents) {
    std::cout << "��������, ������� �� �������� ��������� ��-�� ������ 3:" << std::endl;
    for (int i = 0; i < numStudents; ++i) {
        bool scholarshipSuspension = false;
        for (int j = 0; j < 3; ++j) {
            if (students[i].examGrades[j] == 3) {
                scholarshipSuspension = true;
                break;
            }
        }
        if (scholarshipSuspension) {
            std::cout << students[i].fullName << std::endl;
        }
    }

    std::cout << "��������, ������ ������ �� 4 � 5:" << std::endl;
    for (int i = 0; i < numStudents; ++i) {
        bool onlyFourFive = true;
        for (int j = 0; j < 3; ++j) {
            if (students[i].examGrades[j] != 4 && students[i].examGrades[j] != 5) {
                onlyFourFive = false;
                break;
            }
        }
        if (onlyFourFive) {
            std::cout << students[i].fullName << std::endl;
        }
    }

    std::cout << "��������, ������ ������ �� 5:" << std::endl;
    for (int i = 0; i < numStudents; ++i) {
        bool onlyFive = true;
        for (int j = 0; j < 3; ++j) {
            if (students[i].examGrades[j] != 5) {
                onlyFive = false;
                break;
            }
        }
        if (onlyFive) {
            std::cout << students[i].fullName << std::endl;
        }
    }
}
// ������� ������ ���������� � ������� � ������� � ������
void printStudentsByListNumber(Student students[], int numStudents, int k) {
    for (int i = 0; i < numStudents; ++i) {
        if (students[i].listNumber == k) {
            std::cout << "��� " << students[i].listNumber << ": " << students[i].fullName << std::endl;
            std::cout << "��� (�/�): " << students[i].gender << std::endl;
            std::cout << "����� ������: " << students[i].groupNumber << std::endl;
            std::cout << "����� � ������ ������: " << students[i].listNumber << std::endl;
            std::cout << "������ �� ��������: ";
            for (int j = 0; j < 3; ++j) {
                std::cout << students[i].examGrades[j] << " ";
            }
            std::cout << std::endl;
            std::cout << "������ �� ������: ";
            for (int j = 0; j < 5; ++j) {
                std::cout << students[i].zachetGrades[j] << " ";
            }
            std::cout << std::endl << std::endl;
        }
    }
}
int main() 
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int maxStudents = 4;
    Student students[maxStudents];
    int numStudents = 3;

    // ���������� ���������� � ���������
    for (int i = 0; i < numStudents; ++i) {
        std::cout << "������� ��� �������� " << i + 1 << ": ";
        std::getline(std::cin >> std::ws, students[i].fullName);

        std::cout << "������� ��� �������� " << i + 1 << " (�/�): ";
        std::cin >> students[i].gender;

        std::cout << "������� ����� ������ �������� " << i + 1 << ": ";
        std::cin >> students[i].groupNumber;

        std::cout << "������� ����� � ������ ������ �������� " << i + 1 << ": ";
        std::cin >> students[i].listNumber;

        std::cout << "������� ������ �� �������� (3 ������ ����� ������) �������� " << i + 1 << ": ";
        for (int j = 0; j < 3; ++j) {
            std::cin >> students[i].examGrades[j];
        }

        std::cout << "������� ������ �� ������ (5 ������ ����� ������) �������� " << i + 1 << ": ";
        for (int j = 0; j < 5; ++j) {
            std::cin >> students[i].zachetGrades[j];
        }
    }
    int choise;
    while (true) {
        std::cout << "�������� �������:\n" <<
            "1) ������� ����� ������\n" <<
            "2) ������ ��������� � ������\n" <<
            "3) ����� ���� ������\n" <<
            "4) ����� ���������� ��� ���� ��������� ������ N\n" <<
            "5) �������� � ��������� ������\n" <<
            "6) ���������� ��������� �������� � �������� ����\n" <<
            "7) ����� ������ ������������ ���������\n" <<
            "8) ����� ������ � ���������, ������� ����� � ������ � k\n" <<
            "9) ���\n";
        std::cin >> choise;
        switch (choise) {
        case 1:
            addNewStudent(students, numStudents);
            break;
        case 2:
            int studentIndex;
            std::cout << "������� ����� ��������, ���������� � ������� ����� ��������: ";
            std::cin >> studentIndex;

            if (studentIndex >= 1 && studentIndex <= numStudents) {
                updateStudentInfo(students[studentIndex - 1]);
            }
            else {
                std::cout << "�������� � ����� ������� ���." << std::endl;
                break;
        case 3:
            printAllStudents(students, numStudents);
            break;
        case 4:
            int groupNumber;
            std::cout << "������� ����� ������ ��� ������ ���������� � ��������� ���� ������: ";
            std::cin >> groupNumber;

            printStudentsOfGroup(students, numStudents, groupNumber);
            break;
        case 5:
            printTopStudents(students, numStudents);
            break;
        case 6:
            countStudentsByGender(students, numStudents);
            break;
        case 7:
            printStudentsScholarshipStatus(students, numStudents);
            break;
        case 8:
            int k;
            std::cout << "������� ����� � ������ ������ ��� ������ ����������: ";
            std::cin >> k;
            printStudentsByListNumber(students, numStudents, k);
            break;

            }
        case 9:
            Applicant applicant1 = { "������� ���� ��������", '�', 17, "������", 90.5, true, 9.2 };
            Applicant applicant2 = { "������� ���� ����������", '�', 18, "�����-���������", 84.3, false, 9.5 };
            Applicant applicant3 = { "������� ����� ��������", '�', 16, "������", 88.7, true, 9.8 };
            Applicant applicant4 = { "������ ����� �������������", '�', 19, "�����-���������", 87.2, true, 9.7 };
            Applicant applicant5 = { "�������� ����� ���������", '�', 17, "������", 82.4, false, 9.0 };

            // ����������� ������ 18 ���
            std::cout << "����������� ������ 18 ���:\n";
            if (applicant1.age < 18) {
                std::cout << "- " << applicant1.fullName << std::endl;
            }
            if (applicant2.age < 18) {
                std::cout << "- " << applicant2.fullName << std::endl;
            }
            if (applicant3.age < 18) {
                std::cout << "- " << applicant3.fullName << std::endl;
            }
            if (applicant4.age < 18) {
                std::cout << "- " << applicant4.fullName << std::endl;
            }
            if (applicant5.age < 18) {
                std::cout << "- " << applicant5.fullName << std::endl;
            }

            // ����������� � ������� ������ ��� ������ 85
            std::cout << "\n����������� � ������� ������ ��� ������ 85:\n";
            if (applicant1.averageEGEScore > 85) {
                std::cout << "- " << applicant1.fullName << std::endl;
            }
            if (applicant2.averageEGEScore > 85) {
                std::cout << "- " << applicant2.fullName << std::endl;
            }
            if (applicant3.averageEGEScore > 85) {
                std::cout << "- " << applicant3.fullName << std::endl;
            }
            if (applicant4.averageEGEScore > 85) {
                std::cout << "- " << applicant4.fullName << std::endl;
            }
            if (applicant5.averageEGEScore > 85) {
                std::cout << "- " << applicant5.fullName << std::endl;
            }

            // ����������� ����������� (����������� � �����-����������)
            std::cout << "\n����������� ����������� (����������� � �����-����������):\n";
            if (applicant1.city != "�����-���������" && applicant2.city != "���") {
                std::cout << "- " << applicant1.fullName << std::endl;
            }
            if (applicant2.city != "�����-���������" && applicant2.city != "���") {
                std::cout << "- " << applicant2.fullName << std::endl;
            }
            if (applicant3.city != "�����-���������" && applicant2.city != "���") {
                std::cout << "- " << applicant3.fullName << std::endl;
            }
            if (applicant4.city != "�����-���������" && applicant4.city != "���") {
                std::cout << "- " << applicant4.fullName << std::endl;
            }
            if (applicant5.city != "�����-���������" && applicant2.city != "���") {
                std::cout << "- " << applicant5.fullName << std::endl;
            }

            // ����������� � ���������� � ��������
            std::cout << "\n����������� � ���������� � ��������:\n";
            if (applicant1.averageCertificateScore >= 9.5) {
                std::cout << "- " << applicant1.fullName << std::endl;
            }
            if (applicant2.averageCertificateScore >= 9.5) {
                std::cout << "- " << applicant2.fullName << std::endl;
            }
            if (applicant3.averageCertificateScore >= 9.5) {
                std::cout << "- " << applicant3.fullName << std::endl;
            }
            if (applicant4.averageCertificateScore >= 9.5) {
                std::cout << "- " << applicant4.fullName << std::endl;
            }
            if (applicant5.averageCertificateScore >= 9.5) {
                std::cout << "- " << applicant5.fullName << std::endl;
            }
            break;

        
        }
    }
    return 0;
}
