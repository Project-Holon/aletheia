/*
 * function: func_0218448C
 * address:  0x0218448C
 * packet:   pkt_0218448C
 * region:   ov168
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0208B528  0x0208B528  arm
 */

extern int func_0208B528(void);

void func_0218448C(int *p)
{
    func_0208B528();
    *(int *)((char *)p + 0x28) = 0;
}
