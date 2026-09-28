/*
 * function: func_021BE6AC
 * address:  0x021BE6AC
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021BAA14  0x021BAA14  arm  ov114
 *   func_021BEF08  0x021BEF08  arm  ov114
 *
 *
 * Module +0x14 field read: the +0x14 word of the singleton module object.
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 *func_021BEF08(void);
extern u32 func_021BAA14(u8 *);

u32 func_021BE6AC(void)
{
    return func_021BAA14(func_021BEF08());
}
