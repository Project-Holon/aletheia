/*
 * function: func_021BAA9C
 * address: 0x021BAA9C
 * packet: pkt_ov100_021BAA9C
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: larger predicate follower 0x021BAAEC is filed separately.
 * symbols:
 *   func_0204E804 0x0204E804 arm
 *   func_0201283C 0x0201283C thumb
 *   func_02009A34 0x02009A34 thumb
 *   func_021B95B8 0x021B95B8 thumb ov100
 *   func_021BAFA0 0x021BAFA0 thumb ov100
 *   func_021BAB08 0x021BAB08 thumb ov100
 */
extern int func_0204E804(void),func_0201283C(int),func_02009A34(int);
extern void func_021B95B8(int,void (*)(void));
extern void func_021BAFA0(void),func_021BAB08(void);
void func_021BAA9C(int a) {
 if(func_0204E804()!=0) {
  if(*(int *)(a+0x24c)==7) {
   if(func_02009A34(func_0201283C(**(int **)(a+0x244)))==32) {
    func_021B95B8(a,func_021BAFA0);
    *(int *)(a+0xcac)=180;
    return;
   }
  }
  func_021B95B8(a,func_021BAB08);
 }
}
