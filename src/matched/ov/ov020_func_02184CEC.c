/*
 * function: EVENT_MAPCHANGE_InitWork
 * address:  0x02184CEC
 * packet:   pkt_ov020_02184CEC
 * region:   ov020
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   GAME_DATA_GetSeason  0x02012984  thumb
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   FIELDMAP_GetEncount  0x02188CE8  thumb  ov021
 *   EFFECT_ENCOUNT_SetEffectPaused  0x021AAAF0  thumb  ov021
 */
#include "../include/Obj00248.h"

typedef unsigned short u16;

typedef unsigned int   u32;
typedef unsigned char  u8;
struct BigObj;
struct Ctx;
void *GAMESYSTEM_GetGameData(const struct Ctx *p);
void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
u8 GAME_DATA_GetSeason(const struct BigObj *p);
u16 FIELDMAP_GetZoneId(u8 *p);
u32 FIELDMAP_GetEncount(u8 *p);
void EFFECT_ENCOUNT_SetEffectPaused(int x, int y);

void EVENT_MAPCHANGE_InitWork(void **o, void *p)
{
    void *a = GAMESYSTEM_GetGameData(p);
    void *b = GAMESYSTEM_GetFieldMap(p);
    u16 c = GAME_DATA_GetSeason(a);

    o[0] = p;
    o[1] = a;
    o[2] = b;
    ((struct Obj00248 *)o)->fC = FIELDMAP_GetZoneId(b);
    ((struct Obj00248 *)o)->f40 = 0;
    ((struct Obj00248 *)o)->f44 = 0;
    ((struct Obj00248 *)o)->f48 = c;
    ((struct Obj00248 *)o)->f4A = c;
    EFFECT_ENCOUNT_SetEffectPaused(FIELDMAP_GetEncount(o[2]), 1);
}
