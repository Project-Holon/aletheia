/*
 * function: func_021C5C64
 * address:  0x021C5C64
 * packet:   pkt_ov136_021C5C64
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021C5C64 0x021C5C64 thumb
 *   func_021C6028 0x021C6028 thumb
 *   func_0202CB4C 0x0202CB4C thumb
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed char s8;
struct WinMgr;
extern void func_021C6028(void *p, u32 a, u32 b, u32 c);
extern void func_0202CB4C(struct WinMgr *mgr, u32 idx, s8 x, s8 y);
void func_021C5C64(u8 *p)
{
    func_021C6028(p, 10, 0x16, p[0x1f]);
    func_0202CB4C(**(struct WinMgr ***)(p + 8), 10, 4, 7);
}
