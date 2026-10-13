/*
 * function: ENCEFF_GetEffect
 * address:  0x021CF51C
 * packet:   pkt_ov021_021CF51C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled 4-byte accessor (returns the first word of its argument),
 * filed 2026-10-04 (wave D2) because it blocks ov077/ov078 callers.
 *
 * symbols:
 */

typedef unsigned int u32;

u32 ENCEFF_GetEffect(u32 *p) { return *p; }
