#include <iostream>


// Abstract product A
class ProductAInterface {
public:
    virtual ~ProductAInterface() {};
    virtual std::string getType() const = 0;
};

class ProductBInterface {
public:
    virtual ~ProductBInterface() {};
    virtual std::string getType() const = 0;
};

class ProductA : public ProductAInterface {
public:
    std::string type = "Product A";
    ~ProductA() {};
    ProductA() {};
    std::string getType() const override {
        return this->type;
    };
};

class ProductB : public ProductBInterface {
public:
    std::string type = "Product B";
    ~ProductB() {};
    ProductB() {};
    std::string getType() const override {
        return this->type;
    };
};

// Abstract Factory
class FactoryInterface {
public:
    virtual ~FactoryInterface() {};
    virtual ProductA* createProductA() const = 0;
    virtual ProductB* createProductB() const = 0;
    virtual std::string getFactoryName() const = 0;
};


// Concrete Factories for Product A and B
class FactoryA : public FactoryInterface {
public:
    std::string name = "Factory A";
    ProductA* createProductA() const override{
        return new ProductA();
    }

    ProductB* createProductB() const override {
        return new ProductB();
    }

    std::string getFactoryName() const override {
        return this->name;
    }
};

class FactoryB : public FactoryInterface {
public:
    std::string name = "Factory B";
    ProductA* createProductA() const override {
        return new ProductA();
    }

    ProductB* createProductB() const override {
        return new ProductB();
    }

    std::string getFactoryName() const override {
        return this->name;
    }
};

// Client receive a Abstract factory and interacts with its interfaces
//  instead of concrete classes
void client(const FactoryInterface& factory) {
    const ProductAInterface* productOne = factory.createProductA();
    const ProductBInterface* productTwo = factory.createProductB();

    std::cout << factory.getFactoryName() << " made product type: " << productOne->getType() << "\n";
    std::cout << factory.getFactoryName() << " made product type: " << productTwo->getType() << "\n";
}

int main() {
    FactoryA* fa = new FactoryA();
    FactoryB* fb = new FactoryB();

    client(*fa);
    client(*fb);

    return 0;
}