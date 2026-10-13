/*
 * unit:     no
 * function: GFL_NET_WM_ICON_ClearOam
 * address:  0x02036FD8
 * packet:   pkt_02036F04
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GX_LoadOAM  0x0207E684  arm
 *   GXS_LoadOAM  0x0207E708  arm
 */

int GFL_NET_WM_ICON_ClearOam(void){ int t0 = GX_LoadOAM((int)0x20A0810, (int)0, (int)0x20); int t1 = GXS_LoadOAM((int)0x20A0810, (int)0, (int)0x20); return t1; }
