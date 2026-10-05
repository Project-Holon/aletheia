/*
 * function: func_0200ED54
 * address:  0x0200ED54
 * packet:   pkt_0200ED54
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MI_CpuCopy8   0x02082D44  arm
 *
 * Insert `val` into a 32-entry u32 list unless it is already there: the
 * table is the object's first 0x80 bytes and the count lives at +0x80.
 * When the value is found at index i, everything above it shifts up one
 * slot (the memmove) and the value is rewritten into the last live slot
 * (`p[-1]` on a pointer to one past the end), so the list keeps its
 * length; when it is not found and there is room it goes at the end, and
 * when the list is full the whole table shifts up one slot and the value
 * lands in slot 31.
 *
 * Two shapes the bytes pinned down, both from
 * docs/idioms/pointer-minus-one-scales-before-the-subtraction.md and the
 * signed/unsigned split:
 *
 *  - the copy is MI_CpuCopy8(src, dst, size) -- the SDK's argument order,
 *    which is why the source passes the higher index first: the shift is
 *    downward, arr[i+1] is copied onto arr[i];
 *  - the trailing store is NOT `l->arr[l->count - 1]` (which subtracts one
 *    from the count and then scales) but `p[-1]` on a pointer computed as
 *    `l->arr + l->count`: the original scales the count by four first and
 *    subtracts the element size afterwards, four instructions against
 *    three and the whole tail shifts;
 *  - the walk is unsigned (`bls`/`blo`) while the element count `n` that
 *    gates the shift is signed (`ble`).
 *
 * EXACT* rather than EXACT: the follower at 0x0200EDC4 saves registers but
 * not lr, so disasm.py did not label it (docs/idioms/
 * unlabelled-leaf-functions-hide-in-word-runs.md) and the inferred extent
 * runs to 0x0200EE48. The bytes all match; see
 * src/matched/unit_0200EDC4.c for that follower, which this project can
 * reproduce but has not been able to seed in layout/function_starts.txt.
 */

typedef unsigned int u32;

struct L0200ED54 { u32 arr[32]; u32 count; };
extern void MI_CpuCopy8(const void *src, void *dest, u32 size);

void func_0200ED54(struct L0200ED54 *l, u32 val)
{
    u32 i;
    int n;

    for (i = 0; i < l->count; i++) {
        if (l->arr[i] != val)
            continue;
        n = (int)l->count - 1 - (int)i;
        if (n <= 0)
            return;
        MI_CpuCopy8(&l->arr[i + 1], &l->arr[i], (u32)n * 4);
        {
            u32 *p = l->arr + l->count;
            p[-1] = val;
        }
        return;
    }

    if (l->count < 32) {
        l->arr[l->count] = val;
        l->count++;
        return;
    }

    MI_CpuCopy8(&l->arr[1], &l->arr[0], 0x7c);
    l->arr[31] = val;
    l->count = 32;
}
