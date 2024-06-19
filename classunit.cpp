#include "classunit.h"

void ClassUnit::add( const shared_ptr< Unit >& unit, Flags flags ) //Метод add добавляет указатель на объект типа Unit в вектор полей
                                                                  //класса m_fields с определенным модификатором доступа.
{
    int accessModifier = PRIVATE;
    if( flags < ACCESS_MODIFIERS.size() ) {
        accessModifier = flags;
    }
    m_fields[ accessModifier ].push_back( unit );
}

const vector< string > ClassUnit::ACCESS_MODIFIERS = { "public","protected", "private" };
