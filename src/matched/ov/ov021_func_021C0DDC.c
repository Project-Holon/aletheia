/*
 * function: func_021C0DDC
 * address:  0x021C0DDC
 * packet:   pkt_ov021_021C0DDC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C19B4  0x021C19B4  thumb  ov021
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_0216E5FC  0x0216E5FC  thumb  ov010
 *   func_021A5728  0x021A5728  thumb  ov021
 *   func_021A395C  0x021A395C  thumb  ov021
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_021C0D08  0x021C0D08  thumb  ov021
 *   func_021639C0  0x021639C0  thumb  ov010
 *   func_021C0E4C  0x021C0E4C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_021C19B4(u32 a, u32 b);
extern void func_0216D598(void);
extern int func_0216E5FC(void);
extern u32 func_021A5728(u32 a);
extern u32 func_021A395C(u32 a);
extern u32 func_02188C98(u32 a);
extern u32 func_021C0D08(u32 a, u32 b, u32 c);
extern u32 func_021639C0(u32 a, u32 b);
extern int func_021C0E4C(u32 a, u32 b, u32 c, u32 d);

int func_021C0DDC(u32 a, u32 b, int c)
{
    u32 r6;
    u32 r4;
    u32 f;

    if (c == 1) {
        r6 = func_021C19B4(a, b);
        if (r6 != 0) {
            func_0216D598();
            if (func_0216E5FC() == 1) {
                r4 = func_021C0D08(r6, b, func_02188C98(func_021A395C(func_021A5728(a))));
                f = func_021639C0(r6, b);
                f &= ~1;
                if ((f & 2) && r4 - 2 <= 1)
                    f &= ~2;
                if (f == 0) {
                    int k = 0;
                    if (r4 == 3)
                        k = 1;
                    return func_021C0E4C(a, b, r6, k);
                }
            }
        }
    }
    return 0;
}
