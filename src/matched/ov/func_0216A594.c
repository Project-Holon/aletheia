/*
 * function: SCRCMD_TRIALHOUSE_SetRecordSource
 * address:  0x0216A594
 * packet:   pkt_0216A594
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
 *   TRIAL_HOUSE_SetUseDeliveredTrainers  0x021D0AB8  thumb
 */
#include "../include/Obj17758.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Ctx;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetListCursor(void *base);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *, void *);
extern int TRIAL_HOUSE_SetUseDeliveredTrainers();

int SCRCMD_TRIALHOUSE_SetRecordSource(int a0, int a1)
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
loc_0216A5A0:
a0 = t6 + 0;
    v1 = SCRCMD_WORK_GetGameSystem((void *)a0);
loc_0216A5A6:
    p = GAMESYSTEM_GetGameData((const struct Ctx *)v1);
loc_0216A5AA:
    v2 = GAME_DATA_GetListCursor(p);
loc_0216A5AE:
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
loc_0216A5B8:
a1 = a0 + 0;
a0 = ((struct Obj17758 *)((char *)v2))->f0;
    a0 = TRIAL_HOUSE_SetUseDeliveredTrainers(a0, a1);
loc_0216A5C0:
a0 = 0;
    return a0;}
