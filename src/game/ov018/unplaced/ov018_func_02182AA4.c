/*
 * function: func_02182AA4
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
 *   func_02012138  0x02012138  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_0217F3C4  0x0217F3C4  thumb
 *   func_0217F40C  0x0217F40C  thumb
 *   func_0217F318  0x0217F318  thumb
 *   func_02158768  0x02158768  thumb  ov010
 *   func_021589D0  0x021589D0  thumb  ov010
 *   func_02159058  0x02159058  thumb  ov010
 *   func_02012374  0x02012374  thumb
 *   func_0217FE38  0x0217FE38  thumb
 *   func_0217CA84  0x0217CA84  thumb
 *   func_0201235C  0x0201235C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

#include "../../ov011/intrude_comm_types.h"
#include "../unit_021828B8_types.h"

struct GameSystem;
struct GameComm;
struct ScriptEvent;

extern struct GameSystem *func_020124E4(struct GameEvent *event);
extern struct GameComm *func_02012138(struct GameSystem *gameSystem);
extern IntrudeCommSys *func_02158344(struct GameComm *gameComm);
void func_0217F3C4(EventCommMsgBox *msgBox, int msgId);
int func_0217F40C(EventCommMsgBox *msgBox);
void func_0217F318(EventCommMsgBox *msgBox);
struct ScriptEvent *func_02158768(struct GameSystem *gameSystem, int scriptId, int targetId, int kind);
void *func_021589D0(struct ScriptEvent *scriptEvent);
int func_02159058(void *scriptWork, int var8000, int var8001, int var8002, u16 var8003);
void func_02012374(struct GameEvent *event, struct ScriptEvent *callEvent);
void func_0217FE38(IntrudeCommSys *sys, EventCommMsgWork *work);
struct GameEvent *func_0217CA84(struct GameSystem *gameSystem, int a);
void func_0201235C(struct GameEvent *event, struct GameEvent *nextEvent);

/*
 * Event callback of the script variant of the message event (work set by
 * func_02182A08): print the message, wait for the print to end, run the
 * script event 0xAFD with the work variables set, close the box and change
 * to the event that func_0217CA84 returns.
 */
int func_02182AA4(struct GameEvent *event, int *seq, void *eventWork)
{
    EventCommMsgWork *work = eventWork;
    struct GameSystem *gameSystem;
    IntrudeCommSys *sys;
    struct ScriptEvent *scriptEvent;

    gameSystem = func_020124E4(event);
    sys = func_02158344(func_02012138(gameSystem));
    switch (*seq) {
    case 0:
        func_0217F3C4(&work->msgBox, work->msgId);
        (*seq)++;
        break;
    case 1:
        if (func_0217F40C(&work->msgBox) == 1) {
            (*seq)++;
        }
        break;
    case 2:
        func_0217F318(&work->msgBox);
        scriptEvent = func_02158768(gameSystem, 0xAFD, 0, 4);
        func_02159058(func_021589D0(scriptEvent), 0x23F, 1, 0, 0);
        func_02012374(event, scriptEvent);
        (*seq)++;
        break;
    case 3:
        *seq = 4;
        break;
    case 4:
        func_0217FE38(sys, work);
        func_0201235C(event, func_0217CA84(gameSystem, 0));
        return 0;
    }
    return 0;
}
