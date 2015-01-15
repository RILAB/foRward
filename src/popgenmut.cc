#include <foRward/popgenmut.hpp>
#include <iostream>

namespace foRward {

  popgenMutWriter::result_type popgenMutWriter::operator()( const popgenmut & m, std::ostream & buffer ) const
  {
    buffer.write( reinterpret_cast< const char * >(&m.s), sizeof(double) );
    buffer.write( reinterpret_cast< const char * >(&m.h), sizeof(double) );
    buffer.write( reinterpret_cast< const char * >(&m.o), sizeof(unsigned) );
    buffer.write( reinterpret_cast< const char * >(&m.pos), sizeof(double) );
    buffer.write( reinterpret_cast< const char * >(&m.n), sizeof(unsigned) );
    buffer.write( reinterpret_cast< const char * >(&m.neutral), sizeof(bool) );
  }


  popgenMutReader::result_type popgenMutReader::operator()( std::istream & buffer ) const
  {
    double s,h,pos;
    unsigned o,n;
    bool neutral;
    buffer.read( reinterpret_cast< char * >(&s), sizeof(double) );
    buffer.read( reinterpret_cast< char * >(&h), sizeof(double) );
    buffer.read( reinterpret_cast< char * >(&o), sizeof(unsigned) );
    buffer.read( reinterpret_cast< char * >(&pos), sizeof(double) );
    buffer.read( reinterpret_cast< char * >(&n), sizeof(unsigned) );
    buffer.read( reinterpret_cast< char * >(&neutral), sizeof(bool) );
    return result_type(pos,n,neutral,s,h,o);
  }
}
