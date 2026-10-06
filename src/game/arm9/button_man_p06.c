/*
 * file:     button_man_p06.c
 * unit:     yes
 * function: func_020524C8, func_0205250C, func_020525A0
 * address:  0x020524C8
 * region:   arm9
 * compiler: dsi/../1.2/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02058380  0x02058380  arm
 *   func_020583CC  0x020583CC  arm
 *   func_02058300  0x02058300  arm
 *   func_02053A60   0x02053A60  arm
 */
#include "../../matched/include/Obj16201.h"
#include "../../matched/include/Obj16202.h"
#include "../../matched/include/Obj00077.h"
#include "../../matched/include/Obj11461.h"

struct List;
struct Node;
struct Cfg;
struct Obj;
struct Vec3;
typedef unsigned int u32;

struct Scratch {
    u32 a;
    u32 b;
    u32 c;
};

extern struct Node *func_02058380(struct List *list);
extern void func_020583CC(volatile struct List *list, volatile struct Node *node);
extern struct Node *func_02058300(struct List *list, struct Node *node);
extern void func_02053A60(volatile struct Obj *o, struct Cfg *cfg, const struct Vec3 *pos);
void func_020524C8(void *p);
void func_0205250C(char *p, char *q);
int func_020525A0(char *p, int b, void (*fn)(void *));


/*
 * Promote-first callee of src/pending/func_020515CC.c (parks lane 2).
 * Same shape as its neighbour func_02052634 with two extra steps: the
 * loader takes the address of a twelve-byte zeroed scratch block as its
 * third argument, and a non-null third parameter is called back with the
 * popped node before func_020583CC runs.
 *
 * Built by the 1.2 front end (ARMv4T-style `pop {... lr}; bx lr` epilogue
 * and a `sub sp, sp, #4` alignment word), see
 * docs/idioms/an-armv4t-style-return-and-a-register-blx-name-a-1-2-front-end-not-a-proc-value.md.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020525A0.c \
 *       --func func_020525A0 --addr 0x020525A0 --cc ../1.2/sp2 --arm \
 *       --flags "-O4,p -proc arm946e"
 */
int func_020525A0(char *p, int b, void (*fn)(void *))
{
    void *r = 0;

    if (((struct Obj11461 *)p)->f10 != 0) {
        struct Scratch scratch = { 0, 0, 0 };

        r = func_02058380((struct List *)(p + 0x10));
        func_02053A60(r, (void *)(((struct Obj11461 *)p)->f28 + (b << 5)), (const struct Vec3 *)(&scratch));
        if (fn != 0)
            fn(r);
        func_020583CC((volatile struct List *)(p + 4), r);
        if ((*(u32 *)(*(u32 *)(*(u32 *)&((struct Obj00077 *)r)->f20)) << 0x11 >> 0x1f) != 0)
            r = 0;
    }
    return (int)r;
}


/*
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
void func_0205250C(char *p, char *q)
{
    void *n;

    n = func_02058380((struct List *)(q + 8));
    while (n != 0) {
        char *head = p + 0x1c;
        char *list = q + 8;
        func_020583CC((volatile struct List *)head, n);
        n = func_02058380((struct List *)list);
    }

    n = func_02058380((struct List *)(q + 0x14));
    while (n != 0) {
        char *head = p + 0x1c;
        char *list = q + 0x14;
        func_020583CC((volatile struct List *)head, n);
        n = func_02058380((struct List *)list);
    }

    func_02058300((struct List *)(p + 4), (struct Node *)q);
    func_020583CC((volatile struct List *)(p + 0x10), (volatile struct Node *)q);
}


/*
 * Drain the singly-linked list hanging off p+4: for each node, cache its
 * `next` pointer (the first word) BEFORE handing the node to func_0205250C,
 * which tears the node down.  The cached-next shape is what produces the
 * `ldr r4,[r1]` above the call and the `mov r1,r4; cmp r4,#0` pair below it.
 *
 * Built by the 1.2 front end like the rest of this cluster: the frame pads
 * with `sub sp, sp, #4` and the epilogue is `pop {r4,r5,lr}; bx lr`
 * (docs/idioms/an-armv4t-style-return-and-a-register-blx-name-a-1-2-front-end-not-a-proc-value.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020524C8.c \
 *       --func func_020524C8 --addr 0x020524C8 --cc ../1.2/sp2 --arm \
 *       --flags "-O4,p -proc arm946e"
 */
void func_020524C8(void *p)
{
    void *n = ((struct Obj16201 *)p)->f4;

    while (n != 0) {
        void *next = ((struct Obj16202 *)n)->f0;
        func_0205250C(p, n);
        n = next;
    }
}
