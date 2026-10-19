/*
 * function: SPL_EMITTER_FreeResource
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
 *   SPLList_PopFront  0x02058380  arm
 *   SPLList_PushFront  0x020583CC  arm
 *   SPLList_Erase  0x02058300  arm
 *
 * Tear down one node q owned by container p.  Two identical drain loops move
 * every child off q's two sublists (q+8 and q+0x14) onto the container's own
 * recycle list at p+0x1c with SPLList_PushFront; SPLList_PopFront is the pop, and it
 * is re-called at the bottom of each loop rather than at the top, which is why
 * the original re-materialises `add r5,r7,#0x1c` and `add r4,r6,#k` INSIDE the
 * loop body rather than hoisting them (the two locals are declared in the
 * body, one live range per iteration).  Then q is unlinked from p+4 and pushed
 * onto p+0x10.
 *
 * Called from SPL_EMITTER_FreeResourceList next door, which drains p+4 through this routine.
 *
 * Built by the 1.2 front end (`sub sp,sp,#4` alignment word and a
 * `pop {...,lr}; bx lr` epilogue), the packet-wide pin for this cluster.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SPL_EMITTER_FreeResource.c \
 *       --func SPL_EMITTER_FreeResource --addr 0x0205250C --cc ../1.2/sp2 --arm \
 *       --flags "-O4,p -proc arm946e"
 */

struct List;
struct Node;
extern struct Node *SPLList_PopFront(struct List *list);
extern void SPLList_PushFront(volatile struct List *list, volatile struct Node *node);
struct List;
struct Node;
extern struct Node *SPLList_Erase(struct List *list, struct Node *node);

void SPL_EMITTER_FreeResource(char *p, char *q)
{
    void *n;

    n = SPLList_PopFront((struct List *)(q + 8));
    while (n != 0) {
        char *head = p + 0x1c;
        char *list = q + 8;
        SPLList_PushFront((volatile struct List *)head, n);
        n = SPLList_PopFront((struct List *)list);
    }

    n = SPLList_PopFront((struct List *)(q + 0x14));
    while (n != 0) {
        char *head = p + 0x1c;
        char *list = q + 0x14;
        SPLList_PushFront((volatile struct List *)head, n);
        n = SPLList_PopFront((struct List *)list);
    }

    SPLList_Erase((struct List *)(p + 4), (struct Node *)q);
    SPLList_PushFront((volatile struct List *)(p + 0x10), (volatile struct Node *)q);
}
