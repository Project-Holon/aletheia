/*
 * function: HAND_ITEM_DampRockExtendRain
 * address:  0x021DF4D4
 * packet:   pkt_ov093_021DF4D4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT* (extent runs past compiled, trailing padding)
 *
 * symbols:
 *   HAND_ITEM_ExtendWeatherTurns  0x021DF4E0  thumb  ov093
 */

void HAND_ITEM_ExtendWeatherTurns(void *a, int b, int c, int d);

void HAND_ITEM_DampRockExtendRain(int a, int b, int c)
{
    HAND_ITEM_ExtendWeatherTurns((void *)a, b, c, 2);
}
