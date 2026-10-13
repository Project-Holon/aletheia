/*
 * function: EVENT_COMM_COMMON_TalkPowerGiftTargetEventMain
 * address:  0x021809A4
 * packet:   pkt_ov018_021809A4
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Task callback in the shape of EVENT_COMM_COMMON_MsgScriptEventMain: an 8-state sequence driving
 * the Ov018Obj at +0x10, with an early skip to state 5 while the owner
 * object is absent.
 *
 * symbols:
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb  ov010
 *   INTRUDE_CMD_SendProposal  0x0217405C  thumb  ov011
 *   INTRUDE_COMM_GetJoinStatus  0x02175CF4  thumb  ov011
 *   func_0201F02C  0x0201F02C  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   func_0201F184  0x0201F184  thumb
 *   EVENT_COMM_COMMON_PrintMsg  0x0217F3C4  thumb
 *   EVENT_COMM_COMMON_IsPrintFinished  0x0217F40C  thumb
 *   EVENT_COMM_COMMON_IsKeyTrg  0x0217F420  thumb
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   EVENT_COMM_COMMON_ExitCommonWork  0x0217FE38  thumb
 *   EVENT_COMM_COMMON_CreateMissionResultEvent  0x021804F8  thumb
 *   GAME_EVENT_ChangeEvent  0x0201235C  thumb
 *   d_02183870     0x02183870  data   a2
 *   d_0218387A     0x0218387A  data   a2
 *   d_02183884     0x02183884  data   a2
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
    u8 f78[0x98 - 0x78]; /* 0x78 */
    int f98;            /* 0x98 */
    int f9C;            /* 0x9C */
} Outer;

extern u16 d_02183870[];
extern u16 d_0218387A[];
extern u16 d_02183884[];

typedef signed int     s32;
struct Ctx;
struct Obj;
struct S0201235C;
struct WordSet;
void *GAME_EVENT_GetGameSystem(struct Obj *p);
u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
int INTRUDE_COMM_GetWorkIfRunning(int a0);
int INTRUDE_CMD_SendProposal(char *a, char *b);
int INTRUDE_COMM_GetJoinStatus(char *p, u8 *q);
void func_0201F02C(struct WordSet *p, u32 i, void *a);
void *GAMESYSTEM_GetGameData(const struct Ctx *p);
u8 *GAME_DATA_GetMyStatus(void *p);
void func_0201F184(struct WordSet *p, u32 i, s32 v);
void EVENT_COMM_COMMON_PrintMsg(Ov018Obj *p, int a);
int EVENT_COMM_COMMON_IsPrintFinished(Ov018Obj *p);
int EVENT_COMM_COMMON_IsKeyTrg(void);
void GFL_USE_PlaySeDefaultVolume(u32 a);
void EVENT_COMM_COMMON_ExitCommonWork(u8 *v, Outer *c);
void *EVENT_COMM_COMMON_CreateMissionResultEvent(void *, int);
void GAME_EVENT_ChangeEvent(struct S0201235C *o, u32 *out);

int EVENT_COMM_COMMON_TalkPowerGiftTargetEventMain(void *a, int *state, Outer *c)
{
    void *sub;
    u8 *v;

    sub = GAME_EVENT_GetGameSystem(a);
    v = (u8 *)INTRUDE_COMM_GetWorkIfRunning((int)((void *)GAMESYSTEM_GetGameComm(sub)));
    if (v == 0 && *state <= 1) {
        if (EVENT_COMM_COMMON_IsPrintFinished(&c->obj) == 0) {
            return 0;
        }
        if (*state < 5) {
            EVENT_COMM_COMMON_PrintMsg(&c->obj, 4);
            *state = 5;
            c->f98 = 1;
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
        if (INTRUDE_COMM_GetJoinStatus((char *)v, v + 0x1AC) != 0) {
            c->f9C = 1;
            (*state)++;
        }
        break;
    case 2:
        func_0201F02C(c->obj.f00, 0, c->f78);
        func_0201F02C(c->obj.f00, 1, GAME_DATA_GetMyStatus(GAMESYSTEM_GetGameData(sub)));
        func_0201F184(c->obj.f00, 2, c->f58);
        EVENT_COMM_COMMON_PrintMsg(&c->obj, d_02183870[c->f42]);
        (*state)++;
        break;
    case 3:
        if (EVENT_COMM_COMMON_IsPrintFinished(&c->obj) == 1) {
            EVENT_COMM_COMMON_PrintMsg(&c->obj, d_0218387A[c->f42]);
            (*state)++;
        }
        break;
    case 4:
        if (EVENT_COMM_COMMON_IsPrintFinished(&c->obj) == 1) {
            EVENT_COMM_COMMON_PrintMsg(&c->obj, d_02183884[c->f42]);
            GFL_USE_PlaySeDefaultVolume(0x5E0);
            (*state)++;
        }
        break;
    case 5:
        if (EVENT_COMM_COMMON_IsPrintFinished(&c->obj) == 1) {
            *state = 6;
        }
        break;
    case 6:
        if (EVENT_COMM_COMMON_IsKeyTrg() == 1) {
            *state = 7;
        }
        break;
    case 7:
        EVENT_COMM_COMMON_ExitCommonWork(v, c);
        GAME_EVENT_ChangeEvent(a, EVENT_COMM_COMMON_CreateMissionResultEvent(sub, c->f9C));
        return 0;
    }
    return 0;
}
