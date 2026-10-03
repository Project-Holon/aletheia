/*
 * function: func_06899E2C
 * address: 0x06899E2C
 * packet: pkt_ov095_06899E2C
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 */
typedef unsigned int u32;
void func_06899E2C(unsigned char *p) {
 int i;
 u32 zero;
 unsigned char *q;
 zero=0;
 for(i=0;i<4;i++) {
  q=p+i*16;
  *(u32 *)(q+0x20)=zero;
  *(u32 *)(q+0x24)=zero;
  *(u32 *)(q+0x28)=zero;
  *(u32 *)(q+0x2c)=zero;
 }
 *(u32 *)(p+0x60)=zero;
}
