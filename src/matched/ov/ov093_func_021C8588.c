/*
 * function: func_021C8588
 * address: 0x021C8588
 * packet: pkt_ov093_021C8588
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C85D4 0x021C85D4 thumb ov093
 */
extern void func_021C85D4(unsigned char *, int, int);
void func_021C8588(unsigned char *p)
{
    *(int *)(p + 0x1a64) = 0;
    func_021C85D4(p, 0, 1);
}
