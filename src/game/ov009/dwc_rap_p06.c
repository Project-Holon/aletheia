/*
 * file:     dwc_rap_p06.c
 * unit:     yes
 * function: func_02156B70, func_02156B8C, func_02156BA8, func_02156BC4, func_02156BD8, func_02156C00, func_02156C60, func_02156C84, func_02156C98, func_02156CAC, func_02156CD0
 * address:  0x02156B70
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
 *   d_021A8264     0x021A8264  data  ov009  a4
 *   g_021A8264 0x021A8264 data ov009
 *   func_0203D7FC 0x0203D7FC arm
 *   func_0203D798  0x0203D798  arm
 *   func_0203D7C8  0x0203D7C8  arm
 *   func_021770EC  0x021770EC  arm  ov009
 *   d_021A1C60  0x021A1C60  data  ov009  a4
 */
#include "../../matched/include/Obj18652.h"
#include "../../matched/include/Obj18653.h"
#include "../../matched/include/Obj18654.h"
#include "../../matched/include/Obj18655.h"

typedef signed short s16;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

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

extern void func_0203D7FC(void *);
extern void *func_0203D798(void);
extern void *func_0203D7C8(u32, u32, const char *, u16);
extern void func_021770EC(u8, u32, u32);
s16 func_02156B70(void);
int func_02156B8C(void);
int func_02156BA8(void);
void func_02156BC4(int v);
void func_02156BD8(u32 i);
void func_02156C00(u32 a);
void func_02156C60(void);
unsigned char func_02156C84(void);
void func_02156C98(int unused);
int func_02156CAC(void);
int func_02156CD0(void);
extern DwcRapWork *d_021A8264;
extern char *g_021A8264;
extern u8 d_021A1C60[];




/*
 * Reads the signed halfword at +0x782 of the ov009 work block held in the
 * bss pointer at 0x021A8264, or 0 when no block is allocated.  A leaf with
 * no lr-saving prologue whose only caller is in arm9 (sub_0200F698), so
 * the listing emits it as data words.
 */
s16 func_02156B70(void)
{
    if (d_021A8264 != 0)
        return d_021A8264->s782;
    return 0;
}




/*
 * Recursive MATCH unblocker: callee of func_021BF050 (ov099) +0002. Coherent
 * Thumb code only in ov009 (ov010 holds the tail of another function), so the
 * ov009 shard makes that site attest as `matched`.
 */
int func_02156B8C(void)
{
    int *p = (int *)d_021A8264;

    if (p != 0)
        return ((struct Obj18652 *)p)->f774;
    return 0;
}





/*
 * evidence: BL sites in ov099021BF6E0 target this Thumb word-run start;
 *   full body reads nullable global +0x780 as a signed halfword, else -1.
 */
int func_02156BA8(void)
{
    char *p=g_021A8264;
    if(p)return ((struct Obj18653 *)p)->f780;
    return -1;
}






/*
 * Recursive MATCH unblocker: callee of the ov099 veneer func_021C0C7C +0008.
 * Coherent Thumb code only in ov009 (ov010 decodes to a pop with no push), so
 * the ov009 shard makes that site attest as `matched`.
 */
void func_02156BC4(int v)
{
    *(u16 *)((char *)(int *)g_021A8264 + 0x782) = v;
}




void func_02156BD8(u32 i)
{
    void *p;
    p = *(void **)(g_021A8264 + i * 4 + 0x174);
    if (p != 0) {
        func_0203D7FC(p);
        *(void **)(g_021A8264 + i * 4 + 0x174) = 0;
    }
}




void func_02156C00(u32 a)
{
    u8 *p = func_0203D798();
    func_02156BD8(a);
    if (*(u32 *)(g_021A8264 + a * 4 + 0x174) == 0) {
        u32 n = 0x1000;
        *(u32 *)(g_021A8264 + a * 4 + 0x174) =
            (u32)func_0203D7C8(((struct Obj18654 *)p)->f56, n, (const char *)d_021A1C60, 0xb74);
        func_021770EC(a, *(u32 *)(g_021A8264 + a * 4 + 0x174), n);
    }
}




/*
 * Resets the two slots and marks the flag at +0x7a6.
 */
void func_02156C60(void)
{
    int i;

    for (i = 0; i < 2; i++) {
        func_02156BD8(i);
    }

    d_021A8264->b7a6 = 1;
}





/*
 * Byte at +0x7a2 of the block the module pointer holds.
 */
unsigned char func_02156C84(void)
{
    return d_021A8264->b7a2;
}




/*
 * leaf: sole unresolved overlay blocker of concrete-correct ov115/021D43CC;
 * no ARM9 blocker. Parent confirmed no active assignment owns this leaf.
 * Caller leaves its previous integer result in r0; parameter retained.
 */
void func_02156C98(int unused) { ((unsigned char *)d_021A8264)[0x7A2]=0; }




int func_02156CAC(void)
{
    if (d_021A8264) {
        if (d_021A8264->state == 6) return 1;
        return 0;
    }
    return 0;
}



/*
 * Recursive MATCH unblocker: callee of func_021DA434 (ov175) +0002. Coherent
 * Thumb code only in ov009 (ov010 holds the tail of another function), so the
 * ov009 shard makes that site attest as `matched`.
 */
int func_02156CD0(void)
{
    int *p = (int *)d_021A8264;

    if (p != 0) {
        if ((u32)(((struct Obj18655 *)p)->f754 - 9) <= 1)
            return 1;
    }
    return 0;
}
