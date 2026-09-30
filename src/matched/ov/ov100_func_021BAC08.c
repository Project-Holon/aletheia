/*
 * function: func_021BAC08
 * address: 0x021BAC08
 * packet: pkt_ov100_021BAC08
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201DD68 0x0201DD68 thumb
 *   func_021BA5F4 0x021BA5F4 thumb ov100
 *   func_02040DA8 0x02040DA8 arm
 *   func_0203FB44 0x0203FB44 arm
 *   func_020403F4 0x020403F4 arm
 *   func_02045C04 0x02045C04 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_02045808 0x02045808 arm
 *   func_02040588 0x02040588 arm
 *   func_02027FD8 0x02027FD8 thumb
 *   func_021BA640 0x021BA640 thumb ov100
 */
extern void func_0201DD68(void),func_021BA5F4(int),func_02040DA8(int,int,int),func_0203FB44(int,unsigned short,unsigned short),func_020403F4(int),func_02045C04(int),func_0201D83C(int),func_02045808(int),func_02040588(int,int),func_02027FD8(int),func_021BA640(int);
void func_021BAC08(int a) {
 func_0201DD68();
 func_021BA5F4(a);
 func_02040DA8(5,1,0);
 {
  unsigned int v=*(int *)(a+0x304);
  unsigned int w=v>>16;
  func_0203FB44(5,(unsigned short)v,(unsigned short)w);
 }
 func_020403F4(5);
 func_02045C04(*(int *)(a+0x288));
 func_0201D83C(*(int *)(a+0x290));
 func_02045808(*(int *)(a+0x294));
 func_02045808(*(int *)(a+0x298));
 func_02040588(5,0);
 func_02027FD8(*(int *)(a+0xcc4));
 func_021BA640(a);
}
