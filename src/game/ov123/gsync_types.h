/*
 * Object layouts for the ov123 game-sync code, built by merging the per-function views.
 * Fields are named f<hex offset>. Where views disagree on the type at an offset,
 * the fields sit in a union named u<hex offset>.
 */
#ifndef GSYNC_TYPES_H
#define GSYNC_TYPES_H


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

typedef struct GsyncStateObj1 {
    unsigned short f0;
    unsigned char pad2[6];
    int f8;
    void *fC;
    void *f10;
    void *f14;
    void *f18;
    void *f1C;
    void *f20;
    void *f24;
    void *f28;
    int f2C;
    void *f30;
    void *f34;
    int f38;
    void *f3C;
    void *f40;
    void *f44;
    int f48;
    int f4C;
    unsigned int f50;
    unsigned char pad54[12];
    int f60;
    int f64;
    int f68;
    int f6C;
    int f70;
    int f74;
    int f78;
    int f7C;
    int f80;
    unsigned char pad84[32];
    unsigned char fA4;
    unsigned char fA5;
    unsigned char fA6;
    unsigned char fA7;
    unsigned char fA8;
    unsigned char padA9[1];
    unsigned char fAA;
    unsigned char fAB;
    unsigned char fAC;
    unsigned char fAD;
    unsigned char fAE;
    unsigned char fAF;
    unsigned char padB0[4];
    int fB4;
    int fB8;
    unsigned char padBC[12];
    int fC8;
    int fCC;
    int fD0;
    unsigned char padD4[17536];
    int f4554;
    int f4558;
} GsyncStateObj1;

typedef struct GsyncStateObj2 {
    unsigned int f0;
    unsigned int f4;
    unsigned int f8;
    void *fC;
    void *f10;
    void *f14;
    unsigned char pad18[4];
    void *f1C;
    void *f20;
    void *f24;
    void *f28;
    void *f2C;
    void *f30;
    void *f34;
    void *f38;
    void *f3C;
    void *f40;
    void *f44;
    void *f48;
    void *f4C;
    void *f50;
    void *f54;
    void *f58;
    void *f5C;
    unsigned char pad60[12];
    void *f6C;
    unsigned char pad70[12];
    void *f7C;
    void *f80;
    void *f84;
    void *f88;
    void *f8C;
    void *f90;
    unsigned char pad94[16];
    void *fA4;
    void *fA8;
    void *fAC;
    unsigned char padB0[4];
    void *fB4;
    void *fB8;
    unsigned char padBC[17160];
    unsigned short f43C4;
    short f43C6;
    unsigned char pad43C8[404];
    int f455C;
} GsyncStateObj2;

typedef struct GsyncStateObj3 {
    void *f0;
    void *f4;
    int f8;
    unsigned short fC;
    unsigned char padE[10];
    void *f18;
    unsigned char pad1C[4];
    void *f20;
    void *f24;
    void *f28;
    unsigned char pad2C[4];
    void *f30;
    unsigned char pad34[4];
    void *f38;
    void *f3C;
    unsigned int f40;
    unsigned char pad44[4];
    void *f48;
    unsigned char pad4C[8];
    unsigned short f54;
    unsigned char pad56[42];
    unsigned short f80;
    unsigned char pad82[6];
    unsigned int f88;
    unsigned char pad8C[4];
    void *f90;
    unsigned char pad94[28];
    unsigned short fB0;
    unsigned char padB2[278];
    unsigned int f1C8;
    unsigned char pad1CC[4];
    unsigned short f1D0;
    unsigned short f1D2;
    unsigned char pad1D4[80];
    void *f224;
    void *f228;
    void *f22C;
    void *f230;
    unsigned int f234;
    void *f238;
    void *f23C;
    unsigned short f240;
    unsigned char pad242[6];
    void *f248;
    unsigned short f24C;
    unsigned char pad24E[6];
    void *f254;
    void *f258;
    unsigned char pad25C[4];
    void *f260;
    void *f264;
    unsigned char pad268[8];
    unsigned int f270;
    unsigned char pad274[4];
    unsigned int f278;
    unsigned int f27C;
    void *f280;
    void *f284;
    void *f288;
    unsigned char pad28C[4];
    void *f290;
    void *f294;
    void *f298;
    unsigned char pad29C[4];
    void *f2A0;
    unsigned char pad2A4[8];
    void *f2AC;
    void *f2B0;
    unsigned char pad2B4[17072];
    int f4564;
} GsyncStateObj3;

typedef struct GsyncStateObj4 {
    unsigned short f0;
    unsigned char pad2[6];
    void *f8;
    void *fC;
    void *f10;
    void *f14;
    unsigned char pad18[4];
    void *f1C;
    void *f20;
    unsigned char pad24[4];
    int f28;
    unsigned char pad2C[4];
    int f30;
    unsigned char pad34[56];
    int f6C;
    unsigned int f70;
} GsyncStateObj4;

typedef struct GsyncStateObj5 {
    unsigned char pad0[4];
    int f4;
    int f8;
    unsigned char padC[20];
    void *f20;
    unsigned char pad24[4];
    void *f28;
    void *f2C;
    unsigned char pad30[20];
    void *f44;
    void *f48;
    void *f4C;
    unsigned char pad50[48];
    void *f80;
    void *f84;
    void *f88;
    unsigned char pad8C[36];
    unsigned short fB0;
} GsyncStateObj5;

typedef struct GsyncStateObj6 {
    unsigned char pad0[8];
    int f8;
    unsigned char padC[24];
    void *f24;
    void *f28;
    unsigned char pad2C[4];
    void *f30;
    unsigned char pad34[4];
    void *f38;
    unsigned int f3C;
    unsigned char pad40[484];
    void *f224;
    void *f228;
    void *f22C;
    void *f230;
    void *f234;
    void *f238;
    unsigned char pad23C[24];
    void *f254;
    unsigned char pad258[12];
    void *f264;
    int f268;
    unsigned char pad26C[12];
    int f278;
    int f27C;
    void *f280;
    void *f284;
    void *f288;
    int f28C;
    void *f290;
    void *f294;
    void *f298;
    unsigned char pad29C[16];
    void *f2AC;
    void *f2B0;
} GsyncStateObj6;

typedef struct GsyncStateObj8 {
    void *f0;
    void *f4;
    void *f8;
    unsigned char padC[20];
    void *f20;
    void *f24;
    void *f28;
    void *f2C;
    void *f30;
    unsigned char pad34[84];
    void *f88;
    unsigned int f8C;
    unsigned char pad90[28];
    void *fAC;
    unsigned short fB0;
} GsyncStateObj8;

typedef struct GsyncStateObj10 {
    unsigned char pad0[8];
    void *f8;
    void *fC;
    void *f10;
    void *f14;
    void *f18;
    void *f1C;
    unsigned char pad20[16];
    void *f30;
    unsigned char pad34[4];
    void *f38;
    void *f3C;
    void *f40;
    void *f44;
} GsyncStateObj10;

typedef struct GsyncStateObj12 {
    unsigned char pad0[8];
    void *f8;
    void *fC;
    unsigned char pad10[2412];
    void *f97C;
    void *f980;
    void *f984;
    unsigned char pad988[92];
    unsigned short f9E4;
} GsyncStateObj12;

typedef struct GsyncStateObj13 {
    unsigned char pad0[4];
    int f4;
    unsigned char pad8[2400];
    short f968;
    unsigned char pad96A[1];
    unsigned char f96B;
    unsigned char f96C;
} GsyncStateObj13;

typedef struct GsyncStateObj14 {
    void *f0;
    int f4;
    unsigned short f8;
    unsigned char padA[2];
    int fC;
    int f10;
} GsyncStateObj14;

typedef struct GsyncStateObj15 {
    unsigned char pad0[12];
    unsigned int fC;
    unsigned char pad10[20];
    unsigned int f24;
    unsigned char pad28[20];
    void *f3C;
    unsigned char pad40[24];
    unsigned int f58;
    unsigned char pad5C[80];
    void *fAC;
    unsigned char padB0[17172];
    unsigned short f43C4;
} GsyncStateObj15;

typedef struct GsyncStateObj16 {
    unsigned int f0;
    unsigned int f4;
    unsigned char pad8[704];
    int f2C8;
} GsyncStateObj16;

typedef struct GsyncStateObj17 {
    unsigned char pad0[12];
    unsigned int fC;
    unsigned char pad10[16];
    unsigned int f20;
    unsigned char pad24[20];
    void *f38;
    unsigned char pad3C[24];
    unsigned int f54;
    unsigned char pad58[17260];
    unsigned short f43C4;
} GsyncStateObj17;

typedef struct GsyncStateObj18 {
    unsigned char pad0[116];
    void *f74;
} GsyncStateObj18;

typedef struct GsyncStateObj19 {
    int f0;
} GsyncStateObj19;

typedef struct GsyncStateObj20 {
    unsigned char pad0[2480];
    void *f9B0;
} GsyncStateObj20;

typedef struct GsyncStateObj21 {
    unsigned char pad0[4];
    unsigned short f4;
    unsigned short f6;
} GsyncStateObj21;

typedef struct GsyncStateObj22 {
    unsigned char pad0[12];
    unsigned short fC;
    unsigned char padE[66];
    int f50;
    unsigned char pad54[372];
    int f1C8;
} GsyncStateObj22;

typedef struct GsyncStateObj23 {
    unsigned char pad0[12];
    void *fC;
} GsyncStateObj23;

typedef struct GsyncStateObj24 {
    unsigned char pad0[20];
    void *f14;
} GsyncStateObj24;

typedef struct GsyncStateObj26 {
    unsigned char pad0[12];
    unsigned short fC;
    unsigned char padE[66];
    int f50;
} GsyncStateObj26;

typedef struct GsyncStateObj27 {
    unsigned char pad0[12];
    unsigned short fC;
    unsigned char padE[66];
    int f50;
} GsyncStateObj27;

typedef struct GsyncStateObj28 {
    unsigned char pad0[2];
    unsigned short f2;
    unsigned short f4;
} GsyncStateObj28;

typedef struct GsyncStateObj29 {
    unsigned char pad0[456];
    int f1C8;
} GsyncStateObj29;

typedef struct GsyncStateObj30 {
    unsigned char pad0[12];
    void *fC;
} GsyncStateObj30;

typedef struct GsyncStateObj31 {
    unsigned char pad0[9728];
    unsigned short f2600;
} GsyncStateObj31;

typedef struct GsyncStateObj32 {
    unsigned char pad0[25088];
    unsigned short f6200;
} GsyncStateObj32;

typedef struct GsyncStateObj33 {
    int f0;
} GsyncStateObj33;

typedef struct GsyncStateObj34 {
    int f0;
} GsyncStateObj34;

typedef struct GsyncStateObj35 {
    unsigned char pad0[16];
    int f10;
} GsyncStateObj35;

#endif
