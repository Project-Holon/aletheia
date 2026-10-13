/*
 * function: INTRUDE_SUBDISP_CreatePlayerWarpEvent
 * address:  0x0217CE6C
 * packet:   pkt_ov018_0217CE6C
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb  ov010
 *   INTRUDE_FIELD_FindZonePos  0x0217BEA8  thumb  ov018
 *   EVENT_MAPCHANGE_CreateWarpEvent  0x02184D38  thumb  ov020
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct { int x, y, z; } V12;

struct Ctx;
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
extern int INTRUDE_COMM_GetWorkIfRunning(int a0);
extern u32 *INTRUDE_FIELD_FindZonePos(u16);
extern void *EVENT_MAPCHANGE_CreateWarpEvent(void *p, int unused, int a, const int *q, u16 s, int t);

void *INTRUDE_SUBDISP_CreatePlayerWarpEvent(void *a0, void *a1, int a2)
{
    u8 *p;
    u32 *q;
    V12 v;
    u16 s;

    p = (u8 *)INTRUDE_COMM_GetWorkIfRunning(GAMESYSTEM_GetGameComm(a0));
    if (p == 0 || !(p[0x8FB] & (1 << a2)))
        return 0;
    q = INTRUDE_FIELD_FindZonePos(*(u16 *)(p + a2 * 0x1C + 0xA0));
    if (q == 0)
        return 0;
    s = (*q << 2) >> 22;
    v = *(V12 *)(p + a2 * 0x1C + 0x90);
    v.z += 0x20000;
    return EVENT_MAPCHANGE_CreateWarpEvent(a0, (int)a1, s, (const int *)(&v), 0, 0);
}
