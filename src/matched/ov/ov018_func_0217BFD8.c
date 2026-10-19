/*
 * function: INTRUDE_FIELD_IsDisconnectNeeded
 * address:  0x0217BFD8
 * packet:   pkt_ov018_0217BFD8
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb  ov010
 *   GAME_DATA_GetIntrudeCount  0x02012B70  thumb
 *   GAMESYSTEM_IsNetOffBySleep  0x02012204  thumb
 *   ZONEDATA_IsZone117  0x02013D5C  thumb
 *   ZONEDATA_IsZoneGroup118To120  0x02013D9C  thumb
 *   GAME_COMM_GetCounter  0x0202648C  thumb
 *   GAME_COMM_GetKind  0x02026454  thumb
 *   GAME_COMM_GetLastKind  0x0202647C  thumb
 */

typedef unsigned char  u8;
struct BigObj;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
struct Ctx;
extern unsigned int GAMESYSTEM_GetGameComm(const struct Ctx *p);
extern int INTRUDE_COMM_GetWorkIfRunning(int);
extern int GAME_DATA_GetIntrudeCount(const struct BigObj *p);
extern unsigned int GAMESYSTEM_IsNetOffBySleep(const struct Ctx *p);
typedef unsigned int   u32;
extern u32 ZONEDATA_IsZone117(u32 id);
extern u32 ZONEDATA_IsZoneGroup118To120(u32 id);
extern u32 GAME_COMM_GetCounter(void *obj);
extern u32 GAME_COMM_GetKind(void *obj);
extern u32 GAME_COMM_GetLastKind(void *obj);

int INTRUDE_FIELD_IsDisconnectNeeded(const struct Ctx *a, int b)
{
    int h;
    int t;
    int w;

    h = (int)GAMESYSTEM_GetGameData((const struct Ctx *)a);
    t = GAMESYSTEM_GetGameComm((const struct Ctx *)a);
    w = INTRUDE_COMM_GetWorkIfRunning(t);
    if (GAME_DATA_GetIntrudeCount((const struct BigObj *)h) == 0)
        return 0;
    if (w != 0)
        return 0;
    if (GAMESYSTEM_IsNetOffBySleep(a) == 1)
        return 1;
    if (ZONEDATA_IsZone117(b) == 1) {
        if (GAME_COMM_GetCounter((void *)t) != 0)
            return 1;
        return 0;
    }
    if (ZONEDATA_IsZoneGroup118To120(b) == 1) {
        if (GAME_COMM_GetKind((void *)t) == 2 || (GAME_COMM_GetKind((void *)t) == 0 && GAME_COMM_GetLastKind((void *)t) == 2 && GAME_COMM_GetCounter((void *)t) != 0))
            return 1;
        return 0;
    }
    return 1;
}
