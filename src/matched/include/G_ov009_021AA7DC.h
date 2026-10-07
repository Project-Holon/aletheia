#ifndef ALETHEIA_G_OV009_021AA7DC_H
#define ALETHEIA_G_OV009_021AA7DC_H
/* g_021AA7DC (ov009) */
struct G_ov009_021AA7DC {
    unsigned char inited;
    unsigned char pad_1[0x3];
    long field4;
    long field8;
    unsigned char mutex[24];
    unsigned short field24;
    unsigned char pad_26[0x2];
    void (*recvCb)(unsigned char *, unsigned char *, unsigned char *, long);
};
#endif
