/*
 * function: func_021C1E14
 * address:  0x021C1E14
 * packet:   pkt_ov093_021C1E14
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021CC8D8  0x021CC8D8  thumb  ov093
 *   func_021C78F4  0x021C78F4  thumb  ov093
 *   func_021C3370  0x021C3370  thumb  ov093
 *   func_021C334C  0x021C334C  thumb  ov093
 *   func_021CC95C  0x021CC95C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u32 func_021CC8D8(void *lock, int line);
extern u8 *func_021C78F4(u8 *p, u8 *q, u32 a, u32 b);
extern int func_021C3370(u8 *p, u8 *q);
extern int func_021C334C(u8 *p, u8 *q, u8 *t, int k);
extern void func_021CC95C(void *lock, u32 v, int line);

int func_021C1E14(u8 *p, u8 *q, u32 a, u32 b)
{
    u32 s = func_021CC8D8(p + 0x1D74, 7154);
    int r = 0;
    u8 *t = func_021C78F4(p, q, a, b);
    if (t) {
        if (func_021C3370(p, q) == 0) {
            r = func_021C334C(p, q, t, 1);
        }
    }
    func_021CC95C(p + 0x1D74, s, 7168);
    return r;
}
