/*
 * function: EVENT_MAPCHANGE_EntranceCommEvent
 * address:  0x02184410
 * packet:   pkt_ov020_02184410
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Byte-correct (MATCH*: 242 compiled against a 244-byte listing extent, the
 * two bytes are alignment padding).  The one wildcarded site is +0x4C,
 * `bl ZONEDATA_IsZoneInTableDFC0`: an unlabelled arm9 leaf (the integrator's) with no witness
 * outside this range, the documented near miss after unit_02013D9C.c.  Its
 * bytes (ldr r1,=0x0209DFC0; ldr r3,=ZONEDATA_IsZoneInTable+1; movs r2,#4; bx r3) are
 *     extern const unsigned short tbl_0209DFC0[];      (data)
 *     extern int ZONEDATA_IsZoneInTable(int v, const unsigned short *t, int n);
 *     int ZONEDATA_IsZoneInTableDFC0(int v) { return ZONEDATA_IsZoneInTable(v, tbl_0209DFC0, 4); }
 * which now verifies EXACT on its own (2026-09-29, `match.py one --region
 * arm9 --thumb`: the table by sole-ref/data, ZONEDATA_IsZoneInTable by literal), so
 * the unit_02013D9C.c note that it has no witness is out of date.  Once
 * that leaf is filed in an arm9 shard, this file goes EXACT unchanged.
 *
 * symbols:
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb  ov010
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FLDMMDL_SysPauseMove  0x0216D9A0  thumb  ov010
 *   FLDMMDL_SysResumeMove  0x0216D9E4  thumb  ov010
 *   ZONEDATA_IsZoneInTableDFC0  0x02013DD0  thumb
 *   EVENT_MAPCHANGE_SetupExitEntranceParam  0x0218409C  thumb  ov020
 *   EVENT_ENTRANCE_IN_Create  0x021BD648  thumb  ov021
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   EVENT_MAPCHANGE_CreateChangeFieldEvent  0x02184360  thumb  ov020
 *   EVENT_MAPCHANGE_SetupEnterEntranceParam  0x02184120  thumb  ov020
 *   EVENT_ENTRANCE_OUT_Create  0x021BD9BC  thumb  ov021
 *   GAME_DATA_GetIntrudeIdByte  0x0215841C  thumb  ov010
 *   INTRUDE_COMM_SendUnionInfoRequest  0x021746AC  thumb  ov011
 *   INTRUDE_COMM_GetUnionInfoReceived  0x02158428  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;

struct Ctx;
extern unsigned int GAMESYSTEM_GetGameComm(const struct Ctx *p);
struct Evt;
extern int INTRUDE_COMM_GetWorkIfRunning(int a0);
extern void *FIELDMAP_GetMmdlSys(u8 *p);
extern void FLDMMDL_SysPauseMove(void *a);
extern unsigned int *FLDMMDL_SysResumeMove(void *c);
extern int ZONEDATA_IsZoneInTableDFC0(int a);
extern void EVENT_MAPCHANGE_SetupExitEntranceParam(u8 *p, int a);
extern int EVENT_ENTRANCE_IN_Create(u8 *p);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern void *EVENT_MAPCHANGE_CreateChangeFieldEvent(u8 *p, int value);
extern void EVENT_MAPCHANGE_SetupEnterEntranceParam(u8 *p, int a);
typedef unsigned int   u32;
extern int EVENT_ENTRANCE_OUT_Create(u32 *p);
extern u8 GAME_DATA_GetIntrudeIdByte(void *p);
extern int INTRUDE_COMM_SendUnionInfoRequest(char *a, int b);
extern u8 INTRUDE_COMM_GetUnionInfoReceived(u8 *p);

int EVENT_MAPCHANGE_EntranceCommEvent(int a, int *state, u8 *p)
{
    int z;
    int y;
    u8 *w;

    z = *(int *)(p + 8);
    y = *(int *)(p + 4);
    w = (u8 *)INTRUDE_COMM_GetWorkIfRunning(GAMESYSTEM_GetGameComm((const struct Ctx *)(*(int *)(p + 0))));

    switch (*state) {
    case 0:
        FLDMMDL_SysPauseMove(FIELDMAP_GetMmdlSys((u8 *)z));
        if (ZONEDATA_IsZoneInTableDFC0(*(u16 *)(p + 0x14)) == 1) {
            *state = 5;
        } else {
            *state = 1;
        }
        break;
    case 1:
        EVENT_MAPCHANGE_SetupExitEntranceParam(p, a);
        GAME_EVENT_CallEvent((struct Evt *)a, (struct Evt **)EVENT_ENTRANCE_IN_Create(p + 0x4c));
        (*state)++;
        return 0x21;
    case 2:
        GAME_EVENT_CallEvent((struct Evt *)a, EVENT_MAPCHANGE_CreateChangeFieldEvent(p, 0));
        (*state)++;
        break;
    case 3:
        EVENT_MAPCHANGE_SetupEnterEntranceParam(p, a);
        GAME_EVENT_CallEvent((struct Evt *)a, (struct Evt **)EVENT_ENTRANCE_OUT_Create((u32 *)(p + 0x4c)));
        (*state)++;
        break;
    case 4:
        return 1;
    case 5:
        if (w == 0) {
            *state = 7;
            break;
        }
        if (INTRUDE_COMM_SendUnionInfoRequest((char *)w, GAME_DATA_GetIntrudeIdByte((void *)y)) == 1) {
            (*state)++;
        }
        break;
    case 6:
        if (w == 0) {
            *state = 7;
            break;
        }
        if (INTRUDE_COMM_GetUnionInfoReceived(w) == 1) {
            *state = 1;
        }
        break;
    case 7:
        FLDMMDL_SysResumeMove(FIELDMAP_GetMmdlSys((u8 *)z));
        return 1;
    }
    return 0;
}
