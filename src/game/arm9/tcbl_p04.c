/*
 * file:     tcbl_p04.c
 * unit:     yes
 * function: func_02030D28, func_02030DA4, func_02030DA8, func_02030DC8, func_02030EAC, func_02030EE8, func_02030EF0, func_02030F04, func_02030F34, func_02030F50, func_02030F70, func_02030FB4
 * address:  0x02030D28
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
 *   sub_02030C44  0x02030C44  arm
 *   sub_02030DA8  0x02030DA8  arm
 *   sub_02030DC8  0x02030DC8  arm
 *   sub_02030C68   0x02030C68  arm
 *   sub_020307B0  0x020307B0  arm
 *   sub_02030F34  0x02030F34  arm
 */
struct Ctx_02030D28;
struct Node;
struct Node_02030EAC;
struct Ctx02030C68;
struct Frame02030C68;
struct Tcbl;
struct TcblNode;
struct Node02030F34;
struct S02030F34;
typedef unsigned int u32;

struct Node {
    struct Ctx_02030D28  *owner;   /* +0x00 */
    struct Node *prev;    /* +0x04 */
    struct Node *next;    /* +0x08 */
    u32          key;     /* +0x0c */
    void        *arg;     /* +0x10 */
    void       (*fn)(struct Node *node, void *arg); /* +0x14 */
    u32          fired;   /* +0x18 */
};

struct Ctx_02030D28 {
    u32           capacity;   /* +0x00 */
    u32           top;        /* +0x04 */
    struct Node   head;       /* +0x08 */
    struct Node **freeList;   /* +0x24 */
    struct Node  *pool;       /* +0x28 */
    u32           busy;       /* +0x2c */
    struct Node  *cursor;     /* +0x30 */
    struct Node  *walk;       /* +0x34 */
    struct Node  *slots[1];   /* +0x38 */
};

typedef unsigned char u8;

struct Node_02030DA8 {
    u32          unk_00;
    struct Node_02030DA8 *unk_04;
    struct Node_02030DA8 *unk_08;
    u32          unk_0c;
    void        *unk_10;
    void       (*unk_14)(struct Node_02030DA8 *, void *);
    u32          unk_18;
};

struct Cfg {
    u8  pad_00[0xc];
    u32 unk_0c;
    u32 unk_10;
    u32 unk_14;
};

struct Ctx_02030DA8 {
    u8           pad_00[8];
    struct Node_02030DA8  head;
    u8           pad_24[8];
    u32          busy;
    struct Cfg  *unk_30;
    struct Node_02030DA8 *unk_34;
};

struct Owner {
    u8           pad_00[0x34];
    struct Node_02030EAC *head;
};

struct Node_02030EAC {
    struct Owner *owner;
    struct Node_02030EAC  *prev;
    struct Node_02030EAC  *next;
};

struct S02030EE8 {
    char pad[0x10];
    u32  field10;
};

struct S02030EF0 {
    char pad0[4];
    u32  field4;
    char pad1[0xc];
    u32  field14;
};

struct Node_02030F04 {
    char pad[4];
    struct Node_02030F04 *prev;
    struct Node_02030F04 *next;
};

struct List {
    char pad[0x34];
    struct Node_02030F04 *head;
};

struct Node02030F34 {
    u32 unk0;
    struct Node02030F34 *prev;
    struct Node02030F34 *next;
};

struct S02030F34 {
    char pad[0x34];
    struct Node02030F34 *head;
};

typedef unsigned short u16;

typedef void (*TcblFunc)(struct TcblNode *node, void *work);

struct TcblNode {
    struct Tcbl     *owner;
    struct TcblNode *prev;
    struct TcblNode *next;
    u32              key;
    void            *work;
    TcblFunc         func;
};

struct Tcbl {
    u32              count;
    u32              workSize;
    u16              unk_08;
    u16              pad_0a;
    u32              unk_0c;
    u32              destroyed;
    void            *table;
    struct TcblNode  sentinel;
    struct TcblNode *cursor;
    struct TcblNode *freeHead;
};

struct S02030FB4 {
    char  pad[0x10];
    void *field10;
    char  pad2[4];
    char  embedded[1];
};

void func_02030DA4(void);
extern struct Node_02030DA8 *sub_02030C44(struct Ctx_02030DA8 *c);
extern struct Node_02030DA8 *sub_02030DC8(struct Ctx_02030DA8 *c, void (*a)(struct Node_02030DA8 *, void *), void *b, u32 key);
extern u32 sub_02030C68(struct Ctx02030C68 *ctx, struct Frame02030C68 *frame);
extern u32 sub_020307B0(void *p);
extern void sub_02030F34(struct S02030F34 *p, struct Node02030F34 *node);




/*
 * time_icon.c tail (the task-list runtime).  One pass over the circular
 * callback list at +0x08: unless the +0x2c busy flag is set, walk from
 * head.next to the embedded sentinel through the +0x30 cursor, pre-reading
 * each successor into +0x34 so a callback may unlink its own node, and call
 * each node's callback unless its +0x18 "fired" flag is set (which is
 * cleared instead).  The loop ends with the cursor on the sentinel, whose
 * callback slot is cleared.
 *
 * The documented 13-byte "loop-carried register" residue
 * (docs/notes/sub_02030D28.c.txt) was a misread callback arity: the image
 * loads the node into r0 and node->arg into r1 before `blx r2`, so the
 * callback is fn(node, arg), not fn(arg).  With two arguments the body is
 * byte-exact under 1.1p1 -O4,p.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02030D28.c \
 *       --func func_02030D28 --addr 0x02030D28 --cc 1.1p1 --arm
 */
void func_02030D28(struct Ctx_02030D28 *c)
{
    if (c->busy != 0) {
        return;
    }

    c->cursor = c->head.next;

    while (c->cursor != &c->head) {
        c->walk = c->cursor->next;

        if (c->cursor->fired == 0) {
            if (c->cursor->fn != 0) {
                c->cursor->fn(c->cursor, c->cursor->arg);
            }
        } else {
            c->cursor->fired = 0;
        }

        c->cursor = c->walk;
    }

    c->cursor->fn = 0;
}

void func_02030DA4(void){ }



/*
 * Previously capped at MATCH: 0x02030C44 has exactly one caller image-wide,
 * the call inside sub_02030DC8 below, so no `label` witness exists and no cut
 * could free the site.  src/matched/unit_02030C44.c now reproduces the node
 * allocator's own byte range, so the PC24 at +0x34 resolves in the `matched`
 * class and the unit is EXACT.
 *
 * Insert one node into the context's circular list, kept sorted ascending on
 * the key at +0x0C, plus the re-entry wrapper that guards it.
 *
 * The two functions are one unit rather than two files because nothing in
 * the image branches to 0x02030DC8 except the wrapper: as separate files the
 * wrapper's call has no witness of any class and caps at MATCH, while in one
 * translation unit it is `local` and needs no image evidence at all
 * (docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md read the
 * other way round).
 *
 * The wrapper takes four parameters, not one.  Its own bytes never set r1,
 * r2 or r3 before the call, which is what forwarding untouched parameters
 * looks like, and the tell is the register the constant 1 lands in: `mov ip,
 * #1` before the call and `mov r1, #0` after it.  With fewer parameters
 * declared, r1 is free on both sides and the compiler uses it twice.
 *
 * The list is doubly linked through +0x04 (prev) and +0x08 (next) with the
 * sentinel embedded in the context at +0x08, which is why `c->head.unk_04`
 * is the same word as the context's +0x0C and the loop bound is the address
 * of the sentinel itself.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02030DA8.c \
 *       --addr 0x02030DA8 --arm
 */
struct Node_02030DA8 *sub_02030DA8(struct Ctx_02030DA8 *c, void (*a)(struct Node_02030DA8 *, void *), void *b, u32 key)
{
    struct Node_02030DA8 *n;

    c->busy = 1;
    n = sub_02030DC8(c, a, b, key);
    c->busy = 0;
    return n;
}

/*
 * Previously capped at MATCH: 0x02030C44 has exactly one caller image-wide,
 * the call inside sub_02030DC8 below, so no `label` witness exists and no cut
 * could free the site.  src/matched/unit_02030C44.c now reproduces the node
 * allocator's own byte range, so the PC24 at +0x34 resolves in the `matched`
 * class and the unit is EXACT.
 *
 * Insert one node into the context's circular list, kept sorted ascending on
 * the key at +0x0C, plus the re-entry wrapper that guards it.
 *
 * The two functions are one unit rather than two files because nothing in
 * the image branches to 0x02030DC8 except the wrapper: as separate files the
 * wrapper's call has no witness of any class and caps at MATCH, while in one
 * translation unit it is `local` and needs no image evidence at all
 * (docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md read the
 * other way round).
 *
 * The wrapper takes four parameters, not one.  Its own bytes never set r1,
 * r2 or r3 before the call, which is what forwarding untouched parameters
 * looks like, and the tell is the register the constant 1 lands in: `mov ip,
 * #1` before the call and `mov r1, #0` after it.  With fewer parameters
 * declared, r1 is free on both sides and the compiler uses it twice.
 *
 * The list is doubly linked through +0x04 (prev) and +0x08 (next) with the
 * sentinel embedded in the context at +0x08, which is why `c->head.unk_04`
 * is the same word as the context's +0x0C and the loop bound is the address
 * of the sentinel itself.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02030DA8.c \
 *       --addr 0x02030DA8 --arm
 */
struct Node_02030DA8 *sub_02030DC8(struct Ctx_02030DA8 *c, void (*a)(struct Node_02030DA8 *, void *), void *b, u32 key)
{
    struct Node_02030DA8 *n;
    struct Node_02030DA8 *p;

    n = sub_02030C44(c);
    if (n == 0) {
        return 0;
    }

    n->unk_0c = key;
    n->unk_10 = b;
    n->unk_14 = a;

    if (c->unk_30->unk_14 != 0) {
        if (c->unk_30->unk_0c <= key) {
            n->unk_18 = 1;
        } else {
            n->unk_18 = 0;
        }
    } else {
        n->unk_18 = 0;
    }

    for (p = c->head.unk_08; p != &c->head; p = p->unk_08) {
        if (p->unk_0c > n->unk_0c) {
            n->unk_04 = p->unk_04;
            n->unk_08 = p;
            p->unk_04->unk_08 = n;
            p->unk_04 = n;
            if (p == c->unk_34) {
                c->unk_34 = n;
            }
            return n;
        }
    }

    if (c->unk_34 == &c->head) {
        c->unk_34 = n;
    }
    n->unk_04 = c->head.unk_04;
    n->unk_08 = &c->head;
    c->head.unk_04->unk_08 = n;
    c->head.unk_04 = n;
    return n;
}


/*
 * Unlink one node from its owner's doubly-linked list and then tail-call
 * sub_02030C68 on the owner.  The node carries its owner at +0, its
 * predecessor at +4 and its successor at +8; the owner's list head is at
 * +0x34 and is advanced to the successor when the node being removed is
 * the head.
 *
 * `ldmib r1, {r0, r2}` is the paired load of the two link fields, not an
 * aggregate copy: the head fix-up above it is predicated, so there is no
 * branch anywhere in the function and the scheduler is free to fold the
 * two loads.  The links are then re-loaded for the second unlink store
 * because the first store may alias them.
 *
 * The `mov r1, r0` that opens the function is the arity tell: nothing in
 * the body reads r1, and r1 is not callee-saved, so the only reason to
 * spend an instruction parking the node there is that the tail call
 * needs it as a second argument.  Written as a one-argument call the
 * whole function comes out four bytes shorter with the node left in r0,
 * every concrete byte shifted by one instruction.  See
 * docs/idioms/a-parameter-moved-out-of-r0-at-entry-names-the-tail-calls-arity.md.
 *
 * 0x02030C68 has no branch witness of its own: this function is its only
 * reference image-wide.  The site resolves on class `matched` against
 * src/matched/unit_02030C68.c.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02030EAC.c \
 *       --func sub_02030EAC --addr 0x02030EAC --cc 1.1p1 --arm
 */
void sub_02030EAC(struct Node_02030EAC *n)
{
    struct Owner *o = n->owner;

    if (o->head == n) {
        o->head = n->next;
    }
    n->prev->next = n->next;
    n->next->prev = n->prev;
    sub_02030C68((struct Ctx02030C68 *)n->owner, (struct Frame02030C68 *)n);
}


/*
 * A plain word accessor at offset 0x10. No relocations.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02030EE8.c \
 *       --func sub_02030EE8 --addr 0x02030EE8 --cc 1.1p1
 */
u32 sub_02030EE8(struct S02030EE8 *p)
{
    return p->field10;
}


/*
 * Row address of a stride-`field4 + 0x18` table: `idx * (p->field4 + 0x18)
 * + p->field14`, the `mla` idiom for an index times a runtime stride plus a
 * base. No relocations.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02030EF0.c \
 *       --func sub_02030EF0 --addr 0x02030EF0 --cc 1.1p1
 */
u32 sub_02030EF0(struct S02030EF0 *p, u32 idx)
{
    return idx * (p->field4 + 0x18) + p->field14;
}


struct Node_02030F04 *func_02030F04(struct List *list)
{
    struct Node_02030F04 *head = list->head;
    if (head == 0) {
        return 0;
    }
    list->head = head->next;
    if (head->next != 0) {
        head->next->prev = 0;
    }
    return head;
}


/*
 * Doubly linked list push-front: clears the new node's prev, chains it in
 * front of the current head, fixes the old head's back pointer if there
 * was one, and stores the new node as the head. No relocations.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02030F34.c \
 *       --func sub_02030F34 --addr 0x02030F34 --cc 1.1p1
 */
void sub_02030F34(struct S02030F34 *p, struct Node02030F34 *node)
{
    struct Node02030F34 *old = p->head;
    node->prev = 0;
    node->next = old;
    if (old != 0) {
        old->prev = node;
    }
    p->head = node;
}



/*
 * Reset one task-callback node to the "not in the live list" state: owner
 * back-pointer, both links parked on the manager's sentinel at +0x18, and
 * the three payload words cleared.  It is the shape sub_02030C68 has for the
 * timer pool in src/matched/unit_02030C44.c, one layer up.
 *
 * A leaf: no lr is saved, so disasm.py gives it no label of its own and the
 * function is only visible by address
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md does not apply
 * here only because the callers name it).
 *
 * The owner and the prev link are one `stm r1, {r0, r3}`, which is what two
 * adjacent word stores of two already-live registers collapse to; the zero is
 * materialised between them, filling the load slot.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02030F50.c \
 *       --func sub_02030F50 --addr 0x02030F50 --cc 1.1p1 --arm
 */
void sub_02030F50(struct Tcbl *p, struct TcblNode *n)
{
    n->owner = p;
    n->prev = &p->sentinel;
    n->next = &p->sentinel;
    n->key = 0;
    n->work = 0;
    n->func = 0;
}


/*
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


/*
 * Returns a stored pointer at +0x10, or the address of an embedded object
 * at +0x18 when that pointer is null: the "owned or embedded" accessor
 * shape. No relocations.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02030FB4.c \
 *       --func sub_02030FB4 --addr 0x02030FB4 --cc 1.1p1
 */
void *sub_02030FB4(struct S02030FB4 *p)
{
    void *v = p->field10;
    if (v == 0) {
        v = &p->embedded;
    }
    return v;
}
