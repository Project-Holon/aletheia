/*
 * function: EVENT_COMM_COMMON_BattleAnswerEventMain
 * address:  0x02181584
 * packet:   pkt_ov018_02181584
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
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
 *   EVENT_COMM_COMMON_DeleteChoice  0x0217F4C4  thumb
 *   EVENT_COMM_COMMON_StartChoice  0x0217F4D8  thumb
 *   EVENT_COMM_COMMON_PollChoice  0x0217F508  thumb
 *   INTRUDE_COMM_TakeRequestResult  0x02175514  thumb  ov011
 *   KEY_GetTrg  0x020362DC  arm
 *   INTRUDE_COMM_SendAnswer  0x02173B9C  thumb
 *   INTRUDE_COMM_SendReply  0x02173AE0  thumb  ov011
 *   INTRUDE_COMM_NextRequestToken  0x021753B8  thumb
 *   INTRUDE_COMM_SetLock  0x021756F0  thumb
 *   INTRUDE_COMM_SendPeerFlags  0x021744D0  thumb
 *   INTRUDE_LINK_CreateEvent  0x021766CC  thumb
 *   INTRUDE_COMM_PickEntryForKind  0x021763D8  thumb  ov011
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetLastBattleRecSlot  0x020127B8  thumb
 *   GAME_COMM_RequestExitNoCallback  0x02026400  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   EVENT_COMM_COMMON_ExitCommonWork  0x0217FE38  thumb
 *   GAME_COMM_GetKind  0x02026454  thumb
 *   GAME_COMM_GetWork  0x02026474  thumb
 *   d_021838C4     0x021838C4  data  a2
 *   d_021838CE     0x021838CE  data  a2
 *   d_021838D8     0x021838D8  data  a2
 *   d_021838E2     0x021838E2  data  a2
 *   d_021838EC     0x021838EC  data  a2
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

extern const u16 d_021838C4[];
extern const u16 d_021838CE[];
extern const u16 d_021838D8[];
extern const u16 d_021838E2[];
extern const u16 d_021838EC[];

struct Comm;
struct Ctx;
struct Evt;
struct Obj;
struct WordSet;
void *GAME_EVENT_GetGameSystem(struct Obj *p);
u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
int INTRUDE_COMM_GetWorkIfRunning(int a0);
int INTRUDE_COMM_TogglePeerFlags(u8 *p, int m, int a2);
void func_0201F02C(struct WordSet *p, u32 i, void *a);
void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
void EVENT_COMM_COMMON_InitMsgBox(Ov018Obj *p, void *);
void EVENT_COMM_COMMON_ExitMsgBox(Ov018Obj *p);
void EVENT_COMM_COMMON_PrintMsg(Ov018Obj *p, u16 a);
int EVENT_COMM_COMMON_IsPrintFinished(Ov018Obj *p);
int EVENT_COMM_COMMON_IsKeyTrg(void);
void EVENT_COMM_COMMON_DeleteChoice(Ov018Obj *p);
void EVENT_COMM_COMMON_StartChoice(void **p, int a);
int EVENT_COMM_COMMON_PollChoice(void **p);
int INTRUDE_COMM_TakeRequestResult(u8 *p);
u32 KEY_GetTrg(void);
int INTRUDE_COMM_SendAnswer(int, int);
int INTRUDE_COMM_SendReply(int a, int b, int c, int d);
void INTRUDE_COMM_NextRequestToken(void *);
void INTRUDE_COMM_SetLock(void *, int);
int INTRUDE_COMM_SendPeerFlags(void *, int, int);
void *INTRUDE_LINK_CreateEvent(void *, int *);
void INTRUDE_COMM_PickEntryForKind(u8 *p, u32 key);
void *GAMESYSTEM_GetGameData(const struct Ctx *p);
void *GAME_DATA_GetLastBattleRecSlot(void *);
void GAME_COMM_RequestExitNoCallback(struct Comm *p);
void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
void EVENT_COMM_COMMON_ExitCommonWork(void *v, Ov018Outer *c);
u32 GAME_COMM_GetKind(void *obj);
u32 GAME_COMM_GetWork(void *obj);

int EVENT_COMM_COMMON_BattleAnswerEventMain(void *a, int *state, Ov018Outer *c)
{
    void *sub;
    void *t;
    u8 *v;

    sub = GAME_EVENT_GetGameSystem(a);
    t = (void *)GAMESYSTEM_GetGameComm(sub);
    v = (u8 *)INTRUDE_COMM_GetWorkIfRunning((int)t);
    if (v == 0) {
        if (EVENT_COMM_COMMON_IsPrintFinished(&c->obj) == 0) {
            return 0;
        }
        if (*state < 14 && *state != 1 && *state != 2) {
            EVENT_COMM_COMMON_InitMsgBox(&c->obj, sub);
            EVENT_COMM_COMMON_PrintMsg(&c->obj, 4);
            *state = 14;
            c->f98 = 1;
            return 0;
        }
    }
    switch (*state) {
    case 0:
        func_0201F02C(c->obj.f00, 0, c->f78);
        func_0201EFA4(c->obj.f00, 1, c->fA1, 3, 0, 1);
        EVENT_COMM_COMMON_PrintMsg(&c->obj, c->fA4 == 0 ? d_021838C4[c->f42] : d_021838CE[c->f42]);
        (*state)++;
        break;
    case 1:
        if (EVENT_COMM_COMMON_IsPrintFinished(&c->obj) == 1) {
            EVENT_COMM_COMMON_StartChoice((void **)(&c->obj), (int)sub);
            (*state)++;
        }
        break;
    case 2:
        switch (EVENT_COMM_COMMON_PollChoice((void **)(&c->obj))) {
        case 0:
            EVENT_COMM_COMMON_DeleteChoice(&c->obj);
            *state = 3;
            break;
        case 1:
            EVENT_COMM_COMMON_DeleteChoice(&c->obj);
            *state = 11;
            break;
        }
        break;
    case 3:
        if (INTRUDE_COMM_SendReply((int)v, v[0x154], 4, v[0x158]) == 1) {
            INTRUDE_COMM_SetLock(v, 1);
            *state = 4;
        }
        break;
    case 4:
        EVENT_COMM_COMMON_PrintMsg(&c->obj, d_021838D8[c->f42]);
        (*state)++;
        break;
    case 5:
        if (EVENT_COMM_COMMON_IsPrintFinished(&c->obj) == 1 && INTRUDE_COMM_SendPeerFlags(v, c->f40, 1) == 1) {
            (*state)++;
        }
        break;
    case 6:
        if (INTRUDE_COMM_TogglePeerFlags(v, 1, c->f40) == 1) {
            *state = 7;
        } else if (KEY_GetTrg() & 2) {
            if (INTRUDE_COMM_SendAnswer(v[0x154], v[0x158]) == 1) {
                INTRUDE_COMM_NextRequestToken(v);
                *state = 13;
                GAME_COMM_RequestExitNoCallback(t);
            }
        } else if (INTRUDE_COMM_TakeRequestResult(v) == 3) {
            EVENT_COMM_COMMON_PrintMsg(&c->obj, 4);
            *state = 14;
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
            *state = 14;
        }
        break;
    case 9:
        GAME_EVENT_CallEvent(a, INTRUDE_LINK_CreateEvent(sub, &c->f9C));
        (*state)++;
        break;
    case 10:
        EVENT_COMM_COMMON_InitMsgBox(&c->obj, sub);
        EVENT_COMM_COMMON_PrintMsg(&c->obj, d_021838E2[c->f42]);
        *state = 14;
        break;
    case 11:
        if (INTRUDE_COMM_SendReply((int)v, v[0x154], 2, v[0x158]) == 1) {
            INTRUDE_COMM_PickEntryForKind(GAME_DATA_GetLastBattleRecSlot(GAMESYSTEM_GetGameData(sub)), 0);
            *state = 12;
        }
        break;
    case 12:
        EVENT_COMM_COMMON_PrintMsg(&c->obj, d_021838EC[c->f42]);
        *state = 14;
        break;
    case 13:
        *state = 16;
        break;
    case 14:
        if (EVENT_COMM_COMMON_IsPrintFinished(&c->obj) == 1) {
            *state = 15;
        }
        break;
    case 15:
        if (EVENT_COMM_COMMON_IsKeyTrg() == 1) {
            *state = 16;
        }
        break;
    case 16:
        EVENT_COMM_COMMON_ExitCommonWork(v, c);
        if (GAME_COMM_GetKind(t) == 2 && GAME_COMM_GetWork(t) != 0) {
            INTRUDE_COMM_SetLock((void *)GAME_COMM_GetWork(t), 0);
        }
        return 1;
    }
    return 0;
}
