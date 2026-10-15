/*
 * function: func_021BCD3C
 * address: 0x021BCD3C
 * packet: pkt_ov210_021BCD3C
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: 2-byte alignment padding at 0x021BCDA2.
 * symbols:
 *   BG_SYS_ClearSlot 0x020414EC arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02041300 0x02041300 arm
 *   BG_SYS_ResetSlot 0x02041EE4 arm
 */
typedef unsigned int u32;
typedef unsigned char u8;
extern void BG_SYS_ClearSlot(u32);
extern void func_02041B6C(u32);
extern void func_02041300(u32, int, int, int, u8, u8, u8);
extern void BG_SYS_ResetSlot(u32, u32, u32);
void func_021BCD3C(u8 *p)
{
    p[0x2b8] = 2;
    BG_SYS_ClearSlot(1);
    BG_SYS_ClearSlot(3);
    BG_SYS_ClearSlot(5);
    func_02041B6C(1);
    func_02041B6C(3);
    func_02041B6C(5);
    func_02041300(0, 0, 0, 0, 32, 21, 0);
    func_02041B6C(0);
    BG_SYS_ResetSlot(1, 3, 0);
    BG_SYS_ResetSlot(5, 3, 0);
}
