/*
 * function: BR_GRAPHIC_VBlankTask
 * address:  0x021FC4E8
 * packet:   pkt_021FC4E8
 * region:   ov186
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BR_GRAPHIC_VBlankBg  0x021FC598  thumb  ov186
 *   BR_GRAPHIC_VBlankActors  0x021FC604  thumb  ov186
 */

extern void BR_GRAPHIC_VBlankBg(void *);
extern void BR_GRAPHIC_VBlankActors(void *);

void BR_GRAPHIC_VBlankTask(int a0, char *p)
{
    BR_GRAPHIC_VBlankBg(p);
    BR_GRAPHIC_VBlankActors(p + 4);
}
