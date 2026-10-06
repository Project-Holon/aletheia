/*
 * function: func_021907A8
 * address:  0x021907A8
 * packet:   pkt_ov021_021907A8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02190708  0x02190708  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

typedef struct Fx {
    u16 f00;
    u16 f02;
    u16 f04;
    u16 f06;
} Fx;

extern void *func_02190708(struct Fx *p, u32 a, u16 b, u16 c, u16 d, u16 e);

void func_021907A8(Fx *p, u32 a)
{
    func_02190708(p, a, 1, 0x13, 0x1E, 4);
}
