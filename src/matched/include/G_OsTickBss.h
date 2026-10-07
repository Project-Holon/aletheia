#ifndef ALETHEIA_G_OSTICKBSS_H
#define ALETHEIA_G_OSTICKBSS_H
/* g_02151330 (arm9) */
struct OsTickBss {
    unsigned short OSi_UseTick;
    unsigned char pad_2[0x2];
    int OSi_NeedResetTimer;
    unsigned long long OSi_TickCounter;
};
#endif
