/*
 * function: func_021798E4
 * address:  0x021798E4
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Tail call on the word at +0x1124 of the object.
 *
 * symbols:
 *   func_0215C910  0x0215C910  arm
 */

extern void func_0215C910(int v);

void func_021798E4(const char *p)
{
    func_0215C910(*(const int *)(p + 0x1124));
}

