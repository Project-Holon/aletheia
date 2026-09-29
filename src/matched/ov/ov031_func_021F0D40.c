/*
 * function: func_021F0D40
 * address:  0x021F0D40
 * packet:   pkt_ov031_021F0D40
 * region:   ov031
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (no lr push) sitting in a word run; filed as a blocker of
 * func_021F0C60 and func_021F0CEC.
 *
 * symbols:
 *   func_021F0D40  0x021F0D40  thumb
 */

typedef struct {
    char pad[0x43C];
    int a;
} B;

int func_021F0D40(B *p)
{
    int v = p->a;

    if (v >= 0x1E)
        v = 0x1D;
    v -= 2;
    if (v < 0)
        v = 0;
    return v;
}
