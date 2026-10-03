/*
 * function: func_021C42A8
 * address:  0x021C42A8
 * packet:   pkt_ov127_021C42A8
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * lever: the indirect callback receives the object in r0 and payload in r1;
 * declaring both arguments preserves p and restores both store ordering and table register allocation.
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

extern void (*tbl_021C5FBC[])(struct obj *, int);

void func_021C42A8(struct obj *p, int idx, int a)
{
    p->f14 = 0;
    p->idx = idx;
    if (tbl_021C5FBC[idx] != 0)
        tbl_021C5FBC[idx](p,a);
}
