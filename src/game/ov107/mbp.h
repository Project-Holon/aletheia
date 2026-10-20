#ifndef GAME_OV107_MBP_H
#define GAME_OV107_MBP_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of mbp.c, prototypes copied from their definitions. */

#include "../ov107/mb_comm_sys.h"
#include "../types.h"
#include "../ov107/mb_comm_shared_types.h"

void MB_PARENT_SYS_Init(int a, int b);
void MB_PARENT_SYS_Register(MbRegistryBlock *registry, int channel);
int MB_PARENT_SYS_LoadFileImage(MbRegistryBlock *registry);
void MB_PARENT_SYS_AcceptRequest(u16 aid);
void MB_PARENT_SYS_RejectRequest(u16 aid);
void MB_PARENT_SYS_StartSending(u16 aid);
int MB_PARENT_SYS_AllBootable(void);
void MB_PARENT_SYS_StartBoot(void);
void MB_PARENT_SYS_Cancel(void);
void MB_PARENT_SYS_EndIfAllBootable(void);
void MB_PARENT_SYS_EventCallback(u16 aid, u32 event, MbChildEvent *info);
void MB_PARENT_SYS_SetState(u16 state);
u16 MB_PARENT_SYS_GetState(void);
int MB_PARENT_SYS_GetChildStage(u16 aid);
void MB_PARENT_SYS_FreeBuffers(void);
u32 MB_PARENT_SYS_IsRegistered(void);
/* END mkheaders: generated region */

#endif
