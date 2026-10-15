/*
 * unit:     no
 * function: GFL_NET_WM_ICON_GetCharOffset
 * address:  0x02036F04
 * packet:   pkt_02036F04
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GX_GetBankForOBJ  0x02080C24  arm
 *   GX_GetBankForSubOBJ  0x02080C64  arm
 */

int GFL_NET_WM_ICON_GetCharOffset(int a0){ int t0, t1; if ((unsigned int)(a0) == (unsigned int)(1)) { t0 = GX_GetBankForOBJ(); } else { t1 = GX_GetBankForSubOBJ(); }  return 0; }
