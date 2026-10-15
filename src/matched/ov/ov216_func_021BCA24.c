/*
 * function: BEACON_DETAIL_GRA_Draw
 * address:  0x021BCA24
 * packet:   pkt_021BCA24
 * region:   ov216
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BEACON_DETAIL_GRA_DrawClact  0x021BCB90  thumb  ov216
 *   BEACON_DETAIL_GRA_Noop  0x021BCAF0  thumb  ov216
 *
 * Addresses are Black-image addresses.
 */

extern void BEACON_DETAIL_GRA_DrawClact(void *);
extern void BEACON_DETAIL_GRA_Noop(void *);

void BEACON_DETAIL_GRA_Draw(char *p)
{
    BEACON_DETAIL_GRA_DrawClact(p + 4);
    BEACON_DETAIL_GRA_Noop(p);
}
