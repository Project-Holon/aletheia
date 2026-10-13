/*
 * function: FIELD_ENCOUNT_PickWaterSlot
 * address:  0x021A9E64
 * packet:   pkt_ov021_021A9E64
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_ENCOUNT_RandPercent  0x021A9DC8  thumb
 */

typedef unsigned int u32;

extern u32 FIELD_ENCOUNT_RandPercent(void);

int FIELD_ENCOUNT_PickWaterSlot(int a)
{
    u32 v = FIELD_ENCOUNT_RandPercent();
    if (v < 60) {
        return 0;
    }
    if (v >= 60 && v < 90) {
        return 1;
    }
    if (v >= 90 && v < 95) {
        return 2;
    }
    if (v >= 95 && v < 99) {
        return 3;
    }
    return 4;
}
