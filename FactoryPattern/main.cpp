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

class Circle: public Shape
{
public:
    Circle()
    {
        std::cout << "Constructor of Circle" << std::endl;
    }
    ~Circle()
    {
        std::cout << "Destructor of Circle" << std::endl;
    }
    void draw()
    {
        std::cout << "Inside Circle::draw() method" << std::endl;
    }
};

class ShapeFactory
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
        if (shapeType == "CIRCLE")
        {
            return new Circle();
        }
        else if (shapeType == "RECTANGLE")
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

int main (void)
{
    // Creatr ShapeFactory object
    ShapeFactory* shapeFactory = new ShapeFactory();

    Shape* shapeCircle = shapeFactory->getShape("CIRCLE");
    shapeCircle->draw();
    std::cout << "------------------------------------" << std::endl;
    Shape* shapeRectangle = shapeFactory->getShape("RECTANGLE");
    shapeRectangle->draw();
    std::cout << "------------------------------------" << std::endl;
    Shape* shapeSquare = shapeFactory->getShape("SQUARE");
    shapeSquare->draw();
    std::cout << "------------------------------------" << std::endl;
    delete shapeCircle;
    delete shapeRectangle;
    delete shapeSquare;
    delete shapeFactory;
    return 0;
}
