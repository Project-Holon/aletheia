/*
 * function: func_021AC62C
 * address:  0x021AC62C
 * packet:   pkt_ov021_021AC62C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021AC1AC  0x021AC1AC  thumb  ov021
 *   func_021ABE18  0x021ABE18  thumb  ov021
 *   func_021AC1CC  0x021AC1CC  thumb  ov021
 *   func_021C6590  0x021C6590  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 *func_021AC1AC(u32 a);
extern u32 func_021ABE18(u32 a);
extern void func_021AC1CC(u32 a, u32 *b);
extern u32 func_021C6590(u32 a, u32 b, u32 c, u32 *d);

void func_021AC62C(u32 a, u32 *b)
{
    u32 *p = func_021AC1AC(a);
    b[0] = p[0];
    b[1] = func_021ABE18(*(u32 *)b[0]);
    func_021AC1CC(a, p + 1);
    *(u16 *)(b + 2) = func_021C6590(b[1], *(u16 *)(b[0] + 4), 0, p + 1);
}
