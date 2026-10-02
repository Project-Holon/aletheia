/*
 * function: func_021B98B4
 * address: 0x021B98B4
 * packet: pkt_ov071_021B98B4
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * leaf: unlabelled tail stub called by func_021B9070; parent confirmed unowned.
 * symbols:
 *   func_02028484 0x02028484 thumb
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_02028484(u8 *,u32);
int func_021B98B4(u8 *a,u8 *b)
{
    return func_02028484(a+0x38,*(u32 *)(b+0x294));
}
