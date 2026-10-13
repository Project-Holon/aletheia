/*
 * function: func_022020E0
 * address:  0x022020E0
 * packet:   pkt_022020E0
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb  arm9
 *   GAME_DATA_SaveStart  0x02012DAC  thumb  arm9
 *

 *
 * Run the sub-object init, stamp 0x27 and report 2.
 */
#include "../include/Obj12245.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern int GAME_DATA_SaveStart(int a0);

int func_022020E0(u8 *p)
{
    GAME_DATA_SaveStart((int)GAMESYSTEM_GetGameData((const struct Ctx *)(*(u32 *)(((struct Obj12245 *)p)->f0 + 0x40))));
    ((struct Obj12245 *)p)->f28 = 0x27;
    return 2;
}
