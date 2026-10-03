/*
 * function: func_021B9888
 * address: 0x021B9888
 * packet: pkt_ov100_021B9888
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 */
extern void *func_020399A8(void);
void func_021B9888(unsigned a,int b,int *c,unsigned d,void *e)
{
 if(e==func_020399A8()) *(int *)(d+a*4+0x250)=*c;
}
