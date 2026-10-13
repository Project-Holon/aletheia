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
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
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

extern struct GameSystem *GAME_EVENT_GetGameSystem(struct GameEvent *event);
extern struct GameComm *GAMESYSTEM_GetGameComm(struct GameSystem *gameSystem);
extern IntrudeCommSys *INTRUDE_COMM_GetWorkIfRunning(struct GameComm *gameComm);
void EVENT_COMM_COMMON_PrintMsg(EventCommMsgBox *msgBox, int msgId);
int EVENT_COMM_COMMON_IsPrintFinished(EventCommMsgBox *msgBox);
void EVENT_COMM_COMMON_ExitMsgBox(EventCommMsgBox *msgBox);
struct ScriptEvent *SCRIPT_SYS_CreateScriptEventSimple(struct GameSystem *gameSystem, int scriptId, int targetId, int kind);
void *SCRIPT_SYS_GetEventScriptWork(struct ScriptEvent *scriptEvent);
int SCRIPT_WORK_SetParams(void *scriptWork, int var8000, int var8001, int var8002, u16 var8003);
void GAME_EVENT_CallEvent(struct GameEvent *event, struct ScriptEvent *callEvent);
void EVENT_COMM_COMMON_ExitCommonWork(IntrudeCommSys *sys, EventCommMsgWork *work);
struct GameEvent *INTRUDE_SUBDISP_CreateDisconnectEvent(struct GameSystem *gameSystem, int a);
void GAME_EVENT_ChangeEvent(struct GameEvent *event, struct GameEvent *nextEvent);

/*
 * Event callback of the script variant of the message event (work set by
 * EVENT_COMM_COMMON_StartMsgScriptEvent): print the message, wait for the print to end, run the
 * script event 0xAFD with the work variables set, close the box and change
 * to the event that INTRUDE_SUBDISP_CreateDisconnectEvent returns.
 */
int EVENT_COMM_COMMON_MsgScriptEventMain(struct GameEvent *event, int *seq, void *eventWork)
{
    EventCommMsgWork *work = eventWork;
    struct GameSystem *gameSystem;
    IntrudeCommSys *sys;
    struct ScriptEvent *scriptEvent;

    gameSystem = GAME_EVENT_GetGameSystem(event);
    sys = INTRUDE_COMM_GetWorkIfRunning(GAMESYSTEM_GetGameComm(gameSystem));
    switch (*seq) {
    case 0:
        EVENT_COMM_COMMON_PrintMsg(&work->msgBox, work->msgId);
        (*seq)++;
        break;
    case 1:
        if (EVENT_COMM_COMMON_IsPrintFinished(&work->msgBox) == 1) {
            (*seq)++;
        }
        break;
    case 2:
        EVENT_COMM_COMMON_ExitMsgBox(&work->msgBox);
        scriptEvent = SCRIPT_SYS_CreateScriptEventSimple(gameSystem, 0xAFD, 0, 4);
        SCRIPT_WORK_SetParams(SCRIPT_SYS_GetEventScriptWork(scriptEvent), 0x23F, 1, 0, 0);
        GAME_EVENT_CallEvent(event, scriptEvent);
        (*seq)++;
        break;
    case 3:
        *seq = 4;
        break;
    case 4:
        EVENT_COMM_COMMON_ExitCommonWork(sys, work);
        GAME_EVENT_ChangeEvent(event, INTRUDE_SUBDISP_CreateDisconnectEvent(gameSystem, 0));
        return 0;
    }
    return 0;
}
