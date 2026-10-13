#ifndef ALETHEIA_G_SYS_H
#define ALETHEIA_G_SYS_H
/* _pNetState (arm9) */
struct Sys {
    unsigned char pad_0[0x8];
    void (*cb)(unsigned int);
    unsigned char pad_C[0x3A];
    unsigned short f46;
    signed char flag;
    unsigned char pad_49[0x1];
    unsigned char f4a;
};
#endif
