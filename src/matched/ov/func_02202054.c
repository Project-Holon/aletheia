/*
 * function: func_02202054
 * address:  0x02202054
 * packet:   pkt_02202054
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb  arm9
 *   GAME_DATA_SaveStart  0x02012DAC  thumb  arm9
 *

 * Latch state 0x23 and publish the +2 tick of the 0x3c query into +0xdfc.
 */
#include "../include/Obj09248.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern int GAME_DATA_SaveStart(int a0);
extern u32 func_020056EC(u32 v);

int func_02202054(u8 *p)
{
    GAME_DATA_SaveStart((int)GAMESYSTEM_GetGameData((const struct Ctx *)(*(u32 *)(((struct Obj09248 *)p)->f0 + 0x40))));
    ((struct Obj09248 *)p)->f28 = 0x23;
    ((struct Obj09248 *)p)->fDFC = func_020056EC(0x3c) + 2;
    return 2;
}
