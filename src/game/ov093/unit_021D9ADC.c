/*
 * file:     unit_021D9ADC.c
 * unit:     yes
 * function: HAND_TOKUSEI_ShedSkinOnTurnEnd, HAND_TOKUSEI_PoisonHealOnSickDamage, HAND_TOKUSEI_ShellArmorOnCriticalCheck, HAND_TOKUSEI_AddShellArmor, HAND_TOKUSEI_SuperLuckOnCriticalCheck, HAND_TOKUSEI_AddSuperLuck, HAND_TOKUSEI_AngerPointOnDamageReaction, HAND_TOKUSEI_AddAngerPoint, HAND_TOKUSEI_PoisonPointOnDamageReaction, HAND_TOKUSEI_AddPoisonPoint, HAND_TOKUSEI_StaticOnDamageReaction, HAND_TOKUSEI_AddStatic, HAND_TOKUSEI_FlameBodyOnDamageReaction, HAND_TOKUSEI_AddFlameBody, HAND_TOKUSEI_CuteCharmOnDamageReaction, HAND_TOKUSEI_AddCuteCharm, HAND_TOKUSEI_EffectSporeOnDamageReaction, HAND_TOKUSEI_AddEffectSpore, HAND_TOKUSEI_TryAddContactSick, HAND_TOKUSEI_RoughSkinOnDamageReaction, HAND_TOKUSEI_AddRoughSkin, HAND_TOKUSEI_AftermathOnDamageReaction, HAND_TOKUSEI_AddAftermath, HAND_TOKUSEI_ForecastOnWeatherChange, HAND_TOKUSEI_AddForecast, HAND_TOKUSEI_SynchronizeOnSickAdded, HAND_TOKUSEI_AddSynchronize, HAND_TOKUSEI_MoldBreakerOnAbilityCheck, HAND_TOKUSEI_AddMoldBreaker, HAND_TOKUSEI_CloudNineOnWeatherCheck, HAND_TOKUSEI_AddCloudNine, HAND_TOKUSEI_AddTrace, HAND_TOKUSEI_TraceOnMemberIn
 * address:  0x021D9ADC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0689C944  0x0689C944  thumb
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetMajorStatusIndex  0x021D62A8  thumb  ov093
 *   BTL_CALC_RollChanceOrFlag  0x021D85C0  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   d_021F0878     0x021F0878  data   ov093  a4
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   BTL_CALC_DivideMaxHpMin1  0x021D7B74  thumb  ov093
 *   d_021F0870     0x021F0870  data   ov093  a4
 *   d_021F0860 0x021F0860 data a4
 *   func_021D5D50   0x021D5D50  thumb ov093
 *   func_021C8838   0x021C8838  thumb ov093
 *   func_021C8860   0x021C8860  thumb ov093
 *   d_021F0868     0x021F0868  data   ov093  a4
 *   d_021F0850 0x021F0850 data a4
 *   BTL_CALC_MakeDefaultSickCont 0x021D7D18 thumb ov093
 *   d_021F0848 0x021F0848 data a4
 *   d_021F0840 0x021F0840 data a4
 *   func_021C83D4  0x021C83D4  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   BTL_CALC_MakeSickContFromKind  0x021D7DC0  thumb  ov093
 *   d_021F0838     0x021F0838  data   ov093  a4
 *   BTL_CALC_Random   0x021D78AC  thumb ov093
 *   d_021F0858     0x021F0858  data   ov093  a4
 *   WAZA_TOOL_GetFlag   0x0201BEB8  thumb
 *   BTL_POKEPARAM_IsFainted   0x021D5B68  thumb ov093
 *   d_021F0830     0x021F0830  data   ov093  a4
 *   d_021F0828     0x021F0828  data   ov093  a4
 *   func_021E85F8   0x021E85F8  thumb ov093
 *   BTL_POKEPARAM_HasType   0x021D5814  thumb ov093
 *   func_021C88B4   0x021C88B4  thumb ov093
 *   BTLV_CORE_PackByteTwice   0x021E8CF0  thumb ov093
 *   d_021F0820     0x021F0820  data   ov093  a4
 *   BTLV_CORE_IsSlotKind1Index15   0x021E8A78  thumb ov093
 *   d_021F0818     0x021F0818  data   ov093  a4
 *   d_021F0810     0x021F0810  data   ov093  a4
 *   d_021F0808     0x021F0808  data   ov093  a4
 *   func_021C7D00 0x021C7D00 thumb ov093
 *   func_021C7F68 0x021C7F68 thumb ov093
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   func_021B9A24 0x021B9A24 thumb ov093
 *   func_021B9A6C 0x021B9A6C thumb ov093
 *   func_021C8010 0x021C8010 thumb ov093
 *   func_021C815C 0x021C815C thumb ov093
 *   d_021F0800     0x021F0800  data   ov093  a4
 *   d_021F07F8     0x021F07F8  data   ov093  a4
 */
#include "unit_021D9ADC_types.h"

/* Contact abilities roll this chance (percent) to affect the attacker. */
#define CONTACT_ABILITY_PERCENT 30

extern int BTL_EVENT_GetVar(int varId);
extern struct BtlPokeParam *func_021C7CF4(struct BtlServerFlow *flow, int pokeId);
extern int BTL_POKEPARAM_GetMajorStatusIndex(struct BtlPokeParam *pokeParam);
extern int BTL_CALC_RollChanceOrFlag(struct BtlServerFlow *flow, u32 percent);
extern void *func_021C88A4(struct BtlServerFlow *flow, int kind, int pokeId);
extern void func_021C88C8(struct BtlServerFlow *flow, void *record);
extern int BTL_EVENT_OverwriteVar(int varId, u32 value);
extern int BTL_CALC_DivideMaxHpMin1(struct BtlPokeParam *pokeParam, u32 divisor);
int func_021D5D50(struct BtlPokeParam *pokeParam, int rankKind);
void func_021C8838(struct HandExMessage *message, int kind, int messageId);
void func_021C8860(struct HandExMessage *message, u32 arg);
extern union SickCont BTL_CALC_MakeDefaultSickCont(int sickKind);
extern int func_021C83D4(struct BtlServerFlow *flow);
extern int func_021D59B4(struct BtlPokeParam *pokeParam, int valueId);
extern void BTL_CALC_MakeSickContFromKind(int sickKind, struct BtlPokeParam *attacker, union SickCont *out);
extern u32 BTL_CALC_Random(u32 range);
extern u32 WAZA_TOOL_GetFlag(u16 moveId, u32 bit);
extern int BTL_POKEPARAM_IsFainted(struct BtlPokeParam *pokeParam);
int func_021E85F8(int pokeId);
int BTL_POKEPARAM_HasType(struct BtlPokeParam *pokeParam, int form);
void func_021C88B4(struct BtlServerFlow *flow, int kind, int pokeId);
int BTLV_CORE_PackByteTwice(int weather);
extern int BTLV_CORE_IsSlotKind1Index15(union SickCont sickCont);
extern u16 func_021C7D00(struct BtlServerFlow *flow, int pokeId);
extern u8 func_021C7F68(struct BtlServerFlow *flow, int mask, u8 *outPokeIds);
extern int func_0689C944(u16 abilityId);
extern u8 BTL_POKEPARAM_GetPokeId(struct BtlPokeParam *pokeParam);
extern int func_021B9A24(u32 pokeIdA, u32 pokeIdB);
extern int func_021B9A6C(int mask, u32 slot);
extern int func_021C8010(struct BtlServerFlow *flow, unsigned int pokeId);
extern int func_021C815C(struct BtlServerFlow *flow);
void HAND_TOKUSEI_ShedSkinOnTurnEnd(int myHandle, struct BtlServerFlow *flow, int pokeId);
void *HAND_TOKUSEI_AddShedSkin(int *handlerCount);
void HAND_TOKUSEI_PoisonHealOnSickDamage(int myHandle, struct BtlServerFlow *flow, int pokeId);
void *HAND_TOKUSEI_AddPoisonHeal(int *handlerCount);
void HAND_TOKUSEI_ShellArmorOnCriticalCheck(int myHandle, int flow, int pokeId);
void *HAND_TOKUSEI_AddShellArmor(int *handlerCount);
void HAND_TOKUSEI_SuperLuckOnCriticalCheck(int myHandle, int flow, int pokeId);
void *HAND_TOKUSEI_AddSuperLuck(int *handlerCount);
void HAND_TOKUSEI_AngerPointOnDamageReaction(int myHandle, struct BtlServerFlow *flow, int pokeId);
void *HAND_TOKUSEI_AddAngerPoint(int *handlerCount);
void HAND_TOKUSEI_PoisonPointOnDamageReaction(int myHandle, struct BtlServerFlow *flow, int pokeId);
void *HAND_TOKUSEI_AddPoisonPoint(int *handlerCount);
void HAND_TOKUSEI_StaticOnDamageReaction(int myHandle, struct BtlServerFlow *flow, int pokeId);
void *HAND_TOKUSEI_AddStatic(int *handlerCount);
void HAND_TOKUSEI_FlameBodyOnDamageReaction(int myHandle, struct BtlServerFlow *flow, int pokeId);
void *HAND_TOKUSEI_AddFlameBody(int *handlerCount);
void HAND_TOKUSEI_CuteCharmOnDamageReaction(int myHandle, struct BtlServerFlow *flow, int pokeId);
void *HAND_TOKUSEI_AddCuteCharm(int *handlerCount);
void HAND_TOKUSEI_EffectSporeOnDamageReaction(int myHandle, struct BtlServerFlow *flow, int pokeId);
void *HAND_TOKUSEI_AddEffectSpore(int *handlerCount);
void HAND_TOKUSEI_TryAddContactSick(struct BtlServerFlow *flow, int pokeId, int sickKind, union SickCont sickCont, u8 percent);
void HAND_TOKUSEI_RoughSkinOnDamageReaction(int myHandle, struct BtlServerFlow *flow, int pokeId);
void *HAND_TOKUSEI_AddRoughSkin(int *handlerCount);
void HAND_TOKUSEI_AftermathOnDamageReaction(int myHandle, struct BtlServerFlow *flow, int pokeId);
void *HAND_TOKUSEI_AddAftermath(int *handlerCount);
void HAND_TOKUSEI_ForecastOnWeatherChange(int myHandle, struct BtlServerFlow *flow, int pokeId);
void *HAND_TOKUSEI_AddForecast(int *handlerCount);
void HAND_TOKUSEI_SynchronizeOnSickAdded(int myHandle, struct BtlServerFlow *flow, int pokeId);
void *HAND_TOKUSEI_AddSynchronize(int *handlerCount);
void HAND_TOKUSEI_MoldBreakerOnAbilityCheck(int myHandle, int flow, int pokeId);
void *HAND_TOKUSEI_AddMoldBreaker(int *handlerCount);
void HAND_TOKUSEI_CloudNineOnWeatherCheck(int myHandle, int flow, int pokeId);
void *HAND_TOKUSEI_AddCloudNine(int *handlerCount);
void *HAND_TOKUSEI_AddTrace(int *handlerCount);
void HAND_TOKUSEI_TraceOnMemberIn(int myHandle, struct BtlServerFlow *flow, int pokeId, int *work);
extern int d_021F0878[];
extern int d_021F0870[];
extern int d_021F0860[];
extern int d_021F0868[];
extern int d_021F0850[];
extern int d_021F0848[];
extern int d_021F0840[];
extern int d_021F0838[];
extern int d_021F0858[];
extern int d_021F0830[];
extern int d_021F0828[];
extern int d_021F0820[];
extern int d_021F0818[];
extern int d_021F0810[];
extern int d_021F0808[];
extern int d_021F0800[];
extern int d_021F07F8[];


/* Shed Skin: at the end of the turn, a 33% chance to cure the Pokemon's status condition. */
void HAND_TOKUSEI_ShedSkinOnTurnEnd(int myHandle, struct BtlServerFlow *flow, int pokeId)
{
    struct HandExCureSick *record;

    if (pokeId == BTL_EVENT_GetVar(HANDVAR_POKE_ID)) {
        if (BTL_POKEPARAM_GetMajorStatusIndex(func_021C7CF4(flow, pokeId))) {
            if (BTL_CALC_RollChanceOrFlag(flow, 0x21)) {
                record = func_021C88A4(flow, HANDEX_KIND_CURE_SICK, pokeId);
                record->header |= HANDEX_FLAG_SHOW_ABILITY;
                record->header |= HANDEX_FLAG_SHOW_CURE_MESSAGE;
                record->sickKind = 0x24;
                record->pokeIds[0] = pokeId;
                record->pokeCount = 1;
                func_021C88C8(flow, record);
            }
        }
    }
}


void *HAND_TOKUSEI_AddShedSkin(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F0878;
}


/* Poison Heal: while poisoned, the poison damage becomes 0 and the Pokemon recovers 1/8 of its HP. */
void HAND_TOKUSEI_PoisonHealOnSickDamage(int myHandle, struct BtlServerFlow *flow, int pokeId)
{
    struct BtlPokeParam *self;
    struct HandExRecoverHp *record;

    if (pokeId == BTL_EVENT_GetVar(HANDVAR_POKE_ID) && BTL_EVENT_GetVar(HANDVAR_SICK_ID) == BTL_SICK_POISON) {
        self = func_021C7CF4(flow, pokeId);
        BTL_EVENT_OverwriteVar(HANDVAR_SICK_DAMAGE, 0);
        record = func_021C88A4(flow, HANDEX_KIND_RECOVER_HP, pokeId);
        record->amount = BTL_CALC_DivideMaxHpMin1(self, 8);
        record->pokeId = pokeId;
        record->header |= HANDEX_FLAG_SHOW_ABILITY;
        func_021C88C8(flow, record);
    }
}


void *HAND_TOKUSEI_AddPoisonHeal(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F0870;
}


/* Shell Armor / Battle Armor: the defender takes no critical hits (sets the general flag). */
void HAND_TOKUSEI_ShellArmorOnCriticalCheck(int myHandle, int flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(HANDVAR_DEFENDER_ID))
        BTL_EVENT_OverwriteVar(HANDVAR_GENERAL_FLAG, 1);
}


void *HAND_TOKUSEI_AddShellArmor(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F0868;
}


/* Super Luck: the attacker's critical hit rank goes up by one. */
void HAND_TOKUSEI_SuperLuckOnCriticalCheck(int myHandle, int flow, int pokeId)
{
    unsigned char rank;
    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID)) {
        rank = BTL_EVENT_GetVar(HANDVAR_CRITICAL_RANK) + 1;
        BTL_EVENT_OverwriteVar(HANDVAR_CRITICAL_RANK, rank);
    }
}


void *HAND_TOKUSEI_AddSuperLuck(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F0860;
}


/* Anger Point: when the defender takes a critical hit (not through a substitute),
   its Attack rises as far as it can go. */
void HAND_TOKUSEI_AngerPointOnDamageReaction(int myHandle, struct BtlServerFlow *flow, int pokeId)
{
    struct BtlPokeParam *defender;
    struct HandExRankEffect *record;

    if (pokeId != BTL_EVENT_GetVar(HANDVAR_DEFENDER_ID))
        return;
    if (BTL_EVENT_GetVar(HANDVAR_HIT_SUBSTITUTE) != 0)
        return;
    if (BTL_EVENT_GetVar(HANDVAR_CRITICAL_HIT) == 0)
        return;
    defender = func_021C7CF4(flow, pokeId);
    if (func_021D5D50(defender, BTL_RANK_ATTACK) <= 0)
        return;
    record = func_021C88A4(flow, HANDEX_KIND_RANK_EFFECT, pokeId);
    record->rankKind = BTL_RANK_ATTACK;
    record->volume = func_021D5D50(defender, BTL_RANK_ATTACK);
    record->flagB = 1;
    record->pokeCount = 1;
    record->pokeId = pokeId;
    record->flagA = 1;
    record->header |= HANDEX_FLAG_SHOW_ABILITY;
    func_021C8838(&record->message, HANDEX_MESSAGE_SET, 0x1e1);
    func_021C8860(&record->message, pokeId);
    func_021C88C8(flow, record);
}


void *HAND_TOKUSEI_AddAngerPoint(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F0858;
}


/* Poison Point: contact may poison the attacker. */
void HAND_TOKUSEI_PoisonPointOnDamageReaction(int myHandle, struct BtlServerFlow *flow, int pokeId)
{
    union SickCont sickCont;
    sickCont = BTL_CALC_MakeDefaultSickCont(BTL_SICK_POISON);
    HAND_TOKUSEI_TryAddContactSick(flow, pokeId, BTL_SICK_POISON, sickCont, CONTACT_ABILITY_PERCENT);
}


void *HAND_TOKUSEI_AddPoisonPoint(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F0850;
}


/* Static: contact may paralyze the attacker. */
void HAND_TOKUSEI_StaticOnDamageReaction(int myHandle, struct BtlServerFlow *flow, int pokeId)
{
    union SickCont sickCont;
    sickCont = BTL_CALC_MakeDefaultSickCont(BTL_SICK_PARALYSIS);
    HAND_TOKUSEI_TryAddContactSick(flow, pokeId, BTL_SICK_PARALYSIS, sickCont, CONTACT_ABILITY_PERCENT);
}


void *HAND_TOKUSEI_AddStatic(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F0848;
}


/* Flame Body: contact may burn the attacker. */
void HAND_TOKUSEI_FlameBodyOnDamageReaction(int myHandle, struct BtlServerFlow *flow, int pokeId)
{
    union SickCont sickCont;
    sickCont = BTL_CALC_MakeDefaultSickCont(BTL_SICK_BURN);
    HAND_TOKUSEI_TryAddContactSick(flow, pokeId, BTL_SICK_BURN, sickCont, CONTACT_ABILITY_PERCENT);
}


void *HAND_TOKUSEI_AddFlameBody(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F0840;
}


/* Cute Charm: contact may infatuate the attacker when the two have opposite genders
   (neither is genderless). */
void HAND_TOKUSEI_CuteCharmOnDamageReaction(int myHandle, struct BtlServerFlow *flow, int pokeId)
{
    struct BtlPokeParam *defender;
    struct BtlPokeParam *attacker;
    u8 defenderGender;
    u8 attackerGender;
    union SickCont sickCont;

    if (pokeId == BTL_EVENT_GetVar(HANDVAR_DEFENDER_ID) && BTL_EVENT_GetVar(HANDVAR_HIT_SUBSTITUTE) == 0 && func_021C83D4(flow) == 0) {
        defender = func_021C7CF4(flow, pokeId);
        attacker = func_021C7CF4(flow, (u8)BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID));
        defenderGender = func_021D59B4(defender, BPP_VALUE_GENDER);
        attackerGender = func_021D59B4(attacker, BPP_VALUE_GENDER);
        if (defenderGender != BTL_GENDER_NONE && attackerGender != BTL_GENDER_NONE && defenderGender != attackerGender) {
            BTL_CALC_MakeSickContFromKind(BTL_SICK_INFATUATION, defender, &sickCont);
            HAND_TOKUSEI_TryAddContactSick(flow, pokeId, BTL_SICK_INFATUATION, sickCont, 0x1e);
        }
    }
}


void *HAND_TOKUSEI_AddCuteCharm(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F0838;
}


/* Effect Spore: contact may poison (about 1 in 3), paralyze or put the attacker to sleep. */
void HAND_TOKUSEI_EffectSporeOnDamageReaction(int myHandle, struct BtlServerFlow *flow, int pokeId)
{
    u32 roll;
    int sickKind;
    union SickCont sickCont;

    if (pokeId != BTL_EVENT_GetVar(HANDVAR_DEFENDER_ID))
        return;
    if (BTL_EVENT_GetVar(HANDVAR_HIT_SUBSTITUTE) != 0)
        return;
    roll = BTL_CALC_Random(0x1e);
    if (roll > 0x14) {
        sickKind = BTL_SICK_POISON;
    } else {
        sickKind = BTL_SICK_PARALYSIS;
        if (roll <= 10)
            sickKind = BTL_SICK_SLEEP;
    }
    sickCont = BTL_CALC_MakeDefaultSickCont(sickKind);
    HAND_TOKUSEI_TryAddContactSick(flow, pokeId, sickKind, sickCont, 0x1e);
}


void *HAND_TOKUSEI_AddEffectSpore(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F0830;
}


/* Shared by the contact status abilities: if the hit made contact and the percent
   roll succeeds, add the status condition to the attacker. */
void HAND_TOKUSEI_TryAddContactSick(struct BtlServerFlow *flow, int pokeId, int sickKind, union SickCont sickCont, u8 percent)
{
    struct HandExAddSick *record;

    if (pokeId != BTL_EVENT_GetVar(HANDVAR_DEFENDER_ID))
        return;
    if (BTL_EVENT_GetVar(HANDVAR_HIT_SUBSTITUTE) != 0)
        return;
    if (WAZA_TOOL_GetFlag(BTL_EVENT_GetVar(HANDVAR_MOVE_ID), 0) == 0)
        return;
    if (BTL_CALC_RollChanceOrFlag(flow, percent) == 0)
        return;
    record = func_021C88A4(flow, HANDEX_KIND_ADD_SICK, pokeId);
    record->header |= HANDEX_FLAG_SHOW_ABILITY;
    record->sickKind = sickKind;
    record->sickCont.raw = sickCont.raw;
    record->suppressMessage = 0;
    record->pokeId = BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID);
    func_021C88C8(flow, record);
}


/* Rough Skin: a contact hit damages the attacker by 1/8 of its HP. */
void HAND_TOKUSEI_RoughSkinOnDamageReaction(int myHandle, struct BtlServerFlow *flow, int pokeId)
{
    struct HandExDamage *record;
    u8 attackerId;
    struct BtlPokeParam *attacker;

    if (pokeId != BTL_EVENT_GetVar(HANDVAR_DEFENDER_ID))
        return;
    if (BTL_EVENT_GetVar(HANDVAR_HIT_SUBSTITUTE) != 0)
        return;
    if (WAZA_TOOL_GetFlag(BTL_EVENT_GetVar(HANDVAR_MOVE_ID), 0) == 0)
        return;
    attackerId = BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID);
    attacker = func_021C7CF4(flow, attackerId);
    if (BTL_POKEPARAM_IsFainted(attacker) != 0)
        return;
    record = func_021C88A4(flow, HANDEX_KIND_DAMAGE, pokeId);
    record->header |= HANDEX_FLAG_SHOW_ABILITY;
    record->pokeId = attackerId;
    record->amount = BTL_CALC_DivideMaxHpMin1(attacker, 8);
    func_021C8838(&record->message, HANDEX_MESSAGE_SET, 0x1ae);
    func_021C8860(&record->message, attackerId);
    func_021C88C8(flow, record);
}


void *HAND_TOKUSEI_AddRoughSkin(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F0828;
}


/* Aftermath: when a contact hit makes the defender faint, the attacker takes 1/4 of its HP as damage. */
void HAND_TOKUSEI_AftermathOnDamageReaction(int myHandle, struct BtlServerFlow *flow, int pokeId)
{
    struct HandExDamage *record;
    u8 attackerId;
    struct BtlPokeParam *attacker;

    if (pokeId != BTL_EVENT_GetVar(HANDVAR_DEFENDER_ID))
        return;
    if (BTL_POKEPARAM_IsFainted(func_021C7CF4(flow, pokeId)) == 0)
        return;
    if (WAZA_TOOL_GetFlag(BTL_EVENT_GetVar(HANDVAR_MOVE_ID), 0) == 0)
        return;
    attackerId = BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID);
    attacker = func_021C7CF4(flow, attackerId);
    record = func_021C88A4(flow, HANDEX_KIND_DAMAGE, pokeId);
    record->header |= HANDEX_FLAG_SHOW_ABILITY;
    record->pokeId = attackerId;
    record->amount = BTL_CALC_DivideMaxHpMin1(attacker, 4);
    record->unblockable = 1;
    func_021C8838(&record->message, HANDEX_MESSAGE_SET, 0x192);
    func_021C8860(&record->message, attackerId);
    func_021C88C8(flow, record);
}


void *HAND_TOKUSEI_AddAftermath(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F0820;
}


/*
 * Forecast: when the weather changes, a Pokemon that has this ability switches
 * form to match it. Four gates come first (the species check passes, no battle
 * lock, the Pokemon is alive, the new form differs from the current one), then
 * the window-in, record, window-out sequence.
 */
void HAND_TOKUSEI_ForecastOnWeatherChange(int myHandle, struct BtlServerFlow *flow, int pokeId)
{
    struct BtlPokeParam *self;
    struct HandExChangeForm *record;
    u8 weather;

    if (func_021E85F8(pokeId) == 0)
        return;
    if (func_021C83D4(flow) != 0)
        return;
    self = func_021C7CF4(flow, pokeId);
    if (BTL_POKEPARAM_IsFainted(self) != 0)
        return;
    weather = (u8)BTL_EVENT_GetVar(HANDVAR_WEATHER);
    if (weather == 0x11)
        return;
    if (BTL_POKEPARAM_HasType(self, weather) != 0)
        return;
    func_021C88B4(flow, HANDEX_ABILITY_WINDOW_IN, pokeId);
    record = func_021C88A4(flow, HANDEX_KIND_CHANGE_FORM, pokeId);
    record->form = BTLV_CORE_PackByteTwice(weather);
    record->pokeId = pokeId;
    func_021C88C8(flow, record);
    func_021C88B4(flow, HANDEX_ABILITY_WINDOW_OUT, pokeId);
}


void *HAND_TOKUSEI_AddForecast(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F0818;
}


/* Synchronize: a poison, paralysis or burn inflicted on this Pokemon is passed on to
   the Pokemon that caused it. */
void HAND_TOKUSEI_SynchronizeOnSickAdded(int myHandle, struct BtlServerFlow *flow, int pokeId)
{
    struct HandExAddSick *record;
    int sickKind;
    u8 attackerId;
    struct BtlPokeParam *self;
    union SickCont inflictedCont;

    if (pokeId != BTL_EVENT_GetVar(HANDVAR_DEFENDER_ID))
        return;
    sickKind = BTL_EVENT_GetVar(HANDVAR_SICK_ID);
    if (sickKind != BTL_SICK_POISON && sickKind != BTL_SICK_PARALYSIS && sickKind != BTL_SICK_BURN)
        return;
    attackerId = BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID);
    if (attackerId == BTL_POKEID_NONE || attackerId == pokeId)
        return;
    self = func_021C7CF4(flow, pokeId);
    inflictedCont.raw = BTL_EVENT_GetVar(HANDVAR_SICK_CONT);
    func_021C88B4(flow, HANDEX_ABILITY_WINDOW_IN, pokeId);
    record = func_021C88A4(flow, HANDEX_KIND_ADD_SICK, pokeId);
    record->pokeId = attackerId;
    record->sickKind = sickKind;
    if (sickKind == BTL_SICK_POISON && BTLV_CORE_IsSlotKind1Index15(inflictedCont))
        record->sickCont.raw = inflictedCont.raw;
    else
        BTL_CALC_MakeSickContFromKind(sickKind, self, &record->sickCont);
    record->suppressMessage = 1;
    func_021C88C8(flow, record);
    func_021C88B4(flow, HANDEX_ABILITY_WINDOW_OUT, pokeId);
}


void *HAND_TOKUSEI_AddSynchronize(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F0810;
}


/* Mold Breaker: when this Pokemon attacks, set the general flag so the defender's ability is ignored. */
void HAND_TOKUSEI_MoldBreakerOnAbilityCheck(int myHandle, int flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID))
        BTL_EVENT_OverwriteVar(HANDVAR_GENERAL_FLAG, 1);
}


void *HAND_TOKUSEI_AddMoldBreaker(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F0808;
}


/* Cloud Nine / Air Lock: the weather this Pokemon sees is cleared. */
void HAND_TOKUSEI_CloudNineOnWeatherCheck(int myHandle, int flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(HANDVAR_POKE_ID))
        BTL_EVENT_OverwriteVar(HANDVAR_WEATHER, 0);
}


void *HAND_TOKUSEI_AddCloudNine(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F0800;
}


void *HAND_TOKUSEI_AddTrace(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F07F8;
}


/*
 * Trace: copy a foe's ability. The work flag is 1 when the first attempt found no
 * Pokemon with a copyable ability; the handler then retries as foes enter the field.
 */
void HAND_TOKUSEI_TraceOnMemberIn(int myHandle, struct BtlServerFlow *flow, int pokeId, int *work)
{
    u8 foeIds[3];
    u8 candidateIds[3];
    u8 tracedId;
    u32 abilityId;
    u8 enteringId;
    u8 candidateCount, i, choice;
    u32 foeCount;
    u16 foeMask;
    int slot;
    struct BtlPokeParam *foe;
    int foeAbility;
    struct HandExChangeAbility *record;
    enteringId = BTL_EVENT_GetVar(HANDVAR_POKE_ID);
    tracedId = BTL_POKEID_NONE;
    abilityId = 0;
    if (enteringId == pokeId) {
        foeMask = func_021C7D00(flow, pokeId);
        foeCount = func_021C7F68(flow, (u16)(foeMask | 0x100), foeIds);
        for (candidateCount = 0, i = 0; i < foeCount; i++) {
            if (!func_0689C944((u16)func_021D59B4(func_021C7CF4(flow, foeIds[i]), BPP_VALUE_ABILITY))) candidateIds[candidateCount++] = foeIds[i];
        }
        if (candidateCount != 0) {
            choice = candidateCount == 1 ? 0 : BTL_CALC_Random(candidateCount);
            foe = func_021C7CF4(flow, candidateIds[choice]);
            abilityId = func_021D59B4(foe, BPP_VALUE_ABILITY);
            tracedId = BTL_POKEPARAM_GetPokeId(foe);
        } else {
            *work = 1;
        }
    } else if (!func_021B9A24(enteringId, pokeId) && *work == 1) {
        slot = func_021C8010(flow, enteringId);
        foeMask = func_021C7D00(flow, pokeId);
        if (slot != BTL_SLOT_NONE && (func_021C815C(flow) != 2 || func_021B9A6C(foeMask, slot))) {
            foeAbility = func_021D59B4(func_021C7CF4(flow, enteringId), BPP_VALUE_ABILITY);
            if (!func_0689C944((u16)foeAbility)) { abilityId = foeAbility; tracedId = enteringId; }
        }
    }
    if (abilityId != 0 && pokeId != BTL_POKEID_NONE) {
        record = func_021C88A4(flow, HANDEX_KIND_CHANGE_ABILITY, pokeId);
        record->pokeId = pokeId;
        record->abilityId = abilityId;
        record->announce = 1;
        record->header |= HANDEX_FLAG_SHOW_ABILITY;
        func_021C8838(&record->message, HANDEX_MESSAGE_SET, 0x17d);
        func_021C8860(&record->message, tracedId);
        func_021C8860(&record->message, record->abilityId);
        func_021C88C8(flow, record);
    }
}
