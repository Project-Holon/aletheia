/*
 * function: func_021748CC
 * address: 0x021748CC
 * packet: pkt_ov011_021748CC
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021736D8 0x021736D8 thumb ov011
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3F8 0x0203D3F8 arm
 */
typedef unsigned int u32;
int func_021736D8(void);
u32 func_020399A8(void);
u32 func_0203D3F8(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
u32 func_021748CC(char *p, u32 a)
{
    if (func_021736D8() == 0) {
        return 1;
    }
    return func_0203D3F8(func_020399A8(), a, 0x229, 0x54, (u32)(p + 0x880), 0, 0, 0);
}
