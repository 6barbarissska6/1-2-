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
//Функция добавления новой информейшн
void addNewStudent(Student* students, int& numStudents) {
   

    std::cout << "Введите ФИО нового студента: ";
    std::cin >> std::ws;
    std::getline(std::cin, students[numStudents].fullName);

    std::cout << "Введите пол (м/ж) нового студента: ";
    std::cin >> students[numStudents].gender;

    std::cout << "Введите номер группы нового студента: ";
    std::cin >> students[numStudents].groupNumber;

    std::cout << "Введите номер в списке группы нового студента: ";
    std::cin >> students[numStudents].listNumber;

    std::cout << "Введите оценки за экзамены (3 оценки через пробел) нового студента: ";
    for (int i = 0; i < 3; ++i) {
        std::cin >> students[numStudents].examGrades[i];
    }

    std::cout << "Введите оценки за зачеты (5 оценок через пробел) нового студента: ";
    for (int i = 0; i < 5; ++i) {
        std::cin >> students[numStudents].zachetGrades[i];
    }

    ++numStudents;
}

// Функция для изменения записи о студенте
void updateStudentInfo(Student & student) {
    std::cout << "Введите новые данные для студента " << student.fullName << ":" << std::endl;

    std::cout << "ФИО: ";
    std::getline(std::cin >> std::ws, student.fullName);

    std::cout << "Пол (м/ж): ";
    std::cin >> student.gender;

    std::cout << "Номер группы: ";
    std::cin >> student.groupNumber;

    std::cout << "Номер в списке группы: ";
    std::cin >> student.listNumber;

    std::cout << "Оценки за экзамены (3 оценки через пробел): ";
    for (int i = 0; i < 3; ++i) {
        std::cin >> student.examGrades[i];
    }

    std::cout << "Оценки за зачеты (5 оценок через пробел): ";
    for (int i = 0; i < 5; ++i) {
        std::cin >> student.zachetGrades[i];
    }
}

// Функция вывода всей информации о студентах
void printAllStudents(const Student* students, int numStudents) {
    for (int i = 0; i < numStudents; ++i) {
        std::cout << "Студент " << i + 1 << ":" << std::endl;
        std::cout << "ФИО: " << students[i].fullName << std::endl;
        std::cout << "Пол: " << students[i].gender << std::endl;
        std::cout << "Номер группы: " << students[i].groupNumber << std::endl;
        std::cout << "Номер в списке группы: " << students[i].listNumber << std::endl;

        std::cout << "Оценки за экзамены: ";
        for (int j = 0; j < 3; ++j) {
            std::cout << students[i].examGrades[j] << " ";
        }
        std::cout << std::endl;

        std::cout << "Оценки за зачеты: ";
        for (int j = 0; j < 5; ++j) {
            std::cout << students[i].zachetGrades[j] << " ";
        }
        std::cout << std::endl;

        std::cout << std::endl;
    }
}
// Функция для вывода информации обо всех студентах группы N
void printStudentsOfGroup(const Student* students, int numStudents, int groupNumber) {
    std::cout << "Студенты группы " << groupNumber << ":" << std::endl;
    for (int i = 0; i < numStudents; ++i) {
        if (students[i].groupNumber == groupNumber) {
            std::cout << "Студент " << i + 1 << ":" << std::endl;
            std::cout << "ФИО: " << students[i].fullName << std::endl;
            std::cout << "Пол: " << students[i].gender << std::endl;
            std::cout << "Номер группы: " << students[i].groupNumber << std::endl;
            std::cout << "Номер в списке группы: " << students[i].listNumber << std::endl;
            std::cout << "Оценки за экзамены: ";
            for (int j = 0; j < 3; ++j) {
                std::cout << students[i].examGrades[j] << " ";
            }
            std::cout << std::endl;
            std::cout << "Оценки за зачеты: ";
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

    // Рассчитываем рейтинг каждого студента
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

    // Сортируем массив рейтинга по убыванию среднего балла
    for (int i = 0; i < numStudents; ++i) {
        for (int j = i + 1; j < numStudents; ++j) {
            if (rating[i].averageGrade < rating[j].averageGrade) {
                std::swap(rating[i], rating[j]);
            }
        }
    }

    // Выводим топ-3 студентов
    std::cout << "Топ самых успешных студентов:" << std::endl;
    for (int i = 0; i < numStudents && i < 3; ++i) {
        std::cout << "Место " << i + 1 << ": " << rating[i].fullName << " - Средний балл: " << rating[i].averageGrade << std::endl;
    }
    delete[] rating;
}
// Функция для вывода количества студенов мужского и женского пола
void countStudentsByGender(const Student* students, int numStudents) {
    int maleCount = 0;
    int femaleCount = 0;

    for (int i = 0; i < numStudents; ++i) {
        if (students[i].gender == 'м' || students[i].gender == 'М') {
            ++maleCount;
        }
        else if (students[i].gender == 'ж' || students[i].gender == 'Ж') {
            ++femaleCount;
        }
    }

    std::cout << "Количество студентов мужского пола: " << maleCount << std::endl;
    std::cout << "Количество студентов женского пола: " << femaleCount << std::endl;
}
// Функция кто как выжил после сессии
void printStudentsScholarshipStatus(const Student* students, int numStudents) {
    std::cout << "Студенты, которые не получают стипендию из-за оценок 3:" << std::endl;
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

    std::cout << "Студенты, учатся только на 4 и 5:" << std::endl;
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

    std::cout << "Студенты, учатся только на 5:" << std::endl;
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
// Функция вывода информации о чуваках с номером в списке
void printStudentsByListNumber(Student students[], int numStudents, int k) {
    for (int i = 0; i < numStudents; ++i) {
        if (students[i].listNumber == k) {
            std::cout << "ФИО " << students[i].listNumber << ": " << students[i].fullName << std::endl;
            std::cout << "Пол (м/ж): " << students[i].gender << std::endl;
            std::cout << "Номер группы: " << students[i].groupNumber << std::endl;
            std::cout << "Номер в списке группы: " << students[i].listNumber << std::endl;
            std::cout << "Оценки за экзамены: ";
            for (int j = 0; j < 3; ++j) {
                std::cout << students[i].examGrades[j] << " ";
            }
            std::cout << std::endl;
            std::cout << "оценки за зачеты: ";
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

    // Заполнение информации о студентах
    for (int i = 0; i < numStudents; ++i) {
        std::cout << "Введите ФИО студента " << i + 1 << ": ";
        std::getline(std::cin >> std::ws, students[i].fullName);

        std::cout << "Введите пол студента " << i + 1 << " (м/ж): ";
        std::cin >> students[i].gender;

        std::cout << "Введите номер группы студента " << i + 1 << ": ";
        std::cin >> students[i].groupNumber;

        std::cout << "Введите номер в списке группы студента " << i + 1 << ": ";
        std::cin >> students[i].listNumber;

        std::cout << "Введите оценки за экзамены (3 оценки через пробел) студента " << i + 1 << ": ";
        for (int j = 0; j < 3; ++j) {
            std::cin >> students[i].examGrades[j];
        }

        std::cout << "Введите оценки за зачеты (5 оценок через пробел) студента " << i + 1 << ": ";
        for (int j = 0; j < 5; ++j) {
            std::cin >> students[i].zachetGrades[j];
        }
    }
    int choise;
    while (true) {
        std::cout << "Выберете задание:\n" <<
            "1) Создать новую запись\n" <<
            "2) Внести изменения в запись\n" <<
            "3) Вывод всех данных\n" <<
            "4) Вывод информации обо всех студентах группы N\n" <<
            "5) Студенты с наивысшим баллом\n" <<
            "6) Количество студентов мужского и женского пола\n" <<
            "7) Вывод данных успеваемости студентов\n" <<
            "8) Вывод данных о студентах, имеющих номер в списке – k\n" <<
            "9) ИДЗ\n";
        std::cin >> choise;
        switch (choise) {
        case 1:
            addNewStudent(students, numStudents);
            break;
        case 2:
            int studentIndex;
            std::cout << "Введите номер студента, информацию о котором нужно изменить: ";
            std::cin >> studentIndex;

            if (studentIndex >= 1 && studentIndex <= numStudents) {
                updateStudentInfo(students[studentIndex - 1]);
            }
            else {
                std::cout << "Студента с таким номером нет." << std::endl;
                break;
        case 3:
            printAllStudents(students, numStudents);
            break;
        case 4:
            int groupNumber;
            std::cout << "Введите номер группы для вывода информации о студентах этой группы: ";
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
            std::cout << "Введите номер в списке группы для вывода информации: ";
            std::cin >> k;
            printStudentsByListNumber(students, numStudents, k);
            break;

            }
        case 9:
            Applicant applicant1 = { "Иванова Анна Петровна", 'Ж', 17, "Москва", 90.5, true, 9.2 };
            Applicant applicant2 = { "Сидоров Иван Васильевич", 'М', 18, "Санкт-Петербург", 84.3, false, 9.5 };
            Applicant applicant3 = { "Петрова Мария Игоревна", 'Ж', 16, "Казань", 88.7, true, 9.8 };
            Applicant applicant4 = { "Козлов Павел Александрович", 'М', 19, "Санкт-Петербург", 87.2, true, 9.7 };
            Applicant applicant5 = { "Николаев Артем Сергеевич", 'М', 17, "Москва", 82.4, false, 9.0 };

            // Абитуриенты младше 18 лет
            std::cout << "Абитуриенты младше 18 лет:\n";
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

            // Абитуриенты с средним баллом ЕГЭ больше 85
            std::cout << "\nАбитуриенты с средним баллом ЕГЭ больше 85:\n";
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

            // Иногородние абитуриенты (университет в Санкт-Петербурге)
            std::cout << "\nИногородние абитуриенты (университет в Санкт-Петербурге):\n";
            if (applicant1.city != "Санкт-Петербург" && applicant2.city != "СПб") {
                std::cout << "- " << applicant1.fullName << std::endl;
            }
            if (applicant2.city != "Санкт-Петербург" && applicant2.city != "СПб") {
                std::cout << "- " << applicant2.fullName << std::endl;
            }
            if (applicant3.city != "Санкт-Петербург" && applicant2.city != "СПб") {
                std::cout << "- " << applicant3.fullName << std::endl;
            }
            if (applicant4.city != "Санкт-Петербург" && applicant4.city != "СПб") {
                std::cout << "- " << applicant4.fullName << std::endl;
            }
            if (applicant5.city != "Санкт-Петербург" && applicant2.city != "СПб") {
                std::cout << "- " << applicant5.fullName << std::endl;
            }

            // Абитуриенты с аттестатом с отличием
            std::cout << "\nАбитуриенты с аттестатом с отличием:\n";
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
