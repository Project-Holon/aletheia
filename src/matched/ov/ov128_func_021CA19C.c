/*
 * function: WF2DMAP_TOUCH_UpdateTopBar
 * address: 0x021CA19C
 * packet: pkt_ov128_021CA19C
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two-byte zero padding at 021CA1DE; next labelled function 021CA1E0.
 * symbols:
 *   func_020355C4 0x020355C4 arm
 *   WF2DMAP_TOUCH_DrawTopHighlight 0x021CA124 thumb ov128
 */
typedef unsigned char u8;
extern u8 func_020355C4(void);
typedef unsigned int   u32;
extern void WF2DMAP_TOUCH_DrawTopHighlight(u32 a, u32 b);
void WF2DMAP_TOUCH_UpdateTopBar(unsigned *p)
{
    unsigned i;
    if(func_020355C4()==1) {
        for(i=0;i<3;i++) WF2DMAP_TOUCH_DrawTopHighlight(i,1);
        return;
    }
    for(i=0;i<3;i++) {
        if(i==*p) WF2DMAP_TOUCH_DrawTopHighlight(i,3);
        else WF2DMAP_TOUCH_DrawTopHighlight(i,1);
    }
}
