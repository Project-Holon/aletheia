/*
 * function: BOX2_UI_CursorTagI
 * address:  0x021EEF68
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_UI_UpdateCursor  0x021EE408  thumb  ov170
 *
 * Run the attached handler unless the key is 0x21.
 */



extern void BOX2_UI_UpdateCursor(char *p, int v);
void BOX2_UI_CursorTagI(char *a, int b)
{
    if (b != 0x21)
        BOX2_UI_UpdateCursor(a, b);
}
