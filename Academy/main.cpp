#include<iostream>
#include<string>
#include<ctime>
using std::cin;
using std::cout;
using std::endl;

#define HUMAN_TAKE_PARAMETERS const std::string& last_name, const std::string& first_name, unsigned int age
#define HUMAN_GIVE_PARAMETERS last_name, first_name, age
class Human
{
	std::string last_name;
	std::string first_name;
	unsigned int age;

public:
	const std::string& get_last_name()const
	{
		return last_name;
	}
	const std::string& get_first_name()const
	{
		return first_name;
	}
	unsigned int get_age()const
	{
		return age;
	}
	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(unsigned int age)
	{
		this->age = age;
	}
	//								Constructors:
	Human(const std::string& last_name, const std::string& first_name, unsigned int age)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
#ifdef DEBUG
		cout << "HConstructor:\t" << this << endl;
#endif // DEBUG

	}
	virtual ~Human()
	{
#ifdef DEBUG
		cout << "HDestructor:\t" << this << endl;
#endif // DEBUG

	}

	//								Nethods:
	virtual void print()const
	{
		cout << last_name << " " << first_name << " " << age << endl;
	}
};

std::ostream& operator<<(std::ostream& os, const Human& obj)
{
	return os << obj.get_last_name() + " " + obj.get_first_name() << " " << obj.get_age();
}

#define STUDENT_TAKE_PARAMETERS const std::string& speciality, const std::string& group, double rating, double attendance
#define STUDENT_GIVE_PARAMETERS speciality, group, rating, attendance
class Student :public Human
{
	std::string speciality;
	std::string group;
	double rating;				//������������
	double attendance;			//������������
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	const std::string& get_group()const
	{
		return group;
	}
	double get_rating()const
	{
		return rating;
	}
	double get_attendance()const
	{
		return attendance;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_group(const std::string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating;
	}
	void set_attendance(double attendance)
	{
		this->attendance = attendance;
	}
	//										Constructors:
	Student(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS) :Human(HUMAN_GIVE_PARAMETERS)
	{
		this->speciality = speciality;
		this->group = group;
		this->rating = rating;
		this->attendance = attendance;
#ifdef DEBUG
		cout << "SConstructor:\t" << this << endl;
#endif // DEBUG

	}
	~Student()
	{
#ifdef DEBUG
		cout << "SDestructor:\t" << this << endl;
#endif // DEBUG

	}

	//										Methods:
	void print()const
	{
		Human::print();
		cout << speciality + " " + group << " " << rating << " " << attendance << endl;
	}
};
std::ostream& operator<<(std::ostream& os, const Student& obj)
{
	os << (Human)obj;
	return os << " " << obj.get_speciality() + " " + obj.get_group() << " " << obj.get_rating() << " " << obj.get_attendance();
}

#define TEACHER_TAKE_PARAMETERS const std::string& speciality, unsigned experience
#define TEACHER_GIVA_PARAMETERS speciality, experience
class Teacher :public Human
{
	std::string speciality;
	unsigned int experience;
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	unsigned int get_experience()const
	{
		return experience;
	}
	void set_speciality(const std::string speciality)
	{
		this->speciality = speciality;
	}
	void set_experience(unsigned int experience)
	{
		this->experience = experience;
	}
	Teacher(HUMAN_TAKE_PARAMETERS, TEACHER_TAKE_PARAMETERS) :Human(HUMAN_GIVE_PARAMETERS)
	{
		set_speciality(speciality);
		set_experience(experience);
#ifdef DEBUG
		cout << "TConstructor:\t" << this << endl;
#endif // DEBUG

	}
	~Teacher()
	{
#ifdef DEBUG
		cout << "TDestructor:\t" << this << endl;
#endif // DEBUG

	}

	//											Methods:
	void print()const
	{
		Human::print();
		cout << speciality << " " << experience << endl;
	}
};
std::ostream& operator<<(std::ostream& os, Teacher& obj)
{
	os << (Human)obj;
	return os << " " << obj.get_speciality() << " " << obj.get_experience();
}

class Graduate :public Student
{
	std::string subject;		//���� ���������� �������
public:
	const std::string& get_subject()const
	{
		return subject;
	}
	void set_subject(const std::string& subject)
	{
		this->subject = subject;
	}
	//							Constructors:
	Graduate(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS, const std::string& subject) :Student(HUMAN_GIVE_PARAMETERS, STUDENT_GIVE_PARAMETERS)
	{
		set_subject(subject);
#ifdef DEBUG
		cout << "GConstructor:\t" << this << endl;
#endif // DEBUG

	}
	~Graduate()
	{
#ifdef DEBUG
		cout << "GDestructor:\t" << this << endl;
#endif // DEBUG

	}

	//							Methods
	void print()const
	{
		Student::print();
		cout << subject << endl;
	}
};
std::ostream& operator<<(std::ostream& os, const Graduate& obj)
{
	os << (Student)obj;
	return os << " " << obj.get_subject();
}

//#define INHERITANCE_CHECK

void main()
{
	setlocale(LC_ALL, "");

#ifdef INHERITANCE_CHECK
	Human hm("�������", "�������", 18);
	hm.print();
	Student st("Pinkman", "Jessie", 28, "Chemistry", "WW_01", 90, 85);
	st.print();
	Teacher t("White", "Walter", 50, "Chemistri", 20);
	t.print();
	Graduate gr("Shrader", "Hank", 40, "Criminalistic", "OBN", 90, 90, "How to catch Heisenberg");
	gr.print();
#endif // INHERITANCE_CHECK

	//Generalisation(���������):
	//Upcast - �������������� ��������� ������� � ������� �����
	Human* group[] =
	{
		new Student("Pinkman","Jessie",25,"Chemistry","WW_011",90,80),
		new Student("Vercetti","Tomas",30,"City business","Vice",88,90),
		new Teacher("White","Walter",50,"Chemestry",20),
		new Student("Diaz","Ricardo",55,"Weapons distribution","Vice",91,80),
		new Graduate("Shrader","Hank",40,"Criminalistics","OBN",85,90,"How to catch Heisenberg"),
		new Teacher("Einsten","Albert",142,"Astronomy",110)
	};

	//Spealisation:
	cout << "\n-------------------------------------------------------\n";
	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		//group[i]->print();

		//Downcast -  �� �������� � ��������

		cout << typeid(*group[i]).name() << endl;
		if (typeid(*group[i]) == typeid(Student)) cout << *dynamic_cast<Student*>(group[i]) << endl;
		if (typeid(*group[i]) == typeid(Graduate)) cout << *dynamic_cast<Graduate*>(group[i]) << endl;
		if (typeid(*group[i]) == typeid(Teacher)) cout << *dynamic_cast<Teacher*>(group[i]) << endl;
		cout << "\n-------------------------------------------------------\n";
	}

	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		delete group[i];
	}
}

/*
	�� ����� ��� ������� ����� ��������� ������ ������ � ������� �� � ��������� ����� �������� ������ ��������� �������� �������� ������ � ��������� �� ������ ������������ ����������.
	��� �������� �������� ��������� ������ ������� ��������� ������ �������� ������ � ����� �� ������������ ���������� ��������� ������.���� �� ����� ������ ������ �������� ������ ������ ��������� ������ ������� ����������
	��� ���� ����� ������� ������ �������� ������ ��� �������� ��������� ������ ����������� ��������� ������ ������ ������� ����������� �������� ������ � �������� � ���� ���������
*/