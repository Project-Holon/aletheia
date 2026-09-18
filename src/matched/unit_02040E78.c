/*
 * unit:     yes
 * function: func_02040E78, sub_02040EBC
 * address:  0x02040E78
 * packet:   pkt_02040DA8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DC_FlushRange    0x020862F0  arm
 *   GX_LoadBGPltt    0x0207E3D0  arm
 *   GXS_LoadBGPltt   0x0207E468  arm
 *
 * The palette upload and the two-byte convenience wrapper that calls it, as
 * one range 0x02040E78..0x02040EE0 (104 bytes, no gap and no padding).
 *
 * func_02040E78 flushes the source range and hands it to the main BG palette
 * loader for the first four banks and to the sub-engine one for the rest;
 * the `which` test is unsigned and the argument order is preserved into the
 * loader as (src, offset, size).
 *
 * sub_02040EBC takes the address of its second parameter, so its first
 * instruction is the four-register home-area push of
 * docs/idioms/address-of-a-register-parameter-is-a-push-of-all-four.md and
 * disasm.py labels it one instruction late, at 0x02040EC0; the `add sp, sp,
 * #0x10` after the popped frame is that home area being released.  Folding
 * the two functions into one unit is also what removes the `*` the single
 * function file carried, since the range now ends on the next label
 * (0x02040EE0) instead of running through an unlabelled follower.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02040E78.c  *       --addr 0x02040E78 --arm
 */

typedef unsigned int u32;

extern void DC_FlushRange(void *p, u32 size);
extern void GX_LoadBGPltt(const void *src, u32 offset, u32 size);
extern void GXS_LoadBGPltt(const void *src, u32 offset, u32 size);

void func_02040E78(u32 which, const void *src, u32 size, u32 offset)
{
    DC_FlushRange((void *)src, size);
    if (which < 4) {
        GX_LoadBGPltt(src, offset, size);
    } else {
        GXS_LoadBGPltt(src, offset, size);
    }
}

void sub_02040EBC(u32 which, u32 data, u32 a, u32 b)
{
    func_02040E78(which, &data, 2, 0);
}
