/*
 * file:     irc_ranking_p11.c
 * unit:     yes
 * function: func_021B9360, func_021B9380, func_021B93D8, func_021B93DC, func_021B93E4
 * address:  0x021B9360
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
#include "../../matched/include/Obj10256.h"
#include "../../matched/include/Obj03746.h"
#include "../../matched/include/Obj22271.h"
#include "../../matched/include/Obj10257.h"
#include "../../matched/include/Obj05282.h"

struct Grid;
struct Obj020437AC;
struct U16Vec;
struct CharBuf;
struct MsgBank;
struct PrintSys;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef short s16;

typedef signed char s8;

typedef int s32;

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
void func_021B9360(u8 *p);
void func_021B9380(u8 *p,void *a,void *b,int c);
void func_021B93D8(u8 *p, u16 v);
void func_021B93DC(u8 *p, u32 a, u32 b, u32 c);
int func_021B93E4(u8 *p);

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
