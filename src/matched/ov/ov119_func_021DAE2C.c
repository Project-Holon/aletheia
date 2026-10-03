/*
 * function: func_021DAE2C
 * address: 0x021DAE2C
 * packet: pkt_ov119_021DAE2C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_02039CB4 0x02039CB4 arm
 *   func_021DD24C 0x021DD24C thumb ov119
 *   func_020173EC 0x020173EC thumb
 *   func_021DD294 0x021DD294 thumb ov119
 *   func_021E1098 0x021E1098 thumb ov119
 *   func_02082BCC 0x02082BCC arm
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DBA80 0x021DBA80 thumb ov119
 */
struct Entry;
extern struct Entry *func_020399A8(void);
struct Link;
extern unsigned int func_02039CB4(struct Link *,unsigned,unsigned);
extern int func_021DD24C(void *),func_020173EC(void);
extern void func_021DD294(void *,int,int),func_021E1098(void *),func_02082BCC(void *,int,int);
extern void func_021D8E84(void *,int),func_021DBA80(void *);
void func_021DAE2C(char *p) {
 int i;
 if(func_02039CB4((struct Link *)func_020399A8(),25,8)==0) {func_021DD24C(p);return;}
 func_021DD294(p,1,1);func_021E1098(p);
 p[0x11e0]=0;p[0x11e1]=0;p[0x11e8]=0;p[0x11e9]=0;
 for(i=0;i<6;i++) {
  char *q=p+(i/3)*12+(i%3)*4;
  *(int *)(q+0xfa4)=-1;
  if(*(void **)(q+0xfd8))func_02082BCC(*(void **)(q+0xfd8),0,func_020173EC());
 }
 func_021D8E84(p,(int)func_021DBA80);
}
