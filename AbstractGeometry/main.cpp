#include<Windows.h>
#include<iostream>
using namespace std;

namespace Geometry
{
	enum Color
	{
		console_default = 0x07,
		console_blue = 0x99,
		console_green = 0xAA,
		console_green1 = 0x0A,
		console_red = 0xCC,
		console_yellow = 0xEE,
		console_white = 0xFF
	};

	class Shape
	{
	protected:
		Color color;
	public:
		Shape(Color color) :color(color) {}
		virtual ~Shape() {}

		virtual double get_area()const = 0;			//������� ������
		virtual double get_perimeter()const = 0;	//�������� ������
		virtual void draw()const = 0;				//����� ������ ����� ����������
	};

	class Square :public Shape
	{
		double side;
	public:
		double get_side()const
		{
			return side;
		}
		void set_side(double side)
		{
			if (side <= 0)side = 1;
			this->side = side;
		}
		Square(double side, Color color) :Shape(color)
		{
			set_side(side);
		}
		~Square() {}

		double get_area()const
		{
			return side * side;
		}

		double get_perimeter()const
		{
			return side * 4;
		}

		void draw()const
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, color);
			for (int i = 0; i < side; i++)
			{
				for (int i = 0; i < side; i++)
				{
					cout << "* ";
				}
				cout << endl;
			}
			SetConsoleTextAttribute(hConsole, Color::console_default);
		}

		void info()
		{
			cout << typeid(*this).name() << endl;
			cout << "����� �������:\t" << side << endl;
			cout << "�������:\t" << get_area() << endl;
			cout << "��������:\t" << get_perimeter() << endl;
			draw();
		}
	};

	class Rectangle :public Shape
	{
		double side_A;
		double side_B;
	public:
		double get_side_A()const
		{
			return side_A;
		}
		double get_side_B()const
		{
			return side_B;
		}
		void set_side_A(double side_A)
		{
			if (side_A <= 0)side_A = 1;
			this->side_A = side_A;
		}
		void set_side_B(double side_B)
		{
			if (side_B <= 0)side_B = 1;
			this->side_B = side_B;
		}
		Rectangle(double side_A, double side_B, Color color) :Shape(color)
		{
			set_side_A(side_A);
			set_side_B(side_B);
		}
		~Rectangle() {}

		double get_area()const
		{
			return side_A * side_B;
		}
		double get_perimeter()const
		{
			return (side_A + side_B) * 2;
		}
		void draw()const
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, color);
			for (int i = 0; i < side_A; i++)
			{
				for (int j = 0; j < side_B; j++)
				{
					cout << "* ";
				}
				cout << endl;
			}
			SetConsoleTextAttribute(hConsole, Color::console_default);
		}
		void info()
		{
			cout << typeid(*this).name() << endl;
			cout << "����� ������� A:\t" << side_A << endl;
			cout << "����� ������� B:\t" << side_B << endl;
			cout << "�������:\t" << get_area() << endl;
			cout << "��������:\t" << get_perimeter() << endl;
			draw();
		}
	};

	class Circle :public Shape
	{
		double radius;
	public:
		double get_radius()const
		{
			return radius;
		}
		void set_radius(double radius)
		{
			if (radius <= 0)radius = 1;
			this->radius = radius;
		}
		Circle(double radius, Color color) :Shape(color)
		{
			set_radius(radius);
		}
		~Circle() {}

		double get_area()const
		{
			return 3.15*pow(radius,2);
		}
		double get_perimeter()const
		{
			return 2*3.15*radius;
		}
		void draw()const
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, color);
			cout << "����� ������ ���� ���� :-)";
			SetConsoleTextAttribute(hConsole, Color::console_default);
		}
		void info()
		{
			cout << typeid(*this).name() << endl;
			cout << "������ �����:\t" << radius << endl;
			cout << "�������:\t" << get_area() << endl;
			cout << "��������:\t" << get_perimeter() << endl;
			draw();
		}
	};
}

void main()
{
	setlocale(LC_ALL, "");
	
	//Shape shape(Color::consol_blue);

	Geometry::Square square(8, Geometry::Color::console_blue);
	square.info();

	Geometry::Rectangle rect(5, 12, Geometry::Color::console_red);
	rect.info();

	Geometry::Circle cir(5, Geometry::Color::console_green1);
	cir.info();
}

/*
	enum (Enumeration ��� ������������) - ����� ����������� �������� ���� 'int'

*/