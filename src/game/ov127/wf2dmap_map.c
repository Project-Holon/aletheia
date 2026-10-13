/*
 * file:     wf2dmap_map.c
 * unit:     yes
 * function: func_021C4790, func_021C47A0, func_021C47E4, func_021C47F8, func_021C47FC, func_021C4800, func_021C4818, func_021C4844, func_021C4864, func_021C4880, func_021C48C0, func_021C48D4, func_021C48E8, func_021C4914, func_021C4918, func_021C4954, func_021C4980, func_021C4994, func_021C499C, func_021C49A4, func_021C4A00, func_021C4A54, func_021C4A8C, func_021C4A98, func_021C4AC4, func_021C4AD0, func_021C4ADC, func_021C4B7C, func_021C4B90, func_021C4BA4, func_021C4C88
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
 *   func_021C4CB4 0x021C4CB4 thumb ov127
 *   MI_CpuFill8 0x02082BCC arm
 *   d_021C6014 0x021C6014 data a4
 *   d_021C6010  0x021C6010  data  a1
 *   d_021C601C 0x021C601C data a4
 */
#include "../../matched/include/Obj23032.h"
#include "../../matched/include/Obj23033.h"
#include "../../matched/include/Obj10469.h"
#include "../../matched/include/Obj08123.h"
#include "../../matched/include/Obj23036.h"
#include "../../matched/include/Obj23038.h"
#include "../../matched/include/Obj03278.h"
#include "../../matched/include/Obj14029.h"
#include "../../matched/include/Obj23040.h"
#include "../../matched/include/Obj00535.h"
#include "../../matched/include/Obj23041.h"
#include "../../matched/include/Obj23042.h"

typedef unsigned char u8;

typedef signed char s8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

typedef signed int s32;

typedef struct {u16 width,height;void *entries;} Grid;

typedef union { u32 raw; struct { u32 flag:1; u32 value:31; } bits; } Cell;

typedef struct { void *entries; u32 count; } Container;

typedef struct { short a, b; } Pos;

struct delta { signed char a,b; };

struct pair_021C4B7C {
    u16 a;
    u16 b;
};

struct pair_021C4B90 {
    u16 a;
    u16 b;
};

struct pair_021C4C88 {u16 a,b;};

extern void *func_02030734(u16,u32,int,const char *,u16);
extern u32 func_020307B0(void *p);
extern void func_02082D44(void *,const void *,u32);
extern void func_021C4CB4(u8 *p);
extern void MI_CpuFill8(void *,int,int);
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
char *func_021C4954(unsigned *p, unsigned id);
char *func_021C4980(char **p, int i);
char *func_021C4994(unsigned *p,unsigned id);
char *func_021C499C(char **p,int i);
int func_021C49A4(u8 *p, unsigned int i);
void func_021C4A00(void *p, int i, int v);
Pos func_021C4A54(Pos p,int i);
unsigned char func_021C4A8C(int i);
char *func_021C4A98(unsigned *p);
Pos func_021C4AC4(char *p);
Pos func_021C4AD0(char *p);
Pos func_021C4ADC(char *p);
void func_021C4B7C(char *p, struct pair_021C4B7C v);
void func_021C4B90(char *p, struct pair_021C4B90 v);
u8 *func_021C4BA4(u8 *p, void *list, int n);
void func_021C4C88(char *p,char *q);
extern const char d_021C6110[];
extern Cell d_021C600C;
extern const char d_021C6120[];
extern struct delta d_021C6014;
extern unsigned char d_021C6010[];







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






void func_021C4918(void *a,u16 *s) { u8 *p; s16 x,y;p=(u8 *)func_021C4A98((unsigned *)a);x=(s16)s[0];y=(s16)s[1];((struct Obj03278 *)p)->f4=x;((struct Obj03278 *)p)->f6=y;((struct Obj03278 *)p)->f8=x;((struct Obj03278 *)p)->fA=y;((struct Obj03278 *)p)->fC=s[2];p[21]=s[3];p[20]=s[4];((struct Obj03278 *)p)->fE=s[5];((struct Obj03278 *)p)->f0=1; }






void func_021C4948(void *p) { MI_CpuFill8(p,0,24); }






char *func_021C4954(unsigned *p, unsigned id)
{
 unsigned i=0;
 if (i<p[1]) { char *base=(char *)p[0]; char *e;
 do { e=base+i*24; if (((struct Obj14029 *)e)->f0==1 && id==((struct Obj14029 *)e)->fC) return e; i++; } while(i<p[1]); }
 return 0;
}







char *func_021C4980(char **p, int i)
{
    char *base = *p;
    char *e = base + i * 0x18;

    if (((struct Obj23040 *)e)->f0 != 1)
        return 0;
    return e;
}






char *func_021C4994(unsigned *p,unsigned id) { return func_021C4954(p,id); }






char *func_021C499C(char **p,int i) { return func_021C4980(p,i); }






/*
 * extent: two zero alignment bytes at 0x021C49FE follow the return.
 */
int func_021C49A4(u8 *p, unsigned int i)
{
    switch (i) {
    case 0: return *(s16 *)&((struct Obj00535 *)p)->f4;
    case 1: return *(s16 *)&((struct Obj00535 *)p)->f6;
    case 2: return *(s16 *)&((struct Obj00535 *)p)->f8;
    case 3: return *(s16 *)&((struct Obj00535 *)p)->fA;
    case 4: return ((struct Obj00535 *)p)->fC;
    case 5: return p[21];
    case 6: return p[20];
    case 7: return ((struct Obj00535 *)p)->fE;
    case 8: return ((struct Obj00535 *)p)->f10;
    case 9: return ((struct Obj00535 *)p)->f12;
    case 10: return ((struct Obj00535 *)p)->f16;
    default: return (int)p;
    }
}







void func_021C4A00(void *p, int i, int v)
{
    switch (i)
    {
    case 0:
        ((struct Obj00535 *)p)->f4 = (u16)v;
        break;
    case 1:
        ((struct Obj00535 *)p)->f6 = (u16)v;
        break;
    case 2:
        ((struct Obj00535 *)p)->f8 = (u16)v;
        break;
    case 3:
        ((struct Obj00535 *)p)->fA = (u16)v;
        break;
    case 4:
        ((struct Obj00535 *)p)->fC = (u16)v;
        break;
    case 5:
        ((struct Obj00535 *)p)->f15 = (u8)v;
        break;
    case 6:
        ((struct Obj00535 *)p)->f14 = (u8)v;
        break;
    case 7:
        ((struct Obj00535 *)p)->fE = (u16)v;
        break;
    case 8:
        ((struct Obj00535 *)p)->f10 = (u16)v;
        break;
    case 9:
        ((struct Obj00535 *)p)->f12 = (u16)v;
        break;
    case 10:
        ((struct Obj00535 *)p)->f16 = (u16)v;
        break;
    default:
        break;
    }
}






Pos func_021C4A54(Pos p,int i)
{
 Pos *v=&p;
 v->a += *(signed char *)((unsigned)&d_021C6014.a+i*2);
 v->b += *(signed char *)((unsigned)&d_021C6014.b+i*2);
 return p;
}







/*
 * Unlabelled Thumb leaf in a .word run:
 *   ldr r1,[pc,#4]; ldrb r0,[r1,r0]; bx lr; nop; .word 0x021C6010
 * Byte i of the table d_021C6010.
 */
unsigned char func_021C4A8C(int i)
{
    return d_021C6010[i];
}





char *func_021C4A98(unsigned *p)
{
 unsigned i=0;
 if (i<p[1]) { char *base=(char *)p[0];
 do { if (*(unsigned *)(base+i*24)==0) return base+i*24; i++; } while(i<p[1]); }
 return 0;
}





Pos func_021C4AC4(char *p) { return *(Pos *)(p+4); }



Pos func_021C4AD0(char *p) { return *(Pos *)(p+8); }


Pos func_021C4ADC(char *p)
{
    int n = func_021C49A4((u8 *)p, 8);
    int d = func_021C49A4((u8 *)p, 9);
    Pos a = func_021C4AC4(p);
    Pos b = func_021C4AD0(p);
    a.a -= b.a;
    a.b -= b.b;
    if (n > 0) {
        a.a = n * a.a / d;
        a.b = n * a.b / d;
    } else {
        a.a = 0;
        a.b = 0;
    }
    a.a += b.a;
    a.b += b.b;
    return a;
}



void func_021C4B7C(char *p, struct pair_021C4B7C v)
{
    ((struct Obj00535 *)p)->f4 = v.a;
    ((struct Obj00535 *)p)->f6 = v.b;
}



void func_021C4B90(char *p, struct pair_021C4B90 v)
{
    ((struct Obj00535 *)p)->f8 = v.a;
    ((struct Obj00535 *)p)->fA = v.b;
}


/*
 * extent: two zero alignment bytes at 0x021C4C86 follow the function.
 * lever: Pos declaration order src,a,dst,b fixes stack slots; named qid fixes cmp order.
 */
u8 *func_021C4BA4(u8 *p, void *list, int n)
{
    Pos src, a, dst, b;
    u32 count;
    int id;
    u32 i;
    u8 *q;
    int qid;
    src = func_021C4AC4((char *)p);
    dst = func_021C4A54(src, n);
    id = func_021C49A4(p, 4);
    count = func_021C4914(list);
    for (i = 0; i < count; i++) {
        q = (u8 *)func_021C499C((char **)list, (u16)i);
        if (q != 0) {
            qid = func_021C49A4(q, 4);
            if (qid == id) continue;
            a = func_021C4AC4((char *)q);
            if (a.a == dst.a && a.b == dst.b) return q;
            b = func_021C4AD0((char *)q);
            if (b.a == dst.a && b.b == dst.b) return q;
        }
    }
    return 0;
}


extern void (*d_021C601C)(char *,struct pair_021C4C88,unsigned);


void func_021C4C88(char *p,char *q)
{
 (*(void (**)(char *,struct pair_021C4C88,unsigned))((unsigned)&d_021C601C+*(u16 *)(q+4)*4))(p,*(struct pair_021C4C88 *)q,((struct Obj23042 *)q)->f6);
 ((struct Obj23041 *)p)->f16=0;
}
