#ifndef OV132_TYPES_H
#define OV132_TYPES_H

/* Object layouts for the ov132 sources, merged from the per-function views. */

struct ActingHost {
    unsigned short f0;
    unsigned char unk_2[2];
    int f4;
    int f8;
    int fC;
    unsigned char unk_10[12];
    unsigned char f1C;
    unsigned char unk_1D[43];
    int f48;
    int f4C;
    void * f50;
    void * f54;
    void * f58;
    unsigned char unk_5C[196];
    unsigned int f120;
    void * f124;
    void * f128;
    unsigned short f12C;
    unsigned char unk_12E[2];
    void * f130;
    void * f134;
    void * f138;
    void * f13C;
    union {
        int s;
        void * p;
    } f140;
    union {
        int s;
        unsigned int u;
    } f144;
    union {
        int s;
        unsigned int u;
    } f148;
    unsigned char f14C;
    unsigned char unk_14D[3];
    int f150;
    int f154;
    int f158;
    unsigned char unk_15C[20];
    unsigned int f170;
    unsigned int f174;
    unsigned int f178;
    int f17C;
    unsigned char f180;
};

struct ActingPartA {
    unsigned char unk_0[20];
    void * f14;
    void * f18;
};

struct ActingPartB {
    unsigned char unk_0[8];
    void * f8;
    unsigned int fC;
};

struct ActingRecord {
    int f0;
    void * f4;
    unsigned char unk_8[14];
    unsigned short f16;
    unsigned char unk_18[38];
    unsigned short f3E;
    unsigned char unk_40[4];
    unsigned short f44;
    unsigned char unk_46[50];
    unsigned short f78;
};

struct ActingScene {
    unsigned short f0;
    unsigned short f2;
    unsigned short f4;
    unsigned short f6;
    unsigned short f8;
    unsigned char fA;
    unsigned char unk_B[5];
    int f10;
    unsigned int f14;
    union {
        unsigned int u;
        void * p;
    } f18;
    unsigned int f1C;
    void * f20;
    union {
        int s;
        unsigned int u;
    } f24;
    union {
        int s;
        unsigned int u;
    } f28;
    union {
        int s;
        unsigned int u;
    } f2C;
    void * f30;
    void * f34;
    void * f38;
    void * f3C;
    void * f40;
    void * f44;
    unsigned char unk_48[12];
    void * f54;
    unsigned char unk_58[8];
    int f60;
    unsigned char unk_64[4];
    int f68;
    void * f6C;
    unsigned char unk_70[12];
    void * f7C;
    unsigned char unk_80[4];
    void * f84;
    unsigned char unk_88[4];
    void * f8C;
    void * f90;
    unsigned char unk_94[16];
    void * fA4;
    void * fA8;
    union {
        unsigned int u;
        void * p;
    } fAC;
    void * fB0;
    union {
        unsigned int u;
        void * p;
    } fB4;
    void * fB8;
    void * fBC;
    unsigned char unk_C0[12];
    union {
        unsigned int u;
        void * p;
    } fCC;
    union {
        unsigned int u;
        void * p;
    } fD0;
    union {
        unsigned int u;
        void * p;
    } fD4;
    union {
        unsigned int u;
        void * p;
    } fD8;
    union {
        unsigned int u;
        void * p;
    } fDC;
    union {
        unsigned int u;
        void * p;
    } fE0;
    union {
        int s;
        unsigned int u;
    } fE4;
    union {
        unsigned int u;
        void * p;
    } fE8;
    int fEC;
    unsigned char fF0;
    unsigned char unk_F1[43];
    unsigned char f11C;
    unsigned char f11D;
    unsigned short f11E;
    int f120;
    unsigned char unk_124[56];
    int f15C;
    int f160;
    unsigned int f164;
    unsigned char unk_168[116];
    int f1DC;
    int f1E0;
    unsigned int f1E4;
    unsigned int f1E8;
    union {
        int s;
        unsigned int u;
    } f1EC;
};

struct HostEntry {
    unsigned char unk_0[16];
    void * f10;
    void * f14;
    void * f18;
    unsigned int f1C;
    void * f20;
    unsigned char unk_24[8];
    unsigned int f2C;
};

struct Obj00995 {
    unsigned char f0;
    unsigned char f1;
    unsigned char f2;
    unsigned char unk_3[1];
    unsigned short f4;
    unsigned char f6;
    unsigned char f7;
};

struct Obj01741 {
    void * f0;
    unsigned int f4;
    unsigned int f8;
    unsigned int fC;
    void * f10;
    unsigned int f14;
    unsigned int f18;
    unsigned int f1C;
    unsigned int f20;
    unsigned int f24;
    unsigned int f28;
    unsigned short f2C;
    unsigned char unk_2E[2];
    void * f30;
    void * f34;
};

struct Obj02192 {
    void * f0;
    void * f4;
    void * f8;
    void * fC;
    unsigned char unk_10[4];
    unsigned int f14;
    unsigned int f18;
    unsigned int f1C;
    int f20;
    int f24;
    int f28;
    unsigned short f2C;
    unsigned short f2E;
    void * f30;
    void * f34;
};

struct Obj02487 {
    unsigned char f0;
    unsigned char unk_1[3];
    void * f4;
    void * f8;
    void * fC;
    unsigned int f10;
    unsigned int f14;
    unsigned int f18;
    unsigned short f1C;
    unsigned short f1E;
    unsigned char unk_20[8];
    void * f28;
    void * f2C;
};

struct Obj05398 {
    unsigned short f0;
    unsigned char unk_2[2];
    void * f4;
    void * f8;
    unsigned char unk_C[40];
    void * f34;
};

struct Obj06489 {
    void * f0;
    int f4;
    unsigned char unk_8[12];
    unsigned short f14;
    unsigned short f16;
};

struct Obj06492 {
    void * f0;
    void * f4;
    void * f8;
    unsigned char unk_C[4];
    unsigned int f10;
    unsigned short f14;
    unsigned char unk_16[18];
    void * f28;
    void * f2C;
    void * f30;
    void * f34;
};

struct Obj10567 {
    unsigned int f0;
    unsigned int f4;
};

struct Obj23284 {
    unsigned char unk_0[4];
    void * f4;
};

struct Obj23285 {
    unsigned char unk_0[4];
    void * f4;
};

struct ScriptCtx {
    union {
        void * p;
        unsigned short h;
    } f0;
    union {
        int s;
        void * p;
    } f4;
    unsigned char unk_8[4];
    int fC;
    unsigned char unk_10[4];
    unsigned short f14;
    unsigned short f16;
    unsigned char f18;
    unsigned char unk_19[45];
    unsigned short f46;
    unsigned char unk_48[16];
    void * f58;
    void * f5C;
};

struct ScriptEntry {
    unsigned char unk_0[4];
    void * f4;
    void * f8;
    void * fC;
    int f10;
    unsigned short f14;
    unsigned short f16;
    unsigned char f18;
    unsigned char f19;
};

struct ScriptOwner {
    unsigned short f0;
    unsigned char unk_2[2];
    void * f4;
    unsigned int f8;
    void * fC;
    int f10;
    int f14;
    int f18;
    unsigned char unk_1C[12];
    unsigned short f28;
    unsigned short f2A;
    unsigned char unk_2C[8];
    void * f34;
    unsigned char unk_38[196];
    int fFC;
    unsigned char unk_100[12];
    int f10C;
    unsigned char unk_110[216];
    void * f1E8;
    unsigned char unk_1EC[16];
    unsigned char f1FC;
    unsigned char unk_1FD[3];
    int f200;
    unsigned char f204;
    unsigned char f205;
};

struct ScriptSlot {
    void * f0;
    union {
        int s;
        unsigned int u;
    } f4;
    union {
        int s;
        unsigned int u;
    } f8;
    unsigned int fC;
    void * f10;
    union {
        int s;
        unsigned int u;
    } f14;
    union {
        unsigned int u;
        void * p;
    } f18;
    union {
        unsigned int u;
        void * p;
    } f1C;
    void * f20;
    void * f24;
    void * f28;
    unsigned short f2C;
    unsigned char unk_2E[2];
    void * f30;
    void * f34;
};

struct ScriptTask {
    void * f0;
    union {
        int s;
        unsigned int u;
        void * p;
    } f4;
    union {
        int s;
        unsigned int u;
    } f8;
    unsigned short fC;
    unsigned short fE;
    void * f10;
    void * f14;
    union {
        void * p;
        unsigned char b;
    } f18;
    void * f1C;
    void * f20;
};

struct TargetBank {
    union {
        int s;
        unsigned int u;
    } f0;
    void * f4;
    unsigned char unk_8[4];
    void * fC;
    int f10;
    unsigned short f14;
    unsigned short f16;
    unsigned char f18;
    unsigned char unk_19[18411];
    union {
        unsigned int u;
        void * p;
    } f4804;
    int f4808;
};

struct TaskObj {
    unsigned short f0;
    unsigned char unk_2[2];
    void * f4;
    void * f8;
    union {
        int s;
        unsigned int u;
    } fC;
    int f10;
    int f14;
    void * f18;
    union {
        unsigned int u;
        void * p;
    } f1C;
    union {
        unsigned int u;
        void * p;
    } f20;
    union {
        unsigned int u;
        void * p;
    } f24;
    union {
        unsigned int u;
        void * p;
    } f28;
    union {
        unsigned int u;
        void * p;
    } f2C;
    union {
        unsigned int u;
        void * p;
    } f30;
    union {
        unsigned int u;
        void * p;
    } f34;
    union {
        unsigned int u;
        void * p;
    } f38;
    union {
        unsigned int u;
        void * p;
    } f3C;
    int f40;
    int f44;
    unsigned short f48;
    unsigned short f4A;
    void * f4C;
    void * f50;
    void * f54;
    void * f58;
    void * f5C;
};

#endif
