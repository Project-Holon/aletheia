/*
 * function: func_021BE6BC
 * address:  0x021BE6BC
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021BE6EC  0x021BE6EC  arm  ov114
 *   func_021BEC10  0x021BEC10  arm  ov114
 *   func_021BEF08  0x021BEF08  arm  ov114
 *   func_021BEF58  0x021BEF58  arm  ov114
 *
 *
 * Keyed post to record `a`, forwarding two arguments.
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 *func_021BEF08(void);
extern u8 *func_021BEF58(int);
extern int func_021BEC10(int, int);
extern void func_021BE6EC(int, int, int);

void func_021BE6BC(int a, int b, int c)
{
    func_021BE6EC(func_021BEC10((int)func_021BEF58((int)func_021BEF08()), a), b, c);
}
