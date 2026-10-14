/*
 * function: WORLDTRADE_SERVER_WaitSave
 * address:  0x02202094
 * packet:   pkt_02202094
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb  arm9
 *   GAME_DATA_SaveMain  0x02012DD0  thumb  arm9
 *

 * When the mode query answers 1, publish the u16 at +0xe0c.
 */
#include "../include/Obj09249.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern int GAME_DATA_SaveMain(u8 *p);

int WORLDTRADE_SERVER_WaitSave(u8 *p)
{
    if (GAME_DATA_SaveMain(GAMESYSTEM_GetGameData((const struct Ctx *)(*(u32 *)(((struct Obj09249 *)p)->f0 + 0x40)))) == 1) {
        ((struct Obj09249 *)p)->f28 = ((struct Obj09249 *)p)->fE0C;
    }
    return 2;
}
