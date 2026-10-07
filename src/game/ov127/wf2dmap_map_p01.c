/*
 * file:     wf2dmap_map_p01.c
 * unit:     yes
 * function: func_021C4790, func_021C47A0, func_021C47E4, func_021C47F8, func_021C47FC, func_021C4800, func_021C4818, func_021C4844, func_021C4864, func_021C4880, func_021C48C0, func_021C48D4, func_021C48E8, func_021C4914, func_021C4918
 * address:  0x021C4790
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   d_021C6110 0x021C6110 data a1
 *   func_020307B0 0x020307B0 arm
 *   func_02082D44 0x02082D44 arm
 *   d_021C600C 0x021C600C data a4
 *   d_021C6120 0x021C6120 data a1
 *   func_021C4954  0x021C4954  thumb
 *   func_021C4C88  0x021C4C88  thumb
 *   func_021C4980 0x021C4980 thumb ov127
 *   func_021C4CB4 0x021C4CB4 thumb ov127
 *   func_021C4A98 0x021C4A98 thumb ov127
 *   func_02082BCC 0x02082BCC arm
 */
#include "../../matched/include/Obj23032.h"
#include "../../matched/include/Obj23033.h"
#include "../../matched/include/Obj10469.h"
#include "../../matched/include/Obj08123.h"
#include "../../matched/include/Obj23036.h"
#include "../../matched/include/Obj23038.h"
#include "../../matched/include/Obj03278.h"

typedef unsigned char u8;

typedef signed char s8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

typedef signed int s32;

typedef struct {u16 width,height;void *entries;} Grid;

typedef union { u32 raw; struct { u32 flag:1; u32 value:31; } bits; } Cell;

typedef struct { void *entries; u32 count; } Container;

extern void *func_02030734(u16,u32,int,const char *,u16);
extern u32 func_020307B0(void *p);
extern void func_02082D44(void *,const void *,u32);
extern char *func_021C4954(unsigned *p, unsigned id);
extern void func_021C4C88(char *p, char *q);
extern char *func_021C4980(char **p, int i);
extern void func_021C4CB4(u8 *p);
extern u8 *func_021C4A98(void *);
extern void func_02082BCC(void *,int,int);
int func_021C4790(char *p);
Grid *func_021C47A0(u32 w,u32 h,u32 heap);
void func_021C47E4(u8 *p);
u16 func_021C47F8(u16 *p);
u16 func_021C47FC(u16 *p);
void func_021C4800(u8 *p,void *out);
Cell func_021C4818(u8 *p, u32 x, u32 y);
int func_021C4844(u8 *p, u16 x, u16 y);
u32 func_021C4864(u8 *p, u16 x, u16 y);
Container *func_021C4880(u32 count, u32 heap);
void func_021C48C0(u8 *p);
void func_021C48D4(void *a, u8 *q);
void func_021C48E8(u8 *p);
u32 func_021C4914(u8 *p);
void func_021C4918(void *a,u16 *s);
void func_021C4948(void *p);
extern const char d_021C6110[];
extern Cell d_021C600C;
extern const char d_021C6120[];


int func_021C4790(char *p)
{
    return ((struct Obj23032 *)p)->f4 == 0;
}

Grid *func_021C47A0(u32 w,u32 h,u32 heap) { Grid *p;p=func_02030734(heap,8,1,d_021C6110,76);p->width=w;p->height=h;p->entries=func_02030734(heap,p->width*p->height*4,1,d_021C6110,83);return p; }

/*
 * Extent remainder: 2-byte zero padding, filed getters 021C47F8/47FC,
 * and separately filed follower ov127_func_021C4800.c.
 */
void func_021C47E4(u8 *p) { func_020307B0(((struct Obj23033 *)p)->f4);func_020307B0(p); }


/*
 * Leaf: ldrh r0,[r0]; bx lr.  Blocker of ov099 func_021BA0F8.
 */
u16 func_021C47F8(u16 *p)
{
    return p[0];
}


u16 func_021C47FC(u16 *p)
{
    return p[1];
}

/*
 * Follower of 021C47E4, separate because 021C47F8/47FC already have shards.
 */
void func_021C4800(u8 *p,void *out) { func_02082D44(out,((struct Obj10469 *)p)->f4,((struct Obj10469 *)p)->f0 * ((struct Obj10469 *)p)->f2 * 4); }

Cell func_021C4818(u8 *p, u32 x, u32 y)
{
 Cell r = d_021C600C;
 if (((struct Obj08123 *)p)->f0 > x && ((struct Obj08123 *)p)->f2 > y) r=*(Cell *)(((struct Obj08123 *)p)->f4 + (x + ((struct Obj08123 *)p)->f0*y)*4);
 return r;
}

/*
 * Extent remainder: 2-byte zero alignment padding.
 */
int func_021C4844(u8 *p, u16 x, u16 y) { Cell r=func_021C4818(p,x,y); if(r.raw==(u32)-1) return 1; return r.bits.flag; }

u32 func_021C4864(u8 *p, u16 x, u16 y) { Cell r=func_021C4818(p,x,y); if(r.raw==(u32)-1) return 0; return r.bits.value; }

Container *func_021C4880(u32 count, u32 heap)
{
    Container *p;
    p = func_02030734(heap, 8, 1, d_021C6120, 128);
    p->count = count;
    p->entries = func_02030734(heap, 24 * p->count, 1, d_021C6120, 133);
    return p;
}


/*
 * Addresses are Black-image addresses.
 */
void func_021C48C0(u8 *p)
{
    func_020307B0(((struct Obj23036 *)p)->f0);
    func_020307B0(p);
}


void func_021C48D4(void *a, u8 *q)
{
    func_021C4C88(func_021C4954(a, q[7]), (char *)q);
}

void func_021C48E8(u8 *p) { u32 i,n; char *q; n=func_021C4914(p);for(i=0;i<n;i++){q=func_021C4980((char **)p,(u16)i);if(q)func_021C4CB4((u8 *)q);} }

u32 func_021C4914(u8 *p) { return ((struct Obj23038 *)p)->f4; }

void func_021C4918(void *a,u16 *s) { u8 *p; s16 x,y;p=func_021C4A98(a);x=(s16)s[0];y=(s16)s[1];((struct Obj03278 *)p)->f4=x;((struct Obj03278 *)p)->f6=y;((struct Obj03278 *)p)->f8=x;((struct Obj03278 *)p)->fA=y;((struct Obj03278 *)p)->fC=s[2];p[21]=s[3];p[20]=s[4];((struct Obj03278 *)p)->fE=s[5];((struct Obj03278 *)p)->f0=1; }

void func_021C4948(void *p) { func_02082BCC(p,0,24); }
