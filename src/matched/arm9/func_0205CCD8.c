/*
 * function: DWC_GetLinkLevel
 * address:  0x0205CCD8
 * packet:   pkt_0205CCD8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021666C8  0x021666C8  arm  ov009
 *
 * Tail call to func_021666C8 (WCM_GetLinkLevel, ov009) through a pool word;
 * called from func_021F4EB4.
 */

extern int func_021666C8(void);

int DWC_GetLinkLevel(void)
{
    return func_021666C8();
}
