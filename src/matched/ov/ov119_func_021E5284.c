/*
 * function: func_021E5284
 * address: 0x021E5284
 * packet: pkt_ov119_021E5284
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * interface: 02040618's legacy fourth argument is forwarded only to
 * 02042360, whose complete matched body reads r0-r2 and never r3.
 * The original calls here set only r0-r2; retain its three-input API.
 * symbols:
 *   func_021E57E8 0x021E57E8 thumb ov119
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_02040C14 0x02040C14 arm
 *   func_02041300 0x02041300 arm
 *   func_020409B4 0x020409B4 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02040618 0x02040618 arm
 *   func_02049238 0x02049238 arm
 *   d_021E7E24 0x021E7E24 data a4
 *   d_021E7F44 0x021E7F44 data a4
 */
#include "../include/Obj02829.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct BgTemplate { u32 a,b,bufSize,d; u8 e,f,g,h; u32 i; u8 j,k,l,m; u32 n; } BgTemplate;
extern const BgTemplate d_021E7E24,d_021E7F44;
extern void func_021E57E8(int),func_0203FCA0(u32,const BgTemplate *,u32);
extern void func_02040C14(u32,u32,u32,u32),func_02041300(u32,int,int,int,u8,u8,u8),func_020409B4(u32);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02040618(u32,u32,u32),func_02049238(void *);
void func_021E5284(char *p,int mode)
{
 BgTemplate a,b;
 void *v;
 func_021E57E8(1);p[0x11ec]=1;
 a=d_021E7E24;func_0203FCA0(6,&a,0);func_02040C14(6,0,1,0);func_02041300(6,0,0,0,32,24,17);func_020409B4(6);
 b=d_021E7F44;func_0203FCA0(7,&b,2);
 if(mode==0) {
  v=func_020490F4(0x67,((struct Obj02829 *)p)->f5F4);
  func_02049B68(v,5,6,0x6000,0,((struct Obj02829 *)p)->f5F4);
  func_02049658((void *)((u32)v),4,7,0,0,0,((struct Obj02829 *)p)->f5F4);
  func_020498F4((void *)((u32)v),6,7,0,0,0,((struct Obj02829 *)p)->f5F4);
  func_02040618(7,0,0);func_02049238(v);
 } else {
  v=func_020490F4(0x68,((struct Obj02829 *)p)->f5F4);
  func_02049B68(v,1,6,0x6000,0,((struct Obj02829 *)p)->f5F4);
  func_02049658((void *)((u32)v),0,7,0,0,0,((struct Obj02829 *)p)->f5F4);
  func_020498F4((void *)((u32)v),2,7,0,0,0,((struct Obj02829 *)p)->f5F4);
  func_02040618(7,0,0);func_02049238(v);
 }
}
