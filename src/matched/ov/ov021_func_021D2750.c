/*
 * function: FIELD_CheckPlayerPositionFree
 * address:  0x021D2750
 * packet:   pkt_ov021_021D2750
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Spill slots follow declaration order (h, f, list, y, x, id, q, hdl, n from
 * the top down); the tail loops' counter and table pointer are block locals
 * declared j before t, which puts j in r4 and t in r5.
 *
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment (`q
 * = (Sub *)e;` before `q = &e->sub;`). Game code has no line table, so these
 * were stand-ins. The plain single assignment gives EXACT in --lang c99 and
 * --lang c: the output bytes do not change. Older text in this header that
 * asks for the double assignment is superseded.
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetEventData  0x02012844  thumb
 *   EVENTDATA_SYSTEM_GetNpcHeaders  0x02162740  thumb  ov010
 *   EVENTDATA_SYSTEM_GetNpcCount  0x02162744  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   ZONEDATA_IsPalaceEnabled  0x02013C60  thumb
 *   FIELD_PLAYER_GetFormCode  0x021A3098  thumb  ov021
 *   FLDMMDL_LoadObjCodeParam  0x0216E2E8  thumb  ov010
 *   FIELD_PLAYER_GetNowGridPos  0x021A35FC  thumb  ov021
 *   FIELDMAP_GetMoveKind  0x02188CFC  thumb  ov021
 *   FIELD_PLAYER_GetNogridNextRailLocation  0x021A36BC  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   EVENTDATA_SYSTEM_SearchAutoPosEvent  0x02162890  thumb  ov010
 *   FIELD_WFBC_DATA_LOCAL_OpenNpcData  0x021867C4  thumb  ov020
 *   FIELD_WFBC_DATA_LOCAL_LoadMmdlPositionTable  0x02186830  thumb  ov020
 *   FIELD_WFBC_DATA_LOCAL_GetPositionPair  0x02186844  thumb  ov020
 *   FIELD_WFBC_DATA_LOCAL_GetItemPositionPair  0x0218684C  thumb  ov020
 *   FIELD_WFBC_DATA_LOCAL_FreeMmdlPositionTable  0x0218683C  thumb  ov020
 *   FIELD_WFBC_DATA_LOCAL_CloseNpcData  0x02186804  thumb  ov020
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef short          s16;
typedef unsigned int   u32;

typedef struct { int x, y, z; } V3;

typedef struct {
    u16 a;
    u16 b;
    s16 c;
} Sub;

typedef struct {
    u16 f0;
    u16 f2;
    u8 pad4[0x14];
    u32 kind;
    Sub sub;
    u16 pad22;
} Rec;

typedef struct {
    u8 pad[0xB];
    u8 w;
    u8 h;
    u8 pad2[0xF];
} Info;

typedef struct {
    u16 a;
    u16 f2;
    s16 c;
    u16 b;
    u16 f8;
} Loc;

typedef struct {
    s16 x;
    s16 y;
    s16 z;
} Pos;

struct ArcFile;
struct BigObj;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u32 GAME_DATA_GetEventData(const struct BigObj *p);
struct Rec;
extern u32 EVENTDATA_SYSTEM_GetNpcHeaders(u8 *p);
extern u16 EVENTDATA_SYSTEM_GetNpcCount(u8 *p);
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void *FIELDMAP_GetMmdlSys(unsigned char *p);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern u16 FIELDMAP_GetZoneId(u8 *p);
extern u32 ZONEDATA_IsPalaceEnabled(u32 id);
extern u32 FIELD_PLAYER_GetFormCode(u8 *p);
struct Record;
extern void FLDMMDL_LoadObjCodeParam(const char *ctx, u32 id, struct Record *out);
extern void FIELD_PLAYER_GetNowGridPos(unsigned char **p, u16 *a, u16 *b, u16 *c);
extern u32 FIELDMAP_GetMoveKind(u8 *p);
struct Obj18028;
extern void FIELD_PLAYER_GetNogridNextRailLocation(struct Obj18028 *p, void *a1);
extern void *FIELD_PLAYER_GetMmdl(unsigned char *p);
extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);
struct Actor;
struct VecFx32;
extern void FLDMMDL_GetPos(const struct Actor *, struct VecFx32 *);
extern struct Rec *EVENTDATA_SYSTEM_SearchAutoPosEvent(struct Ctx *c, void *a, int key);
extern int *FIELD_WFBC_DATA_LOCAL_OpenNpcData(int a, int id);
extern void *FIELD_WFBC_DATA_LOCAL_LoadMmdlPositionTable(struct ArcFile **p, int b, unsigned int heap);
extern u8 *FIELD_WFBC_DATA_LOCAL_GetPositionPair(u8 *t, int i);
extern u8 *FIELD_WFBC_DATA_LOCAL_GetItemPositionPair(u8 *t, int i);
extern void FIELD_WFBC_DATA_LOCAL_FreeMmdlPositionTable(void *p);
extern void FIELD_WFBC_DATA_LOCAL_CloseNpcData(void **p);

int FIELD_CheckPlayerPositionFree(u32 a)
{
    Info info;
    V3 v;
    Loc loc;
    Pos pos;
    u32 h, f;
    Rec *list;
    void *y;
    void *x;
    void *o;
    u32 id;
    Rec *e;
    Sub *q;
    int hdl;
    int i;
    int n;
    u8 *p;
    u32 r5;
    void *r4;

    h = (u32)GAMESYSTEM_GetGameData((const struct Ctx *)a);
    f = GAME_DATA_GetEventData((const struct BigObj *)h);
    list = (Rec *)EVENTDATA_SYSTEM_GetNpcHeaders((u8 *)f);
    n = EVENTDATA_SYSTEM_GetNpcCount((u8 *)f);
    y = GAMESYSTEM_GetFieldMap((void *)a);
    x = FIELDMAP_GetMmdlSys((void *)y);
    o = FIELDMAP_GetFieldPlayer((void *)y);
    id = FIELDMAP_GetZoneId(y);
    if ((int)ZONEDATA_IsPalaceEnabled((u16)id) == 0) {
        return 0;
    }
    if ((u32)(FIELD_PLAYER_GetFormCode(o) - 2) <= 1) {
        return 0;
    }
    if ((list == 0 || n == 0) && id != 0 && id != 0x1A8) {
        return 1;
    }
    for (i = 0; i < n; i++) {
        e = &list[i];
        if (e->kind == 0) {
            q = &e->sub;
            FLDMMDL_LoadObjCodeParam(x, e->f2, (struct Record *)&info);
            FIELD_PLAYER_GetNowGridPos(o, (u16 *)(&pos.z), (u16 *)(&pos.y), (u16 *)(&pos.x));
            if (e->sub.a <= pos.z && pos.z < e->sub.a + info.w) {
                if (q->b - info.h < pos.x && pos.x <= q->b) {
                    return 0;
                }
            }
        } else if (e->kind == 1) {
            q = &e->sub;
            if (FIELDMAP_GetMoveKind(y) == 1) {
                FIELD_PLAYER_GetNogridNextRailLocation(o, &loc);
                if (q->a == loc.a && q->b == loc.b && q->c == loc.c) {
                    return 0;
                }
            }
        }
    }
    if (FIELDMAP_GetMoveKind(y) == 0) {
        r4 = FIELD_PLAYER_GetMmdl((void *)o);
        r5 = GAME_DATA_GetEventWork((const struct BigObj *)h);
        FLDMMDL_GetPos(r4, (struct VecFx32 *)&v);
        if (EVENTDATA_SYSTEM_SearchAutoPosEvent((struct Ctx *)f, (void *)r5, (int)(&v))) {
            return 0;
        }
    }
    if (id == 0 || id == 0x1A8) {
        int j;
        u8 *t;
        FIELD_PLAYER_GetNowGridPos(o, (u16 *)(&pos.z), (u16 *)(&pos.y), (u16 *)(&pos.x));
        hdl = (int)FIELD_WFBC_DATA_LOCAL_OpenNpcData(0, 0x8015);
        t = FIELD_WFBC_DATA_LOCAL_LoadMmdlPositionTable((struct ArcFile **)hdl, id != 0, 0x8015);
        for (j = 0; j < 10; j++) {
            p = FIELD_WFBC_DATA_LOCAL_GetPositionPair(t, j);
            if (p[0] == pos.z && p[1] == pos.x) {
                FIELD_WFBC_DATA_LOCAL_FreeMmdlPositionTable(t);
                FIELD_WFBC_DATA_LOCAL_CloseNpcData((void **)hdl);
                return 0;
            }
        }
        for (j = 0; j < 10; j++) {
            p = FIELD_WFBC_DATA_LOCAL_GetItemPositionPair(t, j);
            if (p[0] == pos.z && p[1] == pos.x) {
                FIELD_WFBC_DATA_LOCAL_FreeMmdlPositionTable(t);
                FIELD_WFBC_DATA_LOCAL_CloseNpcData((void **)hdl);
                return 0;
            }
        }
        FIELD_WFBC_DATA_LOCAL_FreeMmdlPositionTable(t);
        FIELD_WFBC_DATA_LOCAL_CloseNpcData((void **)hdl);
    }
    return 1;
}
