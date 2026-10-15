/*
 * function: BOX2_UI_GetPageButtonHit2
 * address:  0x021EF264
 * packet:   pkt_ov170_021EF264
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_UI_HitTableCont 0x021EF0A8 thumb
 *   d_021F0F58 0x021F0F58 data
 */

extern int BOX2_UI_HitTableCont(const char *p, unsigned n);
extern const unsigned char d_021F0F58[];

int BOX2_UI_GetPageButtonHit2(void)
{
    return BOX2_UI_HitTableCont((const char *)d_021F0F58, 1);
}
