/*
 * function: func_021991F0
 * address:  0x021991F0
 * packet:   pkt_ov021_021991F0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D6D4  0x0216D6D4  thumb  ov010
 *   func_02163F8C  0x02163F8C  thumb  ov010
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
extern int *func_0216D6D4(u32);
extern u32 func_02163F8C(u32, int *);
extern u32 func_0216D568(u32, u32);
extern u32 func_02163F10(u32);
extern u32 func_0216D674(u32, u32);
extern u32 func_0216D7CC(u32);

int func_021991F0(u32 a)
{
    int *p;

    p = func_0216D6D4(a);
    func_02163F8C(a, p + 1);
    p[0] = p[0] - 1;
    if (p[0] > 0) {
        return 0;
    }
    func_0216D568(a, 1088);
    func_02163F10(a);
    func_0216D674(a, 0);
    func_0216D7CC(a);
    return 1;
}
