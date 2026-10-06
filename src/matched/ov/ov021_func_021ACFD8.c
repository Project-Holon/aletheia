/*
 * function: func_021ACFD8
 * address:  0x021ACFD8
 * packet:   pkt_ov021_021ACFD8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021ABE18  0x021ABE18  thumb  ov021
 *   func_021C67F4  0x021C67F4  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct Y { u8 pad[0x18]; u16 h18; u16 pad1a; u32 *f1c; u8 pad20[0x34]; u16 h54; } Y;

extern u32 func_021ABE18(u8 *p);
extern void func_021C67F4(u32 a, u32 b);

void func_021ACFD8(u32 a, Y *y)
{
    u32 h = func_021ABE18((u8 *)(*y->f1c));

    func_021C67F4(h, y->h18);
    func_021C67F4(h, y->h54);
}
