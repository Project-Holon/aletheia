/*
 * function: EVENT_COMM_COMMON_TalkedEventMain
 * address:  0x021800A4
 * packet:   pkt_ov018_021800A4
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Task callback in the shape of EVENT_COMM_COMMON_MsgScriptEventMain: a 12-state sequence driving
 * the Ov018Obj at +0x10, with an early skip to state 10 while the owner
 * object is absent.
 *
 * symbols:
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb  ov010
 *   INTRUDE_COMM_ClearRequestResult  0x0217553C  thumb  ov011
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FLDMMDL_SysPauseMove  0x0216D9A0  thumb  ov010
 *   GAME_DATA_GetPlayerStatus  0x02012950  thumb
 *   WORDSET_SetSlotMyStatus  0x0201F02C  thumb
 *   EVENT_COMM_COMMON_PrintMsg  0x0217F3C4  thumb
 *   FLDMMDL_CheckPossibleAcmd  0x0216D3CC  thumb  ov010
 *   FLDMMDL_SetAcmd  0x0216D410  thumb  ov010
 *   FLDMMDL_EndAcmd  0x0216D480  thumb  ov010
 *   INTRUDE_CMD_SendReadyNotice  0x02174258  thumb  ov011
 *   INTRUDE_COMM_TakeNoticeState  0x02175C40  thumb  ov011
 *   INTRUDE_COMM_SendReply  0x02173AE0  thumb  ov011
 *   EVENT_COMM_COMMON_IsPrintFinished  0x0217F40C  thumb
 *   INTRUDE_COMM_TakeRequestResult  0x02175514  thumb  ov011
 *   INTRUDE_COMM_SendNoticeBytes  0x02173C04  thumb  ov011
 *   INTRUDE_COMM_GetNotice  0x0217537C  thumb  ov011
 *   EVENT_COMM_COMMON_ChangeTalkedTypeEvent  0x0218034C  thumb
 *   EVENT_COMM_COMMON_IsKeyTrg  0x0217F420  thumb
 *   FLDMMDL_SysResumeMove  0x0216D9E4  thumb  ov010
 *   EVENT_COMM_COMMON_ExitCommonWork  0x0217FE38  thumb
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
    u8 pad00[4];
    void *f04;          /* 0x04 */
    u8 pad08[4];
    void *f0C;          /* 0x0C */
    Ov018Obj obj;       /* 0x10 */
    u8 f40;             /* 0x40 */
    u8 f41;             /* 0x41 */
    u8 pad42[0x99 - 0x42];
    u8 f99;             /* 0x99 */
} Outer;

struct Ctx;
struct Obj;
struct Rec44;
struct Sub24;
struct WordSet;
void *GAME_EVENT_GetGameSystem(struct Obj *p);
u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
void *GAMESYSTEM_GetGameData(const struct Ctx *p);
int INTRUDE_COMM_GetWorkIfRunning(int a0);
void INTRUDE_COMM_ClearRequestResult(u8 *);
void *FIELDMAP_GetMmdlSys(u8 *p);
void FLDMMDL_SysPauseMove(void *);
struct Rec44 *GAME_DATA_GetPlayerStatus(struct Sub24 *p, u32 i);
void WORDSET_SetSlotMyStatus(struct WordSet *p, u32 i, void *a);
void EVENT_COMM_COMMON_PrintMsg(Ov018Obj *p, int a);
int FLDMMDL_CheckPossibleAcmd(int a0);
void FLDMMDL_SetAcmd(void *, int);
int FLDMMDL_EndAcmd(char *p);
int INTRUDE_CMD_SendReadyNotice(char *a);
int INTRUDE_COMM_TakeNoticeState(void *p);
int INTRUDE_COMM_SendReply(int a, int b, int c, int d);
int EVENT_COMM_COMMON_IsPrintFinished(Ov018Obj *p);
int INTRUDE_COMM_TakeRequestResult(u8 *);
int INTRUDE_COMM_SendNoticeBytes(int, int);
u8 *INTRUDE_COMM_GetNotice(u8 *);
void EVENT_COMM_COMMON_ChangeTalkedTypeEvent(void *, Outer *, u8 *);
int EVENT_COMM_COMMON_IsKeyTrg(void);
u32 *FLDMMDL_SysResumeMove(void *c);
void EVENT_COMM_COMMON_ExitCommonWork(u8 *v, Outer *c);

int EVENT_COMM_COMMON_TalkedEventMain(void *a, int *state, Outer *c)
{
    void *sub;
    void *t;
    void *w;
    u8 *v;
    u8 *p;
    int k;
    int m;
    int flag;

    sub = GAME_EVENT_GetGameSystem(a);
    t = (void *)GAMESYSTEM_GetGameComm(sub);
    w = GAMESYSTEM_GetGameData(sub);
    v = (u8 *)INTRUDE_COMM_GetWorkIfRunning((int)t);
    if (v == 0) {
        if (EVENT_COMM_COMMON_IsPrintFinished(&c->obj) == 0) {
            return 0;
        }
        if (*state < 10) {
            EVENT_COMM_COMMON_PrintMsg(&c->obj, 4);
            *state = 10;
            return 0;
        }
    }
    switch (*state) {
    case 0:
        INTRUDE_COMM_ClearRequestResult(v);
        FLDMMDL_SysPauseMove(FIELDMAP_GetMmdlSys(c->f0C));
        WORDSET_SetSlotMyStatus(c->obj.f00, 0, GAME_DATA_GetPlayerStatus(w, v[0x154]));
        EVENT_COMM_COMMON_PrintMsg(&c->obj, 1);
        (*state)++;
        break;
    case 1:
        if (FLDMMDL_CheckPossibleAcmd((int)c->f04) == 1) {
            k = *(u16 *)(v + c->f40 * 0x1C + 0x9C);
            if (k == 2) {
                m = 3;
            } else if (k == 3) {
                m = 2;
            } else {
                m = 0;
                if (k != 1) {
                    m = 1;
                }
            }
            FLDMMDL_SetAcmd(c->f04, m);
            (*state)++;
        }
        break;
    case 2:
        if (FLDMMDL_EndAcmd(c->f04) == 1) {
            (*state)++;
        }
        break;
    case 3:
        if (INTRUDE_CMD_SendReadyNotice((char *)v) == 1) {
            (*state)++;
        }
        break;
    case 4:
        switch (INTRUDE_COMM_TakeNoticeState(v + 0x1AC)) {
        case 1:
            c->f99 = 1;
            (*state)++;
            break;
        case 2:
            (*state)++;
            break;
        }
        break;
    case 5:
        if (INTRUDE_COMM_SendReply((int)v, v[0x154], v[0x156], v[0x158]) == 1) {
            (*state)++;
        }
        break;
    case 6:
        if (EVENT_COMM_COMMON_IsPrintFinished(&c->obj) == 1) {
            k = INTRUDE_COMM_TakeRequestResult(v);
            flag = 0;
            switch (k) {
            case 0:
                break;
            case 1:
                *state = 7;
                break;
            case 2:
            case 3:
            default:
                flag = 1;
                break;
            }
            if (flag == 1) {
                EVENT_COMM_COMMON_PrintMsg(&c->obj, 4);
                *state = 10;
            }
        }
        break;
    case 7:
        if (INTRUDE_COMM_SendNoticeBytes(v[0x154], c->f99) == 1) {
            (*state)++;
        }
        break;
    case 8:
        p = INTRUDE_COMM_GetNotice(v);
        if (p != 0) {
            if (p[1] != c->f99 || c->f99 == 1) {
                c->f41 = 0;
            }
            *state = 9;
        }
        break;
    case 9:
        EVENT_COMM_COMMON_ChangeTalkedTypeEvent(a, c, v);
        return 0;
    case 10:
        if (EVENT_COMM_COMMON_IsKeyTrg() == 1) {
            *state = 11;
        }
        break;
    case 11:
        if (EVENT_COMM_COMMON_IsPrintFinished(&c->obj) == 1) {
            FLDMMDL_SysResumeMove(FIELDMAP_GetMmdlSys(c->f0C));
            EVENT_COMM_COMMON_ExitCommonWork(v, c);
            return 1;
        }
        break;
    }
    return 0;
}
