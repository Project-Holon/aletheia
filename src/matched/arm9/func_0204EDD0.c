/*
 * function: BILLBOARD_GetImageSizeFromFlags
 * address:  0x0204EDD0
 * packet:   pkt_0204EA64
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Turn two bit groups of the flags word into one-hot halfwords, each store
 * guarded by its own null check.  The `asr` on the high group is the tell
 * that the flags word is signed (an unsigned group would be lsr), and the
 * first guard is a real branch while the second is folded into conditional
 * instructions because nothing follows it.
 *
 * Unlabelled in the current listings: the prologue saves nothing, so
 * disasm.py never auto-labelled it and the worklist's function list for this
 * packet does not carry it (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 * It starts at 0x0204EDD0 and its body ends at 0x0204EE0C.
 *
 * symbols:
 *   none (no external calls, no data references)
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed int     s32;

void BILLBOARD_GetImageSizeFromFlags(s32 flags, u16 *a, u16 *b)
{
    if (a != 0) {
        *a = (u16)(1 << (((flags & 0x70) >> 4) + 3));
    }
    if (b != 0) {
        *b = (u16)(1 << ((flags & 7) + 3));
    }
}
