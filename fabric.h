#ifndef FABRIC_H
#define FABRIC_H
#include "PrintOperatorUnit.h"
#include "classesmethod.h"
#include "classunit.h"
#include "methodunit.h"
#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include <iostream>
using namespace std;
class Fabric //Содержит чисто виртуальные методы для создания объектов различных типов: классов, методов и операторов вывода.
{
public:
    virtual shared_ptr<ClassUnit> createClass(const string& name) = 0;
    virtual shared_ptr<MethodUnit> createMethod(const string& methodName, const string& returnValue, unsigned int flags) = 0;
    virtual shared_ptr<PrintOperatorUnit> createPrintOperator(const string& printText) = 0;
};

class FabricJava : public Fabric
{
public:
    shared_ptr<ClassUnit> createClass(const string& name) override; //метод создает и возвращает объект класса ClassUnit на основе
    //переданного имени name.
    shared_ptr<MethodUnit> createMethod(const string& methodName, const string& returnValue, unsigned int flags) override;
    shared_ptr<PrintOperatorUnit> createPrintOperator(const string& printText) override;
};

class FabricCSharp : public Fabric
{
public:
    shared_ptr<ClassUnit> createClass(const string& name) override;
    shared_ptr<MethodUnit> createMethod(const string& methodName, const string& returnValue, unsigned int flags) override;
    shared_ptr<PrintOperatorUnit> createPrintOperator(const string& printText) override;
};
class FabricCPlus : public Fabric
{
    shared_ptr<ClassUnit> createClass(const string& name) override;
    shared_ptr<MethodUnit> createMethod(const string& methodName, const string& returnValue, unsigned int flags) override;
    shared_ptr<PrintOperatorUnit> createPrintOperator(const string& printText) override;
};

#endif // FABRIC_H
