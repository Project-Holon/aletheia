/*
 * function: func_0219E570
 * address:  0x0219E570
 * packet:   pkt_ov021_0219E570
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D530  0x0216D530  thumb  ov010
 *   func_021BB480  0x021BB480  thumb  ov021
 *   func_021B7D38  0x021B7D38  thumb  ov021
 *   func_021B7C38  0x021B7C38  thumb  ov021
 *   func_0207C768  0x0207C768  arm
 *   func_0216DD1C  0x0216DD1C  thumb  ov010
 *   func_0216D55C  0x0216D55C  thumb  ov010
 *   func_0219E334  0x0219E334  thumb  ov021
 *   func_021B83B0  0x021B83B0  thumb  ov021
 *   func_0219E2F4  0x0219E2F4  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_0216D530();
extern u32 func_021BB480();
extern void func_021B7D38();
extern u32 func_021B7C38();
extern u32 func_0207C768(u32 a, u32 b);
extern int func_0216DD1C();
extern int func_0216D55C(int a0, int a1);
extern void func_0219E334();
extern int func_021B83B0();
extern void func_0219E2F4();

u32 func_0219E570(u32 o, u32 k, u32 flag)
{
    u32 h;
    u32 m;
    u8 rec[12];
    u8 buf[12];
    u32 st;
    u32 cur;
    u8 tB[8];
    u8 tA[8];
    u32 lim;
    int z;

    st = 0;
    h = func_021BB480(func_0216D530(o));
    func_021B7D38(h, k, rec);
    m = func_0207C768(func_021B7C38(h), 0x4000);
    while (func_0216DD1C(o, &cur, &st) == 1) {
        lim = 0x4000 >> 1;
        z = (func_0216D55C(cur, lim) == 0);
        if (!z) {
            if (flag) {
                func_0219E334(cur, tB);
                func_021B7D38(h, tB, buf);
                if (func_021B83B0(rec, buf, m)) {
                    return cur;
                }
            }
            func_0219E2F4(cur, tA);
            func_021B7D38(h, tA, buf);
            if (func_021B83B0(rec, buf, m)) {
                return cur;
            }
        }
    }
    return 0;
}
