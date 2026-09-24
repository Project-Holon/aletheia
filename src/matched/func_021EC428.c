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
 * Stop the slot, re-key it and restart it.  Two facts pin this one:
 *   the second call's FIRST argument is the first call's RESULT (r0 is
 *   never overwritten), and the result must be a named local -- the
 *   nested spelling moves a and b to r6/r7 (r6=a) instead of the image's
 *   r7=a / r6=b, a 1-byte miss at +0x18.
 */

extern int func_0204B7F0(int);
extern void func_0204AA94(int, int, int, int, int);
extern void func_0204B6F4(int, int, int);
extern int func_0204B7F0(int);
extern void func_0204AA94(int, int, int, int, int);
extern void func_0204B6F4(int, int, int);
void func_021EC428(char *p, int a, int i, int b)
{
    int v = func_0204B7F0(*(int *)(p + 0x9E74 + i * 4));
    func_0204AA94(v, a, 0x200, 0, 0);
    func_0204B6F4(*(int *)(p + 0x9E74 + i * 4), (unsigned char)b, 1);
}

