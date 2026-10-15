/*
 * function: BEACON_DETAIL_GRA_Task
 * address:  0x021BCA44
 * packet:   pkt_021BCA44
 * region:   ov216
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BEACON_DETAIL_GRA_UpdateBg  0x021BCAF4  thumb  ov216
 *   BEACON_DETAIL_GRA_VBlankClact  0x021BCB98  thumb  ov216
 *
 * Addresses are Black-image addresses.
 */

extern void BEACON_DETAIL_GRA_UpdateBg(void *);
extern void BEACON_DETAIL_GRA_VBlankClact(void *);

void BEACON_DETAIL_GRA_Task(void *unused, char *p)
{
    BEACON_DETAIL_GRA_UpdateBg(p);
    BEACON_DETAIL_GRA_VBlankClact(p + 4);
}
