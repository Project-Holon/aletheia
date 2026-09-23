/*
 * function: func_0215FA44
 * address:  0x0215FA44
 * packet:   pkt_0215FA34
 * region:   ov010
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocker:  +0008 ABS32 abs_id_14 (0x00000014): the pooled id has no witness;
 *           `literal` indexes only ARM9 pool_ words and none holds 0x14, and the
 *           twin thunk's pool word is an unlabelled ov010 .word.  Every other
 *           byte is right; the sub_0203xxxx pool word resolves on `label`.
 *           Its arm9 callers need an overlay_010 seed at this address instead.
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
extern void sub_02034A5C(const void *id);

void func_0215FA44(void)
{
    sub_02034A5C(abs_id_14);
}
