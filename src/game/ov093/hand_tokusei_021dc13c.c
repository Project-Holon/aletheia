/*
 * file:     hand_tokusei_021dc13c.c
 * unit:     yes
 * function: HAND_TOKUSEI_FriendGuard_ReduceAllyDamage, HAND_TOKUSEI_Healer_CureAllyStatus, HAND_TOKUSEI_GetHealerHandlers, HAND_TOKUSEI_ToxicBoost_BoostPhysicalPower, HAND_TOKUSEI_GetToxicBoostHandlers, HAND_TOKUSEI_FlareBoost_BoostSpecialPower, HAND_TOKUSEI_GetFlareBoostHandlers, HAND_TOKUSEI_Telepathy_AvoidAllyAttack, HAND_TOKUSEI_GetTelepathyHandlers
 * address:  0x021DC13C
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
 *   gFriendGuardHandlers 0x021F0780 data a4
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_MAIN_IsPokeSamePair 0x021B9A24 thumb ov093
 *   BTL_EVENT_MultiplyVar 0x021D7704 thumb ov093
 *   BTL_SERVER_FLOW_GetPokeViewPos  0x021C8010  thumb  ov093
 *   BTL_SERVER_FLOW_CollectAlivePokeIds  0x021C7F68  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetMajorStatusIndex  0x021D62A8  thumb  ov093
 *   HAND_TOKUSEI_RollChanceOrFlag  0x021D85C0  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 *   gHealerHandlers     0x021F0778  data   ov093  a4
 *   gToxicBoostHandlers     0x021F0768  data   ov093  a4
 *   WAZA_TOOL_IsDamaging  0x0201C314  thumb
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   gFlareBoostHandlers     0x021F0620  data   ov093  a4
 *   gTelepathyHandlers     0x021F05E8  data   ov093  a4
 */
#include "hand_tokusei_021dbaf0_types.h"

extern int BTL_EVENT_GetVar(int key);
extern int BTL_MAIN_IsPokeSamePair(unsigned int pokeIdA, unsigned int pokeIdB);
extern void BTL_EVENT_MultiplyVar(int key, int ratio);
extern int BTL_SERVER_FLOW_GetPokeViewPos(struct BtlServerFlow *flow, unsigned int mask);
extern u8 BTL_SERVER_FLOW_CollectAlivePokeIds(struct BtlServerFlow *flow, int posKey, u8 *out);
extern struct BtlPokeParam *BTL_SERVER_FLOW_GetPokeParam(struct BtlServerFlow *flow, int pokeId);
extern int BTL_POKEPARAM_GetMajorStatusIndex(struct BtlPokeParam *bpp);
extern int HAND_TOKUSEI_RollChanceOrFlag(struct BtlServerFlow *flow, u32 percent);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(struct BtlServerFlow *flow, int cmdKind, int pokeId);
extern void BTL_SERVER_FLOW_CommitCmdRecord(struct BtlServerFlow *flow, void *cmd);
extern int BTL_POKEPARAM_HasSick(struct BtlPokeParam *bpp, int sickId);
extern u32 WAZA_TOOL_IsDamaging(u16 moveId);
extern int BTL_EVENT_OverwriteVar(int key, u32 value);
extern void BTL_SERVER_FLOW_InitMsgRecord(BtlStrParam *strParam, int strType, int strId);
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(BtlStrParam *strParam, u32 arg);
void HAND_TOKUSEI_FriendGuard_ReduceAllyDamage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, unsigned int ownerId);
int *HAND_TOKUSEI_GetFriendGuardHandlers(int *handlerCount);
void HAND_TOKUSEI_Healer_CureAllyStatus(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId);
int *HAND_TOKUSEI_GetHealerHandlers(int *handlerCount);
void HAND_TOKUSEI_ToxicBoost_BoostPhysicalPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId);
int *HAND_TOKUSEI_GetToxicBoostHandlers(int *handlerCount);
void HAND_TOKUSEI_FlareBoost_BoostSpecialPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId);
int *HAND_TOKUSEI_GetFlareBoostHandlers(int *handlerCount);
void HAND_TOKUSEI_Telepathy_AvoidAllyAttack(struct BtlEventFactor *factor, struct BtlServerFlow *flow, u32 ownerId);
int *HAND_TOKUSEI_GetTelepathyHandlers(int *handlerCount);
extern int gFriendGuardHandlers;
extern int gHealerHandlers[];
extern int gToxicBoostHandlers[];
extern int gFlareBoostHandlers[];
extern int gTelepathyHandlers[];

/* Friend Guard: damage to an ally of the owner is reduced to three quarters. */
void HAND_TOKUSEI_FriendGuard_ReduceAllyDamage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, unsigned int ownerId)
{
    unsigned char defenderId;
    defenderId = BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID);
    if (defenderId != ownerId && BTL_MAIN_IsPokeSamePair(ownerId, defenderId))
        BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, BTL_RATIO_0_75);
}

int *HAND_TOKUSEI_GetFriendGuardHandlers(int *handlerCount) { *handlerCount = 1; return &gFriendGuardHandlers; }

/* Healer: sometimes cures the major status condition of an ally. */
void HAND_TOKUSEI_Healer_CureAllyStatus(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId)
{
    u8 allyIds[4];
    u8 allyCount;
    u8 i;
    BtlCureSickCmd *cmd;

    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        allyCount = BTL_SERVER_FLOW_CollectAlivePokeIds(flow, (u16)(0x400 | BTL_SERVER_FLOW_GetPokeViewPos(flow, ownerId)), allyIds);
        for (i = 0; i < allyCount; i++) {
            if (allyIds[i] != ownerId) {
                if (BTL_POKEPARAM_GetMajorStatusIndex(BTL_SERVER_FLOW_GetPokeParam(flow, allyIds[i])) && HAND_TOKUSEI_RollChanceOrFlag(flow, 30)) {
                    cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_CURE_SICK, ownerId);
                    cmd->flags |= BTL_CMD_FLAG_FROM_ABILITY;
                    cmd->flags |= BTL_CMD_FLAG_ABILITY_ON_ALLY;
                    cmd->showMessage = 1;
                    cmd->pokeId = allyIds[i];
                    cmd->sickIndex = BTL_CURE_ALL_MAJOR;
                    BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
                }
            }
        }
    }
}

int *HAND_TOKUSEI_GetHealerHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gHealerHandlers;
}

/* Toxic Boost: while poisoned, the physical power of the owner is 1.5 times. */
void HAND_TOKUSEI_ToxicBoost_BoostPhysicalPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId)
{
    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)
        && BTL_POKEPARAM_HasSick(BTL_SERVER_FLOW_GetPokeParam(flow, ownerId), BTL_SICK_POISON) != 0
        && BTL_EVENT_GetVar(BTL_EVAR_DAMAGE_TYPE) == BTL_DAMAGE_TYPE_PHYSICAL) {
        BTL_EVENT_MultiplyVar(BTL_EVAR_POWER_RATIO, BTL_RATIO_1_5);
    }
}

int *HAND_TOKUSEI_GetToxicBoostHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gToxicBoostHandlers;
}

/* Flare Boost: while burned, the special power of the owner is 1.5 times. */
void HAND_TOKUSEI_FlareBoost_BoostSpecialPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId)
{
    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)
        && BTL_POKEPARAM_HasSick(BTL_SERVER_FLOW_GetPokeParam(flow, ownerId), BTL_SICK_BURN) != 0
        && BTL_EVENT_GetVar(BTL_EVAR_DAMAGE_TYPE) == BTL_DAMAGE_TYPE_SPECIAL) {
        BTL_EVENT_MultiplyVar(BTL_EVAR_POWER_RATIO, BTL_RATIO_1_5);
    }
}

int *HAND_TOKUSEI_GetFlareBoostHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gFlareBoostHandlers;
}

/* Telepathy: damaging moves of an ally do not hit the owner. */
void HAND_TOKUSEI_Telepathy_AvoidAllyAttack(struct BtlEventFactor *factor, struct BtlServerFlow *flow, u32 ownerId)
{
    BtlMessageCmd *cmd;
    u8 attackerId;
    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID)) {
        attackerId = BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID);
        if (BTL_MAIN_IsPokeSamePair(ownerId, attackerId) != 0
            && ownerId != attackerId
            && WAZA_TOOL_IsDamaging(BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID)) != 0
            && BTL_EVENT_OverwriteVar(BTL_EVAR_NO_EFFECT_FLAG, 1) != 0) {
            cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_MESSAGE, ownerId);
            cmd->flags |= BTL_CMD_FLAG_FROM_ABILITY;
            BTL_SERVER_FLOW_InitMsgRecord(&cmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_TELEPATHY_AVOID);
            BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->strParam, ownerId);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
        }
    }
}

int *HAND_TOKUSEI_GetTelepathyHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gTelepathyHandlers;
}
