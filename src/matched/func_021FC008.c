/*
 * function: func_021FC008
 * address:  0x021FC008
 * packet:   pkt_021FC008
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F88D8  0x021F88D8  thumb  ov135

 *
 * Hand the second argument to func_021F88D8 with a scratch word.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021F88D8(u32 a, u32 *out);

void func_021FC008(u32 unused, u32 a)
{
    u32 tmp;

    func_021F88D8(a, &tmp);
}
