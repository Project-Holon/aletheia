/*
 * unit:     no
 * function: GFL_NET_STATE_WifiConnected
 * address:  0x0203C464
 * packet:   pkt_0203C304
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_STATE_ChangeStateDebug  0x0203AD80  arm
 *   GFL_NET_GetSession  0x0203D788  arm
 */

int GFL_NET_STATE_WifiConnected(int a0, int a1, int a2, int a3){ int t0 = GFL_NET_GetSession(); int t1 = GFL_NET_STATE_ChangeStateDebug((int)*(int *)((char *)(0x21469DC)), (int)0x203C0F4, (int)0, (int)0x637); return t1; }
