/*
 * function: func_021EC428
 * address:  0x021EC428
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *
 * Three calls on one 0x9E74 table entry; the second takes the first's result.
 *   CLOSES the "constant-vs-index base" residue for this function by taking
 *   the opposite grouping to func_021EBF74: with the CONSTANT first
 *   (`p + 0x9E74 + i * 4`) mwccarm forms base = p+0x9E74 in one register and
 *   the scaled index in another, which is what the image has here
 *   (`adds r5,r0,r1 / ldr r0,[r5,r4]`); the index-first spelling used before
 *   folded the pool word into the offset register instead.
 *   Also: the second call's FIRST argument is the first call's RETURN value
 *   (r0 is never re-set between the two `blx`), not the second formal.
 */

extern int func_0204B7F0(int);
extern void func_0204AA94(int, int, int, int, int);
extern void func_0204B6F4(int, int, int);
void func_021EC428(char *p, int a, int i, int b)
{
    func_0204AA94(func_0204B7F0(*(int *)(p + 0x9E74 + i * 4)), a, 0x200, 0, 0);
    func_0204B6F4(*(int *)(p + 0x9E74 + i * 4), (unsigned char)b, 1);
}
