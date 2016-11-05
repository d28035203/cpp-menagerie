// cpp-menagerie — inheritance + virtual methods
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Animal {
public:
    explicit Animal(std::string name) : name_(std::move(name)) {}
    virtual ~Animal() = default;
    virtual void speak() const = 0;
    virtual std::string species() const = 0;
    const std::string& name() const { return name_; }
protected:
    std::string name_;
};

class Dog : public Animal {
public:
    explicit Dog(std::string name) : Animal(std::move(name)) {}
    void speak() const override { std::cout << name_ << " (dog): woof\n"; }
    std::string species() const override { return "Dog"; }
};

class Cat : public Animal {
public:
    explicit Cat(std::string name) : Animal(std::move(name)) {}
    void speak() const override { std::cout << name_ << " (cat): meow\n"; }
    std::string species() const override { return "Cat"; }
};

class Bird : public Animal {
public:
    explicit Bird(std::string name) : Animal(std::move(name)) {}
    void speak() const override { std::cout << name_ << " (bird): chirp\n"; }
    std::string species() const override { return "Bird"; }
};

int main() {
    std::vector<std::unique_ptr<Animal>> zoo;
    zoo.push_back(std::make_unique<Dog>("Rex"));
    zoo.push_back(std::make_unique<Cat>("Miso"));
    zoo.push_back(std::make_unique<Bird>("Poe"));

    for (const auto& a : zoo) {
        std::cout << a->species() << " named " << a->name() << " → ";
        a->speak();
    }
    return 0;
}
