/*
 * function: func_021D0440
 * address:  0x021D0440
 * packet:   pkt_ov021_021D0440
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021ABE18  0x021ABE18  thumb  ov021
 *   func_021C6580  0x021C6580  thumb  ov021
 *   func_021C6628  0x021C6628  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_021ABE18(u32 a);
extern u32 func_021C6628(u32, u32);
extern u32 func_021C6580(u32, u32);

void func_021D0440(u16 *p)
{
    int i = 0;
    u32 h = func_021ABE18(*(u32 *)(p + 2));

    for (; i < 2; i++) {
        func_021C6628(h, p[4 + i]);
        func_021C6580(h, p[i]);
    }
}
