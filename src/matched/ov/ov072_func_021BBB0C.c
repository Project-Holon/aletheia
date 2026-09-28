/*
 * function: func_021BBB0C
 * address:  0x021BBB0C
 * packet:   pkt_ov072_021BBB0C
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf in a .word run:
 *   lsls r1,r1,#2; adds r0,r0,r1; ldr r0,[r0,#4]; bx lr
 * Word at p + n*4 + 4.
 */

unsigned int func_021BBB0C(void *p, int n)
{
    return *(unsigned int *)((char *)p + n * 4 + 4);
}
