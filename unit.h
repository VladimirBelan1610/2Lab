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
    virtual void add( const shared_ptr< Unit >& , Flags );
    virtual string compile( unsigned int level = 0 ) const = 0;

protected:
    virtual string generateShift( unsigned int level ) const;

};

#endif // UNIT_H
