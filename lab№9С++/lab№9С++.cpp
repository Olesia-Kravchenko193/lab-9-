#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <ctime>
#include <fstream>

using namespace std;

struct Date {
	short day;
	short month;
	short year;
	bool isCorrect();
};

struct Time
{
	short second;
	short minute;
	short hour;
	bool isCorrect();
};

bool Time::isCorrect()
{
	//bool result = false;
	if (hour > 23 || hour < 0)
	{
		return false;
	}
	else
	{
		if (minute < 0 || minute > 59)
		{
			return false;
		}
		else
		{
			if (second < 0 || second > 59)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
	}
}

struct Film
{
	Date date;
	char FilmName[20];
	char Genre[20];
	Time time;
	short duration;
	Time EndTime;
};

struct Poster
{
	char CinemaName[20];
	Film film[15];
};


bool Date::isCorrect()
{
	bool result = false;
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
	{
		if ((day >= 1) && (day <= 31) && (year < 2021))
			result = true;
		break;
	}
	case 4:
	case 6:
	case 9:
	case 11:
	{
		if ((day > 0) && (day <= 30) && (year < 2021))
			result = true;
		break;
	}
	case 2:
	{
		if (year % 4 != 0)
		{
			if ((day > 0) && (day <= 28) && (year < 2021))
				result = true;
		}
		else
		{
			if ((day > 0) && (day <= 29) && (year < 2021))
				result = true;
		}
		break;
	}

	default:
		result = false;
	}
	return result;
}



void Task1()

{
	int sum = 0;
	Date date;
	do {
		cout << "Введите дату в формате : День(enter) Месяц(enter) Год(enter)\n";
		cin >> date.day;
		cin >> date.month;
		cin >> date.year;
	} while (!date.isCorrect());

	for (int i = 1; i < date.year - 1; i++)
	{
		if (i % 4 == 0) {
			sum += 366;
		}
		else {
			sum += 365;
		}

	}
	if (date.month > 1) {
		for (int i = 1; i < date.month; i++) {
			if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) sum += 31;
			if (i == 4 || i == 6 || i == 9 || i == 11) sum += 30;
			if (i == 2 && date.year % 4 == 0) sum += 29;
			if (i == 2 && date.year % 4 != 0) sum += 28;
		}
	}
	sum += date.day;

	int swt = sum % 7;
	cout << "Прошло дней до текущего момента: " << sum << endl << "День недели: ";

	switch (swt)
	{
	case 1:
		cout << "Понедельник";
		break;
	case 2:
		cout << "Вторник";
		break;
	case 3:
		cout << "Среда";
		break;
	case 4:
		cout << "Четверг";
		break;
	case 5:
		cout << "Пятница";
		break;
	case 6:
		cout << "Суббота";
		break;
	case 7:
		cout << "Воскресенье";
		break;
	default:
		break;
	}
	cout << "\n";
}

void Task2()
{
	Poster Afisha;
	cout << "Введите название Кинотеатра:";
	cin >> Afisha.CinemaName;

	cout << "Сколько сеансов в кинотеатре ?";
	int ans = 1;
	cin >> ans;

	if (ans > 15)cout << "Число сеансов не может превышать 15";

	for (int i = 0; i < ans; i++)
	{
		cout << "Сеанс №" << i + 1 << endl;
		do {
			cout << "Введите дату сеанса в формате : День(enter) Месяц(enter) Год(enter)\n";
			cin >> Afisha.film[i].date.day;
			cin >> Afisha.film[i].date.month;
			cin >> Afisha.film[i].date.year;
		} while (!Afisha.film[i].date.isCorrect());

		cout << "Название фильма : ";
		cin >> Afisha.film[i].FilmName;

		cout << "Жанр фильма : ";
		cin >> Afisha.film[i].Genre;

		do {
			cout << "Введите время сеанса в формате : Часы(enter) Минуты(enter) Секунды(enter)\n";
			cin >> Afisha.film[i].time.hour;
			cin >> Afisha.film[i].time.minute;
			cin >> Afisha.film[i].time.second;
		} while (!Afisha.film[i].time.isCorrect());

		cout << "\nКакова длительность фильма ? ";
		cin >> Afisha.film[i].duration;
		cout << "\n\n";

		short min = 0, hou = 0, sum = 0;
		Afisha.film[i].EndTime.second = Afisha.film[i].time.second;
		min = Afisha.film[i].time.minute;
		hou = Afisha.film[i].time.hour;
		sum = min + Afisha.film->duration;

		if (sum > 59)
		{
			hou += floor(sum / 60);
			min = sum % 60;
			if (hou > 23)
			{
				hou = hou % 24;
				Afisha.film[i].EndTime.minute = min;
				Afisha.film[i].EndTime.hour = hou;
			}
		}
		else
		{
			Afisha.film[i].EndTime.minute = sum;
			Afisha.film[i].EndTime.hour = Afisha.film[i].time.hour;
		}

		cout << "Время окончания сеанса " << Afisha.film[i].EndTime.hour << " : " << Afisha.film[i].EndTime.minute << " : " << Afisha.film[i].EndTime.second << "\n\n";
	}

	cout << "Фильмы, которые идут на выходных :\n\n";
	for (int i = 0; i < ans; i++)
	{
		int sum = 0;

		for (int i = 1; i < Afisha.film[i].date.year - 1; i++)
		{
			if (i % 4 == 0) {
				sum += 366;
			}
			else {
				sum += 365;
			}

		}
		if (Afisha.film[i].date.month > 1) {
			for (int i = 1; i < Afisha.film[i].date.month; i++) {
				if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) sum += 31;
				if (i == 4 || i == 6 || i == 9 || i == 11) sum += 30;
				if (i == 2 && Afisha.film[i].date.year % 4 == 0) sum += 29;
				if (i == 2 && Afisha.film[i].date.year % 4 != 0) sum += 28;
			}
		}
		sum += Afisha.film[i].date.day;

		int swt = sum % 7;


		if (swt == 6 || swt == 0)
		{
			cout << "Название фильма : " << Afisha.film[i].FilmName << "\n";
			cout << "Жанр фильма : " << Afisha.film[i].Genre << "\n";
			cout << "Дата сеанса : " << Afisha.film[i].date.day << "." << Afisha.film[i].date.month << "." << Afisha.film[i].date.year << "\n";
			cout << "Время начала :" << Afisha.film[i].time.hour << " : " << Afisha.film[i].time.minute << " : " << Afisha.film[i].time.second << "\n";
			cout << "Время окончания сеанса " << Afisha.film[i].EndTime.hour << " : " << Afisha.film[i].EndTime.minute << " : " << Afisha.film[i].EndTime.second << "\n";
		}

		cout << "\n";
	}
}

void Task3()
{
	short size;
	do {
		size = 0;
		cin.clear();
		cout << "Количество кинотеатров в базе ? ";
		cin >> size;
	} while (size < 0);

	Poster *Afisha = new Poster[size];
	ofstream fout("base.txt");

	short count = rand() % 15;

	for (int j = 0; j < size; j++)
	{
		cout << "Введите название текущего кинотеатра ";
		cin >> Afisha[j].CinemaName;

		for (int i = 0; i < count; i++)
		{
			short choice = 0;
			cout << "Ввести информацию о фильме?\n 1-Да\n(Любое число)-Нет\n";
			cin >> choice;
			if (choice != 1)
			{
				break;
			}
			else
			{
				cout << "Название : " << endl;
				cin >> Afisha[j].film[i].FilmName;
				cout << "Жанр : " << endl;
				cin >> Afisha[j].film[i].Genre;
				do {
					Afisha[j].film[i].date.day = rand() % 31;
					Afisha[j].film[i].date.month = rand() % 2 + 6;
					Afisha[j].film[i].date.year = 2020;
				} while (!Afisha[j].film[i].date.isCorrect());
				do {
					Afisha[j].film[i].time.hour = rand() % 23;
					Afisha[j].film[i].time.minute = rand() % 59;
					Afisha[j].film[i].time.second = 0;
				} while (!Afisha[j].film[i].time.isCorrect());
				Afisha[j].film[i].duration = rand() % 60 + 60;

				short min = 0, hou = 0, sum = 0;
				Afisha[j].film[i].EndTime.second = Afisha[j].film[i].time.second;
				min = Afisha[j].film[i].time.minute;
				hou = Afisha[j].film[i].time.hour;
				sum = min + Afisha[j].film->duration;

				if (sum > 59)
				{
					hou += floor(sum / 60);
					min = sum % 60;
					if (hou > 23)
					{
						hou = hou % 24;
						Afisha[j].film[i].EndTime.minute = min;
						Afisha[j].film[i].EndTime.hour = hou;
					}
				}
				else
				{
					Afisha[j].film[i].EndTime.minute = sum;
					Afisha[j].film[i].EndTime.hour = Afisha[j].film[i].time.hour;
				}

				fout << "Название: " << Afisha[j].film[i].FilmName << endl;
				fout << "Жанр: " << Afisha[j].film[i].Genre << endl;
				fout << "Дата: " << Afisha[j].film[i].date.day << "." << Afisha[j].film[i].date.month << "." << Afisha[j].film[i].date.year << endl;
				fout << "Время начала: " << Afisha[j].film[i].time.hour << ":" << Afisha[j].film[i].time.minute << ":" << Afisha[j].film[i].time.second << endl;
				fout << "Продолжительность(мин): " << Afisha[j].film[i].duration << endl << endl;
			}

		}
	}
	Poster test;
	do {
		cout << "Введите дату сеанса в формате : День(enter) Месяц(enter) Год(enter)\n";
		cin >> test.film[0].date.day;
		cin >> test.film[0].date.month;
		cin >> test.film[0].date.year;
	} while (!test.film[0].date.isCorrect());

	short seanses = 0, dur = 0;

	for (int j = 0; j < size; j++)
	{
		for (int i = 0; i < count; i++)
		{
			if (Afisha[j].film[i].date.day == test.film[0].date.day && Afisha[j].film[i].date.month == test.film[0].date.month && Afisha[j].film[i].date.year == test.film[0].date.year)
			{
				seanses++;
				dur += Afisha[j].film[i].duration;
			}
		}
	}

	cout << "Сеансов в этот день: " << seanses << endl;
	cout << "Средняя продолжительность: " << dur / seanses << endl;

	cout << "Введите название кинотеатра ";
	cin >> test.CinemaName;
	do {
		cout << "Введите дату в формате : День(enter) Месяц(enter) Год(enter)\n";
		cin >> test.film[0].date.day;
		cin >> test.film[0].date.month;
		cin >> test.film[0].date.year;
	} while (!test.film[0].date.isCorrect());

	seanses = 0;

	for (int j = 0; j < size; j++)
	{
		ofstream fout1(Afisha[j].CinemaName);
		for (int i = 0; i < count; i++)
		{
			if (seanses == 0 && Afisha[j].CinemaName == test.CinemaName && Afisha[j].film[i].date.day == test.film[0].date.day && Afisha[j].film[i].date.month == test.film[0].date.month && Afisha[j].film[i].date.year == test.film[0].date.year)
			{
				cout << "Название: " << Afisha[j].film[i].FilmName << endl;
				cout << "Жанр: " << Afisha[j].film[i].Genre << endl;
				cout << "Дата: " << Afisha[j].film[i].date.day << "." << Afisha[j].film[i].date.month << "." << Afisha[j].film[i].date.year << endl;
				cout << "Время начала: " << Afisha[j].film[i].time.hour << ":" << Afisha[j].film[i].time.minute << ":" << Afisha[j].film[i].time.second << endl;
				cout << "Продолжительность(мин): " << Afisha[j].film[i].duration << endl << endl;
			}

			if (Afisha[j].film[i].date.month == 7)
			{
				fout1 << "Название: " << Afisha[j].film[i].FilmName << endl;
				fout1 << "Жанр: " << Afisha[j].film[i].Genre << endl;
				fout1 << "Дата: " << Afisha[j].film[i].date.day << "." << Afisha[j].film[i].date.month << "." << Afisha[j].film[i].date.year << endl;
				fout1 << "Время начала: " << Afisha[j].film[i].time.hour << ":" << Afisha[j].film[i].time.minute << ":" << Afisha[j].film[i].time.second << endl;
				fout1 << "Продолжительность(мин): " << Afisha[j].film[i].duration << endl << endl;
			}
		}
	}


}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int numTask;
	cout << "Enter num of task: ";
	cin >> numTask;
	setlocale(LC_ALL, "Rus");

	switch (numTask)
	{
	case 1:
		Task1();
		break;
	case 2:
		Task2();
		break;
	case 3:
		Task3();
		break;
	}
}
