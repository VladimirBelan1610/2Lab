#ifndef FABRIC_H
#define FABRIC_H
#include "ClassPrintOperator.h"
#include "PrintOperatorUnit.h"
#include "classeslang.h"
#include "classesmethod.h"
#include "classunit.h"
#include "methodunit.h"
#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include <iostream>
using namespace std;
class Fabric
{
public:
    virtual shared_ptr<ClassUnit> createClass(const string& name) = 0;
    virtual shared_ptr<MethodUnit> createMethod(const string& methodName, const string& returnValue, unsigned int flags) = 0;
    virtual shared_ptr<PrintOperatorUnit> createPrintOperator(const string& printText) = 0;
};

class FabricJava : public Fabric
{
public:
    shared_ptr<ClassJava> createClass(const string& name);
    shared_ptr<JavaMethod> createMethod(const string& methodName, const string& returnValue, unsigned int flags);
    shared_ptr<JavaPrintOperator> createPrintOperator(const string& printText);
};

class FabricCSharp : public Fabric
{
public:
    shared_ptr<ClassCSharp> createClass(const string& name);
    shared_ptr<CSharpMethod> createMethod(const string& methodName, const string& returnValue, unsigned int flags);
    shared_ptr<CSharpPrintOperator> createPrintOperatorUnit(const string& printText);
};
class FabricCPlus : public Fabric
{
    shared_ptr<ClassCPlus> createClass(const string& name);
    shared_ptr<CPlusMethod> createMethod(const string& methodName, const string& returnValue, unsigned int flags);
    shared_ptr<CPlusPrintOperator> createPrintOperatorUnit(const string& printText);
};

#endif // FABRIC_H
