/*
 * function: EVENT_COMM_COMMON_BattleRequestEventMain
 * address:  0x0218123C
 * packet:   pkt_ov018_0218123C
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb  ov010
 *   INTRUDE_COMM_TogglePeerFlags  0x0215839C  thumb  ov010
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   EVENT_COMM_COMMON_InitMsgBox  0x0217F2B4  thumb
 *   EVENT_COMM_COMMON_ExitMsgBox  0x0217F318  thumb
 *   EVENT_COMM_COMMON_PrintMsg  0x0217F3C4  thumb
 *   EVENT_COMM_COMMON_IsPrintFinished  0x0217F40C  thumb
 *   EVENT_COMM_COMMON_IsKeyTrg  0x0217F420  thumb
 *   INTRUDE_COMM_TakeRequestResult  0x02175514  thumb  ov011
 *   func_020362DC  0x020362DC  arm
 *   INTRUDE_COMM_SendAnswer  0x02173B9C  thumb
 *   INTRUDE_COMM_NextRequestToken  0x021753B8  thumb
 *   INTRUDE_CMD_SendProposal  0x0217405C  thumb
 *   INTRUDE_COMM_GetJoinStatus  0x02175CF4  thumb
 *   INTRUDE_COMM_SetLock  0x021756F0  thumb
 *   INTRUDE_COMM_SendPeerFlags  0x021744D0  thumb
 *   INTRUDE_LINK_CreateEvent  0x021766CC  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   EVENT_COMM_COMMON_ExitCommonWork  0x0217FE38  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026474  0x02026474  thumb
 *   EVENT_COMM_COMMON_CreateMissionResultEvent  0x021804F8  thumb
 *   INTRUDE_SUBDISP_CreateDisconnectEvent  0x0217CA84  thumb
 *   GAME_EVENT_ChangeEvent  0x0201235C  thumb
 *   d_021838F6     0x021838F6  data  a2
 *   d_02183900     0x02183900  data  a2
 *   d_0218390A     0x0218390A  data  a2
 *   d_02183914     0x02183914  data  a2
 *   d_0218391E     0x0218391E  data  a2
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
    u8 pad00[0x10];
    Ov018Obj obj;       /* 0x10 */
    u8 f40;             /* 0x40 */
    u8 pad41;
    u8 f42;             /* 0x42 */
    u8 pad43[0x58 - 0x43];
    u16 f58;            /* 0x58 */
    u8 pad5A[0x78 - 0x5A];
    u8 f78[0x98 - 0x78]; /* 0x78 */
    int f98;            /* 0x98 */
    int f9C;            /* 0x9C */
    u8 fA0;
    u8 fA1;             /* 0xA1 */
    u8 padA2[2];
    int fA4;            /* 0xA4 */
    int fA8;            /* 0xA8 */
    int fAC;            /* 0xAC */
} Ov018Outer;

extern const u16 d_021838F6[];
extern const u16 d_02183900[];
extern const u16 d_0218390A[];
extern const u16 d_02183914[];
extern const u16 d_0218391E[];

struct Evt;
struct Obj;
struct S0201235C;
struct WordSet;
void *func_020124E4(struct Obj *p);
struct Ctx;
u32 GAMESYSTEM_GetGameComm(const struct Ctx *);
int INTRUDE_COMM_GetWorkIfRunning(int a0);
int INTRUDE_COMM_TogglePeerFlags(u8 *p, int m, int a2);
void func_0201F02C(struct WordSet *p, u32 i, void *a);
void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
void EVENT_COMM_COMMON_InitMsgBox(Ov018Obj *p, void *);
void EVENT_COMM_COMMON_ExitMsgBox(Ov018Obj *p);
void EVENT_COMM_COMMON_PrintMsg(Ov018Obj *p, u16 a);
int EVENT_COMM_COMMON_IsPrintFinished(Ov018Obj *p);
int EVENT_COMM_COMMON_IsKeyTrg(void);
int INTRUDE_COMM_TakeRequestResult(u8 *p);
u32 func_020362DC(void);
int INTRUDE_COMM_SendAnswer(int, int);
void INTRUDE_COMM_NextRequestToken(void *);
int INTRUDE_CMD_SendProposal(void *, void *);
int INTRUDE_COMM_GetJoinStatus(void *, void *);
void INTRUDE_COMM_SetLock(void *, int);
int INTRUDE_COMM_SendPeerFlags(void *, int, int);
void *INTRUDE_LINK_CreateEvent(void *, int *);
void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
void EVENT_COMM_COMMON_ExitCommonWork(void *v, Ov018Outer *c);
u32 func_02026454(void *obj);
u32 func_02026474(void *obj);
void *EVENT_COMM_COMMON_CreateMissionResultEvent(void *, int);
int INTRUDE_SUBDISP_CreateDisconnectEvent(void *a, int b);
void GAME_EVENT_ChangeEvent(struct S0201235C *o, u32 *out);

int EVENT_COMM_COMMON_BattleRequestEventMain(void *a, int *state, Ov018Outer *c)
{
    void *sub;
    void *t;
    u8 *v;
    void *r;

    sub = func_020124E4(a);
    t = (void *)GAMESYSTEM_GetGameComm(sub);
    v = (u8 *)INTRUDE_COMM_GetWorkIfRunning((int)t);
    if (v == 0) {
        if (EVENT_COMM_COMMON_IsPrintFinished(&c->obj) == 0) {
            return 0;
        }
        if (*state < 13) {
            EVENT_COMM_COMMON_InitMsgBox(&c->obj, sub);
            EVENT_COMM_COMMON_PrintMsg(&c->obj, 4);
            *state = 13;
            c->f98 = 1;
            return 0;
        }
    }
    switch (*state) {
    case 0:
        func_0201F02C(c->obj.f00, 0, c->f78);
        func_0201EFA4(c->obj.f00, 1, c->fA1, 3, 0, 1);
        EVENT_COMM_COMMON_PrintMsg(&c->obj, c->fA4 == 0 ? d_021838F6[c->f42] : d_02183900[c->f42]);
        (*state)++;
        break;
    case 1:
        if (EVENT_COMM_COMMON_IsPrintFinished(&c->obj) == 1) {
            switch (INTRUDE_COMM_TakeRequestResult(v)) {
            case 4:
                *state = 2;
                break;
            case 2:
            case 3:
                *state = 11;
                break;
            default:
                if ((func_020362DC() & 2) && INTRUDE_COMM_SendAnswer(v[0x154], v[0x158]) == 1) {
                    INTRUDE_COMM_NextRequestToken(v);
                    *state = 12;
                }
                break;
            }
        }
        break;
    case 2:
        EVENT_COMM_COMMON_PrintMsg(&c->obj, d_0218390A[c->f42]);
        *state = 3;
        break;
    case 3:
        if (INTRUDE_CMD_SendProposal(v, v + 0x1AC) == 1) {
            (*state)++;
        }
        break;
    case 4:
        if (INTRUDE_COMM_GetJoinStatus(v, v + 0x1AC) != 0) {
            INTRUDE_COMM_SetLock(v, 1);
            *state = 5;
        }
        break;
    case 5:
        if (EVENT_COMM_COMMON_IsPrintFinished(&c->obj) == 1 && INTRUDE_COMM_SendPeerFlags(v, c->f40, 1) == 1) {
            (*state)++;
        }
        break;
    case 6:
        if (INTRUDE_COMM_TogglePeerFlags(v, 1, c->f40) == 1) {
            *state = 7;
        } else if ((func_020362DC() & 2) && INTRUDE_COMM_SendAnswer(v[0x154], v[0x158]) == 1) {
            INTRUDE_COMM_NextRequestToken(v);
            *state = 12;
        }
        break;
    case 7:
        if (INTRUDE_COMM_SendPeerFlags(v, c->f40, 2) == 1) {
            (*state)++;
        }
        break;
    case 8:
        if (INTRUDE_COMM_TogglePeerFlags(v, 2, c->f40) == 1) {
            EVENT_COMM_COMMON_ExitMsgBox(&c->obj);
            *state = 9;
        } else if (INTRUDE_COMM_TakeRequestResult(v) == 3) {
            EVENT_COMM_COMMON_PrintMsg(&c->obj, 4);
            *state = 13;
        }
        break;
    case 9:
        c->fA8 = 1;
        GAME_EVENT_CallEvent(a, INTRUDE_LINK_CreateEvent(sub, &c->f9C));
        (*state)++;
        break;
    case 10:
        EVENT_COMM_COMMON_InitMsgBox(&c->obj, sub);
        EVENT_COMM_COMMON_PrintMsg(&c->obj, d_02183914[c->f42]);
        *state = 13;
        break;
    case 11:
        EVENT_COMM_COMMON_PrintMsg(&c->obj, d_0218391E[c->f42]);
        *state = 13;
        break;
    case 12:
        c->fAC = 1;
        *state = 15;
        break;
    case 13:
        if (EVENT_COMM_COMMON_IsPrintFinished(&c->obj) == 1) {
            *state = 14;
        }
        break;
    case 14:
        if (EVENT_COMM_COMMON_IsKeyTrg() == 1) {
            *state = 15;
        }
        break;
    case 15:
        EVENT_COMM_COMMON_ExitCommonWork(v, c);
        if (func_02026454(t) == 2 && func_02026474(t) != 0) {
            INTRUDE_COMM_SetLock((void *)func_02026474(t), 0);
        }
        if (c->fA8 == 1) {
            r = EVENT_COMM_COMMON_CreateMissionResultEvent(sub, c->fA8);
        } else if (c->fAC == 0) {
            r = (void *)INTRUDE_SUBDISP_CreateDisconnectEvent(sub, 1);
        } else {
            r = (void *)INTRUDE_SUBDISP_CreateDisconnectEvent(sub, 0);
        }
        GAME_EVENT_ChangeEvent(a, r);
        return 0;
    }
    return 0;
}
