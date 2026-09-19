/*
 * function: func_02074A6C
 * address:  0x02074A6C
 * packet:   pkt_02074A6C
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02074BEC  0x02074BEC  arm
 *
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

typedef unsigned int u32;

extern u32 func_02074BEC(u32 a, u32 b, u32 c, u32 d, u32 e);

u32 func_02074A6C(u32 a, u32 b)
{
    return func_02074BEC(a, 0xff, b, 1, 0) == 0;
}
