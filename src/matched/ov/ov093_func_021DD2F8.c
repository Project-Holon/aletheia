/*
 * function: func_021DD2F8
 * address: 0x021DD2F8
 * packet: pkt_ov093_021DD2F8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte alignment padding.
 * prototype: third DD39C input widened to full register width; no truncation at call.
 * symbols:
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021DD39C 0x021DD39C thumb ov093
 */
extern int func_021D775C(int);
extern int func_021DD39C(int, void *, int, int, int);
void func_021DD2F8(int a, void *b, int c, int *d)
{
    if (c == func_021D775C(2)) func_021DD39C(a, b, c, (int)d, 0);
}
