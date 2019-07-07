#include <iostream>
#include <string>

class Shape
{
public:
    Shape()
    {
        std::cout << "Constructor of Shape" << std::endl;
    }
    virtual ~Shape()
    {
        std::cout << "Destructor of Shape" << std::endl;
    }
    virtual void draw() = 0;
};

class Rectangle: public Shape
{
public:
    Rectangle()
    {
        std::cout << "Constructor of Rectangle" << std::endl;
    }
    ~Rectangle()
    {
        std::cout << "Destructor of Rectangle" << std::endl;
    }
    void draw()
    {
        std::cout << "Inside Rectangle::draw() method" << std::endl;
    }
};

class RoundedRectangle: public Shape
{
public:
    RoundedRectangle()
    {
        std::cout << "Constructor of RoundedRectangle" << std::endl;
    }
    ~RoundedRectangle()
    {
        std::cout << "Destructor of RoundedRectangle" << std::endl;
    }
    void draw()
    {
        std::cout << "Inside RoundedRectangle::draw() method" << std::endl;
    }
};

class Square: public Shape
{
public:
    Square()
    {
        std::cout << "Constructor of Square" << std::endl;
    }
    ~Square()
    {
        std::cout << "Destructor of Square" << std::endl;
    }
    void draw()
    {
        std::cout << "Inside Square::draw() method" << std::endl;
    }
};

class RoundedSquare: public Shape
{
public:
    RoundedSquare()
    {
        std::cout << "Constructor of RoundedSquare" << std::endl;
    }
    ~RoundedSquare()
    {
        std::cout << "Destructor of RoundedSquare" << std::endl;
    }
    void draw()
    {
        std::cout << "Inside RoundedSquare::draw() method" << std::endl;
    }
};

class AbstractFactory
{
public:
    AbstractFactory()
    {
        std::cout << "Constructor of AbstractFactory" << std::endl;
    }
    ~AbstractFactory()
    {
        std::cout << "Destructor of AbstractFactory" << std::endl;
    }
    virtual Shape* getShape(std::string shapeType) = 0;
};

class ShapeFactory : public AbstractFactory
{
public:
    ShapeFactory()
    {
        std::cout << "Constructor of ShapeFactory" << std::endl;
    }
    ~ShapeFactory()
    {
        std::cout << "Destructor of ShapeFactory" << std::endl;
    }
    Shape* getShape(std::string shapeType)
    {
        if (shapeType == "RECTANGLE")
        {
            return new Rectangle();
        }
        else if (shapeType == "SQUARE")
        {
            return new Square();
        }
        else
        {
            return nullptr;
        }
    }
};

class RoundedShapeFactory : public AbstractFactory
{
public:
    RoundedShapeFactory()
    {
        std::cout << "Constructor of RoundedShapeFactory" << std::endl;
    }
    ~RoundedShapeFactory()
    {
        std::cout << "Destructor of RoundedShapeFactory" << std::endl;
    }
    Shape* getShape(std::string shapeType)
    {
        if (shapeType == "RECTANGLE")
        {
            return new RoundedRectangle();
        }
        else if (shapeType == "SQUARE")
        {
            return new RoundedSquare();
        }
        else
        {
            return nullptr;
        }
    }
};

class FactoryProducer
{
public:
    FactoryProducer()
    {
        std::cout << "Constructor of FactoryProducer" << std::endl;
    }
    ~FactoryProducer()
    {
        std::cout << "Destructor of FactoryProducer" << std::endl;
    }
    static AbstractFactory* getFactory(bool rounded)
    {
        if (rounded)
        {
            return new RoundedShapeFactory();
        }
        else
        {
            return new ShapeFactory();
        }
    }
    
};

int main (void)
{
    FactoryProducer* factoryProducer = new FactoryProducer();
    std::cout << "----------------------------------------" << std::endl;
    AbstractFactory* shapeAbstractFactory = factoryProducer->getFactory(false);
    std::cout << "----------------------------------------" << std::endl;
    Shape* shapeRectangle = shapeAbstractFactory->getShape("RECTANGLE");
    shapeRectangle->draw();
    std::cout << "----------------------------------------" << std::endl;
    Shape* shapeSquare = shapeAbstractFactory->getShape("SQUARE");
    shapeSquare->draw();
    std::cout << "----------------------------------------" << std::endl;
    delete shapeRectangle;
    delete shapeSquare;
    delete shapeAbstractFactory;
    std::cout << "----------------------------------------" << std::endl;
    AbstractFactory* shapeAbstractFactory2 = factoryProducer->getFactory(true);
    std::cout << "----------------------------------------" << std::endl;
    Shape* shapeRectangle2 = shapeAbstractFactory2->getShape("RECTANGLE");
    shapeRectangle2->draw();
    std::cout << "----------------------------------------" << std::endl;
    Shape* shapeSquare2 = shapeAbstractFactory2->getShape("SQUARE");
    shapeSquare2->draw();
    std::cout << "----------------------------------------" << std::endl;
    delete shapeRectangle2;
    delete shapeSquare2;
    delete shapeAbstractFactory2;
    delete factoryProducer;
    return 0;
}
