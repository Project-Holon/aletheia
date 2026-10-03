/*
 * function: func_021B652C
 * address: 0x021B652C
 * packet: pkt_ov101_021B652C
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B67B0 0x021B67B0 thumb ov101
 */
typedef unsigned int u32;
extern int func_021B67B0(u32);
int func_021B652C(u32 p) {
    if(*(u32 *)(p+0x78)!=0) return 1;
    return func_021B67B0(p+4);
}
