/*
 * function: MB_SEQ_GetPageButtonHit
 * address:  0x021C7648
 * packet:   pkt_ov136_021C7648
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   TOUCHPANEL_HitTrg  0x02035C08  arm
 *   d_021C7E2C 0x021C7E2C data a4
 */

typedef unsigned char u8;
extern const u8 d_021C7E2C[];
extern int TOUCHPANEL_HitTrg(const void *);
int MB_SEQ_GetPageButtonHit(u8 *p)
{
    return TOUCHPANEL_HitTrg(d_021C7E2C);
}
