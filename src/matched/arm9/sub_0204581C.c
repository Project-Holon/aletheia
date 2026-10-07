/*
 * unit:     no
 * address:  0x0204581C
 * packet:   pkt_020452E8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * function: sub_0204581C
 *
 * symbols:
 *   g_020A7E7C  0x020A7E7C  data
 *
 * Resets one of the allocator family's u16-array objects in place: drops
 * the used count back to zero and re-stamps the object from the global at
 * 0x020A7E7C. It is the constructor body of sub_020457B0 minus the
 * allocation, the capacity store and the magic store, so it is the "reuse
 * this buffer" entry of the pair.
 *
 * The object shape, from sub_020457B0's allocation of 2 * capacity + 0xa
 * bytes:
 *
 *   +0x00  u16  capacity
 *   +0x02  u16  used
 *   +0x04  u32  magic (0xECD2F8B6 when live, 0 once sub_02045808 kills it)
 *   +0x08  u16  stamp, copied from g_020A7E7C
 *   +0x0a  u16  entries[capacity]
 *
 * The pool word is attested by the copies in sub_020457A0 and
 * sub_020457B0, which is why this function is its own file.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204581C.c \
 *       --func sub_0204581C --addr 0x0204581C --cc 1.1p1 --arm
 */

#include "../include/G_AllocStamp.h"

typedef unsigned short u16;
typedef unsigned int u32;

struct U16Vec {
    u16 capacity;
    u16 used;
    u32 magic;
    u16 stamp;
    u16 entries[1];
};

/*
 * The global based at 0x020A7E7C is one small object, not two independent
 * words: sub_020457B0 loads 0x020A7E80 out of a pool as the allocator's
 * fourth argument, and that word is this symbol plus four
 * (docs/idioms/pool-base-for-a-far-field-is-the-symbol-offset-masked-by-the-load-reach.md).
 * Reading it as a separate object splits one symbol into two and loses
 * the relocation: 0x020A7E80 has exactly one pool reference image-wide
 * and so no witness of its own, while the base has thirty-six.
 */

extern struct AllocStamp g_020A7E7C;

void sub_0204581C(struct U16Vec *vec)
{
    vec->used = 0;
    vec->stamp = g_020A7E7C.value;
}
