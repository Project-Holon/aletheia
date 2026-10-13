/*
 * function: NNSi_SndArcLoadGroup
 * address:  0x02074AE8
 * packet:   pkt_02074AC4
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   NNS_SndArcGetGroupInfo  0x02074518  arm
 *   NNSi_SndArcLoadSeq  0x02074BEC  arm
 *   NNSi_SndArcLoadSeqArc  0x02074C70  arm
 *   NNSi_SndArcLoadBank  0x02074CD0  arm
 *   NNSi_SndArcLoadWaveArc  0x02074E10  arm
 *
 * Event-list walker: look the list up by index, then run each 8-byte entry
 * {u8 kind; u8 b1; u16; u32 f4} through one of four handlers chosen by a dense
 * 4-way switch, returning the first non-zero handler result.  A null list is 1.
 *
 * Three levers, all measured:
 *  - SOURCE ORDER OF THE ARMS IS 0, 3, 1, 2, read straight off the branch
 *    table at 0x02074B34..0x02074B40 (case 0 -> 0x02074B44, case 1 ->
 *    0x02074B8C, case 2 -> 0x02074BB0, case 3 -> 0x02074B68); the emitted arms
 *    run in source order, so the second body in the file is case 3.  The
 *    handlers are 0 -> BEC, 3 -> C70, 1 -> CD0, 2 -> E10.
 *  - The arms return the HANDLER'S OWN RESULT (`r = f(..); if (r) return r;`),
 *    not a literal 1: the image pops straight out of each arm with no `mov r0`.
 *    Writing `return 1` costs 16 bytes and a shared `mov r0, r4` tail.
 *  - The empty-count exit must share the function's LAST epilogue, so the loop
 *    is `if (i < t->count) { do { .. } while (i < t->count); }` with `i = 0`
 *    assigned FIRST.  A `while` head hoists `add r8, r6, #4` above the compare
 *    (12 bytes out) and `t->count != 0` / `> 0` both fold the guard to `beq`
 *    where the image has `bls` (1 byte out); only the `i < t->count` spelling,
 *    with i provably zero, keeps the unsigned form.
 *  - Declaration order `u32 i;` before `struct Entry *e;` is what puts the
 *    counter in r7 and the cursor in r8; reversed, they swap.
 *
 * PIN ../2.0/sp2, the "kept constants" tell (docs/FRONTEND-PINS.md).  The fifth
 * argument is a literal 0 at all four call sites and the image materialises it
 * FOUR separate times, `mov fp, r7` / `mov sl, r7` / `mov r4, r7` / `mov r5, r7`
 * at 0x02074B2C..0x02074B38 off the counter's own zero, one dedicated register
 * per arm, which is what forces the ten-register `push {r3, r4, r5, r6, r7, r8,
 * sb, sl, fp, lr}` (`f8 4f 2d e9`).  1.1p1 -O4,p CSEs all four into a single
 * `mov r5, #0` and shares the `1` of the fourth argument into r4 as well,
 * dropping sl and fp entirely for an eight-register `push {r3, r4, r5, r6, r7,
 * r8, sb, lr}` and 256 bytes against the original's 260.  Under the pin the
 * same C is 260 bytes, 0 mismatches.
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

struct Entry { u8 kind; u8 b1; u16 h2; u32 f4; };
struct Table { u32 count; struct Entry entries[1]; };

extern void *NNS_SndArcGetGroupInfo(int index);
extern u32 NNSi_SndArcLoadSeq(u32 a, u32 b, u32 c, u32 d, u32 *out);
extern u32 NNSi_SndArcLoadSeqArc(u32 a, u32 b, u32 c, u32 d, u32 *out);
extern u32 NNSi_SndArcLoadBank(u32 a, u32 flags, u32 c, u32 d, u32 *out);
extern u32 NNSi_SndArcLoadWaveArc(u32 a, u32 b, u32 c, u32 d, u32 *out);

u32 NNSi_SndArcLoadGroup(u32 index, u32 arg)
{
    struct Table *t;
    u32 i;
    struct Entry *e;
    u32 r;

    t = NNS_SndArcGetGroupInfo(index);
    if (t == 0) {
        return 1;
    }
    i = 0;
    if (i < t->count) {
        e = t->entries;
        do {
        switch (e->kind) {
        case 0:
            r = NNSi_SndArcLoadSeq(e->f4, e->b1, arg, 1, 0);
            if (r != 0) {
                return r;
            }
            break;
        case 3:
            r = NNSi_SndArcLoadSeqArc(e->f4, e->b1, arg, 1, 0);
            if (r != 0) {
                return r;
            }
            break;
        case 1:
            r = NNSi_SndArcLoadBank(e->f4, e->b1, arg, 1, 0);
            if (r != 0) {
                return r;
            }
            break;
        case 2:
            r = NNSi_SndArcLoadWaveArc(e->f4, e->b1, arg, 1, 0);
            if (r != 0) {
                return r;
            }
            break;
        }
            i++;
            e++;
        } while (i < t->count);
    }
    return 0;
}
