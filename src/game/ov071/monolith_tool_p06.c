/*
 * file:     monolith_tool_p06.c
 * unit:     yes
 * function: func_021B7234, func_021B730C, func_021B739C, func_021B7824, func_021B7880, func_021B78D4, func_021B78F4, func_021B7924, func_021B7994
 * address:  0x021B7234
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B6F40  0x021B6F40  thumb  ov071
 *   func_02030734  0x02030734  arm
 *   func_02041090  0x02041090  arm
 *   func_020307B0  0x020307B0  arm
 *   d_021BABE4     0x021BABE4  data  a1
 *   func_0203159C  0x0203159C  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_021B7A68  0x021B7A68  thumb  ov071
 *   func_021B7B10  0x021B7B10  thumb  ov071
 *   func_021B7BD8  0x021B7BD8  thumb  ov071
 *   func_021B7014  0x021B7014  thumb  ov071
 *   func_02040588  0x02040588  arm
 *   func_02043598  0x02043598  arm
 *   d_021BA8A0     0x021BA8A0  data  a4
 *   func_02012138 0x02012138 thumb
 *   func_02158344 0x02158344 thumb ov010
 *   func_020120F4 0x020120F4 thumb
 *   func_02158590 0x02158590 thumb ov010
 *   func_021B7AC4 0x021B7AC4 thumb ov071
 *   func_021B7AE8 0x021B7AE8 thumb ov071
 *   func_021B7BB4 0x021B7BB4 thumb ov071
 *   func_021B7BF0 0x021B7BF0 thumb ov071
 *   func_021B7BFC 0x021B7BFC thumb ov071
 *   func_021B79A0 0x021B79A0 thumb ov071
 *   func_021B7A08 0x021B7A08 thumb ov071
 *   func_021B7A14 0x021B7A14 thumb ov071
 *   func_02035C60 0x02035C60 arm
 *   func_020362DC 0x020362DC arm
 *   func_02035C08 0x02035C08 arm
 *   func_020355D8 0x020355D8 arm
 *   func_020355D8x 0x020355D8 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_02175B14 0x02175B14 thumb ov011
 *   func_02175B4C 0x02175B4C thumb ov011
 *   func_021761EC 0x021761EC thumb ov011
 *   func_02173E2C 0x02173E2C thumb ov011
 *   func_021B6B98 0x021B6B98 thumb ov071
 *   func_021B6BEC 0x021B6BEC thumb ov071
 *   func_021B6C74 0x021B6C74 thumb ov071
 *   func_021B7108 0x021B7108 thumb ov071
 *   func_021B7114 0x021B7114 thumb ov071
 *   d_021BA87C 0x021BA87C data a4
 *   d_021BA85C 0x021BA85C data a1
 *   d_021BA862 0x021BA862 data a1
 *   d_021BAA4C 0x021BAA4C data a4
 *   func_0201C6B4  0x0201C6B4  thumb
 *   func_020435F4  0x020435F4  arm
 *   func_0201CE48  0x0201CE48  thumb
 *   func_02045808  0x02045808  arm
 *   func_021B7068  0x021B7068  thumb  ov071
 *   func_021B7BE4  0x021B7BE4  thumb  ov071
 *   func_021B7B9C  0x021B7B9C  thumb  ov071
 *   func_021B7AAC  0x021B7AAC  thumb  ov071
 *   func_020315D4  0x020315D4  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_02041300  0x02041300  arm
 *   d_021BA8DC     0x021BA8DC  data  a4
 *   d_021BA8FC     0x021BA8FC  data  a4
 *   func_020403F4 0x020403F4 arm
 *   func_020498F4 0x020498F4 arm
 *   func_020409B4 0x020409B4 arm
 *   func_0201F554  0x0201F554  thumb
 *   func_0201F548  0x0201F548  thumb
 *   func_020215EC  0x020215EC  thumb
 *   func_020450F0  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045374  0x02045374  arm
 *   func_0201F73C  0x0201F73C  thumb
 *   func_020452E8  0x020452E8  arm
 */
#include "../../matched/include/Obj13174.h"
#include "../../matched/include/Obj06184.h"
#include "../../matched/include/Obj20691.h"
#include "../../matched/include/Obj20692.h"
#include "../../matched/include/Obj20695.h"

struct Obj0203159C;
struct Ctx;
struct PrintSys;
struct Rec3;
struct S020315D4;
struct U16Vec;
struct BgTemplate;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct PalAnmSlot;
typedef unsigned char u8;

typedef unsigned short u16;

typedef struct {
    u8 pad[0xc];
    u16 n;
    u16 m;
} Counts;

typedef unsigned int   u32;

typedef struct {u32 a[6];} Record;

typedef struct {void **f0;u8 *f4;u8 *f8;u8 padc[0x20];u8 f2c,f2d,f2e;} C;

typedef struct {u8 pad0[0x4c];Record rec;u16 text[10];u8 f78;u8 pad79[7];u8 f80,f81,f82,f83;} D;

extern void *func_021B6F40(u8 **p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02041090(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5);
extern u32 func_020307B0(void *p);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *p, int v, int n);
extern void func_021B7A68(void *a, void *b);
extern void func_021B7B10(int *a, char *b);
extern void func_021B7BD8(void *p, int a);
extern int func_021B7014(int *, const int *, int);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02043598(u32 mask, u32 enable);
extern u32 func_02012138(const struct Ctx *p);
extern int func_02158344(int a0);
extern void *func_020120F4(const struct Ctx *p);
extern int func_02158590(void *);
extern void func_021B7AC4(void **p, void *q);
extern void func_021B7AE8(void **p, int i);
extern void func_021B7BB4(int *a, char *p);
extern void func_021B7BF0(void *);
extern void func_021B7BFC(int *a, char *p, unsigned char m);
extern void func_021B79A0(void **p, int *c, int idx);
extern int func_021B7A08(char *p, char *q);
extern void func_021B7A14(void **p);
extern int func_02035C60(void);
extern u32 func_020362DC(void);
extern int func_02035C08(const void *);
extern void func_020355D8(int);
extern void func_020355D8x(int);
extern void func_020061E4(u32);
extern int func_02175B14(u8 *);
extern void func_02175B4C(u8 *,u8 *);
extern u8 func_021761EC(char *p);
extern int func_02173E2C(char *a, int b);
extern void func_021B6B98(void *p, int *tbl, int n, int sel, int c);
extern void func_021B6BEC(void *p, int *tbl, int n, int sel, int c);
extern u8 func_021B6C74(void *,int);
extern void func_021B7108(void *);
extern int func_021B7114(void *);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern void func_020435F4(u32 a);
extern void func_0201CE48(struct Rec3 *p);
extern void func_02045808(struct U16Vec *vec);
extern void func_021B7068(void *a);
extern void func_021B7BE4(void *a);
extern void func_021B7B9C(char *p);
extern void func_021B7AAC(void **p);
extern void func_020315D4(struct S020315D4 *p);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02041300(u32 layer, u32 tile, u32 x, u32 y, u32 w, u32 h, u32 mode);
extern void func_020403F4(u32 i);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020409B4(unsigned);
extern void func_0201F554(u32 a, u32 b, u32 c, u32 d);
extern u8 func_0201F548(int i);
extern void func_020215EC(struct PalAnmSlot *slots, u32 arcId, u32 fileId, u32 tag, u32 idx, u32 count, u16 off, u16 srcOff);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045374(struct Cfg *cfg);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
void func_021B7234(void *a, int flag, int bg);
int func_021B730C(void *ctx, int *st, int *w);
int func_021B739C(int a,int *state,C *c,D *d);
int func_021B7824(void *a, void *b, char *c, char *d);
void func_021B7880(void);
void func_021B78D4(void);
void func_021B78F4(void *p, void **q);
void func_021B7924(void **p, void **q);
void func_021B7994(void *p);
extern const char d_021BABE4[];
extern const char d_021BA8A0[];
extern const u32 d_021BA87C[];
extern const u8 d_021BA85C[],d_021BA862[][4];
extern const u32 d_021BAA4C[];
extern char d_021BA8DC[];
extern char d_021BA8FC[];


void func_021B7234(void *a, int flag, int bg)
{
    Counts *c;
    u16 *buf;
    int y;
    int n, m;
    int left, right;
    int i;

    c = func_021B6F40(a);
    y = 0x14;
    if (flag) {
        y = 0xe;
    }
    n = c->n;
    m = c->m;
    if (n == m) {
        left = 0x78;
        right = 0x78;
    } else {
        left = n * 0xf0 / (n + m);
        if (m > 0) {
            right = 0xf0 - left;
        } else {
            right = 0;
            left = 0xf0;
        }
    }
    if (n > 0 && left == 0) {
        right--;
    } else if (m > 0 && right == 0) {
        right++;
    }
    buf = func_02030734(0x61, 0x3c, 1, d_021BABE4, 0x474);
    for (i = 0; right > 0; i++) {
        if (right >= 8) {
            buf[i] = 1;
            right -= 8;
        } else {
            buf[i] = 9 - right;
            right = 0;
        }
    }
    for (; i < 30; i++) {
        buf[i] = 9;
    }
    for (i = 0; i < 30; i++) {
        buf[i] |= 0x1000;
    }
    func_02041090((u8)bg, (u32)buf, (u8)1, (u8)y, 30, 1);
    func_020307B0(buf);
}


int func_021B730C(void *ctx, int *st, int *w)
{
    u8 *m;

    switch (st[0]) {
    case 0:
        m = func_0203159C(ctx, 0x84, 0x61);
        func_02082BCC(m, 0, 0x84);
        m[0x82] = 0;
        func_021B7880();
        func_021B78F4(w, (void *)w[1]);
        func_021B7924((void **)m, (void *)w[1]);
        func_021B7A68(m, w);
        func_021B7B10(w, (char *)m);
        func_021B7BD8(w, (int)m);
        ((struct Obj13174 *)m)->f7C = func_021B7014((int *)w[1], (const int *)(d_021BA8A0 + *(u8 *)w[2] * 8), 1);
        st[0]++;
        break;
    case 1:
        func_02040588(6, 1);
        func_02043598(0x10, 1);
        return 1;
    }
    return 0;
}

#pragma opt_lifetimes off

#pragma opt_common_subs off

int func_021B739C(int a,int *state,C *c,D *d)
{
 u16 *dst;
 u16 *src;
 u8 *r;
 int keys,res,t;
 u32 i;
 u8 next;
 const u8 *row;
 r=(u8 *)func_02158344(func_02012138(*c->f0));
 func_021B7AC4((void **)d,c); func_021B7AE8((void **)d,*c->f8);func_021B7BB4((int *)c,(char *)d);func_021B7BF0(d);
 if(c->f2e==1 && *state==3) return 1;
 switch(*state) {
 case 0:
  if(r!=0 && func_02175B14(r+0x1ac)==1) func_021B7BFC((int *)c,(char *)d,1);
  *state=1;break;
 case 1:
  if(func_02158590(func_020120F4(*c->f0))==0) func_021B79A0((void **)d,(int *)c->f4,0x16);
  else func_021B79A0((void **)d,(int *)c->f4,0x12);
  ++*state;break;
 case 2:
  if(func_021B7A08((char *)c->f4,(char *)d)!=1) break;
  if(func_02035C60()==0 && (func_020362DC()&3)==0) break;
  func_021B7A14((void **)d);func_020061E4(0x547);
  if(func_02035C60()!=0) {d->f83=1;func_021B6B98(c,(int *)((u8 *)d+0x2c),1,0xff,3);}
  else {d->f83=0;func_021B6B98(c,(int *)((u8 *)d+0x2c),1,0,3);}
  if(d->f82==0) *state=3;else *state=4;
  break;
 case 3:
  keys=func_020362DC();res=func_02035C08(d_021BA87C);
  if(r!=0 && func_02175B14(r+0x1ac)==1) {func_021B7BFC((int *)c,(char *)d,1);d->f80=1;*state=4;break;}
  if(keys>0 && d->f83==1) {d->f83=0;func_021B6B98(c,(int *)((u8 *)d+0x2c),1,0,3);func_020061E4(0x548);break;}
  if(keys&0xf0) {
   next=0xff;
   for(i=0;(i<6)?1:0;i++) if(d_021BA85C[i]==*c->f8) break;
   i=*c->f8;
   if(keys&0x40) {row=d_021BA862[i];next=row[0];}
   else if(keys&0x80) {row=d_021BA862[i];next=row[1];}
   else if(keys&0x20) {row=d_021BA862[i];next=row[2];}
   else if(keys&0x10) {row=d_021BA862[i];next=row[3];}
   if(next!=0xff) i=next;
   *c->f8=i;func_020061E4(0x548);
  }
  if(res>=0 && res<6) {*c->f8=res;d->f83=1;func_021B6B98(c,(int *)((u8 *)d+0x2c),1,0xff,3);func_020061E4(0x548);break;}
  if(res==6 || (keys&1)) {
   func_020355D8(res==6);
   if(func_02158590(func_020120F4(*c->f0))==0) {
    t=d_021BAA4C[*c->f8];
    if(t!=2 && t!=1) {*state=9;break;}
   }
   func_021B6BEC(c,(int *)((u8 *)d+0x2c),1,0,3);func_020061E4(0x736);*state=5;
  } else if(res==7 || (keys&2)) {
   func_021B7108((u8 *)d+0x24);func_020355D8(res==7);func_020061E4(0x551);*state=11;
  }
  break;
 case 4: {
  int keys4,res4;
  keys4=func_020362DC();res4=func_02035C08(d_021BA87C);
  if(res4==7 || (keys4&2)) {func_020355D8x(res4==7);func_020061E4(0x551);*state=11;}
  break;}

 case 5:
  d->rec=*(Record *)(c->f4+0x60+d_021BAA4C[*c->f8]*24);
  d->f78=((u8 *)c->f0)[0x15];
  dst=d->text;
  src=(u16 *)((u8 *)c->f0+0x18);
  for(i=10;i!=0;i--) {*dst=*src;dst++;src++;}
  if(r!=0 && func_02173E2C((char *)r,(int)(&d->rec))!=1) break;
  *state=6;break;
 case 6:
  if(r==0) {*state=3;break;}
  t=func_021761EC((char *)(r+0x1ac));
  if(t==1) {func_021B79A0((void **)d,(int *)c->f4,0x10);*state=7;}
  else if(t==2) {func_021B79A0((void **)d,(int *)c->f4,0x11);*state=8;}
  else if(t==3) {func_021B79A0((void **)d,(int *)c->f4,0x15);*state=8;}
  else if(t==4) {func_021B79A0((void **)d,(int *)c->f4,0x14);*state=8;}
  break;
 case 7:case 8:
  if(func_021B7A08((char *)c->f4,(char *)d)!=1) break;
  if(*state==7) {
  } else if(*state==8) {
   if(func_02035C60()==0 && !(func_020362DC()&3)) break;
  } else break;
  if(*state==7 && r!=0 && func_02175B14(r+0x1ac)==0) break;
  func_021B7A14((void **)d);func_020061E4(0x547);
  if(*state==7) {if(r!=0) func_02175B4C(r,r+0x1ac);d->f81=1;*state=11;}
  else *state=11;
  break;
 case 9:func_021B79A0((void **)d,(int *)c->f4,0x17);++*state;break;
 case 10:
  if(func_021B7A08((char *)c->f4,(char *)d)==1 && (func_02035C60()!=0 || (func_020362DC()&3)!=0)) {func_021B7A14((void **)d);*state=3;}
  break;
 case 11:
  if(func_021B6C74(c,3)==2) break;
  if(func_021B7114((u8 *)d+0x24)!=0) break;
  if(d->f81==1) c->f2c=4;else c->f2c=0;
  return 1;
 }
 return 0;
}

#pragma opt_lifetimes reset

#pragma opt_common_subs reset


int func_021B7824(void *a, void *b, char *c, char *d)
{
    if (func_0201C6B4(((struct Obj20692 *)(*(char * *)&((struct Obj20691 *)c)->f4))->f8) == 0)
        return 0;
    func_020435F4(8);
    if (((struct Obj06184 *)d)->f8 != 0)
        func_0201CE48(((struct Obj06184 *)d)->f8);
    if (((struct Obj06184 *)d)->f4 != 0)
        func_02045808(((struct Obj06184 *)d)->f4);
    func_021B7068(((struct Obj06184 *)d)->f7C);
    func_021B7BE4(d);
    func_021B7B9C(d);
    func_021B7AAC((void **)d);
    func_021B7994(d);
    func_021B78D4();
    func_020315D4(a);
    return 1;
}


void func_021B7880(void)
{
    func_0203FCA0(5, (const struct BgTemplate *)d_021BA8DC, 0);
    func_0203FCA0(6, (const struct BgTemplate *)d_021BA8FC, 0);
    func_02041300(5, 0, 0, 0, 0x20, 0x20, 0x11);
    func_02041300(6, 0, 0, 0, 0x20, 0x20, 0x11);
    func_02040588(5, 0);
}

void func_021B78D4(void) { func_02040588(5,0); func_02040588(6,0); func_020403F4(5); func_020403F4(6); }

void func_021B78F4(void *p, void **q) {func_020498F4(q[12],6,6,0,0,1,0x61);func_021B7234(p,1,6);func_020409B4(6);}


void func_021B7924(void **p, void **q)
{
    func_0201F554(5, 1, 0, 0x61);
    func_020215EC(q[0], 5, func_0201F548(0), 0x61, 1, 0x20, 0xb0, 0);
    p[0] = (void *)func_020450F0(5, 1, 0x13, 0x1e, 4, 0xd, 1);
    func_02043B5C(func_02045770(p[0]), 0xff);
    func_02045374(p[0]);
    func_0201F73C(p[0], 0, 1, 0xb);
}

void func_021B7994(void *p)
{
    u32 func_020452E8(struct Descriptor *d);
    func_020452E8(((struct Obj20695 *)p)->f0);
}
