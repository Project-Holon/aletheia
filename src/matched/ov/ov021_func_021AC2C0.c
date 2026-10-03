/*
 * function: func_021AC2C0
 * address:  0x021AC2C0
 * packet:   pkt_ov021_021AC2C0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021D9098  0x021D9098  data
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct Arg { u32 a; u32 b; } Arg;

extern int func_021ABEA0(u32 a, u32 b);
extern void func_021ABFA8(u32 a, u8 *b, u32 c, u32 d, Arg *e, u32 f);
extern u8 d_021D9098[];

void func_021AC2C0(u32 a, u32 b)
{
    Arg s;

    s.a = func_021ABEA0(b, 0);
    s.b = a;
    func_021ABFA8(b, d_021D9098, 0, 0, &s, 0);
}
