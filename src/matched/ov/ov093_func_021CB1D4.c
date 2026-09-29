/*
 * function: func_021CB1D4
 * address:  0x021CB1D4
 * packet:   pkt_ov093_021CB1D4
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021CC8D8  0x021CC8D8  thumb  ov093
 *   func_021CB274  0x021CB274  thumb  ov093
 *   func_021CC95C  0x021CC95C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u32 func_021CC8D8(void *lock, int line);
extern u8 func_021CB274(u8 *p, u8 *a, u8 *b, u32 d);
extern void func_021CC95C(void *lock, u32 v, int line);

u8 func_021CB1D4(u8 *p, u8 *a, u8 *b, u32 d)
{
    u32 s = func_021CC8D8(p + 0x1D74, 611);
    u8 r = func_021CB274(p, a, b, d);
    func_021CC95C(p + 0x1D74, s, 613);
    return r;
}
