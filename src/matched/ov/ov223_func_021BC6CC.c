/*
 * function: func_021BC6CC
 * address:  0x021BC6CC
 * packet:   pkt_021BC6CC
 * region:   ov223
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02048AC4  0x02048AC4  arm
 *   func_02046788  0x02046788  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int   u32;
extern u32 func_02048AC4(void *ptr);
extern int func_02046788(int);

void func_021BC6CC(int *p)
{
    func_02046788(func_02048AC4((void *)(*p)));
}
