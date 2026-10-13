/*
 * function: EVENT_MAPCHANGE_InitUnionInfo
 * address:  0x02183C58
 * packet:   pkt_ov020_02183C58
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetSecondUnionInfo  0x020127C4  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   FIELD_WFBC_DATA_LOCAL_Init  0x021860D4  thumb  ov020
 *   EVENT_FIELD_PROCLINK_CheckZoneFlag  0x02161D64  thumb  ov010
 *   GAME_DATA_GetMysteryRecvFlagB  0x020127F0  thumb
 *   EVENT_FIELD_PROCLINK_GetReturnInfo  0x02161F14  thumb  ov010
 */

typedef unsigned short u16;
typedef unsigned char  u8;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetSecondUnionInfo(void *p);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern void FIELD_WFBC_DATA_LOCAL_Init(u16 *p, int a1, int id);
extern int EVENT_FIELD_PROCLINK_CheckZoneFlag(int a0);
extern int GAME_DATA_GetMysteryRecvFlagB(int a);
extern void EVENT_FIELD_PROCLINK_GetReturnInfo(u16 *out, u8 *in, int c);

void EVENT_MAPCHANGE_InitUnionInfo(int a)
{
    int w = (int)GAMESYSTEM_GetGameData((const struct Ctx *)a);
    int r5 = (int)GAME_DATA_GetSecondUnionInfo((void *)w);

    FIELD_WFBC_DATA_LOCAL_Init((u16 *)r5, (int)GAME_DATA_GetMyStatus((void *)w), 1);
    EVENT_FIELD_PROCLINK_CheckZoneFlag((int)GAME_DATA_GetSecondUnionInfo((void *)w));
    r5 = GAME_DATA_GetMysteryRecvFlagB(w);
    EVENT_FIELD_PROCLINK_GetReturnInfo((u16 *)r5, (u8 *)GAME_DATA_GetSecondUnionInfo((void *)w), 1);
}
