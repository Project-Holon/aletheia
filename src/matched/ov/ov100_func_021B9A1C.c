/*
 * function: func_021B9A1C
 * address: 0x021B9A1C
 * packet: pkt_ov100_021B9A1C
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_02039CB4 0x02039CB4 arm
 *   func_0203D7B0 0x0203D7B0 arm
 *   func_0203D7BC 0x0203D7BC arm
 *   func_021B95B8 0x021B95B8 thumb ov100
 *   func_021B99F4 0x021B99F4 thumb ov100
 */
extern void *func_020399A8(void);
extern int func_02039CB4(void *,int,int);
extern void func_0203D7B0(int),func_0203D7BC(int);
extern void func_021B95B8(unsigned char *,unsigned);
extern void func_021B99F4(void);
void func_021B9A1C(unsigned a)
{
 if(func_02039CB4(func_020399A8(),0x7f,12)!=0) {
  func_0203D7B0(0); func_0203D7BC(0);
  *(int *)(a+0xcac)=0;
  func_021B95B8((unsigned char *)a,(unsigned)func_021B99F4);
 }
}
