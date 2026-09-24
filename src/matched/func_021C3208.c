/*
 * function: func_021C3208
 * address:  0x021C3208
 * packet:   pkt_021C3208
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)

 * Writes 3 to +0x60 when the word there, less one, is 0 or 1.
 */


typedef struct {
    char pad[0x60];
    unsigned int state;
} S;

void func_021C3208(int unused, S *p)
{
    unsigned int v = p->state;

    v -= 1;
    if (v <= 1)
        p->state = 3;
}

