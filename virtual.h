class base {

public:

virtual void vfunc() {

cout << “Функция vfunc() из класса base\n”

}

};

class derived1: public base {

public:

void vfunc() {

cout << “Функция vfunc() из класса derived1\n”

}

};

class derived2: public base {

public:

void vfunc() {

cout << “Функция vfunc() из класса derived2\n”

}

};

int main() {

base *p, b;

derived1 d1;

derived2 d2;


// Указатель на объект базового класса:

p = &b;

p→vfunc(); // Вызов функции vfunc() из класса base


// Указатель на объект класса derived1:

p = &d1;

p→vfunc(); // Вызов функции vfunc() из класса derived1


// Указатель на объект класса derived2:

p = &d2;

p→vfunc(); // Вызов функции vfunc() из класса derived2


return 0;

}