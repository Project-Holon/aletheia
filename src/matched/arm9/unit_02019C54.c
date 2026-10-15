/*
 * unit:     yes
 * address:  0x02019C54
 * packet:   pkt_02019C38
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: POKE_TOOL_GetPersonalData
 *
 * A one-entry memo: the (a, b) key pair at 0x02146270 and the 0x10 byte
 * object built for it at 0x02146274, rebuilt through POKE_PERSONAL_LoadData
 * (src/matched/unit_0201ADA4.c) only when the key changes.  POKE_TOOL_GetPersonalParam in
 * src/matched/unit_02019C7C.c is its only caller.
 *
 * Two things pin the source.
 *
 * The guard is one `||` expression rather than two ifs, which is what puts
 * both stores and the call in one block, per
 * docs/idioms/disjunction-must-be-one-expression-to-share-its-exit.md; and the
 * arm that falls through the first `bne` is the second half of the
 * disjunction, not the body.
 *
 * The two pool words 0x02146270 and 0x02146274 are one symbol and an addend,
 * per docs/idioms/pool-base-for-a-far-field-is-the-symbol-offset-masked-by-the-load-reach.md.
 * Declared as two symbols, 0x02146274 would need a witness of its own and the
 * only word in the image that holds it is the one under test.
 *
 * The neighbour POKE_TOOL_GetBoxSubstruct at the head of this packet is byte-correct but
 * MATCH-capped on its private table and is parked in
 * src/pending/sub_02019C38.c; this range is cut to exclude it.
 *
 * symbols:
 *   gPersonalCache   0x02146270  data
 *   POKE_PERSONAL_LoadData  0x0201ADA4  thumb
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02019C54.c \
 *       --addr 0x02019C54 --thumb
 */

#include "../include/G_Memo.h"

typedef unsigned short u16;
typedef unsigned char  u8;
typedef unsigned int   u32;

extern struct Memo gPersonalCache;

extern void POKE_PERSONAL_LoadData(u32 a, int b, void *dest);

void *POKE_TOOL_GetPersonalData(u32 a, u32 b)
{
    if (a != gPersonalCache.a || b != gPersonalCache.b) {
        gPersonalCache.b = (u16)b;
        gPersonalCache.a = (u16)a;
        POKE_PERSONAL_LoadData(a, b, gPersonalCache.obj);
    }
    return gPersonalCache.obj;
}
