/*
 * function: func_021F9154
 * address:  0x021F9154
 * packet:   pkt_ov094_021F9154
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Signed step from a to b in units of c (default 0x1000), at least one unit.
 *
 * symbols:
 *   func_0207C768 0x0207C768 arm
 */
extern int func_0207C768(int, int);

void func_021F9154(int a, int b, int *out, int c)
{
    *out = 0;
    if (b - a == 0)
        return;
    if (c == 0)
        c = 0x1000;
    *out = func_0207C768(b - a, c);
    if (*out == 0) {
        if (b > a)
            *out = 1;
        else
            *out = -1;
    }
}
