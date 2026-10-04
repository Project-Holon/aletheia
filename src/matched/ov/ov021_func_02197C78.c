/*
 * function: func_02197C78
 * address:  0x02197C78
 * packet:   pkt_ov021_02197C78
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D4D4  0x0216D4D4  thumb  ov010
 *   func_0216DAA0  0x0216DAA0  thumb  ov010
 *   func_0216D758  0x0216D758  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern void *func_0216D67C(void *a0);
extern int func_0216D4D4(int a0, int a1);
extern int func_0216DAA0(void *a0);
extern void func_0216D758(void *a0);

void func_02197C78(u32 a)
{
    if (func_0216D4D4((int)func_0216D67C((void *)a), 4) == 0 && func_0216DAA0((void *)a) != 0) {
        func_0216D758((void *)a);
    }
}
