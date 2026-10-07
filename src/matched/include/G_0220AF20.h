#ifndef ALETHEIA_G_0220AF20_H
#define ALETHEIA_G_0220AF20_H
/* g_0220AF20 (arm9) */
struct G_0220AF20 {
    void *owner;
    void *buf;
    unsigned char pad_8[0x180];
    void *h188;
    int h18c;
    void *h190;
    void *h194;
    void *h198;
    void *h19c;
    void *h1a0;
    void *h1a4;
    unsigned char pad_1A8[0x8];
    void *h1b0;
    void *h1b4;
    void *h1b8;
    int param_f0;
    int param_f4;
    int param_f8;
    int param_fc;
    unsigned char param_f10;
    unsigned char param_f11;
    unsigned short param_f12;
    unsigned char param_f14;
    unsigned char param_f15;
    unsigned char pad_1D2[0x12];
    void *param_battle;
    int f1e8;
    unsigned char pad_1EC[0x4];
    unsigned short heap;
    unsigned char pad_1F2[0x6];
    int slots[8];
    unsigned char pad_218[0x2C];
    int f244;
    int f248;
};
#endif
