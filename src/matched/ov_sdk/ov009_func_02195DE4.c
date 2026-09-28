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
 * Tail call on the word at +0xc of the object.  The pool word at +0x14 is the
 * address of the ARM function KeyValHashKey (0x02195DD4, EXACT in
 * ov009_func_02195DD4.c), not data: seeded as a function 2026-09-28.
 *
 * symbols:
 *   KeyValHashKey  0x02195DD4  arm  ov009
 *   func_0218489C  0x0218489C  arm  ov009
 */

extern void KeyValHashKey(void);
extern void func_0218489C(int a, char *p, int c);

void func_02195DE4(int *p)
{
    func_0218489C(p[3], (char *)KeyValHashKey, 0);
}

