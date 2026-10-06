/*
 * unit:     no
 * function: sub_02030F70
 * address:  0x02030F70
 * packet:   pkt_02030F50
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sub_020307B0  0x020307B0  arm
 *   sub_02030F34  0x02030F34  arm
 *
 * Destroy one task-callback node: release the work block the registrar
 * allocated for it at +0x10 (if it owns one), clear the callback so a walk
 * already inside sub_020310C4 cannot call it again, unlink it from the
 * manager's circular list and push it back on the free list.
 *
 * The callback is cleared before the free rather than after, which is what
 * fixes the `mov r1, #0` / `str r1, [r4, #0x14]` ahead of the guard: written
 * after the call, the store lands past the branch and the zero is
 * rematerialised.
 *
 * The unlink is `ldmib r4, {r0, r2}` for the first store and then two fresh
 * loads of the same two fields for the second: the store through r0 may
 * alias the node's own links, so the compiler reloads
 * (docs/idioms/const-pointer-lets-a-field-load-survive-a-store.md read the
 * other way round).  Writing the pair into locals first collapses the
 * reloads and loses eight bytes.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02030F70.c \
 *       --func sub_02030F70 --addr 0x02030F70 --cc 1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct Tcbl;
struct TcblNode;

typedef void (*TcblFunc)(struct TcblNode *node, void *work);

struct TcblNode {
    struct Tcbl     *owner;
    struct TcblNode *prev;
    struct TcblNode *next;
    u32              key;
    void            *work;
    TcblFunc         func;
};

extern u32 sub_020307B0(void *p);
struct Node02030F34;
struct S02030F34;
extern void sub_02030F34(struct S02030F34 *p, struct Node02030F34 *node);

void sub_02030F70(struct TcblNode *n)
{
    n->func = 0;
    if (n->work != 0) {
        sub_020307B0(n->work);
    }
    n->prev->next = n->next;
    n->next->prev = n->prev;
    sub_02030F34((struct S02030F34 *)n->owner, (struct Node02030F34 *)n);
}
