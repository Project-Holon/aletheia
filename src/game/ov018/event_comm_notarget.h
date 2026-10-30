#ifndef GAME_OV018_EVENT_COMM_NOTARGET_H
#define GAME_OV018_EVENT_COMM_NOTARGET_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of event_comm_notarget.c, prototypes copied from their definitions. */

struct GameSystem;
struct ScriptWork;
struct GameEvent;
struct FieldMap;
struct FldMmdl;

#include "../ov018/event_comm_common_types.h"
#include "../types.h"
#include "../ov011/intrude_comm_types.h"
#include "../arm9/script_vm_types.h"

void EVENT_COMM_COMMON_StartMsgEvent(struct GameEvent *event, EventCommCommonWork *src, u16 *msgIds);
int EVENT_COMM_COMMON_MsgEventMain(struct GameEvent *event, int *seq, void *eventWork);
void EVENT_COMM_COMMON_StartMsgEvent95(struct GameEvent *event, EventCommCommonWork *src);
void EVENT_COMM_COMMON_StartMsgEvent105(struct GameEvent *event, EventCommCommonWork *src);
void EVENT_COMM_COMMON_StartMsgEvent110ByKindA(struct GameEvent *event, EventCommCommonWork *src);
void EVENT_COMM_COMMON_StartMsgEvent110ByKindB(struct GameEvent *event, EventCommCommonWork *src);
void EVENT_COMM_COMMON_StartMsgEvent110(struct GameEvent *event, EventCommCommonWork *src);
void EVENT_COMM_COMMON_StartMsgEvent110Alt(struct GameEvent *event, EventCommCommonWork *src);
/* END mkheaders: generated region */

#endif
