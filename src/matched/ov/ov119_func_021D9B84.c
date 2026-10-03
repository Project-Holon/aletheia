/*
 * function: func_021D9B84
 * address: 0x021D9B84
 * packet: pkt_ov119_021D9B84
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D8A24 0x021D8A24 thumb ov119
 *   func_020399A8 0x020399A8 arm
 *   func_02039CB4 0x02039CB4 arm
 *   func_021E1098 0x021E1098 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021D9434 0x021D9434 thumb ov119
 */
extern int func_021D8A24(void *);
extern int func_020399A8(void);
extern int func_02039CB4(int,int,int);
extern void func_021E1098(char *p);
extern void func_021D8E84(void *,int);
extern void func_021D9434(void *);
void func_021D9B84(void *p) {
 if(func_021D8A24(p)) {
  if(func_02039CB4(func_020399A8(),20,8)) {
   func_021E1098(p); func_021D8E84(p,(int)func_021D9434);
  }
 } else { func_021E1098(p); func_021D8E84(p,(int)func_021D9434); }
}
