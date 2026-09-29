/*
 * function: func_02198C4C
 * address:  0x02198C4C
 * packet:   pkt_ov021_02198C4C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D6D4  0x0216D6D4  thumb  ov010
 *   func_02163FC0  0x02163FC0  thumb  ov010
 *   func_02164010  0x02164010  thumb  ov010
 *   func_0216D568  0x0216D568  thumb  ov010
 *   func_02163F10  0x02163F10  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_0216D7CC  0x0216D7CC  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern s16 *func_0216D6D4(u32);
extern u32 func_02163FC0(u32, u32, u32);
extern u32 func_02164010(u32);
extern u32 func_0216D568(u32, u32);
extern u32 func_02163F10(u32);
extern u32 func_0216D674(u32, u32);
extern u32 func_0216D7CC(u32);

int func_02198C4C(u32 a, u32 *b)
{
    s16 *p;

    p = func_0216D6D4(a);
    func_02163FC0(a, *(u16 *)p, b[p[3]]);
    func_02164010(a);
    p[3] = p[3] + 1;
    if (p[3] < p[2]) {
        return 0;
    }
    func_0216D568(a, 1088);
    func_02163F10(a);
    func_0216D674(a, 0);
    func_0216D7CC(a);
    return 1;
}
