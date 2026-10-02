/*
 * function: func_02188D5C
 * address:  0x02188D5C
 * packet:   pkt_ov021_02188D5C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203F8F4  0x0203F8F4  arm
 *   func_02040E78  0x02040E78  arm
 *   func_0204363C  0x0204363C  arm
 *   func_0204361C  0x0204361C  arm
 *   d_021D3620     0x021D3620  data
 */

typedef unsigned short u16;
typedef unsigned int   u32;

#define REG_DISPCNT (*(volatile u32 *)0x04000000)

extern u16 d_021D3620[];
extern void func_0203F8F4(u16 heap);
extern void func_02040E78(u32 a, void *b, u32 c, u32 d);
extern void func_0204363C(int a);
extern void func_0204361C(void);

void func_02188D5C(u16 *p)
{
    func_0203F8F4(p[0]);
    func_02040E78(0, d_021D3620, 0x20, 0);
    func_02040E78(4, d_021D3620, 0x20, 0);
    func_0204363C(1);
    func_0204361C();
    REG_DISPCNT &= ~0xE000;
}
