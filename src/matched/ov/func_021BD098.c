/*
 * function: ZUKAN_DETAIL_GRAPHIC_DrawActors
 * address:  0x021BD098
 * packet:   pkt_021BD098
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_DrawSystem 0x0204A600  arm
 *
 * Tail call to the ARM9 function at 0x0204A600, forwarding the first argument.
 */

extern void CLACT_DrawSystem(char *);

void ZUKAN_DETAIL_GRAPHIC_DrawActors(char *p)
{
    CLACT_DrawSystem(p);
}
