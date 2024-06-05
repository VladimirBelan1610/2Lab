#include "classesmethod.h"

void CPlusMethod::add( const shared_ptr< Unit >& unit, Flags /* flags */  )
{
    m_body.push_back( unit );
}

string CPlusMethod::compile( unsigned int level ) const {
    string result = generateShift( level );
    if( m_flags & STATIC ) {
        result += "static ";
    } else if( m_flags & VIRTUAL ) {
        result += "virtual ";
    }
    result += m_returnType + " ";
    result += m_name + "()";
    if( m_flags & CONST ) {
        result += " const";
    }
    result += " {\n";
    for( const auto& b : m_body ) {
        result += b->compile( level + 1 );
    }
    result += generateShift( level ) + "}\n";
    return result;
}

void CSharpMethod::add( const shared_ptr< Unit >& unit, Flags /* flags */  )
{
    m_body.push_back( unit );
}

string CSharpMethod::compile( unsigned int level ) const {
    string result = generateShift( level );
    if( m_flags & STATIC ) {
        result += "static ";
    } else if( m_flags & VIRTUAL ) {
        result += "virtual ";
    }
    result += m_returnType + " ";
    result += m_name + "()";
    if( m_flags & CONST ) {
        result += " const";
    }
    result += " {\n";
    for( const auto& b : m_body ) {
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
    if( m_flags & STATIC ) {
        result += "static ";
    } else if( m_flags & VIRTUAL ) {
        result += "virtual ";
    }
    result += m_returnType + " ";
    result += m_name + "()";
    if( m_flags & CONST ) {
        result += " const";
    }
    result += " {\n";
    for( const auto& b : m_body ) {
        result += b->compile( level + 1 );
    }
    result += generateShift( level ) + "}\n";
    return result;
}
