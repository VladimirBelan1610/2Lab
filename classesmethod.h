#ifndef CLASSESMETHOD_H
#define CLASSESMETHOD_H
#include <methodunit.h>

class JavaMethod : MethodUnit
{
public:

    enum Modifier {
        STATIC = 1,
        CONST = 1 << 1,
        VIRTUAL = 1 << 2
    };

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



class CSharpMethod : MethodUnit
{
public:

    enum Modifier {
        STATIC = 1,
        CONST = 1 << 1,
        VIRTUAL = 1 << 2
    };

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



class CPlusMethod : MethodUnit
{
public:

    enum Modifier {
        STATIC = 1,
        CONST = 1 << 1,
        VIRTUAL = 1 << 2
    };

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
