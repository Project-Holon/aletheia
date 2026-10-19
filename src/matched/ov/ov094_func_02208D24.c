/*
 * function: BTLV_GAUGE_SetBgmPlayerParam
 * address:  0x02208D24
 * packet:   pkt_ov094_02208D24
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_USE_SetBgmPaused  0x02005DE4  thumb  arm9
 */

extern int func_0200F300(void);
extern void GFL_USE_SetBgmPaused(void *p);

void BTLV_GAUGE_SetBgmPlayerParam(int a)
{
    if (func_0200F300() != 1)
        GFL_USE_SetBgmPaused((void *)a);
}
