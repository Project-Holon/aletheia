/*
 * function: func_02199ED4
 * address:  0x02199ED4
 * packet:   pkt_ov021_02199ED4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Former blocker (now filed in src/matched/arm9): func_020508EC (0x020508EC, arm9, unlabelled leaf, Ilias's).
 * Verified EXACT from a scratch file (region arm9, --arm, dsi/1.1p1 -O4,p):
 *
 *   u32 func_020508EC(u8 *p, int i, u16 *out)
 *   {
 *       u16 v = *(u16 *)(*(u8 **)(p + 0x18) + i * 40 + 0x1c);
 *       *out = v;
 *       return (u16)(v + 4 + 0xC000) <= 3;
 *   }
 *
 * symbols:
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D520  0x0216D520  thumb  ov010
 *   func_0219C9DC  0x0219C9DC  thumb  ov021
 *   func_0216D7A8  0x0216D7A8  thumb  ov010
 *   func_020508EC  0x020508EC  arm
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_0216D7CC  0x0216D7CC  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0216D67C(u32);
extern u32 func_0216D520(u32 p);
extern u32 func_0219C9DC(u32 p);
extern u32 func_0216D7A8(u32, u32);
extern u32 func_020508EC(u32, u32, u16 *);
extern u32 func_0216D5E0(u32, u32);
extern u32 func_0216D674(u32, u32);
extern u32 func_0216D7CC(u32);

int func_02199ED4(u32 a)
{
    u32 s;
    u32 r;
    u16 out;

    s = func_0219C9DC(func_0216D520(func_0216D67C(a)));
    r = func_0216D7A8(a, 0);
    if (r != 0xFFFF) {
        if (func_020508EC(s, (u16)r, &out) == 0) {
            return 0;
        }
    }
    func_0216D5E0(a, 1);
    func_0216D674(a, 0);
    func_0216D7CC(a);
    return 1;
}
