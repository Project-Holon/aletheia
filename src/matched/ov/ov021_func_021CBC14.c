/*
 * function: func_021CBC14
 * address:  0x021CBC14
 * packet:   pkt_ov021_021CBC14
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Shows the kind's message (20/21/22) with the +0x10 number capped at 9999 and reports whether it ended with 2 or 3.
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_GetGameSystem  0x02158F54  thumb  ov010
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetCurrentEvent  0x02012ED8  thumb
 *   BATTLE_REC_Save  0x0200B6E0  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12976.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRIPT_WORK_GetGameSystem(void *a);
struct Big;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetCurrentEvent(struct Big *p);
extern u32 BATTLE_REC_Save(void *a, u16 b, u32 c, u32 d, u32 e, u16 *state, u16 *sub);

int func_021CBC14(u32 unused, u32 a)
{
    void *t;
    u8 *p;
    int id;
    int v;
    int r;

    t = GAMESYSTEM_GetGameData(SCRIPT_WORK_GetGameSystem(SCRCMD_WORK_GetScriptWork((void *)a)));
    p = GAME_DATA_GetCurrentEvent(t);
    id = 20;
    v = ((struct Obj12976 *)p)->f10;
    switch (p[9]) {
    case 0:
    case 4:
    case 5:
        break;
    case 1:
    case 6:
        id = 21;
        break;
    case 2:
    case 3:
    case 7:
    case 8:
        id = 22;
        break;
    }
    if (v > 9999)
        v = 9999;
    r = BATTLE_REC_Save(t, 4, id, v, 0, (u16 *)(p + 0x7e8), (u16 *)(p + 0x7ea));
    if (r == 2 || r == 3)
        return 1;
    return 0;
}
