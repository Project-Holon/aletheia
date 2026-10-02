/*
 * function: func_021F3FD8
 * address: 0x021F3FD8
 * packet: pkt_ov041_021F3FD8
 * region: ov041
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F3FEC 0x021F3FEC thumb ov041
 */

extern void func_021F3FEC(unsigned char *);
void func_021F3FD8(unsigned char *p)
{
    func_021F3FEC(p + 0x720);
    *(int *)(p + 0x720) = 1;
}
