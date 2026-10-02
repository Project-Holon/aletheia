/*
 * function: func_021BBB48
 * address: 0x021BBB48
 * packet: pkt_ov093_021BBB48
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02049238 0x02049238 arm
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_02049238(u32);
extern void func_020307B0(void *);
void func_021BBB48(u8 *p)
{
    func_02049238(*(u32 *)(p + 0x4a4));
    func_020307B0(p);
}
