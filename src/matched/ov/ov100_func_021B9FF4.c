/*
 * function: func_021B9FF4
 * address: 0x021B9FF4
 * packet: pkt_ov100_021B9FF4
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:

 */
void func_021B9FF4(int a,int b) {
 *(int *)(a+0xc7c)=b;
 *(int *)(a+0xc8c)=1;
 *(int *)(a+0xc94)=1;
 if(*(int *)(a+0x24c)==5 && b==0) {
  *(int *)(a+0xc80)=1;
  *(int *)(a+0xc84)=1;
 }
}
