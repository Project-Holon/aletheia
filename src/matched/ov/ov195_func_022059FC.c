/*
 * function: SHINKA_DEMO_GRAPHIC_Draw
 * address:  0x022059FC
 * packet:   pkt_022059FC
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SHINKA_DEMO_GRAPHIC_DrawClact 0x02205BC8 thumb
 *   SHINKA_DEMO_GRAPHIC_Noop 0x02205B60 thumb
 */

extern void SHINKA_DEMO_GRAPHIC_DrawClact(void *);
extern void SHINKA_DEMO_GRAPHIC_Noop(void *);

void SHINKA_DEMO_GRAPHIC_Draw(char *a)
{
    SHINKA_DEMO_GRAPHIC_DrawClact(a + 4);
    SHINKA_DEMO_GRAPHIC_Noop(a);
}