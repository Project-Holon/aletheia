/*
 * function: func_021E3700
 * address:  0x021E3700
 * packet:   pkt_ov119_021E3700
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * 2026-10-02 (wB2 lane08): DIFF. Original keeps n*3 in r4 (push {r3,r4}) with the table base in r3 and loads t[i+2] before the first store; all tried forms (expression, a/b/c locals, volatile pointer local, [n][3] array) pick r0/r1 bases. d_021E8190 also has no witness outside this function (cap MATCH).
 *
 * symbols:
 *   d_021E8190 0x021E8190 data a2
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern u16 d_021E8190[];

void func_021E3700(int n)
{
    int i;

    i = n * 3;
    *(volatile u32 *)0x0400048C = d_021E8190[i] | (d_021E8190[i + 1] << 16);
    *(volatile u32 *)0x0400048C = d_021E8190[i + 2];
}
