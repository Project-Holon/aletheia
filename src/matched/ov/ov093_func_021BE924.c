/*
 * function: func_021BE924
 * address:  0x021BE924
 * packet:   pkt_ov093_021BE924
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021CC8D8  0x021CC8D8  thumb  ov093
 *   func_021BE95C  0x021BE95C  thumb  ov093
 *   func_021CC95C  0x021CC95C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u32 func_021CC8D8(void *lock, int line);
extern void func_021BE95C(u8 *p, u8 *a, u32 v);
extern void func_021CC95C(void *lock, u32 v, int line);

void func_021BE924(u8 *p, u8 *a, u32 v)
{
    u32 s = func_021CC8D8(p + 0x1D74, 3985);
    func_021BE95C(p, a, v);
    func_021CC95C(p + 0x1D74, s, 3987);
}
