/*
 * function: func_02074AC4
 * address:  0x02074AC4
 * packet:   pkt_02074AC4
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   func_02074BEC  0x02074BEC  arm
 *
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

typedef unsigned int u32;

extern u32 func_02074BEC(u32 a, u32 b, u32 c, u32 d, u32 *out);

u32 func_02074AC4(u32 a, u32 b, u32 c)
{
    return func_02074BEC(a, b, c, 1, 0) == 0;
}
