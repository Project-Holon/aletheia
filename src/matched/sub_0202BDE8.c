/*
 * unit:     yes
 * function: sub_0202BDE8
 * address:  0x0202BDE8
 * packet:   pkt_0202BDE8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * A clamp-increment on the same shape as sub_0202BC48, the same array as
 * sub_0202BDD0 (offset 0x224) and the same step (0x20). No relocation. This
 * function opens the next packet, so it stays a file of its own rather than
 * joining the pkt_0202B7D4 trio it otherwise matches. Matched as a
 * one-function unit rather than with `one`, for the same trailing-padding
 * reason as sub_0202BDD0.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/sub_0202BDE8.c \
 *       --addr 0x0202BDE8 --thumb
 */

typedef unsigned int u32;
typedef int s32;

void sub_0202BDE8(void *obj, u32 index, s32 cap)
{
    s32 *arr = (s32 *)((char *)obj + 0x224);
    s32 v = arr[index] + 0x20;

    if (cap < v) {
        v = cap;
    }
    arr[index] = v;
}
