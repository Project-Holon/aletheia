/*
 * unit:     no
 * function: sub_0202B944
 * address:  0x0202B944
 * packet:   pkt_0202B7D4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * A three-field initialiser on a far offset (0x264): a word cleared, a byte
 * cleared right after it, and a byte set to 0xff two past that. The offset
 * is past the Thumb ldr/str immediate reach, so the compiler computes the
 * base with a shift instead of an immediate, which is ordinary codegen for
 * a field this far out rather than anything hand written. No relocation.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202B944.c \
 *       --func sub_0202B944 --addr 0x0202B944 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;

void sub_0202B944(void *obj)
{
    *(u32 *)((char *)obj + 0x264) = 0;
    *(u8 *)((char *)obj + 0x268) = 0;
    *(u8 *)((char *)obj + 0x269) = 0xff;
}
