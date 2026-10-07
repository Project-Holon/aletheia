/*
 * file:     unit_02060468_p03.c
 * unit:     yes
 * function: func_02060550, func_020605B4, func_02060614, func_0206062C, func_02060640, func_020606A8
 * address:  0x02060550
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020604AC  0x020604AC  arm
 *   func_02060500  0x02060500  arm
 *   g_02146B64       0x02146B64  data
 *   func_02060640    0x02060640  arm
 */
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

typedef unsigned int   u32;

struct Elem {
    char pad00[0x0c];
    struct DList sublist;
    u32 min_val;
    u32 max_val;
};

typedef unsigned char u8;

extern void func_020604AC(volatile struct DList *list, void *elem);
extern void func_02060500(volatile struct DList *list, void *elem);
extern struct Elem *func_02060640(struct DList *list, u32 val);
void *func_020606A8(u32 a);
extern u32 g_02146B64;



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
        func_020604AC(list, elem);
        return;
    }
    if (before == list->head) {
        func_02060500(list, elem);
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
