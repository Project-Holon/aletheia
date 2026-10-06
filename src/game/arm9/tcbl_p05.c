/*
 * file:     tcbl_p05.c
 * unit:     yes
 * function: func_0203101C, func_020310C4
 * address:  0x0203101C
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
 *   sub_02030734       0x02030734  arm
 *   sub_02030F50       0x02030F50  arm
 *   sub_02030FC8       0x02030FC8  arm
 *   sub_0203101C_File  0x020A7834  data
 *   sub_02030F70  0x02030F70  arm
 *   sub_02030FB4  0x02030FB4  arm
 */
struct TcblNode_020310C4;
struct S02030FB4;
typedef unsigned short u16;

typedef unsigned int   u32;

struct TcblNode_0203101C {
    u32              unk_00;
    struct TcblNode_0203101C *prev;
    struct TcblNode_0203101C *next;
    u32              unk_0c;
    u32              unk_10;
    u32              unk_14;
};

struct Tcbl_0203101C {
    u32              count;
    u32              workSize;
    u16              unk_08;
    u16              pad_0a;
    u32              unk_0c;
    u32              unk_10;
    void            *table;
    struct TcblNode_0203101C  sentinel;
    struct TcblNode_0203101C *cursor;
    struct TcblNode_0203101C *freeHead;
};

typedef void (*TcblFunc)(struct TcblNode_020310C4 *node, void *work);

struct TcblNode_020310C4 {
    u32              unk_00;
    struct TcblNode_020310C4 *prev;
    struct TcblNode_020310C4 *next;
    u32              unk_0c;
    u32              unk_10;
    TcblFunc         func;
};

struct Tcbl_020310C4 {
    u32              count;
    u32              workSize;
    u16              unk_08;
    u16              pad_0a;
    u32              unk_0c;
    u32              destroyed;
    void            *table;
    struct TcblNode_020310C4  sentinel;
    struct TcblNode_020310C4 *cursor;
    struct TcblNode_020310C4 *freeHead;
};

extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void sub_02030F50(struct Tcbl_0203101C *p, struct TcblNode_0203101C *node);
extern void sub_02030FC8(struct Tcbl_0203101C *p);
extern void sub_02030F70(struct TcblNode_020310C4 *node);
extern void *sub_02030FB4(struct S02030FB4 *p);
struct Tcbl_0203101C *sub_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern const char sub_0203101C_File[];


/*
 * Constructor of the task-callback list (tcbl.c).  A 0x38-byte manager is
 * allocated first, then the row table: stride is the work size rounded up
 * to a word plus the 0x18-byte node header, times the row count, which is
 * the same stride sub_02030EF0 recomputes when indexing the table.
 *
 * The rounded stride is derived from the parameter, not re-read from the
 * field just stored at +0x04: the original stores r6 unchanged and then
 * does `add r1, r6, #3 / bic r1, r1, #3` on the same register, with no
 * reload in between.
 *
 * sub_02030FC8 builds the free list out of the table, and sub_02030F50
 * self-links the sentinel node embedded at +0x18, after which +0x30 (the
 * walk cursor) is cleared.
 *
 * 0x020A7834 is the allocation-site pointer this translation unit passes as
 * the allocator's fourth argument, the tcbl.c anchor in
 * layout/file_anchors.txt; the fifth argument is the u16 tag, here 199 and
 * 207.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0203101C.c \
 *       --func sub_0203101C --addr 0x0203101C --cc 1.1p1 --arm
 */
struct Tcbl_0203101C *sub_0203101C(u16 heap, u16 tag, u32 count, u32 workSize)
{
    struct Tcbl_0203101C *p;

    p = sub_02030734(heap, sizeof(struct Tcbl_0203101C), 0, sub_0203101C_File, 199);
    p->count = count;
    p->workSize = workSize;
    p->unk_08 = tag;
    p->unk_0c = 0;
    p->unk_10 = 0;
    p->table = sub_02030734(heap, (((workSize + 3) & ~3) + 0x18) * count, 0,
                            sub_0203101C_File, 207);
    p->freeHead = 0;
    sub_02030FC8(p);
    sub_02030F50(p, &p->sentinel);
    p->cursor = 0;
    return p;
}


/*
 * Run one pass over the task-callback list: for every node still linked to
 * the sentinel at +0x18, clear the manager's "current node was destroyed"
 * flag at +0x10, invoke the node's callback at +0x14 with the node and its
 * work area (sub_02030FB4, the "owned or embedded" accessor), then advance.
 * If the callback set the flag, the node is unlinked and returned to the
 * free list by sub_02030F70, so its successor has to be read out before the
 * call.
 *
 * The walk cursor lives in the manager at +0x30 rather than in a local, so
 * a callback that destroys a *different* node can fix it up; it is cleared
 * on both exits, which is why this is a `while` and not a `do`/`while`: the
 * empty-list arm branches to the same tail.
 *
 * The loop is carried by a local that is refreshed from +0x30 at the bottom
 * of the body, *and* the body re-reads +0x30 into its own local at the top.
 * Written as a bare `while (p->cursor != s)` with `n = p->cursor` inside,
 * the compiler common-subexpressions the two reads and the body top becomes
 * a register copy, four bytes short; see
 * docs/idioms/a-loop-carried-local-beside-a-re-read-field-keeps-both-loads.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020310C4.c \
 *       --func sub_020310C4 --addr 0x020310C4 --cc 1.1p1 --arm
 */
void sub_020310C4(struct Tcbl_020310C4 *p)
{
    struct TcblNode_020310C4 *s = &p->sentinel;
    struct TcblNode_020310C4 *cur;

    cur = s->next;
    p->cursor = cur;
    while (cur != s) {
        struct TcblNode_020310C4 *n = p->cursor;
        p->destroyed = 0;
        n->func(n, sub_02030FB4((struct S02030FB4 *)n));
        if (p->destroyed == 0) {
            p->cursor = p->cursor->next;
        } else {
            struct TcblNode_020310C4 *next = p->cursor->next;
            sub_02030F70(p->cursor);
            p->cursor = next;
        }
        cur = p->cursor;
    }
    p->cursor = 0;
}
