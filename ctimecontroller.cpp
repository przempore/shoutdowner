#include "ctimecontroller.h"

namespace SD
{
    namespace Logic
    {
        CTimeController::CTimeController() : m_shutdownOption( eNull )
        {
            m_pSystemControl.reset( new CSystemControl() );
            assert( m_pSystemControl );
        }

        CTimeController::~CTimeController()
        {}

        void CTimeController::SetOption( CTimeController::ShutdownOption so )
        {
            this->m_shutdownOption = so;
        }

        void CTimeController::SetTime( int hour, int minutes )
        {
            assert( hour < 0 || minutes < 0 );
            m_suspendTime = hour * 60 + minutes;
            m_suspendTime *= 60; // suspend time is counting in seconds
        }

        void CTimeController::StartCounting()
        {
            m_pSystemControl->StartCounting( m_suspendTime );
        }
    }
}
