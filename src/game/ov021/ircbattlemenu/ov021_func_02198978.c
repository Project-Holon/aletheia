/*
 * function: func_02198978
 * address:  0x02198978
 * packet:   pkt_ov021_02198978
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D6D4 0x0216D6D4  thumb  ov010
 *   func_0216D7CC 0x0216D7CC  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern void *func_0216D6D4(void *p);
extern void func_0216D7CC(u8 *p);

int func_02198978(u32 a)
{
    int *p;

    p = (int *)func_0216D6D4((void *)a);
    if (*p != 0) {
        *p -= 1;
        return 0;
    }
    func_0216D7CC((u8 *)a);
    return 1;
}
