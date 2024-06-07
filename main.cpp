#include <QCoreApplication>
#include <classunit.h>
#include <methodunit.h>
#include <PrintOperatorUnit.h>
#include <unit.h>
#include <iostream>
#include <fabric.h>
using namespace std;

string generateProgram(Fabric& factory) {
    shared_ptr<ClassUnit> myClass = factory.createClass( "MyClass" ); //Создается указатель myClass на объект класса ClassUnit,
                                                                     //который создается с помощью фабрики factory и называется "MyClass"
    myClass->add(factory.createMethod( "testFunc1", "void", 0 ),ClassUnit::PUBLIC); //Добавляется публичный метод "testFunc1" с
    //возвращаемым типом "void" и без модификаторов к доступу.
    myClass->add(factory.createMethod( "testFunc2", "void", MethodUnit::STATIC ),ClassUnit::PRIVATE); //Добавляется приватный статический
    //метод "testFunc2" с возвращаемым типом "void".
    myClass->add(factory.createMethod( "testFunc3", "void", MethodUnit::VIRTUAL | MethodUnit::CONST ),ClassUnit::PUBLIC);
    //Добавляется публичный виртуальный константный метод "testFunc3" с возвращаемым типом "void".
    auto method = factory.createMethod( "testFunc4", "void",MethodUnit::STATIC ); //Создается метод method с именем "testFunc4",
    //возвращаемым типом "void" и модификатором статического метода.
    method->add( factory.createPrintOperator( R"(Hello, world!\n)" ) ); //Для метода method добавляется оператор печати,
    //который выводит текст "Hello, world!\\n".
    myClass->add( method, ClassUnit::PROTECTED ); //Добавляется метод method в класс myClass с модификатором защищенного доступа.
    return myClass->compile(); //Класс myClass компилируется в строку и возвращается из функции.
}

int main()
{
    Fabric* Charp = new FabricCSharp; //Объявляется указатель типа Fabric, который может указывать на объекты любого класса, производного от класса Fabric.
    Fabric* Java = new FabricJava;
    Fabric* CPlus = new FabricCPlus;
    cout << generateProgram(*Charp) << endl;
    cout << generateProgram(*Java) << endl;
    cout << generateProgram(*CPlus) << endl;
    return 0;
}
