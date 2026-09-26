/*
 * function: func_021D53DC
 * address:  0x021D53DC
 * packet:   pkt_021D53DC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * symbols:
 *   func_021D53DC   0x021D53DC  thumb ov093
 *
 * BLOCKER: codegen.  The image is a fully unrolled 60-byte clamp of the first
 * seven signed bytes (floor 6), with the element index carried in a register
 * (`movs r1,#0; ldrsb r2,[r0,r1]; ...; movs r2,#4; ldrsb r2,[r0,r2]`), which
 * is the shape mwcc emits for a constant-trip loop it has unrolled.  At -O4,p
 * the same loop written plainly stays a 20-byte rolled loop (`movs r3,#0;
 * ldrsb r2,[r0,r3]; ... adds r3,#1; cmp r3,#7; blt`), and seven explicit
 * `if (p[i] < 6) p[i] = 6;` statements compile to the 84-byte immediate-offset
 * unroll (`ldrsb r2,[r0,#i]`), not the image's register index.  Neither shape
 * reproduces the original's register-indexed unroll.  This target cannot be
 * matched; the pending ov093 caller func_021D5EFC therefore stays MATCH.
 */

void func_021D53DC(signed char *p)
{
    int i;
    for (i = 0; i < 7; i++) {
        if (p[i] < 6)
            p[i] = 6;
    }
}
