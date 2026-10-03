/*
 * function: func_021C8100
 * address: 0x021C8100
 * packet: pkt_ov128_021C8100
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02035C08 0x02035C08 arm
 *   func_021CA294 0x021CA294 thumb ov128
 *   func_021C7E78 0x021C7E78 thumb ov128
 *   d_021CA5FC 0x021CA5FC data a1
 */
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
extern int func_02035C08(const void *);
typedef unsigned char  u8;
extern void func_021CA294(u8 *p, int a);
extern int func_021C7E78(s16 *p, u8 *a, void *b, int n);
extern const unsigned char d_021CA5FC[];
int func_021C8100(s16 *p, void *a, void *b, int *changed)
{
    u32 v = func_02035C08(d_021CA5FC);
    s8 delta;
    if (v == (u32)-1) return 0;
    if (v <= 7) {
        *changed = 1;
        func_021CA294(b, p[2]);
        p[2] = v;
        return func_021C7E78(p, a, b, 5);
    }
    if (v == 8) {
        *changed = 1;
        p[2] = v;
        return func_021C7E78(p, a, b, 5);
    }
    if (v == 9) {
        *changed = 1;
        p[2] = v;
        return func_021C7E78(p, a, b, 5);
    }
    delta = (v - 10) - p[0];
    if (delta != 0) {
        *changed = 1;
        p[1] = p[0];
        p[0] += delta;
        if (delta >= 0) {
            p[0] %= 4;
            return func_021C7E78(p, a, b, 2);
        } else {
            if (p[0] < 0) p[0] += 4;
            return func_021C7E78(p, a, b, 1);
        }
    }
    return 0;
}
