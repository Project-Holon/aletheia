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
 * Unlabelled leaf: sets state 1 by tail-calling WIH_ChangeSysState.  Used as the
 * callback of WIH_StateOutInitialize's call to WM_SetLifeTime.
 *
 * symbols:
 *   WIH_ChangeSysState  0x02178138  thumb  ov014
 */

extern void WIH_ChangeSysState(int state);

void DWCi_MOV_WH_StateOutSetLifeTime(void)
{
    WIH_ChangeSysState(1);
}
