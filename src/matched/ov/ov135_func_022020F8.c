/*
 * function: WORLDTRADE_SERVER_WaitSaveB
 * address: 0x022020F8
 * packet: pkt_ov135_022020F8
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_SaveMain 0x02012DD0 thumb
 *   WORLDTRADE_SetStateAndReturn 0x021F4EC0 thumb ov135
 *   WORLDTRADE_DeleteTimeIcon 0x021F4FC4 thumb ov135
 *   WORLDTRADE_INPUT_PrintStringPlain 0x021F90A0 thumb ov135
 *   WORLDTRADE_SetNextState 0x021F4E98 thumb ov135
 */
#include "../include/Obj00018.h"
#include "../include/Obj23459.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern int GAME_DATA_SaveMain(u8 *p);
extern void WORLDTRADE_SetStateAndReturn(u8 *p, u32 a, u32 b);
extern void WORLDTRADE_DeleteTimeIcon(u8 *p);
extern void WORLDTRADE_INPUT_PrintStringPlain(u32 a, u32 b, u32 c, u32 d, u16 e);
extern void WORLDTRADE_SetNextState(u8 *p, u32 a, u32 b);
int WORLDTRADE_SERVER_WaitSaveB(u8 *p)
{
    if (GAME_DATA_SaveMain(GAMESYSTEM_GetGameData(((struct Obj23459 *)(*(u8 * *)&((struct Obj00018 *)p)->f0))->f40)) == 2) {
        WORLDTRADE_SetStateAndReturn(p, 1, 0);
        WORLDTRADE_DeleteTimeIcon(p);
        WORLDTRADE_INPUT_PrintStringPlain((u32)p, (u32)(((struct Obj00018 *)p)->fB6C), ((struct Obj00018 *)p)->f24, 1, 0xF0F);
        WORLDTRADE_SetNextState(p, 0x2A, 0x20);
    }
    return 2;
}
