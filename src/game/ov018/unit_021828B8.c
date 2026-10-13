/*
 * file:     unit_021828B8.c
 * unit:     yes
 * function: EVENT_COMM_COMMON_StartMsgEvent, EVENT_COMM_COMMON_MsgEventMain, EVENT_COMM_COMMON_StartMsgEvent95, EVENT_COMM_COMMON_StartMsgEvent105, EVENT_COMM_COMMON_StartMsgEvent110ByKindA, EVENT_COMM_COMMON_StartMsgEvent110ByKindB, EVENT_COMM_COMMON_StartMsgEvent110Alt, EVENT_COMM_COMMON_StartMsgScriptEvent
 * address:  0x021828B8
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb  ov010
 *   GAME_EVENT_Change  0x0201232C  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02082D44  0x02082D44  arm
 *   func_0201F02C  0x0201F02C  thumb
 *   func_02034714  0x02034714  arm
 *   sEmptyTextA     0x02183B4C  data   a1
 *   EVENT_COMM_COMMON_PrintMsg  0x0217F3C4  thumb  ov018
 *   EVENT_COMM_COMMON_IsPrintFinished  0x0217F40C  thumb  ov018
 *   EVENT_COMM_COMMON_IsKeyTrg  0x0217F420  thumb  ov018
 *   EVENT_COMM_COMMON_ExitCommonWork  0x0217FE38  thumb  ov018
 *   sMsgIds95     0x02183A20  data   a2
 *   sMsgIds105     0x02183A38  data   a2
 *   sMsgIds110ByKindA 0x02183A80 data a2
 *   sMsgIds110ByKindB 0x02183A44 data a2
 *   sMsgIds110 0x02183A2C data a2
 *   sMsgIds110Alt 0x02183A14 data a2
 *   EVENT_COMM_COMMON_MsgScriptEventMain  0x02182AA4  thumb  ov018
 *   sEmptyTextB     0x02183B50  data   a1
 *   sMsgIds125     0x02183ABC  data   a2
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

#include "../ov011/intrude_comm_types.h"
#include "unit_021828B8_types.h"

struct WordSet;
struct GameSystem;
struct GameComm;

typedef int (*GameEventFunc)(struct GameEvent *event, int *seq, void *work);

extern struct GameSystem *GAME_EVENT_GetGameSystem(struct GameEvent *event);
extern struct GameComm *GAMESYSTEM_GetGameComm(struct GameSystem *gameSystem);
extern IntrudeCommSys *INTRUDE_COMM_GetWorkIfRunning(struct GameComm *gameComm);
extern void GAME_EVENT_Change(struct GameEvent *event, GameEventFunc func, int workSize);
extern EventCommMsgWork *func_020124E8(struct GameEvent *event);
extern void func_02082D44(const void *src, void *dst, int size);
extern void func_0201F02C(struct WordSet *wordSet, u32 index, void *myStatus);
extern void func_02034714(const char *expr, u32 line, const char *file);
void EVENT_COMM_COMMON_PrintMsg(EventCommMsgBox *msgBox, int msgId);
int EVENT_COMM_COMMON_IsPrintFinished(EventCommMsgBox *msgBox);
int EVENT_COMM_COMMON_IsKeyTrg(void);
void EVENT_COMM_COMMON_ExitCommonWork(IntrudeCommSys *sys, EventCommMsgWork *work);
extern int EVENT_COMM_COMMON_MsgScriptEventMain(struct GameEvent *event, int *seq, void *work);
void EVENT_COMM_COMMON_StartMsgEvent(struct GameEvent *event, EventCommMsgWork *src, u16 *msgIds);
int EVENT_COMM_COMMON_MsgEventMain(struct GameEvent *event, int *seq, void *work);
void EVENT_COMM_COMMON_StartMsgEvent95(struct GameEvent *event, EventCommMsgWork *src);
void EVENT_COMM_COMMON_StartMsgEvent105(struct GameEvent *event, EventCommMsgWork *src);
void EVENT_COMM_COMMON_StartMsgEvent110ByKindA(struct GameEvent *event, EventCommMsgWork *src);
void EVENT_COMM_COMMON_StartMsgEvent110ByKindB(struct GameEvent *event, EventCommMsgWork *src);
void EVENT_COMM_COMMON_StartMsgEvent110(struct GameEvent *event, EventCommMsgWork *src);
void EVENT_COMM_COMMON_StartMsgEvent110Alt(struct GameEvent *event, EventCommMsgWork *src);
void EVENT_COMM_COMMON_StartMsgScriptEvent(struct GameEvent *event, EventCommMsgWork *src);
extern const char sEmptyTextA[];
extern u16 sMsgIds95[];
extern u16 sMsgIds105[];
extern u16 sMsgIds110ByKindA[][5];
extern u16 sMsgIds110ByKindB[][5];
extern u16 sMsgIds110[];
extern u16 sMsgIds110Alt[];
extern const char sEmptyTextB[];
extern u16 sMsgIds125[];



/*
 * Turns the running event into the message event: the event work is
 * 0xAC bytes, takes the 0x98-byte block of the caller and shows the message
 * msgIds[msgIndex] with the player name in word slot 0.
 */
void EVENT_COMM_COMMON_StartMsgEvent(struct GameEvent *event, EventCommMsgWork *src, u16 *msgIds)
{
    IntrudeCommSys *sys;
    EventCommMsgWork *work;

    sys = INTRUDE_COMM_GetWorkIfRunning(GAMESYSTEM_GetGameComm(GAME_EVENT_GetGameSystem(event)));
    GAME_EVENT_Change(event, EVENT_COMM_COMMON_MsgEventMain, 0xAC);
    work = func_020124E8(event);
    func_02082D44(src, work, 0x98);
    if (sys != 0) {
        work->msgId = msgIds[src->msgIndex];
        func_0201F02C(src->msgBox.wordSet, 0, src->myStatus);
    } else {
        func_02034714(sEmptyTextA, 0, sEmptyTextA);
    }
}



/*
 * Event callback of the message event, in the shape of EVENT_COMM_COMMON_TalkPowerGiftTargetEventMain: print
 * the message, wait for the print to end, wait for a key press, then close
 * the box and end the event.
 */
int EVENT_COMM_COMMON_MsgEventMain(struct GameEvent *event, int *seq, void *eventWork)
{
    IntrudeCommSys *sys;
    EventCommMsgWork *work = eventWork;

    sys = INTRUDE_COMM_GetWorkIfRunning(GAMESYSTEM_GetGameComm(GAME_EVENT_GetGameSystem(event)));
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
        if (EVENT_COMM_COMMON_IsKeyTrg() == 1) {
            *seq = 3;
        }
        break;
    case 3:
        EVENT_COMM_COMMON_ExitCommonWork(sys, work);
        return 1;
    }
    return 0;
}



/*
 * Leaf (no lr save): tail call to EVENT_COMM_COMMON_StartMsgEvent with the message IDs 95 to 99.
 */
void EVENT_COMM_COMMON_StartMsgEvent95(struct GameEvent *event, EventCommMsgWork *src)
{
    EVENT_COMM_COMMON_StartMsgEvent(event, src, sMsgIds95);
}



/*
 * Leaf (no lr save): tail call to EVENT_COMM_COMMON_StartMsgEvent with the message IDs 105 to 109.
 */
void EVENT_COMM_COMMON_StartMsgEvent105(struct GameEvent *event, EventCommMsgWork *src)
{
    EVENT_COMM_COMMON_StartMsgEvent(event, src, sMsgIds105);
}


/* Message IDs 110 to 114; the table row is the request kind (all rows hold the same IDs). */
void EVENT_COMM_COMMON_StartMsgEvent110ByKindA(struct GameEvent *event, EventCommMsgWork *src)
{
    int kind;

    kind = src->member.head.kind;
    if (kind >= 6) kind = 0;
    EVENT_COMM_COMMON_StartMsgEvent(event, src, sMsgIds110ByKindA[kind]);
}


/* Same as EVENT_COMM_COMMON_StartMsgEvent110ByKindA with a second copy of the table. */
void EVENT_COMM_COMMON_StartMsgEvent110ByKindB(struct GameEvent *event, EventCommMsgWork *src)
{
    int kind;

    kind = src->member.head.kind;
    if (kind >= 6) kind = 0;
    EVENT_COMM_COMMON_StartMsgEvent(event, src, sMsgIds110ByKindB[kind]);
}


void EVENT_COMM_COMMON_StartMsgEvent110(struct GameEvent *event, EventCommMsgWork *src) { EVENT_COMM_COMMON_StartMsgEvent(event, src, sMsgIds110); }


void EVENT_COMM_COMMON_StartMsgEvent110Alt(struct GameEvent *event, EventCommMsgWork *src) { EVENT_COMM_COMMON_StartMsgEvent(event, src, sMsgIds110Alt); }



/*
 * Like EVENT_COMM_COMMON_StartMsgEvent for the script variant (event work 0xA0 bytes, message
 * IDs 125 to 129). It also stores the opposite facing of the local player
 * in the package of the peer: 0 and 1 swap, 2 and 3 swap.
 */
void EVENT_COMM_COMMON_StartMsgScriptEvent(struct GameEvent *event, EventCommMsgWork *src)
{
    IntrudeCommSys *sys;
    EventCommMsgWork *work;
    int facing;

    sys = INTRUDE_COMM_GetWorkIfRunning(GAMESYSTEM_GetGameComm(GAME_EVENT_GetGameSystem(event)));
    GAME_EVENT_Change(event, EVENT_COMM_COMMON_MsgScriptEventMain, 0xA0);
    work = func_020124E8(event);
    func_02082D44(src, work, 0x98);
    if (sys != 0) {
        facing = 0;
        work->msgId = sMsgIds125[src->msgIndex];
        func_0201F02C(src->msgBox.wordSet, 0, src->myStatus);
    } else {
        func_02034714(sEmptyTextB, 0, sEmptyTextB);
        return;
    }
    if (sys->localPeer.package.zoneId == 2)
        facing = 3;
    else if (sys->localPeer.package.zoneId == 3)
        facing = 2;
    else if (sys->localPeer.package.zoneId != 1)
        facing = 1;
    sys->peers[work->peerSlot].package.zoneId = facing;
}
