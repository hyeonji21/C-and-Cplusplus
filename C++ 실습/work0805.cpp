#include <iostream>
using namespace std;


class Circle {
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	int getRadius() { return radius; }
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
};

class NamedCircle : public Circle {
	string name;
public:

	NamedCircle(int r = 1, string n = " ") : Circle(r) {
		// radius = r;  사용 x : 왜? radius가 private 상태로 상속되었기 때문에
		// setRadius(r); 사용o : 왜? setRadius가 public 상태로 상속되었기 때문에
		name = n;
	}
	void show() {
		cout << "반지름이 " << getRadius() << "인 " << name << endl;
	}
	void setName(string name) {
		this->name = name;
	}
	string getName() {
		return name;
	}
};

int main() {

	NamedCircle pizza[5];

	cout << "5개의 정수 반지름과 원의 이름을 입력하세요" << endl;

	int inputRadius;
	string inputName;

	for (int i = 0; i < 5; i++) {
		cout << i + 1 << ">> ";
		cin >> inputRadius >> inputName;
		
		pizza[i].setRadius(inputRadius);
		pizza[i].setName(inputName);
	}

	NamedCircle* p = pizza;
	
	for (int i = 1; i < 5; i++) {
		if (p->getRadius() < pizza[i].getRadius()) {
			p = &pizza[i];
		}
	}

	cout << "가장 면적이 큰 피자는 ";
	cout << p->getName();
	cout << "입니다.";


	return 0;
}
