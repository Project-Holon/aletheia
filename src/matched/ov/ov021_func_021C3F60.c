/*
 * function: SODATEYA_RollRandomIvInheritance
 * address:  0x021C3F60
 * packet:   pkt_ov021_021C3F60
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02005728  0x02005728  thumb  ov021
 */

typedef unsigned int u32;

extern u32 func_02005728(u32 n);

void SODATEYA_RollRandomIvInheritance(int a, u32 *p)
{
    while (p[0x22] < 3) {
        u32 r = func_02005728(6);

        if (func_02005728(2) == 0) {
            if (p[0x16 + r] == 0 && p[0x1c + r] == 0) {
                p[0x16 + r] = 1;
                p[0x22]++;
            }
        } else {
            if (p[0x16 + r] == 0 && p[0x1c + r] == 0) {
                p[0x1c + r] = 1;
                p[0x22]++;
            }
        }
    }
}
