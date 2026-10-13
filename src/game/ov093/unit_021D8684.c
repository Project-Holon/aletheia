/*
 * file:     unit_021D8684.c
 * unit:     yes
 * function: BTL_CALC_InnerFocusPreventFlinch, BTL_CALC_GetSteadfastHandlers, BTL_CALC_SteadfastOnFlinch, BTL_CALC_GetThickFatHandlers
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
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   gSteadfastHandlers     0x021F07B0  data   ov093  a4
 *   gThickFatHandlers     0x021F05B8  data   ov093  a4
 */
#include "unit_021D8434_types.h"

void BTL_CALC_InnerFocusPreventFlinch(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
int *BTL_CALC_GetSteadfastHandlers(int *packedInfo);
void BTL_CALC_SteadfastOnFlinch(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
int *BTL_CALC_GetThickFatHandlers(int *packedInfo);
extern int gSteadfastHandlers[];
extern int gThickFatHandlers[];


/* Inner Focus: prevents flinching. */
void BTL_CALC_InnerFocusPreventFlinch(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID))
        BTL_EVENT_OverwriteVar(BTL_EVAR_PREVENT_FLAG, 1);
}


/* Steadfast: handler table. */
int *BTL_CALC_GetSteadfastHandlers(int *packedInfo)
{
    *packedInfo = 1;
    return gSteadfastHandlers;
}


/* Steadfast: raises the speed of the poke that flinched by one rank. */
void BTL_CALC_SteadfastOnFlinch(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BtlRankCmd *cmd;

    if (BTL_EVENT_GetVar(BTL_EVAR_FAIL_REASON) == BTL_FAIL_REASON_FLINCH) {
        if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
            cmd = func_021C88A4(flow, 0xe, pokeId);
            cmd->header |= BTL_CMD_FLAG_FROM_ABILITY;
            cmd->statId = 5;
            cmd->amount = 1;
            cmd->showMessage = 0;
            cmd->targetCount = 1;
            cmd->targets[0] = pokeId;
            func_021C88C8(flow, cmd);
        }
    }
}


/* Thick Fat: handler table. */
int *BTL_CALC_GetThickFatHandlers(int *packedInfo)
{
    *packedInfo = 1;
    return gThickFatHandlers;
}
