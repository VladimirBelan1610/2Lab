#include "classesmethod.h"

void CPlusMethod::add( const shared_ptr< Unit >& unit, Flags /* flags */  ) //Метод принимает два аргумента: unit, который является
                                                //умным указателем на объект типа Unit, и flags, который не используется внутри метода.
{
    m_body.push_back( unit ); //объект, переданный в качестве аргумента unit, добавляется в конец вектора m_body, который, содержит
                             //другие объекты типа Unit.
}

string CPlusMethod::compile( unsigned int level ) const { //Метод принимает один аргумент типа unsigned int с именем level и возвращает строку.
    string result = generateShift( level ); //Создается строковая переменная result, которая инициализируется результатом вызова функции
                                           //generateShift(level). Эта функция генерирует отступы в зависимости от уровня level.
    if( m_flags & STATIC ) {
        result += "static ";
    } else if( m_flags & VIRTUAL ) {
        result += "virtual ";
    }
    result += m_returnType + " "; //Добавляется строковое представление типа возвращаемого значения (m_returnType)
    result += m_name + "()"; //и название метода (m_name).
    if( m_flags & CONST ) {
        result += " const";
    }
    result += " {\n"; //Добавляется открывающая фигурная скобка для начала тела метода.
    for( const auto& b : m_body ) {
        result += b->compile( level + 1 ); //Для каждого элемента вызывается метод compile(level + 1),
                                          //который добавляет результат компиляции элемента с увеличением уровня на 1 к строке result.
    }
    result += generateShift( level ) + "}\n"; //Добавляются отступы и закрывающая фигурная скобка для завершения тела метода.
    return result;
}

void CSharpMethod::add( const shared_ptr< Unit >& unit, Flags /* flags */  )
{
    m_body.push_back( unit );
}

string CSharpMethod::compile( unsigned int level ) const {
    string result = generateShift( level );

    if( m_flags & STATIC )
    {
        result += "static ";
    }
    else if( m_flags & VIRTUAL )
    {
        result += "virtual ";
    }
    else if( m_flags & OVERRIDE)
    {
        result += "override ";
    }
    result += m_returnType + " ";
    result += m_name + "()";
    result += " {\n";
    for( const auto& b : m_body )
    {
        result += b->compile( level + 1 );
    }
    result += generateShift( level ) + "}\n";
    return result;
}


void JavaMethod::add( const shared_ptr< Unit >& unit, Flags /* flags */  )
{
    m_body.push_back( unit );
}

string JavaMethod::compile( unsigned int level ) const {
    string result = generateShift( level );
    if( m_flags & STATIC )
    {
        result += "static ";
    }
    if( m_flags & FINAL )
    {
        result += "final ";
    }
    result += m_returnType + " ";
    result += m_name + "()";
    result += " {\n";
    for( const auto& b : m_body )
    {
        result += b->compile( level + 1 );
    }
    result += generateShift( level ) + "}\n";
    return result;
}
