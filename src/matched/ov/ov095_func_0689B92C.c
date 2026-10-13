/*
 * function: BTL_SICK_GetDamageStringId
 * address:  0x0689B92C
 * packet:   pkt_ov095_0689B92C
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

int BTL_SICK_GetDamageStringId(int a)
{
    switch (a) {
    case 5:
        return 0xf3;
    case 4:
        return 0x105;
    case 9:
        return 0x144;
    case 10:
        return 0x42f;
    }
    return -1;
}
