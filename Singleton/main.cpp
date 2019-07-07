#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <memory>

class Singleton
{
private:
    static std::unique_ptr<Singleton> instance;
    static std::once_flag flag;
    Singleton()
    {
        std::cout << "Constructor of Singleton" << std::endl;
    }
    Singleton(const Singleton& src) = delete;
    Singleton& operator = (const Singleton& rhs) = delete;
public:
    ~Singleton()
    {
        std::cout << "Destructor of Singleton" << std::endl;
    }
    static Singleton* getInstance();
    void showMessage()
    {
        std::cout << "---------------- showMessage -------------------- " << std::endl;
    }
    
};

std::unique_ptr<Singleton> Singleton::instance;
std::once_flag Singleton::flag;


Singleton* Singleton::getInstance()
{
    std::call_once(flag,
        [] () {
            instance.reset(new Singleton());
        });
    
    return instance.get();
}

int main()
{
    Singleton* object = Singleton::getInstance();
    object->showMessage();
    // Singleton::getInstance()->showMessage();
    // Singleton* object1 = Singleton::getInstance();
    // Singleton* object2 = Singleton::getInstance();
    // Singleton* object3 = Singleton::getInstance();
    return 0;
}
