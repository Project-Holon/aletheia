/*
 * function: EVENT_MAPCHANGE_CreateIntrudeReturnEvent
 * address:  0x02185214
 * packet:   pkt_ov020_02185214
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * Lever: GAME_COMM_GetCounter reads its pointer argument in the matched ARM9
 * unit_02026454.c. The original forwards GAMESYSTEM_GetGameComm(a) in r0 with
 * no intervening argument setup. Explicitly passing h restores the
 * return-value spill and all frame/register choices (DIFF22 -> EXACT).
 * Runs this retry: 2; the prior consumed permuter was not repeated.
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   GAME_DATA_GetWarpLocation  0x020128DC  thumb
 *   ZONEDATA_IsZoneInTableDFC0  0x02013DD0  thumb
 *   ZONEDATA_SetZoneStartLocation  0x02014204  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   INTRUDE_GetFromSave  0x0200BE48  thumb
 *   GAME_DATA_GetPlayTime  0x02012FCC  thumb
 *   INTRUDE_UpdatePlaySeconds  0x0200BFA4  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAME_COMM_GetCounter  0x0202648C  thumb
 *   GAME_COMM_GetKind  0x02026454  thumb
 *   GAME_COMM_ClearCounter  0x02026484  thumb
 *   GAME_DATA_SetIntrudeCount  0x02012B78  thumb
 *   GAME_DATA_SetOwnNetId  0x02012B64  thumb
 *   GAME_DATA_SetIntrudeId  0x02012B8C  thumb
 *   GAME_DATA_SetEnterMode  0x02012B4C  thumb
 *   EVENT_MAPCHANGE_CreateIntrudeArriveEvent  0x02185C4C  thumb  ov020
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_CheckFormModel  0x021A3238  thumb  ov021
 *   INTRUDE_FIELD_ChangePlayerLook  0x0217BCDC  thumb  ov018
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb  ov010
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef struct { int f00; u16 f04, f06; int f08[5]; } Rec;
struct Big;
struct BigObj;
struct Ctx;
void *GAMESYSTEM_GetGameData(const struct Ctx *p);
void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
Rec *GAME_DATA_GetWarpLocation(void *p);
int ZONEDATA_IsZoneInTableDFC0(int v);
struct t;
void ZONEDATA_SetZoneStartLocation(struct t *p, int id);
void *GAME_DATA_GetSaveControl(struct Big *p);
u16 *INTRUDE_GetFromSave(void *p);
int GAME_DATA_GetPlayTime(int p0);
u64 INTRUDE_UpdatePlaySeconds(u8 *p, void *x, u32 n);
u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
u32 GAME_COMM_GetCounter(void *p);
u32 GAME_COMM_GetKind(void *obj);
void GAME_COMM_ClearCounter(void *p);
struct BigObj *GAME_DATA_SetIntrudeCount(struct BigObj *p, u8 v);
void GAME_DATA_SetOwnNetId(struct BigObj *p, u8 v);
void GAME_DATA_SetIntrudeId(struct BigObj *p, u32 v);
void GAME_DATA_SetEnterMode(struct BigObj *p, u8 v);
void *EVENT_MAPCHANGE_CreateIntrudeArriveEvent(void *p, void *a1, Rec *r);
struct Obj00020;
void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
int FIELD_PLAYER_CheckFormModel(u8 *p);
void INTRUDE_FIELD_ChangePlayerLook(u8 *a, void *b, int c, u8 d, u8 e);
int INTRUDE_COMM_GetWorkIfRunning(int a0);
static inline void create_result(void *a, void *r6, Rec *s, void **out)
{
    *out = EVENT_MAPCHANGE_CreateIntrudeArriveEvent(a, r6, s);
}
static inline void *finish(void *a, void *r4, void *r6, void *ret)
{
    u16 *t;
    void *h;
    t = INTRUDE_GetFromSave(GAME_DATA_GetSaveControl(r4));
    INTRUDE_UpdatePlaySeconds((u8 *)t, (void *)GAME_DATA_GetPlayTime((int)r4), 1);
    h = (void *)GAMESYSTEM_GetGameComm(a);
    GAME_COMM_GetCounter(h);
    if (GAME_COMM_GetKind(h) == 0)
        GAME_COMM_ClearCounter(h);
    if (FIELD_PLAYER_CheckFormModel(FIELDMAP_GetFieldPlayer(r6)) == 0)
        INTRUDE_FIELD_ChangePlayerLook(0, a, 0, 0, 0);
    GAME_DATA_SetIntrudeCount(r4, 0);
    if (INTRUDE_COMM_GetWorkIfRunning(GAMESYSTEM_GetGameComm(a)) == 0) {
        GAME_DATA_SetOwnNetId(r4, 0);
        GAME_DATA_SetIntrudeId(r4, 0);
        GAME_DATA_SetEnterMode(r4, 1);
    }
    return ret;
}
void *EVENT_MAPCHANGE_CreateIntrudeReturnEvent(void *a)
{
    void *r4;
    void *r6;
    Rec s;
    void *ret;
    r4 = GAMESYSTEM_GetGameData(a);
    r6 = GAMESYSTEM_GetFieldMap(a);
    s = *GAME_DATA_GetWarpLocation(r4);
    if (ZONEDATA_IsZoneInTableDFC0(s.f04) == 1)
        ZONEDATA_SetZoneStartLocation((struct t *)(&s), s.f04);
    create_result(a, r6, &s, &ret);
    return finish(a, r4, r6, ret);
}
