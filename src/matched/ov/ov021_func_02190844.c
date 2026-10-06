/*
 * function: func_02190844
 * address:  0x02190844
 * packet:   pkt_ov021_02190844
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02190590  0x02190590  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

typedef struct Slot {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u8  f20;
} Slot;

extern void func_02190590(struct Slot *s, int x, int y, u32 z);

void func_02190844(Slot **p, int x, int y, u32 z)
{
    func_02190590(p[1], (u16)(x + 8), y, z);
}
