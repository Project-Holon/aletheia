/*
 * unit:     no
 * function: sub_02030FC8
 * address:  0x02030FC8
 * packet:   pkt_02030FC8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sub_02030EF0  0x02030EF0  arm
 *   sub_02030F34  0x02030F34  arm
 *   sub_02030F50  0x02030F50  arm
 *
 * Build the free list of the task-control-block pool: walk every row of the
 * stride table, self-link it (sub_02030F50) and push it on the free list
 * (sub_02030F34).  The row address comes from sub_02030EF0, already matched
 * as `idx * (p->field4 + 0x18) + p->field14`.
 *
 * The count is re-read from +0x00 at the bottom of the loop, which is what
 * a plain field read in the loop condition compiles to; a cached local
 * would have kept it in a register and cost a push.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02030FC8.c \
 *       --func sub_02030FC8 --addr 0x02030FC8 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

struct Tcbl {
    u32 count;
};

extern void *sub_02030EF0(struct Tcbl *p, u32 idx);
extern void sub_02030F34(struct Tcbl *p, void *node);
extern void sub_02030F50(struct Tcbl *p, void *node);

void sub_02030FC8(struct Tcbl *p)
{
    u32 i;

    for (i = 0; i < p->count; i++) {
        void *node = sub_02030EF0(p, i);
        sub_02030F50(p, node);
        sub_02030F34(p, node);
    }
}
