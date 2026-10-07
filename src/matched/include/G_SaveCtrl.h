#ifndef ALETHEIA_G_SAVECTRL_H
#define ALETHEIA_G_SAVECTRL_H
/* sub_02006F20_Ptr (arm9) */
struct SaveCtrl {
    unsigned char unk00;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    unsigned char unk04;
    unsigned char unk05;
    unsigned char pad_6[0x6];
    unsigned int unk0C;
    void *unk10;
    void *unk14[9];
};
#endif
