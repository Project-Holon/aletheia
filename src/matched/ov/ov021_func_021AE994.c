/*
 * function: func_021AE994
 * address:  0x021AE994
 * packet:   pkt_ov021_021AE994
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021AE430  0x021AE430  thumb  ov021
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_02159124  0x02159124  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct R { u8 pad[0x14]; u32 f14; u32 f18; } R;

extern u32 func_0215A5F4(u32 a);
extern u32 func_0215A5DC(u32 a);
extern R *func_02159124(u32 a, u32 b);
extern u32 func_021AE430(u32 a, u32 x, u32 y);
extern void func_0215897C(u32 a, u32 b);

int func_021AE994(u32 a, u32 b)
{
    u32 x = func_0215A5F4(b);
    R *p = func_02159124(x, 0);
    R *q = func_02159124(x, 1);

    func_0215897C(x, func_021AE430(func_0215A5DC(b), p->f18, q->f18));
    return 1;
}
