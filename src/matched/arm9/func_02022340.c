/*
 * function: func_02022340
 * address:  0x02022340
 * packet:   pkt_02022174
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * One poll step of the dual-screen cluster.  The mode word at +0x00 (the one
 * func_020223C0 wrote) selects which of the two screen slots gets pumped:
 * mode 0 pumps both, mode 1 prefers the top slot and falls back to the bottom
 * one, mode 2 the mirror of that.  It reports 1 only once both slots have gone
 * null, which is what func_02022174 tests before running the teardown.
 *
 * Three cases starting at zero still compile to a cmp chain, not a halfword
 * table: the table form only wins from four cases up.  The two pump calls are
 * written once per arm and cross-jumped by the compiler into the two shared
 * blocks at 0x0202235C and 0x02022376; factoring them behind a label instead
 * moves the branch targets.  See
 * docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md.
 *
 * The tail has to be written as the positive `if (both null) return 1; return
 * 0;`.  The equivalent `if (top || bottom) return 0; return 1;` inverts the
 * second branch and swaps the two constant returns, four bytes wrong.
 *
 * symbols:
 *   func_02022390  0x02022390  thumb
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02022340.c \
 *       --func func_02022340 --addr 0x02022340 --cc 1.1p1 --thumb
 */
typedef unsigned int u32;

struct Cluster {
    u32    mode;
    void  *top;
    void  *bottom;
};

extern void func_02022390(u32 *obj, void *arg);

u32 func_02022340(struct Cluster *p, void *top, void *bottom)
{
    switch (p->mode) {
    case 0:
        func_02022390((u32 *)(&p->top), top);
        func_02022390((u32 *)(&p->bottom), bottom);
        break;
    case 1:
        if (p->top != 0)
            func_02022390((u32 *)(&p->top), top);
        else
            func_02022390((u32 *)(&p->bottom), bottom);
        break;
    case 2:
        if (p->bottom != 0)
            func_02022390((u32 *)(&p->bottom), bottom);
        else
            func_02022390((u32 *)(&p->top), top);
        break;
    }
    if (p->top == 0 && p->bottom == 0)
        return 1;
    return 0;
}
