/*
 * function: COLOSSEUM_CheckAllFinished
 * address: 0x0217FEB8
 * packet: pkt_ov019_0217FEB8
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_GetNegotiationNum 0x0203D1B4 arm
 *   func_02080D24 0x02080D24 arm
 */

typedef unsigned char u8;
extern int GFL_NET_GetNegotiationNum(void);
extern unsigned int func_02080D24(int a);
int COLOSSEUM_CheckAllFinished(u8 *p)
{
    int n=0; int i; int value=p[0x16e];
    for (i=0;i<4;i++) { if(p[0x162+i] == 1) n++; }
    if (n >= GFL_NET_GetNegotiationNum() || n >= (int)func_02080D24(value)) return 1;
    return 0;
}
