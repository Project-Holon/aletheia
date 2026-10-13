/*
 * function: BILLBOARD_SetElemRotZ
 * address:  0x0204F7C4
 * packet:   pkt_0204F684
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Halfword store at +0x16 of one 0x1c-byte entry of the descriptor's +8
 * array.  Note +0x16 rather than +0x12/+0x14 - it is the third of the three
 * halfword fields that BILLBOARD_SetElemScale and BILLBOARD_SetElemAlpha's family work on, and
 * it is the follower that makes BILLBOARD_SetElemFlipT EXACT*.
 *
 * Unlabelled in the generated listing: the prologue saves nothing.  Seeding
 * 0x0204F7C4 in layout/function_starts.txt turns that EXACT* into EXACT; that
 * file is the integrator's, not this packet's.
 */
#include "../include/Obj16149.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ent {
    u8  pad_00[0x16];
    u16 f16;
    u8  pad_18[4];
};

void BILLBOARD_SetElemRotZ(u8 *a0, int i, u16 *src)
{
    struct Ent *e = &((struct Ent *)((struct Obj16149 *)a0)->f8)[i];

    e->f16 = *src;
}
