/*
 * function: func_021AE9CC
 * address:  0x021AE9CC
 * packet:   pkt_ov021_021AE9CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02159124  0x02159124  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct R { u8 pad[0x14]; u32 f14; u32 f18; } R;

extern u32 func_0215A5F4(u32 a);
extern R *func_02159124(u32 a, u32 b);
extern u16 *func_02159AE8(u32 a, u32 b);

int func_021AE9CC(u32 a, u32 b)
{
    R *p = func_02159124(func_0215A5F4(b), 0);

    *func_02159AE8(a, b) = p->f14;
    return 0;
}
