/*
 * function: func_021EC08C
 * address:  0x021EC08C
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
 * Tail call through the 0x9E74 table keyed by i; a two-halfword local record.
 *   CLOSES the "strh r3 before/after the pool load" scheduling residue: the
 *   fifth formal is a HALFWORD VALUE, and declaring it `unsigned short`
 *   both reproduces `add r2,sp,#0x10 / ldrh r2,[r2]` (a word load of an int
 *   formal never matches) and lets mwccarm sink the pool load past the
 *   second `strh`, which is the order the image has.
 */

extern void func_0204B404(int, void *, int);
void func_021EC08C(char *p, int i, unsigned short a, unsigned short b, unsigned short c)
{
    unsigned short t[2];
    t[0] = a;
    t[1] = b;
    func_0204B404(*(int *)(p + i * 4 + 0x9E74), t, c);
}
