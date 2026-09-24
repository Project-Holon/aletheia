/*
 * function: func_021BEF08
 * address:  0x021BEF08
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021CF984  0x021CF984  data
 *   g_021CF98C  0x021CF98C  data
 *   g_021CF9C0  0x021CF9C0  data
 *   g_021CF964  0x021CF964  data
 *   func_021BEEC4  0x021BEEC4  arm  ov114
 *
 *
 * Lazily instantiates the overlay's singleton module object.
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 g_021CF984[];
extern u8 g_021CF9C0[];
extern void func_021BEEC4(u8 *);

u8 *func_021BEF08(void)
{
    u8 *p = *(u8 **)(g_021CF984 + 4);
    if (p == 0) {
        p = g_021CF9C0;
        *(u8 **)(g_021CF984 + 4) = p;
        func_021BEEC4(p);
    }
    return p;
}
