#include <iostream>
#include <memory>

class InputMap
{
public:
    virtual void render() = 0;
    virtual ~InputMap() {}
};
class XboxMap : public InputMap
{
public:
    void render() override
    {
        std::cout << "render Xbox Mapping\n";
    }
};
class PSMap : public InputMap
{
public:
    void render() override
    {
        std::cout << "render Playstation Mapping\n";
    }
};
class KbMap : public InputMap
{
public:
    void render() override
    {
        std::cout << "render Keyboard Mapping\n";
    }
};
class Input
{
public:
    void render()
    {
        std::shared_ptr<InputMap> Input = createInputMap();
        Input->render();
    }
    virtual std::shared_ptr<InputMap> createInputMap() = 0;
    virtual ~Input() {}
};
class XboxInput : public Input
{
public:
    std::shared_ptr<InputMap> createInputMap() 
    {
        return std::make_shared<XboxMap>();
    }
};
class PSInput : public Input
{
public:
    std::shared_ptr<InputMap> createInputMap() 
    {
        return std::make_shared<PSMap>();
    }
};
class KbInput : public Input
{
public:
    std::shared_ptr<InputMap> createInputMap()
    {
        return std::make_shared<KbMap>();
    }
};
class myExeption
{
public:
    myExeption(){}
    const std::string& what()
    {
        return "error";
    }
};

int main()
{
    std::shared_ptr<Input> dialog; 
    std::string config;
    std::cout << "Enter mapping (Xbox or Ps): ";
    std::cin >> config;
    if (config == "Xbox")
    {
        dialog = std::make_shared<XboxInput>();
    }
    else if(config == "PS")
    {
        dialog = std::make_shared<PSInput>();
    }
    dialog.get()->render();
}


