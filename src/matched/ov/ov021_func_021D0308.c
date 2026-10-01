/*
 * function: func_021D0308
 * address:  0x021D0308
 * packet:   pkt_ov021_021D0308
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0204762C  0x0204762C  arm
 *   func_02047738  0x02047738  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_02047738(u32 a);
extern void func_0204762C(u32 a);

void func_021D0308(void *unused, u32 *p)
{
    int i;

    func_02047738(p[3]);
    for (i = 0; i < 4; i++) {
        func_0204762C(p[4 + i]);
    }
}
