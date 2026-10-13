/*
 * function: BTL_MAIN_GetTrainerType
 * address:  0x021BA020
 * packet:   pkt_021BA020
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT* (extent 12, compiled 10, trailing padding)
 */

unsigned short BTL_MAIN_GetTrainerType(char *p, int i)
{
    return *(unsigned short *)(p + i * 0x28 + 0x28);
}
