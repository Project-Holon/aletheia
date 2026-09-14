/*
 * unit:     yes
 * function: sub_0202BDD0
 * address:  0x0202BDD0
 * packet:   pkt_0202B7D4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * A clamp-decrement on the same shape as sub_0202BC60, a different signed
 * 32-bit array (offset 0x224 of the object) and a different step (0x20). No
 * relocation. Matched as a one-function unit rather than with `one`: this
 * function is followed by two bytes of inter-section padding before the
 * next label, exactly the situation in src/matched/sub_0202AB64.c.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/sub_0202BDD0.c \
 *       --addr 0x0202BDD0 --thumb
 */

typedef unsigned int u32;
typedef int s32;

void sub_0202BDD0(void *obj, u32 index, s32 cap)
{
    s32 *arr = (s32 *)((char *)obj + 0x224);
    s32 v = arr[index] - 0x20;

    if (v < cap) {
        v = cap;
    }
    arr[index] = v;
}
