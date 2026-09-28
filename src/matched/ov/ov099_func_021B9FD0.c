/*
 * function: func_021B9FD0
 * address:  0x021B9FD0
 * packet:   pkt_ov099_021B9FD0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb tail-call thunk in a .word run:
 *   ldr r0,[r0,#0x2c]; ldr r3,[pc,#4]; movs r1,#0; bx r3; .word 0x0204B3DC
 *
 * symbols:
 *   func_0204B3DC  0x0204B3DC  arm
 */

extern int func_0204B3DC(int, int);

int func_021B9FD0(void *p)
{
    return func_0204B3DC(*(int *)((char *)p + 0x2c), 0);
}
