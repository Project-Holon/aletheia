/*
 * function: func_021B6984
 * address:  0x021B6984
 * packet:   pkt_021B6984
 * region:   ov180
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * BLOCKER: 2 bytes, r1 vs r0.  The original ldr/compares p[0x1c] in r1 and
 * then loads p[0x18] in r0; compiled lands both in r0.  Re-verified 2026-09-27:
 * inline, `int v` local, `unsigned`, `volatile`, pointer local and
 * `if (*(int*)(p+0x1c))` all give r0.  The tell is type coercion, not an
 * allocator quirk: declare the field with the width/signedness the image's
 * load uses and mwcc stops converting the loaded value into a fresh register
 * (see docs/idioms/argument-register-match-names-a-coerced-extern.md).
 * The rest is byte-correct.
 *
 * symbols:
 *   func_02015BA4  0x02015BA4  thumb
 */

extern void func_02015BA4(int);

void func_021B6984(char *p)
{
    int v = *(int *)(p + 0x1c);

    if (v != 0) {
        func_02015BA4(*(int *)(p + 0x18));
        *(int *)(p + 0x1c) = 0;
    }
}
