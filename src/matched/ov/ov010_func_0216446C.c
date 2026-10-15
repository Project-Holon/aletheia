/*
 * function: FIELD_MAP_CHANGE_ResetGimmickStateCase4
 * address:  0x0216446C
 * packet:   pkt_ov010_0216446C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled thumb tail-call stub (ldr r3,[pc,#0]; bx r3; .word 0x0215E34D);
 * the sole blocker of ov020 func_0218562C.
 *
 * symbols:
 *   FIELD_ENCOUNT_ST_ResetGimmickState  0x0215E34C  thumb  ov010
 *
 * Every ov020 caller passes a second argument (r1), but FIELD_ENCOUNT_ST_ResetGimmickState
 * reads only r0, so b stays unused here; its result passes back in r0.
 */

extern int FIELD_ENCOUNT_ST_ResetGimmickState(int a0);

int FIELD_MAP_CHANGE_ResetGimmickStateCase4(int a, int b)
{
    return FIELD_ENCOUNT_ST_ResetGimmickState(a);
}
