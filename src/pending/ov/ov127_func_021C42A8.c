/*
 * function: func_021C42A8
 * address:  0x021C42A8
 * packet:   pkt_021C42A8
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * blocker:  codegen: the scheduler emits the +0xc store before the +0x14
 *           zero store and frees r0 for the table base, where the original
 *           keeps r0 as p and uses r1/r3 for the table.  Tried struct fields,
 *           source reordering, a named function-pointer local, and volatile;
 *           none reproduce the original ordering.  12 bytes differ.
 *
 * symbols:
 *   tbl_021C5FBC  0x021C5FBC  data  a4
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;

struct obj {
    int pad0[3];
    int idx;
    int pad1;
    u16 f14;
};

extern void (*tbl_021C5FBC[])(int);

void func_021C42A8(struct obj *p, int idx, int a)
{
    p->f14 = 0;
    p->idx = idx;
    if (tbl_021C5FBC[idx] != 0)
        tbl_021C5FBC[idx](a);
}
