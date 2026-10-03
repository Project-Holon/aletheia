/*
 * function: func_021BB714
 * address:  0x021BB714
 * packet:   pkt_ov091_021BB714
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020450F0  0x020450F0  arm
 *   func_0201F73C  0x0201F73C  thumb
 *   func_021BBA28  0x021BBA28  thumb  ov091
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_0201F73C(u32 h, u32 a, u32 b, u32 c);
extern void func_021BBA28(void *a, u32 *s);

void func_021BB714(void *a, u32 *s, u32 k)
{
    s[0] = k;
    switch (k) {
    case 0:
        s[1] = func_020450F0(0, 1, 0x15, 0x15, 2, 0xe, 1);
        break;
    case 1:
        s[1] = func_020450F0(0, 1, 0x15, 0x14, 2, 0xe, 1);
        break;
    case 2:
        s[1] = func_020450F0(0, 2, 0x13, 0xe, 4, 0xe, 1);
        break;
    case 3:
        s[1] = func_020450F0(0, 2, 0x13, 0x1c, 4, 0xe, 1);
        break;
    }
    func_0201F73C(s[1], 1, 1, 0xc);
    func_021BBA28(a, s);
}
