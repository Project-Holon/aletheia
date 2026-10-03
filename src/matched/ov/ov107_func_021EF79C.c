/*
 * function: func_021EF79C
 * address: 0x021EF79C
 * packet: pkt_ov107_021EF79C
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02178E4C 0x02178E4C thumb ov014
 *   func_02178E84 0x02178E84 thumb ov014
 *   func_02179498 0x02179498 thumb ov014
 *   func_021F0DB4 0x021F0DB4 thumb ov107
 *   func_02179158 0x02179158 thumb ov014
 *   func_021790E4 0x021790E4 thumb ov014
 *   func_02037010 0x02037010 arm
 *   func_02037118 0x02037118 arm
 *   func_020351F8 0x020351F8 arm
 *   func_02012944 0x02012944 thumb
 *   func_021EF96C 0x021EF96C thumb ov107
 *   func_021F1898 0x021F1898 thumb ov107
 *   func_021F1628 0x021F1628 thumb ov107
 *   func_021F18D8 0x021F18D8 thumb ov107
 *   func_02008534 0x02008534 thumb
 *   func_021F1918 0x021F1918 thumb ov107
 *   func_02012FFC 0x02012FFC thumb
 *   func_021F1704 0x021F1704 thumb ov107
 *   func_021F18EC 0x021F18EC thumb ov107
 *   func_021EFA14 0x021EFA14 thumb ov107
 *   func_021F17E0 0x021F17E0 thumb ov107
 *   func_021F1B38 0x021F1B38 thumb ov107
 *   func_0204B878 0x0204B878 arm
 *   func_02179570 0x02179570 thumb ov014
 *   func_021EFC10 0x021EFC10 thumb ov107
 *   func_021EFCA8 0x021EFCA8 thumb ov107
 *   func_0208EE9C 0x0208EE9C arm
 *   func_020370F4 0x020370F4 arm
 *   func_02037154 0x02037154 arm
 *   d_021F6EA0 0x021F6EA0 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_02178E4C(void),func_02178E84(void),func_02179498(void);
extern void func_021F0DB4(void),func_02179158(void);
extern int func_021790E4(u32,int,int);
extern void func_02037010(u32,u32,u32,u32),func_02037118(u32,u32);
extern void func_020351F8(void (*)(int),void *);
struct Sub0200852CObj;
extern u8 *func_02012944(void *p);
extern void func_021EF96C(u8 *),func_021F1898(void *),func_021F1628(void *,int),func_021F18D8(void *);
extern u16 func_02008534(const struct Sub0200852CObj *obj);
extern void func_021F1918(unsigned char *a, int b, int c, int d);
extern signed char func_02012FFC(void);
extern void func_021F1704(void *,int,int),func_021F18EC(void *),func_021EFA14(u8 *),func_021F17E0(void *,int),func_021F1B38(void *,u32),func_0204B878(void *,u16);
extern int func_02179570(int (*)(int)),func_021EFC10(int),func_0208EE9C(void);
extern u32 func_020370F4(u32);
extern void func_02037154(void);
extern u8 d_021F6EA0[];
extern void func_021EFCA8(int);
int func_021EF79C(u8 *p)
{
 void *q;
 if(func_02178E4C()==9 || func_02178E4C()==10){
  *(int *)(p+0x30)=0;*(int *)(p+0x14)=1;
  if(func_02179498()==1){func_021F0DB4();func_02179158();return 1;}return 0;
 }
 switch(p[0x24]){
 case 0:
  *(int *)(d_021F6EA0+8)=0;*(int *)(p+0x1C)=1;
  func_021790E4(*(u16 *)p,(int)func_021EFC10,0);
  func_02037010(240,0,0,*(u16 *)p);
  if(p[0x28]==0)func_02037118(0,*(u16 *)p);
  else func_02037118(1,*(u16 *)p);
  p[0x24]=1;func_020351F8(func_021EFCA8,p);break;
 case 1:
  if(func_02178E4C()==1 && func_02178E84()==1)p[0x24]=2;break;
 default:break;
 case 2:
  if(func_02178E4C()==7){
   q=func_02012944(*(void **)(*(u8 **)(p+8)+4));func_021EF96C(p);
   func_021F1898(*(void **)(p+0x68));
   if(p[0x28]==0)func_021F1628(*(void **)(p+0x68),2);
   else func_021F1628(*(void **)(p+0x68),3);
   func_021F18D8(*(void **)(p+0x68));func_021F1918(*(void **)(p+0x68),0,func_02008534(q),5);
   if(p[0x28]==0)func_021F1704(*(void **)(p+0x68),0,func_02012FFC());
   else func_021F1704(*(void **)(p+0x68),20,func_02012FFC());
   func_021F18EC(*(void **)(p+0x68));p[0x24]=3;
  }break;
 case 3:func_021EFA14(p);break;
 case 4:
  func_021F1898(*(void **)(p+0x68));func_021F1628(*(void **)(p+0x68),1);
  if(p[0x28]==0)func_021F17E0(*(void **)(p+0x68),1);
  else func_021F17E0(*(void **)(p+0x68),21);
  func_021F1B38(*(void **)(p+0x68),1);func_0204B878(*(void **)(p+0x7C),15);p[0x24]=5;break;
 case 5:*(int *)(p+0x30)=1;p[0x24]=6;break;
 case 8:p[0x24]=6;break;
 case 6:*(int *)(d_021F6EA0+8)=0;func_02179570(func_021EFC10);*(int *)(p+0x1C)=0;p[0x24]=7;break;
 case 7:if(*(int *)(d_021F6EA0+8)==1){func_020351F8(0,0);func_02179158();return 1;}break;
 }
 func_020370F4(3-func_0208EE9C());func_02037154();return 0;
}
