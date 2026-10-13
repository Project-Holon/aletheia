/*
 * function: BILLBOARD_GetElemId
 * address:  0x0204F5E4
 * packet:   pkt_0204F344
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 *
 * Fourteen-bit field getter on the 0x1c-byte entries at +8: the shift pair
 * is an equal `lsl #0x12` / `lsr #0x12`, i.e. a mask that is not an ARM
 * immediate, and the stride is spelled as byte arithmetic so it comes out as
 * `mul` rather than `mla`.
 */
#include "../include/Obj16136.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct F14 {
    u16 f0 : 14;
    u16 f1 : 2;
};

void BILLBOARD_GetElemId(u8 *a0, u32 i, u16 *out)
{
    *out = ((struct F14 *)((u8 *)((struct Obj16136 *)a0)->f8 + i * 0x1c))->f0;
}
