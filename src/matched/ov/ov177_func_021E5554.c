/*
 * function: WIFIBATTLEMATCH_GRAPHIC_VBlank
 * address:  0x021E5554
 * packet:   pkt_021E5554
 * region:   ov177
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WIFIBATTLEMATCH_GRAPHIC_TickDisplay  0x021E5604  thumb  ov177
 *   WIFIBATTLEMATCH_GRAPHIC_VBlankClact  0x021E5670  thumb  ov177
 */

extern void WIFIBATTLEMATCH_GRAPHIC_TickDisplay(int *);
extern void WIFIBATTLEMATCH_GRAPHIC_VBlankClact(int *);

void WIFIBATTLEMATCH_GRAPHIC_VBlank(int a, int *p)
{
    WIFIBATTLEMATCH_GRAPHIC_TickDisplay(p);
    WIFIBATTLEMATCH_GRAPHIC_VBlankClact((int *)((char *)p + 4));
}
