/*
 * docs/families/cluster_02051B84.h -- declarations for the pseudo-family
 * around 0x02051B84..0x02051DE8 in the ARM9 image.  REFERENCE ONLY.
 *
 * The per-frame touch-slot refresh (func_02051C88, OPEN, DIFF 19 at 352/352
 * under dsi/1.1p1 -- see docs/notes/pkt_02051C88.c.txt) over a context whose
 * slots are 4-byte { kind, state } records, dispatched through the eight-entry
 * handler table at 0x020A15E8.  ../2.0/sp2 is 360+ on every spelling: 1.1p1.
 * ISA: ARM.
 *
 * LEVER (wave 12): the two slot compares are `a == i` with s32 a and u32 i
 * (an unsigned compare, NO cast); that is what keeps the fourth constant 1
 * in its own register (fp) and makes the function size-exact.
 */
#ifndef CLUSTER_02051B84_H
#define CLUSTER_02051B84_H

typedef unsigned char u8;
typedef unsigned int  u32;
typedef signed   int  s32;

struct Slot { u8 kind; u8 state; u8 pad[2]; };

struct Ctx {
    s32   f00;                          /* 0x00  input source handle          */
    u32   n;                            /* 0x04  slot count                   */
    void (*cb)(s32 i, s32 v, s32 arg);  /* 0x08                               */
    s32   arg;                          /* 0x0c                               */
    struct Slot *slots;                 /* 0x10                               */
};

extern s32 (*const g_020A15E8[])(struct Slot *, s32, s32);  /* handler table */
extern s32 func_02035C38(void);        /* input live?                         */
extern s32 func_02035BA4(s32 h);       /* touched slot index                  */
extern s32 func_02035C08(s32 h);       /* hovered slot index                  */
extern s32 func_02035C60(void);        /* shared third handler argument       */
extern s32 func_02051C88(struct Ctx *c);

#endif /* CLUSTER_02051B84_H */
