/*
 * unit: yes
 * function: func_021DD658, func_021DD670
 * address: 0x021DD658
 * packet: pkt_ov093_021DD658
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DD7B8 0x021DD7B8 thumb ov093
 *   d_021F1C54 0x021F1C54 data a4
 */
typedef unsigned char u8;
extern void func_021DD7B8(int, u8 *, int, int *, int);
void func_021DD658(int a, u8 *b, int c, int *d)
{
    if (d[6] != 0) func_021DD7B8(a, b, c, d, 1);
}
extern u8 d_021F1C54[];
void *func_021DD670(int *p) { *p = 5; return d_021F1C54; }
