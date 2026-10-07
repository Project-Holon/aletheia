#ifndef ALETHEIA_G_CONSOLE_H
#define ALETHEIA_G_CONSOLE_H
/* g_021469AC (arm9) */
struct Console {
    void *chars;
    unsigned short x;
    unsigned short y;
    unsigned char unk8;
    unsigned char unk9;
    unsigned char fg;
    unsigned char bg;
    unsigned char unkB;
};
#endif
