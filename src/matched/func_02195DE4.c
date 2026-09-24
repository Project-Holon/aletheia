/*
 * function: func_02195DE4
 * address:  0x02195DE4
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Tail call on the word at +0xc of the object.
 *
 * symbols:
 *   g_02195DD4  0x02195DD4  data
 *   func_0218489C  0x0218489C  arm  ov009
 */

extern char g_02195DD4[];
extern void func_0218489C(int a, char *p, int c);

void func_02195DE4(int *p)
{
    func_0218489C(p[3], g_02195DD4, 0);
}

