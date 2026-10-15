/*
 * function: MANUAL_COMMON_HitToIndex
 * address: 0x021BB1F4
 * packet: pkt_ov225_021BB1F4
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef unsigned short u16;
u16 MANUAL_COMMON_HitToIndex(void *p, u16 count, u16 value)
{
    u16 index, upper, lower;
    if (count <= 1) index = 0;
    else if (value < 25) index = 0;
    else if (value >= 144) index = count - 1;
    else {
        for (index = 0; index < count; index++) {
            upper = (119 * (index + 1)) / count + 25;
            lower = (119 * index) / count + 25;
            if (lower <= value && value < upper) break;
        }
    }
    if (index >= count) index = 0;
    return index;
}
