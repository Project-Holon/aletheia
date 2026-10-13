/*
 * function: BTL_SIDE_GetSlotOfClientThunk
 * address:  0x021B9AF8
 * packet:   pkt_021B9AF8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT* (extent 12, compiled 10, trailing padding)
 */

char *BTL_SIDE_GetSlotOfClientThunk(char *p, int i)
{
    return p + 4 + i * 0x1c;
}
