#include "ClassPrintOperator.h"

string CPlusPrintOperator::compile( unsigned int level) const
{
    return generateShift( level ) + "printf( \"" + m_text + "\" );\n";
}


string CSharpPrintOperator::compile( unsigned int level) const
{
    return generateShift( level ) + "printf( \"" + m_text + "\" );\n";
}


string JavaPrintOperator::compile( unsigned int level) const
{
    return generateShift( level ) + "printf( \"" + m_text + "\" );\n";
}
