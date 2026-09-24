/*
 * function: func_021BE698
 * address:  0x021BE698
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021BA988  0x021BA988  arm  ov114
 *   func_021BEF08  0x021BEF08  arm  ov114
 *
 *
 * Tears the module down with a null callback.
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned char u8;
extern u8 *func_021BEF08(void);
extern void func_021BA988(u8 *, int);

void func_021BE698(void)
{
    func_021BA988(func_021BEF08(), 0);
}
