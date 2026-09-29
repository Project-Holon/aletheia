/*
 * function: func_021B3B14
 * address:  0x021B3B14
 * packet:   pkt_ov021_021B3B14
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B3B14 0x021B3B14 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_020457B0 0x020457B0 arm
 *   func_0203101C 0x0203101C arm
 *   func_02045EC0 0x02045EC0 arm
 */

typedef unsigned short u16;

extern void *func_02045B38(int, int, int, int);
extern void *func_0201EC64(int);
extern void *func_020457B0(int, int);
extern void *func_0203101C(int, int, int, int);
extern void *func_02045EC0(void *, int);

int func_021B3B14(char *p, int a)
{
    *(void **)(p + 392) = func_02045B38(0, 3, 423, *(u16 *)(p + 4));
    *(void **)(p + 396) = func_02045B38(0, 2, 53, *(u16 *)(p + 4));
    *(void **)(p + 400) = func_0201EC64(*(u16 *)(p + 4));
    *(void **)(p + 408) = func_020457B0(200, *(u16 *)(p + 4));
    *(void **)(p + 436) = func_0203101C(*(u16 *)(p + 4), *(u16 *)(p + 4), 32, 32);
    *(void **)(p + 412) = func_02045EC0(*(void **)(p + 392), 29);
    return a;
}
