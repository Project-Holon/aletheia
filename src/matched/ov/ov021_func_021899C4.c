/*
 * function: func_021899C4
 * address:  0x021899C4
 * packet:   pkt_ov021_021899C4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0207DD24  0x0207DD24  arm
 *   func_021CF520  0x021CF520  thumb  ov021
 */

typedef unsigned short u16;
void func_0207DD24(u16 rgb, int alpha, int depth, int polygonID, int fog);
void func_021CF520(int h);

void func_021899C4(unsigned char *p)
{
    func_0207DD24(0x4210, 0x1F, 0x7FFF, 0, 0);
    func_021CF520(*(int *)(p + 0x13C));
}
