/*
 * function: func_021D70F0
 * address: 0x021D70F0
 * packet: pkt_ov120_021D70F0
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02040618 0x02040618 arm
 *   func_02041300 0x02041300 arm
 *   func_020409B4 0x020409B4 arm
 */
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void func_02041300(u32, int, int, int, u8, u8, u8);
extern void func_020409B4(u32);
void func_021D70F0(void *a0)
{
    func_02040618(4, 3, 0);
    func_02040618(6, 3, 0);
    func_02041300(1, 0, 0, 0, 32, 32, 17);
    func_020409B4(1);
}
