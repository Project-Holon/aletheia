/*
 * function: NHTTP_RAP_ConnectionCallback
 * address: 0x021B95C0
 * packet: pkt_ov114_021B95C0
 * region: ov114
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
int NHTTP_RAP_ConnectionCallback(int a, int b, unsigned int *p)
{
    switch (b) {
    case 1: break;
    case 2:
    case 3: p[2] = 0; break;
    }
    return 0;
}
