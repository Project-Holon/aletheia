/*
 * function: func_021DAB24
 * address: 0x021DAB24
 * packet: pkt_ov093_021DAB24
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte alignment padding.
 * symbols:
 *   func_021DA8A8 0x021DA8A8 thumb ov093
 *   func_021DA96C 0x021DA96C thumb ov093
 */
extern int func_021DA8A8(int, int, int);
extern void func_021DA96C(void *, int, unsigned int, int);

void func_021DAB24(int a, void *b, int c)
{
    if (func_021DA8A8((int)b, c, 0xc))
        func_021DA96C(b, c, 5, 1);
}
