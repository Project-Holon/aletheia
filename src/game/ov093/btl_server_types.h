#ifndef BTL_SERVER_TYPES_H
#define BTL_SERVER_TYPES_H
/* ov093 battle server: types shared by every part of btl_server.c. */

#ifndef OV093_BASIC_TYPES
#define OV093_BASIC_TYPES
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
#endif

/* One word describing an action; the two views share the first three fields. */
typedef union {
    struct { u32 type:4, select:3, move:16, arg:8, rest:1; } full;
    struct { u32 type:4, select:3, move:3, z:1, rest:21; } small;
    u32 w;
} Action;

typedef struct {
    u8 *a;      /* 0x0 */
    Action b;   /* 0x4 */
    u32 c;      /* 0x8 */
    u8 d;       /* 0xc */
    u8 done;    /* 0xd */
    u8 f;       /* 0xe */
    u8 pad;     /* 0xf */
} Entry;

/* A flag word passed by value to the entry checks. */
typedef union {
    u32 word;
    struct { u32 a:1; u32 b:1; u32 rest:30; } bits;
} CallFlags;

/* A one-word status value passed by value; the views overlap. */
union Slot {
    u32 raw;
    struct { u32 kind:3; u32 rest:29; } k;
};

/* The battle server object: one per battle, passed as p to most functions of the unit. */
typedef struct {
    u8 *f0;  /* 0x0 */
    void *f4;  /* 0x4 */
    void *f8;  /* 0x8 */
    void *fC;  /* 0xc */
    u32 f10;  /* 0x10 */
    u32 f14;  /* 0x14 */
    int f18;  /* 0x18 */
    u8 w1c[0x3c4];  /* 0x1c */
    u8 g3e0[0xc4];  /* 0x3e0 */
    void *f4a4;  /* 0x4a4 */
    u8 *f4a8;  /* 0x4a8 */
    u8 *f4ac;  /* 0x4ac */
    u8 *f4b0;  /* 0x4b0 */
    u8 *f4b4;  /* 0x4b4 */
    u8 w4b8[0x8];  /* 0x4b8 */
    u8 w4c0[0xe];  /* 0x4c0 */
    u8 g4ce[0x6];  /* 0x4ce */
    u8 w4d4[0x2a0];  /* 0x4d4 */
    u32 f774;  /* 0x774 */
    u32 f778;  /* 0x778 */
    u8 init;  /* 0x77c */
    u8 f77d;  /* 0x77d */
    u8 f77e;  /* 0x77e */
    u8 f77f;  /* 0x77f */
    u16 f780;  /* 0x780 */
    u8 n;  /* 0x782 */
    u8 k;  /* 0x783 */
    u8 f784;  /* 0x784 */
    u8 f785;  /* 0x785 */
    u8 f786;  /* 0x786 */
    u8 f787;  /* 0x787 */
    u8 f788;  /* 0x788 */
    u8 f789;  /* 0x789 */
    union {
        u8 raw;
        struct { u8 b0:1, b1:1, b2:1, rest:5; } bits;
    } f78a;  /* 0x78a */
    u8 f78b[0x6];  /* 0x78b */
    u8 set[0x18];  /* 0x791 */
    u8 w7a9[0x18];  /* 0x7a9 */
    u8 flags[0x18];  /* 0x7c1 */
    u8 w7d9[0x7];  /* 0x7d9 */
    Entry e[6];                     /* 0x7e0 */
    Entry t;  /* 0x840 */
    void *f850;  /* 0x850 */
    void *f854;  /* 0x854 */
    void *f858;  /* 0x858 */
    void *f85c;  /* 0x85c */
    void *f860;  /* 0x860 */
    void *f864;  /* 0x864 */
    void *f868;  /* 0x868 */
    void *f86c;  /* 0x86c */
    void *f870;  /* 0x870 */
    u8 w874[0x11f0];  /* 0x874 */
    u32 f1a64;  /* 0x1a64 */
    u8 pad1a68[0x48];
    void *f1ab0;  /* 0x1ab0 */
    void *f1ab4;  /* 0x1ab4 */
    u8 w1ab8[0x2c];  /* 0x1ab8 */
    u8 w1ae4[0x24];  /* 0x1ae4 */
    u8 w1b08[0x48];  /* 0x1b08 */
    u8 w1b50[0x224];  /* 0x1b50 */
    u32 lock;  /* 0x1d74 */
    u8 pad1d78[0x1fc];
    u16 f1f74;  /* 0x1f74 */
    u8 pad1f76[0x2];
    int f1f78;  /* 0x1f78 */
    u8 w1f7c[0xc];  /* 0x1f7c */
    u8 w1f88[0x60];  /* 0x1f88 */
    u8 f1fe8[0x8];  /* 0x1fe8 */

} Server;


/* Types shared by several parts. */
typedef struct { u16 v; } W_021C312C;

typedef struct {
    u32 wpos;
    u32 rpos;
    u8 buf[3000];
} Buf_021CC768;
typedef struct { unsigned low:10, size:9, high:13; } QueueA;
typedef struct { unsigned low:13, size:10, high:9; } QueueB;
typedef struct { unsigned low:28, a:1, b:1, c:1, d:1; } Word_021CC768;

typedef enum { FALSE = 0, TRUE = 1 } BOOL;

struct Copy24 { int x[6]; };

struct Unk021BD1E0 {
    u16 f0;
    u8 f2;
    u8 f3;
    u8 f4;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
};

struct Q { u16 h0; u8 pad[6]; u32 w8; };

struct Lock { u32 a:10; u32 b:9; u32 c:9; u32 d:1; u32 e:1; u32 f:1; u32 g:1; };

struct State_p06 { u8 pad[5]; u8 a:1; u8 b:1; };

typedef struct { u16 v; u16 idx:5, b:4, pad:4, c:1, pad2:1, flag:1; } Rec_td;

typedef struct { u8 pad0[2]; u8 n; u8 pad3[1]; Rec_td r[1]; } List_td;

struct Unk021D62A8 { u8 pad[0x1c]; union Slot e[6]; };

struct Msg { u16 a; u16 kind:8; u16 n:7; u16 flag:1; u8 data[0x1c]; u32 w20; };

enum Kind { K0, K1, K10 = 10 };

typedef struct {
    u32 pad : 8; u32 idx : 5; u32 mid : 10; u32 fl : 1; u32 top : 8;
    u16 h4; u8 b6; u8 b7; u16 h8; u16 ha;
} Ent_021C8D2C;

#endif
