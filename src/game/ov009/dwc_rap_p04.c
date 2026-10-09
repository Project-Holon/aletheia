/*
 * file:     dwc_rap_p04.c
 * unit:     yes
 * function: func_0215683C, func_02156860, func_02156874
 * address:  0x0215683C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021A1C5C 0x021A1C5C data ov009 a1
 *   func_02034714 0x02034714 arm
 *   func_021688FC 0x021688FC arm ov009
 *   d_021A8264     0x021A8264  data  ov009  a4
 */

typedef unsigned int   u32;

typedef unsigned char u8;

typedef unsigned short u16;

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
    void (*cb2A8)(void);                /* 0x2A8 */
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

extern DwcRapWork *d_021A8264;

extern void func_02034714(const char *expr, u32 line, const char *file);
extern int func_021688FC(char *, unsigned long);
int func_0215683C(char *a, int b);
int func_02156860(int i);
unsigned char func_02156874(int i);
extern char d_021A1C5C[];

int func_0215683C(char *a, int b)
{
    if (b > 32)
        func_02034714(d_021A1C5C, 0, d_021A1C5C);
    return func_021688FC(a, b);
}


/*
 * Recursive MATCH unblocker: callee of the ov099 veneer func_021C23B8 +0004.
 * Coherent Thumb code only in ov009 (ov010 opens with adds r3,r7,#0 and an
 * immediate branch), so the ov009 shard makes that site attest as `matched`.
 */
int func_02156860(int i)
{
    return (int)((char *)(int *)d_021A8264 + 0x34C + (i << 5));
}


/*
 * Byte at +0x32c past the index of the block the module pointer holds.
 */
unsigned char func_02156874(int i)
{
    return *(unsigned char *)(((char *)d_021A8264) + i + 0x32c);
}
