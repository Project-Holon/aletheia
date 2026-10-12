#ifndef OV136_TYPES_H
#define OV136_TYPES_H

struct MbSeqCtx;
struct MailViewCtx_f1C;
struct MailViewCtx;
struct MbUnitBCtx;
struct MbSeqCtx_f10;
struct MbSeqCtx_f4;
struct MailViewCtx_f10;

struct MbSeqCtx {
    void *f0;
    void *f4;
    void *f8;
    unsigned short fC;
    unsigned char fE;
    unsigned char fF;
    void *f10;
    void *f14;
    unsigned int f18;
    unsigned short f1C;
    unsigned char f1E;
    unsigned char f1F;
    unsigned char f20;
    unsigned char pad_21[1];
    unsigned short f22;
    int f24;
    unsigned int f28;
    void *f2C;
    void *f30;
    int f34;
    int f38;
    unsigned char pad_3C[8];
    unsigned short f44;
    unsigned char pad_46[22];
    unsigned short f5C;
};

struct MailViewCtx_f1C {
    unsigned short f0;
    unsigned char f2;
    unsigned char f3;
    unsigned int f4;
    unsigned char pad_8[1];
    unsigned char f9;
    unsigned char fA;
    unsigned char fB;
    void *fC;
    unsigned char pad_10[4];
    void *f14;
    unsigned char pad_18[26];
    unsigned short f32;
};

struct MailViewCtx {
    unsigned int f0;
    unsigned int f4;
    unsigned short f8;
    unsigned char fA;
    unsigned char fB;
    unsigned char fC;
    unsigned char pad_D[3];
    void *f10;
    unsigned char pad_14[1];
    signed char f15;
    unsigned char f16;
    unsigned char f17;
    unsigned char f18;
    unsigned char f19;
    unsigned char f1A;
    unsigned char f1B;
    void *f1C;
    void *f20;
    void *f24;
    unsigned char pad_28[10];
    unsigned short f32;
    void *f34;
    void *f38;
    void *f3C;
    void *f40;
    unsigned char pad_44[16];
    unsigned int f54;
    unsigned int f58;
    void *f5C;
    unsigned char pad_60[40];
    unsigned int f88;
    unsigned char f8C;
    unsigned char pad_8D[11];
    void *f98;
    void *f9C;
    void *fA0;
    unsigned char pad_A4[80];
    void *fF4;
    void *fF8;
    void *fFC;
    void *f100;
    void *f104;
    void *f108;
    void *f10C;
    void *f110;
    unsigned short f114;
    unsigned char pad_116[2];
    unsigned int f118;
    void *f11C;
    unsigned short f120;
    unsigned char pad_122[2];
    unsigned int f124;
    void *f128;
    void *f12C;
    void *f130;
    unsigned short f134;
    unsigned char pad_136[2];
    unsigned int f138;
    void *f13C;
    unsigned short f140;
    unsigned char pad_142[2];
    unsigned int f144;
    void *f148;
    unsigned short f14C;
    unsigned short f14E;
    unsigned short f150;
    unsigned char pad_152[2];
    void *f154;
    void *f158;
};

struct MbUnitBCtx {
    unsigned char pad_0[68];
    void *f44;
    void *f48;
    unsigned char pad_4C[92];
    void *fA8;
    void *fAC;
    unsigned char pad_B0[12];
    void *fBC;
    void *fC0;
    unsigned char pad_C4[256];
    void *f1C4;
    void *f1C8;
    void *f1CC;
    void *f1D0;
    void *f1D4;
    void *f1D8;
    unsigned char pad_1DC[1];
    unsigned char f1DD;
    unsigned char pad_1DE[2];
    unsigned int f1E0;
    unsigned char pad_1E4[8];
    void *f1EC;
    unsigned char pad_1F0[12];
    void *f1FC;
    unsigned char pad_200[12];
    void *f20C;
    unsigned char pad_210[32];
    void *f230;
    unsigned char pad_234[28];
    void *f250;
    unsigned char pad_254[60];
    void *f290;
    void *f294;
    unsigned char pad_298[100];
    unsigned short f2FC;
    unsigned short f2FE;
    unsigned char pad_300[8];
    unsigned int f308;
    void *f30C;
    void *f310;
    unsigned char pad_314[48];
    void *f344;
    unsigned char pad_348[8];
    void *f350;
    unsigned char pad_354[8];
    void *f35C;
    unsigned short f360;
    unsigned short f362;
    unsigned short f364;
    unsigned char pad_366[2];
    void *f368;
    void *f36C;
};

struct MbSeqCtx_f10 {
    unsigned char pad_0[60];
    unsigned int f3C;
};

struct MbSeqCtx_f4 {
    unsigned char pad_0[4];
    unsigned int f4;
};

struct MailViewCtx_f10 {
    unsigned short f0;
};

#endif
