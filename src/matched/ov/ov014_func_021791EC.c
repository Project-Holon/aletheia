/*
 * function: DWCi_MOV_WH_StateOutSetLifeTime
 * address:  0x021791EC
 * packet:   pkt_ov014_021791EC
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf: sets state 1 by tail-calling func_02178138.  Used as the
 * callback of func_021791F8's call to WM_SetLifeTime.
 *
 * symbols:
 *   func_02178138  0x02178138  thumb  ov014
 */

extern void func_02178138(int state);

void DWCi_MOV_WH_StateOutSetLifeTime(void)
{
    func_02178138(1);
}
