/*
 * function: func_021C67D4
 * address: 0x021C67D4
 * packet: pkt_ov136_021C67D4
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 021C6882 halfword is alignment padding.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   func_02027618 0x02027618 thumb
 *   func_02027614 0x02027614 thumb
 *   func_0202761C 0x0202761C thumb
 *   func_02027620 0x02027620 thumb
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned short u16;
extern u32 func_020275E4(void);
extern u32 func_020490F4(u32, u32);
extern int func_0204A6C8(u32, u32, u32, u32, u16);
extern int func_0204ABF0(u32, u32, u32, u32, u16);
extern int func_0204AF28(u32, u32, u32, u32);
extern void func_02049238(u32);
extern u32 func_02027618(void);
extern u32 func_02027614(void);
extern u32 func_0202761C(u32);
extern u32 func_02027620(u32);
void func_021C67D4(u8 *p)
{
    u32 arc;
    u32 first;
    arc = func_020490F4(155, 102);
    *(u32 *)(p + 0x21c) = func_0204A6C8(arc, 44, 1, 0, 102);
    *(u32 *)(p + 0x234) = func_0204ABF0(arc, 47, 0, 0, 102);
    *(u32 *)(p + 0x254) = func_0204AF28(arc, 45, 46, 102);
    func_02049238(arc);
    arc = func_020490F4(func_020275E4(), 102);
    *(u32 *)(p + 0x220) = func_0204A6C8(arc, func_02027618(), 0, 0, 102);
    *(u32 *)(p + 0x238) = func_0204ABF0(arc, func_02027614(), 0, 128, 102);
    first = func_0202761C(0);
    *(u32 *)(p + 0x258) = func_0204AF28(arc, first, func_02027620(0), 102);
    func_02049238(arc);
}
