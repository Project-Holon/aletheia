/*
 * function: func_02199D4C
 * address:  0x02199D4C
 * packet:   pkt_ov021_02199D4C
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
 *   func_02163F10  0x02163F10  thumb  ov010
 *   func_0216D7CC  0x0216D7CC  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void *func_0216D6D4(void *p);
extern void func_02163FC0(int a, int dir, int amt);
extern int func_02164010(int a);
extern u32 func_02163F10(u32);
extern u32 func_0216D7CC(u32);

int func_02199D4C(u32 a)
{
    s16 *p;

    p = func_0216D6D4((void *)a);
    func_02163FC0(a, (u16)((u32 *)p)[1], ((u32 *)p)[2]);
    func_02164010(a);
    p[1] = p[1] - 1;
    if (p[1] > 0) {
        return 0;
    }
    func_02163F10(a);
    func_0216D7CC(a);
    return 1;
}
