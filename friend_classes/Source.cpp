// дружественный класс должен быть определЄн вне тела класса, предоставл€ющего дружбу
// все компоненты и функции класса друга будуь €вл€тьс€ дружественными дл€ другого класса без указани€ спецификатора friend
// все компоненты дружественного класса доступны другу, но не наоборот
// если дружественный класс при его описании есть функционал использующий компоненты друга, то необходимо предварительное объ€вление этого класса

// поле static €вл€етс€ одним обзим дл€ всех полей класса
// статическа€ функци€ работает только со статическими пол€ми

#include <iostream>
using namespace std;

class Student;

class Teacher {
private:
	string subject = "Subject";
public:
	void printStudent(Student st);
	friend Student;
	
};

class Student {

	string FN;
	string LN;
	static int numSt;
	static string group;
	static int grant;

public:

	void printSubject(Teacher t) {
		cout << t.subject << endl;
	}

	Student() {
		FN = "First name";
		LN = "Last name";
	}

	Student(string fn, string ln, int gr) {
		FN = fn;
		LN = ln;
		grant = gr;
		numSt++;
	}

	void Print_my() {
		cout << numSt << " " << FN << " " << LN << " " << group << " " << grant << endl;
	}

	static void Sum() {
		grant *= 1.1;

	}


	friend Teacher; 
	void setG(string s) {
		group = s;
	}
};


string Student::group = "BV221";
int Student::numSt = 0;
int Student::grant = 1000;

int main() {


	Student st1;
	Teacher t1;
	t1.printStudent(st1);
	st1.printSubject(t1);

	Student st2("F_2", "L_2", 200);
	st2.Print_my();
	Student st3("F_3", "L_3", 50);
	st3.Print_my();
	Student st4("F_4", "L_4", 1000);
	st4.Print_my();
	Student st5("F_5", "L_5", 450);
	st5.Print_my();

	Student::Sum();
	st2.Print_my();

	/*st3.setG("PV445");
	st4.Print_my();*/

	/*Student arr[4] = { st2, st3, st4,st5 };
	for (int i = 0; i < 4; i++)
	{
		arr[i].Print_my();
	}*/




	return 0;
}

void Teacher::printStudent(Student st)
{
	cout << st.FN  << " " << st.LN << endl;
}
