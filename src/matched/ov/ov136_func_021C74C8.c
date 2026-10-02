/*
 * function: func_021C74C8
 * address:  0x021C74C8
 * packet:   pkt_ov136_021C74C8
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0            0x020307B0  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;
struct Bf7 {
    u8 v : 7;
    u8 w : 1;
};
extern void func_020307B0(void *);
int func_021C74C8(u8 *p)
{
    u8 *q = *(u8 **)(p + 0x10);
    ((struct Bf7 *)(p + 0x21))->v = *(u32 *)(q + 0x3C);
    p[0x20] = *(u32 *)(q + 0x40);
    func_020307B0(q);
    return 0;
}
