/*
 * function: func_021BE85C
 * address:  0x021BE85C
 * packet:   pkt_021BE85C
 * region:   ov203
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0 0x020307B0 arm
 */

extern void func_020307B0(void *);

void func_021BE85C(char *a)
{
    func_020307B0((void *)*(int *)(a + 8));
    func_020307B0((void *)*(int *)a);
    func_020307B0(a);
}