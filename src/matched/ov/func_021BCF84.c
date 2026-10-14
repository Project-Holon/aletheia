/*
 * function: ZUKAN_DETAIL_GRAPHIC_VBlankTransfer
 * address:  0x021BCF84
 * packet:   pkt_021BCF18
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   ZUKAN_DETAIL_GRAPHIC_TransferOam 0x021BD034  thumb  ov208
 *   ZUKAN_DETAIL_GRAPHIC_VBlankActors 0x021BD0A0  thumb  ov208

 */

extern void ZUKAN_DETAIL_GRAPHIC_TransferOam(char *);
extern void ZUKAN_DETAIL_GRAPHIC_VBlankActors(char *);

void ZUKAN_DETAIL_GRAPHIC_VBlankTransfer(int unused, char *p)
{
    ZUKAN_DETAIL_GRAPHIC_TransferOam(p);
    ZUKAN_DETAIL_GRAPHIC_VBlankActors(p + 4);
}

