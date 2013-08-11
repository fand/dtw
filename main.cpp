// main.cpp
// 2012/11/26
// fand

#include <iostream>
#include <time.h>
#include <sys/time.h>

#include "watch.hpp"
#include "dtw.hpp"


int main( int argc, char** argv )
{
    if( argc != 3 )
    {
        std::cout << "argc error!" << std::endl;
        return -1;
    }

    Dtw< long > dtw( argv[1], argv[2] );

    Watch watch;

    watch.start();
    dtw.calcDtw();
    watch.stop();

    std::cout << "DTW : " << dtw.getResult() << std::endl;
    std::cout << "computation time : " << watch.getInterval() << " sec" << std::endl;
    
    return 0;
}
