/*
 * function: BOX2_UI_CursorTagE
 * address:  0x021EEB30
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
 * Ignore the two known tags, otherwise run the update.
 */

extern void BOX2_UI_UpdateCursor(char *p, int v);

void BOX2_UI_CursorTagE(void *a, int tag)
{
    if (tag != 0x22 && tag != 0x23)
        BOX2_UI_UpdateCursor(a, tag);
}

