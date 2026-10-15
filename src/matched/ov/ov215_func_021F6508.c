/*
 * function: EGG_DEMO_GRAPHIC_VBlank
 * address:  0x021F6508
 * packet:   pkt_021F6508
 * region:   ov215
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   EGG_DEMO_GRAPHIC_TickDisplay 0x021F65B8 thumb
 *   EGG_DEMO_GRAPHIC_VBlankClact 0x021F6624 thumb
 */

extern void EGG_DEMO_GRAPHIC_TickDisplay(void *);
extern void EGG_DEMO_GRAPHIC_VBlankClact(void *);

void EGG_DEMO_GRAPHIC_VBlank(int a, char *b)
{
    EGG_DEMO_GRAPHIC_TickDisplay(b);
    EGG_DEMO_GRAPHIC_VBlankClact(b + 4);
}