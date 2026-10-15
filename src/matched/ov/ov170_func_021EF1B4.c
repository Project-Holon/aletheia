/*
 * function: BOX2_UI_GetCloseButtonHit
 * address:  0x021EF1B4
 * packet:   pkt_ov170_021EF1B4
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_UI_HitTableCont 0x021EF0A8 thumb
 *   d_021F0F40 0x021F0F40 data
 */

extern int BOX2_UI_HitTableCont(const char *p, unsigned n);
extern const unsigned char d_021F0F40[];

int BOX2_UI_GetCloseButtonHit(void)
{
    return BOX2_UI_HitTableCont((const char *)d_021F0F40, 2);
}
