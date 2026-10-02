/*
 * function: func_021C6E28
 * address:  0x021C6E28
 * packet:   pkt_ov136_021C6E28
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C5C00 0x021C5C00 thumb
 *   func_021C66B8 0x021C66B8 thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021C66B8(u8 *, int, u32);
extern void func_021C5C00(u8 *);
int func_021C6E28(u8 *p)
{
    if (*(u16 *)(p + 0x1C) == 0) {
        func_021C66B8(*(u8 **)(p + 8), 0, 0);
        func_021C66B8(*(u8 **)(p + 8), 1, 1);
    } else {
        func_021C66B8(*(u8 **)(p + 8), 0, 1);
        func_021C66B8(*(u8 **)(p + 8), 1, 0);
    }
    func_021C5C00(p);
    return 9;
}
