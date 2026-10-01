/*
 * function: func_021C675C
 * address: 0x021C675C
 * packet: pkt_ov136_021C675C
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   func_02027698 0x02027698 thumb
 *   func_0202769C 0x0202769C thumb
 *   func_020276A0 0x020276A0 thumb
 *   func_0201BC3C 0x0201BC3C thumb
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned short u16;
extern u32 func_020275E4(void);
extern u32 func_020490F4(u32, u32);
extern u32 func_02027698(void);
extern int func_0204A6C8(u32, u32, u32, u32, u16);
extern u32 func_0201BC3C(void);
extern int func_0204ABF0(u32, u32, u32, u32, u16);
extern u32 func_0202769C(u32);
extern u32 func_020276A0(u32);
extern int func_0204AF28(u32, u32, u32, u32);
extern void func_02049238(u32);
void func_021C675C(u8 *p)
{
    u32 arc;
    u32 i;
    u32 first;
    arc = func_020490F4(func_020275E4(), 102);
    for (i = 0; i <= 2; i++)
        *(u32 *)(p + 0x210 + i * 4) = func_0204A6C8(arc, func_02027698(), 0, 1, 102);
    *(u32 *)(p + 0x230) = func_0204ABF0(arc, func_0201BC3C(), 1, 0, 102);
    first = func_0202769C(0);
    *(u32 *)(p + 0x250) = func_0204AF28(arc, first, func_020276A0(0), 102);
    func_02049238(arc);
}
