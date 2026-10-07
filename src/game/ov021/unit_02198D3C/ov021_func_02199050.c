/*
 * function: func_02199050
 * address:  0x02199050
 * packet:   pkt_ov021_02199050
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D6D4  0x0216D6D4  thumb  ov010
 *   func_0216D7CC  0x0216D7CC  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern void *func_0216D6D4(void *p);
extern void func_0216D7CC(u8 *p);

int func_02199050(u32 a)
{
    u16 *p;

    p = func_0216D6D4((void *)a);
    p[0]++;
    if (p[0] >= p[1]) {
        func_0216D7CC((u8 *)a);
    }
    return 0;
}
