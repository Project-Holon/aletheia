/*
 * unit:     no
 * function: GFL_NET_STATE_ChangeoverParentRestart
 * address:  0x0203B688
 * packet:   pkt_0203B5D4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_STATE_ChangeStateDebug  0x0203AD80  arm
 *   GFL_NET_STATE_GetParentWaitTime  0x0203B344  arm
 */

int GFL_NET_STATE_ChangeoverParentRestart(int a0, int a1, int a2, int a3){ int t0 = GFL_NET_STATE_GetParentWaitTime((int)a0); int t1 = GFL_NET_STATE_ChangeStateDebug((int)*(int *)((char *)(0x21469DC)), (int)0x203B5D4, (int)t0, (int)0x2e0); return t1; }
