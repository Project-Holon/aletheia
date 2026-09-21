/*
 * function: func_0209128C
 * address:  0x0209128C
 * packet:   pkt_02091284
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * note:     status corrected 2026-09-21 from EXACT to DIFF by re-verification (1 concrete bytes out)
 *
 * symbols:
 *   addr_02153B88  0x02153B88  data
 */
typedef unsigned char u8;
extern u8 addr_02153B88;
void func_0209128C(int r0) {
    u8 val;
    if (r0 != 0) {
        val = 1;
    } else {
        val = 0;
    }
    addr_02153B88 = val;
}
