/*
 * function: EVENT_COMM_COMMON_TalkedGreetingAsTargetEventMain
 * address:  0x02181FD8
 * packet:   pkt_ov018_02181FD8
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Task callback in the shape of EVENT_COMM_COMMON_TalkPowerGiftTargetEventMain: a 4-state sequence with an exit that retasks the callback driving
 * the Ov018Obj at +0x10.
 *
 * symbols:
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb  ov010
 *   func_0201F02C  0x0201F02C  thumb
 *   EVENT_COMM_COMMON_PrintMsg  0x0217F3C4  thumb  ov018
 *   EVENT_COMM_COMMON_IsPrintFinished  0x0217F40C  thumb  ov018
 *   EVENT_COMM_COMMON_IsKeyTrg  0x0217F420  thumb  ov018
 *   EVENT_COMM_COMMON_ExitCommonWork  0x0217FE38  thumb  ov018
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   INTRUDE_SUBDISP_CreatePalaceWarpEvent  0x0217CA1C  thumb  ov018
 *   GAME_EVENT_ChangeEvent  0x0201235C  thumb
 *   d_0218397A     0x0218397A  data   a2
 */

typedef unsigned char u8;
typedef unsigned short u16;

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
    u8 pad43[0x78 - 0x43];
    u8 f78[0x98 - 0x78]; /* 0x78 */
} Outer;

extern u16 d_0218397A[];

typedef unsigned int   u32;
struct Obj;
struct S0201235C;
struct WordSet;
void *GAME_EVENT_GetGameSystem(struct Obj *p);
struct Ctx;
u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
int INTRUDE_COMM_GetWorkIfRunning(int a0);
void func_0201F02C(struct WordSet *p, u32 i, void *a);
void EVENT_COMM_COMMON_PrintMsg(Ov018Obj *p, int a);
int EVENT_COMM_COMMON_IsPrintFinished(Ov018Obj *p);
int EVENT_COMM_COMMON_IsKeyTrg(void);
void EVENT_COMM_COMMON_ExitCommonWork(u8 *v, Outer *c);
void GFL_USE_PlaySeDefaultVolume(u32 a);
void *INTRUDE_SUBDISP_CreatePalaceWarpEvent(void *);
void GAME_EVENT_ChangeEvent(struct S0201235C *o, u32 *out);

int EVENT_COMM_COMMON_TalkedGreetingAsTargetEventMain(void *a, int *state, Outer *c)
{
    void *h;
    u8 *v;

    h = GAME_EVENT_GetGameSystem(a);
    v = (u8 *)INTRUDE_COMM_GetWorkIfRunning((int)((void *)GAMESYSTEM_GetGameComm(h)));
    switch (*state) {
    case 0:
        func_0201F02C(c->obj.f00, 0, c->f78);
        EVENT_COMM_COMMON_PrintMsg(&c->obj, d_0218397A[c->f42]);
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
        if (v != 0) {
            GFL_USE_PlaySeDefaultVolume(0x737);
            GAME_EVENT_ChangeEvent(a, INTRUDE_SUBDISP_CreatePalaceWarpEvent(h));
            return 0;
        }
        return 1;
    }
    return 0;
}
