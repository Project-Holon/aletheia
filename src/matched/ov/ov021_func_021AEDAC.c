/*
 * function: func_021AEDAC
 * address:  0x021AEDAC
 * packet:   pkt_ov021_021AEDAC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02014024  0x02014024  thumb
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct R { u32 f0; u32 f4; } R;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5E4(void *a0);
extern R *func_02158F58(u32 a);
extern u32 func_02012F2C(u32 a);
extern u32 func_02188C9C(u32 a);
extern int func_02014024(u32 a);
extern void func_02008DF0(u32 a, u32 b);

void func_021AEDAC(u32 a)
{
    R *p = func_02158F58(func_0215A5F4((void *)a));
    u32 q = func_02012F2C(func_0215A5E4((void *)a));

    if (func_02014024(func_02188C9C(p->f4)) != 0)
        func_02008DF0(q, 0x20);
}
