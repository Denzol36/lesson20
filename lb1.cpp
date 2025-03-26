#include <iostream>
#include <cstdio>

class Student {
private:
    char fullName[100];
    char birthDate[20];
    char phoneNumber[20];
    char city[50];
    char country[50];
    char university[100];
    char universityCity[50];
    char universityCountry[50];
    char groupNumber[20];

    void inputField(const char* prompt, char* userInfo, size_t size) {
        std::cout << prompt;
        fgets(userInfo, size, stdin);
    }

public:
    void inputFullName() { 
        inputField("Enter full name: ", fullName, sizeof(fullName)); 
    }
    void inputBirthDate() { 
        inputField("Enter birth date: ", birthDate, sizeof(birthDate)); 
    }
    void inputPhoneNumber() { 
        inputField("Enter phone number: ", phoneNumber, sizeof(phoneNumber)); 
    }
    void inputCity() { 
        inputField("Enter city: ", city, sizeof(city)); 
    }
    void inputCountry() { 
        inputField("Enter country: ", country, sizeof(country)); 
    }
    void inputUniversity() { 
        inputField("Enter university name: ", university, sizeof(university)); 
    }
    void inputUniversityCity() { 
        inputField("Enter university city: ", universityCity, sizeof(universityCity)); 
    }
    void inputUniversityCountry() { 
        inputField("Enter university country: ", universityCountry, sizeof(universityCountry)); 
    }
    void inputGroupNumber() { 
        inputField("Enter group number: ", groupNumber, sizeof(groupNumber)); 
    }

    void inputAllData() {
        inputFullName();
        inputBirthDate();
        inputPhoneNumber();
        inputCity();
        inputCountry();
        inputUniversity();
        inputUniversityCity();
        inputUniversityCountry();
        inputGroupNumber();
    }

    void showData(){
        std::cout << "\nStudent Information:" << std::endl;
        std::cout << "Full Name: " << fullName << std::endl;
        std::cout << "Birth Date: " << birthDate << std::endl;
        std::cout << "Phone Number: " << phoneNumber << std::endl;
        std::cout << "City: " << city << std::endl;
        std::cout << "Country: " << country << std::endl;
        std::cout << "University: " << university << std::endl;
        std::cout << "University City: " << universityCity << std::endl;
        std::cout << "University Country: " << universityCountry << std::endl;
        std::cout << "Group Number: " << groupNumber << std::endl;
    }
};

int main() {
    Student student;
    student.inputAllData();
    student.showData();
}