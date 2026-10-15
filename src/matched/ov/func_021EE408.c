/*
 * function: BOX2_UI_UpdateCursor
 * address:  0x021EE408
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_UI_SetCursorPos  0x021EE3E4  thumb  ov170
 *   BOX2_SEQ_RefreshHandSlot  0x021ECC1C  thumb  ov170
 *
 * Update the sub-object, then rebuild the panel.
 */



extern void BOX2_UI_SetCursorPos(char **p, unsigned idx);
extern void BOX2_SEQ_RefreshHandSlot(unsigned char *p);
void BOX2_UI_UpdateCursor(char *p, int v)
{
    BOX2_UI_SetCursorPos((char **)p, v);
    BOX2_SEQ_RefreshHandSlot((unsigned char *)p);
}
