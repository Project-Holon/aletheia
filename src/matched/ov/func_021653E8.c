/*
 * function: func_021653E8
 * address:  0x021653E8
 * packet:   pkt_021653E8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Short thunk: stamp the id halfword on the record and hand it
 * straight to the shared submitter.
 *
 * symbols:
 *   GAME_BEACON_ResetDetails   0x0202744C  thumb
 */
#include "../include/Obj00121.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void GAME_BEACON_ResetDetails(void *dst);

void func_021653E8(void *a0)
{
    ((struct Obj00121 *)a0)->f30 = 0x17;
    GAME_BEACON_ResetDetails(a0);
}

