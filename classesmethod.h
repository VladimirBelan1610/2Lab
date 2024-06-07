#ifndef CLASSESMETHOD_H
#define CLASSESMETHOD_H
#include <methodunit.h>

class JavaMethod : public MethodUnit
{
public:

    enum Modifier { //каждому элементу присваивается целочисленное значение, используя битовые операции для установки флагов.
        STATIC = 1, // Элемент перечисления STATIC устанавливает первый бит в значении 1. То есть, битовое представление числа 1 это 0001.
        CONST = 1 << 1, //0010
        VIRTUAL = 1 << 2, //0100
        FINAL = 1 << 3 //1000
    }; // Modifier определяет четыре различных модификатора с доступом по битам: STATIC, CONST, VIRTUAL и FINAL, каждый из которых
       //соответствует уникальному значению, установленному через битовые операции. Каждый модификатор имеет свое уникальное
       //целочисленное значение

    static const vector <string> MODIFIERS;
public:

    JavaMethod( const string& name, const string& returnType, Flags flags ) : MethodUnit(name, returnType, flags), m_name( name ), m_returnType( returnType ), m_flags( flags ) { }
    void add( const shared_ptr< Unit >& unit, Flags /* flags */ = 0 );
    string compile( unsigned int level = 0 ) const;

private:

    string m_name;
    string m_returnType;
    Flags m_flags;
    vector< shared_ptr< Unit > > m_body;
};



class CSharpMethod : public MethodUnit
{
public:

    enum Modifier {
        STATIC = 1,
        CONST = 1 << 1,
        VIRTUAL = 1 << 2,
        OVERRIDE = 1 << 3
    };
static const vector <string> MODIFIERS;
public:

    CSharpMethod( const string& name, const string& returnType, Flags flags ) : MethodUnit(name, returnType, flags), m_name( name ), m_returnType( returnType ), m_flags( flags ) { }
    void add( const shared_ptr< Unit >& unit, Flags /* flags */ = 0 );
    string compile( unsigned int level = 0 ) const;

private:

    string m_name;
    string m_returnType;
    Flags m_flags;
    vector< shared_ptr< Unit > > m_body;
};



class CPlusMethod : public MethodUnit
{
public:

    enum Modifier {
        STATIC = 1,
        CONST = 1 << 1,
        VIRTUAL = 1 << 2

    };
static const vector <string> MODIFIERS;
public:

    CPlusMethod( const string& name, const string& returnType, Flags flags ) : MethodUnit(name, returnType, flags), m_name( name ), m_returnType( returnType ), m_flags( flags ) { }
    void add( const shared_ptr< Unit >& unit, Flags /* flags */ = 0 );
    string compile( unsigned int level = 0 ) const;

private:

    string m_name;
    string m_returnType;
    Flags m_flags;
    vector< shared_ptr< Unit > > m_body;
};



#endif // CLASSESMETHOD_H
