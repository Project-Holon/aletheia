/*
 * function: func_021B65A0
 * address: 0x021B65A0
 * packet: pkt_ov180_021B65A0
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02006CAC 0x02006CAC thumb
 *   func_020069D4 0x020069D4 thumb
 */
extern void func_02006CAC(unsigned *);
extern int func_020069D4(int,int,int,int,int,int,int,void *);
void func_021B65A0(char *p) {
 unsigned value;
 if(*(unsigned short *)(p+0x9158)==441) {
  func_02006CAC(&value);
  *(int *)(p+0x9184)=func_020069D4(*(unsigned short *)(p+0x9158),(unsigned char)p[0x915C],64,0,0,0,0,&value);
 } else *(int *)(p+0x9184)=func_020069D4(*(unsigned short *)(p+0x9158),(unsigned char)p[0x915C],64,0,0,0,0,0);
}
