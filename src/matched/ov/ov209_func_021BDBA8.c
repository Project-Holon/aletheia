/*
 * function: func_021BDBA8
 * address: 0x021BDBA8
 * packet: pkt_ov209_021BDBA8
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 */
extern void func_0204A8D4(unsigned);
extern void func_0204ADA4(unsigned);
extern void func_0204AFD8(unsigned);
void func_021BDBA8(char *p)
{
    unsigned i;
    for(i=0;i<36;i++)if(*(unsigned *)(p+i*4+0xb64)!=-1)func_0204A8D4(*(unsigned *)(p+i*4+0xb64));
    for(i=0;i<6;i++)if(*(unsigned *)(p+i*4+0xbf4)!=-1)func_0204ADA4(*(unsigned *)(p+i*4+0xbf4));
    for(i=0;i<6;i++)if(*(unsigned *)(p+i*4+0xc0c)!=-1)func_0204AFD8(*(unsigned *)(p+i*4+0xc0c));
}
