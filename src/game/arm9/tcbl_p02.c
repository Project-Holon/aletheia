/*
 * file:     tcbl_p02.c
 * unit:     yes
 * function: func_02030C44, func_02030C68
 * address:  0x02030C44
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
 */
struct Ctx;
struct Frame02030C68;
typedef unsigned int u32;

struct Node {
    struct Ctx  *owner;   /* +0x00 */
    struct Node *prev;    /* +0x04 */
    struct Node *next;    /* +0x08 */
    u32          key;     /* +0x0c */
    void        *arg;     /* +0x10 */
    void       (*fn)(struct Node *, void *); /* +0x14 */
    u32          fired;   /* +0x18 */
};

struct Ctx {
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

struct Ctx02030C68 {
    u32 unk00;
    u32 depth;
    u8  buf[0x1c];
    struct Frame02030C68 **stack;
};

struct Frame02030C68 {
    struct Ctx02030C68 *ctx;
    u8 *cur;
    u8 *end;
    u32 unk0C;
    u32 unk10;
    u32 unk14;
};



/*
 * Allocate a timer node.  Free nodes live in a stack of pointers at
 * c->freeList with c->top the live index: this function hands back the entry
 * at the top and steps up, and 0x02030C68 (src/matched/unit_02030C68.c) steps
 * back down and stores the node there.  It calls nothing, so the unit holds
 * no relocations at all and needs no outside evidence; that is what unblocks
 * src/matched/unit_02030DA8.c, whose only unresolved site was the call to
 * 0x02030C44.
 *
 * 0x02030C68 used to be written out again at the bottom of this file, from
 * when it was still an unlabelled follower and this unit's inferred extent
 * ran to 0x02030CB0.  It is seeded in layout/function_starts.txt now and
 * src/matched/unit_02030C68.c is the manifest entry for it, so the extent
 * here stops at 0x02030C68 and the second body was redundant: two files laid
 * out the same 72 bytes and only one of them could own the address
 * (docs/idioms/a-unit-attests-only-its-own-start-address.md).
 *
 * In 0x02030C44 the popped entry is bound to a local before c->top is stepped:
 * that is the `movne r0, r2` at the end, four bytes that disappear if the
 * subscript is returned directly.  `cmp r3, r1` puts the live top on the
 * left, so the guard is written with c->top first
 * (docs/idioms/cmp-operand-order-names-the-temporary.md).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02030C44.c \
 *       --addr 0x02030C44 --cc 1.1p1 --arm
 */
struct Node *sub_02030C44(struct Ctx *c)
{
    struct Node *n;
    u32 top;

    top = c->top;
    if (top == c->capacity) {
        return 0;
    }
    n = c->freeList[top];
    c->top = top + 1;
    return n;
}


/*
 * Push one frame onto the context's stack: fail if the stack is full,
 * otherwise point the frame at the context and at its inline buffer, clear
 * the three counters, and store the frame in the slot the decremented
 * depth names.
 *
 * Filed as a unit, not a single function, because 0x02030C68 saves nothing
 * on entry: disasm.py only auto-labels a prologue that pushes lr, so it
 * put a label on the `mov r0, #1` tail at 0x02030CA8 and the inferred
 * extent stops eight bytes early.  `tu` compares the compiled layout
 * instead and covers 0x02030C68..0x02030CB0.  0x02030CA8 is not a function
 * start and wants removing from layout/function_starts.txt; that file is
 * the integrator's, so this note is the report.
 *
 * The +8 store lands before the pair at +0 and +4 because that is the
 * source order: written ctx, cur, end the compiler emits the `stm` first
 * and the lone `str` last, six bytes apart.
 *
 * Decompiled to unstick src/pending/sub_02030EAC.c (fan-in 196), which is
 * this function's only caller image-wide and so had no `label` witness.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02030C68.c \
 *       --addr 0x02030C68 --cc 1.1p1 --arm
 */
u32 func_02030C68(struct Ctx02030C68 *ctx, struct Frame02030C68 *frame)
{
    if (ctx->depth == 0) {
        return 0;
    }

    frame->end = ctx->buf;
    frame->ctx = ctx;
    frame->cur = ctx->buf;
    frame->unk0C = 0;
    frame->unk10 = 0;
    frame->unk14 = 0;

    ctx->depth--;
    ctx->stack[ctx->depth] = frame;
    return 1;
}
