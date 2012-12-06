// dtw.hpp
// 2012/11/26
// fand

#pragma once

#include <vector>

template < class T >
class Dtw{

private:
    std::vector< T > seq_1, seq_2;
    int len_1, len_2;
    T **table_d, **table_g;
    T result;
    
public:
    Dtw( const char *path_1, const char *path_2 );
    virtual ~Dtw();

    void readFile( std::vector< T > &dst, const char *path );

    T** createTable( int n, int m );
    void deleteTable( T **p );
    
    void calcDtw();
    void calcDistance( T **table, const std::vector< T > &seq_1, const std::vector< T > &seq_2 );
    void calcGamma( T **table_d, T **table_g );
    
    T getResult();

    void printseq( int n, int start, int end );
    void printlen();
};

