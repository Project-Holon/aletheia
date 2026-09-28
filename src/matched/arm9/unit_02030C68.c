/*
 * unit:     yes
 * function: func_02030C68
 * address:  0x02030C68
 * packet:   pkt_02030BD4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
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

typedef unsigned char u8;
typedef unsigned int  u32;

struct Frame02030C68;

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
