/*
 * function: sub_020360A8
 * address:  0x020360A8
 * packet:   pkt_02035E84
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * note:     re-verified 2026-09-20: MATCH; see verify output
 *
 * symbols:
 *   func_02035224  0x02035224  arm
 *   func_02035F38  0x02035F38  arm
 *
 * The no-context spelling of func_02035F38: fetch the singleton with
 * func_02035224 and hand it over.  Sixteen bytes, no register setup between
 * the two calls, so the argument count is not visible from the code; the
 * one-argument reading is the one the rest of this file's wrappers take
 * (compare src/matched/unit_020362BC.c).
 *
 * PARKED AT MATCH.  Every concrete byte is right.  func_02035224 resolves on
 * `label`; func_02035F38 does not, because the `bl` at 0x020360B0 inside this
 * function is its only reference anywhere in the image.
 *
 * Identical situation to src/pending/sub_02035A60.c: a tu over
 * 0x02035F38..0x020360B8 would make the site `local`, and 0x02035F38 is 360
 * bytes, left for whoever takes pkt_02035E84.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_020360A8.c \
 *       --func sub_020360A8 --addr 0x020360A8 --cc 1.1p1 --arm
 */

struct Ctx;

extern struct Ctx *func_02035224(void);
extern void func_02035F38(struct Ctx *ctx);

void sub_020360A8(void)
{
    func_02035F38(func_02035224());
}
