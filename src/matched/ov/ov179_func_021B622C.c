/*
 * function: func_021B622C
 * address:  0x021B622C
 * packet:   pkt_ov179_021B622C
 * region:   ov179
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021B68E4  0x021B68E4  data  a4
 */

extern int d_021B68E4[];

void func_021B622C(char *p, int unused)
{
    unsigned short idx = *(unsigned short *)(*(void **)p);
    int v = d_021B68E4[idx];

    *(int *)(p + 0x6018) = v;
    *(int *)(p + 0x601c) = v;
}
