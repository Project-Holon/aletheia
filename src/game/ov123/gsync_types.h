/*
 * Object layouts for the ov123 game-sync code, built by merging the per-function views.
 * Fields are named f<hex offset>. Where views disagree on the type at an offset,
 * the fields sit in a union named u<hex offset>.
 */
#ifndef GSYNC_TYPES_H
#define GSYNC_TYPES_H

struct GsyncObj01 {
    unsigned char pad_0[4];
    void * f4;
    int f8;
    unsigned short fC;
    unsigned char pad_E[18];
    void * f20;
    void * f24;
    void * f28;
    unsigned char pad_2C[4];
    union {
        unsigned int f30;
        void * f30_p;
    } u30;
    unsigned char pad_34[4];
    void * f38;
    union {
        unsigned int f3C;
        void * f3C_p;
    } u3C;
    unsigned int f40;
    unsigned char pad_44[480];
    void * f224;
    void * f228;
    union {
        unsigned int f22C;
        void * f22C_p;
    } u22C;
    union {
        unsigned int f230;
        void * f230_p;
    } u230;
    unsigned int f234;
    void * f238;
    void * f23C;
    unsigned short f240;
    unsigned char pad_242[6];
    void * f248;
    unsigned short f24C;
    unsigned char pad_24E[6];
    void * f254;
    void * f258;
    unsigned char pad_25C[4];
    union {
        unsigned int f260;
        void * f260_p;
    } u260;
    unsigned int f264;
    unsigned char pad_268[8];
    unsigned int f270;
    unsigned char pad_274[4];
    unsigned int f278;
    unsigned int f27C;
    void * f280;
    void * f284;
    void * f288;
    unsigned char pad_28C[4];
    void * f290;
    void * f294;
    void * f298;
    unsigned char pad_29C[4];
    void * f2A0;
    unsigned char pad_2A4[8];
    union {
        unsigned int f2AC;
        void * f2AC_p;
    } u2AC;
    void * f2B0;
};

struct GsyncObj02 {
    unsigned char pad_0[12];
    void * fC;
};

struct GsyncObj03 {
    unsigned char pad_0[8];
    int f8;
    unsigned char pad_C[4];
    void * f10;
    unsigned char pad_14[12];
    void * f20;
    void * f24;
    void * f28;
    unsigned char pad_2C[4];
    void * f30;
    unsigned char pad_34[4];
    void * f38;
    unsigned int f3C;
    unsigned char pad_40[484];
    void * f224;
    void * f228;
    void * f22C;
    void * f230;
    void * f234;
    void * f238;
    unsigned char pad_23C[24];
    void * f254;
    unsigned char pad_258[4];
    int f25C;
    unsigned char pad_260[32];
    void * f280;
    void * f284;
    void * f288;
    unsigned char pad_28C[4];
    void * f290;
    void * f294;
    void * f298;
    unsigned char pad_29C[16];
    void * f2AC;
    void * f2B0;
};

struct GsyncObj04 {
    unsigned char pad_0[8];
    unsigned int f8;
    unsigned char pad_C[600];
    void * f264;
};

struct GsyncObj05 {
    unsigned char pad_0[8];
    unsigned int f8;
    unsigned char pad_C[612];
    unsigned int f270;
    unsigned char pad_274[44];
    void * f2A0;
};

struct GsyncObj06 {
    unsigned int f0;
    unsigned int f4;
    unsigned char pad_8[704];
    int f2C8;
};

struct GsyncObj07 {
    void * f0;
    unsigned char pad_4[4];
    int f8;
    unsigned char pad_C[548];
    void * f230;
    void * f234;
    void * f238;
    unsigned char pad_23C[40];
    void * f264;
    int f268;
    unsigned char pad_26C[12];
    int f278;
    int f27C;
    unsigned char pad_280[12];
    int f28C;
};

struct GsyncObj08 {
    unsigned char pad_0[456];
    int f1C8;
};

struct GsyncObj09 {
    unsigned char pad_0[4];
    unsigned int f4;
    unsigned int f8;
    unsigned char pad_C[16];
    void * f1C;
    void * f20;
    void * f24;
    void * f28;
    void * f2C;
    void * f30;
    unsigned char pad_34[12];
    void * f40;
    void * f44;
    void * f48;
    unsigned char pad_4C[48];
    void * f7C;
    void * f80;
    void * f84;
    void * f88;
    unsigned char pad_8C[24];
    void * fA4;
};

struct GsyncObj10 {
    unsigned char pad_0[4];
    void * f4;
    void * f8;
    unsigned char pad_C[20];
    void * f20;
    void * f24;
    void * f28;
    void * f2C;
    void * f30;
    unsigned char pad_34[12];
    unsigned int f40;
    unsigned char pad_44[64];
    void * f84;
    unsigned int f88;
    unsigned char pad_8C[24];
    void * fA4;
    unsigned char pad_A8[8];
    unsigned short fB0;
};

struct GsyncObj11 {
    unsigned char pad_0[132];
    void * f84;
    void * f88;
};

struct GsyncObj12 {
    unsigned char pad_0[8];
    int f8;
    unsigned char pad_C[20];
    void * f20;
    unsigned char pad_24[4];
    void * f28;
    void * f2C;
    unsigned char pad_30[20];
    void * f44;
    unsigned char pad_48[56];
    void * f80;
    void * f84;
    unsigned char pad_88[40];
    unsigned short fB0;
};

struct GsyncObj13 {
    unsigned char pad_0[64];
    void * f40;
    void * f44;
    unsigned char pad_48[56];
    void * f80;
};

struct GsyncObj14 {
    unsigned char pad_0[32];
    void * f20;
    unsigned char pad_24[104];
    void * f8C;
    unsigned short f90;
    unsigned char pad_92[6];
    void * f98;
    unsigned short f9C;
    unsigned char pad_9E[6];
    void * fA4;
    unsigned char pad_A8[8];
    unsigned short fB0;
};

struct GsyncObj15 {
    unsigned char pad_0[32];
    void * f20;
    unsigned char pad_24[8];
    void * f2C;
};

struct GsyncObj16 {
    unsigned char pad_0[4];
    int f4;
    unsigned char pad_8[32];
    void * f28;
    void * f2C;
    unsigned char pad_30[24];
    void * f48;
};

struct GsyncObj17 {
    unsigned char pad_0[4];
    int f4;
    unsigned char pad_8[32];
    void * f28;
    void * f2C;
    unsigned char pad_30[24];
    void * f48;
};

struct GsyncObj18 {
    unsigned char pad_0[72];
    void * f48;
};

struct GsyncObj19 {
    unsigned char pad_0[68];
    void * f44;
    unsigned char pad_48[52];
    void * f7C;
    unsigned char pad_80[4];
    unsigned int f84;
    unsigned char pad_88[40];
    unsigned short fB0;
};

struct GsyncObj20 {
    unsigned char pad_0[44];
    void * f2C;
};

struct GsyncObj21 {
    unsigned char pad_0[184];
    void * fB8;
    int fBC;
};

struct GsyncObj22 {
    unsigned char pad_0[184];
    void * fB8;
};

struct GsyncObj23 {
    unsigned char pad_0[184];
    int fB8;
};

struct GsyncObj24 {
    unsigned char pad_0[176];
    int fB0;
    unsigned char pad_B4[16];
    int fC4;
};

struct GsyncObj25 {
    unsigned char pad_0[176];
    int fB0;
};

struct GsyncObj26 {
    unsigned char pad_0[180];
    int fB4;
};

struct GsyncObj27 {
    unsigned char pad_0[180];
    int fB4;
    unsigned char pad_B8[16];
    int fC8;
    unsigned char pad_CC[4];
    int fD0;
};

struct GsyncObj28 {
    unsigned char pad_0[176];
    int fB0;
};

struct GsyncObj29 {
    unsigned char pad_0[204];
    int fCC;
    int fD0;
};

struct GsyncObj30 {
    unsigned char pad_0[200];
    int fC8;
    int fCC;
    int fD0;
};

struct GsyncObj31 {
    unsigned char pad_0[176];
    int fB0;
    unsigned char pad_B4[24];
    int fCC;
    int fD0;
};

struct GsyncObj32 {
    unsigned char pad_0[176];
    int fB0;
    unsigned char pad_B4[4];
    void * fB8;
    int fBC;
    unsigned char pad_C0[12];
    int fCC;
    int fD0;
};

struct GsyncObj33 {
    unsigned char pad_0[176];
    int fB0;
    unsigned char pad_B4[16];
    int fC4;
};

struct GsyncObj34 {
    unsigned char pad_0[172];
    void * fAC;
};

struct GsyncObj35 {
    unsigned int f0;
    unsigned int f4;
    unsigned char pad_8[4];
    union {
        unsigned int fC;
        void * fC_p;
    } uC;
    void * f10;
    unsigned char pad_14[8];
    void * f1C;
    void * f20;
    void * f24;
    union {
        unsigned int f28;
        void * f28_p;
    } u28;
    unsigned char pad_2C[8];
    void * f34;
    void * f38;
    void * f3C;
    unsigned char pad_40[4];
    void * f44;
    unsigned char pad_48[8];
    void * f50;
    void * f54;
    void * f58;
    union {
        unsigned int f5C;
        void * f5C_p;
    } u5C;
    unsigned char pad_60[12];
    void * f6C;
    unsigned char pad_70[68];
    void * fB4;
    void * fB8;
    unsigned char pad_BC[17160];
    unsigned short f43C4;
    unsigned char pad_43C6[406];
    int f455C;
};

struct GsyncObj36 {
    unsigned char pad_0[17350];
    short f43C6;
    unsigned char pad_43C8[396];
    int f4554;
    int f4558;
};

struct GsyncObj37 {
    unsigned char pad_0[12];
    void * fC;
    void * f10;
    void * f14;
    unsigned char pad_18[4];
    void * f1C;
    unsigned char pad_20[148];
    void * fB4;
    void * fB8;
};

struct GsyncObj38 {
    unsigned char pad_0[24];
    void * f18;
    unsigned char pad_1C[17736];
    int f4564;
};

struct GsyncObj39 {
    unsigned char pad_0[12];
    unsigned int fC;
    unsigned char pad_10[20];
    unsigned int f24;
    unsigned char pad_28[20];
    void * f3C;
    unsigned char pad_40[24];
    unsigned int f58;
    unsigned char pad_5C[80];
    void * fAC;
    unsigned char pad_B0[17172];
    unsigned short f43C4;
};

struct GsyncObj40 {
    unsigned char pad_0[12];
    unsigned int fC;
    unsigned char pad_10[16];
    unsigned int f20;
    unsigned char pad_24[20];
    void * f38;
    unsigned char pad_3C[24];
    unsigned int f54;
    unsigned char pad_58[28];
    void * f74;
    unsigned char pad_78[17228];
    unsigned short f43C4;
};

struct GsyncObj41 {
    unsigned char pad_0[168];
    void * fA8;
};

struct GsyncObj42 {
    unsigned char pad_0[116];
    void * f74;
};

struct GsyncObj43 {
    unsigned char pad_0[168];
    void * fA8;
};

struct GsyncObj44 {
    unsigned char pad_0[168];
    void * fA8;
};

struct GsyncObj45 {
    unsigned char pad_0[4];
    unsigned int f4;
    unsigned char pad_8[12];
    void * f14;
    unsigned char pad_18[17324];
    unsigned short f43C4;
};

struct GsyncObj46 {
    unsigned char pad_0[17748];
    int f4554;
    int f4558;
};

struct GsyncObj47 {
    unsigned char pad_0[17756];
    int f455C;
};

struct GsyncObj48 {
    unsigned char pad_0[180];
    void * fB4;
};

struct GsyncObj49 {
    void * f0;
};

struct GsyncObj50 {
    unsigned char pad_0[184];
    void * fB8;
};

struct GsyncObj51 {
    unsigned char pad_0[16644];
    unsigned short f4104;
    unsigned short f4106;
    unsigned short f4108;
    unsigned char pad_410A[698];
    unsigned short f43C4;
};

struct GsyncObj52 {
    unsigned char pad_0[20];
    void * f14;
};

struct GsyncObj53 {
    unsigned char pad_0[12];
    void * fC;
};

struct GsyncObj54 {
    unsigned short f0;
    unsigned char pad_2[14];
    void * f10;
    void * f14;
    void * f18;
    unsigned char pad_1C[4];
    void * f20;
    unsigned char pad_24[4];
    void * f28;
    unsigned char pad_2C[12];
    void * f38;
    unsigned char pad_3C[44];
    int f68;
    int f6C;
    int f70;
    int f74;
    unsigned char pad_78[4];
    int f7C;
    int f80;
    unsigned char pad_84[32];
    unsigned char fA4;
    unsigned char fA5;
    unsigned char fA6;
    signed char fA7;
    unsigned char fA8;
    unsigned char fA9;
    unsigned char pad_AA[4];
    unsigned char fAE;
    unsigned char fAF;
};

struct GsyncObj55 {
    unsigned char pad_0[12];
    unsigned short fC;
    unsigned char pad_E[66];
    int f50;
    unsigned char pad_54[372];
    int f1C8;
};

struct GsyncObj56 {
    unsigned char pad_0[12];
    unsigned short fC;
    unsigned char pad_E[66];
    int f50;
};

struct GsyncObj57 {
    unsigned char pad_0[12];
    unsigned short fC;
    unsigned char pad_E[66];
    int f50;
};

struct GsyncObj58 {
    unsigned char pad_0[80];
    unsigned int f50;
};

struct GsyncObj59 {
    unsigned short f0;
    unsigned char pad_2[22];
    void * f18;
};

struct GsyncObj60 {
    unsigned char pad_0[8];
    int f8;
};

struct GsyncObj61 {
    unsigned char pad_0[8];
    union {
        int f8;
        void * f8_p;
    } u8;
    unsigned char pad_C[4];
    void * f10;
    void * f14;
    void * f18;
    void * f1C;
    void * f20;
    void * f24;
    void * f28;
    union {
        int f2C;
        void * f2C_p;
    } u2C;
    unsigned char pad_30[4];
    void * f34;
    unsigned char pad_38[16];
    int f48;
    int f4C;
    void * f50;
    unsigned char pad_54[86];
    unsigned char fAA;
    unsigned char fAB;
    unsigned char pad_AC[1];
    unsigned char fAD;
    unsigned char fAE;
};

struct GsyncObj62 {
    unsigned char pad_0[16];
    void * f10;
    unsigned char pad_14[4];
    void * f18;
    unsigned char pad_1C[100];
    int f80;
};

struct GsyncObj63 {
    unsigned char pad_0[32];
    void * f20;
};

struct GsyncObj64 {
    unsigned char pad_0[24];
    void * f18;
};

struct GsyncObj65 {
    unsigned char pad_0[24];
    void * f18;
    unsigned char pad_1C[140];
    unsigned char fA8;
};

struct GsyncObj66 {
    unsigned char pad_0[12];
    int fC;
    unsigned char pad_10[8];
    int f18;
    unsigned char pad_1C[80];
    int f6C;
    unsigned char pad_70[8];
    int f78;
};

struct GsyncObj67 {
    unsigned char pad_0[20];
    void * f14;
};

struct GsyncObj68 {
    unsigned short f0;
    unsigned char pad_2[10];
    void * fC;
    unsigned char pad_10[16];
    void * f20;
    void * f24;
    union {
        int f28;
        void * f28_p;
    } u28;
    union {
        int f2C;
        unsigned int f2C_u;
    } u2C;
    unsigned char pad_30[8];
    int f38;
    unsigned char pad_3C[48];
    int f6C;
    unsigned char pad_70[12];
    int f7C;
    unsigned char pad_80[43];
    unsigned char fAB;
    unsigned char pad_AC[1];
    unsigned char fAD;
};

struct GsyncObj69 {
    unsigned char pad_0[12];
    void * fC;
    unsigned char pad_10[4];
    void * f14;
    void * f18;
    unsigned char pad_1C[12];
    void * f28;
    void * f2C;
    unsigned char pad_30[123];
    unsigned char fAB;
    unsigned char pad_AC[1];
    unsigned char fAD;
    unsigned char fAE;
};

struct GsyncObj70 {
    unsigned char pad_0[2];
    signed char f2;
    signed char f3;
    unsigned char pad_4[12];
    void * f10;
    unsigned char pad_14[100];
    int f78;
};

struct GsyncObj71 {
    unsigned char pad_0[20];
    void * f14;
    unsigned char pad_18[20];
    void * f2C;
    unsigned char pad_30[64];
    int f70;
    unsigned char pad_74[4];
    int f78;
};

struct GsyncObj72 {
    unsigned char f0;
    unsigned char pad_1[1];
    unsigned short f2;
    unsigned short f4;
    unsigned char f6;
    unsigned char f7;
};

struct GsyncObj73 {
    unsigned char pad_0[8];
    int f8;
    unsigned char pad_C[116];
    int f80;
};

struct GsyncObj74 {
    unsigned char pad_0[64];
    void * f40;
    unsigned char pad_44[97];
    unsigned char fA5;
    unsigned char pad_A6[8];
    unsigned char fAE;
};

struct GsyncObj75 {
    unsigned char pad_0[44];
    int f2C;
};

struct GsyncObj76 {
    unsigned short f0;
    unsigned char pad_2[6];
    int f8;
    unsigned char pad_C[32];
    int f2C;
    unsigned char pad_30[16];
    int f40;
    unsigned char pad_44[60];
    int f80;
    unsigned char pad_84[42];
    unsigned char fAE;
};

struct GsyncObj77 {
    unsigned char pad_0[9728];
    unsigned short f2600;
};

struct GsyncObj78 {
    unsigned char pad_0[60];
    void * f3C;
    unsigned char pad_40[102];
    unsigned char fA6;
    unsigned char pad_A7[7];
    unsigned char fAE;
};

struct GsyncObj79 {
    unsigned char pad_0[44];
    int f2C;
};

struct GsyncObj80 {
    unsigned short f0;
    unsigned char pad_2[6];
    int f8;
    unsigned char pad_C[32];
    int f2C;
    unsigned char pad_30[12];
    void * f3C;
    unsigned char pad_40[64];
    int f80;
    unsigned char pad_84[42];
    unsigned char fAE;
};

struct GsyncObj81 {
    unsigned char pad_0[25088];
    unsigned short f6200;
};

struct GsyncObj82 {
    unsigned char pad_0[48];
    void * f30;
    unsigned char pad_34[122];
    unsigned char fAE;
};

struct GsyncObj83 {
    unsigned short f0;
    unsigned char pad_2[6];
    int f8;
    unsigned char pad_C[32];
    int f2C;
    int f30;
    unsigned char pad_34[76];
    int f80;
    unsigned char pad_84[32];
    unsigned char fA4;
    unsigned char pad_A5[2];
    unsigned char fA7;
    unsigned char pad_A8[6];
    unsigned char fAE;
};

struct GsyncObj84 {
    unsigned char pad_0[8];
    int f8;
    unsigned char pad_C[8];
    void * f14;
    unsigned char pad_18[88];
    int f70;
    unsigned char pad_74[12];
    int f80;
};

struct GsyncObj85 {
    unsigned char pad_0[8];
    int f8;
    unsigned char pad_C[116];
    int f80;
};

struct GsyncObj86 {
    unsigned char pad_0[8];
    int f8;
    unsigned char pad_C[116];
    int f80;
};

struct GsyncObj87 {
    unsigned char pad_0[8];
    int f8;
    unsigned char pad_C[116];
    int f80;
};

struct GsyncObj88 {
    unsigned char pad_0[8];
    int f8;
    unsigned char pad_C[116];
    int f80;
};

struct GsyncObj89 {
    unsigned char pad_0[8];
    void * f8;
    unsigned char pad_C[116];
    int f80;
    unsigned char pad_84[32];
    unsigned char fA4;
    unsigned char fA5;
    unsigned char fA6;
    unsigned char fA7;
};

struct GsyncObj90 {
    unsigned short f0;
    unsigned char pad_2[6];
    void * f8;
    unsigned char pad_C[116];
    int f80;
    unsigned char pad_84[35];
    unsigned char fA7;
};

struct GsyncObj91 {
    unsigned char pad_0[4];
    unsigned short f4;
    unsigned short f6;
    unsigned char f8;
    unsigned char f9;
    unsigned char fA;
};

struct GsyncObj92 {
    unsigned char f0;
    unsigned char pad_1[83];
    unsigned short f54;
    unsigned char pad_56[1];
    unsigned char f57;
    unsigned char f58;
    unsigned char f59;
    unsigned char pad_5A[1];
    unsigned char f5B;
};

struct GsyncObj93 {
    unsigned char pad_0[24];
    void * f18;
};

struct GsyncObj94 {
    unsigned char pad_0[20];
    void * f14;
    void * f18;
};

struct GsyncObj95 {
    unsigned char pad_0[24];
    void * f18;
};

struct GsyncObj96 {
    unsigned char pad_0[24];
    void * f18;
};

struct GsyncObj97 {
    unsigned char pad_0[24];
    void * f18;
};

struct GsyncObj98 {
    unsigned char pad_0[24];
    void * f18;
};

struct GsyncObj99 {
    unsigned char pad_0[24];
    void * f18;
    void * f1C;
    unsigned char pad_20[4];
    void * f24;
    unsigned char pad_28[60];
    int f64;
};

struct GsyncObj100 {
    unsigned char pad_0[24];
    void * f18;
    void * f1C;
    unsigned char pad_20[68];
    int f64;
};

struct GsyncObj101 {
    unsigned char pad_0[20];
    void * f14;
    void * f18;
    unsigned char pad_1C[12];
    void * f28;
};

struct GsyncObj102 {
    unsigned char pad_0[24];
    void * f18;
};

struct GsyncObj103 {
    unsigned char pad_0[24];
    void * f18;
    unsigned char pad_1C[12];
    void * f28;
    unsigned char pad_2C[131];
    signed char fAF;
};

struct GsyncObj104 {
    unsigned char pad_0[24];
    void * f18;
};

struct GsyncObj105 {
    unsigned char pad_0[24];
    void * f18;
    unsigned char pad_1C[4];
    void * f20;
};

struct GsyncObj106 {
    int f0;
};

struct GsyncObj107 {
    unsigned char pad_0[24];
    void * f18;
};

struct GsyncObj108 {
    unsigned char pad_0[24];
    void * f18;
};

struct GsyncObj109 {
    unsigned char pad_0[24];
    void * f18;
};

struct GsyncObj110 {
    unsigned char pad_0[24];
    void * f18;
};

struct GsyncObj111 {
    unsigned char pad_0[128];
    unsigned short f80;
};

struct GsyncObj112 {
    unsigned char pad_0[16];
    void * f10;
    unsigned char pad_14[4];
    void * f18;
};

struct GsyncObj113 {
    unsigned char pad_0[24];
    void * f18;
    unsigned char pad_1C[4];
    void * f20;
};

struct GsyncObj114 {
    unsigned char pad_0[24];
    void * f18;
};

struct GsyncObj115 {
    int f0;
};

struct GsyncObj116 {
    unsigned char pad_0[16];
    void * f10;
    unsigned char pad_14[20];
    void * f28;
    unsigned char pad_2C[128];
    unsigned char fAC;
};

struct GsyncObj117 {
    unsigned char pad_0[100];
    int f64;
};

struct GsyncObj118 {
    unsigned char pad_0[24];
    void * f18;
};

struct GsyncObj119 {
    unsigned char pad_0[12];
    int fC;
    unsigned char pad_10[4];
    void * f14;
    void * f18;
    unsigned char pad_1C[40];
    void * f44;
    unsigned char pad_48[40];
    int f70;
};

struct GsyncObj120 {
    unsigned char pad_0[20];
    void * f14;
    unsigned char pad_18[20];
    void * f2C;
    unsigned char pad_30[4];
    void * f34;
    unsigned char pad_38[56];
    int f70;
    unsigned char pad_74[57];
    signed char fAD;
};

struct GsyncObj121 {
    unsigned char pad_0[40];
    void * f28;
    void * f2C;
    unsigned char pad_30[64];
    int f70;
    unsigned char pad_74[54];
    signed char fAA;
    unsigned char pad_AB[2];
    signed char fAD;
};

struct GsyncObj122 {
    int f0;
};

struct GsyncObj123 {
    unsigned char pad_0[20];
    void * f14;
    void * f18;
    unsigned char pad_1C[68];
    int f60;
};

struct GsyncObj124 {
    unsigned char pad_0[20];
    void * f14;
    unsigned char pad_18[72];
    int f60;
};

struct GsyncObj125 {
    unsigned char pad_0[20];
    void * f14;
    unsigned char pad_18[72];
    int f60;
};

struct GsyncObj126 {
    unsigned char pad_0[20];
    void * f14;
    unsigned char pad_18[72];
    int f60;
};

struct GsyncObj127 {
    unsigned char pad_0[12];
    void * fC;
    unsigned char pad_10[4];
    void * f14;
    unsigned char pad_18[72];
    int f60;
};

struct GsyncObj128 {
    unsigned short f0;
    unsigned char pad_2[10];
    void * fC;
    unsigned char pad_10[4];
    void * f14;
    unsigned char pad_18[12];
    void * f24;
    void * f28;
    unsigned char pad_2C[28];
    int f48;
    int f4C;
    unsigned char pad_50[90];
    unsigned char fAA;
};

struct GsyncObj129 {
    unsigned char pad_0[16];
    void * f10;
};

struct GsyncObj130 {
    unsigned short f0;
    unsigned char pad_2[14];
    void * f10;
    void * f14;
    void * f18;
    unsigned char pad_1C[4];
    void * f20;
    unsigned int f24;
    void * f28;
    void * f2C;
    unsigned char pad_30[24];
    int f48;
    int f4C;
    unsigned char pad_50[92];
    unsigned char fAC;
    unsigned char pad_AD[2];
    unsigned char fAF;
};

struct GsyncObj131 {
    unsigned char pad_0[4];
    void * f4;
    unsigned char pad_8[448];
    unsigned int f1C8;
    unsigned char pad_1CC[4];
    unsigned short f1D0;
    unsigned short f1D2;
};

struct GsyncObj132 {
    unsigned char pad_0[8];
    void * f8;
    void * fC;
    void * f10;
    void * f14;
    void * f18;
    void * f1C;
    unsigned char pad_20[16];
    void * f30;
    unsigned char pad_34[4];
    void * f38;
    void * f3C;
    void * f40;
    void * f44;
};

struct GsyncObj133 {
    unsigned int f0;
    unsigned int f4;
    unsigned int f8;
    unsigned char pad_C[16];
    void * f1C;
    void * f20;
    void * f24;
    void * f28;
    void * f2C;
    void * f30;
    unsigned char pad_34[12];
    void * f40;
    void * f44;
    void * f48;
    void * f4C;
    unsigned char pad_50[48];
    void * f80;
    unsigned char pad_84[4];
    void * f88;
    void * f8C;
    void * f90;
    unsigned char pad_94[24];
    void * fAC;
};

struct GsyncObj134 {
    void * f0;
    void * f4;
    void * f8;
    unsigned char pad_C[20];
    void * f20;
    void * f24;
    void * f28;
    void * f2C;
    void * f30;
    unsigned char pad_34[84];
    void * f88;
    unsigned int f8C;
    unsigned char pad_90[28];
    void * fAC;
    unsigned short fB0;
};

struct GsyncObj135 {
    unsigned char pad_0[136];
    void * f88;
    void * f8C;
};

struct GsyncObj136 {
    unsigned char pad_0[8];
    int f8;
    unsigned char pad_C[20];
    void * f20;
    unsigned char pad_24[4];
    void * f28;
    void * f2C;
    unsigned char pad_30[24];
    void * f48;
    unsigned char pad_4C[52];
    void * f80;
    unsigned char pad_84[4];
    void * f88;
    unsigned char pad_8C[36];
    unsigned short fB0;
};

struct GsyncObj137 {
    unsigned char pad_0[72];
    void * f48;
    unsigned char pad_4C[60];
    unsigned int f88;
    unsigned char pad_8C[4];
    void * f90;
    unsigned char pad_94[28];
    unsigned short fB0;
};

struct GsyncObj138 {
    unsigned char pad_0[128];
    void * f80;
};

struct GsyncObj139 {
    unsigned char pad_0[72];
    void * f48;
    unsigned char pad_4C[68];
    void * f90;
};

struct GsyncObj140 {
    unsigned char pad_0[4];
    int f4;
    unsigned char pad_8[24];
    void * f20;
    unsigned char pad_24[4];
    void * f28;
    void * f2C;
    unsigned char pad_30[28];
    void * f4C;
};

struct GsyncObj141 {
    unsigned char pad_0[76];
    void * f4C;
};

struct GsyncObj142 {
    int f0;
    unsigned char pad_4[28];
    void * f20;
    unsigned char pad_24[4];
    void * f28;
    void * f2C;
    unsigned char pad_30[16];
    void * f40;
    void * f44;
};

struct GsyncObj143 {
    unsigned char pad_0[64];
    void * f40;
    void * f44;
};

struct GsyncObj144 {
    unsigned char pad_0[2428];
    void * f97C;
    void * f980;
    unsigned char pad_984[96];
    unsigned short f9E4;
};

struct GsyncObj145 {
    unsigned char pad_0[8];
    void * f8;
    void * fC;
    unsigned char pad_10[2412];
    void * f97C;
    void * f980;
    void * f984;
};

struct GsyncObj146 {
    unsigned char pad_0[4];
    int f4;
    unsigned char pad_8[2400];
    short f968;
    unsigned char pad_96A[1];
    unsigned char f96B;
    unsigned char f96C;
};

struct GsyncObj147 {
    unsigned char pad_0[2480];
    void * f9B0;
};

struct GsyncObj148 {
    unsigned char pad_0[8];
    void * f8;
    unsigned char pad_C[4];
    void * f10;
    unsigned char pad_14[92];
    int f70;
};

struct GsyncObj149 {
    unsigned char pad_0[48];
    int f30;
};

struct GsyncObj150 {
    unsigned short f0;
};

struct GsyncObj151 {
    unsigned char pad_0[16];
    void * f10;
};

struct GsyncObj152 {
    unsigned char pad_0[16];
    void * f10;
    unsigned char pad_14[12];
    void * f20;
    unsigned char pad_24[72];
    int f6C;
};

struct GsyncObj153 {
    unsigned char pad_0[16];
    void * f10;
    unsigned char pad_14[12];
    int f20;
    unsigned char pad_24[72];
    int f6C;
};

struct GsyncObj154 {
    unsigned char pad_0[16];
    void * f10;
};

struct GsyncObj155 {
    unsigned char pad_0[16];
    void * f10;
    unsigned char pad_14[8];
    void * f1C;
};

struct GsyncObj156 {
    unsigned char pad_0[16];
    void * f10;
    unsigned char pad_14[20];
    int f28;
};

struct GsyncObj157 {
    unsigned char pad_0[16];
    void * f10;
    unsigned char pad_14[20];
    int f28;
};

struct GsyncObj158 {
    unsigned char pad_0[8];
    void * f8;
    unsigned char pad_C[4];
    void * f10;
    unsigned char pad_14[92];
    unsigned int f70;
};

struct GsyncObj159 {
    unsigned char pad_0[16];
    void * f10;
};

struct GsyncObj160 {
    unsigned char pad_0[16];
    void * f10;
};

struct GsyncObj161 {
    unsigned char pad_0[16];
    void * f10;
    void * f14;
};

struct GsyncObj162 {
    unsigned char pad_0[16];
    void * f10;
    int f14;
};

struct GsyncObj163 {
    unsigned char pad_0[16];
    void * f10;
};

struct GsyncObj164 {
    unsigned char pad_0[16];
    void * f10;
};

struct GsyncObj165 {
    unsigned char pad_0[16];
    void * f10;
    unsigned char pad_14[20];
    int f28;
};

struct GsyncObj166 {
    unsigned char pad_0[8];
    void * f8;
};

struct GsyncObj167 {
    unsigned short f0;
    unsigned char pad_2[6];
    void * f8;
    void * fC;
    void * f10;
    unsigned char pad_14[8];
    void * f1C;
    void * f20;
    unsigned char pad_24[4];
    int f28;
};

struct GsyncObj168 {
    void * f0;
    int f4;
    unsigned short f8;
    unsigned char pad_A[2];
    int fC;
    int f10;
};

struct GsyncObj169 {
    unsigned char pad_0[8];
    void * f8;
    int fC;
    void * f10;
    void * f14;
    unsigned char pad_18[8];
    void * f20;
    unsigned char pad_24[12];
    void * f30;
    unsigned char pad_34[56];
    int f6C;
};

struct GsyncObj170 {
    unsigned char pad_0[16];
    int f10;
};

struct GsyncObj171 {
    unsigned char pad_0[12];
    unsigned int fC;
    unsigned char pad_10[24];
    unsigned int f28;
    unsigned char pad_2C[20];
    void * f40;
    unsigned char pad_44[24];
    unsigned int f5C;
    unsigned char pad_60[72];
    void * fA8;
    unsigned char pad_AC[17176];
    unsigned short f43C4;
};

struct GsyncObj172 {
    unsigned char pad_0[12];
    void * fC;
};

struct GsyncObj173 {
    unsigned char pad_0[456];
    int f1C8;
};

struct GsyncObj174 {
    unsigned char pad_0[4];
    void * f4;
};

struct GsyncObj175 {
    unsigned char pad_0[80];
    int f50;
    unsigned char pad_54[372];
    int f1C8;
};

struct GsyncObj176 {
    unsigned char pad_0[456];
    int f1C8;
};

struct GsyncObj177 {
    unsigned char pad_0[456];
    int f1C8;
};

#endif
