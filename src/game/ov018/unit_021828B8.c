/*
 * file:     unit_021828B8.c
 * unit:     yes
 * function: func_021828B8, func_02182920, func_02182988, func_02182998, func_021829A8, func_021829C8, func_021829F8, func_02182A08
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
 *   func_020124E4  0x020124E4  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_0201232C  0x0201232C  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02082D44  0x02082D44  arm
 *   func_0201F02C  0x0201F02C  thumb
 *   func_02034714  0x02034714  arm
 *   sEmptyTextA     0x02183B4C  data   a1
 *   func_0217F3C4  0x0217F3C4  thumb  ov018
 *   func_0217F40C  0x0217F40C  thumb  ov018
 *   func_0217F420  0x0217F420  thumb  ov018
 *   func_0217FE38  0x0217FE38  thumb  ov018
 *   sMsgIds95     0x02183A20  data   a2
 *   sMsgIds105     0x02183A38  data   a2
 *   sMsgIds110ByKindA 0x02183A80 data a2
 *   sMsgIds110ByKindB 0x02183A44 data a2
 *   sMsgIds110 0x02183A2C data a2
 *   sMsgIds110Alt 0x02183A14 data a2
 *   func_02182AA4  0x02182AA4  thumb  ov018
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

extern struct GameSystem *func_020124E4(struct GameEvent *event);
extern struct GameComm *func_02012138(struct GameSystem *gameSystem);
extern IntrudeCommSys *func_02158344(struct GameComm *gameComm);
extern void func_0201232C(struct GameEvent *event, GameEventFunc func, int workSize);
extern EventCommMsgWork *func_020124E8(struct GameEvent *event);
extern void func_02082D44(const void *src, void *dst, int size);
extern void func_0201F02C(struct WordSet *wordSet, u32 index, void *myStatus);
extern void func_02034714(const char *expr, u32 line, const char *file);
void func_0217F3C4(EventCommMsgBox *msgBox, int msgId);
int func_0217F40C(EventCommMsgBox *msgBox);
int func_0217F420(void);
void func_0217FE38(IntrudeCommSys *sys, EventCommMsgWork *work);
extern int func_02182AA4(struct GameEvent *event, int *seq, void *work);
void func_021828B8(struct GameEvent *event, EventCommMsgWork *src, u16 *msgIds);
int func_02182920(struct GameEvent *event, int *seq, void *work);
void func_02182988(struct GameEvent *event, EventCommMsgWork *src);
void func_02182998(struct GameEvent *event, EventCommMsgWork *src);
void func_021829A8(struct GameEvent *event, EventCommMsgWork *src);
void func_021829C8(struct GameEvent *event, EventCommMsgWork *src);
void func_021829E8(struct GameEvent *event, EventCommMsgWork *src);
void func_021829F8(struct GameEvent *event, EventCommMsgWork *src);
void func_02182A08(struct GameEvent *event, EventCommMsgWork *src);
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
void func_021828B8(struct GameEvent *event, EventCommMsgWork *src, u16 *msgIds)
{
    IntrudeCommSys *sys;
    EventCommMsgWork *work;

    sys = func_02158344(func_02012138(func_020124E4(event)));
    func_0201232C(event, func_02182920, 0xAC);
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
 * Event callback of the message event, in the shape of func_021809A4: print
 * the message, wait for the print to end, wait for a key press, then close
 * the box and end the event.
 */
int func_02182920(struct GameEvent *event, int *seq, void *eventWork)
{
    IntrudeCommSys *sys;
    EventCommMsgWork *work = eventWork;

    sys = func_02158344(func_02012138(func_020124E4(event)));
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
        if (func_0217F420() == 1) {
            *seq = 3;
        }
        break;
    case 3:
        func_0217FE38(sys, work);
        return 1;
    }
    return 0;
}



/*
 * Leaf (no lr save): tail call to func_021828B8 with the message IDs 95 to 99.
 */
void func_02182988(struct GameEvent *event, EventCommMsgWork *src)
{
    func_021828B8(event, src, sMsgIds95);
}



/*
 * Leaf (no lr save): tail call to func_021828B8 with the message IDs 105 to 109.
 */
void func_02182998(struct GameEvent *event, EventCommMsgWork *src)
{
    func_021828B8(event, src, sMsgIds105);
}


/* Message IDs 110 to 114; the table row is the request kind (all rows hold the same IDs). */
void func_021829A8(struct GameEvent *event, EventCommMsgWork *src)
{
    int kind;

    kind = src->member.head.kind;
    if (kind >= 6) kind = 0;
    func_021828B8(event, src, sMsgIds110ByKindA[kind]);
}


/* Same as func_021829A8 with a second copy of the table. */
void func_021829C8(struct GameEvent *event, EventCommMsgWork *src)
{
    int kind;

    kind = src->member.head.kind;
    if (kind >= 6) kind = 0;
    func_021828B8(event, src, sMsgIds110ByKindB[kind]);
}


void func_021829E8(struct GameEvent *event, EventCommMsgWork *src) { func_021828B8(event, src, sMsgIds110); }


void func_021829F8(struct GameEvent *event, EventCommMsgWork *src) { func_021828B8(event, src, sMsgIds110Alt); }



/*
 * Like func_021828B8 for the script variant (event work 0xA0 bytes, message
 * IDs 125 to 129). It also stores the opposite facing of the local player
 * in the package of the peer: 0 and 1 swap, 2 and 3 swap.
 */
void func_02182A08(struct GameEvent *event, EventCommMsgWork *src)
{
    IntrudeCommSys *sys;
    EventCommMsgWork *work;
    int facing;

    sys = func_02158344(func_02012138(func_020124E4(event)));
    func_0201232C(event, func_02182AA4, 0xA0);
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
