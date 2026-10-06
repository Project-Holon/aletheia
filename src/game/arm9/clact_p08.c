/*
 * file:     clact_p08.c
 * unit:     yes
 * function: func_0204C98C, func_0204CA30, func_0204CA74, func_0204CAAC, func_0204CAE4, func_0204CB44
 * address:  0x0204C98C
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
 *   func_0204B838  0x0204B838  arm
 *   func_0204CA74  0x0204CA74  arm
 *   func_0204CAAC  0x0204CAAC  arm
 *   sub_0204B838  0x0204B838  arm
 *   sub_02082BCC  0x02082BCC  arm
 *   sub_02063790  0x02063790  arm
 *   sub_020637D4  0x020637D4  arm
 *   func_02066748  0x02066748   12 bytes  -- veneer, resolves `veneer`
 *   func_02065BD0  0x02065BD0  168 bytes  -- OPEN, docs/notes/func_02065BD0.c.txt
 *   func_0204CBB0  0x0204CBB0  188 bytes  -- closed, resolves `matched`
 *   func_0204BA7C  0x0204BA7C  112 bytes  -- closed, resolves `matched`
 *   func_0204CC6C  0x0204CC6C  584 bytes  -- OPEN, soft-float, multi-function
 *   func_02065C78  0x02065C78  108 bytes  -- closed, resolves `matched`
 */
struct Node;
struct Rec;
typedef unsigned char u8;

typedef unsigned int  u32;

typedef struct Node0204C98C Node0204C98C;

struct Node0204C98C {
    Node0204C98C *next;
    Node0204C98C *prev;
};

typedef struct {
    u32            unk00;
    Node0204C98C  *head;
} List0204C98C;

struct Node_0204CA30 {
    struct Node_0204CA30 *f0;
    struct Node_0204CA30 *f4;
};

struct Mgr {
    u8           pad_000[4];
    struct Node_0204CA30 *head;
};

struct Node_0204CA74 {
    struct Node_0204CA74 *prev;
    void        *payload;
};

struct Node_0204CAAC {
    struct Node_0204CAAC *prev;
    struct Node_0204CAAC *next;
};

struct Obj {
    u8  pad_00[0x14];
    u32 unk_14;
    u32 unk_18;
    u8  unk_1c[0x24];
    u8  unk_40[0x14];
    u32 unk_54;
    u8  pad_58[8];
    u32 flag_lo   : 8;
    u32 mode      : 4;
    u32 flag_mid  : 6;
    u32 kind      : 2;
    u32 flag_hi   : 11;
    u32 done      : 1;
    u8  pad_64[0x80];
};

struct Elem {
    u8  pad00[0x1c]; /* 0x00 */
    u8  unk1c[0x24]; /* 0x1c */
    u8  unk40[0x20]; /* 0x40 */
    u32 pad60_0 : 12;
    u32 unk60_c : 4;  /* 0x60, bits 12-15 */
    u32 pad60_1 : 10;
    u32 enabled : 1;  /* 0x60, bit 26 */
    u32 pad60_2 : 4;
    u32 unk60_1f : 1; /* 0x60, bit 31 */
};

typedef unsigned short u16;

extern int func_0204B838(int a0);
extern void *func_0204CA74(struct Node *head, u32 key);
extern struct Node *func_0204CAAC(struct Node *head, u32 key);
extern int sub_0204B838(int a0);
extern void sub_02082BCC(void *dst, int value, u32 len);
extern void sub_02063790(u32 *p);
extern void sub_020637D4(u32 *p);
extern void func_02066748(int *a0, int a1, int a2);
extern void func_02065BD0(void *obj);
extern void func_0204CBB0(struct Elem *e, struct Rec *r);
extern void func_0204BA7C(u32 set, u16 bias, u32 v);
extern u32  func_0204CC6C(struct Elem *e);
extern void func_02065C78(u32 a);
void func_0204C98C(List0204C98C *a0, Node0204C98C *a1);


/*
 * Sorted insert into a circular doubly-linked list whose head pointer sits
 * at a0+4 and whose links are {next @0, prev @4}.  The empty list seeds a
 * self-loop; a first key below the head's key goes in front of the tail;
 * otherwise the average of the head and tail keys picks the half to search
 * and func_0204CA74/func_0204CAAC return the node to insert after.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204C98C.c \
 *       --func func_0204C98C --addr 0x0204C98C --cc 1.1p1
 */
void func_0204C98C(List0204C98C *a0, Node0204C98C *a1)
{
    Node0204C98C *pos;

    if (a0->head == 0) {
        a0->head = a1;
        a1->next = a1;
        a0->head->prev = a1;
        return;
    }
    {
        u32 key = func_0204B838((int)a1);
        u32 headkey = func_0204B838((int)a0->head);
        u32 tailkey;
        u8  avg;

        if (key < headkey) {
            pos = a0->head->prev;
            a0->head = a1;
        } else {
            tailkey = func_0204B838((int)a0->head->prev);
            avg = (u8)((int)(headkey + tailkey) / 2);
            if (avg >= key) {
                pos = func_0204CA74((struct Node *)a0->head, key);
            } else {
                pos = (Node0204C98C *)func_0204CAAC((struct Node *)a0->head->prev, key);
            }
        }
    }
    a1->prev = pos;
    a1->next = pos->next;
    pos->next->prev = a1;
    pos->next = a1;
}


/*
 * Unlink a node from a doubly linked list whose head pointer lives at +4 of
 * the manager.  A node whose own forward pointer is itself is the only
 * entry, so the manager's head is cleared instead of taking the link.  Both
 * arms of that inner if write the head, which is why the store is a
 * conditional pair rather than one unconditional store.
 */
void func_0204CA30(struct Mgr *m, struct Node_0204CA30 *l)
{
    if (m->head == l) {
        if (l->f0 == l) {
            m->head = 0;
        } else {
            m->head = l->f0;
        }
    }
    l->f0->f4 = l->f4;
    l->f4->f0 = l->f0;
    l->f0 = 0;
    l->f4 = 0;
}


/*
 * Walk the circular list backwards from `head` and return the payload of
 * the first node whose key sorts strictly above `key`; if the walk comes
 * all the way round, the head's own payload is the answer.
 *
 * The list is circular, so the test is at the bottom and the loop is a
 * `do`/`while`: a `while` would have added an entry test the original does
 * not have.  `hi` rather than `gt` fixes the comparison as unsigned.  The
 * hit arm is two predicated instructions, `ldrhi` and `pophi`, so it never
 * reaches the shared tail.
 *
 * Its mirror image sub_0204CAAC walks the same list forwards, returns the
 * node instead of the payload and inverts the condition.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204CA74.c \
 *       --func sub_0204CA74 --addr 0x0204CA74 --cc 1.1p1 --arm
 */
void *sub_0204CA74(struct Node_0204CA74 *head, u32 key)
{
    struct Node_0204CA74 *n = head;

    do {
        if (sub_0204B838((int)n) > key) {
            return n->payload;
        }
        n = n->prev;
    } while (n != head);

    return head->payload;
}


/*
 * The forward half of the pair that opens this packet: walk the circular
 * list through its `next` links and return the first node whose key does
 * not sort above `key`, falling back on the head's `prev` when the walk
 * comes all the way round.
 *
 * Where sub_0204CA74 returns a payload, this one returns the node itself,
 * which is the whole difference between `ldrhi r0, [r4, #4]` there and
 * `movls r0, r4` here.  The polarity is the other way round too: `ls`, the
 * complement of the sibling's `hi`.
 *
 * The two are separate translation units in the image, not one: each gets
 * its own `bl 0x204b838` and its own copy of the loop.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204CAAC.c \
 *       --func sub_0204CAAC --addr 0x0204CAAC --cc 1.1p1 --arm
 */
struct Node_0204CAAC *sub_0204CAAC(struct Node_0204CAAC *head, u32 key)
{
    struct Node_0204CAAC *n = head;

    do {
        if (sub_0204B838((int)n) <= key) {
            return n;
        }
        n = n->next;
    } while (n != head);

    return head->prev;
}


/*
 * The constructor for the 0xe4-byte object this packet operates on: wipe
 * it, initialise the two embedded sub-objects at +0x1c and +0x40, set the
 * three 0x1000 scale fields, and fix up the flag word at +0x60.
 *
 * The flag word is one load and one store for three separate bitfield
 * assignments, which is the whole reason this function is worth reading:
 * the 4-bit field at bit 8 is a read-modify-write (`lsl #20; lsr #28; orr
 * #1; lsl #28; ... lsr #20` around a `bic #0xf00`), while the two fields
 * being set to zero collapse into plain `bic`s of their masks.  Only the
 * field whose new value depends on its old one pays for the extract and
 * reinsert.
 *
 * 0x1000 is materialised once into r4 and reused for all three stores; the
 * compiler spreads those stores across the two calls rather than keeping
 * them together, so their position in the listing is not their position in
 * the source.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204CAE4.c \
 *       --func sub_0204CAE4 --addr 0x0204CAE4 --cc 1.1p1 --arm
 */
void sub_0204CAE4(struct Obj *o)
{
    sub_02082BCC(o, 0, 0xe4);
    o->unk_54 = 0x1000;
    sub_02063790((u32 *)o->unk_1c);
    sub_020637D4((u32 *)o->unk_40);
    o->unk_14 = 0x1000;
    o->unk_18 = 0x1000;
    o->mode |= 1;
    o->done = 0;
    o->kind = 0;
}


/*
 * Blocked at MATCH on the `label`/`matched` classes: all 108 concrete bytes
 * are right, but every one of the six callees has exactly one branch
 * reference image-wide and it is the call in this function, so none of the
 * six can be witnessed and no cut frees any of them.  Four of the six are
 * now closed and the file is at 4 of 6 relocation sites resolved:
 *
 *   func_02066748  0x02066748   12 bytes  -- veneer, resolves `veneer`
 *   func_02065BD0  0x02065BD0  168 bytes  -- OPEN, docs/notes/func_02065BD0.c.txt
 *   func_0204CBB0  0x0204CBB0  188 bytes  -- closed, resolves `matched`
 *   func_0204BA7C  0x0204BA7C  112 bytes  -- closed, resolves `matched`
 *   func_0204CC6C  0x0204CC6C  584 bytes  -- OPEN, soft-float, multi-function
 *   func_02065C78  0x02065C78  108 bytes  -- closed, resolves `matched`
 *
 * func_02066748 is not decompilable and never will be.  It is a twelve-byte
 * ARM linker veneer, `ldr ip, [pc]; bx ip; .word 0x02067AA0`, and the
 * `veneer` attestation class used to refuse it because 0x02067AA0 was an
 * unlabelled three-instruction leaf (`str r1, [r0, #8]; str r2, [r0, #0xc];
 * bx lr`) that `disasm.py` never labels, so `names_known_code()` failed.  The
 * integrator seeded 0x02067AA0 into layout/function_starts.txt before wave
 * 25 and the site now resolves `veneer` with no change to any source file,
 * exactly as
 * docs/idioms/a-veneer-attests-nothing-while-its-target-is-an-unlabelled-leaf.md
 * predicted.
 *
 * What remains is func_02065BD0, a 24-byte codegen near miss over one
 * zero-register allocation (the note names every spelling tried), and
 * func_0204CC6C, 584 bytes of soft-float record publishing that nobody has
 * attempted yet.  This function is itself the sole blocker for
 * src/pending/func_0204C944.c, which is the sole blocker named in
 * docs/notes/clact_c_fan_in_1_blockers.c.txt for src/pending/func_0204BB8C.c,
 * which is one of the two blockers of src/pending/sub_0204A600.c (the other
 * is 0x02066998).
 *
 * Per-element teardown.  Guarded by bit 26 of the flag word at +0x60; the
 * two values handed to func_0204BA7C are bits 12-15 (narrowed to u8, which
 * is what the otherwise redundant `and r1, r1, #0xff` after the shift pair
 * records) and bit 31 of the same word, read through one load.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0204CB44.c \
 *       --func func_0204CB44 --addr 0x0204CB44 --cc 1.1p1 --arm
 */
void func_0204CB44(struct Elem *e, u32 arg)
{
    if (e->enabled == 0)
        return;

    func_02066748((int *)arg, (int)e->unk1c, (int)e->unk40);
    func_02065BD0((void *)arg);
    func_0204CBB0(e, (struct Rec *)arg);
    func_0204BA7C((u32)e->unk40, (u8)e->unk60_c, e->unk60_1f);
    func_02065C78(func_0204CC6C(e));
}
