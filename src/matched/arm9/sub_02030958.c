/*
 * unit:     no
 * address:  0x02030958
 * packet:   pkt_020307E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * function: sub_02030958
 *
 * The out-of-memory failure reporter reached from the allocation entry
 * point sub_02030734 just before OS_Terminate.
 *
 *   void sub_02030958(u32 heapId)
 *
 * Only r0 is read. sub_02030734 sets up four argument registers at this
 * call (heapId, size, site, tag) but the last three arrive unchanged from
 * its own prologue and are leftovers, the shape of
 * docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md;
 * the declaration in src/pending/sub_02030734.c spelling four parameters
 * is therefore wider than the real callee and should be narrowed to one
 * when that file is revisited.
 *
 * Body: sub_02030428 maps the public heap id to the heap's arena handle
 * (it masks the id, range-checks it against the count at +8 of the heap
 * table, records an error code at +0xe on failure and otherwise tail-calls
 * sub_0202FBAC), that handle is then walked by sub_02060E6C and dumped by
 * sub_02060E94 with a mode of 4, and sub_02030B50 is passed the original
 * public id. The handle value is live across two calls, so it costs r4,
 * and the id costs r5.
 *
 * symbols:
 *   sub_02030428    0x02030428  arm
 *   sub_02030B50    0x02030B50  arm
 *   sub_02060E6C    0x02060E6C  arm
 *   sub_02060E94    0x02060E94  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02030958.c \
 *       --func sub_02030958 --addr 0x02030958 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern void *sub_02030428(u32 heapId);
extern void sub_02030B50(u32 heapId);
typedef signed int     s32;
struct Heap;
extern int sub_02060E6C(int *p);
extern s32 sub_02060E94(struct Heap *heap, s32 x);

void sub_02030958(u32 heapId)
{
    void *arena;

    arena = sub_02030428(heapId);
    sub_02060E6C(arena);
    sub_02060E94(arena, 4);
    sub_02030B50(heapId);
}
