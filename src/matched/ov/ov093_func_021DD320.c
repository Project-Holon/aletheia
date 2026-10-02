/*
 * function: func_021DD320
 * address: 0x021DD320
 * packet: pkt_ov093_021DD320
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte alignment padding.
 * symbols:
 *   func_021DD39C 0x021DD39C thumb ov093
 */
typedef unsigned char u8;
extern int func_021DD39C(int, void *, u8, int, int);
void func_021DD320(int a, void *b, u8 c, int *d)
{
    if (d[6] != 0) func_021DD39C(a, b, c, (int)d, 1);
}
