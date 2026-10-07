#ifndef ALETHEIA_G_OSALARMBSS_H
#define ALETHEIA_G_OSALARMBSS_H
/* g_02151340 (arm9) */
struct OsAlarmBss {
    unsigned short OSi_UseAlarm;
    unsigned char pad_2[0x2];
    void *OSi_AlarmQueue_head;
    void *OSi_AlarmQueue_tail;
};
#endif
