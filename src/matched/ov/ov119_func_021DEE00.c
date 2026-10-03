/*
 * function: func_021DEE00
 * address: 0x021DEE00
 * packet: pkt_ov119_021DEE00
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_02039CB4 0x02039CB4 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_021E1024 0x021E1024 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DEDBC 0x021DEDBC thumb ov119
 *   func_021DE8C0 0x021DE8C0 thumb ov119
 */
extern unsigned func_020399A8(void);
extern int func_02039CB4(unsigned,int,int);
extern void func_02045CAC(int,int,int);
extern void func_021E1024(void *);
extern void func_021D8E84(void *,int);
extern void func_021DEDBC(void *);
extern void func_021DE8C0(char *p);
void func_021DEE00(unsigned char *p) {
 int v;
 if(func_02039CB4(func_020399A8(),21,8)) {
  if(p[0x11e6]==0 && p[0x11e7]==0) {func_021D8E84(p,(int)func_021DEDBC);return;}
  if(p[0x11e6]==0xf0) v=0x9e;
  else if(p[0x11e6]==0xf1) v=0x9f;
  else if(p[0x11e6]==0xf2) v=0xa0;
  else if(p[0x11e6]==0xff) v=0xa1;
  else if((p[0x11e7]&0xf0)==0xf0) v=0xa1;
  else if(p[0x11e7]) v=0x8f;
  else v=0x90;
  func_02045CAC(*(int *)(p+0x720),v,*(int *)(p+0x738));
  func_021E1024(p);p[0x11f1]=120;*(int *)(p+0xf2c)=0;
  func_021D8E84(p,(int)func_021DE8C0);
 }
}
