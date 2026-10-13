/*
 * function: func_02164464
 * address:  0x02164464
 * packet:   pkt_ov010_02164464
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_ENCOUNT_ST_ResetGimmickState  0x0215E34C  thumb  ov010
 *
 * Unlabelled leaf (a tail-call thunk saves nothing, so disasm.py prints it
 * as data after the previous function).  One of four byte-identical thunks
 * to FIELD_ENCOUNT_ST_ResetGimmickState at 0x02164454, 0x0216445C, 0x02164464 and 0x0216446C.
 * Blocker of ov020 EVENT_MAPCHANGE_ChangeFieldEvent (case 2 of the *(u8 *)(p + 0x30) switch).
 *
 * Every ov020 caller passes a second argument (r1), but FIELD_ENCOUNT_ST_ResetGimmickState
 * reads only r0, so b stays unused here; its result passes back in r0.
 */

extern int FIELD_ENCOUNT_ST_ResetGimmickState(int a0);

int func_02164464(int a, int b)
{
    return FIELD_ENCOUNT_ST_ResetGimmickState(a);
}
