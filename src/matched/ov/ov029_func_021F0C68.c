/*
 * function: C_GEAR_IsTileFlashing
 * address:  0x021F0C68
 * packet:   pkt_021F0C68
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   C_GEAR_IsTileFlashing 0x021F0C68 thumb
 */

int C_GEAR_IsTileFlashing(unsigned short *p)
{
    return (int)((unsigned)(*p << 31) >> 31);
}
