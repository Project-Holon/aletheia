/*
 * function: func_021B6100
 * address: 0x021B6100
 * packet: pkt_ov174_021B6100
 * region: ov174
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Store the two one-valued fields before committing the task handle; scheduler hoists its store after movs r1,#1.
 * symbols:
 *   func_021B63DC 0x021B63DC thumb ov174
 *   func_021B655C 0x021B655C thumb ov174
 *   func_021B6594 0x021B6594 thumb ov174
 *   func_021B6760 0x021B6760 thumb ov174
 *   func_021B63B0 0x021B63B0 thumb ov174
 *   func_020490F4 0x020490F4 arm
 *   func_021B6C70 0x021B6C70 thumb ov174
 *   func_020056A0 0x020056A0 thumb
 *   GAME_DATA_GetSeason 0x02012984 thumb
 *   TIMEZONE_GetZoneLightLevel 0x02011400 thumb
 *   func_0203F4CC 0x0203F4CC arm
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 */
#include "../include/Obj01167.h"
#include "../include/Obj24197.h"
typedef unsigned char u8;
typedef unsigned short u16;
struct RtcTime{unsigned hour,minute,second;};
struct BigObj;
extern void func_021B63DC(u8 *);
extern void func_021B655C(char *p);
extern void func_021B6594(u8 *);
extern void func_021B6760(u8 *);
extern void func_021B63B0(void);
typedef unsigned int   u32;
extern void *func_020490F4(u32 id, u32 heap);
extern char *func_021B6C70(char *p, int index);
extern void *func_020056A0(unsigned,unsigned,unsigned);
extern u8 GAME_DATA_GetSeason(const struct BigObj *p);
extern u8 TIMEZONE_GetZoneLightLevel(int row, int col);
extern void func_0203F4CC(struct RtcTime *),GFL_NET_RestartWithDefaultTimeout(unsigned,unsigned);
void func_021B6100(u8 *p)
{
 struct RtcTime time; unsigned config,lo,mid,hi; u8 i; void *task; unsigned one;
 func_021B63DC(p);
 ((struct Obj01167 *)p)->f18=func_020490F4(131,((struct Obj01167 *)p)->f0);
 func_021B655C((char *)p);func_021B6594(p);func_021B6760(p);
 config=GAME_DATA_GetSeason(((struct Obj24197 *)(*(u8 * *)&((struct Obj01167 *)p)->f30))->f4);
 lo=TIMEZONE_GetZoneLightLevel(config,0);mid=TIMEZONE_GetZoneLightLevel(config,2);hi=TIMEZONE_GetZoneLightLevel(config,3);
 func_0203F4CC(&time);
 if(time.hour>=lo && time.hour<mid) ((struct Obj01167 *)p)->f10=0;
 else if(time.hour>=mid && time.hour<hi) ((struct Obj01167 *)p)->f10=1;
 else ((struct Obj01167 *)p)->f10=2;
 for(i=0;i<((struct Obj01167 *)p)->f8;i++) *(void **)(p+28+i*4)=func_021B6C70((char *)p,i);
 task=func_020056A0((unsigned)func_021B63B0,(unsigned)p,8);
 one=1;((struct Obj01167 *)p)->fD=one;((struct Obj01167 *)p)->f34=one;
 ((struct Obj01167 *)p)->f4=task;((struct Obj01167 *)p)->f89=0;
 ((struct Obj01167 *)p)->fE=0;((struct Obj01167 *)p)->f14=0;((struct Obj01167 *)p)->f2C=0;((struct Obj01167 *)p)->fC=0;
 GFL_NET_RestartWithDefaultTimeout(0,((struct Obj01167 *)p)->f0);
}
