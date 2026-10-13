/*
 * function: INTRUDE_FIELD_CreateTileEvent
 * address:  0x0217B410
 * packet:   pkt_ov018_0217B410
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetMyPlayerWork  0x020120F8  thumb
 *   GAME_DATA_GetPlayerZoneId  0x02012AC8  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb  ov010
 *   func_02013D5C  0x02013D5C  thumb
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   INTRUDE_FIELD_CreateExitConfirmEvent  0x0217B5DC  thumb  ov018
 *   FIELD_G3D_MAP_CreateSymbolEntryEvent  0x0216B340  thumb  ov010
 *   INTRUDE_FIELD_gSymbolMarkerPos     0x02182B90  data   a4
 */

typedef unsigned char u8;

typedef struct { int x, y, z; } V12;

struct Ctx;

extern u8 *GAMESYSTEM_GetMyPlayerWork(const struct Ctx *p);
struct Rec44;
extern unsigned short GAME_DATA_GetPlayerZoneId(const struct Rec44 *p);
extern unsigned int GAMESYSTEM_GetGameComm(const struct Ctx *p);
typedef unsigned int   u32;
extern int INTRUDE_COMM_GetWorkIfRunning(int a0);
extern u32 func_02013D5C(u32 id);
struct VecFx32;
extern void FIELD_PLAYER_GetPos(unsigned char *p, struct VecFx32 *out);
extern int INTRUDE_FIELD_CreateExitConfirmEvent();
struct Desc;
extern struct Desc *FIELD_G3D_MAP_CreateSymbolEntryEvent(int a0, int a1, void *a2, int a3, int a4);
extern const V12 INTRUDE_FIELD_gSymbolMarkerPos;

int INTRUDE_FIELD_CreateTileEvent(int a0, int a1, int a2)
{
    int h;
    int w;
    int i;
    int base;
    V12 pos;
    V12 v;

    h = GAME_DATA_GetPlayerZoneId((const struct Rec44 *)GAMESYSTEM_GetMyPlayerWork((const struct Ctx *)a1));
    w = INTRUDE_COMM_GetWorkIfRunning(GAMESYSTEM_GetGameComm((const struct Ctx *)a1));
    if (func_02013D5C(h) == 0)
        return 0;
    FIELD_PLAYER_GetPos((unsigned char *)a2, (struct VecFx32 *)&pos);
    for (i = 0; i < 3; i++) {
        if (pos.x >= (i << 22) + 0x1F8000 && pos.x <= (i << 22) + 0x1F8000 && pos.z >= 0x2C8000 && pos.z <= 0x2C8000)
            return INTRUDE_FIELD_CreateExitConfirmEvent(a1, a0, w);
    }
    base = 0x1F8000;
    for (i = 0; i < 3; i++) {
        if (pos.x >= base && pos.x < base + 0x20000 && pos.z == 0x158000) {
            v = INTRUDE_FIELD_gSymbolMarkerPos;
            v.x += pos.x - base;
            return (int)FIELD_G3D_MAP_CreateSymbolEntryEvent(a1, 1, &v, 0, 4); /* int-typed on purpose: function returns int */
        }
        base += 0x400000;
    }
    return 0;
}
