#ifndef ALETHEIA_G_ST_H
#define ALETHEIA_G_ST_H
/* gNNSSndSystem (arm9) */
struct St {
    unsigned int f00;
    unsigned int f04;
    unsigned char pad_8[0x4];
    unsigned int f0c;
    unsigned int f10;
    unsigned int f14;
    unsigned char pad_18[0x4];
    unsigned int f1c;
    unsigned int f20;
    unsigned int f24;
    unsigned int f28;
    signed int f2c;
    unsigned char pad_30[0xC];
    unsigned char f3c[16];
    unsigned int f4c;
    signed int f50;
};
#endif
