/*
 * function: sub_02045180
 * address:  0x02045180
 * packet:   pkt_020445F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 *
 * status:   EXACT
 * closed:   blocker func_0203FAF0 is now a manifest entry (matched class)
 *
 * symbols:
 *   func_0204169C  0x0204169C  arm
 *   func_0203FAF0  0x0203FAF0  arm
 *   sub_02045210   0x02045210  arm
 *
 * Every concrete byte is right; the file is capped at MATCH by one
 * relocation site, the bl to func_0203FAF0 at +0x44.  Blocking evidence
 * class: none available.  0x0203FAF0 has exactly one witness image wide and
 * it is the call inside this very function (--suggest-split reports "the
 * whole range as one file is NOT viable", best partition 0 pieces), so no
 * cut of this range can attest it.  It unsticks the moment either
 * 0x0203FAF0 itself is taken EXACT (the `matched` class) or a second caller
 * of it turns up in another packet.
 *
 * The fixed-offset twin of sub_020450F0: the caller already knows where the
 * layer's character data goes, so func_0203FAF0 is asked to reserve that
 * offset (answering 0 on failure, not -1), the cell count is passed in units
 * rather than scaled to bytes, and the caller's own offset is what reaches
 * sub_02045210 as the seventh argument.
 *
 * The 8bpp test and the doubling of the unit count are identical to
 * sub_020450F0; only the missing `lsl #5` and the different failure
 * convention separate the two.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02045180.c \
 *       --func sub_02045180 --addr 0x02045180 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

extern u32 func_0204169C(u32 layer);
extern u32 func_0203FAF0(u32 layer, u32 offset, u32 units);
extern u32 sub_02045210(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d,
                        u32 offset, u32 is8bpp);

u32 sub_02045180(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u32 offset)
{
    u32 is8bpp;
    u32 units;

    if (func_0204169C(layer) == 0) {
        is8bpp = 0;
        units = tiles * c;
    } else {
        is8bpp = 1;
        units = tiles * c * 2;
    }

    if (func_0203FAF0(layer, offset, units) == 0)
        return 0;

    return sub_02045210(layer, a, b, tiles, c, d, offset, is8bpp);
}
