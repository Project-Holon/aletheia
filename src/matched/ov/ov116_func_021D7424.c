/*
 * function: func_021D7424
 * address: 0x021D7424
 * packet: pkt_ov116_021D7424
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021D8580 0x021D8580 data a4
 */

typedef struct { void (*f[3])(int **, int); } Tbl;
extern const Tbl d_021D8580;
void func_021D7424(int **p, int x)
{
    Tbl t = d_021D8580;
    t.f[**p](p, x);
}
