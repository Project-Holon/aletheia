/*
 * function: EVENT_MAPCHANGE_CreateSituationWarpEvent
 * address:  0x02184F40
 * packet:   pkt_ov020_02184F40
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetSituationWarpId  0x02012914  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   ZONEDATA_SetZoneStartLocation  0x02014204  thumb
 *   MAP_REPLACE_GetWarpFlagId  0x02159F94  thumb  ov010
 *   EVENT_MAPCHANGE_ResetPlayerFormEvent  0x0218495C  thumb  ov020
 *   EVENT_MAPCHANGE_InitWork  0x02184CEC  thumb  ov020
 */
#include "../include/Obj00248.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ctx;
struct Desc;
struct Obj;
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
void *GAMESYSTEM_GetGameData(const struct Ctx *p);
struct BigObj;
u16 GAME_DATA_GetSituationWarpId(const struct BigObj *p);
u16 MAP_REPLACE_GetWarpFlagId(int a);
struct t;
void ZONEDATA_SetZoneStartLocation(struct t *p, int id);
int EVENT_MAPCHANGE_ResetPlayerFormEvent(int ctx, int *state, u8 *p);
void EVENT_MAPCHANGE_InitWork(void **o, void *p);

void *EVENT_MAPCHANGE_CreateSituationWarpEvent(void *p)
{
    void *r6 = (void *)GAME_DATA_GetSituationWarpId(GAMESYSTEM_GetGameData(p));
    void *r0v = func_020122C0(p, 0, EVENT_MAPCHANGE_ResetPlayerFormEvent, 0x9c);
    char *r4 = func_020124E8(r0v);

    EVENT_MAPCHANGE_InitWork((void **)r4, p);
    ZONEDATA_SetZoneStartLocation((struct t *)(r4 + 0x10), MAP_REPLACE_GetWarpFlagId((int)r6));
    ((struct Obj00248 *)r4)->f10 = 1;
    ((struct Obj00248 *)r4)->f2C = 0;
    return r0v;
}
