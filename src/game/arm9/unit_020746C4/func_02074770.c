/*
 * function: func_02074770
 * address:  0x02074770
 * packet:   pkt_020737C0
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Drains the whole pending-request structure: an outer walk over the list at
 * o->list, and for each list an inner walk over its nodes, invoking every node
 * whose callback slot at +0x0C is non-null with (node + 0x20, +0x08, +0x10,
 * +0x14). Each exhausted list is unlinked with func_020605B4 and the outer walk
 * restarts from the head, so the loop terminates when the list is empty. The
 * tail then releases the heap through func_02061158(o->f00, 3), calls
 * func_02074A34 once if any callback ran at all, and finishes with
 * func_020749F8(o).
 *
 * PINNED ../2.0/sp2, the pin seven cluster siblings carry.
 *
 * ONE LEVER, and it is the only thing that was ever wrong: DECLARATION ORDER.
 * The first spelling was size-exact at 188 bytes on the first compile with 14
 * concrete bytes out, and the whole residue was a clean r6/r7 exchange between
 * the `any` flag and the inner node cursor. Declaring `any` BEFORE the node
 * pointer gives the image's assignment (`any` in r6, the cursor in r7) and
 * closes it, per
 * docs/idioms/declaration-order-decides-which-register-a-local-gets.md. Note
 * this is declaration order, not initialisation order: `any` is still assigned
 * its zero after `n` is declared.
 *
 * The inner cursor is re-fetched as func_0206062C(a, n), i.e. the "next after
 * this one" form of the same iterator the outer loop calls with a null cursor
 * to get a head -- one function serving both roles is what makes the four call
 * sites to func_0206062C all identical in shape.
 *
 * All eight relocation sites resolve.
 *
 * symbols:
 *   func_0206062C  0x0206062C  arm
 *   func_020605B4  0x020605B4  arm
 *   func_02061158  0x02061158  arm
 *   func_02074A34  0x02074A34  arm
 *   func_020749F8  0x020749F8  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02074770.c \
 *       --func func_02074770 --addr 0x02074770 --cc ../2.0/sp2 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Node {
    u8  pad00[8];
    u32 f08;
    u32 f0c;   /* callback */
    u32 f10;
    u32 f14;
};

struct Obj { u32 f00; u8 list[4]; };

struct DList;
extern void *func_0206062C(struct DList *list, void *elem);
extern void func_020605B4(volatile struct DList *list, void *elem);
struct Table;
extern void func_02061158(void *p, int flags);
extern void  func_02074A34(void);
extern int func_020749F8(struct Table *t);

void func_02074770(struct Obj *o)
{
    void *a;
    u32 any;
    struct Node *n;

    any = 0;
    a = func_0206062C((struct DList *)o->list, 0);
    while (a != 0) {
        n = (struct Node *)func_0206062C(a, 0);
        while (n != 0) {
            if (n->f0c != 0) {
                ((void (*)(void *, u32, u32, u32))n->f0c)((u8 *)n + 0x20, n->f08, n->f10, n->f14);
                any = 1;
            }
            n = (struct Node *)func_0206062C(a, n);
        }
        func_020605B4((volatile struct DList *)o->list, a);
        a = func_0206062C((struct DList *)o->list, 0);
    }

    func_02061158((void *)o->f00, 3);
    if (any != 0) func_02074A34();
    func_020749F8((struct Table *)o);
}
