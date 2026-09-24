/*
 * function: func_021D8E24
 * address:  0x021D8E24
 * packet:   pkt_021D8980
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF (parked)
 *
 * DIFF: block order. The image falls through into the grid path p + 0x11fc + (b + a*0x1e + 6)*4 and branches out to the six-entry table path; any if/else we write produces the two tails in the other order. Blocking site: block order of the two returns, see OV-BRIEF rule 6.
 *
 * Sub-object pointer for a slot index, or 0 when out of range.
 *
 * symbols:
 *   (none)
 */

char *func_021D8E24(int a, int b, char *p)
{
    int n;

    if (a == -1)
        return 0;
    n = *(int *)(p + 0x630);
    if (n < a)
        return 0;
    if (n != a && b != -1)
        return p + 0x11fc + (b + a * 0x1e + 6) * 4;
    if (b < 0 || b >= 6)
        return 0;
    return p + 0x11fc + b * 4;
}

