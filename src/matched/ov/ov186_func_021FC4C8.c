/*
 * function: BR_GRAPHIC_Draw
 * address:  0x021FC4C8
 * packet:   pkt_021FC4C8
 * region:   ov186
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BR_GRAPHIC_DrawActors  0x021FC5FC  thumb  ov186
 *   BR_GRAPHIC_DrawBg  0x021FC594  thumb  ov186
 */

extern void BR_GRAPHIC_DrawActors(void *);
extern void BR_GRAPHIC_DrawBg(void *);

void BR_GRAPHIC_Draw(char *p)
{
    BR_GRAPHIC_DrawActors(p + 4);
    BR_GRAPHIC_DrawBg(p);
}
