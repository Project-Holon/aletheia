/*
 * function: INTRUDE_SUBDISP_CreateTownWarpEvent
 * address:  0x0217CE08
 * packet:   pkt_ov018_0217CE08
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetIntrudeCount  0x02012B70  thumb
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb  ov010
 *   INTRUDE_FIELD_GetZoneAnchor  0x0217BED4  thumb  ov018
 *   EVENT_MAPCHANGE_CreateIntrudeWarpEvent  0x02185140  thumb  ov020
 *   EVENT_MAPCHANGE_CreateWarpEventWithIntrudeOffset  0x02185588  thumb  ov020
 */

typedef struct { int x, y, z; } V12;

struct Ctx;

typedef unsigned int   u32;
typedef unsigned char  u8;
struct BigObj;
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern int GAME_DATA_GetIntrudeCount(const struct BigObj *p);
extern int INTRUDE_COMM_GetWorkIfRunning(int a0);
extern int INTRUDE_FIELD_GetZoneAnchor();
extern void *EVENT_MAPCHANGE_CreateIntrudeWarpEvent();
extern void *EVENT_MAPCHANGE_CreateWarpEventWithIntrudeOffset();

void *INTRUDE_SUBDISP_CreateTownWarpEvent(void *a0, void *a1, int a2, int a3)
{
    int h;
    void *c;
    V12 v;

    h = GAMESYSTEM_GetGameComm(a0);
    c = GAMESYSTEM_GetGameData(a0);
    INTRUDE_COMM_GetWorkIfRunning(h);
    if (INTRUDE_FIELD_GetZoneAnchor(a2, &v) == 0)
        return 0;
    if (GAME_DATA_GetIntrudeCount(c) == 0 && a2 == 0x117)
        return EVENT_MAPCHANGE_CreateIntrudeWarpEvent(a0, a2, &v, a3);
    return EVENT_MAPCHANGE_CreateWarpEventWithIntrudeOffset(a0, a2, &v);
}
