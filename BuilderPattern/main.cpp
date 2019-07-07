#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <memory>
#include <list>

class Packing
{
public:
    Packing() = default;
    ~Packing() = default;
    virtual std::string pack() = 0;
};

class Item
{
public:
    Item() = default;
    ~Item() = default;
    virtual std::string name() = 0;
    virtual Packing* packing() = 0;
    virtual float price() = 0;
};


class Bottle : public Packing
{
public:
    Bottle() = default;
    ~Bottle() = default;
    std::string pack()
    {
        return "Bottle";
    }
};

class Wrapper : public Packing
{
public:
    Wrapper() = default;
    ~Wrapper() = default;
    std::string pack()
    {
        return "Wrapper";
    }
};


class Burger : public Item
{
public:
    Burger() = default;
    ~Burger() = default;
    Packing* packing()
    {
        return new Wrapper();
    }
    virtual float price() = 0;
};

class ColdDrink : public Item
{
public:
    ColdDrink() = default;
    ~ColdDrink() = default;
    Packing* packing()
    {
        return new Bottle();
    }
    virtual float price() = 0;
};

class VegBurger : public Burger
{
public:
    VegBurger() = default;
    ~VegBurger() = default;
    float price()
    {
        return 25.0f;
    }
    std::string name()
    {
        return "Veg Burger";
    }
};

class ChickenBurger : public Burger
{
public:
    ChickenBurger() = default;
    ~ChickenBurger() = default;
    float price()
    {
        return 50.5f;
    }
    std::string name()
    {
        return "Chicken Burger";
    }
};

class Coke : public ColdDrink
{
public:
    Coke() = default;
    ~Coke() = default;
    float price()
    {
        return 30.0f;
    }
    std::string name()
    {
        return "Coke";
    }
};

class Pepsi : public ColdDrink
{
public:
    Pepsi() = default;
    ~Pepsi() = default;
    float price()
    {
        return 35.0f;
    }
    std::string name()
    {
        return "Pepsi";
    }
};

class Meal
{
private:
    std::list<Item*> items;
public:
    Meal() = default;
    ~Meal() = default;
    void addItem(Item* item)
    {
        items.push_back(item);
    }
    float getCost()
    {
        float cost = 0.0;
        for (auto itr : items)
        {
            cost += itr->price();
        }
        return cost;
    }
    void showItems()
    {
        for (auto itr : items)
        {
            std::cout << "Item : " << itr->name()
                      << ", Packing : " << itr->packing()->pack()
                      << ", Price : " << itr->price() << std::endl;
        }
    }
};

class MealBuilder
{
public:
    MealBuilder() = default;
    ~MealBuilder() = default;
    Meal* prepareVegMeal()
    {
        Meal* meal = new Meal();
        meal->addItem(new VegBurger());
        meal->addItem(new Coke());
        return meal;
    }

    Meal* prepareNonVegMeal()
    {
        Meal* meal = new Meal();
        meal->addItem(new ChickenBurger());
        meal->addItem(new Pepsi());
        return meal;
    }
};

int main()
{
    MealBuilder* mealBuilder = new MealBuilder();
    Meal* vegMeal = mealBuilder->prepareVegMeal();
    std::cout << "Veg Meal" << std::endl;
    vegMeal->showItems();
    std::cout << "Total Price: " << vegMeal->getCost() << std::endl;

    MealBuilder* mealBuilder2 = new MealBuilder();
    Meal* vegMeal2 = mealBuilder2->prepareNonVegMeal();
    std::cout << "Non Veg Meal" << std::endl;
    vegMeal2->showItems();
    std::cout << "Total Price: " << vegMeal2->getCost() << std::endl;
    return 0;
}