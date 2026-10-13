/*
 * function: DPW_TR_Init
 * address: 0x021C7BA0
 * packet: pkt_ov114_021C7BA0
 * region: ov114
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * status: EXACT
 * symbols:
 * gDpwTrWork 0x021D3D2C data a4
 * gDpwTrServerIndex 0x021D3D28 data a4
 */
extern unsigned int gDpwTrWork[], gDpwTrServerIndex;
void DPW_TR_Init(unsigned int a, unsigned int b, unsigned int c, int d)
{
    gDpwTrWork[0] = 1;
    gDpwTrWork[1] = 0;
    gDpwTrWork[2] = a;
    gDpwTrWork[3] = b;
    gDpwTrWork[4] = c;
    switch (d) {
    case 0: gDpwTrServerIndex = 0; break;
    case 1: gDpwTrServerIndex = 1; break;
    case 2: gDpwTrServerIndex = 2; break;
    default: gDpwTrServerIndex = 1; break;
    }
}
