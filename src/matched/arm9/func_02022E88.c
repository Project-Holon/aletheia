/*
 * unit:     no
 * function: WIPE_SUB_SetWindowVisibleMode
 * address:  0x02022E88
 * packet:   pkt_02022D98
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WIPE_SUB_SetWindowVisible  0x02023B48  thumb
 *   WIPE_SUB_RequestWindowVisible  0x02023CFC  thumb
 */

int WIPE_SUB_SetWindowVisibleMode(int a0, int a1, int a2, int a3){ int t0, t1; if ((unsigned int)(a3) == (unsigned int)(0)) { t0 = WIPE_SUB_SetWindowVisible((int)(a1 + 0), (int)(a2 + 0)); return t0; } else { t1 = WIPE_SUB_RequestWindowVisible(a0, a1, a2); return t1; } }
