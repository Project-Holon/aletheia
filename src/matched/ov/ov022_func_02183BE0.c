/*
 * function: UNION_APP_Delete
 * address:  0x02183BE0
 * packet:   pkt_ov022_02183BE0
 * region:   ov022
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled tail-call thunk (ldr r3 / bx r3 / pool) in ov022; blocker of
 * ov012 UNION_MAIN_StepGroupActivity.
 * symbols:
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

void UNION_APP_Delete(void *p)
{
    func_020307B0(p);
}
