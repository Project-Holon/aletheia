/*
 * unit:     yes
 * function: FS_EndOverlay, FS_UnloadOverlayImage
 * address:  0x02079164
 * packet:   pkt_020792B8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02087988  0x02087988  arm
 *   func_0208799C  0x0208799C  arm
 *   g_021542B8     0x021542B8  data
 *
 * 0x02079164..0x02079264: the callback-flush worker and its one-line
 * wrapper.
 *
 * FS_EndOverlay repeatedly detaches, inside the 0x02087988/0x0208799C
 * critical section, every node of the global list g_021542B8 whose
 * callback argument (+8) falls in the descriptor's byte range, or whose
 * callback function (+4) does when the argument is null, then runs the
 * detached callbacks with interrupts restored and starts over.  The
 * branch back to the function header is that restart: a callback may
 * queue new nodes, so the list is rescanned until a pass detaches
 * nothing.  The range is [it->base, it->base + it->len0 + it->len1).
 *
 * FS_UnloadOverlayImage is folded into the same unit deliberately.  The `bl` at
 * 0x02079258 is 0x02079164's only reference in the whole image, so as two
 * separate files neither can attest the other and both cap at MATCH; in
 * one unit that call site is class `local` and the range is EXACT, which
 * in turn attests 0x02079254 for src/matched/func_020792B8.c.
 *
 * Three things the byte match pinned down, in the order they cost time:
 *
 *  - 0x02087988's result is live in r0 across the whole scan loop and is
 *    0x0208799C's argument (the SDK disable/restore-interrupts pair).
 *    Spelling both as `void f(void)` leaves r0 free, and the allocator
 *    then has one spare register and picks a different colouring for
 *    every local in the function.
 *  - `cur->arg` and `cur->fn` are read into locals before the test, not
 *    referenced inside it: the original loads +4 unconditionally, ahead
 *    of the branch that only one arm of the test needs.
 *  - which locals live in the function scope and which in the `for` body
 *    block decides the colouring outright.  `prev` and `list` outlive the
 *    loop body's declarations here; moving either one inside the block
 *    moves eight or more bytes.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02079164.c  *       --addr 0x02079164 --cc 1.1p1 --arm
 */

#include "../include/G_Node.h"


typedef unsigned int u32;

struct Node02079164 {
    struct Node02079164 *next;
    void (*fn)(void *);
    void *arg;
};

struct Iter020792B8 {
    u32 unk00;
    u32 base;
    u32 len0;
    u32 len1;
    u32 pad[7];
};

extern struct Node *g_021542B8;

extern u32  func_02087988(void);
extern void func_0208799C(u32 e);

void FS_EndOverlay(struct Iter020792B8 *it)
{
    struct Node02079164 *prev;
    struct Node02079164 *list;

    for (;;) {
        struct Node02079164 *head;
        struct Node02079164 *tail;
        struct Node02079164 *cur;
        struct Node02079164 *next;
        u32 lo;
        u32 hi;
        u32 arg;
        u32 fn;
        u32 e;

        head = 0;
        tail = 0;
        lo = it->base;
        hi = lo + (it->len0 + it->len1);

        e = func_02087988();

        list = ((struct Node02079164 *)g_021542B8);
        prev = 0;
        cur = list;
        while (cur != 0) {
            arg = (u32)cur->arg;
            next = cur->next;
            fn = (u32)cur->fn;
            if ((arg == 0 && fn >= lo && fn < hi) || (arg >= lo && arg < hi)) {
                if (tail != 0) {
                    tail->next = cur;
                } else {
                    head = cur;
                }
                if (list == cur) {
                    g_021542B8 = (struct Node *)(next);
                    list = next;
                }
                cur->next = 0;
                tail = cur;
                if (prev != 0) {
                    prev->next = next;
                }
            } else {
                prev = cur;
            }
            cur = next;
        }

        func_0208799C(e);

        if (head == 0) {
            return;
        }

        do {
            next = head->next;
            if (head->fn != 0) {
                head->fn(head->arg);
            }
            head = next;
        } while (head != 0);

    }
}

int FS_UnloadOverlayImage(struct Iter020792B8 *it)
{
    FS_EndOverlay(it);
    return 1;
}
