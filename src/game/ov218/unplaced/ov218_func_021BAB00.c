/*
 * function: func_021BAB00
 * address:  0x021BAB00
 * packet:   pkt_021BAB00
 * region:   ov218
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02048AC4  0x02048AC4  arm
 *   func_02046788  0x02046788  arm
 */

typedef unsigned int   u32;
extern u32 func_02048AC4(void *ptr);
extern void func_02046788(void);

void func_021BAB00(int *p)
{
    func_02048AC4((void *)(*p));
    func_02046788();
}
