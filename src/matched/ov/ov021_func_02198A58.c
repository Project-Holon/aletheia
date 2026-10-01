/*
 * function: func_02198A58
 * address:  0x02198A58
 * packet:   pkt_ov021_02198A58
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D6BC  0x0216D6BC  thumb  ov010
 *   func_020061E4  0x020061E4  thumb
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_0216D7CC  0x0216D7CC  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern u32 *func_0216D6BC(u32, u32);
extern void func_020061E4(u32);
extern void func_0216D674(u32, u32);
extern void func_0216D7CC(u32);

int func_02198A58(u32 a)
{
    u32 *p;

    p = func_0216D6BC(a, 8);
    p[0] = 0x140000;
    p[1] = 0xFFFF0000;
    func_020061E4(0x676);
    func_0216D674(a, 0);
    func_0216D7CC(a);
    return 1;
}
