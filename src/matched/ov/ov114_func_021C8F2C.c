/*
 * function: DPW_BT_Init
 * address: 0x021C8F2C
 * packet: pkt_ov114_021C8F2C
 * region: ov114
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * status: EXACT
 * symbols:
 *   gDpwBtWork 0x021D4084 data a4
 *   gDpwBtServerIndex 0x021D3EFC data a4
 */
extern unsigned gDpwBtWork[];
extern unsigned gDpwBtServerIndex;
void DPW_BT_Init(unsigned a, unsigned b, unsigned c, unsigned mode)
{
    gDpwBtWork[0] = 1;
    gDpwBtWork[1] = 0;
    gDpwBtWork[2] = a;
    gDpwBtWork[3] = b;
    gDpwBtWork[4] = c;
    switch (mode) {
    case 0: gDpwBtServerIndex = 0; break;
    case 1: gDpwBtServerIndex = 1; break;
    case 2: gDpwBtServerIndex = 2; break;
    default: gDpwBtServerIndex = 1; break;
    }
}
