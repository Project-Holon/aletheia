/*
 * function: func_021C2224
 * address:  0x021C2224
 * packet:   pkt_ov099_021C2224
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020410D0  0x020410D0  arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_020410D0(u32 index, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u8 a6, u8 a7, u8 a8, u8 a9);

void func_021C2224(char *p, u32 a1, u32 a2, u32 mode, u8 slot)
{
    u16 x;
    u16 y;
    if (mode == 2) {
        x = 0;
        y = 0x12;
    } else {
        x = (u16)(mode << 4);
        y = (u16)(slot * 6);
    }
    func_020410D0(6, a1, a2, 0x10, 6, *(u32 *)(p + 0x8B8) + 0xC, x, y, 0x20, 0x18);
}
