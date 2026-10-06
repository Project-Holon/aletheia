/*
 * function: func_021B6AFC
 * address:  0x021B6AFC
 * packet:   pkt_ov021_021B6AFC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A6C4  0x0215A6C4  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158F78  0x02158F78  thumb  ov010
 *   func_02158F7C  0x02158F7C  thumb  ov010
 *   func_0215A5D0  0x0215A5D0  thumb  ov010
 *   func_021B6AB0  0x021B6AB0  thumb
 *   func_021B6AA4  0x021B6AA4  thumb
 *   func_0215A7F0  0x0215A7F0  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_0215A6C4(void *);
extern void *func_0215A5F4(void *p);
extern u32 func_02158F78(u8 *p);
extern u32 func_02158F7C(u8 *p);
extern u16 func_0215A5D0(void *);
extern int func_021B6AB0(void *a);
extern u16 *func_021B6AA4(void *, u32);
struct U16Vec;
extern void func_0215A7F0(unsigned short *p, int a, int b, int c, struct U16Vec *s0, void *s1);

u32 func_021B6AFC(void *a, void *b)
{
    void *tab = func_0215A6C4(b);
    void *r4 = func_0215A5F4(b);
    int s0c = func_02158F78(r4);
    int s8 = func_02158F7C(r4);
    u16 id = func_0215A5D0(b);
    u32 n = func_021B6AB0(tab);
    u32 i = 0;

    for (; i < n; i++) {
        u16 *e = func_021B6AA4(tab, i);

        if (id != e[1])
            func_0215A7F0(b, e[0], 0xffff, i, (struct U16Vec *)s0c, (void *)s8);
    }
    return 0;
}
