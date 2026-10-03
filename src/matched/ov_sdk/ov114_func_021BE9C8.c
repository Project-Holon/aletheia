/*
 * function: func_021BE9C8
 * address:  0x021BE9C8
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021BE9F8  0x021BE9F8  arm  ov114
 *   func_021BEC10  0x021BEC10  arm  ov114
 *   func_021BEF08  0x021BEF08  arm  ov114
 *   func_021BEF58  0x021BEF58  arm  ov114
 *
 *
 * Keyed post of the b/c pair onto record `a`.
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 *func_021BEF08(void);
extern void *func_021BEF58(int p);
extern int func_021BEC10(int, int);
extern int func_021BE9F8(u8 *, int, int);

void func_021BE9C8(int a, int b, int c)
{
    func_021BE9F8((u8 *)func_021BEC10((int)func_021BEF58((int)func_021BEF08()), a), b, c);
}
