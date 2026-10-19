/*
 * unit:     no
 * function: GFL_NET_STATE_ChangeoverParentCallback
 * address:  0x0203B6B4
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
 *   GFL_NET_STATE_RollParentWaitTime  0x0203B344  arm
 */

int GFL_NET_STATE_ChangeoverParentCallback(int a0, int a1, int a2, int a3){ int t0 = GFL_NET_STATE_RollParentWaitTime((int)*(int *)((char *)(0x21469DC))); int t1 = GFL_NET_STATE_ChangeStateDebug((int)*(int *)((char *)(0x21469DC)), (int)0x203B5D4, (int)t0, (int)0x2E6); return 1; }
