/*
 * function: EVENT_COMM_COMMON_TalkEventMain
 * address:  0x0217FE6C
 * packet:   pkt_ov018_0217FE6C
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Task callback in the shape of EVENT_COMM_COMMON_MsgScriptEventMain: a 10-state sequence; state 0
 * copies the 0x98-byte work block into a temporary allocation (lines 493
 * and 517 of the file string at 0x02183B30) and hands it to one of the
 * follow-up task starters.
 *
 * symbols:
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb  ov010
 *   EVENT_COMM_COMMON_IsPrintFinished  0x0217F40C  thumb
 *   EVENT_COMM_COMMON_PrintMsg  0x0217F3C4  thumb
 *   INTRUDE_COMM_GetRequestKind  0x02175DCC  thumb  ov011
 *   func_02030734  0x02030734  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   func_020307B0  0x020307B0  arm
 *   INTRUDE_COMM_GetSessionResult  0x02175BCC  thumb  ov011
 *   INTRUDE_COMM_IsSessionActive  0x02175B14  thumb  ov011
 *   INTRUDE_COMM_IsSessionAccepted  0x02175B8C  thumb  ov011
 *   INTRUDE_COMM_IsRequestFromNetId  0x0217620C  thumb  ov011
 *   EVENT_COMM_COMMON_StartMsgScriptEvent  0x02182A08  thumb  ov018
 *   EVENT_COMM_COMMON_StartMsgEvent105  0x02182998  thumb  ov018
 *   EVENT_COMM_COMMON_ChangeSearchFoundEvent  0x02181BE8  thumb  ov018
 *   EVENT_COMM_COMMON_StartMsgEvent95  0x02182988  thumb  ov018
 *   INTRUDE_CMD_SendReadyNotice  0x02174258  thumb  ov011
 *   INTRUDE_COMM_TakeNoticeState  0x02175C40  thumb  ov011
 *   INTRUDE_SUBDISP_MainRequestAnswerSeq  0x0217C914  thumb  ov018
 *   INTRUDE_COMM_ClearRequestResult  0x0217553C  thumb  ov011
 *   INTRUDE_COMM_SendNoticeBytes  0x02173C04  thumb  ov011
 *   INTRUDE_COMM_GetNotice  0x0217537C  thumb  ov011
 *   EVENT_COMM_COMMON_ChangeTalkTypeEvent  0x021802A8  thumb  ov018
 *   EVENT_COMM_COMMON_IsKeyTrg  0x0217F420  thumb
 *   EVENT_COMM_COMMON_ExitCommonWork  0x0217FE38  thumb
 *   str_02183B30   0x02183B30  data   a1
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
    u16 f00;            /* 0x00 */
    u8 pad02[0x10 - 2];
    Ov018Obj obj;       /* 0x10 */
    u8 f40;             /* 0x40 */
    u8 f41;             /* 0x41 */
    u8 pad42[0x98 - 0x42];
    u8 f98;             /* 0x98 */
    u8 f99;             /* 0x99 */
} Outer;

typedef struct {
    u16 lo : 9;
    u16 f9 : 6;
    u16 f15 : 1;
} Bits;

extern char str_02183B30[];

struct Obj;
void *GAME_EVENT_GetGameSystem(struct Obj *p);
struct Ctx;
u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
int INTRUDE_COMM_GetWorkIfRunning(int a0);
int EVENT_COMM_COMMON_IsPrintFinished(Ov018Obj *p);
void EVENT_COMM_COMMON_PrintMsg(Ov018Obj *p, int a);
int INTRUDE_COMM_GetRequestKind(void *p);
void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
void MI_CpuCopy8(void *, void *, int);
u32 func_020307B0(void *p);
u8 *INTRUDE_COMM_GetSessionResult(u8 *p);
int INTRUDE_COMM_IsSessionActive(u8 *);
int INTRUDE_COMM_IsSessionAccepted(u8 *);
int INTRUDE_COMM_IsRequestFromNetId(u8 *, int);
void EVENT_COMM_COMMON_StartMsgScriptEvent(void *, void *);
void EVENT_COMM_COMMON_StartMsgEvent105(void *, void *);
void EVENT_COMM_COMMON_ChangeSearchFoundEvent(void *, void *);
void EVENT_COMM_COMMON_StartMsgEvent95(void *, void *);
int INTRUDE_CMD_SendReadyNotice(char *a);
int INTRUDE_COMM_TakeNoticeState(void *p);
int INTRUDE_SUBDISP_MainRequestAnswerSeq(u8 *v, u8 *w, u8 *state);
void INTRUDE_COMM_ClearRequestResult(u8 *);
int INTRUDE_COMM_SendNoticeBytes(int, int);
u8 *INTRUDE_COMM_GetNotice(u8 *);
void EVENT_COMM_COMMON_ChangeTalkTypeEvent(void *, Outer *, u8 *);
int EVENT_COMM_COMMON_IsKeyTrg(void);
void EVENT_COMM_COMMON_ExitCommonWork(u8 *v, Outer *c);

int EVENT_COMM_COMMON_TalkEventMain(void *a, int *state, Outer *c)
{
    u8 *v;
    u8 *p;
    void *t;
    int kind;
    Bits *b;

    v = (u8 *)INTRUDE_COMM_GetWorkIfRunning((int)((void *)GAMESYSTEM_GetGameComm(GAME_EVENT_GetGameSystem(a))));
    if (v == 0) {
        if (EVENT_COMM_COMMON_IsPrintFinished(&c->obj) == 0) {
            return 0;
        }
        if (*state <= 6) {
            EVENT_COMM_COMMON_PrintMsg(&c->obj, 4);
            *state = 8;
            return 0;
        }
    }
    switch (*state) {
    case 0:
        kind = INTRUDE_COMM_GetRequestKind(v + 0x1AC);
        b = (Bits *)(v + 0xA2 + c->f40 * 0x1C);
        if (b->f15 == 1) {
            t = func_02030734((u16)((c->f00 & 0x7FFF) | 0x8000), 0x98, 1, str_02183B30, 493);
            MI_CpuCopy8(c, t, 0x98);
            if (INTRUDE_COMM_GetSessionResult(v + 0x1AC) == 0 && INTRUDE_COMM_IsSessionActive(v + 0x1AC) == 1
                && INTRUDE_COMM_IsSessionAccepted(v + 0x1AC) == 1 && INTRUDE_COMM_IsRequestFromNetId(v + 0x1AC, c->f40) == 1) {
                EVENT_COMM_COMMON_StartMsgScriptEvent(a, t);
            } else {
                EVENT_COMM_COMMON_StartMsgEvent105(a, t);
            }
            func_020307B0(t);
        } else if (b->f9 != 0) {
            t = func_02030734((u16)((c->f00 & 0x7FFF) | 0x8000), 0x98, 1, str_02183B30, 517);
            MI_CpuCopy8(c, t, 0x98);
            if (((Bits *)(v + c->f40 * 0x1C + 0xA2))->f9 == 2) {
                if (kind == 5) {
                    EVENT_COMM_COMMON_ChangeSearchFoundEvent(a, t);
                } else {
                    EVENT_COMM_COMMON_StartMsgEvent95(a, t);
                }
            } else {
                EVENT_COMM_COMMON_StartMsgEvent105(a, t);
            }
            func_020307B0(t);
        } else {
            (*state)++;
        }
        break;
    case 1:
        if (INTRUDE_CMD_SendReadyNotice((char *)v) == 1) {
            (*state)++;
        }
        break;
    case 2:
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
    case 3:
        switch (INTRUDE_SUBDISP_MainRequestAnswerSeq(v, (u8 *)c, &c->f98)) {
        case 1:
            INTRUDE_COMM_ClearRequestResult(v);
            *state = 4;
            break;
        case 2:
            *state = 9;
            break;
        case 3:
            *state = 7;
            break;
        }
        break;
    case 4:
        if (INTRUDE_COMM_SendNoticeBytes(c->f40, c->f99) == 1) {
            (*state)++;
        }
        break;
    case 5:
        p = INTRUDE_COMM_GetNotice(v);
        if (p != 0) {
            if (p[1] != c->f99 || c->f99 == 1) {
                c->f41 = 0;
            }
            (*state)++;
        }
        break;
    case 6:
        EVENT_COMM_COMMON_ChangeTalkTypeEvent(a, c, v);
        return 0;
    case 7:
        *state = 9;
        break;
    case 8:
        if (EVENT_COMM_COMMON_IsKeyTrg() == 1) {
            *state = 9;
        }
        break;
    case 9:
        EVENT_COMM_COMMON_ExitCommonWork(v, c);
        return 1;
    }
    return 0;
}
