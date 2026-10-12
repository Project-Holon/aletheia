#ifndef OV183_BR_CODEIN_TYPES_H
#define OV183_BR_CODEIN_TYPES_H

struct CodeinWorkA {
    void * f0;
    void * f4;
    void * f8;
    void * fC;
    void * f10;
    void * f14;
    unsigned char  f18;
    unsigned char pad_19[3];
    char * f1C;
    char * f20;
    void * f24;
    char * f28;
    unsigned char pad_2C[8];
    void * f34;
    void * f38;
    char * f3C;
    int  f40;
    int  f44;
    void * f48;
    int  f4C;
    int  f50;
    unsigned short  f54;
    unsigned char pad_56[14];
    void * f64;
    int  f68;
    unsigned short  f6C;
    unsigned char pad_6E[6];
    void * f74;
    int  f78;
    unsigned short  f7C;
    unsigned char pad_7E[50];
    int  fB0;
    unsigned short  fB4;
    unsigned char pad_B6[22];
    int  fCC;
    char * fD0;
    unsigned char pad_D4[4];
    int  fD8;
    unsigned char pad_DC[36];
    int  f100;
    int  f104;
    char * f108;
    unsigned char pad_10C[124];
    int  f188;
    unsigned char pad_18C[8];
    void * f194;
    unsigned char pad_198[24];
    void * f1B0;
    unsigned char pad_1B4[40];
    int  f1DC;
    unsigned char pad_1E0[8];
    void * f1E8;
    unsigned char pad_1EC[8];
    signed char  f1F4;
    unsigned char pad_1F5[15];
    void * f204;
    unsigned char pad_208[36];
    int  f22C;
    int  f230;
    int  f234;
    int  f238;
    int  f23C;
    int  f240;
    int  f244;
    int  f248;
    int  f24C;
    int  f250;
    int  f254;
    void * f258;
    void * f25C;
    int  f260;
    unsigned int  f264;
    int  f268;
    int  f26C;
    unsigned int  f270;
    int  f274;
    unsigned char pad_278[12];
    int  f284;
    unsigned int  f288;
    int  f28C;
    unsigned char pad_290[4];
    void * f294;
    unsigned char  f298;
    unsigned char  f299;
    unsigned char  f29A;
    unsigned char  f29B;
    unsigned char pad_29C[84];
    unsigned char  f2F0;
    unsigned char pad_2F1[1];
    unsigned char  f2F2;
    unsigned char pad_2F3[1];
    unsigned char  f2F4;
    unsigned char pad_2F5[1];
    unsigned char  f2F6;
    unsigned char pad_2F7[1];
    unsigned char  f2F8;
    unsigned char pad_2F9[3];
    int  f2FC;
    void * f300;
    void * f304;
    void * f308;
    unsigned char pad_30C[4];
    int  f310;
    void * f314;
    int  f318;
    int  f31C;
    int  f320;
    unsigned char pad_324[32];
    void * f344;
    unsigned char pad_348[4];
    unsigned short  f34C;
    unsigned char pad_34E[2];
    int  f350;
    unsigned char pad_354[12];
    unsigned long long  f360;
};

struct CodeinWorkB {
    int  f0;
    int  f4;
    void * f8;
    int  fC;
    int  f10;
    void * f14;
    void * f18;
    unsigned int  f1C;
    int  f20;
    char * f24;
    void * f28;
    char * f2C;
    unsigned char pad_30[4];
    char * f34;
    void * f38;
    unsigned char pad_3C[4];
    int  f40;
    int  f44;
    int  f48;
    int  f4C;
    int  f50;
    unsigned short  f54;
    unsigned char pad_56[90];
    int  fB0;
    unsigned short  fB4;
    unsigned char pad_B6[18];
    int  fC8;
    unsigned char pad_CC[4];
    char * fD0;
    int  fD4;
    int  fD8;
    int  fDC;
    int  fE0;
    int  fE4;
};

struct CodeinArgA {
    int  f0;
    int  f4;
    int  f8;
    void * fC;
    int  f10;
    int  f14;
    unsigned short  f18;
    unsigned char pad_1A[2];
    int  f1C;
    unsigned char pad_20[4];
    int  f24;
    unsigned char pad_28[224];
    char * f108;
    unsigned char pad_10C[80];
    void * f15C;
};

struct CodeinSubA {
    unsigned char pad_0[4];
    int  f4;
    int * f8;
    int * fC;
    int  f10;
    int  f14;
    void * f18;
    char * f1C;
    unsigned char pad_20[4];
    void * f24;
    void * f28;
    unsigned char pad_2C[5868];
    unsigned int  f1718;
    unsigned int  f171C;
};

struct CodeinWorkC {
    int  f0;
    void * f4;
    int  f8;
    void * fC;
    void * f10;
    int  f14;
    int  f18;
    unsigned short  f1C;
    unsigned char pad_1E[2];
    char * f20;
    unsigned int  f24;
    void * f28;
    unsigned char pad_2C[4];
    void * f30;
    void * f34;
    unsigned char pad_38[24];
    int  f50;
    unsigned char pad_54[44];
    void * f80;
};

struct CodeinWorkD {
    void * f0;
    void * f4;
    void * f8;
    void * fC;
    void * f10;
    void * f14;
    unsigned short  f18;
    unsigned char pad_1A[2];
    void * f1C;
    int  f20;
    void * f24;
    unsigned char pad_28[16];
    unsigned short  f38;
    unsigned char pad_3A[2];
    char * f3C;
    unsigned char pad_40[20];
    int  f54;
    void * f58;
    unsigned char pad_5C[116];
    void * fD0;
    unsigned char pad_D4[44];
    int  f100;
    int  f104;
    char * f108;
};

struct CodeinArgB {
    int  f0;
    void * f4;
    int  f8;
    char * fC;
    void * f10;
    unsigned short  f14;
    unsigned char  f16;
    unsigned char  f17;
    int  f18;
};

struct CodeinRecordA {
    int  f0;
    unsigned char pad_4[4];
    int  f8;
    void * fC;
    unsigned char pad_10[4];
    short  f14;
    short  f16;
    unsigned char  f18;
    unsigned char  f19;
    unsigned char pad_1A[322];
    void * f15C;
    unsigned char pad_160[4];
    short  f164;
    short  f166;
    unsigned char  f168;
};

struct CodeinWorkE {
    unsigned char pad_0[4];
    unsigned short  f4;
    unsigned char pad_6[2];
    void * f8;
    void * fC;
    unsigned char pad_10[4];
    int  f14;
    int  f18;
    char * f1C;
};

struct CodeinWorkF {
    int  f0;
    int  f4;
    unsigned short  f8;
    unsigned char pad_A[2];
    int  fC;
    int  f10;
    unsigned short  f14;
    unsigned char pad_16[2];
    char * f18;
};

struct CodeinSlotA {
    unsigned char pad_0[28];
    void * f1C;
};

struct CodeinStateA {
    void * f0;
    unsigned short  f4;
    unsigned char pad_6[6];
    void * fC;
    unsigned char pad_10[4];
    void * f14;
    void * f18;
    char * f1C;
};

struct CodeinSubB {
    unsigned char pad_0[16];
    unsigned short  f10;
};

struct CodeinStateB {
    int  f0;
    int  f4;
    unsigned char pad_8[4];
    char * fC;
    unsigned char pad_10[4];
    unsigned short  f14;
};

struct CodeinArgC {
    int  f0;
    int  f4;
    int  f8;
    int  fC;
    int  f10;
    unsigned char pad_14[4];
    unsigned int  f18;
};

struct CodeinWorkG {
    void * f0;
    void * f4;
    void * f8;
    unsigned char pad_C[8];
    unsigned short  f14;
    unsigned short  f16;
    unsigned short  f18;
    unsigned char pad_1A[62];
    void * f58;
};

struct CodeinSpecialA {
    unsigned char pad_0[336];
    int  f150;
    unsigned char pad_154[8];
    void * f15C;
    unsigned char pad_160[4];
    short  f164;
    short  f166;
    unsigned char  f168;
};

struct CodeinDataA {
    unsigned char pad_0[56];
    void * f38;
    unsigned char pad_3C[8];
    void * f44;
    void * f48;
};

struct CodeinArgD {
    int  f0;
    unsigned char pad_4[8];
    int  fC;
    unsigned long long  f10;
};

struct CodeinA1A {
    unsigned char pad_0[12];
    int  fC;
};

#endif
