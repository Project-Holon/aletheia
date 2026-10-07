#ifndef ALETHEIA_G_LINKSTATE_H
#define ALETHEIA_G_LINKSTATE_H
/* g_021469D0 (arm9) */
struct LinkState {
    void *f0;
    unsigned int *f04;
    unsigned char *f08;
    unsigned char *f0C;
    unsigned char *f10;
    unsigned char *f14;
    void *f18;
    unsigned char pad_1C[0xB0];
    char obj_CC;
    unsigned char pad_CD[0x27];
    char obj_F4;
    unsigned char pad_F5[0xB7];
    unsigned int f1AC;
    unsigned int f1B0;
    unsigned int f1b4;
    unsigned int f1b8;
    unsigned char pad_1BC[0x19];
    unsigned char f1D5;
    unsigned char pad_1D6[0x1];
    unsigned char f1D7[8];
    unsigned char pad_1DF[0x1];
    unsigned int f1E0;
    unsigned char pad_1E4[0x3];
    unsigned char unk_1e7;
    unsigned char pad1e8;
    unsigned char unk_1e9;
    unsigned char unk_1ea;
    unsigned char unk_1eb;
};
#endif
