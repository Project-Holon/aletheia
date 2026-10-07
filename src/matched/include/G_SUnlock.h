#ifndef ALETHEIA_G_SUNLOCK_H
#define ALETHEIA_G_SUNLOCK_H
/* g_021F6EF4 (arm9) */
struct SUnlock {
    unsigned char pad_0[0x10];
    unsigned int unk10;
    void (*unk14)();
    void *list;
    void *p1c;
    unsigned char pad_20[0x4];
    unsigned char unk24;
    unsigned char pad25;
    unsigned char unk26;
    unsigned char pad_27[0x2];
    unsigned char unk29;
};
#endif
