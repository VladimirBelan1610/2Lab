#ifndef CLASSPRINTOPERATOR_H
#define CLASSPRINTOPERATOR_H
#include <PrintOperatorUnit.h>

class JavaPrintOperator : public PrintOperatorUnit
{
public:
    explicit JavaPrintOperator( const string& text ) : PrintOperatorUnit( text ), m_text( text ) { }
    string compile( unsigned int level = 0 ) const;
private:
    string m_text;

};
class CSharpPrintOperator : public PrintOperatorUnit
{
public:
    explicit CSharpPrintOperator( const string& text ) : PrintOperatorUnit( text ), m_text( text ) { }
    string compile( unsigned int level = 0 ) const;
private:
    string m_text;

};
class CPlusPrintOperator : public PrintOperatorUnit
{
public:
    explicit CPlusPrintOperator( const string& text ) : PrintOperatorUnit( text ), m_text( text ) { }
    string compile( unsigned int level = 0 ) const;
private:
    string m_text;

};

#endif // CLASSPRINTOPERATOR_H
