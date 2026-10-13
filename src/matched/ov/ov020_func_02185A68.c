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
 *   func_02013D5C  0x02013D5C  thumb
 *   GAME_DATA_GetMoveModelSys  0x02012B38  thumb
 *   func_02014450  0x02014450  thumb
 *   func_02013CC8  0x02013CC8  thumb
 *   func_02013CE0  0x02013CE0  thumb
 *   func_02013DF0  0x02013DF0  thumb
 *   func_02013D20  0x02013D20  thumb
 *   GAME_DATA_GetSubscreenType  0x020129AC  thumb
 *   GAME_DATA_SetSubscreenType  0x020129B8  thumb
 *   GAME_DATA_GetSeason  0x02012984  thumb
 *   GAME_DATA_GetFieldWork  0x02012974  thumb
 *   func_02013B44  0x02013B44  thumb
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
u32 func_02013D5C(u32 id);
void *GAME_DATA_GetMoveModelSys(const struct BigObj *p);
void func_02014450(struct Sub02014444Obj *o, u32 v);
u32 func_02013CC8(u32 id);
u32 func_02013CE0(u32 id);
u32 func_02013DF0(u32 id);
u32 func_02013D20(u32 id);
u8 GAME_DATA_GetSubscreenType(const struct BigObj *p);
void GAME_DATA_SetSubscreenType(struct BigObj *p, u32 v);
u8 GAME_DATA_GetSeason(const struct BigObj *p);
u32 GAME_DATA_GetFieldWork(const struct BigObj *p);
u32 func_02013B44(u32 id);
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
    if (GAME_DATA_GetIntrudeCount(r4) == 1 && func_02013D5C(b) == 0)
        func_02014450(GAME_DATA_GetMoveModelSys(r4), 1);
    else
        func_02014450(GAME_DATA_GetMoveModelSys(r4), 0);

    if (func_02013CC8(b) != 0) {
        GAME_DATA_SetSubscreenType(r4, 2);
    } else if (func_02013CE0(b) != 0 || func_02013DF0(b) != 0 || func_02013D20(b) != 0) {
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
    MAP_MATRIX_Load((int)r7, func_02013B44(b), b, 0x8001);
    MAP_MATRIX_ApplyReplace(r7, (int)a, 0x8001);
    EVENT_MAPCHANGE_SetMapEffectMask(r4, b);
}
