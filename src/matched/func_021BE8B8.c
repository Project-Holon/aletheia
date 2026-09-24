/*
 * function: func_021BE8B8
 * address:  0x021BE8B8
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021BEC10  0x021BEC10  arm  ov114
 *   func_021BEF08  0x021BEF08  arm  ov114
 *   func_021BEF58  0x021BEF58  arm  ov114
 *
 *
 * Keyed word store at +0xd0; -1 when the key is unknown.
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 *func_021BEF08(void);
extern u8 *func_021BEF58(int);
extern int func_021BEC10(int, int);

int func_021BE8B8(int a, int v)
{
    u8 *p = (u8 *)func_021BEC10((int)func_021BEF58((int)func_021BEF08()), a);
    if (p == 0)
        return -1;
    *(u32 *)(p + 0xd0) = v;
    return 0;
}
