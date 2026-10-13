/*
 * function: FLDEFF_GYOE_PlaySe
 * address:  0x021BB778
 * packet:   pkt_ov021_021BB778
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020061E4  0x020061E4  thumb
 */

typedef unsigned int   u32;
void func_020061E4(u32 a);

void FLDEFF_GYOE_PlaySe(int n)
{
    int id = 0;

    switch (n) {
    case 0:
        id = 0x678;
        break;
    case 1:
        id = 0x730;
        break;
    case 2:
        id = 0x731;
        break;
    case 3:
        return;
    }
    func_020061E4(id);
}
