/*
 * function: EVENT_COMM_COMMON_TalkedSearchAsTargetEventMain
 * address:  0x02181A98
 * packet:   pkt_ov018_02181A98
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
 *   func_0201F02C  0x0201F02C  thumb
 *   EVENT_COMM_COMMON_PrintMsg  0x0217F3C4  thumb
 *   EVENT_COMM_COMMON_IsPrintFinished  0x0217F40C  thumb
 *   EVENT_COMM_COMMON_IsKeyTrg  0x0217F420  thumb
 *   EVENT_COMM_COMMON_ExitCommonWork  0x0217FE38  thumb
 *   func_020061E4  0x020061E4  thumb
 *   INTRUDE_SUBDISP_CreatePalaceWarpEvent  0x0217CA1C  thumb
 *   GAME_EVENT_ChangeEvent  0x0201235C  thumb
 *   d_02183932     0x02183932  data  a2
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

extern unsigned short d_02183932[];

typedef unsigned int   u32;
struct Obj;
struct WordSet;
void *func_020124E4(struct Obj *p);
struct Ctx;
u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
struct S0201235C;
int INTRUDE_COMM_GetWorkIfRunning(int a0);
void func_0201F02C(struct WordSet *p, u32 i, void *a);
void EVENT_COMM_COMMON_PrintMsg(Ov018Obj *p, int a);
int EVENT_COMM_COMMON_IsPrintFinished(Ov018Obj *p);
int EVENT_COMM_COMMON_IsKeyTrg(void);
void EVENT_COMM_COMMON_ExitCommonWork(int v, Ov018Outer *c);
void func_020061E4(u32 a);
void *INTRUDE_SUBDISP_CreatePalaceWarpEvent(void *p);
void GAME_EVENT_ChangeEvent(struct S0201235C *o, u32 *out);

int EVENT_COMM_COMMON_TalkedSearchAsTargetEventMain(void *a, int *state, Ov018Outer *c)
{
    void *sub;
    void *sys;
    int v;

    sub = func_020124E4(a);
    sys = (void *)GAMESYSTEM_GetGameComm(sub);
    v = INTRUDE_COMM_GetWorkIfRunning((int)sys);
    switch (*state) {
    case 0:
        func_0201F02C(c->obj.f00, 0, &c->f78);
        EVENT_COMM_COMMON_PrintMsg(&c->obj, d_02183932[c->f42]);
        (*state)++;
        break;
    case 1:
        if (EVENT_COMM_COMMON_IsPrintFinished(&c->obj) == 1) {
            *state = 2;
        }
        break;
    case 2:
        if (EVENT_COMM_COMMON_IsKeyTrg() == 1) {
            *state = 3;
        }
        break;
    case 3:
        EVENT_COMM_COMMON_ExitCommonWork(v, c);
        if (INTRUDE_COMM_GetWorkIfRunning((int)sys) != 0) {
            func_020061E4(0x737);
            GAME_EVENT_ChangeEvent(a, INTRUDE_SUBDISP_CreatePalaceWarpEvent(sub));
            return 0;
        }
        return 1;
    }
    return 0;
}
