/*
 * function: func_021B7FE4
 * address:  0x021B7FE4
 * packet:   pkt_ov106_021B7FE4
 * region:   ov106
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk to the ARM function at 0x0204A600.
 *
 * symbols:
 *   CLACT_DrawSystem  0x0204A600  arm  arm9
 */

extern void CLACT_DrawSystem(void);

void func_021B7FE4(void *a0)
{
    CLACT_DrawSystem();
}
