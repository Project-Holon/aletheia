/*
 * function: EVENT_MAPCHANGE_ApplyLocation
 * address:  0x021857C0
 * packet:   pkt_ov020_021857C0
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetMyPlayerWork  0x020127A4  thumb
 *   GAME_DATA_GetEventData  0x02012844  thumb
 *   GAME_DATA_GetMoveModelSys  0x02012B38  thumb
 *   func_02014454  0x02014454  thumb
 *   GAME_DATA_GetEntranceLocation  0x02012870  thumb
 *   GAME_DATA_SetSpecialLocation  0x0201289C  thumb
 *   GAME_DATA_SetPlayerZoneId  0x02012AC4  thumb
 *   GAME_DATA_SetPlayerDirection  0x02012ACC  thumb
 *   ZONEDATA_GetLocationPosType  0x020141DC  thumb
 *   GAME_DATA_SetPlayerPosition  0x02012A90  thumb
 *   GAME_DATA_SetPlayerRailLocation  0x02012AA4  thumb
 *   GAME_DATA_SetPlayerMoveForm  0x02012ABC  thumb
 *   GAMESYSTEM_GetIssSystem  0x02012134  thumb
 *   ISS_SYS_ChangeZone  0x0202B544  thumb
 *   GAME_DATA_SetStartLocation  0x02012854  thumb
 *   GAME_DATA_SetWarpId  0x02012900  thumb
 *   func_0202C83C  0x0202C83C  thumb
 *   func_0201405C  0x0201405C  thumb
 *   GAME_DATA_GetOccupyInfo  0x02012964  thumb
 *   EVENT_MAPCHANGE_ResolveLocation  0x02185788  thumb  ov020
 *   EVENT_MAPCHANGE_DirToAngle  0x02185758  thumb  ov020
 *   EVENT_MAPCHANGE_ApplyZoneTableEntry  0x02185B9C  thumb  ov020
 *   EVENT_MAPCHANGE_AddEventDataMmdl  0x021858E4  thumb  ov020
 *   EVENT_MAPCHANGE_SetMapEffectMask  0x02185A34  thumb  ov020
 *   EVENT_MAPCHANGE_ReloadMmdl  0x021859FC  thumb  ov020
 *   func_02159FE0  0x02159FE0  thumb  ov010
 *   FIELD_CLOCK_Update  0x02168EEC  thumb  ov010
 *   func_021643E8  0x021643E8  thumb  ov010
 *   func_0215A014  0x0215A014  thumb  ov010
 *   SCRIPT_SYS_RunZoneChangeScript  0x02158AE0  thumb  ov010
 *   FLDMMDL_SysLoadObjCodeParamCache  0x0216E29C  thumb  ov010
 *   FLDMMDL_ClearObjCodeParamCache  0x0216CCCC  thumb  ov010
 */

typedef unsigned short u16;
typedef short          s16;

typedef struct Obj {
    int f0;
    s16 h4, h6, h8, ha;
    int fc, f10, f14, f18;
} Obj;

struct BigObj;
struct Ctx;
struct H4;
struct Rec020141DC;
struct Rec1C;
struct Rec44;
struct SaveBlock;
struct Vec12;
void *GAMESYSTEM_GetGameData(const struct Ctx *p);
void *GAME_DATA_GetMyPlayerWork(struct SaveBlock *p);
unsigned int GAME_DATA_GetEventData(const struct BigObj *p);
void *GAME_DATA_GetMoveModelSys(const struct BigObj *p);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct BigObj;
struct Rec44;
struct Sub02014444Obj;
void func_02014454(struct Sub02014444Obj *o, u8 v);
struct Rec1C *GAME_DATA_GetEntranceLocation(const struct BigObj *p);
void GAME_DATA_SetSpecialLocation(struct BigObj *p, const struct Rec1C *src);
struct Rec44 *GAME_DATA_SetPlayerZoneId(struct Rec44 *p, u16 v);
void GAME_DATA_SetPlayerDirection(struct Rec44 *p, int v);
int ZONEDATA_GetLocationPosType(const struct Rec020141DC *p);
void GAME_DATA_SetPlayerPosition(struct Rec44 *p, const struct Vec12 *src);
void GAME_DATA_SetPlayerRailLocation(struct Rec44 *p, const struct H4 *src);
void GAME_DATA_SetPlayerMoveForm(struct Rec44 *p, u8 v);
u32 GAMESYSTEM_GetIssSystem(u32 *p);
void ISS_SYS_ChangeZone(u32 a, u16 b);
void GAME_DATA_SetStartLocation(struct BigObj *p, const struct Rec1C *src);
void GAME_DATA_SetWarpId(const struct BigObj *p, u16 v);
int func_0202C83C(int a0, int a1);
u8 func_0201405C(u32 id);
u32 GAME_DATA_GetOccupyInfo(const struct BigObj *p);
void EVENT_MAPCHANGE_ResolveLocation(int a, int b, Obj *o);
int EVENT_MAPCHANGE_DirToAngle(int v);
void EVENT_MAPCHANGE_ApplyZoneTableEntry(int a0, int id);
void EVENT_MAPCHANGE_AddEventDataMmdl(int a, const short *p);
void EVENT_MAPCHANGE_SetMapEffectMask(void *p, unsigned int id);
void EVENT_MAPCHANGE_ReloadMmdl(void *p, const short *s);
int func_02159FE0(int v);
void FIELD_CLOCK_Update(int a);
void func_021643E8(void *p, u16 v);
void func_0215A014(void *p, int v);
void SCRIPT_SYS_RunZoneChangeScript(void *a0, void *a1);
void FLDMMDL_SysLoadObjCodeParamCache(struct Obj *o, int v);
void FLDMMDL_ClearObjCodeParamCache(struct Obj *o);

void EVENT_MAPCHANGE_ApplyLocation(void *a, int b)
{
    void *r5;
    void *r4;
    int t;
    Obj s;
    u16 v;
    int n;
    void *q;

    r5 = GAMESYSTEM_GetGameData(a);
    r4 = GAME_DATA_GetMyPlayerWork(r5);
    t = (int)GAME_DATA_GetEventData(r5);
    func_02014454(GAME_DATA_GetMoveModelSys(r5), 1);
    EVENT_MAPCHANGE_ResolveLocation(t, b, &s);
    if (s.f0 == 3)
        GAME_DATA_SetSpecialLocation(r5, GAME_DATA_GetEntranceLocation(r5));
    GAME_DATA_SetPlayerZoneId(r4, s.h4);
    GAME_DATA_SetPlayerDirection(r4, EVENT_MAPCHANGE_DirToAngle(s.h8));
    if (ZONEDATA_GetLocationPosType((const struct Rec020141DC *)(&s)) == 0) {
        GAME_DATA_SetPlayerPosition(r4, (const struct Vec12 *)(&s.f10));
        GAME_DATA_SetPlayerMoveForm(r4, 0);
    } else {
        GAME_DATA_SetPlayerRailLocation(r4, (const struct H4 *)(&s.f10));
        GAME_DATA_SetPlayerMoveForm(r4, 1);
    }
    ISS_SYS_ChangeZone((u32)GAMESYSTEM_GetIssSystem(a), s.h4);
    GAME_DATA_SetStartLocation(r5, (const struct Rec1C *)(&s));
    v = func_02159FE0(s.h4);
    if (v != 0)
        GAME_DATA_SetWarpId(r5, v);
    EVENT_MAPCHANGE_ApplyZoneTableEntry((int)r5, s.h4);
    FIELD_CLOCK_Update((int)r5);
    func_021643E8(r5, s.h4);
    func_0215A014(r5, s.h4);
    SCRIPT_SYS_RunZoneChangeScript(a, (void *)4);
    EVENT_MAPCHANGE_AddEventDataMmdl((int)r5, (const short int *)b);
    EVENT_MAPCHANGE_SetMapEffectMask(r5, (u16)s.h4);
    EVENT_MAPCHANGE_ReloadMmdl(r5, (const short int *)(&s));
    func_0202C83C((int)a, s.h4);
    n = (int)func_0201405C((u16)s.h4);
    q = (void *)GAME_DATA_GetOccupyInfo(r5);
    if (n < 16)
        FLDMMDL_SysLoadObjCodeParamCache(q, n);
    else
        FLDMMDL_ClearObjCodeParamCache(q);
}
