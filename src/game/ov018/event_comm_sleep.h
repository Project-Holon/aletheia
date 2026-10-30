#ifndef GAME_OV018_EVENT_COMM_SLEEP_H
#define GAME_OV018_EVENT_COMM_SLEEP_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of event_comm_sleep.c, prototypes copied from their definitions. */

struct GameSystem;
struct ScriptWork;
struct GameEvent;
struct FieldMap;
struct FldMmdl;

#include "../ov018/event_comm_common_types.h"
#include "../types.h"
#include "../ov011/intrude_comm_types.h"
#include "../arm9/script_vm_types.h"

void EVENT_COMM_COMMON_StartMsgScriptEvent(struct GameEvent *event, EventCommCommonWork *src);
int EVENT_COMM_COMMON_MsgScriptEventMain(struct GameEvent *event, int *seq, void *eventWork);
/* END mkheaders: generated region */

#endif
