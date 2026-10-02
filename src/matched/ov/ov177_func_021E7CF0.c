/*
 * function: func_021E7CF0
 * address: 0x021E7CF0
 * packet: pkt_ov177_021E7CF0
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
unsigned func_021E7CF0(void *p, unsigned short v, unsigned short w)
{
    if (v >= 1000) {
        return 5;
    }
    if (v >= 500) {
        return 4;
    }
    if (v >= 200) {
        return 3;
    }
    if (v >= 100) {
        return 2;
    }
    if (v >= 50) {
        return 1;
    }
    return 0;
}
