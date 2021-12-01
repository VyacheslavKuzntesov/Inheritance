﻿#include<iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
}

/*
	НАСЛЕДОВАНИЕ Inheritance
	Наследование это способность классов наследовать свойства других классов
	В наследовании разлечают базовый или родительский класс это класс от которого наследуют и дочерний или производный класс это класс который наследует чужие свойства
	Базовый класс(Base class) не знает сколько и каких классов от него унаследованно
	А дочерний класc(Derived class) знает только своего ближайщего родителя и не знает своих прародителей

	Наследование обобщает свойства разных классов и позволяет их вывести в отдельный класс а это в свою очередь в значительной степени сокращает объем исходного кода а так же распределяет ответственность между разными классами
	Наследование реализует отношения между классами типа является (is a) и по этому прежде чем что-то от чего-то унаследовать нужно убедиться в том что что-то является чем-то например кот является животным? - да, грузовик является машиной? - да, колесо являеться машиной? - нет поэтому класс калесо нельзя унаследовать от класса "машина"
	Машина агрегирует в себя колесо и это не наследование а агрегирование

*/