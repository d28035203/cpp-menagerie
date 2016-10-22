// cpp-menagerie — OOP inheritance demo
#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Animal {
public:
    explicit Animal(std::string n) : name_(std::move(n)) {}
    virtual ~Animal() = default;
    virtual void speak() const {
        std::cout << name_ << " makes a noise.\n";
    }
protected:
    std::string name_;
};

class Dog : public Animal {
public:
    explicit Dog(std::string n) : Animal(std::move(n)) {}
    void speak() const override {
        std::cout << name_ << " says woof.\n";
    }
};

class Cat : public Animal {
public:
    explicit Cat(std::string n) : Animal(std::move(n)) {}
    void speak() const override {
        std::cout << name_ << " says meow.\n";
    }
};

int main() {
    std::vector<std::unique_ptr<Animal>> zoo;
    zoo.push_back(std::unique_ptr<Animal>(new Dog("Byte")));
    zoo.push_back(std::unique_ptr<Animal>(new Cat("Null")));
    zoo.push_back(std::unique_ptr<Animal>(new Animal("Generic")));
    for (size_t i = 0; i < zoo.size(); ++i)
        zoo[i]->speak();
    return 0;
}
