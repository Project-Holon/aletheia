/*
 * function: WORLDTRADE_CancelSave
 * address:  0x021F513C
 * packet:   pkt_021F513C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0200F7C0   0x0200F7C0  thumb
 *   GAME_DATA_SaveCancel  0x02012E08  thumb  arm9
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb  arm9
 *
 * Shape: mode query pair, then the 0x29 command byte.  0x0200F7C0 is a
 * thumb leaf whose EXACT arm9 entry attests the call once the symbols line
 * declares the true ISA.
 */
#include "../include/Obj18539.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void GAME_DATA_SaveCancel(char *p);
extern void func_0200F7C0(u32 c);

void WORLDTRADE_CancelSave(u8 *p)
{
    GAME_DATA_SaveCancel(GAMESYSTEM_GetGameData((const struct Ctx *)(*(u32 *)(((struct Obj18539 *)p)->f0 + 0x40))));
    func_0200F7C0(0x29);
}
