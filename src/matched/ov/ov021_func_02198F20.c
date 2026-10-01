/*
 * function: func_02198F20
 * address:  0x02198F20
 * packet:   pkt_ov021_02198F20
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Promoted 2026-10-01: the arm9 leaf func_020508EC is now filed EXACT
 * (src/matched/arm9/func_020508EC.c), which witnesses the call.
 *
 * symbols:
 *   func_0216D6D4  0x0216D6D4  thumb  ov010
 *   func_0216D7A8  0x0216D7A8  thumb  ov010
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D520  0x0216D520  thumb  ov010
 *   func_0219C9DC  0x0219C9DC  thumb  ov021
 *   func_020508EC  0x020508EC  arm
 *   func_0216D7CC  0x0216D7CC  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0216D6D4(u32);
extern u32 func_0216D7A8(u32, u32);
extern u32 func_0216D67C(u32);
extern u32 func_0216D520();
extern u32 func_0219C9DC();
extern u32 func_020508EC(u32, u32, u16 *);
extern u32 func_0216D7CC(u32);

int func_02198F20(u32 a)
{
    u32 r;
    u16 out;

    func_0216D6D4(a);
    r = func_0216D7A8(a, 0);
    if (r != 0xFFFF) {
        func_0216D67C(a);
        func_0216D520();
        if (func_020508EC(func_0219C9DC(), (u16)r, &out) == 1) {
            func_0216D7CC(a);
            return 1;
        }
    }
    return 0;
}
