/*
 * function: func_021B9848
 * address: 0x021B9848
 * packet: pkt_ov100_021B9848
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:

 */
void func_021B9848(int a)
{
 if(*(int *)(a+0x24c)!=5) {
  *(int *)(a+0xc80)=1; *(int *)(a+0xc84)=1; *(int *)(a+0xca0)=1;
 } else {
  if(*(int *)(a+0xc7c)!=0 && *(int *)(a+0xc98)!=0) {
   *(int *)(a+0xc80)=1; *(int *)(a+0xc84)=1;
  }
 }
}
