/*
 * function: sub_020450F0
 * address:  0x020450F0
 * packet:   pkt_020445F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 *
 * status:   EXACT
 *
 * symbols:
 *   func_0204169C  0x0204169C  arm
 *   func_0203FA08  0x0203FA08  arm
 *   sub_02045210   0x02045210  arm
 *
 * Set up a BG layer whose character data is placed at a VRAM offset chosen
 * by the allocator.  func_0204169C says whether the layer is 8bpp; that
 * decides both the flag handed to sub_02045210 and whether a cell costs one
 * or two units, and the unit count is scaled by 32 to bytes before
 * func_0203FA08 is asked for room.  A returned -1 (not 0) is the allocator's
 * failure answer, and the function reports failure as 0.
 *
 * sub_02045180, the next function, is the same routine for the case where
 * the caller already knows the offset: it calls func_0203FAF0 to reserve
 * that exact offset instead, passes a count rather than a byte size, and
 * forwards the caller's offset straight through as sub_02045210's seventh
 * argument.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020450F0.c \
 *       --func sub_020450F0 --addr 0x020450F0 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned int   u32;
typedef signed int     s32;

extern u8 func_0204169C(int channel);
extern u32 func_0203FA08(u32 layer, u32 size, u32 top);
extern u32 sub_02045210(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d,
                        u32 offset, u32 is8bpp);

u32 sub_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot)
{
    u32 is8bpp;
    u32 units;
    s32 offset;

    if (func_0204169C(layer) == 0) {
        is8bpp = 0;
        units = tiles * c;
    } else {
        is8bpp = 1;
        units = tiles * c * 2;
    }

    offset = func_0203FA08(layer, units * 32, slot);
    if (offset == -1)
        return 0;

    return sub_02045210(layer, a, b, tiles, c, d, offset, is8bpp);
}
