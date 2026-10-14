/*
 * function: HALL_OF_FAME_GetVramBanksAddr
 * address:  0x021B61FC
 * packet:   pkt_021B61FC
 * region:   ov180
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

int HALL_OF_FAME_GetVramBanksAddr(int a)
{
    if (a == 0)
        return 0x021B8060;
    return 0x021B8090;
}
