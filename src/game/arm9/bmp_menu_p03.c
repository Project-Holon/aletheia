/*
 * file:     bmp_menu_p03.c
 * unit:     yes
 * function: func_0201F79C, func_0201F7A8, func_0201F81C, func_0201F868, func_0201F878, func_0201F898, func_0201F8B8, func_0201F8F4, func_0201F91C, func_0201F93C
 * address:  0x0201F79C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201F73C  0x0201F73C  thumb
 *   func_02045730  0x02045730  arm
 *   func_02045748  0x02045748  arm
 *   func_02045750  0x02045750  arm
 *   func_02045758  0x02045758  arm
 *   func_02045760  0x02045760  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02041300  0x02041300  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_02030734        0x02030734  arm
 *   sBmpMenuWorkFile     0x020A7374  data
 *   func_0201F8F4  0x0201F8F4  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_0201F8B8  0x0201F8B8  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045874  0x02045874  arm
 *   func_02045808  0x02045808  arm
 *   sBmpMenuFile    0x020A7384  data
 *   func_02020D18   0x02020D18  thumb
 *   func_02020DC8   0x02020DC8  thumb
 *   func_0201FC1C   0x0201FC1C  thumb
 *   func_0201FC5C   0x0201FC5C  thumb
 *   func_0201FD18   0x0201FD18  thumb
 */
struct Descriptor;
struct Slot;
struct MsgBank;
struct U16Vec;
struct Obj;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char u8;

typedef struct {
    const void *str;    /* +0x00 */
    u32         param;  /* +0x04 */
} BmpMenuWork;

struct Slot {
    union {
        u32   raw;
        void *ptr;
    } u;
    u32 tag;
};

typedef struct {
    u32 unk00[3];
    u16 unk0c;
    u16 unk0e;
    u32 unk10[5];
} BmpMenuHeader;

typedef struct {
    BmpMenuHeader hdr;  /* +0x00 */
    void *cursor;       /* +0x24 */
    u32 cancel;         /* +0x28 */
    u8  pad2c;
    u8  pos;            /* +0x2D */
    u8  width;          /* +0x2E */
    u8  px;             /* +0x2F */
    u8  py;             /* +0x30 */
    u8  xmax;           /* +0x31 */
    u8  ymax;           /* +0x32 */
    u8  lastDir;        /* +0x33 */
    u16 heap;           /* +0x34 */
    u16 pad36;
} BmpMenu;

extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern u8 func_02045730(struct Descriptor *p);
extern u8 func_02045748(struct Descriptor *p);
extern u8 func_02045750(struct Descriptor *p);
extern u8 func_02045758(struct Descriptor *p);
extern u8 func_02045760(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern void func_02041B6C(u32 bit);
extern void func_02041300(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5,
                          u8 a6);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_0201F8F4(struct Slot *s);
extern u32 func_020307B0(void *p);
extern struct Slot *func_0201F8B8(struct Slot *s, u32 *tag_out);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct U16Vec *func_02045874(struct U16Vec *src, u32 heapId);
extern void func_02045808(struct U16Vec *vec);
extern void *func_02020D18(u32 heap);
extern void func_02020DC8(char *p, int a);
extern u32 func_0201FC1C(struct Obj *o);
extern void  func_0201FC5C(BmpMenu *m);
extern void  func_0201FD18(BmpMenu *m);
void func_0201F79C(void *desc, u32 kind, u32 base, u32 pal);
void func_0201F7A8(void *desc, u32 kind);
BmpMenuWork *func_0201F81C(u32 n, u32 heap);
u32 func_0201F868(void *p);
BmpMenu *func_0201F93C(const BmpMenuHeader *hdr, u8 px, u8 py, u8 pos, u16 heap, u32 cancel);
extern char sBmpMenuWorkFile[];
extern char sBmpMenuFile[];





/*
 * A width-narrowing wrapper on func_0201F73C, and the only evidence in the
 * image that func_0201F73C's third parameter is u16: the single
 * `lsls #16 / lsrs #16` pair here is the argument conversion, so the wrapper
 * takes the tile base as a full word and the worker takes it as a halfword.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201F79C.c \
 *       --func func_0201F79C --addr 0x0201F79C --cc 1.1p1 --thumb
 */
void func_0201F79C(void *desc, u32 kind, u32 base, u32 pal)
{
    func_0201F73C(desc, kind, (u16)base, pal);
}





/*
 * The sibling of func_0201F73C: the same five ARM byte accessors on the same
 * descriptor, but the four geometry bytes are adjusted before the call, the
 * two extents shrunk by one and the two origins grown by two, and the worker
 * is func_02041300 with a zero second argument and a zero trailing one.
 * The four `lsls #24 / lsrs #24` pairs are the u8 truncation of each adjusted
 * value, not bitfield extraction: they are equal-amount pairs on values that
 * already left the accessors as bytes, so they only survive because the
 * arithmetic promoted to int in between.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201F7A8.c \
 *       --func func_0201F7A8 --addr 0x0201F7A8 --cc 1.1p1 --thumb
 */
void func_0201F7A8(void *desc, u32 kind)
{
    u8 id;
    u8 a;
    u8 b;
    u8 c;
    u8 d;

    id = func_02045730(desc);
    a = func_02045758(desc);
    b = func_02045760(desc);
    c = func_02045748(desc);
    d = func_02045750(desc);
    func_02041300(id, 0, (u8)(a - 1), (u8)(b - 1), (u8)(c + 2), (u8)(d + 2), 0);
    if (kind == 0) {
        func_020409B4(id);
        return;
    }
    if (kind == 1) {
        func_02041B6C(id);
    }
}





/*
 * bmp_menuwork.c: allocate a menu item list of n cleared 8-byte entries plus
 * a terminator entry { 0xFFFFFFFF, heap } (line 0x29, __FILE__ anchor
 * 0x020A7374 "bmp_menuwork.c").  The previous reading
 * (docs/notes/pkt_0201F81C.c.txt) stored the index into both fields; the
 * loop stores ZERO (the `adds r1, r6, #0` before the loop is the zero
 * rematerialised off the index register and never updated), and with that
 * the index lands in r6 and the frame gets its own `sub sp, #4`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201F81C.c \
 *       --func func_0201F81C --addr 0x0201F81C --thumb
 */
BmpMenuWork *func_0201F81C(u32 n, u32 heap)
{
    BmpMenuWork *p;
    u32 i;

    p = func_02030734((u16)heap, (n + 1) * sizeof(BmpMenuWork), 1, sBmpMenuWorkFile, 0x29);
    if (p != 0) {
        for (i = 0; i < n; i++) {
            p[i].str = 0;
            p[i].param = 0;
        }
        p[i].str = (const void *)0xFFFFFFFF;
        p[i].param = heap;
    }
    return p;
}





/*
 * Destructor pair: run the teardown at 0x0201F8F4, then release the object
 * itself through the allocator's free entry at 0x020307B0.  The pointer has
 * to survive the first call, which is what spends r4 and turns a two-call
 * leaf into a push/pop function.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201F868.c \
 *       --func func_0201F868 --addr 0x0201F868 --cc 1.1p1 --thumb
 */
u32 func_0201F868(void *p)
{
    func_0201F8F4(p);
    return func_020307B0(p);
}





/*
 * Claims a slot through func_0201F8B8 and, if one was free, fills it with the
 * handle func_02045EC0 returns and the caller's tag.  The tag word the
 * claim function writes back is never used here; it lands in the pushed r3
 * home slot at sp+0, which is exactly why the prologue pushes r3 at all.
 * A failed claim is silent.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201F878.c  *       --func func_0201F878 --addr 0x0201F878 --cc 1.1p1 --thumb
 */
void func_0201F878(struct Slot *table, u32 a, u32 b, u32 tag, u32 heap)
{
    struct Slot *slot;
    u32          unused;

    slot = func_0201F8B8(table, &unused);
    if (slot != 0) {
        slot->u.ptr = func_02045EC0((struct MsgBank *)a, b);
        slot->tag = tag;
    }
}


/*
 * Claims a slot through func_0201F8B8 and, if one was free, fills it with the
 * handle func_02045874 returns and the caller's third argument.  Note the
 * argument roles are not the same as in the neighbouring func_0201F878: here
 * the builder takes the caller's *fourth* argument and the slot's tag word
 * comes from the third, the mirror of that function.  The tag word the
 * claim function writes back is never used here; it lands in the pushed r3
 * home slot at sp+0, which is exactly why the prologue pushes r3 at all.
 * A failed claim is silent.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201F898.c  *       --func func_0201F898 --addr 0x0201F898 --cc 1.1p1 --thumb
 */
void func_0201F898(struct Slot *table, u32 a, u32 b, u32 tag)
{
    struct Slot *slot;
    u32          unused;

    slot = func_0201F8B8(table, &unused);
    if (slot != 0) {
        slot->u.ptr = func_02045874((struct U16Vec *)a, tag);
        slot->tag = b;
    }
}



/*
 * Claims a slot in the same eight-byte-stride table func_0201F8F4 walks: it
 * scans for the first empty entry, gives up if the 0xFFFFFFFF terminator
 * arrives first, then runs on to the terminator record and hands its tag word
 * back through the out-parameter.  The empty slot is the return value, null on
 * a full table.
 *
 * Both loops read the word once per iteration and share the load between the
 * zero test and the terminator test, which is why this function needs no
 * union where func_0201F8F4 does: here both tests are u32.  The terminator
 * constant is rematerialised with its own `movs`/`mvns` pair in each of the
 * two blocks that needs it rather than kept live across the first loop; see
 * docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md.
 *
 * It is a leaf, so `push {r3, r4}` / `pop {r3, r4}` + `bx lr` rather than a
 * pop into pc, and disasm.py never labels it.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201F8B8.c \
 *       --func func_0201F8B8 --addr 0x0201F8B8 --cc 1.1p1 --thumb
 */
struct Slot *func_0201F8B8(struct Slot *s, u32 *tag_out)
{
    struct Slot *free_slot;

    while (s->u.raw != 0) {
        if (s->u.raw == 0xFFFFFFFF)
            return 0;
        s++;
    }
    free_slot = s;
    while (s->u.raw != 0xFFFFFFFF)
        s++;
    *tag_out = s->tag;
    return free_slot;
}


/*
 * Releases every live handle in an eight-byte-stride table and blanks its
 * slot.  The table is terminated by 0xFFFFFFFF and the walk also stops at the
 * first null slot.  0xFFFFFFFF is materialised as `movs`/`mvns`, not a pool
 * word.
 *
 * The first word is a union: the terminator test reads it as u32 and the
 * null test reads it as a pointer.  That is what keeps the second `ldr` in
 * the loop body alive, and it is the only spelling that does; with a single
 * u32 member the compiler forwards the guard's load into the body and the
 * function comes out two instructions short whether the loop is written as a
 * `while`, a `for`, or a guard plus `do`/`while`.  The call then has to take
 * the pointer member too, or the null test lands in r1 and the call argument
 * stays the stale guard value.  See
 * docs/idioms/a-sentinel-test-and-a-null-test-on-one-word-are-two-union-members.md.
 *
 * EXACT* is the extent walk running into the unlabelled leaf at 0x0201F91C.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201F8F4.c \
 *       --func func_0201F8F4 --addr 0x0201F8F4 --cc 1.1p1 --thumb
 */
void func_0201F8F4(struct Slot *s)
{
    if (s->u.raw == 0xFFFFFFFF)
        return;
    do {
        if (s->u.ptr == 0)
            return;
        func_02045808(s->u.ptr);
        s->u.raw = 0;
        s++;
    } while (s->u.raw != 0xFFFFFFFF);
}


/*
 * Counts the occupied entries of the same eight-byte-stride table
 * func_0201F8B8 claims from, stopping at the 0xFFFFFFFF terminator.  An empty
 * table returns zero without entering the loop.
 *
 * Two shape facts.  The terminator constant is `subs r1, r3, #1` off the
 * counter while it still holds zero rather than a `movs`/`mvns` pair, and it
 * is rematerialised that way twice, once per block.  And the occupancy test
 * has to read the word as a pointer while the terminator tests read it as
 * u32, or the guard's load is forwarded into the loop body and two
 * instructions disappear; see
 * docs/idioms/a-sentinel-test-and-a-null-test-on-one-word-are-two-union-members.md.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201F91C.c \
 *       --func func_0201F91C --addr 0x0201F91C --cc 1.1p1 --thumb
 */
u32 func_0201F91C(struct Slot *s)
{
    u32 n;

    n = 0;
    if (s->u.raw != 0xFFFFFFFF) {
        do {
            if (s->u.ptr != 0)
                n++;
            s++;
        } while (s->u.raw != 0xFFFFFFFF);
    }
    return n;
}


/*
 * bmp_menu.c constructor (line 0x61, __FILE__ 0x020A7384 "bmp_menu.c"):
 * allocate the 0x38-byte menu, copy the 0x24-byte header in, create the
 * cursor, record cancel mask, start position, widest item (func_0201FC1C),
 * heap id and the pixel origin, then draw (func_0201FC5C) and place the
 * cursor (func_0201FD18).
 *
 * The residue in docs/notes/func_0201F93C.c.txt (the stack-passed u16 heap
 * cached once in a callee-saved register instead of reloaded, 92 bytes out)
 * depended on the conversion at the allocation call: the allocator's heap
 * parameter is `u32`, and the explicit `(u32)(int)heap` keeps that site's
 * signed conversion distinct from the other uses. Without it, the u16 value
 * is zero-extended once and CSE'd into all four uses. With the conversion,
 * the first `ldrh` feeds r0 directly, the header pointer's register is
 * reused for the second load, and the frame shrinks to the original's
 * push {r3-r7,lr} / sub sp,#8.  Found by tools/permuter.py hill (a
 * `(int)heap` cast at that one site), then retained explicitly at the call
 * while preserving the allocator's unsigned-word parameter.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201F93C.c \
 *       --func func_0201F93C --addr 0x0201F93C --thumb
 */
BmpMenu *func_0201F93C(const BmpMenuHeader *hdr, u8 px, u8 py, u8 pos, u16 heap, u32 cancel)
{
    BmpMenu *m = func_02030734((u32)(int)heap, sizeof(BmpMenu), 1, sBmpMenuFile, 0x61);

    m->hdr = *hdr;
    m->cursor = func_02020D18(heap);
    m->cancel = cancel;
    m->pos = pos;
    m->width = func_0201FC1C((struct Obj *)m);
    m->heap = heap;
    m->px = px;
    m->py = py;
    func_02020DC8(m->cursor, (u32)heap);
    m->xmax = m->hdr.unk0c;
    m->ymax = m->hdr.unk0e;
    func_0201FC5C(m);
    func_0201FD18(m);
    return m;
}
