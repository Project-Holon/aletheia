/*
 * function: func_021DABE8
 * address: 0x021DABE8
 * packet: pkt_ov119_021DABE8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_02039CB4 0x02039CB4 arm
 *   func_0203D7B0 0x0203D7B0 arm
 *   func_0203D7BC 0x0203D7BC arm
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DABB0 0x021DABB0 thumb ov119
 */
struct Entry;
extern struct Entry *func_020399A8(void);
struct Link;
extern unsigned int func_02039CB4(struct Link *p, unsigned int lo, unsigned int hi);
extern void func_0203D7B0(int),func_0203D7BC(int);
extern void func_021D8E84(char *,int),func_021DABB0(char *);
void func_021DABE8(char *p) {
 if(func_02039CB4((struct Link *)func_020399A8(),22,8)) {
  func_0203D7B0(1);
  func_0203D7BC(1);
  *(int *)(p+0xf2c)=0;
  func_021D8E84(p,(int)func_021DABB0);
 }
}
