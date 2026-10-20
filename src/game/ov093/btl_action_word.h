#ifndef GAME_OV093_BTL_ACTION_WORD_H
#define GAME_OV093_BTL_ACTION_WORD_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of btl_action_word.c, prototypes copied from their definitions. */

union BtlAction;

#include "../types.h"

void BTL_ACTION_SetFight(union BtlAction *action, u32 moveId, u32 targetPos);
void BTL_ACTION_SetFightTarget(union BtlAction *action, int targetPos);
void BTL_ACTION_SetFightSlotFlag(union BtlAction *action);
u32 BTL_ACTION_GetFightSlotFlag(const union BtlAction *action);
u32 BTL_ACTION_GetFightMove(const union BtlAction *action);
void BTL_ACTION_SetItem(union BtlAction *action,u32 itemId,u32 targetIndex,u32 itemParam);
void BTL_ACTION_SetChange(union BtlAction *action,u32 posIndex,u32 memberIndex);
void BTL_ACTION_SetChangeDepleted(union BtlAction *action);
int BTL_ACTION_IsChangeDepleted(const union BtlAction *action);
void BTL_ACTION_SetRotate(union BtlAction *action,u32 direction);
void BTL_ACTION_SetEscape(union BtlAction *action);
void BTL_ACTION_SetSkip(union BtlAction *action);
void BTL_ACTION_SetNone(union BtlAction *action);
void BTL_ACTION_SetForcedSkip(union BtlAction *action);
unsigned int BTL_ACTION_GetKind(const union BtlAction *action);
void BTL_ACTION_SetRecordReset(u32 *action);
void BTL_ACTION_SetRecordError(u32 *action);
/* END mkheaders: generated region */

#endif
