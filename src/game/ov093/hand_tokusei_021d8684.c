/*
 * file:     hand_tokusei_021d8684.c
 * unit:     yes
 * function: HAND_TOKUSEI_InnerFocusPreventFlinch, HAND_TOKUSEI_GetSteadfastHandlers, HAND_TOKUSEI_SteadfastOnFlinch, HAND_TOKUSEI_GetThickFatHandlers
 * address:  0x021D8684
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
 *   BTL_EVENT_OverwriteVar   0x021D76BC  thumb
 *   BTL_EVENT_GetVar   0x021D775C  thumb
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   gSteadfastHandlers     0x021F07B0  data   ov093  a4
 *   gThickFatHandlers     0x021F05B8  data   ov093  a4
 */
#include "btl_action_word_types.h"

void HAND_TOKUSEI_InnerFocusPreventFlinch(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
int *HAND_TOKUSEI_GetSteadfastHandlers(int *packedInfo);
void HAND_TOKUSEI_SteadfastOnFlinch(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
int *HAND_TOKUSEI_GetThickFatHandlers(int *packedInfo);
extern int gSteadfastHandlers[];
extern int gThickFatHandlers[];


/* Inner Focus: prevents flinching. */
void HAND_TOKUSEI_InnerFocusPreventFlinch(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID))
        BTL_EVENT_OverwriteVar(BTL_EVAR_FORCE_GROUNDED_FLAG, 1);
}


/* Steadfast: handler table. */
int *HAND_TOKUSEI_GetSteadfastHandlers(int *packedInfo)
{
    *packedInfo = 1;
    return gSteadfastHandlers;
}


/* Steadfast: raises the speed of the poke that flinched by one rank. */
void HAND_TOKUSEI_SteadfastOnFlinch(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BtlRankCmd *cmd;

    if (BTL_EVENT_GetVar(BTL_EVAR_FAIL_REASON) == BTL_FAIL_REASON_FLINCH) {
        if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
            cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, 0xe, pokeId);
            cmd->header |= BTL_CMD_FLAG_FROM_ABILITY;
            cmd->statId = 5;
            cmd->amount = 1;
            cmd->showMessage = 0;
            cmd->targetCount = 1;
            cmd->targets[0] = pokeId;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
        }
    }
}


/* Thick Fat: handler table. */
int *HAND_TOKUSEI_GetThickFatHandlers(int *packedInfo)
{
    *packedInfo = 1;
    return gThickFatHandlers;
}
