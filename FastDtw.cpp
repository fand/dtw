// FastDtw.cpp

#include <iostream>
#include "FastDtw.hpp"



template < class T >
FastDtw< T >::FastDtw( const char *path_1, const char *path_2 ) : Dtw< T >( path_1, path_2 )
{
    // なにもしない
}


template < class T >
FastDtw< T >::~FastDtw()
{
    // FastDtw だけで使う object を delete
    
}



template < class T >
void FastDtw< T >::calcDtw()
{    
    Dtw< T >::calcDtw();
    
}




//
// テンプレート実装コードの生成
//

template class FastDtw< int >;
template class FastDtw< long >;
template class FastDtw< double >;
template class FastDtw< long double >;
