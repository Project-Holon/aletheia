/*
 * function: func_022020B8
 * address:  0x022020B8
 * packet:   pkt_022020B8
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F4FC4  0x021F4FC4  thumb  ov135
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb  arm9
 *   GAME_DATA_SaveMain  0x02012DD0  thumb  arm9

 * When the mode query answers 2, publish the u16 at +0xe0e and hand the object back.
 */
#include "../include/Obj09250.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern int GAME_DATA_SaveMain(u8 *p);
extern void func_021F4FC4(u8 *p);

int func_022020B8(u8 *p)
{
    if (GAME_DATA_SaveMain(GAMESYSTEM_GetGameData((const struct Ctx *)(*(u32 *)(((struct Obj09250 *)p)->f0 + 0x40)))) == 2) {
        ((struct Obj09250 *)p)->f28 = ((struct Obj09250 *)p)->fE0E;
        func_021F4FC4(p);
    }
    return 2;
}
