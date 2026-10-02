/*
 * function: func_021DA798
 * address: 0x021DA798
 * packet: pkt_ov119_021DA798
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_021D8A24 0x021D8A24 thumb ov119
 *   func_02039CB4 0x02039CB4 arm
 *   func_02039C68 0x02039C68 arm
 *   func_021DD24C 0x021DD24C thumb ov119
 *   func_021DD294 0x021DD294 thumb ov119
 *   func_02045CAC 0x02045CAC arm
 *   func_021E1024 0x021E1024 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DA76C 0x021DA76C thumb ov119
 *   func_021DAEF0 0x021DAEF0 thumb ov119
 */
extern unsigned func_020399A8(void);
extern unsigned func_0203D1A4(unsigned);
extern int func_021D8A24(void *);
extern unsigned func_02039CB4(unsigned,unsigned,unsigned);
extern void func_02039C68(unsigned,unsigned,unsigned);
extern int func_021DD24C(void *);
extern void func_021DD294(void *,int,int);
extern void func_02045CAC(unsigned,unsigned,unsigned);
extern void func_021E1024(void *);
extern void func_021D8E84(void *,int);
extern void func_021DA76C(void *),func_021DAEF0(void *);
void func_021DA798(char *p) {
 int i, j, v;
 unsigned char a, b;
 i = func_0203D1A4(func_020399A8());
 j = 1 - i;
 if(func_021D8A24(p) && func_02039CB4(func_020399A8(),27,8)==0) {
  func_021DD24C(p);
  return;
 }
 func_021DD294(p,1,1);
 a = (p+i)[0x11e0];
 if(a==2 && ((unsigned char *)(p+j))[0x11e0]==2) {
  if(func_021D8A24(p)) func_02039C68(func_020399A8(),13,8);
  func_021D8E84(p,(int)func_021DA76C);
  return;
 }
 b = (p+j)[0x11e0];
 if(b==5) v=0x61;
 else if(a==5) v=0x62;
 else if(b==7) v=0x63;
 else if(a==7) v=0x64;
 else if(b==8) v=0x64;
 else if(a==8) v=0x63;
 else if(b==9) v=0x61;
 else if(a==9) v=0x65;
 else if(b==6) v=0x61;
 else if(a==6) v=0x6f;
 else if(b==3) v=0x61;
 else if(a==3) v=0x66;
 func_02045CAC(*(unsigned *)(p+0x720),v,*(unsigned *)(p+0x738));
 func_021E1024(p);
 p[0x11e0]=0;
 p[0x11e1]=0;
 func_021D8E84(p,(int)func_021DAEF0);
}
