#ifndef GAME_OV012_UNION_MAIN_H
#define GAME_OV012_UNION_MAIN_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of union_main.c, prototypes copied from their definitions. */

struct GameSystem;
struct GameComm;

#include "../ov012/union_comm_types.h"
#include "../types.h"

void UNION_MAIN_StartComm(struct GameSystem *gameSystem);
void UNION_MAIN_UpdateField(struct GameComm *gameComm, void *fieldMap);
int UNION_MAIN_IsFieldReady(UnionRoomWork *work);
void UNION_MAIN_FieldCreateCallback(void *gameSystem, UnionRoomWork *work, void *fieldMap);
void UNION_MAIN_FieldDeleteCallback(void *gameSystem, UnionRoomWork *work);
int UNION_MAIN_GetFieldRequest(UnionRoomWork *work);
int UNION_MAIN_IsExitStarted(UnionRoomWork *work);
void UNION_MAIN_SetAppealNo(UnionRoomWork *work, int appealNo);
u8 UNION_MAIN_GetAppealNo(UnionRoomWork *work);
int UNION_MAIN_IsIdle(struct GameSystem *gameSystem);
/* END mkheaders: generated region */

#endif
