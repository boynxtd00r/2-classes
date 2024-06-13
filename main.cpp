#include <iostream>

// Класс B с функцией умножения
class B {
public:
    virtual int multiply(int x, int y) {
        return x * y;
    }
};

// Класс A с функцией f1
class A {
private:
    B& b; // Ссылка на экземпляр класса B

public:
    A(B& bInstance) : b(bInstance) {} // Конструктор инициализирует ссылку на B

    void f1(int x, int y) {
        int result = b.multiply(x, y); // Вызов функции multiply из класса B
        std::cout << "Result of multiplication: " << result << std::endl;
    }
};

int main() {
    B b;
    A a(b); // Создание экземпляра класса A с экземпляром B
    a.f1(3, 4); // Вызов функции f1 с аргументами 3 и 4

    return 0;
}

