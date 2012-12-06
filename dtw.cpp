// dtw.cpp
// 2012/11/26
// fand

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>

#include "dtw.hpp"


template < class T >
Dtw< T >::Dtw( const char *path_1, const char *path_2 )
{
    this->readFile( this->seq_1, path_1 );
    this->readFile( this->seq_2, path_2 );

    this->len_1 = this->seq_1.size();
    this->len_2 = this->seq_2.size();

    this->table_d = this->createTable( this->len_1, this->len_2 );
    this->table_g = this->createTable( this->len_1, this->len_2 );
}


template < class T >
Dtw< T >::~Dtw()
{
    this->deleteTable( this->table_d );
    this->deleteTable( this->table_g );
}


template < class T >
void Dtw< T >::readFile( std::vector< T > &dst, const char* path )
{
    std::ifstream fs( path );
    T temp;

    if( !fs )
    {
        std::cout << "Error: cannot open file(" << path << ")" << std::endl;
        exit(1);
    }
    
    while( fs >> temp )
    {
        dst.push_back( temp );
    }
}


template < class T >
T** Dtw< T >::createTable( int n, int m )
{
    T** p = new T* [ n ];

    for(int i = 0; i < n; i++ )
    {
        p[i] = new T[ m ];
    }

    return p;
}


template < class T >
void Dtw< T >::deleteTable( T **p )
{
    for(int i = 0; i < this->len_1; i++ )
    {
        delete[] p[i];        
    }

    delete[] p;
}


template < class T >
void Dtw< T >::calcDistance( T **table, const std::vector< T > &seq_1, const std::vector< T > &seq_2 )
{
    for( int i = 0; i< this->len_1; i++ )
    {
        for( int j = 0; j < this->len_2; j++ )
        {
            table[i][j] = fabs( seq_1.at(i) - seq_2.at(j) );
        }
    }
}


template < class T >
void Dtw< T >::calcGamma( T **table_d, T **table_g )
{
    table_g[0][0] = table_d[0][0];
        
    for( int i = 1; i < this->len_1; i++){
        table_g[i][0] = table_d[i][0] + table_g[i-1][0];
    }

    for( int i = 1; i < this->len_2; i++){
        table_g[0][i] = table_d[0][i] + table_g[0][i-1];
    }

    for( int i = 1; i< this->len_1; i++ )
    {
        for( int j = 1; j < this->len_2; j++ )
        {
            table_g[i][j] = table_d[i][j] + std::min( std::min( table_g[i-1][j], table_g[i][j-1] ), table_g[i-1][j-1] );
        }
    }
}


template < class T >
void Dtw< T >::calcDtw()
{
    this->calcDistance( this->table_d, this->seq_1, this->seq_2 );
    this->calcGamma( this-> table_d, this->table_g );
    
    this->result = this->table_g[ this->len_1 - 1 ][ this->len_2 - 1 ];
}


template < class T >
T Dtw< T >::getResult()
{
    return this->result;
}


template < class T >
void Dtw< T >::printseq(int n, int start, int end)
{
    if(n == 1)
    {
        for(int i=start;i<end;i++)
        {
            std::cout << this->seq_1.at(i) << std::endl;
        }
    }
    
    if(n == 2)
    {
        for(int i=start;i<end;i++)
        {
            std::cout << this->seq_2.at(i) << std::endl;
        }
    }
    
}


template < class T >
void Dtw< T >::printlen()
{
    std::cout << "seq1: " << this->seq_1.size() << std::endl;
    std::cout << "seq2: " << this->seq_2.size() << std::endl;
}



//
// テンプレート実装コードの生成
//

template class Dtw< int >;
template class Dtw< long >;
template class Dtw< double >;
template class Dtw< long double >;

