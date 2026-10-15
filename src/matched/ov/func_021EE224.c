/*
 * function: BOX2_UI_SetSlotOamEnabled
 * address:  0x021EE224
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_OAM_SetEnabled  0x02025774  thumb  ov170
 *
 * Forward the i-th entry word plus the third argument.
 */

extern void BMP_OAM_SetEnabled(int, int);

void BOX2_UI_SetSlotOamEnabled(char *p, int i, int v)
{
    BMP_OAM_SetEnabled(*(int *)(p + i * 8 + 4), v);
}

