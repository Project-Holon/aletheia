/*
 * function: GAME_BEACON_SetInfoZone
 * address:  0x0202737C
 * packet:   pkt_0202735C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02166C7C  0x02166C7C  thumb
 *   GAME_BEACON_ResetDetails  0x0202744C  thumb
 */
#include "../include/Obj00121.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;


extern u32 func_02166C7C(u32 a0);
extern void GAME_BEACON_ResetDetails(void *dst);

void GAME_BEACON_SetInfoZone(u32 *p, u32 a1, u32 a2)
{
    p[1] = (p[1] & 0xf801ffff) | ((a1 & 0x3ff) << 17);
    p[2] = (p[2] & 0x003fffff) | (func_02166C7C(a2) << 22);
    ((struct Obj00121 *)p)->f48 = (((struct Obj00121 *)p)->f48 & ~0xff) | 5;
    GAME_BEACON_ResetDetails(p);
}
