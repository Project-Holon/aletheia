/*
 * function: func_021BCD08
 * address: 0x021BCD08
 * packet: pkt_ov216_021BCD08
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020862F0 0x020862F0 arm
 *   func_0207E3D0 0x0207E3D0 arm
 *   func_0207E468 0x0207E468 arm
 *   func_0207E51C 0x0207E51C arm
 *   func_0207E5D0 0x0207E5D0 arm
 */
extern void func_020862F0(void *,unsigned);
extern void func_0207E3D0(void *,unsigned,unsigned);
extern void func_0207E468(void *,unsigned,unsigned);
extern void func_0207E51C(void *,unsigned,unsigned);
extern void func_0207E5D0(void *,unsigned,unsigned);
void func_021BCD08(void *p,unsigned mode,unsigned a,unsigned b)
{
    unsigned x=a*2,y=b*2;
    func_020862F0(p,y);
    switch(mode) {
    case 0: func_0207E3D0(p,x,y); break;
    case 1: func_0207E468(p,x,y); break;
    case 2: func_0207E51C(p,x,y); break;
    case 3: func_0207E5D0(p,x,y); break;
    }
}
