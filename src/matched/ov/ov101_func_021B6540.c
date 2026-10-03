/*
 * function: func_021B6540
 * address: 0x021B6540
 * packet: pkt_ov101_021B6540
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B67C4 0x021B67C4 thumb ov101
 */
typedef unsigned int u32;
extern int func_021B67C4(u32);
int func_021B6540(u32 p) {
    if(*(u32 *)(p+0x78)!=0) return 1;
    return func_021B67C4(p+4);
}
