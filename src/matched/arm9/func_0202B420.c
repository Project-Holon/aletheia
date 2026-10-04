/*
 * function: func_0202B420
 * address:  0x0202B420
 * packet:   pkt_0202B1F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * A four-byte setter for the halfword at +0x12.  Unlabelled in the listing
 * (it saves nothing and is chased by a linker thunk at 0x0202B424), absent
 * from the worklist, and filed straight from the bytes.  It is the blocker of
 * src/pending/func_0202B7C8.c, which reaches it through a pool word and so
 * has no other witness.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B420.c \
 *       --func func_0202B420 --addr 0x0202B420 --thumb --cc 1.1p1
 */
#include "../include/Obj15835.h"

typedef unsigned char  u8;
typedef unsigned short u16;

void func_0202B420(u8 *p, u16 v)
{
    ((struct Obj15835 *)p)->f12 = v;
}
