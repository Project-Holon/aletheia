/*
 * function: func_0205250C
 * address:  0x0205250C
 * packet:   pkt_0205250C
 * region:   arm9
 * compiler: ../1.2/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02058380  0x02058380  arm
 *   func_020583CC  0x020583CC  arm
 *   func_02058300  0x02058300  arm
 *
 * Tear down one node q owned by container p.  Two identical drain loops move
 * every child off q's two sublists (q+8 and q+0x14) onto the container's own
 * recycle list at p+0x1c with func_020583CC; func_02058380 is the pop, and it
 * is re-called at the bottom of each loop rather than at the top, which is why
 * the original re-materialises `add r5,r7,#0x1c` and `add r4,r6,#k` INSIDE the
 * loop body rather than hoisting them (the two locals are declared in the
 * body, one live range per iteration).  Then q is unlinked from p+4 and pushed
 * onto p+0x10.
 *
 * Called from func_020524C8 next door, which drains p+4 through this routine.
 *
 * Built by the 1.2 front end (`sub sp,sp,#4` alignment word and a
 * `pop {...,lr}; bx lr` epilogue), the packet-wide pin for this cluster.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0205250C.c \
 *       --func func_0205250C --addr 0x0205250C --cc ../1.2/sp2 --arm \
 *       --flags "-O4,p -proc arm946e"
 */

extern void *func_02058380(void *p);
extern void func_020583CC(void *a, void *b);
extern void func_02058300(void *a, void *b);

void func_0205250C(char *p, char *q)
{
    void *n;

    n = func_02058380(q + 8);
    while (n != 0) {
        char *head = p + 0x1c;
        char *list = q + 8;
        func_020583CC(head, n);
        n = func_02058380(list);
    }

    n = func_02058380(q + 0x14);
    while (n != 0) {
        char *head = p + 0x1c;
        char *list = q + 0x14;
        func_020583CC(head, n);
        n = func_02058380(list);
    }

    func_02058300(p + 4, q);
    func_020583CC(p + 0x10, q);
}
