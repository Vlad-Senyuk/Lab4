#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <cstringt.h>
using namespace std;

class transpsred
{
public:
	transpsred()
	{
		strcpy_s(name," ");
		number = 0;
		next = 0;
	};

	transpsred(char *name, int number)
	{
		strcpy_s(this->name, name);
		this->number = number;
		next = 0;
	}

	virtual ~transpsred()
	{}

	virtual void show(void) = 0;
	virtual void input(void) = 0;

protected:
	dvigatel p;
	char name[20];
	int number;
	transpsred *next;

	friend class LIST;
};

class mashina : public transpsred
{
public:
	mashina()
	{
		mod=0;
	}

	mashina(char *name, int number, int mod) :transpsred(name, number)
	{
		this->mod = mod;
	}

	void show(void)
	{
		cout << "name: " << name << endl;
		cout << "number: " << number << endl;
		cout << "model: " << mod << endl;
	}

	void input(void)
	{
		cout << "name: ";
		cin >> name;
		cout << endl;
		cout << "number: ";
		cin >> number;
		cout << endl;
		cout << "model: ";
		cin >> mod;
		cout << endl;
	}

protected:
	int mod;
};

class dvigatel
{
public:
	dvigatel()
	{
		strcpy_s(col, " ");
	}

	dvigatel(char *col)
	{
		strcpy_s(this->col, col);
	}

	void show(void)
	{
		cout << "model: " << col << endl;
	}

	void input(void)
	{
		cout << "Dvigatel: ";
		cin >> col;
		cout << endl;
	}

protected:
	char col[20];
	
};

class raz_s
{
public:
	raz_s()
	{
		strcpy_s(name1, " ");
		next = 0;
	};

	raz_s(char *name)
	{
		strcpy_s(this->name1, name1);
		next = 0;
	}

	virtual ~raz_s()
	{}

	virtual void show(void) = 0;
	virtual void input(void) = 0;

protected:
	char name1[20];
	raz_s *next;

	friend class LIST;
};

class tel:public raz_s
{
public:
	tel()
	{
		strcpy_s(nam, " ");
	}

	tel(char *name1, char*nam):raz_s(name1)
	{
		strcpy_s(this->nam, nam);
	}

	void show(void)
	{
		cout << "name raz_s: " << nam << endl;
	}

	void input(void)
	{
		cout << "nam_raz_s: ";
		cin >> nam;
		cout << endl;
	}

protected:
	char nam[20];

};

class tr :public raz_s, public transpsred
{
public:
	tr()
	{
		strcpy_s(transf, " ");
	}

	tr(char *name1, char *name, int mod, char *transf):raz_s(name1),transpsred(name, mod)
	{
		strcpy_s(this->transf, transf);
	}

	void show(void)
	{
		cout << "transformer: " << transf << endl;
	}

	void input(void)
	{
		cout << "transformer: ";
		cin >> transf;
		cout << endl;
	}

protected:
	char transf[20];

};



class LIST
{
public:
	LIST()
	{
		begin = 0;
	}

	~LIST();

	void insert(raz_s*);
	void show(void);

private:
	raz_s *begin;
	
};

LIST::~LIST()
{
	raz_s *j;

	while (begin)
	{
		j = begin;
		begin = begin->next;
		delete j;
	}
}

void LIST::insert(raz_s* h)
{
	raz_s *f;
	f = begin;
	begin = h;
	h->next = f;
}

void LIST::show()
{
	raz_s *v;
	v = begin;

	while (v)
	{
		v->show();
		v = v->next;
	}
}
