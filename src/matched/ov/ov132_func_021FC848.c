/*
 * function: func_021FC848
 * address: 0x021FC848
 * packet: pkt_ov132_021FC848
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAME_DATA_GetSaveBlock2A 0x02012F44 thumb
 *   func_020173EC 0x020173EC thumb
 *   POKE_TOOL_GetBoxParamSize 0x020173E8 thumb
 *   MYSTATUS_GetSize 0x02008468 thumb
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0200A81C 0x0200A81C thumb
 *   d_021FDE5C 0x021FDE5C data a4
 * 02012F44 returns the live pointer from its forwarding target 020071CC;
 * its matched void prototype discards that result.
 * Lever: row is block-local; the final fill has a per-entry pointer.
 * The SDK MI_CpuClear8 inline spelling restores both fill-call setup orders
 * (direct MI_CpuFill8 leaves 15 bytes; data/size signedness changes are flat).
 */
#include "../include/Obj02195.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *GAME_DATA_GetSaveBlock2A(void *);
extern u32 func_020173EC(void);
extern u32 POKE_TOOL_GetBoxParamSize(void);
extern int MYSTATUS_GetSize(void);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void func_02082BCC(void *,u8,u32);
struct Big;
extern u16 func_0200A81C(struct Big *p);
extern const char d_021FDE5C[];
static inline void clear8(void *dest,u32 size)
{
 func_02082BCC(dest,0,size);
}
#define W(q,k) (*(u32 *)((q)+(k)))
#define P(q,k) (*(u8 **)((q)+(k)))
void func_021FC848(u8 *p,void *a,void *b,int unused,void *d,u16 heap)
{
 void *data;
 u32 size1,size2;
 u8 i,j;
 data=GAME_DATA_GetSaveBlock2A(P(p,0x58));
 ((struct Obj02195 *)p)->f0=heap;
 for(i=0;i<4;i++) {
  u8 *row;
  row=p+i*0x30;
  W(row,0x60)=0;
  row[0x72]=i;
  W(row,0x78)=0;
  W(row,0x64)=0;W(row,0x68)=0;W(row,0x6C)=0;
  row[0x70]=10;row[0x71]=10;
  P(row,0x7C)=func_02030734(((struct Obj02195 *)p)->f0,func_020173EC()+0x7C,0,d_021FDE5C,0x20E);
  size1=MYSTATUS_GetSize();
  P(row,0x8C)=func_02030734(((struct Obj02195 *)p)->f0,(size1+4)+POKE_TOOL_GetBoxParamSize(),0,d_021FDE5C,0x20F);
  clear8(P(row,0x7C),func_020173EC()+0x7C);
  size2=MYSTATUS_GetSize();
  clear8(P(row,0x8C),(size2+4)+POKE_TOOL_GetBoxParamSize());
  P(row,0x80)=P(row,0x8C);
  P(row,0x84)=P(row,0x8C)+4;
  P(row,0x88)=P(row,0x8C)+4+MYSTATUS_GetSize();
  for(j=0;j<2;j++) row[0x73+j]=0xFF;
 }
 ((struct Obj02195 *)p)->f12C=func_0200A81C(data);
 ((struct Obj02195 *)p)->f130=a;((struct Obj02195 *)p)->f134=b;
 W(p,0x138)=0;W(p,0x124)=0;
 P(p,0x128)=func_02030734(((struct Obj02195 *)p)->f0,(func_020173EC()+0x7C)*4,0,d_021FDE5C,0x221);
 size1=MYSTATUS_GetSize();
 P(p,0x13C)=func_02030734(((struct Obj02195 *)p)->f0,((size1+4)+POKE_TOOL_GetBoxParamSize())*4,0,d_021FDE5C,0x222);
 p[0x1C]=0;W(p,0x14)=0;W(p,0x18)=0;
 p[0x14C]=0;W(p,0x150)=0;
 W(p,0x158)=0;W(p,0x15C)=0;W(p,0x160)=0;W(p,0x164)=0;
 W(p,0x168)=0;W(p,0x170)=0;W(p,0x174)=0;W(p,0x17C)=0;
 W(p,0x184)=0;W(p,0x188)=0;
 p[0x180]=4;
 W(p,8)=1;
 for(j=0;j<8;j++) {
  u8 *entry=p+j*4;
  W(entry,0x18C)=0xFFFF;
 }
 ((struct Obj02195 *)p)->f140=d;
 W(p,0x4C)=1;
}
