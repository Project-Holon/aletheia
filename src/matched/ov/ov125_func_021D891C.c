/*
 * function: GDS_SOCKET_GetRequestSize
 * address: 0x021D891C
 * packet: pkt_ov125_021D891C
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * status: EXACT
 */
int GDS_SOCKET_GetRequestSize(int n)
{
    int size;
    switch (n) {
    case 0: size = 0x400; break;
    case 0x5208: size = 0x230; break;
    case 0x5209: size = 12; break;
    case 0x55f0: size = 0x19a8; break;
    case 0x55f1: size = 28; break;
    case 0x55f2: size = 12; break;
    case 0x55f3: size = 8; break;
    default: return -1;
    }
    return size + 0x140;
}
