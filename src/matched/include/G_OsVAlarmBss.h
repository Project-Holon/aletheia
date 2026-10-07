#ifndef ALETHEIA_G_OSVALARMBSS_H
#define ALETHEIA_G_OSVALARMBSS_H
/* g_0215134C (arm9) */
struct OsVAlarmBss {
    unsigned short OSi_UseVAlarm;
    unsigned char pad_2[0x2];
    signed int OSi_PreviousVCount;
    signed int OSi_VFrameCount;
    void *OSi_VAlarmQueue_head;
    void *OSi_VAlarmQueue_tail;
};
#endif
