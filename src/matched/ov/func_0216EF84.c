/*
 * function: EVENT_BATTLE_SetResultSound
 * address:  0x0216EF84
 * packet:   pkt_0216EF84
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetTrainerRecord  0x02012F2C  thumb
 *   func_02008DF0  0x02008DF0  thumb
 */
#include "../include/Obj00020.h"
#include "../include/Obj12059.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Ctx;

extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
struct Sub02008C20Obj;
extern void *GAME_DATA_GetTrainerRecord(int *p);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);

int EVENT_BATTLE_SetResultSound(int a0)
{
    int a1;
    int t4;
    void *p;

t4 = *(int *)&((struct Obj00020 *)a0)->f8;
a0 = ((struct Obj00020 *)((char *)a0))->f0;
    p = GAMESYSTEM_GetGameData((const struct Ctx *)a0);
loc_0216EF8E:
    a0 = (int)GAME_DATA_GetTrainerRecord(p);
loc_0216EF92:
a1 = ((struct Obj12059 *)((char *)t4))->f0;
    if (a1 != 0) goto loc_0216EFA6;
loc_0216EF98:
t4 = t4 + 0x8c;
a1 = ((struct Obj12059 *)((char *)t4))->f0;
    if (a1 != 4) goto loc_0216EFA6;
loc_0216EFA0:
a1 = 0x4f;
    a0 = func_02008DF0((struct Sub02008C20Obj *)a0, a1);
loc_0216EFA6:
    return a0;}
