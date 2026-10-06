/*
 * function: func_021B92D4
 * address: 0x021B92D4
 * packet: pkt_ov106_021B92D4
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021B9680 0x021B9680 data ov106 a1
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_020457B0 0x020457B0 arm
 *   func_02043678 0x02043678 arm
 *   func_020255A0 0x020255A0 thumb
 */
#include "../include/Obj06376.h"
#include "../include/Obj07992.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef struct { void *bmp; s16 x,y; int f8,fc;u8 f10,f11;u16 f12;int f14; } Param;
extern const char d_021B9680[];
extern void *func_02030734(unsigned,unsigned,int,const char *,u16);
extern void func_02082BCC(void *,int,unsigned);
extern void *func_020457B0(int,u16);
extern void *func_02043678(unsigned,unsigned,unsigned,u16);
struct Grid;
struct Param;
struct Sys;
extern struct Grid *func_020255A0(struct Sys *sys, const struct Param *param);
void *func_021B92D4(const u8 *pos, u8 a, u8 b, int c, u8 d, int e, void *sys, void *owner, u16 heap) {
 u8 *p; Param cfg;
 p=func_02030734(heap,36,0,d_021B9680,3402);
 func_02082BCC(p,0,36);
 ((struct Obj06376 *)p)->f20=owner;
 ((struct Obj06376 *)p)->f18=func_020457B0(128,heap);
 ((struct Obj06376 *)p)->f0=func_02043678(a,b,32,heap);
 func_02082BCC(&cfg,0,24);
 cfg.bmp=((struct Obj06376 *)p)->f0;cfg.x=((struct Obj07992 *)pos)->f0;cfg.y=((struct Obj07992 *)pos)->f2;
 cfg.f8=c;cfg.f10=pos[6];cfg.f12=e;cfg.f14=e;cfg.f11=pos[7];cfg.fc=d;
 ((struct Obj06376 *)p)->f1C=func_020255A0(sys,(const struct Param *)(&cfg));
 return p;
}
