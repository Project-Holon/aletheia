/*
 * function: func_0204F764
 * address:  0x0204F764
 * packet:   pkt_0204F684
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Copy the caller's word, narrowed to 16 bits, into bit 10 of the +0x18
 * halfword.  The lsl #16 / lsr #16 pair comes from the u16 narrowing and the
 * lsl #31 / lsr #21 pair from the bit write, which is why the C has to keep
 * the narrowing visible: the bit is a 1-bit bitfield assigned a u16 value.
 *
 * symbols:
 *   none (no external calls, no data references)
 */
#include "../include/Obj08866.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Rec {
    u16 lo  : 10;
    u16 b10 : 1;
    u16 hi  : 5;
};

void func_0204F764(void *p, u32 idx, u32 *val)
{
    struct Rec *r = (struct Rec *)(*(u8 * *)&((struct Obj08866 *)p)->f8 + idx * 0x1c + 0x18);

    r->b10 = (u16)*val;
}
