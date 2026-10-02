/*
 * function: func_021F04D4
 * address: 0x021F04D4
 * packet: pkt_ov031_021F04D4
 * region: ov031
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 */
typedef unsigned int u32;
extern void func_0204ADA4(u32);
extern void func_0204A8D4(u32);
extern void func_0204AFD8(u32);
void func_021F04D4(char *p)
{
    func_0204ADA4(*(u32 *)(p + 12));
    func_0204A8D4(*(u32 *)(p + 8));
    func_0204AFD8(*(u32 *)(p + 16));
}
