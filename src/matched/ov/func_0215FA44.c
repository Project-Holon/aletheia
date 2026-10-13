/*
 * function: SCRCMD_NETWORK_UnloadOv020
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
 *   GF_OVERLAY_Unload   0x02034A5C  arm
 *
 * Thumb tail call into the ARM GF_OVERLAY_Unload with the id 0x14, which the
 * original loads from its own pool rather than as `movs r0, #0x14`: the
 * pooled small constant is an absolute linker symbol
 * (docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md).
 * Unlabelled in the listing (no lr-saving prologue, callers only in arm9);
 * the pair with SCRCMD_NETWORK_LoadOv020 (same id, into GF_OVERLAY_Load).
 */

extern unsigned char abs_id_14[];
extern void GF_OVERLAY_Unload(int handle);

void SCRCMD_NETWORK_UnloadOv020(void)
{
    GF_OVERLAY_Unload((int)abs_id_14);
}
