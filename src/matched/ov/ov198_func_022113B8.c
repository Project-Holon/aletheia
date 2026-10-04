/*
 * function: func_022113B8
 * address: 0x022113B8
 * packet: pkt_ov198_022113B8
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Trailing 022113FA halfword is zero alignment padding, not a follower.
 * symbols:
 *   func_0204162C 0x0204162C arm
 *   func_02082A60 0x02082A60 arm
 *   func_0221139C 0x0221139C thumb ov198
 */
typedef unsigned char u8;
typedef unsigned int   u32;
extern u32 func_0204162C(int channel);
extern void func_02082A60(const void *, void *, unsigned);
extern void func_0221139C(u8 *, u8 *, unsigned);
void func_022113B8(u8 *dst, unsigned bg, unsigned which)
{
    u8 xy[2];
    u8 *src = (u8 *)func_0204162C(bg);
    u8 i;
    func_0221139C(&xy[1], &xy[0], which);
    for (i = 0; i < 6; i++) {
        func_02082A60(src + 2 * (xy[1] + ((xy[0] + i) << 5)), dst + (i << 5), 32);
    }
}
