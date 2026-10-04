/*
 * function: func_021BDB5C
 * address: 0x021BDB5C
 * packet: pkt_ov172_021BDB5C
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Extent remainder: zero alignment halfword at 021BDBC2.
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_02049238 0x02049238 arm
 */
typedef unsigned int u32;
typedef unsigned char u8;
struct Obj;
extern void func_0204B3B4(struct Obj *p);
extern void func_0204ADA4(u32);
extern void func_0204A8D4(u32);
extern void func_0204AFD8(u32);
extern void func_02049238(u32);
void func_021BDB5C(u8 *p)
{
    u8 i;
    func_0204B3B4((struct Obj *)(*(u32 *)(p + 0x1b0)));
    for (i = 0; i < 4; i++) func_0204ADA4(*(u32 *)(p + i * 4 + 0x180));
    for (i = 4; i < 8; i++) func_0204A8D4(*(u32 *)(p + i * 4 + 0x180));
    for (i = 8; i < 11; i++) func_0204AFD8(*(u32 *)(p + i * 4 + 0x180));
    func_02049238(*(u32 *)(p + 0x17c));
}
