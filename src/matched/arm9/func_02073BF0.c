/*
 * function: NNSi_SndStrmUpdate
 * address:  0x02073BF0
 * packet:   pkt_020737C0
 * status:   EXACT
 * isa:      arm
 * compiler: ../2.0/sp2
 * symbols:
 *   gSndStrmChannels     0x0214E934  data
 *   gSndStrmBufferTable     0x0214E8F4  data
 *   func_0209C2B0  0x0209C2B0  arm
 *
 * Per-frame step of the sound object: base = f30 / f34 (func_0209C2B0),
 * fill gSndStrmBufferTable[0 .. f50) with each slot's buffer address plus
 * base * frame, hand the table to the callback at +0x38, then advance the
 * frame counter at +0x40 and wrap it at +0x34.
 *
 * The callback's argument list is (arg, o->f50, gSndStrmBufferTable, base, f28, f3c):
 * the COUNT of entries in the table goes second and the per-frame base
 * fourth (the image's r1 is the f50 the loop test just loaded, r3 the base
 * it copied out of r0 before the multiply).  docs/notes/pkt_02073BF0.c.txt
 * had them as (base, table, i) leftovers, 27 bytes out.  With the right
 * list the residue was 9 bytes, which tools/permuter.py --mode hill closed
 * with two mutations: declaration order step, i, base, and the slot's
 * buffer address bound to its own local before the add.
 */

#include "../include/G_SlotDesc.h"

typedef unsigned char u8;
typedef unsigned int  u32;
typedef signed int    s32;

extern struct SlotDesc gSndStrmChannels[];
extern u32 gSndStrmBufferTable[];

struct Obj {
    u8  pad00[0x28];
    u32 f28;
    u8  pad2c[4];
    u32 f30;
    s32 f34;
    u32 f38;      /* callback */
    u32 f3c;
    s32 f40;      /* frame counter */
    u8  pad44[0xc];
    s32 f50;      /* active slot count */
    u8  f54[4];   /* slot indices */
};

typedef void (*SndSeqCb)(u32 arg, s32 n, u32 *table, u32 base, u32 f28, u32 f3c);

extern u32 func_0209C2B0(u32 a, s32 b);

void NNSi_SndStrmUpdate(struct Obj *o, u32 arg)
{
    u32 step;
    s32 i;
    u32 base;
    u32 addr;

    base = func_0209C2B0(o->f30, o->f34);
    step = base * o->f40;
    for (i = 0; i < o->f50; i++) {
        addr = gSndStrmChannels[o->f54[i]].a;
        gSndStrmBufferTable[i] = addr + step;
    }
    ((SndSeqCb)o->f38)(arg, o->f50, gSndStrmBufferTable, base, o->f28, o->f3c);
    o->f40 = o->f40 + 1;
    if (o->f40 >= o->f34) o->f40 = 0;
}
