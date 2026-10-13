/*
 * function: scThink
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
 *   sciWsThink  0x021E0764  arm
 *   (none)
 *
 * Null-checked release: no object reports 2, an object with no +0x50 listener
 * reports 3, otherwise the listener path runs and the call reports 0.
 */

typedef unsigned int u32;

extern void sciWsThink(void *p);

int scThink(int *p)
{
    if (p == 0)
        return 2;
    if (p[0x14] == 0)
        return 3;
    sciWsThink(p);
    return 0;
}
