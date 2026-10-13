/*
 * function: EVENT_COMM_COMMON_MsgScriptEventMain
 * address:  0x02182AA4
 * packet:   pkt_ov018_02182AA4
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
 *   EVENT_COMM_COMMON_PrintMsg  0x0217F3C4  thumb
 *   EVENT_COMM_COMMON_IsPrintFinished  0x0217F40C  thumb
 *   EVENT_COMM_COMMON_ExitMsgBox  0x0217F318  thumb
 *   SCRIPT_SYS_CreateScriptEventSimple  0x02158768  thumb  ov010
 *   SCRIPT_SYS_GetEventScriptWork  0x021589D0  thumb  ov010
 *   SCRIPT_WORK_SetParams  0x02159058  thumb  ov010
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   EVENT_COMM_COMMON_ExitCommonWork  0x0217FE38  thumb
 *   INTRUDE_SUBDISP_CreateDisconnectEvent  0x0217CA84  thumb
 *   GAME_EVENT_ChangeEvent  0x0201235C  thumb
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
    unsigned char pad40[0x5C];
    unsigned short f9C;
} Ov018Outer;

typedef unsigned short u16;
struct Evt;
struct Obj;
struct Ctx;
void *func_020124E4(struct Obj *p);
unsigned int GAMESYSTEM_GetGameComm(const struct Ctx *p);
typedef unsigned int   u32;
struct Desc;
struct S0201235C;
int INTRUDE_COMM_GetWorkIfRunning(int a0);
void EVENT_COMM_COMMON_PrintMsg(Ov018Obj *p, int a);
int EVENT_COMM_COMMON_IsPrintFinished(Ov018Obj *p);
void EVENT_COMM_COMMON_ExitMsgBox(Ov018Obj *p);
struct Desc *SCRIPT_SYS_CreateScriptEventSimple(int a0, int a1, int a2, int a3);
int SCRIPT_SYS_GetEventScriptWork(int a0);
int SCRIPT_WORK_SetParams(int a, int b, int c, int d, u16 e);
void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
void EVENT_COMM_COMMON_ExitCommonWork(int v, Ov018Outer *c);
int INTRUDE_SUBDISP_CreateDisconnectEvent(void *a, int b);
void GAME_EVENT_ChangeEvent(struct S0201235C *o, u32 *out);

int EVENT_COMM_COMMON_MsgScriptEventMain(void *a, int *state, Ov018Outer *c)
{
    void *sub;
    int v;
    void *w;

    sub = func_020124E4(a);
    v = INTRUDE_COMM_GetWorkIfRunning((int)((void *)GAMESYSTEM_GetGameComm(sub)));
    switch (*state) {
    case 0:
        EVENT_COMM_COMMON_PrintMsg(&c->obj, c->f9C);
        (*state)++;
        break;
    case 1:
        if (EVENT_COMM_COMMON_IsPrintFinished(&c->obj) == 1) {
            (*state)++;
        }
        break;
    case 2:
        EVENT_COMM_COMMON_ExitMsgBox(&c->obj);
        w = SCRIPT_SYS_CreateScriptEventSimple((int)sub, 0xAFD, 0, 4);
        SCRIPT_WORK_SetParams(SCRIPT_SYS_GetEventScriptWork((int)w), 0x23F, 1, 0, 0);
        GAME_EVENT_CallEvent(a, w);
        (*state)++;
        break;
    case 3:
        *state = 4;
        break;
    case 4:
        EVENT_COMM_COMMON_ExitCommonWork(v, c);
        GAME_EVENT_ChangeEvent(a, (u32 *)INTRUDE_SUBDISP_CreateDisconnectEvent(sub, 0));
        return 0;
    }
    return 0;
}
