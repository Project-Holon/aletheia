/*
 * function: PLEASURE_BOAT_GetPassengerType
 * address:  0x021C87AC
 * packet:   pkt_ov021_021C87AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * Unlabelled leaf in the 0x1C-byte record accessor run; called from ov010
 * SYMBOL_MAP_ScrCmdGetEventStateValue case 6. 10 bytes plus 2 bytes of padding.
 */
typedef unsigned char u8;
typedef unsigned int u32;

u32 PLEASURE_BOAT_GetPassengerType(void *p, u32 i)
{
    return *(u32 *)((u8 *)p + i * 0x1C + 0x10);
}
