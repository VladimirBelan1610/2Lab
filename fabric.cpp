#include "fabric.h"

shared_ptr<ClassJava> FabricJava::createClass(const string& name)
{
    return make_shared<ClassJava>(name);
}
shared_ptr<JavaMethod> FabricJava::createMethod(const string& methodName, const string& returnValue, unsigned int flags)
{
    return make_shared<JavaMethod>(methodName, returnValue, flags);
}
shared_ptr<JavaPrintOperator> FabricJava::createPrintOperator(const string& printText)
{
    return make_shared<JavaPrintOperator>(printText);
}



shared_ptr<ClassCSharp> FabricCSharp::createClass(const string& name)
{
    return make_shared<ClassCSharp>(name);
}
shared_ptr<CSharpMethod> FabricCSharp::createMethod(const string& methodName, const string& returnValue, unsigned int flags)
{
    return make_shared<CSharpMethod>(methodName, returnValue, flags);
}
shared_ptr<CSharpPrintOperator> FabricCSharp::createPrintOperatorUnit(const string& printText)
{
    return make_shared<CSharpPrintOperator>(printText);
}



shared_ptr<ClassCPlus> FabricCPlus::createClass(const string& name)
{
     return make_shared<ClassCPlus>(name);
}
shared_ptr<CPlusMethod> FabricCPlus::createMethod(const string& methodName, const string& returnValue, unsigned int flags)
{
     return make_shared<CPlusMethod>(methodName, returnValue, flags);
}
shared_ptr<CPlusPrintOperator> FabricCPlus::createPrintOperatorUnit(const string& printText)
{
     return make_shared<CPlusPrintOperator>(printText);
}
