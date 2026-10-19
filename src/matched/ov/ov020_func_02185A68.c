/*
 * function: EVENT_MAPCHANGE_UpdateFieldStateForZone
 * address:  0x02185A68
 * packet:   pkt_ov020_02185A68
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetEventData  0x02012844  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   GAME_DATA_GetIntrudeCount  0x02012B70  thumb
 *   ZONEDATA_IsEntralink  0x02013D5C  thumb
 *   GAME_DATA_GetMoveModelSys  0x02012B38  thumb
 *   FIELD_STATUS_SetMapMode  0x02014450  thumb
 *   ZONEDATA_IsUnionRoom  0x02013CC8  thumb
 *   ZONEDATA_IsZone96Pair  0x02013CE0  thumb
 *   ZONEDATA_IsZone4E  0x02013DF0  thumb
 *   ZONEDATA_IsZone34  0x02013D20  thumb
 *   GAME_DATA_GetSubscreenType  0x020129AC  thumb
 *   GAME_DATA_SetSubscreenType  0x020129B8  thumb
 *   GAME_DATA_GetSeason  0x02012984  thumb
 *   GAME_DATA_GetFieldWork  0x02012974  thumb
 *   ZONEDATA_GetMatrixId  0x02013B44  thumb
 *   EVENTDATA_SYSTEM_Load  0x02162408  thumb  ov010
 *   MAP_MATRIX_Load  0x02159B94  thumb  ov010
 *   MAP_MATRIX_ApplyReplace  0x02159CC4  thumb  ov010
 *   EVENT_MAPCHANGE_SetMapEffectMask  0x02185A34  thumb  ov020
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
struct BigObj;
struct Ctx;
struct Sub02014444Obj;
void *GAMESYSTEM_GetGameData(const struct Ctx *p);
u32 GAME_DATA_GetEventData(const struct BigObj *p);
void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
int GAME_DATA_GetIntrudeCount(const struct BigObj *p);
u32 ZONEDATA_IsEntralink(u32 id);
void *GAME_DATA_GetMoveModelSys(const struct BigObj *p);
void FIELD_STATUS_SetMapMode(struct Sub02014444Obj *o, u32 v);
u32 ZONEDATA_IsUnionRoom(u32 id);
u32 ZONEDATA_IsZone96Pair(u32 id);
u32 ZONEDATA_IsZone4E(u32 id);
u32 ZONEDATA_IsZone34(u32 id);
u8 GAME_DATA_GetSubscreenType(const struct BigObj *p);
void GAME_DATA_SetSubscreenType(struct BigObj *p, u32 v);
u8 GAME_DATA_GetSeason(const struct BigObj *p);
u32 GAME_DATA_GetFieldWork(const struct BigObj *p);
u32 ZONEDATA_GetMatrixId(u32 id);
int EVENTDATA_SYSTEM_Load(int a0, int a1, int a2);
int MAP_MATRIX_Load(int a0, int a1, int a2, int a3);
void MAP_MATRIX_ApplyReplace(u32 *a, int b, int c);
void EVENT_MAPCHANGE_SetMapEffectMask(void *p, unsigned int id);

void EVENT_MAPCHANGE_UpdateFieldStateForZone(void *a, int b)
{
    void *r4;
    void *r7;
    int st;

    r4 = GAMESYSTEM_GetGameData(a);
    r7 = (void *)GAME_DATA_GetEventData(r4);
    GAMESYSTEM_GetFieldMap(a);
    if (GAME_DATA_GetIntrudeCount(r4) == 1 && ZONEDATA_IsEntralink(b) == 0)
        FIELD_STATUS_SetMapMode(GAME_DATA_GetMoveModelSys(r4), 1);
    else
        FIELD_STATUS_SetMapMode(GAME_DATA_GetMoveModelSys(r4), 0);

    if (ZONEDATA_IsUnionRoom(b) != 0) {
        GAME_DATA_SetSubscreenType(r4, 2);
    } else if (ZONEDATA_IsZone96Pair(b) != 0 || ZONEDATA_IsZone4E(b) != 0 || ZONEDATA_IsZone34(b) != 0) {
        GAME_DATA_SetSubscreenType(r4, 5);
    } else {
        if (GAME_DATA_GetIntrudeCount(r4) == 1 && GAME_DATA_GetSubscreenType(r4) != 3)
            GAME_DATA_SetSubscreenType(r4, 3);
        else if (GAME_DATA_GetIntrudeCount(r4) == 0 && GAME_DATA_GetSubscreenType(r4) == 3)
            GAME_DATA_SetSubscreenType(r4, 0);
        st = GAME_DATA_GetSubscreenType(r4);
        if (st != 3 && st != 4 && st != 6)
            GAME_DATA_SetSubscreenType(r4, 0);
    }

    EVENTDATA_SYSTEM_Load((int)r7, b, GAME_DATA_GetSeason(r4));
    r7 = (void *)GAME_DATA_GetFieldWork(r4);
    MAP_MATRIX_Load((int)r7, ZONEDATA_GetMatrixId(b), b, 0x8001);
    MAP_MATRIX_ApplyReplace(r7, (int)a, 0x8001);
    EVENT_MAPCHANGE_SetMapEffectMask(r4, b);
}
