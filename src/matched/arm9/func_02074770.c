/*
 * function: NNS_SndHeapClear
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
 * +0x14). Each exhausted list is unlinked with NNS_FndRemoveListObject and the outer walk
 * restarts from the head, so the loop terminates when the list is empty. The
 * tail then releases the heap through NNS_FndFreeToFrmHeap(o->f00, 3), calls
 * NNSi_SndHeapFlushCommands once if any callback ran at all, and finishes with
 * NNSi_SndHeapAllocLevel(o).
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
 * The inner cursor is re-fetched as NNS_FndGetPrevListObject(a, n), i.e. the "next after
 * this one" form of the same iterator the outer loop calls with a null cursor
 * to get a head -- one function serving both roles is what makes the four call
 * sites to NNS_FndGetPrevListObject all identical in shape.
 *
 * All eight relocation sites resolve.
 *
 * symbols:
 *   NNS_FndGetPrevListObject  0x0206062C  arm
 *   NNS_FndRemoveListObject  0x020605B4  arm
 *   NNS_FndFreeToFrmHeap  0x02061158  arm
 *   NNSi_SndHeapFlushCommands  0x02074A34  arm
 *   NNSi_SndHeapAllocLevel  0x020749F8  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_SndHeapClear.c \
 *       --func NNS_SndHeapClear --addr 0x02074770 --cc ../2.0/sp2 --arm
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
extern void *NNS_FndGetPrevListObject(struct DList *list, void *elem);
extern void NNS_FndRemoveListObject(volatile struct DList *list, void *elem);
struct Table;
extern void NNS_FndFreeToFrmHeap(void *p, int flags);
extern void  NNSi_SndHeapFlushCommands(void);
extern int NNSi_SndHeapAllocLevel(struct Table *t);

void NNS_SndHeapClear(struct Obj *o)
{
    void *a;
    u32 any;
    struct Node *n;

    any = 0;
    a = NNS_FndGetPrevListObject((struct DList *)o->list, 0);
    while (a != 0) {
        n = (struct Node *)NNS_FndGetPrevListObject(a, 0);
        while (n != 0) {
            if (n->f0c != 0) {
                ((void (*)(void *, u32, u32, u32))n->f0c)((u8 *)n + 0x20, n->f08, n->f10, n->f14);
                any = 1;
            }
            n = (struct Node *)NNS_FndGetPrevListObject(a, n);
        }
        NNS_FndRemoveListObject((volatile struct DList *)o->list, a);
        a = NNS_FndGetPrevListObject((struct DList *)o->list, 0);
    }

    NNS_FndFreeToFrmHeap((void *)o->f00, 3);
    if (any != 0) NNSi_SndHeapFlushCommands();
    NNSi_SndHeapAllocLevel((struct Table *)o);
}
