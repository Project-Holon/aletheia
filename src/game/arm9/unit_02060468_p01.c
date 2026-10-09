/*
 * file:     unit_02060468_p01.c
 * unit:     yes
 * function: func_02060468, func_02060480, func_020604AC, func_02060500, func_02060550, func_020605B4, func_02060614, func_0206062C, func_02060640, func_020606A8, func_020606D0, func_0206074C, func_02060764, func_02060790, func_020607B8, func_020607E8
 * address:  0x02060468
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_02146B64       0x02146B64  data
 *   sRootListInitialized  0x02146B60  data
 *   sRootList             0x02146B64  data
 */
#include "../../matched/include/Obj06998.h"
#include "../../matched/include/Obj00512.h"

#define GetLink(list, obj) ((NNSFndLink_02060468 *)(((u32)(obj)) + (list)->offset))
#define NNSi_FndSetBitValue(data, st, bits, val) \
    ((data) = (((data) & ~(((1u << (bits)) - 1) << (st))) | (((val) & ((1u << (bits)) - 1)) << (st))))
struct DList;
struct Elem;
typedef unsigned short u16;

struct DList {
    void *head;
    void *tail;
    u16   count;
    u16   node_offset;
};

struct DListNode {
    void *prev;
    void *next;
};

typedef unsigned int u32;

typedef struct { void *prevObject; void *nextObject; } NNSFndLink_02060468;

typedef struct { void *headObject; void *tailObject; u16 numObjects; u16 offset; } NNSFndList_02060468;

struct Elem {
    char pad00[0x0c];
    struct DList sublist;
    u32 min_val;
    u32 max_val;
};

typedef unsigned char u8;

typedef int BOOL;

typedef struct NNSFndLink_020606D0 { void *prevObject; void *nextObject; } NNSFndLink_020606D0;

typedef struct NNSFndList_020606D0 { void *headObject; void *tailObject; u16 numObjects; u16 offset; } NNSFndList_020606D0;

typedef struct NNSiFndHeapHead {
    u32 signature;
    NNSFndLink_020606D0 link;
    NNSFndList_020606D0 childList;
    void *heapStart;
    void *heapEnd;
    u32 attribute;
} NNSiFndHeapHead;

void func_02060468(int p0, int p1);
void func_02060480(volatile struct DList *list, void *elem);
void func_020604AC(NNSFndList_02060468 *list, void *object);
void func_02060500(NNSFndList_02060468 *list, void *object);
void func_02060550(volatile struct DList *list, void *before, void *elem);
void func_020605B4(volatile struct DList *list, void *elem);
void *func_02060614(struct DList *list, void *elem);
void *func_0206062C(struct DList *list, void *elem);
struct Elem *func_02060640(struct DList *list, u32 val);
void *func_020606A8(u32 a);
void func_020606D0(NNSiFndHeapHead *pHeapHd, u32 signature, void *heapStart, void *heapEnd, u16 optFlag);
void NHTTP_CleanupAsync(void *p);
void func_02060764(int *out, int *blk);
void *func_02060790(int *p, int *node);
void *func_020607B8(int *p, void *node, int *a);
void *func_020607E8(int *p, int v);
extern u32 g_02146B64;
extern BOOL sRootListInitialized;
extern NNSFndList_020606D0 sRootList;






void func_02060468(int p0, int p1){ ((struct Obj06998 *)p0)->f0 = (int)0; ((struct Obj06998 *)p0)->f4 = (int)0; ((struct Obj06998 *)p0)->f8 = (unsigned short)0; ((struct Obj06998 *)p0)->fA = (unsigned short)p1; }






/*
 * DList: seed an empty list with its first element.  The list header is the
 * one src/matched/unit_02060614.c already fixes -- head at +0x00, tail at
 * +0x04, a u16 count at +0x08 and the u16 byte offset of the embedded link
 * pair at +0x0a -- and the node's own pair is prev at +0x00, next at +0x04.
 * Both links are cleared, head and tail both name the new element, and the
 * count goes up by one.  func_020604AC and func_02060500 both call here when
 * the list they were handed is still empty.
 *
 * The `volatile` on the list pointer is load-bearing and is the only lever
 * that moves this function.  Without it mwcc hoists the `ldrh r1, [r0, #8]`
 * of the count above the two head/tail stores, which frees r1 (the element
 * argument, dead after the stores) for the counter and the whole tail of the
 * function shifts by one register.  The image reads the count last, in source
 * order, and reuses r1 for it.  The permuter names the same mutation
 * (`volatile-add(list)`) as the single change from the plain spelling, whose
 * residue is exactly one register substitution r1 -> r2.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02060480.c \
 *       --func func_02060480 --addr 0x02060480 --cc 1.1p1 --arm
 */
void func_02060480(volatile struct DList *list, void *elem)
{
    struct DListNode *node = (struct DListNode *)((char *)elem + list->node_offset);

    node->next = 0;
    node->prev = 0;
    list->head = elem;
    list->tail = elem;
    list->count = list->count + 1;
}





/*
 * NitroSystem fnd/list.c, NNS_FndAppendListObject (append at the tail).  The library was identified from
 * the shape (head, tail, u16 count, u16 link offset) and the body follows the
 * public NitroSystem source: the link address is formed in u32 arithmetic
 * ((u32)obj + list->offset), the non-empty case is an else arm rather than an
 * early return, and the list pointer is NOT volatile.  The earlier 4-byte
 * residue (docs/notes/dlist_ops.c.txt) came from the pointer-typed add plus
 * the volatile; with the u32 add the middle is exact under both compilers and
 * the remaining count-load hoist is a 1.1p1 artefact: it closes under
 * ../2.0/sp2 (also sp1, sp2p2..sp2p4), DIFF 8 bytes under 1.1p1.
 * func_02060480 is the list's SetFirstObject step.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_020604AC.c \
 *       --func func_020604AC --addr 0x020604AC --arm --cc ../2.0/sp2
 */
void func_020604AC(NNSFndList_02060468 *list, void *object)
{
    if (list->headObject == 0)
    {
        func_02060480((volatile struct DList *)list, object);
    }
    else
    {
        NNSFndLink_02060468 *link = GetLink(list, object);
        link->prevObject = list->tailObject;
        link->nextObject = 0;
        GetLink(list, list->tailObject)->nextObject = object;
        list->tailObject = object;
        list->numObjects++;
    }
}





/*
 * NitroSystem fnd/list.c, NNS_FndPrependListObject (prepend at the head).  The library was identified from
 * the shape (head, tail, u16 count, u16 link offset) and the body follows the
 * public NitroSystem source: the link address is formed in u32 arithmetic
 * ((u32)obj + list->offset), the non-empty case is an else arm rather than an
 * early return, and the list pointer is NOT volatile.  The earlier 4-byte
 * residue (docs/notes/dlist_ops.c.txt) came from the pointer-typed add plus
 * the volatile; with the u32 add the middle is exact under both compilers and
 * the remaining count-load hoist is a 1.1p1 artefact: it closes under
 * ../2.0/sp2 (also sp1, sp2p2..sp2p4), DIFF 8 bytes under 1.1p1.
 * func_02060480 is the list's SetFirstObject step.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02060500.c \
 *       --func func_02060500 --addr 0x02060500 --arm --cc ../2.0/sp2
 */
void func_02060500(NNSFndList_02060468 *list, void *object)
{
    if (list->headObject == 0)
    {
        func_02060480((volatile struct DList *)list, object);
    }
    else
    {
        NNSFndLink_02060468 *link = GetLink(list, object);
        link->prevObject = 0;
        link->nextObject = list->headObject;
        GetLink(list, list->headObject)->prevObject = object;
        list->headObject = object;
        list->numObjects++;
    }
}






/*
 * DList insert-before: splice `elem` into the list immediately ahead of
 * `before`.  A null `before` means "no successor", i.e. append at the tail
 * (func_020604AC); a `before` that is already the head is a prepend
 * (func_02060500).  Otherwise the four links are rewritten in place.
 *
 * The node-offset load is hoisted into a local because the splice reads it
 * once and the final `before->prev` write re-reads it: the image has two
 * `ldrh [r0, #0xa]`, not one and not three.
 *
 * Order is load-bearing twice over.  The `node` pointer is computed BEFORE
 * `prev` is read, even though `prev` is used first: mwcc numbers values in
 * the order the IR creates them and colours in that order, so computing
 * `prev` first gives it ip and `node` r3, exactly inverting the image's
 * `ldr r3, [r1, lr]` / `add ip, r2, lr` pair.  Writing the two statements in
 * the other order is a five-byte, pure register-substitution residue that no
 * single mutation moves; the permuter found the same lever independently
 * (`temp(tmp=(struct DListNode *)((char *)elem + off))` lifted above the
 * `prev` read) from that five-byte baseline.  The `volatile` on the list
 * pointer is the cluster-wide shape documented on func_02060480: it keeps
 * the count read after the link stores.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02060550.c \
 *       --func func_02060550 --addr 0x02060550 --cc 1.1p1 --arm
 */
void func_02060550(volatile struct DList *list, void *before, void *elem)
{
    u16               off;
    struct DListNode *node;
    void             *prev;

    if (before == 0) {
        func_020604AC((NNSFndList_02060468 *)list, elem);
        return;
    }
    if (before == list->head) {
        func_02060500((NNSFndList_02060468 *)list, elem);
        return;
    }
    off = list->node_offset;
    node = (struct DListNode *)((char *)elem + off);
    prev = ((struct DListNode *)((char *)before + off))->prev;
    node->prev = prev;
    node->next = before;
    ((struct DListNode *)((char *)prev + off))->next = elem;
    ((struct DListNode *)((char *)before + list->node_offset))->prev = elem;
    list->count = list->count + 1;
}







/*
 * DList remove: unlink `elem` from the list and clear its own link pair.
 * Both ends are handled by the same shape -- a null neighbour means the
 * element was at that end, so the list header's own head/tail takes the
 * element's other link.  The image's conditional execution (`ldreq`/`streq`
 * paired with `ldrne`/`strne`) is mwcc if-converting both arms; no goto or
 * ternary is needed to get it.
 *
 * The node offset is read into a local for the first arm pair and re-read
 * from the list for the second `->prev` write: the image has exactly two
 * `ldrh [r0, #0xa]`, the second inside the `ne` arm (`ldrhne r1, [r0, #0xa]`),
 * which is what pins that one access to the field rather than the local.
 * The `volatile` on the list pointer is the cluster-wide shape documented on
 * func_02060480: it keeps the count read after the link stores.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020605B4.c \
 *       --func func_020605B4 --addr 0x020605B4 --cc 1.1p1 --arm
 */
void func_020605B4(volatile struct DList *list, void *elem)
{
    u16               off  = list->node_offset;
    struct DListNode *node = (struct DListNode *)((char *)elem + off);

    if (node->prev == 0) {
        list->head = node->next;
    } else {
        ((struct DListNode *)((char *)node->prev + off))->next = node->next;
    }
    if (node->next == 0) {
        list->tail = node->prev;
    } else {
        ((struct DListNode *)((char *)node->next + list->node_offset))->prev = node->prev;
    }
    node->prev = 0;
    node->next = 0;
    list->count = list->count - 1;
}





/*
 * A whole translation unit, matched as one byte range.
 *
 * DList iterators and recursive range query.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02060614.c \
 *       --addr 0x02060614 --arm
 */
void *func_02060614(struct DList *list, void *elem)
{
    if (elem == 0) {
        return list->head;
    }
    return ((struct DListNode *)((char *)elem + list->node_offset))->next;
}




void *func_0206062C(struct DList *list, void *elem)
{
    if (elem == 0) {
        return list->tail;
    }
    return ((struct DListNode *)((char *)elem + list->node_offset))->prev;
}




struct Elem *func_02060640(struct DList *list, u32 val)
{
    struct Elem *elem;
    for (elem = (struct Elem *)func_02060614(list, 0); elem != 0; elem = (struct Elem *)func_02060614(list, elem)) {
        if (elem->min_val <= val && val < elem->max_val) {
            struct Elem *res = func_02060640(&elem->sublist, val);
            if (res == 0) {
                res = elem;
            }
            return res;
        }
    }
    return 0;
}





void *func_020606A8(u32 a)
{
    void *r = &g_02146B64;
    u32 v = (u32)func_02060640((struct DList *)(&g_02146B64), a);

    if (v != 0) {
        r = (void *)(v + 0xc);
    }
    return r;
}



static inline void SetOptForHeap(NNSiFndHeapHead *pHeapHd, u16 optFlag)
{
    NNSi_FndSetBitValue(pHeapHd->attribute, 0, 8, optFlag);
}



/*
 * NitroSystem fnd heapcommon.c, NNSi_FndInitHeapHead: fill the heap header,
 * set the option byte of the attribute (SetOptForHeap as an inline over the
 * NNSi_FndSetBitValue macro), init the child list (link offset 4), create the
 * root heap list once, and append the heap to the list FindListContainHeap
 * (func_020606A8) picks.  The kept-constants tell (docs/FRONTEND-PINS.md): the
 * image passes the offset 4 as a fresh `mov r1, #4` at both NNS_FndInitList
 * calls (+0x2C, +0x4C) and reloads the latch address from the pool at +0x38
 * and +0x54 under `push {r4, lr}`.  docs/notes/func_020606D0.c.txt measured
 * the pin on an arena-registry reading of this body and found it worse; in
 * the library's shape (attribute cleared then set through the macro, signed
 * BOOL latch, header struct from heapcommon.h) ../2.0/sp2 gives 124 bytes,
 * 0 mismatches, where 1.1p1 gives 73 out.
 */
void func_020606D0(NNSiFndHeapHead *pHeapHd, u32 signature, void *heapStart, void *heapEnd, u16 optFlag)
{
    pHeapHd->signature = signature;
    pHeapHd->heapStart = heapStart;
    pHeapHd->heapEnd = heapEnd;
    pHeapHd->attribute = 0;
    SetOptForHeap(pHeapHd, optFlag);

    func_02060468((int)(&pHeapHd->childList), 4);

    if (!sRootListInitialized) {
        func_02060468((int)(&sRootList), 4);
        sRootListInitialized = 1;
    }

    func_020604AC(func_020606A8((u32)pHeapHd), pHeapHd);
}





void NHTTP_CleanupAsync(void *p)
{
    func_020605B4(func_020606A8((u32)p), p);
}





/*
 * Block extent: writes the two ends of a heap block into a two-word result.
 * out[0] is the block's own start, recovered from the size of the preceding
 * block, which the header packs into the top seven bits of the flag halfword
 * as (flags >> 8) & 0x7f.  out[1] is the block's end: the block plus the
 * 0x10-byte header plus the free-space word at +4.
 *
 * The flag halfword is loaded zero-extended but shifted arithmetically, which
 * is what an int temporary gives: the mask forces the top byte down to seven
 * bits, and re-narrowing the result to u16 is the lsl/lsr pair the sub then
 * folds into its operand.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02060764.c \
 *       --func func_02060764 --addr 0x02060764 --cc 1.1p1 --arm
 */
void func_02060764(int *out, int *blk)
{
    int f = ((struct Obj00512 *)blk)->f2;

    out[0] = (int)blk - (u16)((f >> 8) & 0x7f);
    out[1] = blk[1] + (int)(blk + 4);
}




void *func_02060790(int *p, int *node)
{
    int *a = (int *)node[2];
    int *b = (int *)node[3];
    if (a != 0)
        a[3] = (int)b;
    else
        p[0] = (int)b;
    if (b != 0)
        b[2] = (int)a;
    else
        p[1] = (int)a;
    return a;
}





void *func_020607B8(int *p, void *node, int *a)
{
    int *b;
    ((struct Obj00512 *)node)->f8 = (int)a;
    if (a != 0) {
        b = (int *)a[3];
        a[3] = (int)node;
    } else {
        b = (int *)p[0];
        p[0] = (int)node;
    }
    *(int *)&((struct Obj00512 *)node)->fC = (int)b;
    if (b != 0)
        b[2] = (int)node;
    else
        p[1] = (int)node;
    return node;
}



void *func_020607E8(int *p, int v)
{
    int *q = (int *)p[0];
    ((struct Obj00512 *)q)->f0 = (unsigned short)v;
    ((struct Obj00512 *)q)->f2 = 0;
    ((struct Obj00512 *)q)->f4 = (int)((char *)p[1] - ((char *)q + 0x10));
    ((struct Obj00512 *)q)->f8 = 0;
    *(int *)&((struct Obj00512 *)q)->fC = 0;
    return q;
}
