#ifndef GAME_OV021_SCRCMD_SUB_PROC_EVENTS_H
#define GAME_OV021_SCRCMD_SUB_PROC_EVENTS_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of scrcmd_sub_proc_events.c, prototypes copied from their definitions. */

struct GameEvent;
struct NameInEventWork;
struct NicknameEventWork;
struct SubProcEventWork;
typedef struct NameInEventWork NameInEventWork;
typedef struct NicknameEventWork NicknameEventWork;
typedef struct SubProcEventWork SubProcEventWork;

#include "../ov010/namein_args.h"
#include "../types.h"

void *SCRCMD_CreateNameInEvent(void *gameSystem, void *fieldMap, NameInArgs *nameIn, u32 mode);
int SCRCMD_NameInEventMain(struct GameEvent *event, int *state, void *work);
struct GameEvent *SCRCMD_CreateNicknameEvent(void *gameSystem, u16 *result, int partyIndex, int mode);
int SCRCMD_NicknameEventMain(struct GameEvent *event, int *state, NicknameEventWork *work);
void *SCRCMD_CreateSubProcEvent(void *gameSystem, u32 procId, u16 *result);
int SCRCMD_SubProcEventMain(struct GameEvent *event, int *state, void *work);
/* END mkheaders: generated region */

#endif
