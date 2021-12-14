#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
#include<iomanip>
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
	virtual std::ostream& print(std::ostream& os)const
	{
		/*return os << last_name << " " << first_name << " " << age;*/
		/*os.width(15);			//������ ������ ���������� ����
		os << std::left;		//������ ������������ ���������� ����
		os << last_name;
		os.width(10);
		os << std::left;
		os << first_name;
		os.width(5);
		os << std::right;
		os << age;
		return os;*/
		return os
			<< std::setw(15) << std::left << last_name
			<< std::setw(10) << std::left << first_name
			<< std::setw(5) << std::right << age;
	}
	virtual std::ofstream& print(std::ofstream& os)const
	{
		os
			<< std::setw(15) << std::left << last_name + ","
			<< std::setw(10) << std::left << first_name + ","
			<< std::setw(5) << std::right << age;
		return os;
	}
	virtual std::ifstream& input(std::ifstream& is)
	{
		std::getline(is, last_name, ',');
		std::getline(is, first_name, ',');
		std::string age_buffer;
		std::getline(is, age_buffer, ',');
		age = std::stoi(age_buffer);
		return is;
	}
};
std::ostream& operator<<(std::ostream& os, const Human& obj)
{
	return obj.print(os);
}
std::ofstream& operator<<(std::ofstream& os, const Human& obj)
{
	return obj.print(os);
}
std::ifstream& operator>>(std::ifstream& is, Human& obj)
{
	return obj.input(is);
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
	std::ostream& print(std::ostream& os)const
	{
		//return Human::print(os) << " " << speciality + " " + group << " " << rating << " " << attendance;
		return Human::print(os) << " "
			<< std::setw(25) << std::left << speciality
			<< std::setw(10) << std::left << group
			<< std::setw(5) << std::right << rating
			<< std::setw(5) << std::right << attendance;
	}
	std::ofstream& print(std::ofstream& os)const
	{
		//return Human::print(os) << " " << speciality + " " + group << " " << rating << " " << attendance;
		Human::print(os) << ","
			<< std::setw(25) << std::left << speciality + ","
			<< std::setw(10) << std::left << group + ","
			<< std::setw(5) << std::right << rating << ","
			<< std::setw(5) << std::right << attendance;
		return os;
	}
	std::ifstream& input(std::ifstream& is)
	{
		Human::input(is);
		std::getline(is, speciality, ',');
		std::getline(is, group, ',');
		is >> rating;
		is.ignore();
		is >> attendance;
		return is;
	}
};

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
	std::ostream& print(std::ostream& os)const
	{
		//return Human::print(os) << " " << speciality << " " << experience;
		return Human::print(os) << " "
			<< std::setw(35) << std::left << speciality
			<< std::setw(5) << std::right << experience;
	}
	std::ofstream& print(std::ofstream& os)const
	{
		//return Human::print(os) << " " << speciality << " " << experience;
		Human::print(os) << ","
			<< std::setw(35) << std::left << speciality + ","
			<< std::setw(5) << std::right << experience;
		return os;
	}
	std::ifstream& input(std::ifstream& is)
	{
		Human::input(is);
		std::getline(is, speciality, ',');
		is >> experience;
		return is;
	}
};

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
	std::ostream& print(std::ostream& os)const
	{
		return Student::print(os) << " " << subject;
	}
	std::ofstream& print(std::ofstream& os)const
	{
		Student::print(os) << "," << subject;
		return os;
	}
	std::ifstream& input(std::ifstream& is)
	{
		Student::input(is);
		std::getline(is, subject, ';');
		return is;
	}
};

Human* HumanFactory(const std::string& type)
{
	if (type.find("class Student") != std::string::npos)
	{
		return new Student("last_name", "first_name", 0, "specs", "group", 0, 0);
	}
	if (type.find("class Graduate") != std::string::npos)
	{
		return new Graduate("last_name", "first_name", 0, "specs", "group", 0, 0, "subject");
	}
	if (type.find("class Teacher") != std::string::npos)
	{
		return new Teacher("last_name", "first_name", 0, "spec", 0);
	}
}

//#define INHERITANCE_CHECK
//#define SAVE_TO_FILE

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

#ifdef SAVE_TO_FILE

	//Generalisation(���������):
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
		cout << *group[i] << endl;
	}
	cout << "\n-------------------------------------------------------\n";

	std::ofstream fout("group.txt");
	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		//group[i]->print();
		fout << typeid(*group[i]).name() << ":\t";
		fout << *group[i] << ";" << endl;
	}
	fout.close();

	system("start notepad group.txt");

	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		delete group[i];
	}
#endif // SAVE_TO_FILE

	std::ifstream fin("group.txt");

	size_t size = 0;
	Human** group = nullptr;

	if (fin.is_open())
	{
		std::string str(" ");
		//1)������� ���������� ����� � �����, ����� �������� ������ ��� ������:
		std::string buffer;
		for (size = 0; !fin.eof(); size++)
		{
			std::getline(fin, buffer, ';');
		}
		cout << "������ ������: " << size << endl;
		cout << "������� " << fin.tellg() << endl;
		//2)�������� ������ ��� ������:
		group = new Human * [--size]{};
		//3) ������������ � ������ ����� ��� ���� ����� ��� ��������� ������ � ��������� �� � ������
		fin.clear();
		fin.seekg(0);
		cout << "������� " << fin.tellg() << endl;
		//4) ������ ������ ����, � ��������� ��� ������ � �������:
		for (int i = 0; i < size; i++)
		{
			std::getline(fin, buffer, ':');
			group[i] = HumanFactory(buffer);
			fin >> *group[i];
			cout << *group[i] << endl;
		}
		fin.close();
	}
	else
	{
		std::cerr << "Error: file not found :-(\n";
	}

	cout << "\n-------------------------------------------------------\n";
	for (int i = 0; i < size; i++)
	{
		cout << *group[i] << endl;
	}
	cout << "\n-------------------------------------------------------\n";

	for (int i = 0; i < size; i++)
	{
		delete group[i];
	}
	delete[] group;
}


/*
	�� ����� ��� ������� ����� ��������� ������ ������ � ������� �� � ��������� ����� �������� ������ ��������� �������� �������� ������ � ��������� �� ������ ������������ ����������.
	��� �������� �������� ��������� ������ ������� ��������� ������ �������� ������ � ����� �� ������������ ���������� ��������� ������.���� �� ����� ������ ������ �������� ������ ������ ��������� ������ ������� ����������
	��� ���� ����� ������� ������ �������� ������ ��� �������� ��������� ������ ����������� ��������� ������ ������ ������� ����������� �������� ������ � �������� � ���� ���������
*/