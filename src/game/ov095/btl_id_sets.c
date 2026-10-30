/*
 * file:     btl_id_sets.c
 * unit:     yes
 * function: BTL_ID_IsBatonPassSick, BTL_ID_IsInList, BTL_ID_IsEncoreFailMove, BTL_ID_IsMeFirstFailMove, BTL_ID_IsMetronomeItemIgnoredMove, BTL_ID_IsPressureNoExtraPpMove, BTL_ID_IsGemIgnoredMove, BTL_ID_IsHeldItemUseBlocked, BTL_ID_IsBagItemUseBlocked, BTL_ID_IsAbilityRolePlayBlocked, BTL_ID_IsAbilityEntrainmentBlocked, BTL_ID_IsAbilityTraceBlocked, BTL_ID_IsAbilitySkillSwapBlocked, BTL_ID_IsMultitypeAbility, BTL_ID_IsArceusPlate, BTL_ID_IsGenesectDrive, BTL_ID_IsBallWithCatchBonus, BTL_ID_IsAbilityIgnoredByMoldBreaker, BTL_ID_IsArceusSpecies, BTL_ID_IsSimpleEffectId, BTL_ID_GetItemCuredSick, BTL_ID_GetTurnCheckSick, BTL_ID_IsCallMoveExcluded, BTL_ID_IsSleepTalkExcludedMove, BTL_ID_IsAssistExcludedMove, BTL_ID_IsCopycatExcludedMove, BTL_ID_IsMimicExcludedMove, BTL_ID_GetMetronomeExcludedMoves
 * address:  0x0689C868
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from unit_0689C868.c, unit_0689C888.c by tools/splitfile.py.
 *
 * symbols:
 *   gBatonPassSickKinds 0x0689E200 data a2
 *   gEncoreFailMoves 0x0689E2DA data a2
 *   gMeFirstFailMoves 0x0689E31C data a2
 *   gMetronomeItemIgnoredMoves 0x0689E2B6 data a2
 *   gPressureNoExtraPpMoves 0x0689E2C4 data a2
 *   gGemIgnoredMoves 0x0689E2B0 data a2
 *   gHeldItemUseBlockedItems 0x0689E2F6 data a2
 *   gBagItemUseBlockedItems 0x0689E2AA data a2
 *   gRolePlayBlockedAbilities 0x0689E2E6 data a2
 *   gSkillSwapBlockedAbilities 0x0689E2A4 data a2
 *   gArceusPlateItems 0x0689E38C data a2
 *   gGenesectDriveItems 0x0689E2BC data a2
 *   gCatchBonusBalls 0x0689E308 data a2
 *   gMoldBreakerIgnoredAbilities 0x0689E450 data a2
 *   gSimpleEffectIds 0x0689E35C data a2
 *   gItemCuredSickKinds 0x0689E374 data a4
 *   gTurnCheckSickKinds 0x0689E4C0 data a4
 *   gCallMoveExcludedMoves     0x0689E330  data  ov095  a2
 *   gSleepTalkExtraExcludedMoves 0x0689E346 data a2
 *   gAssistExtraExcludedMoves 0x0689E3D4 data a2
 *   gCopycatExtraExcludedMoves     0x0689E3AC  data  ov095  a2
 *   gMimicExcludedMoves     0x0689E2CE  data  ov095  a2
 *   gMetronomeExcludedMoves     0x0689E3FC  data  ov095  a4
 */
#include "../version.h"
#include "btl_pokeparam_types.h"

#define BTL_ID_BATON_PASS_SICK_COUNT 14

extern u16 gBatonPassSickKinds[BTL_ID_BATON_PASS_SICK_COUNT];

int BTL_ID_IsBatonPassSick(unsigned sickKind)
{
    unsigned i;
    for (i = 0; i < BTL_ID_BATON_PASS_SICK_COUNT; i++) {
        if (sickKind == gBatonPassSickKinds[i]) return 1;
    }
    return 0;
}

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

extern u16 gEncoreFailMoves[6];      /* moves Encore cannot repeat */

extern u16 gMeFirstFailMoves[10];     /* moves Me First cannot copy */

extern u16 gMetronomeItemIgnoredMoves[3];      /* moves the Metronome item ignores */

extern u16 gPressureNoExtraPpMoves[5];      /* moves Pressure does not charge extra PP for */

extern u16 gGemIgnoredMoves[3];      /* moves gems and redirection ignore */

extern u16 gHeldItemUseBlockedItems[9];      /* items a held-item effect cannot use */

extern u16 gBagItemUseBlockedItems[3];      /* items the bag cannot use in battle */

extern u16 gRolePlayBlockedAbilities[8];      /* abilities Role Play cannot copy */

extern u16 gSkillSwapBlockedAbilities[3];      /* abilities Skill Swap cannot move */

extern u16 gArceusPlateItems[16];     /* Arceus plates */

extern u16 gGenesectDriveItems[4];      /* Genesect drives */

#define CATCH_BONUS_BALL_COUNT PM_LANG_JA(10, 11)

extern u16 gCatchBonusBalls[CATCH_BONUS_BALL_COUNT];     /* balls with a catch bonus */

extern u16 gMoldBreakerIgnoredAbilities[55];     /* abilities Mold Breaker ignores */

extern u16 gSimpleEffectIds[12];     /* simple effect ids */

extern const u32 gItemCuredSickKinds[6];      /* conditions an item cures */

extern const u32 gTurnCheckSickKinds[0x23];   /* conditions checked at the end of a turn */

extern u16 gCallMoveExcludedMoves[11];     /* moves no call-a-move move can pick */

extern u16 gSleepTalkExtraExcludedMoves[11];     /* extra moves Sleep Talk cannot pick */

extern u16 gAssistExtraExcludedMoves[20];     /* extra moves Assist cannot pick */

extern u16 gCopycatExtraExcludedMoves[20];     /* extra moves Copycat cannot pick */

extern u16 gMimicExcludedMoves[6];      /* moves Mimic cannot copy */

extern int gMetronomeExcludedMoves[0x29];   /* moves Metronome cannot pick */

int BTL_ID_IsInList(unsigned id, const u16 *list, unsigned count)
{
    unsigned i;
    for (i = 0; i < count; i++) {
        if (id == list[i])
            return 1;
    }
    return 0;
}

int BTL_ID_IsEncoreFailMove(unsigned moveId)
{
    return BTL_ID_IsInList(moveId, gEncoreFailMoves, 6);
}

int BTL_ID_IsMeFirstFailMove(unsigned moveId)
{
    return BTL_ID_IsInList(moveId, gMeFirstFailMoves, 10);
}

int BTL_ID_IsMetronomeItemIgnoredMove(unsigned moveId)
{
    return BTL_ID_IsInList(moveId, gMetronomeItemIgnoredMoves, 3);
}

int BTL_ID_IsPressureNoExtraPpMove(unsigned moveId)
{
    return BTL_ID_IsInList(moveId, gPressureNoExtraPpMoves, 5);
}

int BTL_ID_IsGemIgnoredMove(unsigned moveId)
{
    return BTL_ID_IsInList(moveId, gGemIgnoredMoves, 3);
}

int BTL_ID_IsHeldItemUseBlocked(unsigned itemId)
{
    return BTL_ID_IsInList(itemId, gHeldItemUseBlockedItems, 9);
}

int BTL_ID_IsBagItemUseBlocked(unsigned itemId)
{
    return BTL_ID_IsInList(itemId, gBagItemUseBlockedItems, 3);
}

int BTL_ID_IsAbilityRolePlayBlocked(unsigned abilityId)
{
    if (BTL_ID_IsMultitypeAbility(abilityId)) return 1;
    return BTL_ID_IsInList(abilityId, gRolePlayBlockedAbilities, 8);
}

int BTL_ID_IsAbilityEntrainmentBlocked(unsigned abilityId) { return BTL_ID_IsAbilityTraceBlocked(abilityId); }

int BTL_ID_IsAbilityTraceBlocked(unsigned abilityId)
{
    if (abilityId == 25) return 0;
    return BTL_ID_IsAbilityRolePlayBlocked(abilityId);
}

int BTL_ID_IsAbilitySkillSwapBlocked(unsigned abilityId)
{
    if (BTL_ID_IsMultitypeAbility(abilityId)) return 1;
    return BTL_ID_IsInList(abilityId, gSkillSwapBlockedAbilities, 3);
}

int BTL_ID_IsMultitypeAbility(int abilityId)
{
    return abilityId == 0x79;
}

int BTL_ID_IsArceusPlate(unsigned itemId)
{
    return BTL_ID_IsInList(itemId, gArceusPlateItems, 16);
}

int BTL_ID_IsGenesectDrive(unsigned itemId)
{
    return BTL_ID_IsInList(itemId, gGenesectDriveItems, 4);
}

int BTL_ID_IsBallWithCatchBonus(unsigned itemId)
{
    return BTL_ID_IsInList(itemId, gCatchBonusBalls, CATCH_BONUS_BALL_COUNT);
}

int BTL_ID_IsAbilityIgnoredByMoldBreaker(unsigned abilityId)
{
    return BTL_ID_IsInList(abilityId, gMoldBreakerIgnoredAbilities, 55);
}

int BTL_ID_IsArceusSpecies(unsigned speciesId)
{
    return speciesId == 0x1ed;
}

int BTL_ID_IsSimpleEffectId(unsigned effectId)
{
    return BTL_ID_IsInList(effectId, gSimpleEffectIds, 12);
}

unsigned int BTL_ID_GetItemCuredSick(unsigned index)
{
    if (index < 6) return gItemCuredSickKinds[index];
    return 0;
}

unsigned int BTL_ID_GetTurnCheckSick(unsigned index)
{
    if (index < 0x23) return gTurnCheckSickKinds[index];
    return 0;
}

int BTL_ID_IsCallMoveExcluded(unsigned moveId)
{
    return BTL_ID_IsInList(moveId, gCallMoveExcludedMoves, 0xb);
}

int BTL_ID_IsSleepTalkExcludedMove(unsigned moveId)
{
    if (BTL_ID_IsCallMoveExcluded(moveId)) return 1;
    return BTL_ID_IsInList(moveId, gSleepTalkExtraExcludedMoves, 11);
}

int BTL_ID_IsAssistExcludedMove(unsigned moveId)
{
    if (BTL_ID_IsCallMoveExcluded(moveId))
        return 1;
    return BTL_ID_IsInList(moveId, gAssistExtraExcludedMoves, 20);
}

int BTL_ID_IsCopycatExcludedMove(unsigned moveId)
{
    if (BTL_ID_IsCallMoveExcluded(moveId))
        return 1;
    return BTL_ID_IsInList(moveId, gCopycatExtraExcludedMoves, 0x14);
}

int BTL_ID_IsMimicExcludedMove(unsigned moveId)
{
    return BTL_ID_IsInList(moveId, gMimicExcludedMoves, 6);
}

int *BTL_ID_GetMetronomeExcludedMoves(int *count)
{
    *count = 0x29;
    return gMetronomeExcludedMoves;
}
