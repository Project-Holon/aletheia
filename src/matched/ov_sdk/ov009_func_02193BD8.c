/*
 * function: func_02193BD8
 * address:  0x02193BD8
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Stores a word at +4 of the state object and returns the address of the next.
 *
 * symbols:
 *   g_021ADFD0  0x021ADFD0  data
 *   g_021ADFD4  0x021ADFD4  data
 */

extern char g_021ADFD0[];
extern char g_021ADFD4[];

char *func_02193BD8(int v)
{
    *(int *)(g_021ADFD0 + 4) = v;

    return g_021ADFD4;
}

