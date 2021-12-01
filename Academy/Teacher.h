#pragma once
#include"stdafx.h"
#include"Human.h"
#define TEACHER_TAKE_PARAMETERS const std::string& speciality, unsigned experience
#define TEACHER_GIVA_PARAMETERS speciality, experience
class Teacher :public Human
{
	std::string speciality;
	unsigned int experience;
public:
	const std::string& get_speciality()const;
	unsigned int get_experience()const;
	void set_speciality(const std::string speciality);
	void set_experience(unsigned int experience);
	Teacher(HUMAN_TAKE_PARAMETERS, TEACHER_TAKE_PARAMETERS);
	~Teacher();

	//											Methods:
	void print()const;
};