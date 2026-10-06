/*
 * function: func_021DFA6C
 * address:  0x021DFA6C
 * packet:   pkt_021DFA6C
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * note:     the listing extent (60 B) covers the two untraced ARM accessors
 *           that follow this 44-byte body; every compiled byte matches.
 *
 * symbols:
 *   (none)
 *
 * Null-checked release: no object reports 2, an object with no +0x50 listener
 * reports 3, otherwise the listener path runs and the call reports 0.
 */

typedef unsigned int u32;

extern void func_021E0764(void *p);

int func_021DFA6C(int *p)
{
    if (p == 0)
        return 2;
    if (p[0x14] == 0)
        return 3;
    func_021E0764(p);
    return 0;
}
