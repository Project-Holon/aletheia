/*
 * function: func_021BBB14
 * address:  0x021BBB14
 * packet:   pkt_ov072_021BBB14
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf in a .word run:
 *   lsls r1,r1,#2; ldr r0,[r0,r1]; bx lr
 * Word at p + n*4.
 */

unsigned int func_021BBB14(void *p, int n)
{
    return *(unsigned int *)((char *)p + n * 4);
}
