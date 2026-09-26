/*
 * function: func_021BB998
 * address:  0x021BB998
 * packet:   pkt_ov217_021BB998
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf in a .word run:
 *   movs r1,#0; str r1,[r0,#0x20]; bx lr
 * Clears the word at p+0x20.
 */

void func_021BB998(void *p)
{
    *(unsigned int *)((char *)p + 0x20) = 0;
}
