/*
 * function: func_021C195C
 * address:  0x021C195C
 * packet:   pkt_ov093_021C195C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D5B40  0x021D5B40  thumb  ov093
 *   func_021CC8D8  0x021CC8D8  thumb  ov093
 *   func_021C199C  0x021C199C  thumb  ov093
 *   func_021CC95C  0x021CC95C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u16 func_021D5B40(void *p);
extern u32 func_021CC8D8(void *lock, int line);
extern void func_021C199C(u8 *p, u8 *q, u32 n);
extern void func_021CC95C(void *lock, u32 v, int line);

void func_021C195C(u8 *p, u8 *q, u32 n)
{
    if (func_021D5B40(q)) {
        u32 s = func_021CC8D8(p + 0x1D74, 6844);
        func_021C199C(p, q, n);
        func_021CC95C(p + 0x1D74, s, 6850);
    }
}
