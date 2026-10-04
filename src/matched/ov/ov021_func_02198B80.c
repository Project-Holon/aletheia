/*
 * function: func_02198B80
 * address:  0x02198B80
 * packet:   pkt_ov021_02198B80
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D6D4  0x0216D6D4  thumb  ov010
 *   func_021BB5C8  0x021BB5C8  thumb  ov021
 *   func_021AC154  0x021AC154  thumb  ov021
 *   func_0216D7CC  0x0216D7CC  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern void *func_0216D6D4(void *p);
extern int func_021BB5C8(u32);
extern void func_021AC154(u32);
extern void func_0216D7CC(u8 *p);

int func_02198B80(u32 a)
{
    u32 *p;

    p = func_0216D6D4((void *)a);
    if (func_021BB5C8(p[1]) == 1) {
        func_021AC154(p[1]);
        func_0216D7CC((u8 *)a);
        return 1;
    }
    return 0;
}
