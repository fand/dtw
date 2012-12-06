// FastDtw.hpp

#pragma once

#include "dtw.hpp"


template < class T >
class FastDtw : public Dtw< T >{

public:
    FastDtw( const char *path_1, const char *path_2 );
    virtual ~FastDtw();

    void calcDtw();
};

