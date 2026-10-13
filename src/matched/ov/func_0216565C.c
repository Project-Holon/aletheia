/*
 * function: func_0216565C
 * address:  0x0216565C
 * packet:   pkt_0216565C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Stamp the fixed id halfword and the caller's value on the two
 * record fields, then jump to the shared submitter.
 *
 * symbols:
 *   GAME_BEACON_ResetDetails   0x0202744C  thumb
 */
#include "../include/Obj00121.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void GAME_BEACON_ResetDetails(void *dst);

void func_0216565C(void *a0, unsigned a1)
{
    ((struct Obj00121 *)a0)->f30 = 0x29;
    *(u32 *)((char *)a0 + 0x34) = (u32)a1;
    GAME_BEACON_ResetDetails(a0);
}

