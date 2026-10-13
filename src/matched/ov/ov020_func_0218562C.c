/*
 * function: EVENT_MAPCHANGE_InitFieldFromSituationWarp
 * address:  0x0218562C
 * packet:   pkt_ov020_0218562C
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetSituationWarpId  0x02012914  thumb
 *   func_02159FA8  0x02159FA8  thumb  ov010
 *   func_02159F94  0x02159F94  thumb  ov010
 *   ZONEDATA_SetZoneStartLocation  0x02014204  thumb
 *   GAME_DATA_SetEscapeLocation  0x020128C0  thumb
 *   EVENT_MAPCHANGE_DeleteAllMmdlOfSystem  0x02185B70  thumb  ov020
 *   EVENT_MAPCHANGE_UpdateFieldStateForZone  0x02185A68  thumb  ov020
 *   EVENT_MAPCHANGE_ApplyLocation  0x021857C0  thumb  ov020
 *   GAME_BEACON_SetZone  0x0202735C  thumb
 *   FIELD_CLOCK_Update  0x02168EEC  thumb  ov010
 *   func_0216446C  0x0216446C  thumb  ov010
 */

typedef unsigned short u16;

struct BigObj;
struct Ctx;
struct Rec1C;
void *GAMESYSTEM_GetGameData(const struct Ctx *p);
u16 GAME_DATA_GetSituationWarpId(const struct BigObj *p);
void func_02159FA8(int a, int b);
typedef unsigned int   u32;
u16 func_02159F94(int a);
struct t;
void ZONEDATA_SetZoneStartLocation(struct t *p, int id);
void GAME_DATA_SetEscapeLocation(struct BigObj *p, const struct Rec1C *src);
void EVENT_MAPCHANGE_DeleteAllMmdlOfSystem(void *p);
void EVENT_MAPCHANGE_UpdateFieldStateForZone(void *a, int b);
void EVENT_MAPCHANGE_ApplyLocation(int a, void *b);
void GAME_BEACON_SetZone(u32 a0, u32 a1);
void FIELD_CLOCK_Update(int a);
int func_0216446C(int a, int b);

void EVENT_MAPCHANGE_InitFieldFromSituationWarp(int a)
{
    int r4 = (int)GAMESYSTEM_GetGameData((const struct Ctx *)a);
    struct { char b[0x1c]; int f; u16 h; char pad[0x16]; } l;

    func_02159FA8(GAME_DATA_GetSituationWarpId((const struct BigObj *)r4), (int)(&l.f));
    ZONEDATA_SetZoneStartLocation((struct t *)l.b, func_02159F94(GAME_DATA_GetSituationWarpId((const struct BigObj *)r4)));
    GAME_DATA_SetEscapeLocation((struct BigObj *)r4, (const struct Rec1C *)l.b);
    EVENT_MAPCHANGE_DeleteAllMmdlOfSystem((void *)a);
    EVENT_MAPCHANGE_UpdateFieldStateForZone((void *)a, l.h);
    EVENT_MAPCHANGE_ApplyLocation(a, &l.f);
    GAME_BEACON_SetZone(l.h, r4);
    FIELD_CLOCK_Update(r4);
    func_0216446C(r4, l.h);
}
