/*
 * function: SODATEYA_CompactSlots
 * address:  0x021C36B0
 * packet:   pkt_ov021_021C36B0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Compacts the two day-care slots so occupied ones come first.
 *
 * symbols:
 *   DAYCARE_IsSlotInUse  0x0200BCA8  thumb
 *   DAYCARE_SwapSlots  0x0200BCEC  thumb
 */

extern int DAYCARE_IsSlotInUse(void *e, int i);
extern void DAYCARE_SwapSlots(void *e, int i, int j);

void SODATEYA_CompactSlots(void *e)
{
    int i, j;

    for (i = 0; i < 2; i++) {
        if (DAYCARE_IsSlotInUse(e, i) == 1)
            continue;
        for (j = i + 1; j < 2; j++) {
            if (DAYCARE_IsSlotInUse(e, j) == 1)
                DAYCARE_SwapSlots(e, j, j - 1);
        }
    }
}
