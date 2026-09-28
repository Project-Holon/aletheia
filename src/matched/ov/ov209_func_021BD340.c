/*
 * function: func_021BD340
 * address:  0x021BD340
 * packet:   pkt_ov209_021BD340
 * region:   ov209
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BD314 0x021BD314 thumb
 */

extern void func_021BD314(void *);

int func_021BD340(char *a)
{
    func_021BD314(a);
    *(int *)(*(int *)a + 0x10) = 3;
    return 7;
}