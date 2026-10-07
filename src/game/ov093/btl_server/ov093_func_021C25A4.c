/*
 * function: func_021C25A4
 * address:  0x021C25A4
 * packet:   pkt_ov093_021C25A4
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C8810  0x021C8810  thumb  ov093
 *   func_021C8828  0x021C8828  thumb  ov093
 *   func_021C99A0  0x021C99A0  thumb  ov093
 *   func_021C264C  0x021C264C  thumb  ov093
 *   func_021C26A8  0x021C26A8  thumb  ov093
 *   func_021C26FC  0x021C26FC  thumb  ov093
 *   func_021C2758  0x021C2758  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern void func_021C8810(u8 *lock);
extern u32 func_021C8828(u8 *p);
struct Msg;
extern int func_021C99A0(void *w, const struct Msg *m);
extern int func_021C264C(u8 *p, u8 *a, u8 *b, u32 c);
extern void func_021C26A8(u8 *p, u32 a, u8 *b, u8 *c, u32 d);
extern void func_021C26FC(u8 *p, u8 *a, u8 *b, u32 c, u32 *d);
extern int func_021C2758(u8 *p, u32 b, u32 a, u32 s0, u32 s1, u32 s2, u32 t);

int func_021C25A4(u8 *p, u32 a, u32 b, u32 unused, u32 s0, u32 s1, u32 s2)
{
    int t;
    func_021C8810(p + 0x1AE4);
    if (s0 == 0xFFFF) {
        s0 = func_021C264C(p, (u8 *)a, (u8 *)b, (u32)(p + 0x1AE4));
        if (s0 == 0 || s0 == 0xFFFF)
            return 0;
    } else {
        func_021C26A8(p, s0, (u8 *)a, (u8 *)b, (u32)(p + 0x1AE4));
    }
    func_021C26FC(p, (u8 *)a, (u8 *)b, s0, &s1);
    t = func_021C8828(p + 0x1AE4) ? 0 : 1;
    if (func_021C2758(p, b, a, s0, s1, s2, t) != 0) {
        if (t == 0) {
            func_021C99A0(p, (const struct Msg *)(p + 0x1AE4));
            func_021C8810(p + 0x1AE4);
        }
        return 1;
    }
    return 0;
}
