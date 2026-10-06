/*
 * function: sub_02035C60
 * address:  0x02035C60
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
 *   func_02035C48  0x02035C48  arm
 *
 * Forward to func_02035C48 with the context func_02035224 supplies, same
 * "no context argument" shape as the block in unit_02035C70.c.
 *
 * func_02035C48's only call site anywhere in the image is the one right
 * here, inside this 16-byte function, so the `label` class has no witness
 * outside the range under test and --suggest-split cannot help (the
 * function is atomic; there is nothing to cut).  The site resolves on
 * class `matched` against src/matched/func_02035C48.c, decompiled for
 * exactly this purpose.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02035C60.c \
 *       --func sub_02035C60 --addr 0x02035C60 --cc 1.1p1 --arm
 */

typedef unsigned short u16;

struct Ctx;

struct Ctx02035C48;
struct UiCtx;
extern struct UiCtx *func_02035224(void);
extern u16 func_02035C48(struct Ctx02035C48 *ctx);

int sub_02035C60(void)
{
    return func_02035C48((struct Ctx02035C48 *)func_02035224());
}
