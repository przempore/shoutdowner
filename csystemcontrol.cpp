#include <cstdlib>
#include <iostream>
#include "csystemcontrol.h"

namespace SD
{
    namespace Logic
    {
        CSystemControl::CSystemControl()
        {}

        CSystemControl::~CSystemControl()
        {}

        void CSystemControl::StartCounting(int time)
        {
           system( "timeout /t " + time );
           std::cout << "Koniec!!!\n";
        }
    }
}
