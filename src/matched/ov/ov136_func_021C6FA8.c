/*
 * function: func_021C6FA8
 * address:  0x021C6FA8
 * packet:   pkt_ov136_021C6FA8
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020061E4            0x020061E4  thumb
 *   func_021C66A0 0x021C66A0 thumb
 *   func_021C770C 0x021C770C thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021C770C(u8 *);
extern void func_020061E4(u32);
extern void func_021C66A0(u8 *p, int i, u32 v);
int func_021C6FA8(u8 *p)
{
    if (func_021C770C(p) == 1) {
        func_020061E4(0x551);
        func_021C66A0(*(u8 **)(p + 8), 3, 9);
        *(u32 *)(p + 0x28) = 0x10;
        return 0x18;
    }
    return 0xF;
}
