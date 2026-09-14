/*
 * unit:     no
 * address:  0x02030A00
 * packet:   pkt_020307E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * function: sub_02030A00
 *
 * Success-side bookkeeping for the allocation entry point sub_02030734,
 * and a debug filter: the whole body is gated on a global watch id.
 *
 *   void sub_02030A00(u32 heapId, void *p, u32 size)
 *
 * g_020A7820 is a signed watch id, -1 (or any negative value) meaning
 * "watch nothing". Only when it is non-negative and equal to the heap id
 * of this allocation does the block get handed to sub_02030984, which
 * validates the provenance name stamped by sub_02030880.
 *
 * The `cmp r3, #0` / `cmpge r0, r3` pair is the conditional-compare fold
 * of a single `&&`: the first comparison is the first-written conjunct,
 * and the guard must be one expression, not two sequential `if`s, for the
 * `popne` to serve both.
 *
 * symbols:
 *   g_020A7820      0x020A7820  data
 *   sub_02030984    0x02030984  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02030A00.c \
 *       --func sub_02030A00 --addr 0x02030A00 --cc 1.1p1 --arm
 */

typedef unsigned int u32;
typedef signed int s32;

extern s32 g_020A7820;
extern void sub_02030984(void *p, u32 size);

void sub_02030A00(u32 heapId, void *p, u32 size)
{
    if (g_020A7820 >= 0 && heapId == (u32)g_020A7820) {
        sub_02030984(p, size);
    }
}
