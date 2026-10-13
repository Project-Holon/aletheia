/*
 * unit: yes
 * function: HAND_ITEM_ChestoBerryOnEaten, HAND_ITEM_AddChestoBerry
 * address: 0x021DD08C
 * packet: pkt_ov093_021DD08C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   HAND_ITEM_CureSickOnEaten 0x021DD19C thumb ov093
 *   gChestoBerryHandlers 0x021F1AEC data a4
 */
extern void HAND_ITEM_CureSickOnEaten(void *, unsigned char *, int, int);
extern const unsigned char gChestoBerryHandlers[];
void HAND_ITEM_ChestoBerryOnEaten(void *a, void *b, int c)
{
    HAND_ITEM_CureSickOnEaten(a, b, c, 2);
}
const void *HAND_ITEM_AddChestoBerry(int *p)
{
    *p = 5;
    return gChestoBerryHandlers;
}
