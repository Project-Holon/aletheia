/*
 * function: INTRUDE_FIELD_UpdateCommState
 * address:  0x0217B968
 * packet:   pkt_ov018_0217B968
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0202648C  0x0202648C  thumb
 *   func_02026460  0x02026460  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   func_02035390  0x02035390  arm
 *   func_020353B0  0x020353B0  arm
 *   GAMESYSTEM_IsNetOffBySleep  0x02012204  thumb
 *   GAMESYSTEM_IsEventActive  0x020120D8  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetMyPlayerWork  0x020127A4  thumb
 *   GAME_DATA_GetPlayerZoneId  0x02012AC8  thumb
 *   func_02013D5C  0x02013D5C  thumb
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   func_02026454  0x02026454  thumb
 *   INTRUDE_FIELD_IsAtAreaEdge  0x0217B930  thumb  ov018
 *   INTRUDE_FIELD_StartComm  0x0217BA54  thumb  ov018
 *   GFL_NET_SYSTEM_GetConnectNum  0x020392B8  arm
 *   func_02026474  0x02026474  thumb
 *   GAME_COMM_RequestExitNoCallback  0x02026400  thumb
 *   GAME_COMM_RequestExit  0x0202640C  thumb
 *   INTRUDE_FIELD_StartCommAfterExit  0x0217BA48  thumb  ov018
 */

typedef unsigned char u8;

typedef struct { int x, y, z; } Vec;

typedef unsigned int   u32;
struct Comm;
struct Ctx;
struct Rec44;
extern u32 func_0202648C(void *obj);
extern u32 func_02026460(void *obj);
extern u32 func_0200FB24(void);
extern int func_02035390(void);
extern int func_020353B0(void);
extern u32 GAMESYSTEM_IsNetOffBySleep(const struct Ctx *p);
extern int GAMESYSTEM_IsEventActive(char *p);
struct SaveBlock;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetMyPlayerWork(struct SaveBlock *p);
extern unsigned short GAME_DATA_GetPlayerZoneId(const struct Rec44 *p);
extern u32 func_02013D5C(u32 id);
struct VecFx32;
extern void FIELD_PLAYER_GetPos(unsigned char *, struct VecFx32 *);
extern u32 func_02026454(void *obj);
extern int INTRUDE_FIELD_IsAtAreaEdge(int *p);
extern void INTRUDE_FIELD_StartComm(void *);
extern int GFL_NET_SYSTEM_GetConnectNum(void);
extern u32 func_02026474(void *obj);
extern void GAME_COMM_RequestExitNoCallback(struct Comm *p);
extern void GAME_COMM_RequestExit(struct Comm *p, u32 a, u32 b);
extern void INTRUDE_FIELD_StartCommAfterExit(int, int);

void INTRUDE_FIELD_UpdateCommState(int a0, void *a1, void *a2, void *a3)
{
    Vec v;

    if (func_0202648C(a2) != 0)
        return;
    if (func_02026460(a2) == 1)
        return;
    if (func_0200FB24() != 0)
        return;
    if (func_02035390() == 1 && func_020353B0() == 1)
        return;
    if (GAMESYSTEM_IsNetOffBySleep(a1) == 1)
        return;
    if (GAMESYSTEM_IsEventActive(a1) == 1)
        return;
    if (func_02013D5C(GAME_DATA_GetPlayerZoneId((const struct Rec44 *)GAME_DATA_GetMyPlayerWork(GAMESYSTEM_GetGameData(a1)))) == 0)
        return;
    FIELD_PLAYER_GetPos(a3, (struct VecFx32 *)&v);
    switch (func_02026454(a2)) {
    case 0:
        if (INTRUDE_FIELD_IsAtAreaEdge((int *)(&v)) == 1)
            INTRUDE_FIELD_StartComm(a1);
        break;
    case 2:
        if (INTRUDE_FIELD_IsAtAreaEdge((int *)(&v)) != 0)
            return;
        if (GFL_NET_SYSTEM_GetConnectNum() > 1)
            return;
        if (((u8 *)func_02026474(a2))[0x8FD] == 4)
            return;
        GAME_COMM_RequestExitNoCallback(a2);
        break;
    case 1:
        if (INTRUDE_FIELD_IsAtAreaEdge((int *)(&v)) == 1)
            GAME_COMM_RequestExit(a2, (u32)INTRUDE_FIELD_StartCommAfterExit, (u32)a1);
        break;
    }
}
