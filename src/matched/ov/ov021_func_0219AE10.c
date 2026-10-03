/*
 * function: func_0219AE10
 * address:  0x0219AE10
 * packet:   pkt_ov021_0219AE10
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D5A8  0x0216D5A8  thumb  ov010
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D63C  0x0216D63C  thumb  ov010
 *   func_021AE198  0x021AE198  thumb  ov021
 *   func_02197E7C  0x02197E7C  thumb  ov021
 *   func_0216D438  0x0216D438  thumb  ov010
 *   func_0216DA44  0x0216DA44  thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern int func_0216D5A8(u32);
extern u32 func_0216D5F8(u32);
extern u32 func_0216D63C(u32, u32);
extern int func_021AE198(int a, int b, int c, int d);
extern int func_02197E7C(int a, int b);
extern void func_0216D438(int a0, int a1);
extern void func_0216DA44(u32);

int func_0219AE10(u32 a, u8 *b)
{
    u32 c;
    if (func_0216D5A8(a) == 10) {
        c = func_0216D5F8(a);
        if (func_021AE198(a, c, func_0216D63C(a, 0), 0) != -1) {
            func_0216D438(a, func_02197E7C(c, 0x30));
            func_0216DA44(a);
            b[0] = 1;
            return 1;
        }
    }
    b[0] = 2;
    return 1;
}
