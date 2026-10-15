/*
 * unit:     no
 * address:  0x020308B8
 * packet:   pkt_020307E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * function: GFL_HEAP_ReadAllocSiteName
 *
 * Copies a block's allocation-site name out of its header into a caller
 * buffer and answers whether the name is plausible. A leaf: no prologue,
 * no relocations.
 *
 *   int GFL_HEAP_ReadAllocSiteName(u8 *dst, const char *src)
 *
 * Three passes, in this order:
 *
 *  1. Copy up to 0x12 bytes, stopping on the NUL, then NUL-terminate at
 *     the copied length. This is the read-back of what GFL_HEAP_StampAllocSite
 *     stamped, and it is the mirror image of that function's loop: there
 *     the terminator is stored and the length test comes after the store,
 *     here the test comes first and the terminator is written separately,
 *     which is why the buffer must be 0x13 bytes and not 0x12.
 *  2. Every byte must be printable ASCII, 0x20..0x7e. The `ldrb` here
 *     against the `ldrsb` of the copy loop is the whole signedness story:
 *     the source is `char` (signed by -char signed) and the destination is
 *     read back as `u8`, which is what makes `< 0x20` an unsigned `blo`.
 *  3. A name shorter than the full 0x12 bytes must contain a '.', i.e. it
 *     must look like a file name. A name that fills the field is accepted
 *     without the dot, since the dot may simply have been truncated away.
 *
 * An empty name is rejected before pass 2, and the zero it returns is the
 * same register the NUL-terminator store just materialised, which also
 * seeds the pass-2 index: one `mov r2, #0` doing three jobs.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_HEAP_ReadAllocSiteName.c \
 *       --func GFL_HEAP_ReadAllocSiteName --addr 0x020308B8 --cc 1.1p1 --arm
 */

typedef unsigned char u8;

int GFL_HEAP_ReadAllocSiteName(u8 *dst, const char *src)
{
    int len;
    int i;

    for (len = 0; len < 0x12; len++) {
        char c = src[len];
        if (c == 0) {
            break;
        }
        dst[len] = c;
    }
    dst[len] = 0;
    if (len == 0) {
        return 0;
    }
    for (i = 0; i < len; i++) {
        u8 c = dst[i];
        if (c < 0x20 || c > 0x7e) {
            return 0;
        }
    }
    if (len < 0x12) {
        for (i = 0; i < len; i++) {
            if (dst[i] == '.') {
                break;
            }
        }
        if (i == len) {
            return 0;
        }
    }
    return 1;
}
