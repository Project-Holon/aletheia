/*
 * function: HAND_ITEM_MentalHerbCureCondition
 * address:  0x021DE34C
 * packet:   pkt_ov093_021DE34C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT* (extent runs past compiled, trailing padding)
 *
 * symbols:
 *   HAND_ITEM_CureSickOnEaten  0x021DD19C  thumb  ov093
 */

typedef unsigned char  u8;
void HAND_ITEM_CureSickOnEaten(void *a, u8 *b, int c, int d);

void HAND_ITEM_MentalHerbCureCondition(int a, int b, int c, u8 *a3)
{
    HAND_ITEM_CureSickOnEaten((void *)a, (u8 *)b, c, 0x26);
}
