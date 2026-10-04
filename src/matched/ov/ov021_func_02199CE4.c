/*
 * function: func_02199CE4
 * address:  0x02199CE4
 * packet:   pkt_ov021_02199CE4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D6D4  0x0216D6D4  thumb  ov010
 *   func_0216D7CC  0x0216D7CC  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void *func_0216D6D4(void *p);
extern void func_0216D7CC(u32);

int func_02199CE4(u32 a)
{
    int *p = func_0216D6D4((void *)a);
    if (++*p >= 22) {
        func_0216D7CC(a);
    }
    return 0;
}
