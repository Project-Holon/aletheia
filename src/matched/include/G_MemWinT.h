#ifndef ALETHEIA_G_MEMWINT_H
#define ALETHEIA_G_MEMWINT_H
/* g_021DE658 (arm9) */
struct MemWinT {
    void *cellWin;
    void *cellChar;
    void *button[2];
    void *canv;
    void *task;
    unsigned short countWait;
    signed char count;
    signed char input;
    unsigned char type;
    unsigned char wait;
    unsigned char dark;
};
#endif
