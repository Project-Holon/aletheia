/*
 * function: sub_0204ADA4
 * address:  0x0204ADA4
 * packet:   pkt_0204ACEC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146A74   0x02146A74  data
 *
 * Reset one entry of the 0x18-byte table hanging off +0x110 of the
 * singleton at 0x02146A74: set the top bit of the word at +0x14 and clear
 * the other 31 bits under it.
 *
 * The two statements do not share one address computation, even though
 * there is no call between them: the `str` of the first statement may
 * alias the global pointer itself, so the compiler has to reload
 * g_02146A74 and re-index before the second
 * (docs/idioms/const-pointer-lets-a-field-load-survive-a-store.md, read
 * from the other side).  The index multiply is a real `mul` by a
 * register-held 0x18, not a shift pair, because 24 is not a power of two.
 *
 * `bic` immediately followed by `orr` with the same constant is the
 * bitfield-assignment shape, not a redundant pair: the field is cleared
 * and then the value inserted, and the value happening to be the constant
 * 1 does not collapse the two.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204ADA4.c \
 *       --func sub_0204ADA4 --addr 0x0204ADA4 --cc 1.1p1 --arm
 */

#include "../include/G_Mgr.h"

typedef unsigned char u8;
typedef unsigned int  u32;

struct Entry {
    u8  pad_00[0x14];
    u32 unk_14_0 : 31;
    u32 unk_14_31 : 1;
};

extern struct Mgr *g_02146A74;

void sub_0204ADA4(u32 i)
{
    ((struct Entry *)g_02146A74->owner_slots2)[i].unk_14_31 = 1;
    ((struct Entry *)g_02146A74->owner_slots2)[i].unk_14_0 = 0;
}
