/*
 * PARKED AT MATCH.  Every concrete byte is right.
 *
 * function: sub_02035C60
 * address:  0x02035C60
 * packet:   pkt_02035C60
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * symbols:
 *   func_02035224  0x02035224  arm
 *   func_02035C48  0x02035C48  arm
 *
 * The no-context spelling of func_02035C48: fetch the singleton with
 * func_02035224() and hand it over.  Same two-call shape as
 * src/pending/sub_02035C38.c and src/matched/unit_020362BC.c.
 *
 * Blocked on evidence class `label`: 0x02035C48 is reached by exactly one
 * branch in the whole image, the `bl` at 0x02035C68 inside this function, so
 * it has no witness outside the compared range and no split can create one.
 * It was cut out of src/matched/unit_02035C60.c on --suggest-split's advice
 * for exactly that reason; the rest of that range is EXACT.  It unsticks as
 * soon as 0x02035C48 is itself decompiled to EXACT (class `matched`).
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_02035C60.c \
 *       --func sub_02035C60 --addr 0x02035C60 --cc 1.1p1 --arm
 */

struct Ctx;

extern struct Ctx *func_02035224(void);
extern void func_02035C48(struct Ctx *ctx);

void sub_02035C60(void)
{
    func_02035C48(func_02035224());
}
