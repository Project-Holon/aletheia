/*
 * unit:     no
 * function: sub_0204D134
 * address:  0x0204D134
 * packet:   pkt_0204CA74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Classify a request into the small index the sibling sub_0204D0C4 uses to
 * pick a handler out of its table: 1 if the pointer at +0x1c is set, else 2
 * if the one at +0x14 is, else 0.  A leaf with no prologue at all, so
 * disasm.py never labelled it.
 *
 * The first arm gets its own `bxne lr` while the last two share one exit as
 * a `movne`/`moveq` pair: that is what an early `return` followed by a
 * two-way tail looks like once the compiler has run out of conditional
 * slots to fold the first test into
 * (docs/idioms/initialise-the-result-before-the-input-or-every-arm-duplicates-the-return.md
 * read in reverse, the result here is not initialised first).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204D134.c \
 *       --func sub_0204D134 --addr 0x0204D134 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef signed int    s32;

struct Req {
    u8    pad_00[0x14];
    void *unk_14;
    u8    pad_18[4];
    void *unk_1c;
};

s32 sub_0204D134(const struct Req *r)
{
    if (r->unk_1c != 0) {
        return 1;
    }
    if (r->unk_14 != 0) {
        return 2;
    }
    return 0;
}
