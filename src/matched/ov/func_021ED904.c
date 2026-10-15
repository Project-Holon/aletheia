/*
 * function: BOX2_UI_RefreshBoxName
 * address:  0x021ED904
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BOX2_UI_DrawSlot  0x021EDAB0  thumb  ov170
 *   BOX2_UI_RefreshBoxHeader  0x021ED9C8  thumb  ov170
 *
 * Seat one entry, then re-sort.
 */



extern void BOX2_UI_DrawSlot(char *, int);
extern void BOX2_UI_RefreshBoxHeader(char *);
void BOX2_UI_RefreshBoxName(unsigned char *p)
{
    BOX2_UI_DrawSlot((char *)p, p[0x14]);
    BOX2_UI_RefreshBoxHeader((char *)p);
}
