/*
 * function: MOVE_POKEMON_SurfEventMain
 * address: 0x0215EB88
 * packet: pkt_ov010_0215EB88
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetEventWork 0x0201296C thumb
 *   SCRIPT_SYS_ChangeScriptEvent 0x021587B0 thumb ov010
 *   SCRIPT_WORK_SetParams 0x02159058 thumb ov010
 * Interface: 021587B0 returns its final ldr r0,[r4] at 021587DC;
 * caller consumes that result despite older callers declaring void.
 */
#include "../include/Obj12313.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct BigObj;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);
extern int SCRIPT_SYS_ChangeScriptEvent(int a0, int a1, int a2, int a3);
extern int SCRIPT_WORK_SetParams(int a, int b, int c, int d, u16 e);
int MOVE_POKEMON_SurfEventMain(void *a, int *state, void *b)
{
    int h;
    int t;
    GAME_DATA_GetEventWork(GAMESYSTEM_GetGameData(((struct Obj12313 *)b)->f8));
    h = ((struct Obj12313 *)b)->fC;
    t = SCRIPT_SYS_ChangeScriptEvent((int)a, 0x2717, 0, 0);
    SCRIPT_WORK_SetParams(t, h, 0, 0, 0);
    return 0;
}
