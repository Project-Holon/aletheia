/*
 * function: func_02189998
 * address:  0x02189998
 * packet:   pkt_ov021_02189998
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0207DD24  0x0207DD24  arm
 *   func_021C1AEC  0x021C1AEC  thumb  ov021
 *   func_021C1C4C  0x021C1C4C  thumb  ov021
 */

typedef unsigned short u16;
void func_0207DD24(u16 rgb, int alpha, int depth, int polygonID, int fog);
void func_021C1AEC(void);
void func_021C1C4C(int h);

void func_02189998(unsigned char *p)
{
    func_0207DD24(0, 0, 0x7FFF, 0, 0);
    func_021C1AEC();
    func_021C1C4C(*(int *)(p + 0x124));
}
