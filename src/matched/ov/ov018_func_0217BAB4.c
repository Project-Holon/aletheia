/*
 * function: INTRUDE_FIELD_UpdateAreaIndex
 * address:  0x0217BAB4
 * packet:   pkt_ov018_0217BAB4
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   GAMESYSTEM_GetMyPlayerWork  0x020120F8  thumb
 *   GAME_DATA_GetPlayerZoneId  0x02012AC8  thumb
 *   GAME_DATA_GetPlayerDirectionType  0x02012AE4  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_COMM_GetKind  0x02026454  thumb
 *   ZONEDATA_IsEntralink  0x02013D5C  thumb
 *   INTRUDE_COMM_HasResultReward  0x02175E90  thumb  ov011
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   GAMESYSTEM_IsEventActive  0x020120D8  thumb
 *   FIELD_PLAYER_SetPos  0x021A3044  thumb  ov021
 *   INTRUDE_COMM_AdjustAllRemotePositions  0x02175274  thumb  ov011
 *   GFL_NET_SYSTEM_GetCurrentAid  0x02039338  arm
 *   INTRUDE_COMM_SetIntrudeId  0x02175710  thumb  ov011
 *   EVENT_FIELD_PROCLINK_SetReturnLinkId  0x02161FEC  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct { u16 f : 3; u16 g : 13; } Fh;
typedef struct { int x, y, z; } Vec;

struct Ctx;
extern u8 *GAMESYSTEM_GetMyPlayerWork(const struct Ctx *p);
struct Rec44;
extern u16 GAME_DATA_GetPlayerZoneId(const struct Rec44 *p);
extern unsigned int GAME_DATA_GetPlayerDirectionType(const struct Rec44 *p);
typedef unsigned int   u32;
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u32 GAME_COMM_GetKind(void *obj);
extern u32 ZONEDATA_IsEntralink(u32 id);
extern int INTRUDE_COMM_HasResultReward(void *p, u8 *q);
struct VecFx32;
extern void FIELD_PLAYER_GetPos(unsigned char *, struct VecFx32 *);
extern int GAMESYSTEM_IsEventActive(char *p);
extern void FIELD_PLAYER_SetPos(u8 *p, void *v);
extern void INTRUDE_COMM_AdjustAllRemotePositions(u8 *, int);
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern void INTRUDE_COMM_SetIntrudeId(u8 *o, u32 v);
extern void EVENT_FIELD_PROCLINK_SetReturnLinkId(char *p, u16 v);

void INTRUDE_FIELD_UpdateAreaIndex(int a0, void *a1, void *a2, u8 *p)
{
    int x;
    int idx;
    Vec cur;
    Vec tmp;
    int flag;
    int prev;
    int limit;
    int sys;

    x = (int)GAMESYSTEM_GetMyPlayerWork(a1);
    sys = GAME_DATA_GetPlayerZoneId((const struct Rec44 *)x);
    GAME_DATA_GetPlayerDirectionType((const struct Rec44 *)x);
    x = GAMESYSTEM_GetGameComm(a1);
    flag = 0;
    GAMESYSTEM_GetGameData(a1);
    if ((int)GAME_COMM_GetKind((void *)x) != 2)
        return;
    if (p == 0)
        return;
    if (ZONEDATA_IsEntralink(sys) == 0)
        return;
    if (p[0x902] < 2)
        return;
    if (INTRUDE_COMM_HasResultReward(p, p + 0x1AC) == 1)
        return;
    FIELD_PLAYER_GetPos(a2, (struct VecFx32 *)&cur);
    tmp = cur;
    x = cur.x;
    prev = ((Fh *)(p + 0x86))->f;
    limit = (p[0x901] + 1) << 22;
    if (x < 0) {
        tmp.x = limit + x;
        flag = 1;
    } else if (x > limit) {
        tmp.x = x - limit;
        flag = 1;
    }
    if (flag == 1) {
        x = tmp.x;
        if (GAMESYSTEM_IsEventActive(a1) == 1) {
            tmp = cur;
            flag = 0;
        }
    }
    idx = x / 0x400000;
    if (flag == 1) {
        FIELD_PLAYER_SetPos(a2, &tmp);
        INTRUDE_COMM_AdjustAllRemotePositions(p, tmp.x);
    }
    idx += GFL_NET_SYSTEM_GetCurrentAid();
    if (idx > p[0x901])
        idx -= p[0x901] + 1;
    if (prev == idx)
        return;
    INTRUDE_COMM_SetIntrudeId(p, idx);
    p[0x900] = 1;
    EVENT_FIELD_PROCLINK_SetReturnLinkId((char *)(p + 0x35C), (u8)idx);
}
