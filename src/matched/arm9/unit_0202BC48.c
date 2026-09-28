/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x0202BC48
 * packet:   pkt_0202B7D4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_0202BC48, sub_0202BC60
 *
 * A clamp-increment and a clamp-decrement on the same signed 32-bit array,
 * offset 0x1E4 of the object, indexed by the second argument and clamped
 * against a caller-supplied bound passed as the third: sub_0202BC48 adds
 * 0x10 and caps at the bound from above, sub_0202BC60 subtracts 0x10 and
 * floors at the bound from below. The two are otherwise identical, back to
 * back with no gap, and neither has a relocation.
 *
 * The comparison order in each is a deliberate `cmp`-operand tell
 * (docs/idioms/cmp-operand-order-names-the-temporary.md): sub_0202BC48
 * compares the bound against the computed value (`cmp r2, r1`), which is
 * what `if (cap < v)` compiles to, not `if (v > cap)`.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202BC48.c \
 *       --addr 0x0202BC48 --thumb
 */

typedef unsigned int u32;
typedef int s32;

void sub_0202BC48(void *obj, u32 index, s32 cap)
{
    s32 *arr = (s32 *)((char *)obj + 0x1E4);
    s32 v = arr[index] + 0x10;

    if (cap < v) {
        v = cap;
    }
    arr[index] = v;
}

void sub_0202BC60(void *obj, u32 index, s32 cap)
{
    s32 *arr = (s32 *)((char *)obj + 0x1E4);
    s32 v = arr[index] - 0x10;

    if (v < cap) {
        v = cap;
    }
    arr[index] = v;
}
