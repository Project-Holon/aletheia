/*
 * function: func_021B9920
 * address: 0x021B9920
 * packet: pkt_ov093_021B9920
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9C00 0x021B9C00 thumb ov093
 */
typedef unsigned int u32;
typedef unsigned char u8;
extern u8 *func_021B9C00(void *p, u32 i);
u8 *func_021B9920(void *p, u32 i, u8 j)
{
    return func_021B9C00((void *)((unsigned int)p + 4 + i * 28), j);
}
