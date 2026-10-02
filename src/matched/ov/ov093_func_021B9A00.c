/*
 * function: func_021B9A00
 * address: 0x021B9A00
 * packet: pkt_ov093_021B9A00
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B99F0 0x021B99F0 thumb ov093
 *   func_021B8C20 0x021B8C20 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 func_021B99F0(u32);
extern u8 func_021B8C20(int, u32, u32);
int func_021B9A00(u32 x, u8 *out)
{
    if (func_021B99F0(x) == 0) {
        *out = func_021B8C20(2, x, (u8)(x >> 1));
        return 1;
    }
    return 0;
}
