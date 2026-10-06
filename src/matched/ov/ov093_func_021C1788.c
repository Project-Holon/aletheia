/*
 * function: func_021C1788
 * address:  0x021C1788
 * packet:   pkt_ov093_021C1788
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021CC8D8  0x021CC8D8  thumb  ov093
 *   func_021C17CC  0x021C17CC  thumb  ov093
 *   func_021CC95C  0x021CC95C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u32 func_021CC8D8(void *lock, int line);
extern void func_021C17CC(u8 *p, u32 x, u8 *a, u32 n, u8 **arr);
extern void func_021CC95C(u32 *p, u32 v, int line);

void func_021C1788(u8 *p, u32 x, u8 *a, u32 n, u32 *arr)
{
    u32 s = func_021CC8D8(p + 0x1D74, 6697);
    func_021C17CC(p, x, a, n, (u8 **)arr);
    func_021CC95C((u32 *)(p + 0x1D74), s, 6702);
}
