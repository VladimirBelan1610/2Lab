#include "classeslang.h"
void ClassCPlus::add( const shared_ptr< Unit >& unit, Flags flags )//принимает умный указатель на объект класса Unit и
                                                                   //определяет флаг доступа для добавляемого юнита.
{
    int accessModifier = PRIVATE; //устанавливает начальное значение модификатора доступа как PRIVATE.
    if( flags < ACCESS_MODIFIERS.size() ) { //проверяет, что значение флага находится в пределах размера вектора ACCESS_MODIFIERS.
        accessModifier = flags; //устанавливается значение модификатора доступа равным значению флага.
    }
    m_fields[ accessModifier ].push_back( unit ); // добавляет переданный юнит в соответствующий вектор в m_fields с учетом
                                                  //установленного модификатора доступа.
}

string ClassCPlus::compile( unsigned int level) const
{
    string result = generateShift( level ) + "class " + m_name + " {\n"; //формируется начало строки с объявлением класса, включая его имя.
    for( size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i ) { //Затем происходит цикл по всем модификаторам доступа из вектора ACCESS_MODIFIERS.
        if( m_fields[ i ].empty() ) {
            continue; //Если вектор полей m_fields для текущего модификатора пустой, то пропускается текущая итерация цикла.
        }
        result += ACCESS_MODIFIERS[ i ] + ":\n"; //Далее добавляется строка с текущим модификатором доступа
        for( const auto& f : m_fields[ i ] ) {
            result += f->compile( level + 1 ); //происходит вложенный цикл по всем элементам поля для текущего модификатора,
                                         //где для каждого элемента вызывается метод compile для генерации его строкового представления.
        }
        result += "\n"; //После этого добавляется пустая строка для разделения полей с разными модификаторами доступа.
    }
    result += generateShift( level ) + "};\n"; //Наконец, добавляется строка с завершением объявления класса.
    return result; //Метод возвращает сгенерированную строку, представляющую класс.
}
const vector< string > ClassCPlus::ACCESS_MODIFIERS = { "public","protected", "private" };



void ClassCSharp::add( const shared_ptr< Unit >& unit, Flags flags )
{
    int accessModifier = PRIVATE;
    if( flags < ACCESS_MODIFIERS.size() ) {
        accessModifier = flags;
    }
    m_fields[ accessModifier ].push_back( unit );
}

string ClassCSharp::compile( unsigned int level) const //Объявление метода compile класса ClassCSharp, который принимает уровень
                                                      //вложенности level и возвращает строку.
{
    string result = generateShift(level); //Создание строки result с отступами, которая будет содержать сгенерированный код класса.
    if (m_flags == PUBLIC)
    {
        result += "public ";
    }
    else if (m_flags == PROTECTED)
    {
        result += "protected ";
    }
    else if (m_flags == PRIVATE)
    {
        result += "private ";
    }
    else if (m_flags == INTERNAL)
    {
        result += "internal ";
    }
    else if (m_flags == PROTECTED_INTERNAL)
    {
        result += "protected_internal ";
    }
    else if (m_flags == PRIVATE_PROTECTED)
    {
        result += "private_protected ";
    }
    else if (m_flags == FILE)
    {
        result += "file ";
    }
    result += "class " + m_name + " {\n";

    for( size_t i = 0; i < ACCESS_MODIFIERS.size(); i++) //Цикл по всем элементам вектора модификаторов доступа ACCESS_MODIFIERS.
    {
        if( m_fields[ i ].empty() ) //Проверка, что вектор полей для текущего модификатора доступа не пустой, иначе переходим к следующей итерации цикла.
        {
            continue;
        }
        for( const auto& f : m_fields[ i ] ) //Цикл по всем полям в текущем модификаторе доступа.
        {
            result += generateShift(level + 1);
            result += ACCESS_MODIFIERS[ i ]; //добавляется модификатор доступа поля, сгенерированное представление поля
                                            //с помощью метода compile, и отступы.
            result += f->compile( level + 1 );
        }
        result += "\n"; //Добавление пустой строки для разделения полей с разными модификаторами доступа.
    }
    result += generateShift( level ) + "};\n"; //Завершение объявления класса добавлением закрывающей фигурной скобки и точки с запятой.
    return result; //Возвращение строки, представляющей сгенерированный код класса.
}
const vector< string > ClassCSharp::ACCESS_MODIFIERS = { "public","protected", "private", "internal ","protected_internal ","private_protected ","file " };


void ClassJava::add( const shared_ptr< Unit >& unit, Flags flags )
{
    int accessModifier = PRIVATE;
    if( flags < ACCESS_MODIFIERS.size() ) {
        accessModifier = flags;
    }
    m_fields[ accessModifier ].push_back( unit );
}

string ClassJava::compile( unsigned int level) const
{
    string result = generateShift(level);
    if (m_flags == PUBLIC)
    {
        result += "public ";
    }
    if (m_flags == PROTECTED)
    {
        result += "protected ";
    }
    if (m_flags == PRIVATE)
    {
        result += "private ";
    }
    if (m_flags == DEFAULT)
    {
        result += "default ";
    }
    result += "class " + m_name + " {\n";
    for( size_t i = 0; i < ACCESS_MODIFIERS.size(); i++ )
    {
        if( m_fields[ i ].empty() )
        {
            continue;
        }
        for( const auto& f : m_fields[ i ] )
        {
            result += generateShift(level + 1);
            result += ACCESS_MODIFIERS[ i ];
            result += f->compile( level + 1 );
        }
        result += "\n";
    }
    result += generateShift( level ) + "};\n";
    return result;
}
const vector< string > ClassJava::ACCESS_MODIFIERS = { "public","protected", "private", "default" };



