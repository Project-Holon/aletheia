/*
 * function: func_021B57CC
 * address:  0x021B57CC
 * packet:   pkt_ov021_021B57CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Blocker: func_0201A354 (arm9, unlabelled leaf, Ilias's) has no witness
 * outside this range. Verified C for it (match.py one, EXACT, 16 bytes, Thumb):
 *   extern int func_02048F60();  (symbols: func_02048F60 0x02048F60 arm)
 *   int func_0201A354(int a, int b) { return func_02048F60(0x69, a, b); }
 *
 * symbols:
 *   func_0201A354  0x0201A354  thumb
 *   func_021B5824  0x021B5824  thumb  ov021
 *   func_0201EE60  0x0201EE60  thumb
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0201A354();
extern u16 *func_021B5824();
extern void func_0201EE60();
extern void func_020307B0();

u16 func_021B57CC(int a0, int a1, int a2, int a3)
{
    u16 n = 0;
    u16 i = 0;
    int t;
    u16 *v;

    t = func_0201A354(a2, a3);
    v = func_021B5824(t, a0, &n, a3);
    for (i = 0; i < n; i++) {
        func_0201EE60(a1, i, v[i]);
    }
    func_020307B0(v);
    func_020307B0(t);
    return n;
}
