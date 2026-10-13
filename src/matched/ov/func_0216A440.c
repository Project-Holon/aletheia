/*
 * function: SCRCMD_TRIALHOUSE_SetBattleMode
 * address:  0x0216A440
 * packet:   pkt_0216A440
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocked:  
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetListCursor  0x02012F50  thumb
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   TRIAL_HOUSE_SetBattleMode  0x021D0A74  thumb
 */
#include "../include/Obj17756.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Ctx;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetListCursor(void *base);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern int TRIAL_HOUSE_SetBattleMode();

int SCRCMD_TRIALHOUSE_SetBattleMode(int a0, int a1)
{    int t5;
    int t6;
    void *p;
    void *v0;
    void *v1;
    void *v2;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    v0 = SCRCMD_WORK_GetScriptWork((void *)a0);
loc_0216A44C:
a0 = t6 + 0;
    v1 = SCRCMD_WORK_GetGameSystem((void *)a0);
loc_0216A452:
    p = GAMESYSTEM_GetGameData((const struct Ctx *)v1);
loc_0216A456:
    v2 = GAME_DATA_GetListCursor(p);
loc_0216A45A:
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = (int)SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
loc_0216A464:
a1 = a0 + 0;
a0 = ((struct Obj17756 *)((char *)v2))->f0;
    a0 = TRIAL_HOUSE_SetBattleMode(a0, a1);
loc_0216A46C:
a0 = 0;
    return a0;}
