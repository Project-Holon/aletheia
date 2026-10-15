/*
 * function: EGG_DEMO_GRAPHIC_Draw
 * address:  0x021F64D0
 * packet:   pkt_021F64D0
 * region:   ov215
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   EGG_DEMO_GRAPHIC_DrawClact 0x021F661C thumb
 *   EGG_DEMO_GRAPHIC_Noop 0x021F65B4 thumb
 */

extern void EGG_DEMO_GRAPHIC_DrawClact(void *);
extern void EGG_DEMO_GRAPHIC_Noop(void *);

void EGG_DEMO_GRAPHIC_Draw(char *a)
{
    EGG_DEMO_GRAPHIC_DrawClact(a + 4);
    EGG_DEMO_GRAPHIC_Noop(a);
}