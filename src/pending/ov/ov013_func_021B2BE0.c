/*
 * function: func_021B2BE0
 * address:  0x021B2BE0
 * packet:   pkt_ov013_021B2BE0
 * region:   ov013
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * note 2026-10-05 (wave P6 lane U4): written from the listing; types and the
 * Pool/Node/Stats layouts come from matched ov013 021B22B4, 021B2AA0, 021B2894,
 * 021B279C, 021B26DC (no twin of the function itself). Audio session start/
 * continue gate: if the active node state is 2 it checks the packet channel
 * and re-runs the transition table (func_021B2894), else it tests the channel
 * mask in d_021B4BD0.f4, arms the node (state 2, channel, fc 0) and runs the
 * table; then it builds the event (func_021B279C), and on event 10 stamps the
 * 64-bit tick (func_020870D0) into d_021B4BD0.f8. d_021B4C0C is the same node
 * as g_021B4BE0.active (separate pool word in the listing, so two externs).
 * Layout, block order, the three-way compare chain (switch with cases -3/-2/-1
 * in the second arm, case -2 first in the first arm plus default: break) and
 * all pool words match. Residue, 364 B vs 372 B: (1) the original keeps the
 * table result in r4 and the hoisted zero in r6, the build has them swapped;
 * (2) the original reloads ev->type (ldr r0,[r7]) before the compare with 10,
 * the build reuses the call result in r0 (4 B). Tried without effect: all six
 * per-function pragmas; unsigned result local; result and node local declaration
 * order; per-arm tail via a static inline (440 B); raw int* store for fc and an
 * int *ev (no reload); node pointer assigned in each arm (needed for the single
 * ldr r5 per arm). Tail merging of r at the join is the open idea.
 *
 * note 2026-10-05 (wave P6 lane U4b): ev->type reload FIXED (4 B): the node
 * field store is written through the global (`d_021B4C0C.fc = r;`), which may
 * alias the event pointer, so ev->type is read back (368 B now, 4 B short).
 * Residue: (1) r in r4 / zero in r6 still swapped; (2) the original has a lone
 * `b join` at +0x88 that the switch default branches to (an unthreaded hop,
 * idiom a-conditional-branch-onto-an-unconditional-b); ours threads the default
 * straight to the join and drops the hop. Tried without effect: Node.fc int,
 * Event.type unsigned, result local t, ev->node->fc store, ev_is() inline, node
 * store order, no n local (360 B, worse), the tail written in each arm (436-440 B:
 * the tail ends in a conditional so cross-jump cannot merge it, so the original
 * has ONE tail), goto tail from default, no default / if-chain in arm 1 (356 B),
 * dead local ok = 1 after the switch, int r = 0, r before n, unsigned r,
 * opt_lifetimes/propagation off (same), opt_common_subs off (372 B but 80 B
 * differ, rematerialises pkt->f8). Open: what makes the default exit a live hop.
 *
 * note 2026-10-05 final push G9L2 (38 compiles, 3 rounds, still DIFF 199/368 B off; listing 372):
 * CORRECTION: the U4b "reload fixed" claim is wrong. The global fc store gives `ldr r1,[pool]`
 * (address rematerialised), not an ev->type reload; the original stores `str r4,[r5,#0xc]` through
 * the node register and reloads ev->type (`ldr r0,[r7]`). A store through n (`n->fc = r`, also
 * ev->node->fc, int or unsigned fields) gives 364 B and no reload; a store through an unrelated
 * pointer (`pkt->fc = r`) does reload (368), so the original store base is not a known constant.
 * Earliest residue: zero in r6/result in r4 (ours swapped) and the lone `b tail` hop at +0x88.
 * Tried without effect: tail written in both arms (440 B, copies do not cross-jump), result phi
 * copy t then r = t (also with opt_propagation/opt_lifetimes off), no default, goto done/tail
 * from default or after the switch, if-chain with goto (360 B), dead statements after the arm-1
 * switch (r=r, n=n, ev=ev, label, empty block), named zero int/pointer local (with propagation
 * off the -3 compare chain rebases on it and 7 registers are used: 372 B, 208 off), no n local
 * (360 B), local Event aggregate copy (stack, 400 B), second Event view for the compare, switch
 * (r = f(...)) form, state != 2 first (376 B). Idea left: mwcc runs IRO_DoJumpChaining last, so
 * the hop means the switch-end label block was not jump-only at chaining time; and the zero must
 * be born before n and the result.
 *
 * symbols:
 *   g_021B4BE0     0x021B4BE0  data  a4
 *   d_021B4C0C     0x021B4C0C  data  a4
 *   g_021B4BD0     0x021B4BD0  data  a4
 *   func_021B2894  0x021B2894  arm  ov013
 *   func_021B279C  0x021B279C  arm  ov013
 *   func_021B26DC  0x021B26DC  arm  ov013
 *   func_020870D0  0x020870D0  arm
 */

struct Node {
    unsigned int state;
    unsigned char f4;
    unsigned char f5;
    unsigned short f6;
    unsigned int f8;
    unsigned int fc;
    unsigned int f10;
    struct Node *next;
};

struct Pool {
    struct Node *nodes;
    unsigned int f4;
    void *tick;
    unsigned int mul;
    unsigned int add;
    struct Node freeList;
    struct Node active;
};

struct Pkt {
    unsigned char pad0[4];
    unsigned char f4;
    unsigned char f5;
    unsigned char f6;
    unsigned char f7;
    unsigned char f8;
    unsigned char f9;
    unsigned char fa;
    unsigned char fb;
    unsigned int fc;
};

struct Event {
    int type;
    struct Node *node;
};

struct Stats {
    unsigned int f0;
    unsigned int f4;
    unsigned long long f8;
};

extern struct Pool g_021B4BE0;
extern struct Stats g_021B4BD0;
extern struct Node d_021B4C0C;
extern int func_021B2894(struct Node *node, struct Pkt *pkt);
extern int func_021B279C(struct Pkt *pkt, struct Node *node);
extern void func_021B26DC(int x);
extern unsigned long long func_020870D0(void);

int func_021B2BE0(struct Pkt *pkt, struct Event *ev)
{
    struct Node *n;
    int r;

    if (g_021B4BE0.active.state == 2) {
        if (g_021B4BE0.active.f4 == pkt->f8) {
            n = &d_021B4C0C;
            r = func_021B2894(n, pkt);
            switch (r) {
            case -2:
                ev->type = 0xC;
                ev->node = 0;
                return 1;
            case -3:
            case -1:
                return 0;
            default:
                break;
            }
        } else {
            func_021B26DC(1);
            return 0;
        }
    } else {
        if (!(g_021B4BD0.f4 & ((pkt->f8 != 0) ? (1 << pkt->f8) : 1)))
            return 0;
        g_021B4BE0.active.f4 = pkt->f8;
        g_021B4BE0.active.state = 2;
        g_021B4BE0.active.fc = 0;
        n = &d_021B4C0C;
        r = func_021B2894(n, pkt);
        switch (r) {
        case -3:
        case -2:
        case -1:
            g_021B4BE0.active.state = 0;
            return 0;
        }
    }
    ev->type = func_021B279C(pkt, n);
    ev->node = n;
    d_021B4C0C.fc = r;
    if (ev->type == 10) {
        func_021B26DC(1);
        g_021B4BD0.f8 = func_020870D0();
    } else {
        func_021B26DC(0);
        g_021B4BD0.f8 = 0;
    }
    return 1;
}
