/*
 * function: func_021BD880
 * address:  0x021BD880
 * packet:   pkt_021BD880
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Re-verified 2026-09-27 (DIFF fixer lane): the +8 store in the image is a
 * full word, `str r1,[r4,#8]`, not `strh`: the zero-extended u16 is written
 * through an int lvalue.  With `*(int *)(p + 8) = h;` the whole function
 * reproduces, including `ldrh r1,[r4,#0x28]; ldr r0,[r4]; str r1,[r4,#8]`.
 * EXACT*: the inferred extent runs 2 bytes past `pop` (an unlabelled
 * follower/alignment word), never a byte difference.
 *
 * symbols:
 *   (none)
 */


extern void func_0204B878(int, unsigned short);
extern void func_020061E4(int);

void func_021BD880(char *p)
{
    unsigned short h = *(unsigned short *)(p + 0x28);
    int v = *(int *)p;

    *(int *)(p + 8) = h;
    func_0204B878(v, h);
    if (*(int *)(p + 0x30) != 0)
        func_020061E4(*(int *)(p + 0x30));
}
