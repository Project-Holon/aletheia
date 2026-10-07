/*
 * file:     unit_021B7560_p13.c
 * unit:     yes
 * function: func_021B8D9C, func_021B8DE4, func_021B8F00, func_021B8FA0, func_021B9060, func_021B9110, func_021B9174, func_021B9184, func_021B91A8, func_021B91B4
 * address:  0x021B8D9C
 * region:   ov103
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02035CB8 0x02035CB8 arm
 *   func_021B8BC0 0x021B8BC0 thumb ov103
 *   _u32_div_f 0x0209C2B0 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02041300 0x02041300 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02049238 0x02049238 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021B793C 0x021B793C thumb ov103
 *   func_0204B6F4 0x0204B6F4 arm
 */
#include "../../matched/include/Obj07985.h"
#include "../../matched/include/Obj13740.h"
#include "../../matched/include/Obj03741.h"

struct Pt;
struct Obj;
typedef unsigned int u32;

typedef unsigned char u8;

typedef struct {int x,y;} Pair;

typedef struct {Pair point[12];} Line;

typedef struct {Pair origin,end;Line a,b;} Record;

typedef struct {Pair origin,end;Line a,b;u32 tail[2];} Block;

typedef unsigned short u16;

struct Pt { int x, y; };

typedef short s16;

typedef signed char s8;

typedef int s32;

extern u32 func_02035CB8(u32 *outA, u32 *outB);
extern void func_021B8BC0(u8 *,Block *);
extern void *func_0204A380(void *a0, u32 a1, u32 a2, u32 a3);
extern int func_02062B30(void *file, void **out);
extern u8 func_0204169C(int channel);
extern u32 func_0204162C(int channel);
extern void func_020410D0(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u8 a6, u8 a7, u8 a8, u8 a9);
extern void func_020413B0(u8,u8,u8,u8,u8,u8);
extern void func_020409B4(u8);
extern u32 func_020307B0(void *p);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_02041300(u8,u8,u8,u8,u8,u8,u8);
extern void func_02041B6C(u32 bit);
extern void func_02049238(void *);
extern void func_02082BCC(void *,int,int);
extern int func_021B793C(u8 *p, int i);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
int func_021B8D9C(u32 *p,u32 *out);
u8 func_021B8DE4(u8 *p);
u8 func_021B8F00(struct Pt *pa, struct Pt *a, struct Pt *pb, struct Pt *b);
void func_021B8FA0(int a,int b,int c,int d,u8 e,u8 f,u8 g,u8 h,u8 i,u8 j,u8 k,u8 l,u8 m,int n,u16 o);
void func_021B9060(int a,u16 b);
void func_021B9110(u8 *p,void *q,int a,int b,int c,u8 d);
void func_021B9174(void *p);
void func_021B9184(u8 *p, struct Obj *q, int v, u8 w);
void func_021B91A8(void *p);
int func_021B91B4(u8 *p,u32 *rect);

int func_021B8D9C(u32 *p,u32 *out) {
 u32 x,y;
 if(func_02035CB8(&x,&y)) {
  if(x-p[0]<p[2]-p[0] && y-p[1]<p[3]-p[1]) {
   if(out) {out[0]=x;out[1]=y;}
   return 1;
  }
 }
 return 0;
}

u8 func_021B8DE4(u8 *p)
{
    Block ref;
    Block cur;
    Pair rp,cp;
    u32 dx,dy,dist;
    u32 score;
    u32 first,second,part1,part2;
    Line *tmp;
    ref.origin=*(Pair *)(p+0xa3c);
    tmp=(Line *)(p+0xa4c);
    ref.end=*(Pair *)(p+0xa44);
    ref.a=*tmp;
    ref.b=*(Line *)(p+0xaac);
    func_021B8BC0(p+0x75c,&cur);
    rp=ref.origin;
    cp=cur.origin;
    dy=(u32)rp.y;
    dy=dy-(u32)cp.y;
    dx=(u32)rp.x-(u32)cp.x;
    dist=dx*dx+dy*dy;
    if(dist>0 && dist<=64)score=100;
    else if(dist>64 && dist<=256)score=80;
    else if(dist>256 && dist<=576)score=50;
    else if(dist>576 && dist<=1024)score=30;
    else if(dist>1024 && dist<=1600)score=10;
    else score=0;
    first=func_021B8F00((struct Pt *)ref.a.point,(struct Pt *)ref.a.point,(struct Pt *)cur.a.point,(struct Pt *)cur.a.point);
    second=func_021B8F00((struct Pt *)ref.b.point,(struct Pt *)ref.b.point,(struct Pt *)cur.b.point,(struct Pt *)cur.b.point);
    return (score*40u)/100u+(first*40u)/100u+(second*20u)/100u;
}

u8 func_021B8F00(struct Pt *pa, struct Pt *a, struct Pt *pb, struct Pt *b)
{
    int i;
    u32 sum;
    sum = 0;
    for (i = 1; i < 10; i++) {
        int dy1, dx1, dy2, dx2;
        u32 d1, d2;
        u16 d;
        dx1 = a[i].x - pa->x;
        dy1 = a[i].y - pa->y;
        dx2 = b[i].x - pb->x;
        dy2 = b[i].y - pb->y;
        if (dy1 < 0) dy1 = -dy1;
        if (dx1 < 0) dx1 = -dx1;
        d1 = dx1 + dy1;
        if (dy2 < 0) dy2 = -dy2;
        if (dx2 < 0) dx2 = -dx2;
        d2 = dx2 + dy2;
        if (d1 > d2) d = d1 - d2; else d = d2 - d1;
        if (d == 0)
            sum += 100;
        else if (d == 1)
            sum += 80;
        else if (d == 2)
            sum += 50;
        else if (d >= 3 && d <= 5)
            sum += 30;
    }
    return (u8)(sum / 9);
}

void func_021B8FA0(int a,int b,int c,int d,u8 e,u8 f,u8 g,u8 h,u8 i,u8 j,u8 k,u8 l,u8 m,int n,u16 o) {
 void *handle;
 int t;
 u8 *data;
 u16 *p;
 int count;
 handle=func_0204A380((void *)a,b,n,(u16)((o&0x7fff)|0x8000));
 func_02062B30(handle,(void **)(&data));
 if(d && !func_0204169C((u8)c)) {
  count=h*g;
  p=(u16 *)(data+12);
  for(t=0;t<(g*h);t++)p[t]+=(u16)d;
 }
 if(func_0204162C((u8)c)) {
  func_020410D0((u8)c,i,j,k,l,(u32)(data+12),e,f,g,h);
  func_020413B0(c,i,j,k,l,m);
  func_020409B4(c);
 }
 func_020307B0(handle);
}

void func_021B9060(int a,u16 b) {
 void *p = func_020490F4(94,b);
 if(a&1)func_021B8FA0((int)p,7,2,0,0,0,16,24,0,0,16,24,9,0,b);
 else func_02041300(2,0,0,0,16,24,9);
 if(a&2)func_021B8FA0((int)p,8,2,0,0,0,16,24,16,0,16,24,9,0,b);
 else func_02041300(2,0,16,0,16,24,9);
 func_02041B6C(2);func_02049238(p);
}

void func_021B9110(u8 *p,void *q,int a,int b,int c,u8 d) {
 int i;
 func_02082BCC(p,0,0x590);
 ((struct Obj07985 *)p)->f580=a;((struct Obj07985 *)p)->f584=b;
 ((struct Obj07985 *)p)->f588=0;((struct Obj07985 *)p)->f58C=10;
 for(i=0;i<32;i++)func_021B9184(p+i*0x2c,(struct Obj *)func_021B793C(q,c+i),b,d);
}

void func_021B9174(void *p) { func_02082BCC(p,0,0x590); }

void func_021B9184(u8 *p, struct Obj *q, int v, u8 w) { func_02082BCC(p,0,0x2c); *(struct Obj * *)&((struct Obj13740 *)p)->f0=q; ((struct Obj13740 *)p)->f4=w; func_0204B6F4(q,(u8)v,1); }

void func_021B91A8(void *p) { func_02082BCC(p, 0, 0x60); }

/*
 * volatile: 021B91E6 and 021B91EC reread the halfword at offset 0x50.
 */
int func_021B91B4(u8 *p,u32 *rect) {
 u16 n;
 if(((struct Obj03741 *)p)->f5C)return 1;
 if((((struct Obj03741 *)p)->f54)++>150) {
  func_021B8D9C(rect,(u32 *)(p+0x48));
  ((struct Obj03741 *)p)->f5C=1;
  return 1;
 }
 if(((struct Obj03741 *)p)->f58==0) {
  n=*(volatile u16 *)&((struct Obj03741 *)p)->f50;
  (*(volatile u16 *)&((struct Obj03741 *)p)->f50)++;
  func_021B8D9C(rect,(u32 *)(p+n*8));
 }
 if((((struct Obj03741 *)p)->f58)++>15)((struct Obj03741 *)p)->f58=0;
 return 0;
}
