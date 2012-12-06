// file.cpp
// 2012/11/26
// fand

#include <iostream>
#include <time.h>
#include <sys/time.h>

#include "watch.hpp"
#include "FastDtw.hpp"


int main( int argc, char** argv )
{
    if( argc != 3 )
    {
        std::cout << "argc error!" << std::endl;
        return -1;
    }

    FastDtw< long > dtw( argv[1], argv[2] );

    
    Watch watch;    // Watch watch()としてはいけない

    watch.start();
    dtw.calcDtw();
    watch.stop();
    
    std::cout << "DTW : " << dtw.getResult() << std::endl;
    std::cout << "計算時間 : " << watch.getInterval() << " sec" << std::endl;
    
    return 0;
}
