#ifndef STA_OAM_TYPES_H
#define STA_OAM_TYPES_H

/* Objects of the Pokemon status screen sprite code (ov131), one struct per object. */

struct StaOam {
    unsigned short f0;
    unsigned char pad_2[2];
    void * f4;
    void * f8;
    int fC;
    int f10;
    int f14;
    unsigned short f18;
    unsigned char f1A;
    unsigned char f1B;
    unsigned char f1C;
    unsigned char pad_1D[3];
    unsigned int f20;
    int f24;
    unsigned int f28;
    unsigned int f2C;
    unsigned int f30;
    unsigned int f34;
    unsigned int f38;
    unsigned int f3C;
    int f40;
    int f44;
    int f48;
    int f4C;
    int f50;
    int f54;
    int f58;
    unsigned int f5C;
    unsigned char pad_60[16];
    void * f70;
    unsigned char pad_74[4];
    void * f78;
    void * f7C;
    void * f80;
    void * f84;
    void * f88;
    void * f8C;
    void * f90;
    void * f94;
    unsigned int f98;
    unsigned int f9C;
    unsigned int fA0;
    unsigned int fA4;
    unsigned int fA8;
    unsigned int fAC;
    void * fB0;
    unsigned int fB4;
    void * fB8;
    unsigned int fBC;
    unsigned int fC0;
    unsigned int fC4;
    unsigned int fC8;
    unsigned int fCC;
    unsigned int fD0;
    unsigned int fD4;
    unsigned int fD8;
    unsigned char pad_DC[8];
    unsigned int fE4;
    void * fE8;
    unsigned int fEC;
    unsigned int fF0;
    unsigned int fF4;
    unsigned int fF8;
    unsigned int fFC;
    unsigned int f100;
    unsigned int f104;
    unsigned int f108;
    void * f10C;
    unsigned char pad_110[4];
    unsigned int f114;
    void * f118;
    unsigned int f11C;
    unsigned int f120;
    unsigned int f124;
    unsigned int f128;
    unsigned int f12C;
    unsigned int f130;
    unsigned char pad_134[64];
    void * bank;
    void * actors[8];
    void * f198;
    void * f19C;
    void * f1A0;
    unsigned short ang;
    unsigned short x4[4];
    unsigned short pal4[4];
    unsigned short a16[16];
    unsigned short b16[16];
    unsigned short o16[16];
    unsigned short o3[16];
    unsigned short i3[16];
    unsigned char pad_256[2];
    void * f258;
    unsigned int f25C;
    unsigned char f260;
};

struct StaOamSub88 {
    void * f0;
    void * f4;
    unsigned int f8;
    unsigned int fC;
    int f10;
    int f14;
    void * f18;
    void * f1C;
    void * f20;
    unsigned char pad_24[24];
    void * f3C;
    void * f40;
    void * f44;
    void * f48;
    int f4C;
    int f50;
    int f54;
    unsigned int f58;
    unsigned int f5C;
    unsigned short f60;
    unsigned short f62;
    unsigned short f64;
    unsigned short f66;
    unsigned short f68;
    unsigned char pad_6A[2];
    unsigned int f6C;
    unsigned int f70;
    unsigned int f74;
    unsigned char f78;
    unsigned char f79;
    unsigned char f7A;
    unsigned char f7B;
    unsigned int f7C;
    unsigned char f80;
    unsigned char f81;
    unsigned char f82;
    unsigned char f83;
    unsigned int f84;
    unsigned char f88;
    unsigned char f89;
    unsigned char f8A;
    unsigned char f8B;
    unsigned int f8C;
    unsigned int f90;
    unsigned char f94;
    unsigned char pad_95[4];
    unsigned char f99;
    unsigned char f9A;
    unsigned char f9B;
};

struct StaOamSub8C {
    unsigned int f0;
    int f4;
    void * f8;
    unsigned int fC;
    void * f10;
    unsigned int f14;
    unsigned int f18;
    unsigned int f1C;
    unsigned int f20;
    unsigned int f24;
    unsigned int f28;
    unsigned int f2C;
    void * f30;
    void * f34;
    void * f38;
    void * f3C;
    void * f40;
    void * f44;
    void * f48;
    void * f4C;
    void * f50;
    void * f54;
    void * f58;
    void * f5C;
    void * f60;
    void * f64;
    void * f68;
};

struct StaOamSub90 {
    unsigned int f0;
    unsigned int f4;
    unsigned int f8;
    int fC;
    unsigned int f10;
    int f14;
    int f18;
    int f1C;
    int f20;
    unsigned int f24;
    unsigned char f28;
    unsigned char f29;
    unsigned char f2A;
    unsigned char f2B;
    unsigned int f2C;
    unsigned int f30;
    void * f34;
    void * f38;
    void * f3C;
    void * f40;
    void * f44;
    void * f48;
    unsigned int f4C;
    void * f50;
    void * f54;
    void * f58;
    void * f5C;
    void * f60;
    void * f64;
    void * f68;
    void * f6C;
    void * f70;
    void * f74;
    void * f78;
    void * f7C;
    void * f80;
    void * f84;
    void * f88;
    void * f8C;
    void * f90;
    void * f94;
    void * f98;
    void * f9C;
    void * fA0;
    void * fA4;
    void * fA8;
    void * fAC;
};

struct StaOamSub94 {
    int f0;
    int f4;
    int f8;
    unsigned int fC;
    unsigned char f10;
    unsigned char pad_11[3];
    unsigned int f14;
    unsigned int f18;
    void * f1C;
    void * f20;
    void * f24;
    unsigned int f28;
    void * f2C;
    void * f30;
    void * f34;
    void * f38;
    void * f3C;
    unsigned int f40;
    void * f44;
    void * f48;
    void * f4C;
    void * f50;
    void * f54;
    unsigned char f58;
    unsigned char f59;
    unsigned char f5A;
    unsigned char pad_5B[1];
    int f5C;
    unsigned char f60;
    unsigned char pad_61[3];
    unsigned int f64;
    unsigned int f68;
    void * f6C;
    unsigned short f70;
    unsigned char pad_72[14];
    void * f80;
};

struct StaOamBlob {
    unsigned char pad_0[8];
    unsigned int f8;
    unsigned char pad_C[8];
    void * f14;
};

struct StaOamEntry {
    unsigned short f0;
    unsigned char pad_2[10];
    void * fC;
    void * f10;
    unsigned char pad_14[100];
    unsigned int f78;
    void * f7C;
    void * f80;
};

struct StaOamGrid {
    void * f0;
    unsigned char pad_4[12];
    unsigned int f10;
    unsigned char pad_14[12];
    unsigned short f20;
    unsigned char f22;
    unsigned char f23;
};

struct StaOamParent {
    unsigned char pad_0[8];
    void * f8;
    unsigned char pad_C[8];
    unsigned short f14;
    unsigned char pad_16[2];
    unsigned int f18;
    unsigned char pad_1C[8];
    int f24;
};

struct StaOamBmpInfo {
    void * f0;
    short f4;
    short f6;
    unsigned int f8;
    unsigned int fC;
    unsigned char f10;
    unsigned char f11;
    unsigned short f12;
    unsigned int f14;
};

struct StaOamFlagBlk {
    void * f0;
    unsigned char pad_4[8];
    unsigned char fC;
};

struct StaOamSlot {
    unsigned char f0;
    unsigned char pad_1[3];
    int f4;
    void * f8;
    void * fC;
    void * f10;
    void * f14;
};

struct StaOamOwner {
    unsigned int f0;
    unsigned short f4;
};

struct StaOamRecord {
    unsigned int f0;
    unsigned char pad_4[1];
    unsigned char f5;
    unsigned char f6;
};

struct StaOamActorTag {
    unsigned short f0;
    unsigned char pad_2[6];
    void * f8;
};

struct StaOamPtrPair {
    unsigned char pad_0[4];
    void * f4;
    unsigned char pad_8[12];
    void * f14;
};

struct StaOamCtl {
    unsigned char pad_0[32];
    int f20;
};

struct StaOamPartyRef {
    void * f0;
    unsigned char pad_4[4];
    void * f8;
    unsigned char fC;
    unsigned char fD;
    unsigned char fE;
    unsigned char fF;
    unsigned char f10;
    unsigned char pad_11[3];
    unsigned short f14;
    unsigned char pad_16[2];
    unsigned int f18;
    unsigned char pad_1C[4];
    unsigned int f20;
};

#endif
