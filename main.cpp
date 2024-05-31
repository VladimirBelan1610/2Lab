#include <QCoreApplication>
#include <classunit.h>
#include <methodunit.h>
#include <PrintOperatorUnit.h>
#include <unit.h>
#include <iostream>
#include <fabric.h>
using namespace std;

string generateProgram(Fabric& factory) {
    shared_ptr<ClassUnit> myClass = factory.createClass( "MyClass" );
    myClass->add(factory.createMethod( "testFunc1", "void", 0 ),ClassUnit::PUBLIC);
    myClass->add(factory.createMethod( "testFunc2", "void", MethodUnit::STATIC | MethodUnit::PRIVATE ),ClassUnit::PRIVATE);
    myClass->add(factory.createMethod( "testFunc3", "void", MethodUnit::VIRTUAL | MethodUnit::CONST ),ClassUnit::PUBLIC);
    auto method = factory.createMethod( "testFunc4", "void",MethodUnit::STATIC );
    method->add( factory.createPrintOperator( R"(Hello, world!\n)" ) );
    myClass->add( method, ClassUnit::PROTECTED );
    return myClass->compile();
}

int main()
{
    Fabric* Java = new FabricJava;
    cout << generateProgram(*Java) << endl;
    return 0;
}
