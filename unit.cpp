#include <unit.h>

string Unit::generateShift(unsigned int level ) const //возвращает строку, представляющую отступ (пробелы), основываясь на уровне level,
                                                     //переданном в качестве аргумента.
{
    static const auto DEFAULT_SHIFT = " "; //Внутри функции определена статическая константа DEFAULT_SHIFT, которая равна одному пробелу.
    string result; //Затем создается пустая строка result, в которую будут добавляться пробелы.
    for( unsigned int i = 0; i < level; i++ ) {
        result += DEFAULT_SHIFT; //С помощью цикла for добавляются пробелы в строку result столько раз, сколько указано в переменной level.
    }
    return result; //Строка result возвращается как результат выполнения функции.
}

void Unit::add( const shared_ptr< Unit >& , Flags ) //Это метод класса Unit, который принимает два аргумента: указатель на объект типа
                                                   //Unit и флаги типа Flags.
{
    throw runtime_error( "Not supported" ); //вызывает исключение
}
