/*
 * function: EVENT_COMM_COMMON_SupportMsgEventMain
 * address:  0x02181DD4
 * packet:   pkt_ov018_02181DD4
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   WORDSET_SetSlotMyStatus  0x0201F02C  thumb
 *   EVENT_COMM_COMMON_PrintMsg  0x0217F3C4  thumb
 *   EVENT_COMM_COMMON_IsPrintFinished  0x0217F40C  thumb
 *   EVENT_COMM_COMMON_ExitMsgBox  0x0217F318  thumb
 *   SCRIPT_SYS_CreateScriptEventSimple  0x02158768  thumb  ov010
 *   SCRIPT_SYS_GetEventScriptWork  0x021589D0  thumb  ov010
 *   SCRIPT_WORK_SetParams  0x02159058  thumb  ov010
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   func_020307B0  0x020307B0  arm
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
    void *f30;
} Ov018Obj;

typedef unsigned short u16;
typedef unsigned int   u32;
struct Evt;
struct Obj;
struct WordSet;
void *GAME_EVENT_GetGameSystem(struct Obj *p);
void WORDSET_SetSlotMyStatus(struct WordSet *p, u32 i, void *a);
void EVENT_COMM_COMMON_PrintMsg(Ov018Obj *p, int a);
int EVENT_COMM_COMMON_IsPrintFinished(Ov018Obj *p);
void EVENT_COMM_COMMON_ExitMsgBox(Ov018Obj *p);
struct Desc;
struct Desc *SCRIPT_SYS_CreateScriptEventSimple(int a0, int a1, int a2, int a3);
int SCRIPT_SYS_GetEventScriptWork(int a0);
int SCRIPT_WORK_SetParams(int a, int b, int c, int d, u16 e);
void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
u32 func_020307B0(void *p);

int EVENT_COMM_COMMON_SupportMsgEventMain(void *a, int *state, Ov018Obj *c)
{
    void *sub;
    void *w;

    sub = GAME_EVENT_GetGameSystem(a);
    switch (*state) {
    case 0:
        WORDSET_SetSlotMyStatus(c->f00, 0, c->f30);
        EVENT_COMM_COMMON_PrintMsg(c, 0x1C);
        (*state)++;
        break;
    case 1:
        if (EVENT_COMM_COMMON_IsPrintFinished(c) == 1) {
            (*state)++;
        }
        break;
    case 2:
        EVENT_COMM_COMMON_ExitMsgBox(c);
        w = SCRIPT_SYS_CreateScriptEventSimple((int)sub, 0xAFD, 0, 4);
        SCRIPT_WORK_SetParams(SCRIPT_SYS_GetEventScriptWork((int)w), 0x1C, 1, 0, 0);
        GAME_EVENT_CallEvent(a, w);
        (*state)++;
        break;
    case 3:
        *state = 4;
        break;
    case 4:
        func_020307B0(c->f30);
        return 1;
    }
    return 0;
}
