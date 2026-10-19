/*
 * function: INTRUDE_SUBDISP_CreateReturnPalaceEvent
 * address:  0x0217CA40
 * packet:   pkt_ov018_0217CA40
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetOwnNetId  0x02012B58  thumb
 *   GAME_DATA_SetIntrudeId  0x02012B8C  thumb
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb  ov010
 *   INTRUDE_COMM_SetIntrudeId  0x02175710  thumb  ov011
 *   INTRUDE_SUBDISP_CreatePalaceWarpEvent  0x0217CA1C  thumb  ov018
 */

struct Ctx;

extern unsigned int GAMESYSTEM_GetGameComm(const struct Ctx *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
typedef unsigned char  u8;
struct BigObj;
extern u8 GAME_DATA_GetOwnNetId(const struct BigObj *p);
extern void GAME_DATA_SetIntrudeId(struct BigObj *p, unsigned int v);
extern int INTRUDE_COMM_GetWorkIfRunning(int a0);
typedef unsigned int   u32;
extern void INTRUDE_COMM_SetIntrudeId(u8 *o, u32 v);
extern void *INTRUDE_SUBDISP_CreatePalaceWarpEvent(void *p);

void *INTRUDE_SUBDISP_CreateReturnPalaceEvent(int a0)
{
    int h;
    void *c;
    int p;

    h = GAMESYSTEM_GetGameComm((const struct Ctx *)a0);
    c = GAMESYSTEM_GetGameData((const struct Ctx *)a0);
    p = INTRUDE_COMM_GetWorkIfRunning(h);
    if (p != 0) {
        INTRUDE_COMM_SetIntrudeId((u8 *)p, GAME_DATA_GetOwnNetId(c));
    } else {
        GAME_DATA_SetIntrudeId(c, GAME_DATA_GetOwnNetId(c));
    }
    return INTRUDE_SUBDISP_CreatePalaceWarpEvent((void *)a0);
}
