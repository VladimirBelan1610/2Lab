#include "fabric.h"
#include "classeslang.h"
#include "classesmethod.h"
#include "ClassPrintOperator.h"

shared_ptr<ClassUnit> FabricJava::createClass(const string& name)
{
    return make_shared<ClassJava>(name);
}
shared_ptr<MethodUnit> FabricJava::createMethod(const string& methodName, const string& returnValue, unsigned int flags)
{
    return make_shared<JavaMethod>(methodName, returnValue, flags);
}
shared_ptr<PrintOperatorUnit> FabricJava::createPrintOperator(const string& printText)
{
    return make_shared<JavaPrintOperator>(printText);
}



shared_ptr<ClassUnit> FabricCSharp::createClass(const string& name)
{
    return make_shared<ClassCSharp>(name);
}
shared_ptr<MethodUnit> FabricCSharp::createMethod(const string& methodName, const string& returnValue, unsigned int flags)
{
    return make_shared<CSharpMethod> (methodName, returnValue, flags);
}
shared_ptr<PrintOperatorUnit> FabricCSharp::createPrintOperator(const string& printText)
{
    return make_shared<CSharpPrintOperator>(printText);
}



shared_ptr<ClassUnit> FabricCPlus::createClass(const string& name)
{
     return make_shared<ClassCPlus>(name);
}
shared_ptr<MethodUnit> FabricCPlus::createMethod(const string& methodName, const string& returnValue, unsigned int flags)
{
     return make_shared<CPlusMethod>(methodName, returnValue, flags);
}
shared_ptr<PrintOperatorUnit> FabricCPlus::createPrintOperator(const string& printText)
{
     return make_shared<CPlusPrintOperator>(printText);
}
