/*
 * unit:     no
 * function: BTL_SETUP_Delete
 * address:  0x020130B4
 * packet:   pkt_02013090
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SETUP_FreeSlots  0x020130DC  thumb
 */

int BTL_SETUP_Delete(int a0){ int t0 = BTL_SETUP_FreeSlots(a0); int t1 = func_020307B0((int)((a0 + 0) + 0)); return t1; }
