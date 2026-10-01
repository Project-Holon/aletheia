/*
 * function: func_02190F64
 * address:  0x02190F64
 * packet:   pkt_ov021_02190F64
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02190DCC  0x02190DCC  thumb  ov021
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

extern void *func_02190DCC(Fx *a, u32 b, u32 c, u32 d, u16 e, u16 f);

void func_02190F64(Fx *a, u32 b)
{
    func_02190DCC(a, b, 1, 0x13, 0x1E, 4);
}
