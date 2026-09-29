/*
 * function: func_021A5928
 * address:  0x021A5928
 * packet:   pkt_ov021_021A5928
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D5A0  0x0216D5A0  thumb  ov010
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_0216E0AC  0x0216E0AC  thumb  ov010
 *   func_0219E348  0x0219E348  thumb  ov021
 *   func_0219E2C0  0x0219E2C0  thumb  ov021
 *   d_021DDEE0     0x021DDEE0  data  a4
 *   d_021DDEE0b    0x021DDEE0  data  a4
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;

extern u16  d_021DDEE0[2];
extern u16  d_021DDEE0b[2];

extern int func_0216D5A0(int o);
extern u16 func_0216D598(int o);
extern void func_0216E0AC(int o, void *d);
extern int func_0219E348(int o);
extern void func_0219E2C0(int o, int v);

void func_021A5928(u8 *p, int v)
{
    if (func_0216D5A0(*(int *)(p + 0x1c)) != 0x45) {
        d_021DDEE0[1] = func_0216D598(*(int *)(p + 0x1c));
        func_0216E0AC(*(int *)(p + 0x1c), d_021DDEE0b);
    }
    *(int *)(p + 0x20) = func_0219E348(*(int *)(p + 0x1c));
    func_0219E2C0(*(int *)(p + 0x1c), v);
}
