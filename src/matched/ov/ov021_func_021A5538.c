/*
 * function: func_021A5538
 * address:  0x021A5538
 * packet:   pkt_ov021_021A5538
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_0216D608  0x0216D608  thumb  ov010
 *   func_021A5264  0x021A5264  thumb  ov021
 *   func_021A550C  0x021A550C  thumb  ov021
 *   func_021A5354  0x021A5354  thumb  ov021
 *   func_021A3964  0x021A3964  thumb  ov021
 *   func_021A5328  0x021A5328  thumb  ov021
 *   func_02197E7C  0x02197E7C  thumb  ov021
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_0216D548  0x0216D548  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_021A3960(u32);
extern u32 func_0216D608(void);
extern int func_021A5264(u32, u32, u32, int *);
extern void func_021A550C(u32);
extern void func_021A5354(u32);
extern void func_021A3964(u32, u32);
extern void func_021A5328(u32);
extern u32 func_02197E7C(u32, u32);
extern void func_0216D410(u32, u32);
extern void func_0216D548(u32, u32);

int func_021A5538(u32 a)
{
    int v;
    u32 x = func_021A3960(*(u32 *)(a + 12));
    u32 y = func_0216D608();
    if (func_021A5264(a, x, y, &v) != 0) {
        func_021A550C(a);
        func_021A5354(a);
        func_021A3964(*(u32 *)(a + 12), 0);
        return 0;
    }
    func_021A5328(a);
    func_0216D410(x, func_02197E7C(y, 0x10));
    func_0216D548(x, 0x18);
    *(u32 *)a = 1;
    func_021A3964(*(u32 *)(a + 12), 1);
    return 1;
}
