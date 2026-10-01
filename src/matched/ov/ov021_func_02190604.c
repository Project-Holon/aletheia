/*
 * function: func_02190604
 * address:  0x02190604
 * packet:   pkt_ov021_02190604
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021905C8  0x021905C8  thumb  ov021
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

extern void func_021905C8(Slot *s, int x, int y, u32 z, u16 w, u32 v);

void func_02190604(Slot *s, int x, int y, u32 z, u16 w)
{
    func_021905C8(s, x, y, z, w, s->f08);
}
