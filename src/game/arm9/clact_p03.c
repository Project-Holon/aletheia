/*
 * file:     clact_p03.c
 * unit:     yes
 * function: func_0204C83C, func_0204C8A4, func_0204C8B8, func_0204C8E4, func_0204C944, func_0204C98C, func_0204CA30, func_0204CA74, func_0204CAAC, func_0204CAE4, func_0204CB44
 * address:  0x0204C83C
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
 *   g_02146A74     0x02146A74  data
 *   func_0204C804  0x0204C804  arm
 *   g_020A138C     0x020A138C  data
 *   DC_FlushRange  0x020862F0  arm
 *   sub_02034714  0x02034714  arm
 *   s_FileName    0x020A7F74  data
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
struct Entry;
struct Pool;
struct Obj_0204C83C;
struct Node;
struct Rec;
typedef unsigned char u8;

typedef unsigned int  u32;

struct Sub {
    u8 pad_00[4];
};

struct Sys {
    u8         pad_000[0xe0];
    struct Sub unk_0e0;   /* 0xe0 */
};

struct Entry {
    u32 unk_00;   /* 0x00 */
    u32 unk_04;   /* 0x04 */
    u32 unk_08;   /* 0x08 */
    u32 unk_0c;   /* 0x0c */
};

struct Xfer {
    void *src;
    u32   unk_04;
    u32   size;
    u32   kind;
};

typedef unsigned short u16;

struct Obj_0204C83C {
    u32 unk_00;
    u8  pad_04[0xe0];
};

struct Owner {
    struct Obj_0204C83C *objs;
    u8          pad_04[8];
    u16         count;
};

struct AssertStrings {
    char file[8];
    char expr0[4];
};

struct Elem_0204C83C {
    struct Elem_0204C83C *next;  /* 0x00 */
};

struct Ring {
    u8            pad_00[4];
    struct Elem_0204C83C  *head;   /* 0x04 */
    u32           arg;    /* 0x08 */
    u8            pad_0c[2];
    u8            flags_lo : 4;  /* 0x0e */
    u8            flags_hi : 4;
};

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

struct Obj_0204C98C {
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

struct Elem_0204C98C {
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

extern struct Entry *func_0204C804(struct Pool *p);
extern void DC_FlushRange(void *addr, u32 size);
extern void sub_02034714(const char *file, u32 line, const char *expr);
extern void sub_0204CEB4(struct Obj_0204C83C *o);
extern int func_0204B838(int a0);
extern void *func_0204CA74(struct Node *head, u32 key);
extern struct Node *func_0204CAAC(struct Node *head, u32 key);
extern int sub_0204B838(int a0);
extern void sub_02082BCC(void *dst, int value, u32 len);
extern void sub_02063790(u32 *p);
extern void sub_020637D4(u32 *p);
extern void func_02066748(int *a0, int a1, int a2);
extern void func_02065BD0(void *obj);
extern void func_0204CBB0(struct Elem_0204C98C *e, struct Rec *r);
extern void func_0204BA7C(u32 set, u16 bias, u32 v);
extern u32  func_0204CC6C(struct Elem_0204C98C *e);
extern void func_02065C78(u32 a);
u32 func_0204C83C(u32 kind, u32 a, u32 b, u32 c);
void func_0204C8A4(struct Entry *e, u32 sel, u32 a, u32 b, u32 c);
void func_0204C8B8(struct Xfer *x);
struct Obj_0204C83C *sub_0204C8E4(struct Owner *ow);
void func_0204C944(struct Ring *b);
void func_0204C98C(List0204C98C *a0, Node0204C98C *a1);
void func_0204CA30(struct Mgr *m, struct Node_0204CA30 *l);
void *sub_0204CA74(struct Node_0204CA74 *head, u32 key);
struct Node_0204CAAC *sub_0204CAAC(struct Node_0204CAAC *head, u32 key);
void sub_0204CAE4(struct Obj_0204C98C *o);
void func_0204CB44(struct Elem_0204C98C *e, u32 arg);
extern struct Sys *g_02146A74;
extern const struct AssertStrings s_FileName;



/*
 * The per-record callback src/matched/func_0204C660.c hands to func_02066934,
 * which is why its address only ever appears as a pool word and never as a
 * branch target.
 *
 * The selector local really is uninitialised on the path where the first
 * argument is neither 0x13 nor 0x23: r4 is written only inside the two
 * predicated arms and is read again at the call below, with no `mov r4, ...`
 * on the fall-through.  Giving it a default value in the C adds that `mov`
 * and four bytes, so the original's C had an `if`/`else if` with no `else`.
 *
 * The handle passed to func_0204C8A4 is func_0204C804's return value left in
 * r0, not a reload; the selector chain in between touches only r4 and the
 * flags.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204C83C.c \
 *       --func func_0204C83C --addr 0x0204C83C --cc 1.1p1 --arm
 */
u32 func_0204C83C(u32 kind, u32 a, u32 b, u32 c)
{
    void *h;
    u32   sel;

    h = func_0204C804((struct Pool *)(&g_02146A74->unk_0e0));

    if (kind == 0x13) {
        sel = 0;
    } else if (kind == 0x23) {
        sel = 1;
    }

    if (c != 0) {
        func_0204C8A4(h, sel, a, b, c);
    }

    return 1;
}



/*
 * Fill one 0x10-byte pool entry.  A leaf with five arguments, so the last one
 * is read straight back off the caller's stack with no frame at all.
 *
 * The store order in the source is +0x0c, +0x00, +0x04, +0x08: only the last
 * two are adjacent in both address and source order, which is what lets the
 * compiler fuse them into `stmib r0, {r2, ip}`.  Writing the four fields in
 * address order would fuse three of them instead and change the encoding.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204C8A4.c \
 *       --func func_0204C8A4 --addr 0x0204C8A4 --cc 1.1p1 --arm
 */
void func_0204C8A4(struct Entry *e, u32 sel, u32 a, u32 b, u32 c)
{
    e->unk_0c = sel;
    e->unk_00 = b;
    e->unk_04 = a;
    e->unk_08 = c;
}



extern void (*g_020A138C[])(void *src, u32 arg, u32 size);



/*
 * Blocked at MATCH: all 44 concrete bytes are correct, but the ABS32 at
 * +0x0028 (the handler table at 0x020A138C) has no witness.  The table is
 * plain data, so only the `literal` class could attest it, and the pool word
 * inside this function is the address's only occurrence image wide; there is
 * no second site.  The same wall docs/notes/clact_c_fan_in_1_blockers.c.txt
 * describes for 0x0204C83C, but without its escape: there the address was a
 * function that could be decompiled to EXACT and become a `matched` witness,
 * here it is a table and nothing compiles it.
 *
 * Run one 16-byte transfer record: flush the source range out of the data
 * cache, then dispatch on the record's fourth word through the handler table
 * at 0x020A138C, passing the other three words.
 *
 * The four words are read back with a single `ldm r4, {r0, r1, r2, ip}`,
 * which is the compiler combining four consecutive field loads, not a struct
 * copy: the first and third are loaded a second time here because
 * DC_FlushRange may have written them.
 *
 * This function is the sole blocker for src/pending/func_0204C7A4.c, whose
 * only call to it is the one branch reference it has image wide.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0204C8B8.c \
 *       --func func_0204C8B8 --addr 0x0204C8B8 --cc 1.1p1 --arm
 */
void func_0204C8B8(struct Xfer *x)
{
    DC_FlushRange(x->src, x->size);
    g_020A138C[x->kind](x->src, x->unk_04, x->size);
}



/*
 * The slot allocator for the 0xe4-byte display object: walk the owner's
 * array of `count` records and return the first whose word 0 is zero, or
 * fail the GF_ASSERT(0) at calct.c:5204 and return NULL.
 *
 * 0xe4 is not a power of two, so the index is a real `mul` against a
 * materialised element size rather than a shift; the size constant lands in
 * r0 on top of the owner pointer because the count and the array base are
 * both hoisted out of the loop before the first iteration and the owner is
 * dead from there on.  The `ble` guard is signed, which is what a plain
 * `int i` compared against a `u16` field gives: the field zero-extends into
 * an int and the comparison stays signed.
 *
 * The two `__FILE__`/expression strings are one object here, not two.  The
 * file-name string 0x020A7F74 has 92 pool witnesses image-wide, but the
 * expression string "0" at 0x020A7F7C is pooled only by this function, and
 * it is one character long, below the string class's minimum run, so
 * `string` cannot fix it from the preceding terminator either (which is
 * what docs/idioms/a-string-after-a-data-table-has-no-witness.md describes
 * from the other side).  Declaring this translation unit's string area as
 * a single object whose second member starts at +8, the length of
 * "calct.c" including its terminator, puts both relocations on the attested
 * base and takes the +8 from the C.  Same bytes, same two pool words.  See
 * docs/idioms/an-assert-expression-string-rides-the-file-name-symbol.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204C8E4.c \
 *       --func sub_0204C8E4 --addr 0x0204C8E4 --cc 1.1p1 --arm
 */
struct Obj_0204C83C *sub_0204C8E4(struct Owner *ow)
{
    int i;

    for (i = 0; i < ow->count; i++) {
        if (ow->objs[i].unk_00 == 0) {
            return &ow->objs[i];
        }
    }

    sub_02034714(s_FileName.file, 5204, s_FileName.expr0);
    return 0;
}



/*
 * Blocked at MATCH: all 72 concrete bytes are correct and sub_0204CEB4
 * resolves `matched`, but the call to func_0204CB44 (+0x0028) has no
 * witness: 0204CB44 has exactly one branch reference image wide, this
 * call, so no cut frees it. func_0204C944 itself was the blocker named in
 * docs/notes/clact_c_fan_in_1_blockers.c.txt for func_0204BB8C; closing it
 * only traded one fan-in-1 blocker for another one level down
 * (func_0204CB44, 108 bytes, not otherwise investigated here).
 *
 * Guarded by the top nibble of the byte at +0xe (the low nibble is never
 * tested here, hence the `lsl #0x18; lsrs #0x1c` rather than a plain
 * `ldrb`/`ands`) and by the ring head at +0x04 being non-null. Then walk
 * that ring (the node's own +0x00 is its `next`, same shape as
 * func_0204BB8C's bank ring) running func_0204CB44 and sub_0204CEB4 (the
 * latter already matched, src/matched/sub_0204CEB4.c) over every member.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204C944.c \
 *       --func func_0204C944 --addr 0x0204C944 --cc 1.1p1 --arm
 */
void func_0204C944(struct Ring *b)
{
    struct Elem_0204C83C *cur;

    if (b->flags_hi == 0) {
        return;
    }

    cur = b->head;
    if (cur == 0) {
        return;
    }

    do {
        func_0204CB44((struct Elem_0204C98C *)cur, b->arg);
        sub_0204CEB4((struct Obj_0204C83C *)cur);
        cur = cur->next;
    } while (cur != b->head);
}



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
void sub_0204CAE4(struct Obj_0204C98C *o)
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
void func_0204CB44(struct Elem_0204C98C *e, u32 arg)
{
    if (e->enabled == 0)
        return;

    func_02066748((int *)arg, (int)e->unk1c, (int)e->unk40);
    func_02065BD0((void *)arg);
    func_0204CBB0((struct Elem_0204C98C *)e, (struct Rec *)arg);
    func_0204BA7C((u32)e->unk40, (u8)e->unk60_c, e->unk60_1f);
    func_02065C78(func_0204CC6C((struct Elem_0204C98C *)e));
}
