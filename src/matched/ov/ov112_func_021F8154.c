/*
 * function: STA_ACT_LIGHT_SetElemValue
 * address:  0x021F8154
 * packet:   pkt_ov112_021F8154
 * region:   ov112
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocked:  
 *
 * symbols:
 */

int STA_ACT_LIGHT_SetElemValue(int a0, int *a1, int a2)
{
    a1[3] = a2;
    a1[1] = 1;
    return 1;
}
