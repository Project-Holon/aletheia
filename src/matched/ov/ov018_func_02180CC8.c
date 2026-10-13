/*
 * function: EVENT_COMM_COMMON_TalkedPowerGiftTargetEventMain
 * address:  0x02180CC8
 * packet:   pkt_ov018_02180CC8
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Task callback in the shape of EVENT_COMM_COMMON_MsgScriptEventMain: a 7-state sequence driving
 * the Ov018Obj at +0x10; state 2 pushes an ov083 child task.
 *
 * symbols:
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb  ov010
 *   func_0201F02C  0x0201F02C  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   func_0201F184  0x0201F184  thumb
 *   EVENT_COMM_COMMON_PrintMsg  0x0217F3C4  thumb
 *   EVENT_COMM_COMMON_IsPrintFinished  0x0217F40C  thumb
 *   EVENT_COMM_COMMON_IsKeyTrg  0x0217F420  thumb
 *   EVENT_COMM_COMMON_ExitMsgBox  0x0217F318  thumb
 *   EVENT_COMM_COMMON_InitMsgBox  0x0217F2B4  thumb
 *   GAME_EVENT_CreateOverlayEvent  0x020124AC  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   EVENT_COMM_COMMON_ExitCommonWork  0x0217FE38  thumb
 *   GPOWER_EVENT_CreateActivateEvent  0x021F5260  thumb  ov083
 *   ov083_id       0x00000053  data
 *   d_02183852     0x02183852  data   a2
 *   d_0218385C     0x0218385C  data   a2
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
    u8 pad40[2];
    u8 f42;             /* 0x42 */
    u8 pad43[0x58 - 0x43];
    u16 f58;            /* 0x58 */
    u8 pad5A[0x78 - 0x5A];
    u8 f78[0xA0 - 0x78]; /* 0x78 */
    int fA0;            /* 0xA0 */
} Outer;

typedef struct {
    u32 a;
    u32 zero;
} Args;

extern u8 ov083_id[];
extern u16 d_02183852[];
extern u16 d_0218385C[];

typedef signed int     s32;
struct Ctx;
struct Evt;
struct Obj;
struct WordSet;
void *GAME_EVENT_GetGameSystem(struct Obj *p);
u32 GAMESYSTEM_GetGameComm(const struct Ctx *);
int INTRUDE_COMM_GetWorkIfRunning(int a0);
void func_0201F02C(struct WordSet *p, u32 i, void *a);
void *GAMESYSTEM_GetGameData(const struct Ctx *p);
u8 *GAME_DATA_GetMyStatus(void *p);
void func_0201F184(struct WordSet *p, u32 i, s32 v);
void EVENT_COMM_COMMON_PrintMsg(Ov018Obj *p, int a);
int EVENT_COMM_COMMON_IsPrintFinished(Ov018Obj *p);
int EVENT_COMM_COMMON_IsKeyTrg(void);
void EVENT_COMM_COMMON_ExitMsgBox(Ov018Obj *p);
void EVENT_COMM_COMMON_InitMsgBox(Ov018Obj *p, void *sub);
struct Desc;
struct Desc *GAME_EVENT_CreateOverlayEvent(void *a0, u32 a1, u32 (*fn)(void *, u32), u32 a3);
void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
void EVENT_COMM_COMMON_ExitCommonWork(int v, Outer *c);
void *GPOWER_EVENT_CreateActivateEvent(void *a0, int *a1);

int EVENT_COMM_COMMON_TalkedPowerGiftTargetEventMain(void *a, int *state, Outer *c)
{
    void *sub;
    int v;
    Args args;

    sub = GAME_EVENT_GetGameSystem(a);
    v = INTRUDE_COMM_GetWorkIfRunning((int)((void *)GAMESYSTEM_GetGameComm(sub)));
    switch (*state) {
    case 0:
        func_0201F02C(c->obj.f00, 0, c->f78);
        func_0201F02C(c->obj.f00, 1, GAME_DATA_GetMyStatus(GAMESYSTEM_GetGameData(sub)));
        func_0201F184(c->obj.f00, 2, c->f58);
        c->fA0 = c->f42;
        EVENT_COMM_COMMON_PrintMsg(&c->obj, d_02183852[c->fA0]);
        (*state)++;
        break;
    case 1:
        if (EVENT_COMM_COMMON_IsPrintFinished(&c->obj) == 1) {
            (*state)++;
        }
        break;
    case 2:
        EVENT_COMM_COMMON_ExitMsgBox(&c->obj);
        args.a = c->f58;
        args.zero = 0;
        GAME_EVENT_CallEvent(a, (struct Evt **)GAME_EVENT_CreateOverlayEvent(sub, (u32)ov083_id, (u32 (*)(void *, u32))GPOWER_EVENT_CreateActivateEvent, (u32)(&args)));
        (*state)++;
        break;
    case 3:
        *state = 4;
        break;
    case 4:
        EVENT_COMM_COMMON_InitMsgBox(&c->obj, sub);
        func_0201F02C(c->obj.f00, 0, c->f78);
        EVENT_COMM_COMMON_PrintMsg(&c->obj, d_0218385C[c->fA0]);
        (*state)++;
        break;
    case 5:
        if (EVENT_COMM_COMMON_IsPrintFinished(&c->obj) == 1 && EVENT_COMM_COMMON_IsKeyTrg() == 1) {
            (*state)++;
        }
        break;
    case 6:
        EVENT_COMM_COMMON_ExitCommonWork(v, c);
        return 1;
    }
    return 0;
}
