//
//  main.cpp
//  28_Inheritance_Practice_2
//
//  Created by 세광 on 2021/07/23.
//

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const double PI = 3.141592653589793;

class Shape {
public:
    virtual ~Shape() {}
    virtual double GetArea() const = 0;
    virtual void Resize(double factor) = 0;
    virtual string GetInfo() const {
        return "도형의 넓이: " + to_string(GetArea());
    }
};

class Circle : public Shape {
public:
    Circle(double r) : r(r) {}

    double GetArea() const {
        return r * r * PI;
    }
    void Resize(double factor) {
        r *= factor;
    }

private:
    double r;
};

class Rectangle : public Shape {
public:
    Rectangle(double a, double b) : a(a), b(b) {}

    double GetArea() const {
        return a * b;
    }
    void Resize(double factor) {
        a *= factor;
        b *= factor;
    }
    string GetInfo() const {
        return Shape::GetInfo() + "\n대각선의 길이: " + to_string(GetDiag());
    }

    double GetDiag() const {
        return sqrt(a * a + b * b);
    }

private:
    double a, b;
};

int main() {
    Shape *shapes[] = { new Circle(1), new Rectangle(1, 2) };

    // dynamic_cast를 사용하지 않고 오버라이딩을 이용
    // 도형의 정보를 가져오는 역할을 main에서 하는 것이 아닌 class에서 수행
    // 이와 같은 형식으로 구현할 경우 main 함수 안에서 s가 어떤 객체를 가리키고 있는지 알 필요가 없음 (추상 클래스를 사용하는 이유)
    for (Shape *s : shapes) cout << s->GetInfo() << endl;
    
    for (Shape *s : shapes) delete s;
}
