#ifndef CLASSESLANG_H
#define CLASSESLANG_H
#include <classunit.h>

class ClassJava : public ClassUnit
{
public:
    enum AccessModifier { //определяет набор различных модификаторов доступа для полей класса.
        PUBLIC,
        PROTECTED,
        PRIVATE,
        DEFAULT
    };
    static const vector< string > ACCESS_MODIFIERS; //хранит список строковых представлений модификаторов доступа.
public:

    explicit ClassJava( const string& name ) : ClassUnit(name),m_name( name ) {
        m_fields.resize( ACCESS_MODIFIERS.size() ); //инициализирует объект класса с заданным именем и создает вектор полей для каждого модификатора доступа.
    }
    void add( const shared_ptr< Unit >& unit, Flags flags ); // добавляет новое поле в класс с указанными флагами.
    string compile( unsigned int level = 0 ) const; //компилирует информацию о классе в строку с учетом уровня вложенности.
protected:

    string m_name; // хранит имя класса.
    using Fields = vector< shared_ptr< Unit > >; //определяет вектор указателей на объекты типа Unit
    vector< Fields > m_fields; //хранит поля класса в виде вектора по модификаторам доступа.

};

class ClassCSharp : public ClassUnit
{
public:
    enum AccessModifier {
        PUBLIC,
        PROTECTED,
        PRIVATE,
        INTERNAL,
        PROTECTED_INTERNAL,
        PRIVATE_PROTECTED,
        FILE

    };
    static const vector< string > ACCESS_MODIFIERS; //объявления статической переменной класса. Переменная ACCESS_MODIFIERS будет
                                                    //общей для всех экземпляров класса, и она будет инициализирована один раз при загрузке программы.
public:

    explicit ClassCSharp( const string& name ) : ClassUnit(name),m_name( name ) {
        m_fields.resize( ACCESS_MODIFIERS.size() ); // explicit предотвращает неявные преобразования типов при создании объектов.
    }                                               // вызов метода resize() для вектора m_fields, который устанавливается равным размеру
                                                    //вектора ACCESS_MODIFIERS.
    void add( const shared_ptr< Unit >& unit, Flags flags );
    string compile( unsigned int level = 0 ) const;
protected:

    string m_name;
    using Fields = vector< shared_ptr< Unit > >;
    vector< Fields > m_fields;

};

class ClassCPlus : public ClassUnit
{
public:
    enum AccessModifier {
        PUBLIC,
        PROTECTED,
        PRIVATE
    };
    static const vector< string > ACCESS_MODIFIERS;
public:

    explicit ClassCPlus( const string& name ) : ClassUnit(name),m_name( name ) {
        m_fields.resize( ACCESS_MODIFIERS.size() );
    }
    void add( const shared_ptr< Unit >& unit, Flags flags );
    string compile( unsigned int level = 0 ) const;
protected:

    string m_name;
    using Fields = vector< shared_ptr< Unit > >;
    vector< Fields > m_fields;
};


#endif // CLASSESLANG_H
