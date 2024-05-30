#include "PrintOperatorUnit.h"

string PrintOperatorUnit::compile( unsigned int level) const
{
    return generateShift( level ) + "printf( \"" + m_text + "\" );\n";
}
