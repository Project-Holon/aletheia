/*
 * function: EVENT_COMM_COMMON_ItemSaleEventMain
 * address:  0x021823A8
 * packet:   pkt_ov018_021823A8
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201EF40  0x0201EF40  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   GAME_EVENT_ChangeEvent  0x0201235C  thumb
 *   func_020362DC  0x020362DC  arm
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb  ov010
 *   INTRUDE_CMD_SendProposal  0x0217405C  thumb  ov011
 *   INTRUDE_COMM_SendAnswer  0x02173B9C  thumb  ov011
 *   INTRUDE_COMM_NextRequestToken  0x021753B8  thumb  ov011
 *   INTRUDE_COMM_TakeRequestResult  0x02175514  thumb  ov011
 *   INTRUDE_COMM_GetJoinStatus  0x02175CF4  thumb  ov011
 *   INTRUDE_SUBDISP_CreateDisconnectEvent  0x0217CA84  thumb  ov018
 *   EVENT_COMM_COMMON_PrintMsg  0x0217F3C4  thumb  ov018
 *   EVENT_COMM_COMMON_IsPrintFinished  0x0217F40C  thumb  ov018
 *   EVENT_COMM_COMMON_IsKeyTrg  0x0217F420  thumb  ov018
 *   EVENT_COMM_COMMON_ExitCommonWork  0x0217FE38  thumb  ov018
 *   EVENT_COMM_COMMON_CreateMissionResultEvent  0x021804F8  thumb  ov018
 *   d_021839E0     0x021839E0  data  a2
 *
 * lever: EVENT_COMM_COMMON_CreateMissionResultEvent reads the live r1 as its second argument.
 * The f9C comparison value is forwarded unchanged on the taken arm.
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Outer {
    u8   pad00[0x10];
    void *p10;
    u8   pad14[0x42 - 0x14];
    u8   b42;
    u8   pad43[0x58 - 0x43];
    u16  h58[2];
    u8   pad5C[0x78 - 0x5C];
    u8   f78[0x98 - 0x78];
    int  f98;
    int  f9C;
    int  fA0;
} Outer;

extern const u16 d_021839E0[5][5];

struct Ctx;
struct Obj;
struct S0201235C;
struct WordSet;
extern void *func_020124E4(struct Obj *p);
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201EF40(struct WordSet *p, u32 i, u32 v);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void GAME_EVENT_ChangeEvent(struct S0201235C *o, u32 *out);
extern u32   func_020362DC(void);
extern int INTRUDE_COMM_GetWorkIfRunning(int a0);
extern int INTRUDE_CMD_SendProposal(char *a, char *b);
extern int INTRUDE_COMM_SendAnswer(int a, int b);
extern void  INTRUDE_COMM_NextRequestToken(u8 *);
extern int   INTRUDE_COMM_TakeRequestResult(u8 *);
extern int INTRUDE_COMM_GetJoinStatus(char *p, u8 *q);
extern int INTRUDE_SUBDISP_CreateDisconnectEvent(void *a, int b);
extern void  EVENT_COMM_COMMON_PrintMsg(u8 *, int);
extern int   EVENT_COMM_COMMON_IsPrintFinished(u8 *);
extern int   EVENT_COMM_COMMON_IsKeyTrg();
extern void  EVENT_COMM_COMMON_ExitCommonWork(u8 *, Outer *);
extern void *EVENT_COMM_COMMON_CreateMissionResultEvent(void *, int);

int EVENT_COMM_COMMON_ItemSaleEventMain(void *a, int *state, Outer *c)
{
    void *sub;
    u8 *v;
    u16 *h;

    sub = func_020124E4(a);
    v = (u8 *)INTRUDE_COMM_GetWorkIfRunning((int)((void *)GAMESYSTEM_GetGameComm(sub)));
    if (v == 0 && *state <= 4) {
        if (EVENT_COMM_COMMON_IsPrintFinished((u8 *)c + 0x10) == 0) {
            return 0;
        }
        if (*state < 9) {
            EVENT_COMM_COMMON_PrintMsg((u8 *)c + 0x10, 4);
            *state = 9;
            c->f98 = 1;
            return 0;
        }
    }
    switch (*state) {
    case 0:
        func_0201F02C(c->p10, 0, c->f78);
        h = c->h58;
        func_0201EF40(c->p10, 1, h[0]);
        func_0201EFA4(c->p10, 2, h[1], 5, 0, 1);
        func_0201F02C(c->p10, 3, GAME_DATA_GetMyStatus(GAMESYSTEM_GetGameData(sub)));
        EVENT_COMM_COMMON_PrintMsg((u8 *)c + 0x10, d_021839E0[0][c->b42]);
        (*state)++;
        break;
    case 1:
        if (EVENT_COMM_COMMON_IsPrintFinished((u8 *)c + 0x10) == 1) {
            switch (INTRUDE_COMM_TakeRequestResult(v)) {
            case 7:
                *state = 2;
                break;
            case 3:
            case 8:
                *state = 5;
                break;
            case 9:
                *state = 6;
                break;
            case 10:
                *state = 7;
                break;
            default:
                if ((func_020362DC() & 2) && INTRUDE_COMM_SendAnswer(v[0x154], v[0x158]) == 1) {
                    INTRUDE_COMM_NextRequestToken(v);
                    c->fA0 = 1;
                    *state = 8;
                }
                break;
            }
        }
        break;
    case 2:
        EVENT_COMM_COMMON_PrintMsg((u8 *)c + 0x10, d_021839E0[4][c->b42]);
        (*state)++;
        break;
    case 3:
        if (INTRUDE_CMD_SendProposal((char *)v, (char *)(v + 0x1AC)) == 1) {
            (*state)++;
        }
        break;
    case 4:
        if (INTRUDE_COMM_GetJoinStatus((char *)v, v + 0x1AC) != 0) {
            c->f9C = 1;
            *state = 9;
        }
        break;
    case 5:
        EVENT_COMM_COMMON_PrintMsg((u8 *)c + 0x10, d_021839E0[1][c->b42]);
        *state = 9;
        break;
    case 6:
        EVENT_COMM_COMMON_PrintMsg((u8 *)c + 0x10, d_021839E0[2][c->b42]);
        *state = 9;
        break;
    case 7:
        EVENT_COMM_COMMON_PrintMsg((u8 *)c + 0x10, d_021839E0[3][c->b42]);
        *state = 9;
        break;
    case 8:
        *state = 11;
        break;
    case 9:
        if (EVENT_COMM_COMMON_IsPrintFinished((u8 *)c + 0x10) == 1) {
            *state = 10;
        }
        break;
    case 10:
        if (EVENT_COMM_COMMON_IsKeyTrg() == 1) {
            *state = 11;
        }
        break;
    case 11:
        EVENT_COMM_COMMON_ExitCommonWork(v, c);
        if (c->f9C == 1) {
            GAME_EVENT_ChangeEvent(a, EVENT_COMM_COMMON_CreateMissionResultEvent(sub, c->f9C));
            return 0;
        }
        if (c->fA0 == 0) {
            GAME_EVENT_ChangeEvent(a, (u32 *)INTRUDE_SUBDISP_CreateDisconnectEvent(sub, 2));
            return 0;
        }
        GAME_EVENT_ChangeEvent(a, (u32 *)INTRUDE_SUBDISP_CreateDisconnectEvent(sub, 0));
        return 0;
    }
    return 0;
}
