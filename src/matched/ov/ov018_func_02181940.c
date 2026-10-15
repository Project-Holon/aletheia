/*
 * function: EVENT_COMM_COMMON_TalkSearchTargetEventMain
 * address:  0x02181940
 * packet:   pkt_ov018_02181940
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
 *   WORDSET_SetSlotMyStatus  0x0201F02C  thumb
 *   EVENT_COMM_COMMON_PrintMsg  0x0217F3C4  thumb
 *   EVENT_COMM_COMMON_IsPrintFinished  0x0217F40C  thumb
 *   EVENT_COMM_COMMON_IsKeyTrg  0x0217F420  thumb
 *   EVENT_COMM_COMMON_ExitCommonWork  0x0217FE38  thumb
 *   d_02183928     0x02183928  data  a2
 */

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
    unsigned char pad00[0x10];
    Ov018Obj obj;
    unsigned char pad40[2];
    unsigned char f42;
    unsigned char pad43[0x35];
    int f78;
} Ov018Outer;

extern unsigned short d_02183928[];

typedef unsigned int   u32;
struct Ctx;
struct Obj;
struct WordSet;
void *GAME_EVENT_GetGameSystem(struct Obj *p);
u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
int INTRUDE_COMM_GetWorkIfRunning(int a0);
void WORDSET_SetSlotMyStatus(struct WordSet *p, u32 i, void *a);
void EVENT_COMM_COMMON_PrintMsg(Ov018Obj *p, int a);
int EVENT_COMM_COMMON_IsPrintFinished(Ov018Obj *p);
int EVENT_COMM_COMMON_IsKeyTrg(void);
void EVENT_COMM_COMMON_ExitCommonWork(int v, Ov018Outer *c);

int EVENT_COMM_COMMON_TalkSearchTargetEventMain(void *a, int *state, Ov018Outer *c)
{
    int v;

    v = INTRUDE_COMM_GetWorkIfRunning(GAMESYSTEM_GetGameComm(GAME_EVENT_GetGameSystem(a)));
    switch (*state) {
    case 0:
        WORDSET_SetSlotMyStatus(c->obj.f00, 0, &c->f78);
        EVENT_COMM_COMMON_PrintMsg(&c->obj, d_02183928[c->f42]);
        (*state)++;
        break;
    case 1:
        if (EVENT_COMM_COMMON_IsPrintFinished(&c->obj) == 1) {
            (*state)++;
        }
        break;
    case 2:
        if (EVENT_COMM_COMMON_IsPrintFinished(&c->obj) == 1) {
            *state = 3;
        }
        break;
    case 3:
        if (EVENT_COMM_COMMON_IsKeyTrg() == 1) {
            *state = 4;
        }
        break;
    case 4:
        EVENT_COMM_COMMON_ExitCommonWork(v, c);
        return 1;
    }
    return 0;
}
