/*
 * function: func_021AC3A4
 * address:  0x021AC3A4
 * packet:   pkt_ov021_021AC3A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216E1C4  0x0216E1C4  thumb  ov010
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D98C  0x0216D98C  thumb  ov010
 *   func_0216DAB4  0x0216DAB4  thumb  ov010
 *   func_0216D57C  0x0216D57C  thumb  ov010
 *   func_021AC154  0x021AC154  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_0216E1C4(u32 a, u32 *b);
extern u32 func_0216D67C(u32 a);
extern int func_0216D98C(int a0);
extern int func_0216DAB4(u32 a);
extern u32 func_0216D57C(u32 a, u32 b);
extern void func_021AC154(u32 a);

void func_021AC3A4(u32 a, u32 *b)
{
    if (func_0216E1C4(b[2], b + 3) == 0) {
        func_021AC154(a);
        return;
    }
    if (func_0216D98C(func_0216D67C(b[2])) == 0) {
        func_021AC154(a);
        return;
    }
    if (func_0216DAB4(b[2]) == 1 || func_0216D57C(b[2], 0x8000) != 0)
        b[0] = 1;
    else
        b[0] = 0;
}
