/*
 * function: func_02024134
 * address:  0x02024134
 * packet:   pkt_02024134
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled Thumb tail-call thunk: sub_02024570(b, a + 0x10), where sub_02024570 copies a halfword pair.
 *
 * symbols:
 *   sub_02024570  0x02024570  thumb
 */

extern void sub_02024570(void *dst, void *src);

void func_02024134(char *a, void *b)
{
    sub_02024570(b, a + 0x10);
}
