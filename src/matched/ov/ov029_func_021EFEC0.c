/*
 * function: func_021EFEC0
 * address:  0x021EFEC0
 * packet:   pkt_ov029_021EFEC0
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf at the start of ov029 (the listing prints it as .word
 * data); called by C_GEAR_HandleButton.
 */

int func_021EFEC0(int a, int b)
{
    if (a % 2 == 0) {
        if (b < 3)
            return 1;
    } else {
        if (b < 4)
            return 1;
    }
    return 0;
}
