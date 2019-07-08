#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <memory>
#include <list>
#include <map>
#include <iterator>

class Shape
{
public:
    Shape() = default;
    virtual ~Shape() = default;
    std::string getType()
    {
        return type;
    }
    std::string getId()
    {
        return id;
    }
    void setId(std::string id)
    {
        this->id = id;
    }
    virtual Shape* clone() = 0;
    virtual void draw() = 0;
protected:
    std::string type;
private:
    std::string id;
};

class Rectangle : public Shape
{
public:
    Rectangle()
    {
        std::cout << "Constructor Rectangle " << std::endl;
        type = "Rectangle";
    }
    Rectangle(const Rectangle& rhs)
    {
        type = rhs.type;
        std::cout << "Copy Constructor Rectangle " << std::endl;
    }
    ~Rectangle()
    {
        std::cout << "Destructor Rectangle " << std::endl;
    }
    void draw()
    {
        std::cout << "Inside Rectangle::draw() method. " << std::endl;
    }
    Shape* clone()
    {
        return new Rectangle(*this);
    }
};

class Circle : public Shape
{
public:
    Circle()
    {
        std::cout << "Constructor Circle " << std::endl;
        type = "Circle";
    }
    Circle(const Circle& rhs)
    {
        type = rhs.type;
        std::cout << "Copy Constructor Circle " << std::endl;
    }
    ~Circle()
    {
        std::cout << "Destructor Circle " << std::endl;
    }
    void draw()
    {
        std::cout << "Inside Circle::draw() method. " << std::endl;
    }
    Shape* clone()
    {
        return new Circle(*this);
    }
};

class Square : public Shape
{
public:
    Square()
    {
        std::cout << "Constructor Square " << std::endl;
        type = "Square";
    }
    Square(const Square& rhs)
    {
        type = rhs.type;
        std::cout << "Copy Constructor Square " << std::endl;
    }
    ~Square()
    {
        std::cout << "Destructor Square " << std::endl;
    }
    void draw()
    {
        std::cout << "Inside Square::draw() method. " << std::endl;
    }
    Shape* clone()
    {
        return new Square(*this);
    }
};

class ShapeCache
{
public:
    ShapeCache() = default;
    ~ShapeCache()
    {
        std::cout << "-------- Finalize ------ " << std::endl;
        if (circle != nullptr)
            delete circle;
        if (square != nullptr)
            delete square;
        if (rectangle != nullptr)
            delete rectangle;
    }
    Shape* getShape(std::string shapeId)
    {
        std::map<std::string, Shape*>::iterator it;
        it = shapeMap.find(shapeId);
        if (it != shapeMap.end())
        {
            Shape* cachedShape = it->second;
            return cachedShape->clone();
        }
        return nullptr;
    }

    void loadCache()
    {
        circle = new Circle();
        circle->setId("1");
        shapeMap.emplace(circle->getId(), circle);

        square = new Square();
        square->setId("2");
        shapeMap.emplace(square->getId(), square);

        rectangle = new Rectangle();
        rectangle->setId("3");
        shapeMap.emplace(rectangle->getId(), rectangle);
    }
private:
    std::map<std::string, Shape*> shapeMap;
    Circle* circle;
    Square* square;
    Rectangle* rectangle;
};


int main()
{
    ShapeCache* shapeCache = new ShapeCache();
    shapeCache->loadCache();

    Shape* cloneShape;

    cloneShape = shapeCache->getShape("1");
    std::cout << "Shape: " << cloneShape->getType() << std::endl;

    cloneShape = shapeCache->getShape("2");
    std::cout << "Shape: " << cloneShape->getType() << std::endl;

    cloneShape = shapeCache->getShape("3");
    std::cout << "Shape: " << cloneShape->getType() << std::endl;

    delete shapeCache;
    return 0;
}