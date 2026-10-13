/*
 * function: BILLBOARD_SetElemPos
 * address:  0x0204F638
 * packet:   pkt_0204F344
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 *
 * Twelve-byte aggregate copy out of the caller's record into offset +4 of
 * one 0x1c-byte entry: one `ldm`/`stm` of three registers.
 */
#include "../include/Obj16139.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Trip {
    u32 a;
    u32 b;
    u32 c;
};

struct Ent {
    u8  pad_00[0x18];
    u16 f18;
    u8  pad_1a[2];
};

void BILLBOARD_SetElemPos(u8 *a0, int i, struct Trip *src)
{
    struct Ent *e = &((struct Ent *)((struct Obj16139 *)a0)->f8)[i];

    *(struct Trip *)((u8 *)e + 4) = *src;
}
