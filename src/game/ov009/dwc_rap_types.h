/* Work block of the DWC RAP module: the area d_021A8264 points to. */
#ifndef DWC_RAP_TYPES_H
#define DWC_RAP_TYPES_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef void (*RapRecvCb)(u32, u8 *, u16);

typedef struct DwcRapWork {
    union { int hdr; u8 b[4]; } pkt;    /* 0x000 */
    u8 pktdata[0xFC];                   /* 0x004 */
    u8 *friend_list;                    /* 0x100 */
    u8 pad104[4];
    void *userdata;                     /* 0x108 */
    u8 x10C[0x174 - 0x10C];             /* 0x10C */
    void *buf[2];                       /* 0x174 */
    int arr[32];                        /* 0x17C */
    int arr2[32];                       /* 0x1FC */
    RapRecvCb cb0;                      /* 0x27C */
    RapRecvCb cb1;                      /* 0x280 */
    void (*cb284)(u32, u32);            /* 0x284 */
    u32 arg288;                         /* 0x288 */
    int (*cb28C)(u32, u32, u32, int);   /* 0x28C */
    u32 arg290;                         /* 0x290 */
    int (*cb294)(u32, u32, u32, int);   /* 0x294 */
    u32 arg298;                         /* 0x298 */
    void (*cb29C)(int, int);            /* 0x29C */
    int arg2A0;                         /* 0x2A0 */
    int (*cb2A4)(int, u32);             /* 0x2A4 */
    void (*cb2A8)(int);                 /* 0x2A8 */
    char name[0x80];                    /* 0x2AC */
    u8 bytes[32];                       /* 0x32C */
    u8 ent[32][0x20];                   /* 0x34C */
    u32 w74C;                           /* 0x74C */
    int w750;                           /* 0x750 */
    int state;                          /* 0x754 */
    int err;                            /* 0x758 */
    int mode;                           /* 0x75C */
    int f760;                           /* 0x760 */
    int n;                              /* 0x764 */
    int aid;                            /* 0x768 */
    int f76c;                           /* 0x76C */
    int idx;                            /* 0x770 */
    int f774;                           /* 0x774 */
    int f778;                           /* 0x778 */
    int w77C;                           /* 0x77C */
    short s780;                         /* 0x780 */
    short s782;                         /* 0x782 */
    int cnt[3];                         /* 0x784 */
    int f790;                           /* 0x790 */
    u16 h794;                           /* 0x794 */
    u16 h796;                           /* 0x796 */
    int f798;                           /* 0x798 */
    u8 seq;                             /* 0x79C */
    u8 b79d;
    u8 b79e;
    u8 b79f;
    u8 b7a0;
    u8 b7a1;
    u8 b7a2;
    u8 b7a3;
    u8 b7a4;
    u8 b7a5;
    u8 b7a6;
    u8 b7a7;
    u8 b7a8;
    u8 b7a9;
    u8 pad7AA[2];
} DwcRapWork;

/* The ov009 context block that func_0203D798 returns. */
typedef struct RapCtx {
    char pad0[0x3C];
    void (*cb3C)(u32, u32, u32);        /* 0x3C */
    char pad40[0x48 - 0x40];
    int heap_size;                      /* 0x48 */
    char pad4C[0x56 - 0x4C];
    u16 heap;                           /* 0x56 */
    u16 heap2;                          /* 0x58 */
    char pad5A[0x60 - 0x5A];
    u8 b60;                             /* 0x60 */
} RapCtx;

extern RapCtx *func_0203D798(void);

/* Heap object that d_021A8268 points to (the module's own allocation). */
typedef struct RapHeap {
    u32 heap;                           /* 0x00 handle of the main heap */
    u32 mem;                            /* 0x04 its backing block */
    u32 sub_heap;                       /* 0x08 secondary heap, 0 when none */
    u32 sub_mem;                        /* 0x0C its backing block */
    u32 sub_id;                         /* 0x10 owner id the secondary heap serves */
    u32 sub_users;                      /* 0x14 live blocks in the secondary heap */
    u32 sub_limit;                      /* 0x18 smallest request that is not served from it */
    u32 failed;                         /* 0x1C set when an allocation failed */
    u16 tag;                            /* 0x20 */
} RapHeap;

#endif
