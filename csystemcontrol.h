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
            void StartCounting( int time );
        };
    }
}
#endif // CSYSTEMCONTROL_H
