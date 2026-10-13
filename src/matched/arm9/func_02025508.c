/*
 * unit:     no
 * function: ACTOR_TOOL_GetCharBlock
 * address:  0x02025508
 * packet:   pkt_02024ABC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CLACT_GetPaletteVramAddress  0x0204AEF4  arm
 */

unsigned int ACTOR_TOOL_GetCharBlock(int a0, int a1, int a2){ int t0 = CLACT_GetPaletteVramAddress((int)(a1 + 0), (int)(a2 + 0)); return ((unsigned int)(t0) >> 5); }
