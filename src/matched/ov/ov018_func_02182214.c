/*
 * function: EVENT_COMM_COMMON_OfferAnswerEventMain
 * address:  0x02182214
 * packet:   pkt_ov018_02182214
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb  ov010
 *   INTRUDE_CMD_SendProposal  0x0217405C  thumb  ov011
 *   INTRUDE_COMM_GetJoinStatus  0x02175CF4  thumb  ov011
 *   INTRUDE_COMM_SendProfile  0x021745F8  thumb  ov011
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   WORDSET_SetSlotMyStatus  0x0201F02C  thumb
 *   WORDSET_Callback_EF40  0x0201EF40  thumb
 *   GAME_DATA_GetExitMode  0x02012B58  thumb
 *   EVENT_COMM_COMMON_GetPeerTalkStatus  0x0217F5F0  thumb
 *   EVENT_COMM_COMMON_ExitMsgBox  0x0217F318  thumb
 *   EVENT_COMM_COMMON_PrintMsg  0x0217F3C4  thumb
 *   EVENT_COMM_COMMON_IsPrintFinished  0x0217F40C  thumb
 *   EVENT_COMM_COMMON_IsKeyTrg  0x0217F420  thumb
 *   EVENT_COMM_COMMON_CreateMissionResultEvent  0x021804F8  thumb
 *   GAME_EVENT_ChangeEvent  0x0201235C  thumb
 *   d_02183998     0x02183998  data  a2
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    void *f00;
    void *f04;
    void *f08;
    void *f0C;
    void *f10;
    void *f14;
    void *f18;
    void *f1C;
    void *f20;
    void *f24;
    unsigned char f28;
    unsigned char pad29[3];
    void *f2C;
} Ov018Obj;

typedef struct {
    Ov018Obj obj;       /* 0x00 */
    u8 f30[0x40 - 0x30]; /* 0x30 */
    u16 f40;            /* 0x40 */
    u8 pad42[2];
    u16 f44;            /* 0x44 */
    u8 pad46[2];
    int f48;            /* 0x48 */
    int f4C;            /* 0x4C */
    int f50;            /* 0x50 */
} Ov018Work;

extern const u16 d_02183998[];

struct Ctx;
struct Obj;
struct S0201235C;
struct WordSet;
void *GAME_EVENT_GetGameSystem(struct Obj *p);
u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
void *GAMESYSTEM_GetGameData(const struct Ctx *p);
void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
int INTRUDE_COMM_GetWorkIfRunning(int a0);
struct BigObj;
int INTRUDE_CMD_SendProposal(char *a, char *b);
int INTRUDE_COMM_GetJoinStatus(char *p, u8 *q);
int INTRUDE_COMM_SendProfile(u32 a, u32 b);
u8 *GAME_DATA_GetMyStatus(void *p);
void WORDSET_SetSlotMyStatus(struct WordSet *p, u32 i, void *a);
void WORDSET_Callback_EF40(struct WordSet *p, u32 i, u32 v);
u8 GAME_DATA_GetExitMode(const struct BigObj *p);
int EVENT_COMM_COMMON_GetPeerTalkStatus(void *, u8);
void EVENT_COMM_COMMON_ExitMsgBox(Ov018Obj *p);
void EVENT_COMM_COMMON_PrintMsg(Ov018Obj *p, u16 a);
int EVENT_COMM_COMMON_IsPrintFinished(Ov018Obj *p);
int EVENT_COMM_COMMON_IsKeyTrg(void);
void *EVENT_COMM_COMMON_CreateMissionResultEvent(void *, int);
void GAME_EVENT_ChangeEvent(struct S0201235C *o, u32 *out);

int EVENT_COMM_COMMON_OfferAnswerEventMain(void *a, int *state, Ov018Work *c)
{
    void *sub;
    void *x;
    u8 *v;
    int idx;

    sub = GAME_EVENT_GetGameSystem(a);
    v = (u8 *)GAMESYSTEM_GetGameComm(sub);
    x = GAMESYSTEM_GetGameData(sub);
    GAMESYSTEM_GetFieldMap(sub);
    v = (u8 *)INTRUDE_COMM_GetWorkIfRunning((int)v);
    if (v == 0) {
        if (EVENT_COMM_COMMON_IsPrintFinished(&c->obj) == 0) {
            return 0;
        }
        if (*state < 4) {
            EVENT_COMM_COMMON_PrintMsg(&c->obj, 6);
            *state = 4;
            c->f48 = 1;
            return 0;
        }
    }
    switch (*state) {
    case 0:
        if (INTRUDE_CMD_SendProposal((char *)v, (char *)(v + 0x1AC)) == 1) {
            (*state)++;
        }
        break;
    case 1:
        if ((c->f50 = INTRUDE_COMM_GetJoinStatus((char *)v, v + 0x1AC)) != 0) {
            (*state)++;
        }
        break;
    case 2:
        WORDSET_SetSlotMyStatus(c->obj.f00, 0, GAME_DATA_GetMyStatus(x));
        WORDSET_Callback_EF40(c->obj.f00, 1, c->f40);
        if (c->f50 == 1) {
            idx = d_02183998[EVENT_COMM_COMMON_GetPeerTalkStatus(v, (int)GAME_DATA_GetExitMode(x))];
            c->f4C = 1;
        } else {
            idx = 5;
        }
        EVENT_COMM_COMMON_PrintMsg(&c->obj, idx);
        (*state)++;
        break;
    case 3:
        if (c->f4C == 1) {
            if (INTRUDE_COMM_SendProfile((u8)c->f44, (u32)c->f30) == 1) {
                (*state)++;
            }
        } else {
            (*state)++;
        }
        break;
    case 4:
        if (EVENT_COMM_COMMON_IsPrintFinished(&c->obj) == 1) {
            *state = 5;
        }
        break;
    case 5:
        if (EVENT_COMM_COMMON_IsKeyTrg() == 1) {
            *state = 6;
        }
        break;
    case 6:
        EVENT_COMM_COMMON_ExitMsgBox(&c->obj);
        GAME_EVENT_ChangeEvent(a, EVENT_COMM_COMMON_CreateMissionResultEvent(sub, c->f4C));
        return 0;
    }
    return 0;
}
