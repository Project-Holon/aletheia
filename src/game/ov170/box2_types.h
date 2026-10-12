/*
 * Shared object layouts of the ov170 box screens (box2_*.c, unit_*.c).
 * Offsets are the offsets the code uses; fields are named by offset.
 */
#ifndef OV170_BOX2_TYPES_H
#define OV170_BOX2_TYPES_H

/* The task object (0x30 bytes). f2C is the work area. */
typedef struct BoxTask {
    void * f0;
    void * f4;
    int f8;
    void * fC;
    unsigned short f10;
    unsigned char f12;
    unsigned char f13;
    unsigned char f14;
    unsigned char f15;
    unsigned char f16;
    unsigned char f17;
    unsigned char f18;
    unsigned char f19;
    unsigned char f1A;
    unsigned char f1B;
    unsigned char f1C;
    unsigned char f1D;
    unsigned char f1E;
    unsigned char f1F;
    unsigned char f20;
    unsigned char f21;
    unsigned char pad_22[0x6];
    int f28;
    void * f2C;
} BoxTask;

/* The work area behind BoxTask.f2C. Only the fields the code uses. */
typedef struct BoxWork {
    void * f0;
    void * f4;
    void * f8;
    unsigned char pad_C[0x4C];
    int f58;
    int f5C;
    void * f60;
    short f64;
    short f66;
    unsigned char pad_68[0xC];
    void * f74;
    unsigned int f78;
    unsigned char pad_7C[0x4];
    void * f80;
    void * f84;
    void * f88;
    unsigned char pad_8C[0x8];
    void * f94;
    unsigned char pad_98[0x4C];
    unsigned int fE4;
    unsigned char pad_E8[0x4];
    unsigned int fEC;
    unsigned char pad_F0[0x4];
    unsigned int fF4;
    unsigned char pad_F8[0x4];
    unsigned int fFC;
    unsigned char pad_100[0x4];
    void * f104;
    unsigned char pad_108[0x4];
    void * f10C;
    unsigned char pad_110[0x4];
    void * f114;
    unsigned char pad_118[0x4];
    void * f11C;
    unsigned char pad_120[0x4];
    void * f124;
    unsigned char pad_128[0x4];
    void * f12C;
    unsigned char pad_130[0x80];
    int f1B0;
    unsigned char pad_1B4[0x9CBC];
    int f9E70;
    unsigned char pad_9E74[0x160];
    void * f9FD4;
    unsigned char pad_9FD8[0xB0];
    int fA088;
    int fA08C;
    unsigned char pad_A090[0x68];
    void * fA0F8;
    unsigned char pad_A0FC[0xC];
    void * fA108;
    int fA10C;
    int fA110;
    void * fA114;
    unsigned char pad_A118[0x8];
    unsigned int fA120;
    void * fA124;
    unsigned char pad_A128[0xC];
    void * fA134;
    int fA138;
    int fA13C;
    unsigned char pad_A140[0x14];
    void * fA154;
    unsigned char pad_A158[0x21];
    unsigned char fA179;
    unsigned char pad_A17A[0x1A];
    int fA194;
} BoxWork;

/* The sequence block at BoxWork + 0x58. */
typedef struct BoxSeq {
    unsigned char pad_0[0x8];
    void * f8;
    unsigned short fC;
    unsigned short fE;
} BoxSeq;

#endif
