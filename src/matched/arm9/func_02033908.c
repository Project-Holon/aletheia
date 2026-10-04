/*
 * function: func_02033908
 * address:  0x02033908
 * packet:   pkt_02033908
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_020A78CC       0x020A78CC  data
 *   func_02030734    0x02030734  arm
 *   func_02033A88    0x02033A88  arm
 *   MIi_CpuClear32   0x02082A7C  arm
 *
 * Seven arguments, the last three on the stack.  A 0x1c-byte record is taken
 * from the pool `a0` names (tag 0x49) and cleared, four of the caller's
 * values are stored into it (- / +4 / +0x10 / +8 in that order), a second
 * run of 12 * a2 bytes is taken with tag 0x4f and its address goes to +0x14,
 * the last stack argument to +0x18, and the whole record plus the second
 * stack argument goes to func_02033A88.
 *
 * Blocked on: the call to func_02033A88 at +0x98 is the only branch to that
 * address anywhere in the image, so `label` refuses it (its sole witness is
 * this function's own call site) and the site stays wildcarded.  Every other
 * byte, including the other four relocation sites, is right.  0x02033A88 is
 * in pkt_02033A88, not this lane's packets; filing it first would turn this
 * row EXACT with no change to the C.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02033908.c \
 *       --func func_02033908 --addr 0x02033908 --cc 1.1p1 --arm
 */
#include "../include/Obj01312.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32 g_020A78CC[];

extern void *func_02030734(u32 a, u32 b, int c, const char *d, unsigned short e);
extern void  func_02033A88(void *p, u32 a);
extern void  MIi_CpuClear32(u32 v, void *dst, u32 n);

void *func_02033908(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6)
{
    u8 *p = (u8 *)func_02030734(a0, 0x1c, 0, (const char *)g_020A78CC, 0x49);

    MIi_CpuClear32(0, p, 0x1c);
    *(u32 *)&((struct Obj01312 *)p)->f0 = a1;
    ((struct Obj01312 *)p)->f4 = a2;
    ((struct Obj01312 *)p)->f10 = a3;
    ((struct Obj01312 *)p)->f8 = a4;
    *(u32 *)&((struct Obj01312 *)p)->f14 = (u32)func_02030734(a0, a2 * 12, 1, (const char *)g_020A78CC, 0x4f);
    ((struct Obj01312 *)p)->f18 = a6;
    func_02033A88(p, a5);
    return p;
}
