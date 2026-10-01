/*
 * function: func_021AD598
 * address:  0x021AD598
 * packet:   pkt_ov021_021AD598
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021D9170  0x021D9170  data
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct Arg { u32 f0; u32 f4; u32 f8; u32 fc; } Arg;

extern u32 func_021ABEA0(u32 a, u32 b);
extern void func_021ABFA8(u32 a, u8 *b, u32 c, u32 d, Arg *e, u32 f);
extern u8 d_021D9170[];

void func_021AD598(u32 a, u32 b, u32 c)
{
    Arg s;

    s.f4 = func_021ABEA0(a, 9);
    s.f8 = b;
    s.fc = 0;
    s.f0 = 1;
    func_021ABFA8(a, d_021D9170, c, 0, &s, 1);
}
