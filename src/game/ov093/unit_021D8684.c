/*
 * file:     unit_021D8684.c
 * unit:     yes
 * function: func_021D8684, func_021D869C, func_021D86A8, func_021D86F0
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
 *   func_021D76BC   0x021D76BC  thumb
 *   func_021D775C   0x021D775C  thumb
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   d_021F07B0     0x021F07B0  data   ov093  a4
 *   d_021F05B8     0x021F05B8  data   ov093  a4
 */
#include "unit_021D8434_types.h"

void func_021D8684(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
int *func_021D869C(int *packedInfo);
void func_021D86A8(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
int *func_021D86F0(int *packedInfo);
extern int d_021F07B0[];
extern int d_021F05B8[];


/* Inner Focus: prevents flinching. */
void func_021D8684(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == func_021D775C(BTL_EVAR_DEFENDER_ID))
        func_021D76BC(BTL_EVAR_PREVENT_FLAG, 1);
}


/* Steadfast: handler table. */
int *func_021D869C(int *packedInfo)
{
    *packedInfo = 1;
    return d_021F07B0;
}


/* Steadfast: raises the speed of the poke that flinched by one rank. */
void func_021D86A8(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BtlRankCmd *cmd;

    if (func_021D775C(BTL_EVAR_FAIL_REASON) == BTL_FAIL_REASON_FLINCH) {
        if (pokeId == func_021D775C(BTL_EVAR_POKE_ID)) {
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
int *func_021D86F0(int *packedInfo)
{
    *packedInfo = 1;
    return d_021F05B8;
}
