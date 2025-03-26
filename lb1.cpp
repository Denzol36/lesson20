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

public:
    void setFullName(const char* name){ 
        strncpy(fullName, name, sizeof(fullName) - 1); 
    }
    void setBirthDate(const char* date){ 
        strncpy(birthDate, date, sizeof(birthDate) - 1); 
    }
    void setPhoneNumber(const char* phone){ 
        strncpy(phoneNumber, phone, sizeof(phoneNumber) - 1); }
    void setCity(const char* cityName){ strncpy(city, cityName, sizeof(city) - 1); 
    }
    void setCountry(const char* countryName){ 
        strncpy(country, countryName, sizeof(country) - 1); 
    }
    void setUniversity(const char* uni){ 
        strncpy(university, uni, sizeof(university) - 1); 
    }
    void setUniversityCity(const char* uniCity){ 
        strncpy(universityCity, uniCity, sizeof(universityCity) - 1); 
    }
    void setUniversityCountry(const char* uniCountry){ 
        strncpy(universityCountry, uniCountry, sizeof(universityCountry) - 1); 
    }
    void setGroupNumber(const char* group){ 
        strncpy(groupNumber, group, sizeof(groupNumber) - 1); 
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

void inputField(const char* prompt, char* userInfo, size_t size) {
    std::cout << prompt;
    fgets(userInfo, size, stdin);
}

void inputAllData(Student &student) {
    char temp[100];
    inputField("Enter full name: ", temp, sizeof(temp));
    student.setFullName(temp);
    
    inputField("Enter birth date: ", temp, sizeof(temp));
    student.setBirthDate(temp);

    inputField("Enter phone number: ", temp, sizeof(temp));
    student.setPhoneNumber(temp);

    inputField("Enter city: ", temp, sizeof(temp));
    student.setCity(temp);

    inputField("Enter country: ", temp, sizeof(temp));
    student.setCountry(temp);

    inputField("Enter university name: ", temp, sizeof(temp));
    student.setUniversity(temp);

    inputField("Enter university city: ", temp, sizeof(temp));
    student.setUniversityCity(temp);

    inputField("Enter university country: ", temp, sizeof(temp));
    student.setUniversityCountry(temp);

    inputField("Enter group number: ", temp, sizeof(temp));
    student.setGroupNumber(temp);
}

int main() {
    Student student;
    inputAllData(student);
    student.showData();
}
