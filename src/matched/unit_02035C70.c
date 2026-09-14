/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * function: sub_02035C70, sub_02035CB8, sub_02035CD8, sub_02035D20,
 *           sub_02035D40
 * address:  0x02035C70
 * packet:   pkt_02035C60
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02035224  0x02035224  arm
 *   func_02035750  0x02035750  arm
 *   func_02035760  0x02035760  arm
 *   func_02035780  0x02035780  arm
 *   func_020357A0  0x020357A0  arm
 *   func_020357C0  0x020357C0  arm
 *   func_02035ADC  0x02035ADC  arm
 *
 * The singleton-facing half of the 0x02035000 block: every entry point here
 * is the "no context argument" spelling of a worker that lives a little
 * earlier in the file, with func_02035224() supplying the context.
 *
 * sub_02035C70 and sub_02035CD8 are the two two-output readers; they differ
 * only in which predicate gates them (0x020357A0 versus 0x020357C0).  Each
 * is called from exactly one place, its own wrapper in this same file, so
 * the two pairs have to live in one unit for those sites to close as
 * `local` (same shape as src/matched/unit_020362BC.c).
 *
 * sub_02035D40 has no label of its own in the listing: it is an unlabelled
 * follower of sub_02035D20 (its prologue saves nothing).  It is the u16
 * narrowing shim in front of func_02035ADC, and it is the pool-word-and-bx
 * tail call idiom, one section per function.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02035C70.c \
 *       --addr 0x02035C70 --arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct Ctx;

extern struct Ctx *func_02035224(void);
extern void func_02035750(struct Ctx *ctx);
extern u32 func_02035760(struct Ctx *ctx);
extern u32 func_02035780(struct Ctx *ctx);
extern u32 func_020357A0(struct Ctx *ctx);
extern u32 func_020357C0(struct Ctx *ctx);
extern u32 func_02035ADC(struct Ctx *ctx, u16 a, u16 b);

u32 sub_02035C70(struct Ctx *ctx, u32 *outA, u32 *outB);
u32 sub_02035CD8(struct Ctx *ctx, u32 *outA, u32 *outB);

u32 sub_02035C70(struct Ctx *ctx, u32 *outA, u32 *outB)
{
    func_02035750(ctx);
    if (func_020357A0(ctx) == 0) {
        return 0;
    }
    *outA = func_02035760(ctx);
    *outB = func_02035780(ctx);
    return 1;
}

u32 sub_02035CB8(u32 *outA, u32 *outB)
{
    return sub_02035C70(func_02035224(), outA, outB);
}

u32 sub_02035CD8(struct Ctx *ctx, u32 *outA, u32 *outB)
{
    func_02035750(ctx);
    if (func_020357C0(ctx) == 0) {
        return 0;
    }
    *outA = func_02035760(ctx);
    *outB = func_02035780(ctx);
    return 1;
}

u32 sub_02035D20(u32 *outA, u32 *outB)
{
    return sub_02035CD8(func_02035224(), outA, outB);
}

u32 sub_02035D40(struct Ctx *ctx, u32 a, u32 b)
{
    return func_02035ADC(ctx, a, b);
}
