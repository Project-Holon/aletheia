/*
 * function: func_0219E498
 * address:  0x0219E498
 * packet:   pkt_ov021_0219E498
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D530  0x0216D530  thumb  ov010
 *   func_021BB480  0x021BB480  thumb  ov021
 *   func_021B7D38  0x021B7D38  thumb  ov021
 *   func_021B7C38  0x021B7C38  thumb  ov021
 *   func_0207C768  0x0207C768  arm
 *   func_0216DD1C  0x0216DD1C  thumb  ov010
 *   func_0216D55C  0x0216D55C  thumb  ov010
 *   func_0219E348  0x0219E348  thumb  ov021
 *   func_021B8040  0x021B8040  thumb  ov021
 *   func_021B8038  0x021B8038  thumb  ov021
 *   func_021B7E60  0x021B7E60  thumb  ov021
 *   func_021B7ED4  0x021B7ED4  thumb  ov021
 *   func_021B83B0  0x021B83B0  thumb  ov021
 * Addresses are Black-image addresses.
 * EXACT* is the 2-byte alignment pad after the last pop.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_0216D67C();
extern u32 func_0216D530();
extern u32 func_021BB480();
extern void func_021B7D38();
extern u32 func_021B7C38();
extern u32 func_0207C768();
extern int func_0216DD1C();
extern int func_0216D55C();
extern u32 func_0219E348();
extern int func_021B8040();
extern u32 func_021B8038();
extern void func_021B7E60();
extern void func_021B7ED4();
extern int func_021B83B0();

int func_0219E498(u32 o, u32 k)
{
    u32 t;
    u32 h;
    u32 m;
    u8 rec[12];
    u8 tA[12];
    u32 cur;
    u32 st;
    u32 lim;
    u32 s;
    int z;

    s = func_0216D67C(o);
    h = func_021BB480(func_0216D530(s));
    st = 0;
    func_021B7D38(h, k, rec);
    m = func_0207C768(func_021B7C38(h), 0x4000);
    while (func_0216DD1C(s, &cur, &st) == 1) {
        lim = 0x4000 >> 1;
        if (cur == o) {
            continue;
        }
        if (func_0216D55C(cur, 0x80) != 0) {
            continue;
        }
        z = (func_0216D55C(cur, lim) == 0);
        if (!z) {
            t = func_0219E348(cur);
            if (func_021B8040(t)) {
                func_021B7E60(t, func_021B8038(t), 0, tA);
                if (func_021B83B0(rec, tA, m)) {
                    return 1;
                }
            }
            func_021B7ED4(t, tA);
            if (func_021B83B0(rec, tA, m)) {
                return 1;
            }
        }
    }
    return 0;
}
