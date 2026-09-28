/*
 * function: func_021B9D58
 * address:  0x021B9D58
 * packet:   pkt_ov068_021B9D58
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf; the function thunk func_021B9964 tail-calls.
 * movs r1,#0 / adds r0,#0x4c / strh r1,[r0] / bx lr.
 */

void func_021B9D58(char *p)
{
    *(unsigned short *)(p + 0x4c) = 0;
}
