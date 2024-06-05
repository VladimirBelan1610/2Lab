#ifndef CLASSESLANG_H
#define CLASSESLANG_H
#include <classunit.h>

class ClassJava : public ClassUnit
{
public:
    enum AccessModifier {
        PUBLIC,
        PROTECTED,
        PRIVATE
    };
    static const vector< string > ACCESS_MODIFIERS;
public:

    explicit ClassJava( const string& name ) : ClassUnit(name),m_name( name ) {
        m_fields.resize( ACCESS_MODIFIERS.size() );
    }
    void add( const shared_ptr< Unit >& unit, Flags flags );
    string compile( unsigned int level = 0 ) const;
protected:

    string m_name;
    using Fields = vector< shared_ptr< Unit > >;
    vector< Fields > m_fields;

};

class ClassCSharp : public ClassUnit
{
public:
    enum AccessModifier {
        PUBLIC,
        PROTECTED,
        PRIVATE
    };
    static const vector< string > ACCESS_MODIFIERS;
public:

    explicit ClassCSharp( const string& name ) : ClassUnit(name),m_name( name ) {
        m_fields.resize( ACCESS_MODIFIERS.size() );
    }
    void add( const shared_ptr< Unit >& unit, Flags flags );
    string compile( unsigned int level = 0 ) const;
protected:

    string m_name;
    using Fields = vector< shared_ptr< Unit > >;
    vector< Fields > m_fields;

};

class ClassCPlus : public ClassUnit
{
public:
    enum AccessModifier {
        PUBLIC,
        PROTECTED,
        PRIVATE
    };
    static const vector< string > ACCESS_MODIFIERS;
public:

    explicit ClassCPlus( const string& name ) : ClassUnit(name),m_name( name ) {
        m_fields.resize( ACCESS_MODIFIERS.size() );
    }
    void add( const shared_ptr< Unit >& unit, Flags flags );
    string compile( unsigned int level = 0 ) const;
protected:

    string m_name;
    using Fields = vector< shared_ptr< Unit > >;
    vector< Fields > m_fields;
};


#endif // CLASSESLANG_H
