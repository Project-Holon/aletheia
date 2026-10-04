/*
 * function: func_021B6518
 * address: 0x021B6518
 * packet: pkt_ov101_021B6518
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B678C 0x021B678C thumb ov101
 */
typedef unsigned int u32;
extern int func_021B678C(int *p, int a, int b);
int func_021B6518(u32 p,u32 a,u32 b) {
    if(*(u32 *)(p+0x78)!=0) return 1;
    return func_021B678C((int *)(p+4),a,b);
}
