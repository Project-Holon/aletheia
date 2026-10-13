/*
 * function: HAND_ITEM_AspearBerryOnTrigger
 * address:  0x021DD0C8
 * packet:   pkt_021DD0C8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT* (extent runs past compiled, trailing padding)
 *
 * symbols:
 *   HAND_ITEM_CureSickOnTrigger  0x021DD158  thumb  ov093
 */

typedef unsigned char  u8;
void HAND_ITEM_CureSickOnTrigger(u8 *a, u8 *b, int c, int d);

void HAND_ITEM_AspearBerryOnTrigger(int a, int b, int c)
{
    HAND_ITEM_CureSickOnTrigger((u8 *)a, (u8 *)b, c, 3);
}
