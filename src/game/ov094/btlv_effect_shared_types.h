#ifndef BTLV_EFFECT_SHARED_TYPES_H
#define BTLV_EFFECT_SHARED_TYPES_H

#include "btlv_effvm_types.h"
#include "btlv_camera_shared_types.h"

struct Ctx;

struct Res;

struct PalAnmSlot;

struct Node;

struct W;

struct O;

struct S02030EE8;

typedef enum { SLOT_ZERO, SLOT_LAST = 14 } Slot_021F6560;

typedef unsigned long long u64;

typedef struct {
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
    unsigned int  w1;
    unsigned int  w2;
    unsigned short h1;
} S9844;

typedef struct {
    void *h;
    char pad04[0x44];
    int k48;
    unsigned int f0 : 1;
    unsigned int f1 : 1;
    unsigned int flip : 1;
    char pad50[0x0c];
} Entry_021FEAC0;

typedef struct {
    unsigned int b0 : 1;
    unsigned int b1 : 1;
} Flags_021FEAC0;

typedef struct {
    int *cb;                /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_021FEAC0 e[14];            /* 0x008 */
    Flags_021FEAC0 flags;            /* 0x510 */
    char pad514[0x534 - 0x514];
    int active;             /* 0x534 */
    int scaleEven;          /* 0x538 */
    int scaleOdd;           /* 0x53c */
    u16 heap;               /* 0x540 */
} Work_021FEAC0;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x24];
    void *task;             /* 0x28 */
    char pad2c[0x30];
} Entry_021FEB78;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_021FEB78 e[14];            /* 0x008 */
} Work_021FEB78;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x48];
    unsigned int f0 : 1;    /* 0x4c */
    unsigned int f1 : 1;
    unsigned int f2 : 5;
    unsigned int f7 : 1;
    unsigned int f8 : 1;
    unsigned int f9 : 2;
    unsigned int f11 : 1;
    int f50;                /* 0x50 */
    int f54;                /* 0x54 */
    int f58;                /* 0x58 */
} Entry_021FEBAC;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_021FEBAC e[14];            /* 0x008 */
    unsigned int pad510 : 2;    /* 0x510 */
    unsigned int f510 : 1;
    int m514;
    int m518;
    int m51c;
    int m520;
    int m524;
    int m528;               /* 0x528 */
} Work_021FEBAC;

typedef struct {
    void *h;
    char pad04[0x44];
    int k48;
    unsigned int f0 : 1;
    unsigned int f1 : 1;
    unsigned int flip : 1;
    char pad50[0x0c];
} Entry_021FE254;

typedef struct {
    int pad00;
    void *obj;
    Entry_021FE254 e[14];
} Work_vE254;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x24];
    void *task;             /* 0x28 */
    char pad2c[0x30];
} Entry_021FF0F8;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_021FF0F8 e[14];            /* 0x008 */
} Work_021FF0F8;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x24];
    void *task;             /* 0x28 */
    char pad2c[0x30];
} Entry_021FF144;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_021FF144 e[14];            /* 0x008 */
} Work_021FF144;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x48];
    unsigned int f0 : 1;    /* 0x4c */
    unsigned int f1 : 1;
    unsigned int flip : 1;
    char pad50[0x0c];
} Entry_021FF16C;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_021FF16C e[14];            /* 0x008 */
    char pad[0x534 - 0x008 - 14 * 0x5c];
    int active;             /* 0x534 */
    fx32 scaleEven;         /* 0x538 */
    fx32 scaleOdd;          /* 0x53c */
} Work_021FF16C;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x48];
    unsigned int f0 : 1;    /* 0x4c */
    unsigned int f1 : 1;
    unsigned int flip : 1;
    char pad50[0x0c];
} Entry_021FF228;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_021FF228 e[14];            /* 0x008 */
} Work_021FF348;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x48];
    unsigned int f0 : 5;    /* 0x4c */
    unsigned int f5 : 1;
    char pad50[0x0c];
} Entry_021FF374;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_021FF374 e[14];            /* 0x008 */
} Work_vF228;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x44];
    int key;                /* 0x48 */
    unsigned int pad4c : 6; /* 0x4c */
    unsigned int f6 : 1;
    char pad50[0x0c];
} Entry_021FF7B0;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_021FF7B0 e[14];            /* 0x008 */
} Work_021FF7B0;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x58];
} Entry_021FFCB0;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_021FFCB0 e[14];            /* 0x008 */
    unsigned int pad510 : 2;    /* 0x510 */
    unsigned int f510 : 1;
    int m514;              /* 0x514 */
    int m518;               /* 0x518 */
    int m51c;               /* 0x51c */
    int m520;               /* 0x520 */
    int m524;               /* 0x524 */
    int m528;               /* 0x528 */
    int m52c;               /* 0x52c */
    int m530;               /* 0x530 */
} Work_021FFCB0;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x48];
    unsigned int f0 : 1;    /* 0x4c */
    unsigned int f1 : 1;
    unsigned int flip : 1;
    char pad50[0x0c];
} Entry_021FFD6C;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_021FFD6C e[14];            /* 0x008 */
} Work_021FFD6C;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x48];
    u32 flags;              /* 0x4c */
    char pad50[0x0c];
} Entry_021FFDB4;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_021FFDB4 e[14];            /* 0x008 */
} Work_vFCB0;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x28];
    u32 a;                  /* 0x2c (w+0x34) */
    u32 b;                  /* 0x30 (w+0x38) */
    u32 c;                  /* 0x34 (w+0x3c) */
    u16 d;                  /* 0x38 (w+0x40) */
    u16 e;                  /* 0x3a (w+0x42) */
    u32 f;                  /* 0x3c (w+0x44) */
    u32 flags0;             /* 0x40 (w+0x48) */
    char pad44[0x08];
    u32 flags;              /* 0x4c (w+0x54) */
    char pad50[0x0c];
} Entry_021FFE48;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_021FFE48 e[14];            /* 0x008 */
} Work_021FFE48;

typedef struct {
    int w[9];
} Rec_022001DC;

typedef struct {
    void *h;                /* 0x00 */
    Rec_022001DC rec;                /* 0x04 */
    char pad28[0x0c];
    int k34;                /* 0x34 */
    char pad38[0x24];
} Entry_022001DC;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_022001DC e[14];            /* 0x008 */
} Work_022001DC;

typedef struct {
    void *owner;            /* 0x000 */
    char pad004[0x510 - 4];
    u32 flags;              /* 0x510 */
    char pad514[0x540 - 0x514];
    u16 heap;               /* 0x540 */
} Work_02200344;

typedef struct {
    int pad00;              /* 0x00 */
    void *obj;              /* 0x04 */
} Work_022003EC;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x58];
} Entry_0220055C;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_0220055C e[14];            /* 0x008 */
} Work_0220055C;

typedef struct {
    void *h;               /* 0x00 */
    char pad04[0x48];
    unsigned int lo : 10;   /* 0x4c */
    unsigned int f10 : 1;
    unsigned int hi : 21;
    char pad50[0x0c];
} Entry_02200608;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_02200608 e[14];            /* 0x008 */
} Work_02200608;

typedef struct Res_02201894 {
    void *owner;
    void *h;
    char pad[0x80 - 8];
    u16 heap;
} Res_02201894;

typedef struct Ent_02201AC4 { void *h8; void *hc; void *h10; void *h14; } Ent_02201AC4;

typedef struct Res_02201AC4 { void *owner; void *h; Ent_02201AC4 e[7]; } Res_02201AC4;

struct W { unsigned char pad[0x68]; unsigned int pad15 : 15; unsigned int f : 2; };

typedef struct Main_v3880 {
    void *owner;
    char pad04[0x60];
    void *pal64;
    unsigned int f0:1, st:3, hi:28;
    char pad6c[0x1bc];
    void *obj228;
} Main_v3880;

typedef struct { Main_v3880 *main; int state; } Ctx;

typedef struct {
    char pad00[0x40];
    int kind;
    char pad44[0x3c];
} Slot_02206BC8;

typedef struct {
    void *f00;
    void *h04;
    int f08;
    void *f0c;
    void *f10;
    int f14;
    int f18[6];
    int f30, f34, f38, f3c;
    Slot_02206BC8 slot[8];
    int f440;
    int f444;
    u16 heap;
} Obj_02206BC8;

typedef struct Obj_02206EB4 Obj_02206EB4;

typedef struct {
    char pad[0xc];
    Obj_02206EB4 *h;
    char pad10[0x38];
    int a, b, f90;
    char pad54[0x1c];
    u32 b0:1, b1:1, b2:1, b3:1, lo:4, count:8, mid:4, b20:1, flash:5, b26:1, b27:1, b28:1, b29:1, hi:2;
    char pad74[0xc];
} Row_02206BC8;

typedef struct W_02206BC8 {
    char pad[0x40];
    Row_02206BC8 rows[8];
    struct { u32 lo:4, b4:1, mid:16, b21:1, b22:1, hi:9; } flags;
} W_02206BC8;

typedef struct { char pad[0x40]; u32 mode, side, a, b, f90, f94, f98, f9c, fa0, fa4, fa8; u8 level, sex, fae, seen; u32 flags, fb4, fb8, fbc; } Row_022070C0;

typedef struct W_022070C0 { char pad[0x40]; Row_022070C0 rows[8]; } W_022070C0;

typedef struct { char pad[0x40]; u32 mode, side, a, b, f90, f94, f98, f9c, fa0, fa4, fa8; u8 level, sex, fae, seen; u32 flags, fb4, fb8, fbc; } Row_022064CC;

typedef struct W_02207288 { char pad[0x40]; Row_022064CC rows[8]; } W_02207288;

#endif
