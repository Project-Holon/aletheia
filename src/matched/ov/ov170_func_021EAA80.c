/*
 * function: func_021EAA80
 * address: 0x021EAA80
 * packet: pkt_ov170_021EAA80
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045088 0x02045088 arm
 *   func_020450F0 0x020450F0 arm
 *   d_021EFC20 0x021EFC20 data a1
 */
#define WORK(p) (*(char **)((p)+0x2C))
extern void func_02045088(unsigned);
extern void *func_020450F0(unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char);
extern const unsigned char d_021EFC20[];
void func_021EAA80(unsigned char *p) {
 const unsigned char *x; unsigned i;
 func_02045088(0x4C);
 x=d_021EFC20;
 for(i=0;i<28;i++,x+=6)
  *(void **)(WORK(p)+0x94+i*8)=func_020450F0(x[0],x[1],x[2],x[3],x[4],x[5],1);
}
