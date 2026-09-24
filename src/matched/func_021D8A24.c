/*
 * function: func_021D8A24
 * address:  0x021D8A24
 * packet:   pkt_021D8980
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * True when the object has a session and its state index is in range.
 *
 * symbols:
 *   (none)
 */

extern int func_0203CD98(int a);

int func_021D8A24(void *p)
{
    int v;

    if (*(int *)((char *)p + 8) == 0)
        return 0;
    v = *(int *)((char *)p + 0x118c);
    if (v >= 4)
        return 0;
    return func_0203CD98(v) != 0;
}

