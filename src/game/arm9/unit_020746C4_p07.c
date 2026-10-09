/*
 * file:     unit_020746C4_p07.c
 * unit:     yes
 * function: func_02074A6C, func_02074A98, func_02074AC4, func_02074AE8
 * address:  0x02074A6C
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02074BEC  0x02074BEC  arm
 *   func_02074E10  0x02074E10  arm
 *   func_02074518  0x02074518  arm
 *   func_02074C70  0x02074C70  arm
 *   func_02074CD0  0x02074CD0  arm
 */

typedef unsigned int u32;

extern u32 func_02074BEC(u32 a, u32 b, u32 c, u32 d, u32 *out);

/*
 * One-line wrapper: call the byte-stream reader over a 0xff mask and invert
 * the result.
 *
 * PER-FILE PIN (../2.0/sp2), and the byte evidence for it: this is the
 * "kept constants" tell of docs/FRONTEND-PINS.md, measured on 2026-09-19.
 * The image materialises the fourth and fifth arguments at the call and
 * rebuilds the boolean from immediates:
 *
 *   push {r3, lr} / mov r2, r1 / mov ip, #0 / mov r1, #0xff / mov r3, #1 /
 *   str ip, [sp] / bl ... / cmp r0, #0 / moveq r0, #1 / movne r0, #0
 *
 * `dsi/1.1p1 -O4,p -proc arm946e` instead keeps the same two constants live
 * in callee-saved r4/r5 across the call (push {r3, r4, r5, lr} / mov r5, #1 /
 * mov r4, #0 / ... / movne r5, r4 / mov r0, r5): 48 bytes, 35 differing.
 * `../2.0/sp2 -O4,p -proc arm946e` gives the image's 44 bytes byte for byte,
 * so the bytes themselves name the front end.  The pin needs a row in
 * docs/FRONTEND-PINS.md; that file is outside this lane's write set.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02074A6C.c \
 *       --func func_02074A6C --addr 0x02074A6C --arm --cc ../2.0/sp2
 */
u32 func_02074A6C(u32 a, u32 b)
{
    return func_02074BEC(a, 0xff, b, 1, 0) == 0;
}

extern u32 func_02074E10(u32 a, u32 b, u32 c, u32 d, u32 *out);
u32 func_02074A98(u32 a, u32 b);
u32 func_02074AC4(u32 a, u32 b, u32 c);

/*
 * Sibling of func_02074A6C: the identical wrapper over the other byte-stream
 * reader in the same unit.
 *
 * PER-FILE PIN (../2.0/sp2), same byte evidence and same tell as
 * func_02074A6C (docs/FRONTEND-PINS.md, "kept constants"): the image
 * materialises 0xff / 1 / 0 at the call and the boolean from immediates
 * (44 bytes), `dsi/1.1p1` keeps 1 and 0 live in callee-saved r4/r5 and needs
 * 48 bytes (35 differing), `../2.0/sp2` reproduces the image exactly.
 * Needs a row in docs/FRONTEND-PINS.md; that file is outside this lane's
 * write set.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02074A98.c \
 *       --func func_02074A98 --addr 0x02074A98 --arm --cc ../2.0/sp2
 */
u32 func_02074A98(u32 a, u32 b)
{
    return func_02074E10(a, 0xff, b, 1, 0) == 0;
}

/*
 * Three-argument sibling of src/matched/func_02074A6C.c / func_02074A98.c:
 * forward a, b, c to the byte-stream reader with d=1, out=0, and invert the
 * result.  Same "kept constants" tell and the same ../2.0/sp2 pin as both of
 * those; docs/FRONTEND-PINS.md's closing paragraph names this very address as
 * the unmeasured 36-byte member of the family.  Measured here: the image is
 * `push {r3, lr} / mov ip, #0 / mov r3, #1 / str ip, [sp] / bl ... /
 * cmp r0, #0 / moveq r0, #1 / movne r0, #0`, 36 bytes; 1.1p1 -O4,p keeps the
 * two constants live in callee-saved r4/r5 across the call and emits
 * `push {r3, r4, r5, lr}` for 40 bytes.  Under the pin: 36 bytes, 0 mismatches.
 */
u32 func_02074AC4(u32 a, u32 b, u32 c)
{
    return func_02074BEC(a, b, c, 1, 0) == 0;
}

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

struct Entry { u8 kind; u8 b1; u16 h2; u32 f4; };
struct Table { u32 count; struct Entry entries[1]; };

extern void *func_02074518(int index);
extern u32 func_02074C70(u32 a, u32 b, u32 c, u32 d, u32 *out);
extern u32 func_02074CD0(u32 a, u32 flags, u32 c, u32 d, u32 *out);

/*
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
u32 func_02074AE8(u32 index, u32 arg)
{
    struct Table *t;
    u32 i;
    struct Entry *e;
    u32 r;

    t = func_02074518(index);
    if (t == 0) {
        return 1;
    }
    i = 0;
    if (i < t->count) {
        e = t->entries;
        do {
        switch (e->kind) {
        case 0:
            r = func_02074BEC(e->f4, e->b1, arg, 1, 0);
            if (r != 0) {
                return r;
            }
            break;
        case 3:
            r = func_02074C70(e->f4, e->b1, arg, 1, 0);
            if (r != 0) {
                return r;
            }
            break;
        case 1:
            r = func_02074CD0(e->f4, e->b1, arg, 1, 0);
            if (r != 0) {
                return r;
            }
            break;
        case 2:
            r = func_02074E10(e->f4, e->b1, arg, 1, 0);
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
