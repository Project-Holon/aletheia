/*
 * unit: yes
 * function: func_021DD68C, func_021DD6A4
 * address: 0x021DD68C
 * packet: pkt_ov093_021DD68C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DD7B8 0x021DD7B8 thumb ov093
 *   d_021F1C7C 0x021F1C7C data a4
 */
typedef unsigned char u8;
extern void func_021DD7B8(int, u8 *, int, int *, int);
void func_021DD68C(int a, u8 *b, int c, int *d)
{
    if (d[6] != 0) func_021DD7B8(a, b, c, d, 2);
}
extern u8 d_021F1C7C[];
void *func_021DD6A4(int *p) { *p = 5; return d_021F1C7C; }
