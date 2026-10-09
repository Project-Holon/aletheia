/*
 * file:     irc_ranking_p03.c
 * unit:     yes
 * function: func_021B9298, func_021B92D4, func_021B9360, func_021B9380, func_021B93D8, func_021B93DC, func_021B93E4
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
 *   func_0202570C 0x0202570C thumb
 *   func_020437AC 0x020437AC arm
 *   func_02045808 0x02045808 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045CAC 0x02045CAC arm
 *   func_021B9414 0x021B9414 thumb ov106
 *   func_0201C724 0x0201C724 thumb
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_020257D0 0x020257D0 thumb
 */
#include "../../matched/include/Obj06376.h"
#include "../../matched/include/Obj07992.h"
#include "../../matched/include/Obj10256.h"
#include "../../matched/include/Obj03746.h"
#include "../../matched/include/Obj22271.h"
#include "../../matched/include/Obj10257.h"
#include "../../matched/include/Obj05282.h"

struct Bmp;
struct Grid;
struct Param;
struct Sys;
struct Obj020437AC;
struct U16Vec;
struct CharBuf;
struct MsgBank;
struct PrintSys;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef short s16;

typedef struct { void *bmp; s16 x,y; int f8,fc;u8 f10,f11;u16 f12;int f14; } Param;

typedef signed char s8;

typedef int s32;

extern void *func_020437D4(const struct Bmp *bmp);
extern void func_02082A90(const void *src, void *dst, u32 size);
extern void *func_02030734(unsigned,unsigned,int,const char *,u16);
extern void func_02082BCC(void *,int,unsigned);
extern void *func_020457B0(int,u16);
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u16 heap);
extern struct Grid *func_020255A0(struct Sys *sys, const struct Param *param);
extern void func_0202570C(struct Grid *g);
extern void func_020437AC(struct Obj020437AC *p);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_020307B0(void *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_021B9414(void *,int,int *);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_020257D0(void *);
void func_021B9298(const struct Bmp *a, const struct Bmp *b, int x, int y, u16 sx, u16 sy, u16 w, u16 h);
void *func_021B92D4(const u8 *pos, u8 a, u8 b, int c, u8 d, int e, void *sys, void *owner, u16 heap);
void func_021B9360(u8 *p);
void func_021B9380(u8 *p,void *a,void *b,int c);
void func_021B93D8(u8 *p, u16 v);
void func_021B93DC(u8 *p, u32 a, u32 b, u32 c);
int func_021B93E4(u8 *p);
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


void func_021B9360(u8 *p) { func_0202570C(((struct Obj10256 *)p)->f1C); func_020437AC(((struct Obj10256 *)p)->f0); func_02045808(((struct Obj10256 *)p)->f18); func_020307B0(p); }


/*
 * extent: two bytes of alignment padding after the return.
 */
void func_021B9380(u8 *p,void *a,void *b,int c) {
 int xy[2];
 func_02043B5C(((struct Obj03746 *)p)->f0,((struct Obj03746 *)p)->f4&31);
 func_02045CAC(a,(u32)b,((struct Obj03746 *)p)->f18);
 func_021B9414(p,c,xy);
 func_0201C724(((struct Obj03746 *)p)->f20,(u32)(((struct Obj03746 *)p)->f0),(short)xy[0],(short)xy[1],(u32)(((struct Obj03746 *)p)->f18),c,((struct Obj03746 *)p)->f4);
 ((struct Obj03746 *)p)->f8=1;
}



void func_021B93D8(u8 *p, u16 v) { ((struct Obj22271 *)p)->f4 = v; }



void func_021B93DC(u8 *p, u32 a, u32 b, u32 c) { ((struct Obj10257 *)p)->fC = a; ((struct Obj10257 *)p)->f10 = b; ((struct Obj10257 *)p)->f14 = c; }


int func_021B93E4(u8 *p) { if(((struct Obj05282 *)p)->f8 && !func_0201C6C4(((struct Obj05282 *)p)->f20,((struct Obj05282 *)p)->f0)){func_020257D0(((struct Obj05282 *)p)->f1C);((struct Obj05282 *)p)->f8=0;} if(!((struct Obj05282 *)p)->f8)return 1; return 0; }
