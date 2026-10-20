#ifndef GAME_OV095_BTL_ID_SETS_H
#define GAME_OV095_BTL_ID_SETS_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of btl_id_sets.c, prototypes copied from their definitions. */

#include "../types.h"

int BTL_ID_IsBatonPassSick(unsigned sickKind);
int BTL_ID_IsInList(unsigned id, const u16 *list, unsigned count);
int BTL_ID_IsEncoreFailMove(unsigned moveId);
int BTL_ID_IsMeFirstFailMove(unsigned moveId);
int BTL_ID_IsMetronomeItemIgnoredMove(unsigned moveId);
int BTL_ID_IsPressureNoExtraPpMove(unsigned moveId);
int BTL_ID_IsGemIgnoredMove(unsigned moveId);
int BTL_ID_IsHeldItemUseBlocked(unsigned itemId);
int BTL_ID_IsBagItemUseBlocked(unsigned itemId);
int BTL_ID_IsAbilityRolePlayBlocked(unsigned abilityId);
int BTL_ID_IsAbilityEntrainmentBlocked(unsigned abilityId);
int BTL_ID_IsAbilityTraceBlocked(unsigned abilityId);
int BTL_ID_IsAbilitySkillSwapBlocked(unsigned abilityId);
int BTL_ID_IsMultitypeAbility(int abilityId);
int BTL_ID_IsArceusPlate(unsigned itemId);
int BTL_ID_IsGenesectDrive(unsigned itemId);
int BTL_ID_IsBallWithCatchBonus(unsigned itemId);
int BTL_ID_IsAbilityIgnoredByMoldBreaker(unsigned abilityId);
int BTL_ID_IsArceusSpecies(unsigned speciesId);
int BTL_ID_IsSimpleEffectId(unsigned effectId);
unsigned int BTL_ID_GetItemCuredSick(unsigned index);
unsigned int BTL_ID_GetTurnCheckSick(unsigned index);
int BTL_ID_IsCallMoveExcluded(unsigned moveId);
int BTL_ID_IsSleepTalkExcludedMove(unsigned moveId);
int BTL_ID_IsAssistExcludedMove(unsigned moveId);
int BTL_ID_IsCopycatExcludedMove(unsigned moveId);
int BTL_ID_IsMimicExcludedMove(unsigned moveId);
int *BTL_ID_GetMetronomeExcludedMoves(int *count);
/* END mkheaders: generated region */

#endif
