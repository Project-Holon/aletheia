#ifndef ALETHEIA_G_CONN_H
#define ALETHEIA_G_CONN_H
/* g_021CF984 (arm9) */
struct Conn {
    unsigned char pad_0[0x10];
    void *f10;
    void *f14;
    unsigned char pad_18[0x8];
    struct Conn *next;
};
#endif
