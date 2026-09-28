/*
 * function: func_021B9234
 * address:  0x021B9234
 * packet:   pkt_ov093_021B9234
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf in a .word run:
 *   ldr r2,[pc,#8]; movs r1,#0x40; ldrb r3,[r0,r2]; orrs r1,r3; strb r1,[r0,r2]; bx lr
 * with pool word 0x473.  Sets bit 6 of the byte at p+0x473.
 */

void func_021B9234(unsigned char *p)
{
    p[0x473] |= 0x40;
}
