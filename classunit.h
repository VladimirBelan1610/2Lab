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
        PRIVATE,
        DEFAULT
    };
    static const vector< string > ACCESS_MODIFIERS; //Статическое поле ACCESS_MODIFIERS, которое представляет собой вектор строк,
                                                    //соответствующий различным модификаторам доступа.
public:

    explicit ClassUnit( const string& name ) : m_name( name ) { //Конструктор ClassUnit, который принимает строку name и инициализирует
                                                                //поле m_name этой строкой, а также изменяет размер вектора m_fields до
                                                               //размера вектора ACCESS_MODIFIERS.
        m_fields.resize( ACCESS_MODIFIERS.size() );
    }
    void add( const shared_ptr< Unit >& unit, Flags flags );
    string compile( unsigned int level = 0 ) const;
protected:

    string m_name;
    using Fields = vector< shared_ptr< Unit > >; //Псевдоним типа Fields, который представляет собой вектор указателей на объекты типа Unit.
    vector< Fields > m_fields; //Вектор векторов m_fields, который, вероятно, используется для хранения полей класса с различными модификаторами доступа.
    Flags m_flags; //Поле m_flags типа Flags.
};



#endif // CLASSUNIT_H
