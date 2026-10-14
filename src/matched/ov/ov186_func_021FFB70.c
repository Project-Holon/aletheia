/*
 * function: BR_NET_IsStep
 * address: 0x021FFB70
 * packet: pkt_ov186_021FFB70
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
int BR_NET_IsStep(int *p,int value)
{
    if(*p==value) return 1;
    return 0;
}
