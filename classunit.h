#ifndef CLASSUNIT_H
#define CLASSUNIT_H

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include <unit.h>
using namespace std;
class ClassUnit : public Unit
{
public:
    enum AccessModifier {
        PUBLIC,
        PROTECTED,
        PRIVATE
    };
    static const vector< string > ACCESS_MODIFIERS;
public:

    explicit ClassUnit( const string& name ) : m_name( name ) {
        m_fields.resize( ACCESS_MODIFIERS.size() );
    }
    void add( const shared_ptr< Unit >& unit, Flags flags );
    string compile( unsigned int level = 0 ) const;
private:

    string m_name;
    using Fields = vector< shared_ptr< Unit > >;
    vector< Fields > m_fields;
};



#endif // CLASSUNIT_H
