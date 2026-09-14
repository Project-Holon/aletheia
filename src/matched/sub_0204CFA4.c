/*
 * unit:     no
 * function: sub_0204CFA4
 * address:  0x0204CFA4
 * packet:   pkt_0204CA74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The seven-argument initialiser for the 0x20-byte request record: four
 * arguments arrive in registers, three more off the caller's stack, and the
 * last three words of the record are cleared.
 *
 * The four-register push is not about callee-saved state, it is the cost of
 * having three stack arguments to stage; [sp, #0x10] is the first of them,
 * sixteen bytes past the pushed frame.  `stmib r0, {r3, r5}` is the
 * compiler folding the +4 and +8 stores once both values happen to sit in
 * ascending registers, not a struct copy
 * (docs/idioms/aggregate-assignment-is-ldm-stm.md describes the other case).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204CFA4.c \
 *       --func sub_0204CFA4 --addr 0x0204CFA4 --cc 1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct Req {
    u16 unk_00;
    u16 unk_02;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1c;
};

void sub_0204CFA4(struct Req *r, u16 a, u16 b, u32 c, u32 d, u32 e, u32 f)
{
    r->unk_00 = a;
    r->unk_02 = b;
    r->unk_04 = c;
    r->unk_08 = d;
    r->unk_0c = e;
    r->unk_10 = f;
    r->unk_14 = 0;
    r->unk_18 = 0;
    r->unk_1c = 0;
}
