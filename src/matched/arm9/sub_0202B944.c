/*
 * unit:     no
 * function: ISS_3DS_SYS_ClearTable
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
 *   python tools/match.py one --src src/matched/ISS_3DS_SYS_ClearTable.c \
 *       --func ISS_3DS_SYS_ClearTable --addr 0x0202B944 --cc 1.1p1 --thumb
 */
#include "../include/Obj01019.h"

typedef unsigned char u8;
typedef unsigned int u32;

void ISS_3DS_SYS_ClearTable(void *obj)
{
    ((struct Obj01019 *)obj)->f264 = 0;
    ((struct Obj01019 *)obj)->f268 = 0;
    ((struct Obj01019 *)obj)->f269 = 0xff;
}
