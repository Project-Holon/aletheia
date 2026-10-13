/*
 * function: TRIAL_HOUSE_SetUseDeliveredTrainers
 * address:  0x021D0AB8
 * packet:   pkt_021D0AB8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   TRIAL_HOUSE_SetUseDeliveredTrainers   0x021D0AB8  thumb ov021
 *
 * Unlabelled ov021 leaf hidden in a word run: stores the second argument at
 * +0x130 of the first.  Matched to supply the `matched` witness for the
 * pending ov010 caller SCRCMD_TRIALHOUSE_SetRecordSource.
 */
#include "../include/Obj18370.h"

void TRIAL_HOUSE_SetUseDeliveredTrainers(int *p, int v)
{
    ((struct Obj18370 *)p)->f130 = v;
}
