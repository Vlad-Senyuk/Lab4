#include <iostream>
#include "class.h"
#include <string>
#include <string.h>
#include <cstring>
#include <cstringt.h>

void main()
{
	LIST list;
	mashina *p;
	tel *r;
	tr *t;
	r = new tel ("Telovek","M5000");
	list.insert(r);
	t = new tr("Telovek", "Mashina", 1997, "Kiborg");
	list.insert(t);
	r = new tel("Telovek", "T400");
	list.insert(r);
	t = new tr("Telovek", "Mashina", 1997, "Kiborg");
	list.insert(t);
	list.show();
}
