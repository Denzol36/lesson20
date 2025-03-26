#include <iostream>
#include <cstdio>

class Point {
private:
    double x, y, z;
public:
    void setX(double value);
    void setY(double value);
    void setZ(double value);
    double getX();
    double getY();
    double getZ();
    void display();
    void saveToFile(const char* filename);
    void loadFromFile(const char* filename);
};

void Point::setX(double value) {
    x = value;
}

void Point::setY(double value) {
    y = value;
}

void Point::setZ(double value) {
    z = value;
}

double Point::getX(){
    return x;
}

double Point::getY(){
    return y;
}

double Point::getZ(){
    return z;
}

void Point::display(){
    std::cout << "Point coordinates: (" << x << ", " << y << ", " << z << ")\n";
}

void Point::saveToFile(const char* filename){
    FILE* file = fopen(filename, "w");
    if (file) {
        fprintf(file, "%lf %lf %lf", x, y, z);
        fclose(file);
        std::cout << "Data saved to " << filename << "\n";
    } else {
        std::cerr << "Error\n";
    }
}

void Point::loadFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file) {
        fscanf(file, "%lf %lf %lf", &x, &y, &z);
        fclose(file);
        std::cout << "Data loaded from " << filename << "\n";
    } else {
        std::cerr << "Error\n";
    }
}
void inputX(Point& point) {
    double x;
    std::cout << "Enter x: ";
    std::cin >> x;
    point.setX(x);
}

void inputY(Point& point) {
    double y;
    std::cout << "Enter y: ";
    std::cin >> y;
    point.setY(y);
}

void inputZ(Point& point) {
    double z;
    std::cout << "Enter z: ";
    std::cin >> z;
    point.setZ(z);
}

void inputAll(Point& point) {
    inputX(point);
    inputY(point);
    inputZ(point);
}

int main() {
    Point point;
    inputAll(point);
    point.display();
    point.saveToFile("point_data.txt");
    point.loadFromFile("point_data.txt");
    point.display();
}
