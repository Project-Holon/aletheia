/*
 * function: func_0215FA44
 * address:  0x0215FA44
 * packet:   pkt_0215FA34
 * region:   ov010
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     wave 17 (overlay_id class): EXACT. The pooled overlay-id site
 *           abs_id_14 (20) resolves as `overlay_id` (a layout overlay index,
 *           loaded by a pc-relative load of this function, reaching the id
 *           register of a known overlay loader), which was the last blocker.
 *
 * symbols:
 *   abs_id_14      0x00000014  data
 *   sub_02034A5C   0x02034A5C  arm
 *
 * Thumb tail call into the ARM sub_02034A5C with the id 0x14, which the
 * original loads from its own pool rather than as `movs r0, #0x14`: the
 * pooled small constant is an absolute linker symbol
 * (docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md).
 * Unlabelled in the listing (no lr-saving prologue, callers only in arm9);
 * the pair with func_0215FA34 (same id, into sub_02034AC4).
 */

extern unsigned char abs_id_14[];
extern void sub_02034A5C(int handle);

void func_0215FA44(void)
{
    sub_02034A5C((int)abs_id_14);
}
