/*
 * Shared object layouts of the Pokedex detail screen (ov208), used by the
 * zukan_detail_graphic parts. Offsets are checked against every view.
 */
#ifndef ZUKAN_DETAIL_TYPES_H
#define ZUKAN_DETAIL_TYPES_H

struct Ov208ActDesc {
    int f0;
    short x;
    short y;
    unsigned short h8;
    unsigned short ha;
    unsigned short hc;
    unsigned short he;
    unsigned short h10;
    unsigned short h12;
    unsigned short h14;
    unsigned short h16;
    unsigned int f18;
    unsigned int f1c;
};

struct Ov208ActList {
    struct Ov208ActDesc *descs;
    unsigned int count;
    unsigned int owner;
    unsigned int channel;
    unsigned int pal;
    unsigned int objPal;
    unsigned int kind;
    unsigned int skip;
};

struct Ov208ActSrc {
    int id;
    unsigned short x;
    unsigned short y;
    unsigned short h8;
    unsigned short pad;
    unsigned int fc;
    unsigned int f10;
};

struct Ov208Bg {
    unsigned int f0;
    unsigned int f4;
    unsigned int f8;
    unsigned int fc;
    unsigned int f10;
};

/* One 0x38-byte entry of the manager's table. */
struct Ov208Rec {
    unsigned int f0;
    unsigned int f4;
    unsigned int f8;
    void (*fc)(void);
    unsigned int f10;
    struct Ov208ActDesc desc;
    unsigned int f34;
};

struct Ov208Mgr {
    int f0;
    unsigned int count;
    int f8;
    int fc;
    int f10;
    struct Ov208Bg bg;
    struct Ov208Rec recs[1];
};

struct Ov208Slot {
    struct Ov208ActSrc *src;
    unsigned int obj;
};

struct Ov208Scene {
    unsigned short heap;
    unsigned short pad2;
    unsigned int f4;
    int state;
    int fc;
    int mode;
    unsigned int f14;
    unsigned int f18;
    unsigned int f1c;
    int idx;
    unsigned char step;
    unsigned char pad25[3];
    unsigned int f28;
    unsigned int f2c;
    struct Ov208Mgr *mgr;
    unsigned int f34;
    unsigned int f38;
    unsigned int f3c;
    unsigned int f40;
    unsigned int f44;
    unsigned int f48;
    unsigned int f4c;
    unsigned int f50;
    unsigned int f54;
    unsigned int f58;
    unsigned int f5c;
    unsigned int f60;
    unsigned int f64;
    unsigned char count;
    unsigned char pad69[3];
    struct Ov208Slot slots[9];
    short pos;
    unsigned short palA[16];
    unsigned short palB[16];
    unsigned short palOut[16];
    short pad116;
    int phase;
};

#endif
