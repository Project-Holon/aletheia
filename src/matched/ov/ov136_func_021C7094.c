/*
 * function: func_021C7094
 * address:  0x021C7094
 * packet:   pkt_ov136_021C7094
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C7430 0x021C7430 thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Bf7 {
    u8 v : 7;
    u8 w : 1;
};
extern void func_021C7430(u8 *, int, u16, u16);
int func_021C7094(u8 *p)
{
    if (*(u32 *)(p + 0x24) == 0) {
        *(u32 *)(p + 0x28) = 0x15;
        return 0;
    }
    func_021C7430(p, 0xB, *(u16 *)(p + 0x22), ((struct Bf7 *)(p + 0x21))->v);
    *(u32 *)(p + 0x14) = 3;
    return 6;
}
