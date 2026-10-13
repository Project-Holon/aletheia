/*
 * function: COLOSSEUM_CheckAllEntered
 * address: 0x0217FDC8
 * packet: pkt_ov019_0217FDC8
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   GFL_NET_GetNegotiationNum 0x0203D1B4 arm
 */

typedef unsigned char u8;
extern int GFL_NET_GetNegotiationNum(void);
int COLOSSEUM_CheckAllEntered(u8 *p)
{
    int n=0; int i;
    for (i=0;i<4;i++) { if (p[0x3e + i*0x2c] == 1) n++; }
    if (n >= GFL_NET_GetNegotiationNum()) return 1;
    return 0;
}
