/*
 * function: SCRCMD_TRIALHOUSE_StartBattle
 * address:  0x0216A560
 * packet:   pkt_0216A560
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * blocked:  listing 52 compiled 50
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetListCursor  0x02012F50  thumb
 *   FLD_BTL_INST_TOOL_CreateBattleEvent  0x02168CF4  thumb  ov010
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 */
#include "../include/Obj17757.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Ctx;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetListCursor(void *base);
extern void *FLD_BTL_INST_TOOL_CreateBattleEvent();
extern int SCRIPT_SYS_CallEvent();

int SCRCMD_TRIALHOUSE_StartBattle(int a0, int a1)
{
    int t4;
    void *p;
    void *task;
    void *v0;
    void *v1;
    void *v2;

t4 = a1 + 0;
a0 = t4 + 0;
    v0 = SCRCMD_WORK_GetScriptWork((void *)a0);
loc_0216A56A:
a0 = t4 + 0;
    v1 = SCRCMD_WORK_GetGameSystem((void *)a0);
loc_0216A572:
    p = GAMESYSTEM_GetGameData((const struct Ctx *)v1);
loc_0216A578:
    v2 = GAME_DATA_GetListCursor(p);
loc_0216A57C:
a1 = ((struct Obj17757 *)((char *)v2))->f0;
    task = FLD_BTL_INST_TOOL_CreateBattleEvent(v1, a1);
loc_0216A586:
    a0 = SCRIPT_SYS_CallEvent(v0, task);
loc_0216A58E:
a0 = 1;
    return a0;}
