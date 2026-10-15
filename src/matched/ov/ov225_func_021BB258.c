/*
 * function: MANUAL_COMMON_IndexToY
 * address: 0x021BB258
 * packet: pkt_ov225_021BB258
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * lever: narrow the average to u16 before subtracting 8; minimum clamp returns directly.
 * extent: 90 compiled bytes followed by two zero alignment bytes at 021BB2B2.
 */
typedef unsigned short u16;
u16 MANUAL_COMMON_IndexToY(void *p, u16 count, u16 index)
{
    u16 result, low, high;
    if (index == 0) result = 17;
    else if (index == count - 1) result = 135;
    else {
        low = (119 * index) / count + 25;
        high = (119 * (index + 1)) / count + 25;
        result = (low + high) / 2;
        result -= 8;
    }
    if (result < 17) return 17;
    if (result > 135) result = 135;
    return result;
}
