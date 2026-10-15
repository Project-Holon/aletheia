/*
 * function: NAMEIN_GRAPHIC_PickerMove
 * address:  0x021F26E0
 * packet:   pkt_021F26E0
 * region:   ov194
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

void NAMEIN_GRAPHIC_PickerMove(char *a, int b, int c)
{
    ((void (*)(int, int, char *))(*(void **)(a + 0x18)))(b, c, a + 4);
}
