/*
 * function: SCRCMD_TRIALHOUSE_CreateWork
 * address:  0x0216A3F8
 * packet:   pkt_0216A3F8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * blocked:  listing 40 compiled 38
 *
 * symbols:
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetListCursor  0x02012F50  thumb
 *   TRIAL_HOUSE_CreateWork  0x021D096C  thumb
 */
#include "../include/Obj12054.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Ctx;

extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetListCursor(void *base);
extern void *TRIAL_HOUSE_CreateWork(void *a);

int SCRCMD_TRIALHOUSE_CreateWork(int a0, int a1)
{    void *p;
    void *v0;
    void *v1;

a0 = a1 + 0;
    v0 = SCRCMD_WORK_GetGameSystem((void *)a0);
loc_0216A400:
    p = GAMESYSTEM_GetGameData((const struct Ctx *)v0);
loc_0216A406:
    v1 = GAME_DATA_GetListCursor(p);
loc_0216A40A:
a0 = *(int *)&((struct Obj12054 *)((char *)v1))->f0;
    if (a0 != 0) goto loc_0216A41A;
loc_0216A412:
    p = TRIAL_HOUSE_CreateWork(v0);
loc_0216A418:
((struct Obj12054 *)((char *)v1))->f0 = p;
loc_0216A41A:
a0 = 0;
    return a0;}
