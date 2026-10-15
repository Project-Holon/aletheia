/*
 * function: BG_SYS_SetFlagField06
 * address:  0x02041B6C
 * packet:   pkt_020414C4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gUnk_02146A44  0x02146A44  data
 *
 * Sets one bit of the 16-bit request mask at +6 of the singleton reached
 * through the pointer at 0x02146A44.  The lsl #16 / lsr #16 pair is the
 * u16 truncation of `1 << bit`, not a mask written in the source.
 */

typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;

struct Unk02146A44 {
    u8  pad_00[6];
    u16 mask;
};

extern struct Unk02146A44 *gUnk_02146A44;

void BG_SYS_SetFlagField06(u32 bit)
{
    gUnk_02146A44->mask |= 1 << bit;
}
