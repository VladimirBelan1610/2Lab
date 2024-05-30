#ifndef PRINTOPERATORUNIT_H
#define PRINTOPERATORUNIT_H
#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include <unit.h>
using namespace std;

class PrintOperatorUnit : public Unit {
public:
    explicit PrintOperatorUnit( const string& text ) : m_text( text ) { }
    string compile( unsigned int level = 0 ) const;
private:
    string m_text;
};

#endif // PRINTOPERATORUNIT_H
