#ifndef CTIMECONTROLLER_H
#define CTIMECONTROLLER_H

#include <boost/shared_ptr.hpp>
#include <QTime>

namespace SD
{
    namespace Logic
    {
        class CTimeController
        {
        public:
            CTimeController();
            ~CTimeController();

        public:
            /// \brief option of shutdown command
            enum ShutdownOption
            {
                eRestart,
                eShutdown,

                eNull
            };

            /// \brief Set which shutdown command to use
            /// \param[in] ShutdownOption; type of shutdown command
            void SetOption( ShutdownOption so );

            /// \brief Set time to counting
            /// \param[in] hour, number of hours to count
            /// \param[in] minutes, number of minutes to count
            void SetTime( int hour, int minutes );

            /// \brief Start counting
            void StartCounting();

            QTime GetSuspendTime(); // const;
            void SetSetSuspendTime( int suspendTime );

        private:
            ShutdownOption m_shutdownOption;    // option od shutdown command
            int m_suspendTime;  // time of suspend before shutdown command

        private:
            boost::shared_ptr< CSystemControl > m_pSystemControl;
            QTime m_time;
            int m_hours;
            int m_minutes;
        };
    }
}

#endif // CTIMECONTROLLER_H
