// Dekorator.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <memory>


class Component {
public:
    virtual void operation() const = 0;
    virtual ~Component() = default;
};


class ConcreteComponent : public Component {
public:
    void operation() const override {
        std::cout << "Concrete Component" << std::endl;
    }
};

class Decorator : public Component {
public:
    Decorator(std::unique_ptr<Component> component) : component(std::move(component)) {}

    void operation() const override {
        if (component) {
            component->operation();
        }
    }

private:
    std::unique_ptr<Component> component;
};


class ConcreteDecoratorA : public Decorator {
public:
    ConcreteDecoratorA(std::unique_ptr<Component> component) : Decorator(std::move(component)) {}

    void operation() const override {
        Decorator::operation();
        addBehavior();
    }

    void addBehavior() const {
        std::cout << "Concrete Decorator A Behavior" << std::endl;
    }
};

class ConcreteDecoratorB : public Decorator {
public:
    ConcreteDecoratorB(std::unique_ptr<Component> component) : Decorator(std::move(component)) {}

    void operation() const override {
        Decorator::operation();
        addBehavior();
    }

    void addBehavior() const {
        std::cout << "Concrete Decorator B Behavior" << std::endl;
    }
};

int main() {
   
    std::unique_ptr<Component> component = std::make_unique<ConcreteComponent>();
    std::unique_ptr<Component> decoratedA = std::make_unique<ConcreteDecoratorA>(std::move(component));
    std::unique_ptr<Component> decoratedB = std::make_unique<ConcreteDecoratorB>(std::move(decoratedA));

    decoratedB->operation();

    return 0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
