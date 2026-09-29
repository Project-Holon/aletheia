/*
 * function: func_0218B6F8
 * address:  0x0218B6F8
 * packet:   pkt_ov021_0218B6F8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021A3074  0x021A3074  thumb
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_021641E8  0x021641E8  thumb  ov010
 *   func_021641F8  0x021641F8  thumb  ov010
 *   func_02188C7C  0x02188C7C  thumb
 *   func_0216DDC0  0x0216DDC0  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef signed short   s16;

extern void *func_021A3074(void *p);
extern int func_0216D83C(void *o);
extern int func_0216D86C(void *o);
extern int func_021641E8(u16 d);
extern int func_021641F8(u16 d);
extern void *func_02188C7C(void *q);
extern int func_0216DDC0(void *c, int x, int z, int a);

int func_0218B6F8(char *p, void *q)
{
    void *o = func_021A3074(*(void **)(p + 0x18));
    u16 d = *(u16 *)(p + 0x30);
    int x = func_0216D83C(o);
    int z = func_0216D86C(o);
    int i;

    for (i = 0; i < 2; i++) {
        x = (s16)(x + func_021641E8(d));
        z = (s16)(z + func_021641F8(d));
        if (func_0216DDC0(func_02188C7C(q), x, z, 1))
            return 0;
    }
    return 1;
}
