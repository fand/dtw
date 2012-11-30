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
Dtw< T >::Dtw(){}


template < class T >
Dtw< T >::~Dtw(){
    this->deleteTable( this->table_d );
    this->deleteTable( this->table_g );
}


template < class T >
void Dtw< T >::readFile( std::vector< T > *dst, const char* path )
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
        dst->push_back( temp );
    }

}


template < class T >
void Dtw< T >::readTwoFiles( const char *path_1, const char *path_2 )
{
    this->readFile( &( this->seq_1 ), path_1 );
    this->readFile( &( this->seq_2 ), path_2 );

    this->len_1 = this->seq_1.size();
    this->len_2 = this->seq_2.size();

    this->initTables();
}


template < class T >
inline void Dtw< T >::initTables()
{
    this->table_d = this->createTable( this->len_1, this->len_2 );
    this->table_g = this->createTable( this->len_1, this->len_2 );
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
void Dtw< T >::calcDistance()
{
    for( int i = 0; i< this->len_1; i++ )
    {
        for( int j = 0; j < this->len_2; j++ )
        {
            this->table_d[i][j] = fabs( this->seq_1.at(i) - this->seq_2.at(j) );
        }
    }
}


template < class T >
void Dtw< T >::calcGamma()
{
    this->table_g[0][0] = this->table_d[0][0];
        
    for( int i = 1; i < this->len_1; i++){
        this->table_g[i][0] = this->table_d[i][0] + this->table_g[i-1][0];
    }

    for( int i = 1; i < this->len_2; i++){
        this->table_g[0][i] = this->table_d[0][i] + this->table_g[0][i-1];
    }

    for( int i = 1; i< this->len_1; i++ )
    {
        for( int j = 1; j < this->len_2; j++ )
        {
            this->table_g[i][j] = this->table_d[i][j] + std::min( std::min( this->table_g[i-1][j], this->table_g[i][j-1] ), this->table_g[i-1][j-1] );
        }
    }

    this->result = this->table_g[ this->len_1 - 1 ][ this->len_2 - 1 ];
}


template < class T >
void Dtw< T >::calcDtw()
{
    this->calcDistance();
    this->calcGamma();
}


template < class T >
T Dtw< T >::getResult()
{
    return this->result;
}




//
// テンプレート実装コードの生成
//

template class Dtw< int >;
template class Dtw< double >;
template class Dtw< float >;
template class Dtw< long >;
