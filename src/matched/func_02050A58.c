/*
 * function: func_02050A58
 * address:  0x02050A58
 * packet:   pkt_02050984
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The fourth arm of the handler table func_02050984 dispatches through (its
 * pool word at 0x02050980-ish; see src/pending/func_02050984.c).  Twenty
 * bytes, a leaf: it loads the command's second halfword (`c->f02`), zeroes the
 * entry's +0x12 counter, stores the halfword at +0x10 and returns 0.
 *
 * The zero is materialised once and reused for both the +0x12 store and the
 * return (`mov r1,#0 ... mov r0,r1`), which is what a single `0` constant
 * shared between the store and the `return 0;` produces.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02050A58.c \
 *       --func func_02050A58 --addr 0x02050A58 --cc 1.1p1 --arm
 */

typedef unsigned short u16;

struct Ent {
    u16 pad00[8];
    u16 f10;
    u16 f12;
};

struct Cmd {
    u16 f00;
    u16 f02;
};

int func_02050A58(struct Ent *e, struct Cmd *c)
{
    u16 v = c->f02;

    e->f12 = 0;
    e->f10 = v;
    return 0;
}
