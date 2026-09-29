/*
 * function: func_021A5264
 * address:  0x021A5264
 * packet:   pkt_ov021_021A5264
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D854  0x0216D854  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_021641E8  0x021641E8  thumb  ov010
 *   func_021641F8  0x021641F8  thumb  ov010
 *   func_02163994  0x02163994  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_02164208  0x02164208  thumb  ov010
 *   func_02163E34  0x02163E34  thumb  ov010
 *   func_021AB0F0  0x021AB0F0  thumb  ov021
 *   func_021AB2DC  0x021AB2DC  thumb  ov021
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216E5B0  0x0216E5B0  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_0216D83C(u32);
extern int func_0216D854(u32);
extern int func_0216D86C(u32);
extern int func_021641E8(u32);
extern int func_021641F8(u32);
extern int func_02163994(u32, int, int, int, u32);
extern void func_0216D88C(u32, int *);
extern void func_02164208(u32, int *, u32);
extern int func_02163E34(u32, int *, int *);
extern void func_021AB0F0(int);
extern int func_021AB2DC(void);
extern u32 func_0216D67C(u32);
extern int func_0216E5B0(u32, int *);

int func_021A5264(u32 a, u32 b, u32 c, int *d)
{
    int buf[3];
    int s2;
    int s1;
    int r4;
    int r3;
    r4 = func_0216D83C(b);
    s1 = func_0216D854(b);
    s2 = func_0216D86C(b);
    r4 = (short)(r4 + func_021641E8(c));
    r3 = (short)(s2 + func_021641F8(c));
    r4 = func_02163994(b, r4, s1, r3, c);
    func_0216D88C(b, buf);
    func_02164208(c, buf, 0x10000);
    if (func_02163E34(b, buf, d) == 0) {
        *d = -1;
    }
    if (r4 & 2) {
        func_021AB0F0(*d);
        if (func_021AB2DC() == 1) {
            if (func_0216E5B0(func_0216D67C(b), buf) == 1) {
                r4 &= ~2;
            }
        }
    }
    return r4;
}
