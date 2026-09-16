/*
 * unit:     no
 * function: sub_02061CA4
 * address:  0x02061CA4
 * packet:   pkt_02061C0C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * symbols:
 *   g_02146B80     0x02146B80  data
 *   func_02061860  0x02061860  arm
 *   func_02061BC0  0x02061BC0  arm
 *   func_02061B74  0x02061B74  arm
 *
 * Pushes one four-word request onto the queue object at 0x02146B80 and adds
 * its size field to the queue's running byte total at +0x10. func_02061860
 * is the "queue full" test: a non-zero answer makes this return 0 without
 * touching anything, which is why the failure path is a `movne r0, #0` fused
 * into the conditional epilogue rather than a branch.
 *
 * The middle two stores land as one `stmib r4, {r7, r8}` and that ordering is
 * the whole tell for the argument mapping: `stm` writes the lowest-numbered
 * register to the lowest address, so +4 takes r7 (the third argument) and +8
 * takes r8 (the second). Writing the two fields in numeric field order
 * instead swaps the two arguments and still produces an `stmib`, so the
 * verdict stays SIZE-clean and the diff is only two bytes.
 *
 * Byte-correct, capped at MATCH. Blocked on: func_02061BC0 (0x02061BC0) and
 * func_02061B74 (0x02061B74) each have exactly one branch reference in the
 * whole image, the `bl` inside this function, so the `label` class has no
 * witness outside the compared range. There is nothing to cut: the range is
 * a single function, so `--suggest-split` has no cut to offer. Both need an
 * EXACT manifest entry of their own, and both sit outside pkt_02061C0C.
 * func_02061860 and g_02146B80 do resolve (label and literal).
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_02061CA4.c \
 *       --func sub_02061CA4 --addr 0x02061CA4 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;
typedef signed int    s32;

struct Req {
    void *unk_00;
    u32 unk_04;
    u32 unk_08;
    s32 size;
};

struct Queue {
    u8 pad_00[0x10];
    s32 total;
};

extern struct Queue g_02146B80;

extern s32 func_02061860(struct Queue *q);
extern struct Req *func_02061BC0(struct Queue *q);
extern void func_02061B74(struct Queue *q);

s32 sub_02061CA4(void *p, u32 a, u32 b, s32 size)
{
    struct Req *req;

    if (func_02061860(&g_02146B80) != 0) {
        return 0;
    }

    req = func_02061BC0(&g_02146B80);
    req->unk_00 = p;
    req->unk_04 = b;
    req->unk_08 = a;
    req->size = size;
    func_02061B74(&g_02146B80);
    g_02146B80.total += req->size;
    return 1;
}
