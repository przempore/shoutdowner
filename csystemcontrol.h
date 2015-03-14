#ifndef CSYSTEMCONTROL_H
#define CSYSTEMCONTROL_H


namespace SD
{
    namespace Logic
    {
        class CSystemControl
        {
        public:
            CSystemControl();
            ~CSystemControl();

        public:
            /// \brief Start counting time of suspend
            /// \param [in] time; time to count
            void StartCounting( int time );
        };
    }
}
#endif // CSYSTEMCONTROL_H
