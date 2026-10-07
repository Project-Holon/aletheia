/*
 * file:     unit_021C6180_p11.c
 * unit:     yes
 * function: func_021C899C, func_021C89C4, func_021C8A50
 * address:  0x021C899C
 * region:   ov128
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C8904 0x021C8904 thumb ov128
 *   func_021CA4B4 0x021CA4B4 thumb ov128
 *   func_020456F8 0x020456F8 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02041300 0x02041300 arm
 *   func_021C41BC 0x021C41BC thumb ov127
 *   func_0204B3B4 0x0204B3B4 arm
 */
#include "../../matched/include/Obj05381.h"
#include "../../matched/include/Obj03282.h"
#include "../../matched/include/Obj05380.h"

struct Descriptor;
struct Obj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short s16;

extern void func_021C8904(char *,char *,void *,void *,int,char *,int,u16);
extern void func_021CA4B4(char *);
extern void func_020456F8(struct Descriptor *d);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32 bit);
extern void func_02041300(u32,int,u8,u8,u8,u8,u8);
extern void func_021C41BC(u8 *p);
extern void func_0204B3B4(struct Obj *p);
void func_021C899C(char *p,char *q,void *r,void *s,int t,char *table,int page,u16 heap);
void func_021C89C4(char *p, void *q, void *a2);
void func_021C8A50(char *p,int unused);

void func_021C899C(char *p,char *q,void *r,void *s,int t,char *table,int page,u16 heap) {func_021C8904(p,q,r,s,t,table,page,heap);func_021CA4B4(**(char ** *)&((struct Obj05381 *)p)->f8);}

static inline int ab(int v) {return v<0?-v:v;}

/*
 * extent: trailing two-byte zero padding at 0x021C8A4E; next label 0x021C8A50.
 */
void func_021C89C4(char *p, void *q, void *a2) {
 void *v;
 func_021C8A50(p,(int)q);
 v=**(void ** *)&((struct Obj03282 *)p)->f8;func_020456F8(v);func_02041B6C(func_02045730(v));
 func_02041300(2,0,ab(((struct Obj03282 *)p)->f0),ab(((struct Obj03282 *)p)->f2),p[4],p[5],0);
 func_02041B6C(2);
 func_02041300(3,0,ab(((struct Obj03282 *)p)->f0),ab(((struct Obj03282 *)p)->f2),p[4],p[5],0);
 func_02041B6C(3);
}

void func_021C8A50(char *p,int unused) {int i;char *q;for(i=0;i<8;i++) {q=p+i*4;if(((struct Obj05380 *)q)->fC){func_021C41BC(((struct Obj05380 *)q)->fC);*(u32 *)&((struct Obj05380 *)q)->fC=0;} if(((struct Obj05380 *)q)->f2C){func_0204B3B4(((struct Obj05380 *)q)->f2C);*(u32 *)&((struct Obj05380 *)q)->f2C=0;}}}
