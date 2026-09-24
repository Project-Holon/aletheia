/*
 * function: func_021BA850
 * address:  0x021BA850
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021BEF08  0x021BEF08  arm  ov114
 *
 *
 * Calls the +0x04 hook of the module object with one argument.
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern u8 *func_021BEF08(void);

void func_021BA850(int a)
{
    void (*g)(int) = *(void (**)(int))(func_021BEF08() + 4);
    if (g != 0)
        g(a);
}
