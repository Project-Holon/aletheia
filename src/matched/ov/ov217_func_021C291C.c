/*
 * function: PERCENTAGE_ClearFields
 * address:  0x021C291C
 * packet:   pkt_ov217_021C291C
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * This address is also matched as PERCENTAGE_ClearFields in ov016; the ov217 copy is a
 * distinct function and gets its own shard.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj10967.h"

typedef unsigned short u16;
typedef unsigned char u8;

void PERCENTAGE_ClearFields(char *p, u16 v)
{
    int i;
    ((struct Obj10967 *)p)->f0 = v;
    ((struct Obj10967 *)p)->f2 = 0;
    ((struct Obj10967 *)p)->fC = 0;
    for (i = 0; i < 4; i++)
        *(int *)(p + 0x10 + i * 4) = 0;
}
