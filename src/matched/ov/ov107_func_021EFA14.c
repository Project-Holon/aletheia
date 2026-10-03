/*
 * function: func_021EFA14
 * address: 0x021EFA14
 * packet: pkt_ov107_021EFA14
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: follower 021EFC10 already has its own matched source/shard.
 * ABI: 19E4 keeps the caller's visibly supplied r1. 0AE4 reads no incoming arguments.
 * symbols:
 *   func_021F0D28 0x021F0D28 thumb ov107
 *   func_02035C08 0x02035C08 arm
 *   func_020362DC 0x020362DC arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_020061E4 0x020061E4 thumb
 *   func_021F0A28 0x021F0A28 thumb ov107
 *   func_021F0A64 0x021F0A64 thumb ov107
 *   func_021F0AE4 0x021F0AE4 thumb ov107
 *   func_021F1898 0x021F1898 thumb ov107
 *   func_021F1628 0x021F1628 thumb ov107
 *   func_02012FFC 0x02012FFC thumb
 *   func_021F1704 0x021F1704 thumb ov107
 *   func_021F1B14 0x021F1B14 thumb ov107
 *   func_021F1930 0x021F1930 thumb ov107
 *   func_021F19E4 0x021F19E4 thumb ov107
 *   func_021F19C8 0x021F19C8 thumb ov107
 *   func_021F1A2C 0x021F1A2C thumb ov107
 *   func_02034714 0x02034714 arm
 *   func_021EFC1C 0x021EFC1C thumb ov107
 *   func_02012944 0x02012944 thumb
 *   func_021F19B8 0x021F19B8 thumb ov107
 *   func_021F1A24 0x021F1A24 thumb ov107
 *   func_021F18D8 0x021F18D8 thumb ov107
 *   func_02008534 0x02008534 thumb
 *   func_021F1918 0x021F1918 thumb ov107
 *   func_021F18EC 0x021F18EC thumb ov107
 *   d_021F6AF8 0x021F6AF8 data a4
 *   d_021F6E08 0x021F6E08 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u16 func_021F0D28(void);
extern int func_02035C08(const void *),func_021F0A28(void),func_021F1B14(void *),func_021F19C8(void *),func_021F1A2C(void *);
extern u32 func_020362DC(void);
extern void func_0204B878(void *,u16),func_0204B92C(void *,u32),func_020061E4(u32);
extern void func_021F0A64(void),func_021F0AE4(void),func_021F1898(void *),func_021F1628(void *,int);
struct Sub0200852CObj;
extern signed char func_02012FFC(void);
extern void func_021F1704(void *,int,int),func_021F1930(void *,int),func_021F19E4(void *,int);
extern void func_02034714(void *,int,void *),func_021EFC1C(u8 *,int);
extern u8 *func_02012944(void *p);
extern void func_021F19B8(void *),func_021F1A24(void *),func_021F18D8(void *);
extern u16 func_02008534(const struct Sub0200852CObj *obj);
extern void func_021F1918(void *,int,u16,int),func_021F18EC(void *);
extern u8 d_021F6AF8[],d_021F6E08[];
void func_021EFA14(u8 *p)
{
 int a;void *q;
 func_021F0D28();
 switch(func_021F0D28()){
 case 2:
  if(p[0x26]==0){
   a=func_02035C08(d_021F6AF8);
   if(func_020362DC()==2 || (a==0 && p[0x28]==0)){
    p[0x26]=1;func_0204B878(*(void **)(p+0x7C),9);func_0204B92C(*(void **)(p+0x7C),1);func_020061E4(1361);
   }else if(func_021F0A28()){func_021F0A64();}
  }break;
 case 5:p[0x24]=4;break;
 case 7:func_021F0AE4();break;
 case 0:p[0x24]=8;break;
 case 1:case 3:case 4:case 6:default:break;
 }
 switch(p[0x26]){
 case 1:
  func_021F1898(*(void **)(p+0x68));func_0204B878(*(void **)(p+0x7C),15);
  if(p[0x28]==0){func_021F1628(*(void **)(p+0x68),7);func_021F1704(*(void **)(p+0x68),9,func_02012FFC());}
  else {func_021F1628(*(void **)(p+0x68),5);func_021F1704(*(void **)(p+0x68),42,func_02012FFC());}
  p[0x26]=2;break;
 case 2:
  if(func_021F1B14(*(void **)(p+0x68))==1){
   if(p[0x28]==0)func_021F1930(*(void **)(p+0x68),0);
   else func_021F19E4(*(void **)(p+0x68),0);
   p[0x26]=3;
  }break;
 case 3:
  if(p[0x28]==0)a=func_021F19C8(*(void **)(p+0x68));
  else a=func_021F1A2C(*(void **)(p+0x68));
  if(a==1){
   if(func_021F0D28()!=2)func_02034714(d_021F6E08,0,d_021F6E08);
   func_021EFC1C(p,4);func_021F0AE4();p[0x26]=4;
  }else if(a==2){
   q=func_02012944(*(void **)(*(u8 **)(p+8)+4));
   if(p[0x28]==0)func_021F19B8(*(void **)(p+0x68));else func_021F1A24(*(void **)(p+0x68));
   func_021F1898(*(void **)(p+0x68));
   if(p[0x28]==0)func_021F1628(*(void **)(p+0x68),2);else func_021F1628(*(void **)(p+0x68),3);
   func_021F18D8(*(void **)(p+0x68));func_021F1918(*(void **)(p+0x68),0,func_02008534(q),5);
   func_0204B878(*(void **)(p+0x7C),1);
   if(p[0x28]==0)func_021F1704(*(void **)(p+0x68),0,func_02012FFC());else func_021F1704(*(void **)(p+0x68),20,func_02012FFC());
   func_021F18EC(*(void **)(p+0x68));p[0x26]=0;
  }break;
 }
}
