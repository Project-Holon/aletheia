/*
 * function: ZUKAN_DETAIL_COMMON_ApplyBrightness
 * address:  0x021BC520
 * packet:   pkt_ov208_021BC520
 * region:   ov208
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0207D67C  0x0207D67C  arm
 */

extern void func_0207D67C(unsigned int, int, int, int, int, int);

void ZUKAN_DETAIL_COMMON_ApplyBrightness(int flag, int *p)
{
    if (flag == 0) {
        func_0207D67C(0x04000050, p[0], p[1], p[2], 0, p[2] - 0x10);
    } else {
        func_0207D67C(0x04001050, p[0], p[1], p[2], 0, p[2] - 0x10);
    }
}