/*
 * unit:     no
 * function: GFL_NET_WM_ICON_SetLevel
 * address:  0x02036E74
 * packet:   pkt_02036CA8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

int *GFL_NET_WM_ICON_SetLevel(int *p, int v){ if (v < 4) *p = v;  return p; }
