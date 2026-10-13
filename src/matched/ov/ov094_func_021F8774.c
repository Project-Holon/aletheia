/*
 * function: func_021F8774
 * address:  0x021F8774
 * packet:   pkt_ov094_021F8774
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call to BTLV_GAUGE_IsLowHpBgmPlaying with the handle at 0x1a4 of the global work block.
 *
 * symbols:
 *   d_0220AF20  0x0220AF20  data  ov094
 *   BTLV_GAUGE_IsLowHpBgmPlaying 0x022088F4 thumb ov094
 */
extern char *d_0220AF20;
extern void BTLV_GAUGE_IsLowHpBgmPlaying(void *);

void func_021F8774(void)
{
    BTLV_GAUGE_IsLowHpBgmPlaying(*(void **)(d_0220AF20 + 0x1a4));
}
