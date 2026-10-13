/*
 * function: FIELD_PLACE_NAME_UsesIntrudeTemplate
 * address:  0x021BCB48
 * packet:   pkt_ov021_021BCB48
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb
 *   GAME_DATA_GetMoveModelSys  0x02012B38  thumb
 *   GAME_DATA_GetExitMode  0x02012B58  thumb
 *   GAME_DATA_GetIntrudeIdByte  0x0215841C  thumb
 *   FIELD_STATUS_GetMapMode  0x0201444C  thumb
 *   ZONEDATA_IsZone117  0x02013D5C  thumb
 */

struct Ctx;
extern unsigned int GAMESYSTEM_GetGameComm(const struct Ctx *p);
extern int INTRUDE_COMM_GetWorkIfRunning(int a);
typedef unsigned char  u8;
struct BigObj;
extern void *GAME_DATA_GetMoveModelSys(const struct BigObj *p);
extern u8 GAME_DATA_GetExitMode(const struct BigObj *p);
extern int GAME_DATA_GetIntrudeIdByte(int a);
struct Sub02014444Obj;
extern unsigned int FIELD_STATUS_GetMapMode(struct Sub02014444Obj *o);
typedef unsigned int   u32;
extern u32 ZONEDATA_IsZone117(u32 id);

int FIELD_PLACE_NAME_UsesIntrudeTemplate(int *p, int b)
{
    int r4, r6, t;

    r4 = INTRUDE_COMM_GetWorkIfRunning((int)GAMESYSTEM_GetGameComm((const struct Ctx *)p[0]));
    t = (int)GAME_DATA_GetMoveModelSys((const struct BigObj *)p[1]);
    r6 = GAME_DATA_GetExitMode((const struct BigObj *)p[1]);
    if (r4 != 0) {
        r4 = GAME_DATA_GetIntrudeIdByte(p[1]);
        if (FIELD_STATUS_GetMapMode((struct Sub02014444Obj *)t) == 1) {
            return 1;
        }
        if (ZONEDATA_IsZone117(b) != 0 && r6 != r4) {
            return 1;
        }
    }
    return 0;
}
