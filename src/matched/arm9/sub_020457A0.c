/*
 * unit:     no
 * address:  0x020457A0
 * packet:   pkt_020452E8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * function: STRBUF_SetEosChar
 *
 * symbols:
 *   g_020A7E7C  0x020A7E7C  data
 *
 * Setter for the allocator family's global u16 stamp at 0x020A7E7C: the
 * value every object of this family copies into its own +0x8 field when
 * it is constructed (STRBUF_Create) or reset (STRBUF_Clear). Those two
 * functions are its readers, and their literal pools at 0x02045804 and
 * 0x02045834 are the outside witnesses for this file's own pool word,
 * which is why the three are kept in separate files rather than folded
 * into one unit: a single tu over 0x020457A0..0x02045838 would swallow
 * every pool copy of the address and cap at MATCH
 * (docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md).
 *
 * 0x020A7E7C sits immediately before the __FILE__ string at 0x020A7E80
 * that STRBUF_Create passes to the allocator, so it is the last word of
 * data before the packed string area.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/STRBUF_SetEosChar.c \
 *       --func STRBUF_SetEosChar --addr 0x020457A0 --cc 1.1p1 --arm
 */

#include "../include/G_AllocStamp.h"

typedef unsigned short u16;

/*
 * The global based at 0x020A7E7C is one small object, not two independent
 * words: STRBUF_Create loads 0x020A7E80 out of a pool as the allocator's
 * fourth argument, and that word is this symbol plus four
 * (docs/idioms/pool-base-for-a-far-field-is-the-symbol-offset-masked-by-the-load-reach.md).
 * Reading it as a separate object splits one symbol into two and loses
 * the relocation: 0x020A7E80 has exactly one pool reference image-wide
 * and so no witness of its own, while the base has thirty-six.
 */

extern struct AllocStamp g_020A7E7C;

void STRBUF_SetEosChar(u16 stamp)
{
    g_020A7E7C.value = stamp;
}
