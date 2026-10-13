/*
 * function: func_021F8180
 * address:  0x021F8180
 * packet:   pkt_ov094_021F8180
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call to BTLV_GAUGE_IsAnimating with the handle at 0x1a4 of the global work block.
 *
 * symbols:
 *   d_0220AF20  0x0220AF20  data  ov094
 *   BTLV_GAUGE_IsAnimating 0x02207C94 thumb ov094
 */
extern char *d_0220AF20;
typedef unsigned char  u8;
extern int BTLV_GAUGE_IsAnimating(u8 *p);

int func_021F8180(void)
{
    return BTLV_GAUGE_IsAnimating(*(void **)(d_0220AF20 + 0x1a4));
}
