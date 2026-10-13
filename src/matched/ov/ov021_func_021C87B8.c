/*
 * function: PLEASURE_BOAT_GetPassengerExtra
 * address:  0x021C87B8
 * packet:   pkt_ov021_021C87B8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * Unlabelled leaf in the 0x1C-byte record accessor run; called from ov010
 * SYMBOL_MAP_ScrCmdGetEventStateValue case 7. 14 bytes plus 2 bytes of padding.
 * lever: the record pointer as its own local; the flat
 *   `p + i*0x1C + j*4 + 0x1C` spelling is DIFF4 (adds order).
 */
typedef unsigned char u8;
typedef unsigned int u32;

u32 PLEASURE_BOAT_GetPassengerExtra(void *p, u32 i, u32 j)
{
    u8 *e = (u8 *)p + i * 0x1C;
    return ((u32 *)(e + 0x1C))[j];
}
