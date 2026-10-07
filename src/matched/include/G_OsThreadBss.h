#ifndef ALETHEIA_G_OSTHREADBSS_H
#define ALETHEIA_G_OSTHREADBSS_H
/* g_02150FD0 (arm9) */
struct OsThreadBss {
    void *OSi_SystemCallbackInSwitchThread;
    unsigned int OSi_RescheduleCount;
    void *OSi_CurrentThreadPtr;
    unsigned int other[4];
    unsigned short OSi_ThreadInfo_isNeedRescheduling;
    unsigned short OSi_ThreadInfo_irqDepth;
    void *OSi_ThreadInfo_current;
    void *OSi_ThreadInfo_list;
    void *OSi_ThreadInfo_switchCallback;
};
#endif
