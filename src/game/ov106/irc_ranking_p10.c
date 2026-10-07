/*
 * file:     irc_ranking_p10.c
 * unit:     yes
 * function: func_021B9298, func_021B92D4
 * address:  0x021B9298
 * region:   ov106
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020437D4 0x020437D4 arm
 *   func_02082A90 0x02082A90 arm
 *   d_021B9680 0x021B9680 data ov106 a1
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_020457B0 0x020457B0 arm
 *   func_02043678 0x02043678 arm
 *   func_020255A0 0x020255A0 thumb
 */
#include "../../matched/include/Obj06376.h"
#include "../../matched/include/Obj07992.h"

struct Bmp;
struct Grid;
struct Param;
struct Sys;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef short s16;

typedef struct { void *bmp; s16 x,y; int f8,fc;u8 f10,f11;u16 f12;int f14; } Param;

extern void *func_020437D4(const struct Bmp *bmp);
extern void func_02082A90(const void *src, void *dst, u32 size);
extern void *func_02030734(unsigned,unsigned,int,const char *,u16);
extern void func_02082BCC(void *,int,unsigned);
extern void *func_020457B0(int,u16);
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u16 heap);
extern struct Grid *func_020255A0(struct Sys *sys, const struct Param *param);
void func_021B9298(const struct Bmp *a, const struct Bmp *b, int x, int y, u16 sx, u16 sy, u16 w, u16 h);
void *func_021B92D4(const u8 *pos, u8 a, u8 b, int c, u8 d, int e, void *sys, void *owner, u16 heap);
extern const char d_021B9680[];

void func_021B9298(const struct Bmp *a, const struct Bmp *b, int x, int y, u16 sx, u16 sy, u16 w, u16 h) {
    u8 *dst = func_020437D4(a);
    u8 *src = func_020437D4(b);
    func_02082A90(dst + (x + w * y) * 32, src + (sx + w * sy) * 32, w * h * 32);
}

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
