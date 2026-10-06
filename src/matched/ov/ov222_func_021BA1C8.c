/*
 * function: func_021BA1C8
 * address:  0x021BA1C8
 * packet:   pkt_021BA1C8
 * region:   ov222
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02048AC4  0x02048AC4  arm
 *   func_02046788  0x02046788  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern u32 func_02048AC4(void *ptr);
extern void func_02046788(u32 x);

void func_021BA1C8(u32 *p)
{
    func_02046788(func_02048AC4((void *)(*p)));
}
