#ifndef UNIT_H
#define UNIT_H
#include <iostream>
#include <string>
#include <memory>
#include <vector>
using namespace std;

class Unit {

public:

    using Flags = unsigned int;

public:
    virtual ~Unit() = default;
    virtual void add( const shared_ptr< Unit >& , Flags ); //Виртуальный метод add, принимающий умный указатель на объект класса Unit и
                                                          //флаги типа Flags
    virtual string compile( unsigned int level = 0 ) const = 0;
//Чисто виртуальный метод compile, который должен быть реализован в производных классах. Принимает уровень вложенности (по умолчанию 0)
//и возвращает строку.

protected:
    virtual string generateShift( unsigned int level ) const;
//метод generateShift, который генерирует отступы для форматирования вывода. Принимает уровень вложенности и возвращает строку.
};

#endif // UNIT_H
