#include <QTime>
#include "ctimecontroller.h"
#include "ccounter.h"

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
            assert( hour > 0 || minutes > 0 );
            this->m_time = QTime( hour, minutes );
            m_suspendTime = m_time.hour() * 60 + m_time.minute();
            m_suspendTime *= 60; // suspend time is counting in seconds
        }

        void CTimeController::StartCounting()
        {
            CCounter cCounter( QTime( m_hours, m_minutes ) );
            cCounter.setModal( true );
            cCounter.exec();
        }

        QTime CTimeController::suspendTime()// const
        {
            return m_time;
        }
        void CTimeController::setSuspendTime(int suspendTime)
        {
            m_suspendTime = suspendTime;
        }

    }
}
