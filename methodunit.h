#ifndef METHODUNIT_H
#define METHODUNIT_H
#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include <unit.h>
using namespace std;

class MethodUnit : public Unit {

public:

    enum Modifier { //Определяет перечисление, которое используется для представления различных модификаторов метода
        STATIC = 1,
        CONST = 1 << 1,
        VIRTUAL = 1 << 2
    };

public:
    //Конструктор класса с инициализацией методов
    MethodUnit( const string& name, const string& returnType, Flags flags ) : m_name( name ), m_returnType( returnType ), m_flags( flags ) { }
    void add( const shared_ptr< Unit >& unit, Flags /* flags */ = 0 );
    virtual string compile( unsigned int level = 0 ) const = 0;

protected:

    string m_name;
    string m_returnType;
    Flags m_flags;
    vector< shared_ptr< Unit > > m_body;
};

#endif // METHODUNIT_H
