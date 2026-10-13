/*
 * function: EVENT_FIELD_PROCLINK_ReturnTrainerCardView
 * address:  0x021611E0
 * packet:   pkt_021611E0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetBgmInfo  0x02012A30  thumb
 *   GAMESYSTEM_GetIssSystem  0x02012134  thumb
 *   FIELD_SOUND_SYSTEM_RestoreVolume  0x02029DD8  thumb
 */
#include "../include/Obj00020.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Ctx;

extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
struct BigObj;
extern u32 GAME_DATA_GetBgmInfo(const struct BigObj *p);
extern int GAMESYSTEM_GetIssSystem();
extern int FIELD_SOUND_SYSTEM_RestoreVolume(int a0, int a1);

int EVENT_FIELD_PROCLINK_ReturnTrainerCardView(int a0, int a1)
{
    int t4;
    int t5;
    int t6;
    void *ctx;

t5 = a0 + 0;
a0 = ((struct Obj00020 *)t5)->f18;
t4 = a1 + 0;
a0 = ((struct Obj00020 *)((char *)a0))->f0;
    ctx = GAMESYSTEM_GetGameData((const struct Ctx *)a0);
loc_021611EE:
    a0 = GAME_DATA_GetBgmInfo(ctx);
loc_021611F2:
t6 = a0 + 0;
a0 = ((struct Obj00020 *)t5)->f18;
a0 = ((struct Obj00020 *)((char *)a0))->f0;
    a0 = GAMESYSTEM_GetIssSystem(a0);
loc_021611FC:
a1 = a0 + 0;
a0 = t6 + 0;
    a0 = FIELD_SOUND_SYSTEM_RestoreVolume(a0, a1);
loc_02161204:
a0 = *(int *)&((struct Obj00020 *)t4)->f10;
    if (a0 != 1) goto loc_0216120E;
loc_0216120A:
a0 = 1;
    return a0;
loc_0216120E:
a0 = 0;
    return a0;}
