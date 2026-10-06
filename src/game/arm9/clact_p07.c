/*
 * file:     clact_p07.c
 * unit:     yes
 * function: func_0204C83C, func_0204C8A4, func_0204C8B8, func_0204C8E4, func_0204C944
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
 *   func_0204C8A4  0x0204C8A4  arm
 *   g_020A138C     0x020A138C  data
 *   DC_FlushRange  0x020862F0  arm
 *   sub_02034714  0x02034714  arm
 *   s_FileName    0x020A7F74  data
 *   func_0204CB44  0x0204CB44  arm
 */
struct Entry;
struct Pool;
struct Obj;
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

struct Obj {
    u32 unk_00;
    u8  pad_04[0xe0];
};

struct Owner {
    struct Obj *objs;
    u8          pad_04[8];
    u16         count;
};

struct AssertStrings {
    char file[8];
    char expr0[4];
};

struct Elem {
    struct Elem *next;  /* 0x00 */
};

struct Ring {
    u8            pad_00[4];
    struct Elem  *head;   /* 0x04 */
    u32           arg;    /* 0x08 */
    u8            pad_0c[2];
    u8            flags_lo : 4;  /* 0x0e */
    u8            flags_hi : 4;
};

extern struct Entry *func_0204C804(struct Pool *p);
extern void func_0204C8A4(struct Entry *e, u32 sel, u32 a, u32 b, u32 c);
extern void DC_FlushRange(void *addr, u32 size);
extern void sub_02034714(const char *file, u32 line, const char *expr);
extern void func_0204CB44(struct Elem *e, u32 arg);
extern void sub_0204CEB4(struct Obj *o);
u32 func_0204C83C(u32 kind, u32 a, u32 b, u32 c);
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
struct Obj *sub_0204C8E4(struct Owner *ow)
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
    struct Elem *cur;

    if (b->flags_hi == 0) {
        return;
    }

    cur = b->head;
    if (cur == 0) {
        return;
    }

    do {
        func_0204CB44(cur, b->arg);
        sub_0204CEB4((struct Obj *)cur);
        cur = cur->next;
    } while (cur != b->head);
}
