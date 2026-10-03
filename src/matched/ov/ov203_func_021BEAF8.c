/*
 * function: func_021BEAF8
 * address: 0x021BEAF8
 * packet: pkt_ov203_021BEAF8
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0208068C 0x0208068C arm
 *   func_0207D4B0 0x0207D4B0 arm
 *   func_02030EAC 0x02030EAC arm
 */
extern void func_0208068C(int);
struct Node;
extern void func_0207D4B0(int dispMode, int bgMode, int bg0_2d3d);
extern void func_02030EAC(struct Node *n);
void func_021BEAF8(void *node,int *s)
{
    int bank;
    switch(s[1]){case 2:bank=1;break;case 6:bank=2;break;case 10:bank=4;break;case 14:bank=8;break;default:bank=0;break;}
    func_0208068C(bank);func_0207D4B0(s[1],s[2],s[3]);s[12]=1;func_02030EAC(node);
}
