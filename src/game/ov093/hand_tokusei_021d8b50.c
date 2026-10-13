/*
 * file:     hand_tokusei_021d8b50.c
 * unit:     yes
 * function: HAND_TOKUSEI_FilterHalveSuperEffective, HAND_TOKUSEI_SniperBoostCritical, HAND_TOKUSEI_SpeedBoostOnTurnEnd, HAND_TOKUSEI_GetSpeedBoostHandlers, HAND_TOKUSEI_AdaptabilityBoostSameType, HAND_TOKUSEI_GetAdaptabilityHandlers, HAND_TOKUSEI_BlazeBoostFire, HAND_TOKUSEI_GetBlazeHandlers, HAND_TOKUSEI_TorrentBoostWater, HAND_TOKUSEI_GetTorrentHandlers, HAND_TOKUSEI_OvergrowBoostGrass, HAND_TOKUSEI_GetOvergrowHandlers, HAND_TOKUSEI_SwarmBoostBug, HAND_TOKUSEI_GetSwarmHandlers, HAND_TOKUSEI_PinchBoostType, HAND_TOKUSEI_GutsBoostAttack, HAND_TOKUSEI_GetGutsHandlers
 * address:  0x021D8B50
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
 *   gFilterHandlers 0x021F07C0 data a4
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_CALC_SummarizeTypeAffinity 0x021D7AD4 thumb ov093
 *   BTL_EVENT_MultiplyVar 0x021D7704 thumb ov093
 *   gSniperHandlers 0x021F07B8 data a4
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_TestContFlag  0x021D5BDC  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_EVENT_OverwriteVar   0x021D76BC  thumb ov093
 *   gSpeedBoostHandlers     0x021F0698  data   ov093  a4
 *   BTL_CALC_DivideMaxHp  0x021D7B60  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   BTL_POKEPARAM_GetMajorStatusIndex  0x021D62A8  thumb  ov093
 *   WAZA_TOOL_GetDamageType  0x0201C1E8  thumb
 *   gAdaptabilityHandlers     0x021F07D8  data   ov093  a4
 *   gBlazeHandlers     0x021F06B0  data   ov093  a4
 *   gTorrentHandlers     0x021F0610  data   ov093  a4
 *   gOvergrowHandlers     0x021F0648  data   ov093  a4
 *   gSwarmHandlers     0x021F0640  data   ov093  a4
 *   gGutsHandlers     0x021F0638  data   ov093  a4
 */
#include "btl_action_word_types.h"

void HAND_TOKUSEI_FilterHalveSuperEffective(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void *HAND_TOKUSEI_GetFilterHandlers(int *packedInfo);
void HAND_TOKUSEI_SniperBoostCritical(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void *HAND_TOKUSEI_GetSniperHandlers(int *packedInfo);
void HAND_TOKUSEI_SpeedBoostOnTurnEnd(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
int *HAND_TOKUSEI_GetSpeedBoostHandlers(int *packedInfo);
void HAND_TOKUSEI_AdaptabilityBoostSameType(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
int *HAND_TOKUSEI_GetAdaptabilityHandlers(int *packedInfo);
void HAND_TOKUSEI_BlazeBoostFire(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
int *HAND_TOKUSEI_GetBlazeHandlers(int *packedInfo);
void HAND_TOKUSEI_TorrentBoostWater(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
int *HAND_TOKUSEI_GetTorrentHandlers(int *packedInfo);
void HAND_TOKUSEI_OvergrowBoostGrass(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
int *HAND_TOKUSEI_GetOvergrowHandlers(int *packedInfo);
void HAND_TOKUSEI_SwarmBoostBug(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
int *HAND_TOKUSEI_GetSwarmHandlers(int *packedInfo);
void HAND_TOKUSEI_PinchBoostType(struct BtlSvFlow *flow, int pokeId, int moveType);
void HAND_TOKUSEI_GutsBoostAttack(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
int *HAND_TOKUSEI_GetGutsHandlers(int *packedInfo);
extern unsigned char gFilterHandlers[];
extern unsigned int gSniperHandlers;
extern int gSpeedBoostHandlers[];
extern int gAdaptabilityHandlers[];
extern int gBlazeHandlers[];
extern int gTorrentHandlers[];
extern int gOvergrowHandlers[];
extern int gSwarmHandlers[];
extern int gGutsHandlers[];

/* Filter and Solid Rock: moves that are super effective against the owner do 0.75 times damage. */
void HAND_TOKUSEI_FilterHalveSuperEffective(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID) && BTL_CALC_SummarizeTypeAffinity(BTL_EVENT_GetVar(BTL_EVAR_TYPE_AFFINITY)) == BTL_AFFINITY_SUPER_EFFECTIVE)
        BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, BTL_RATIO_0_75);
}

/* Filter and Solid Rock: handler table. */
void *HAND_TOKUSEI_GetFilterHandlers(int *packedInfo)
{
    *packedInfo = 1;
    return gFilterHandlers;
}

/* Sniper: critical hits of the owner do 1.5 times damage again. */
void HAND_TOKUSEI_SniperBoostCritical(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID) && BTL_EVENT_GetVar(BTL_EVAR_CRITICAL_FLAG))
        BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, BTL_RATIO_1_5);
}

/* Sniper: handler table. */
void *HAND_TOKUSEI_GetSniperHandlers(int *packedInfo) { *packedInfo = 1; return &gSniperHandlers; }

/* Speed Boost: raises the speed of the owner by one rank at the end of the turn. */
void HAND_TOKUSEI_SpeedBoostOnTurnEnd(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BtlRankCmd *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        if (BTL_POKEPARAM_TestContFlag(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), 0) != 0) {
            cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, 14, pokeId);
            cmd->header |= BTL_CMD_FLAG_FROM_ABILITY;
            cmd->statId = 5;
            cmd->targetCount = 1;
            cmd->targets[0] = pokeId;
            cmd->amount = 1;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
        }
    }
}

/* Speed Boost: handler table. */
int *HAND_TOKUSEI_GetSpeedBoostHandlers(int *packedInfo)
{
    *packedInfo = 1;
    return gSpeedBoostHandlers;
}

/* Adaptability: moves of the owner that get the same type bonus do twice the damage. */
void HAND_TOKUSEI_AdaptabilityBoostSameType(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        if (BTL_EVENT_GetVar(BTL_EVAR_SAME_TYPE_FLAG) != 0)
            BTL_EVENT_OverwriteVar(BTL_EVAR_RATIO, BTL_RATIO_2_0);
    }
}

/* Adaptability: handler table. */
int *HAND_TOKUSEI_GetAdaptabilityHandlers(int *packedInfo)
{
    *packedInfo = 1;
    return gAdaptabilityHandlers;
}

/* Blaze. */
void HAND_TOKUSEI_BlazeBoostFire(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    HAND_TOKUSEI_PinchBoostType(flow, pokeId, POKETYPE_FIRE);
}

/* Blaze: handler table. */
int *HAND_TOKUSEI_GetBlazeHandlers(int *packedInfo)
{
    *packedInfo = 1;
    return gBlazeHandlers;
}

/* Torrent. */
void HAND_TOKUSEI_TorrentBoostWater(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    HAND_TOKUSEI_PinchBoostType(flow, pokeId, POKETYPE_WATER);
}

/* Torrent: handler table. */
int *HAND_TOKUSEI_GetTorrentHandlers(int *packedInfo)
{
    *packedInfo = 1;
    return gTorrentHandlers;
}

/* Overgrow. */
void HAND_TOKUSEI_OvergrowBoostGrass(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    HAND_TOKUSEI_PinchBoostType(flow, pokeId, POKETYPE_GRASS);
}

/* Overgrow: handler table. */
int *HAND_TOKUSEI_GetOvergrowHandlers(int *packedInfo)
{
    *packedInfo = 1;
    return gOvergrowHandlers;
}

/* Swarm. */
void HAND_TOKUSEI_SwarmBoostBug(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    HAND_TOKUSEI_PinchBoostType(flow, pokeId, POKETYPE_BUG);
}

/* Swarm: handler table. */
int *HAND_TOKUSEI_GetSwarmHandlers(int *packedInfo)
{
    *packedInfo = 1;
    return gSwarmHandlers;
}

/* Blaze, Torrent, Overgrow and Swarm: moves of the given type do 1.5 times damage when the owner has a third of its HP or less. */
void HAND_TOKUSEI_PinchBoostType(struct BtlSvFlow *flow, int pokeId, int moveType)
{
    struct BtlPokeParam *bpp;
    u32 hpThreshold;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        bpp = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        hpThreshold = BTL_CALC_DivideMaxHp(bpp, 3);
        if (func_021D59B4(bpp, 13) <= hpThreshold) {
            if (moveType == BTL_EVENT_GetVar(BTL_EVAR_MOVE_TYPE))
                BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, BTL_RATIO_1_5);
        }
    }
}

/* Guts: physical moves of an owner with a status condition do 1.5 times damage. */
void HAND_TOKUSEI_GutsBoostAttack(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (BTL_POKEPARAM_GetMajorStatusIndex(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId)) != 0) {
            if (WAZA_TOOL_GetDamageType((u16)BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID)) == WAZA_DAMAGE_PHYSICAL)
                BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, BTL_RATIO_1_5);
        }
    }
}

/* Guts: handler table. */
int *HAND_TOKUSEI_GetGutsHandlers(int *packedInfo)
{
    *packedInfo = 1;
    return gGutsHandlers;
}
