/*
 * file:     script_command_p09.c
 * unit:     yes
 * function: func_021FC560, func_021FC570, func_021FC5A0, func_021FC5BC, func_021FC5D8, func_021FC5E8, func_021FC61C, func_021FC634, func_021FC644, func_021FC684, func_021FC694, func_021FC6EC, func_021FC7DC, func_021FC804, func_021FC81C, func_021FC848, func_021FCA38, func_021FCAA0
 * address:  0x021FC560
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021F94B0  0x021F94B0  thumb
 *   func_0201134C 0x0201134C thumb
 *   func_0201DD78 0x0201DD78 thumb
 *   func_021F9664  0x021F9664  thumb
 *   func_021F9680  0x021F9680  thumb
 *   func_021F9690  0x021F9690  thumb
 *   func_021F969C 0x021F969C thumb ov132
 *   func_021F96B0  0x021F96B0  thumb
 *   func_021F96C4  0x021F96C4  thumb
 *   func_02030734 0x02030734 arm
 *   d_021FDE5C 0x021FDE5C data a4
 *   func_02026400 0x02026400 thumb
 *   func_0203CBAC 0x0203CBAC arm
 *   func_02087C6C 0x02087C6C arm
 *   d_021FDE4C 0x021FDE4C data a4
 *   d_021FDDEC 0x021FDDEC data a4
 *   func_0203D1B4 0x0203D1B4 arm
 *   func_0203CEAC 0x0203CEAC arm
 *   func_0203A5E4 0x0203A5E4 arm
 *   func_0203D7BC 0x0203D7BC arm
 *   func_0200FB24 0x0200FB24 thumb
 *   func_0203D378 0x0203D378 arm
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3A8 0x0203D3A8 arm
 *   func_02012124 0x02012124 thumb
 *   func_021FCDEC 0x021FCDEC thumb ov132
 *   func_021FCE00 0x021FCE00 thumb ov132
 *   func_021FCAA8 0x021FCAA8 thumb ov132
 *   func_0203CDBC 0x0203CDBC arm
 *   func_020307B0 0x020307B0 arm
 *   func_0203A574 0x0203A574 arm
 *   d_021FDC38 0x021FDC38 data a4
 *   func_02012F44 0x02012F44 thumb
 *   func_020173EC 0x020173EC thumb
 *   func_020173E8 0x020173E8 thumb
 *   func_02008468 0x02008468 thumb
 *   func_02082BCC 0x02082BCC arm
 *   func_0200A81C 0x0200A81C thumb
 */
#include "../../matched/include/Obj23262.h"
#include "../../matched/include/Obj10564.h"
#include "../../matched/include/Obj14122.h"
#include "../../matched/include/Obj23263.h"
#include "../../matched/include/Obj14123.h"
#include "../../matched/include/Obj23264.h"
#include "../../matched/include/Obj23266.h"
#include "../../matched/include/Obj08172.h"
#include "../../matched/include/Obj23267.h"
#include "../../matched/include/Obj14124.h"
#include "../../matched/include/Obj23268.h"
#include "../../matched/include/Obj23270.h"
#include "../../matched/include/Obj05406.h"
#include "../../matched/include/Obj03291.h"
#include "../../matched/include/Obj06493.h"
#include "../../matched/include/Obj08173.h"
#include "../../matched/include/Obj14125.h"
#include "../../matched/include/Obj14126.h"
#include "../../matched/include/Obj02195.h"
#include "../../matched/include/Obj10565.h"
#include "../../matched/include/Obj23271.h"

#define W(q,k) (*(u32 *)((q)+(k)))
#define P(q,k) (*(u8 **)((q)+(k)))
struct Cursor;
struct Comm;
struct Ctx;
struct Req;
struct Entry;
struct Big;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

extern void func_021F94B0(u8 *p);
extern u32 func_0201134C(struct Cursor *);
extern void func_0201DD78(u32 r, u32 g, u32 b);
extern void func_021F9664(char *p, int a);
extern void func_021F9680(char *p, int a);
extern void func_021F9690(char *p);
extern int func_021F969C(char *p, u32 a, u32 b, u32 d);
extern void func_021F96B0(char *p, int a);
extern void func_021F96C4(char *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_020120F4(const struct Ctx *p);
extern void func_020263D8(struct Comm *p, u32 a1, u32 a2);
extern void func_02026400(struct Comm *);
extern u8 *func_02012944(void *p);
extern void func_0203CBAC(struct Req *req, u32 a2, u32 a3);
extern void func_02008494(void *, void *);
extern void func_02087C6C(void *);
extern int func_0203D1B4(void);
extern int func_0203CEAC(int);
extern void func_0203A5E4(u32);
extern void func_0203D7BC(u8 a0);
extern u32 func_0200FB24(void);
extern u32 func_0203D378(void);
extern struct Entry *func_020399A8(void);
extern int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
extern void func_02012124(struct Ctx *p, u32 v);
extern void func_021FCDEC(int,int);
extern int func_021FCE00(char *p, int id);
extern int func_0203CDBC(void);
extern u32 func_020307B0(void *p);
extern void func_021FCAA8(char *);
extern void func_0203A574(u32,u32,u32,u32);
extern void *func_02012F44(void *);
extern u32 func_020173EC(void);
extern u32 func_020173E8(void);
extern int func_02008468(void);
extern void func_02082BCC(void *,u8,u32);
extern u16 func_0200A81C(struct Big *p);
int func_021FC560(void *a, void **pp);
int func_021FC570(int unused,char *p);
int func_021FC5A0(int a, char **pp);
int func_021FC5BC(int a, char **pp);
int func_021FC5D8(int a, char **pp);
int func_021FC5E8(int unused,char *p);
int func_021FC61C(int a, char **pp);
int func_021FC634(int a, char **pp);
void func_021FC644(int a, void *b, void *c, int d);
void func_021FC684(char *p);
void *func_021FC694(int a,char *p);
int func_021FC6EC(int *state,u8 *p);
int func_021FC7DC(int unused,int unused1,void *p);
void func_021FC7F8(int unused,int unused1,char *p);
void func_021FC804(char *p);
void func_021FC81C(char *p);
void func_021FC848(u8 *p,void *a,void *b,int unused,void *d,u16 heap);
void func_021FCA38(char *p);
void func_021FCAA0(char *p);
extern const char d_021FDE5C[];
extern char d_021FDE4C[];
extern char d_021FDDEC[];
extern char d_021FDC38[];


/*
 * Addresses are Black-image addresses.
 */
int func_021FC560(void *a, void **pp)
{
    func_021F94B0(((struct Obj23262 *)((u8 *)*pp))->f34);
    return 0;
}

int func_021FC570(int unused,char *p) { u32 a,b,c; a=func_0201134C(*(struct Cursor * *)&((struct Obj10564 *)p)->f4); b=func_0201134C(*(struct Cursor * *)&((struct Obj10564 *)p)->f4); c=func_0201134C(*(struct Cursor * *)&((struct Obj10564 *)p)->f4); func_0201DD78((u8)a,(u8)b,(u8)c); return 0; }


int func_021FC5A0(int a, char **pp)
{
    char *p = *pp;
    int x = func_0201134C((struct Cursor *)(((struct Obj14122 *)pp)->f4));

    func_021F9664(((struct Obj23263 *)p)->f34, (unsigned short)x);
    return 0;
}


int func_021FC5BC(int a, char **pp)
{
    char *p = *pp;
    int x = func_0201134C((struct Cursor *)(((struct Obj14123 *)pp)->f4));

    func_021F9680(((struct Obj23264 *)p)->f34, (unsigned short)x);
    return 0;
}


int func_021FC5D8(int a, char **pp)
{
    func_021F9690(((struct Obj23266 *)(*pp))->f34);
    return 0;
}

int func_021FC5E8(int unused,char *p) { char *o; u32 a,b,c; o=*(char * *)&((struct Obj08172 *)p)->f0; a=func_0201134C(*(struct Cursor * *)&((struct Obj08172 *)p)->f4); b=func_0201134C(*(struct Cursor * *)&((struct Obj08172 *)p)->f4); c=func_0201134C(*(struct Cursor * *)&((struct Obj08172 *)p)->f4); func_021F969C(*(char * *)&((struct Obj23267 *)o)->f34,(u16)a,(u16)b,(u16)c); return 0; }


int func_021FC61C(int a, char **pp)
{
    char *p = *pp;
    int x = func_0201134C((struct Cursor *)(((struct Obj14124 *)pp)->f4));

    func_021F96B0(((struct Obj23268 *)p)->f34, x);
    return 0;
}


int func_021FC634(int a, char **pp)
{
    func_021F96C4(((struct Obj23270 *)(*pp))->f34);
    return 0;
}

void func_021FC644(int a, void *b, void *c, int d)
{
    char *p;
    p = func_02030734(4, 0x1ac, 1, d_021FDE5C, 0x14c);
    ((struct Obj05406 *)p)->fC = d;
    ((struct Obj05406 *)p)->f54 = b;
    ((struct Obj05406 *)p)->f58 = func_020120F4(b);
    ((struct Obj05406 *)p)->f50 = c;
    ((struct Obj05406 *)p)->f4 = 0;
    ((struct Obj05406 *)p)->f8 = 0;
    func_020263D8(c, 4, (u32)p);
}

void func_021FC684(char *p) { func_021FCA38(p); func_02026400(*(struct Comm * *)&((struct Obj03291 *)p)->f50); }

void *func_021FC694(int a,char *p)
{
    ((struct Obj06493 *)p)->f5C=func_02012944(((struct Obj06493 *)p)->f58);
    if(((struct Obj06493 *)p)->fC==1) d_021FDE4C[5]=4;
    else {
        d_021FDE4C[5]=0;
        func_0203CBAC((struct Req *)d_021FDDEC,(u32)func_021FCAA0,(u32)p);
    }
    func_02008494(((struct Obj06493 *)p)->f5C,p+0x20);
    func_02087C6C(p+0x40);
    ((struct Obj06493 *)p)->f46=0x3a0b;
    return p;
}

/*
 * 0203D1B4's forwarding matched void declaration loses its live result.
 * 0203D7BC retains the original caller's unused zero argument.
 */
int func_021FC6EC(int *state,u8 *p)
{
 switch(*state) {
 case 0:
  if(func_0203D1B4()<=1) {func_0203CEAC(0);return 1;}
  if(((struct Obj08173 *)p)->fC==1) func_0203A5E4(0x1100);
  if(((struct Obj08173 *)p)->f8==1) {func_0203D7BC(0);func_021FCDEC((int)p,0x41);*state=1;}
  else *state=2;
  break;
 case 1:
  if(func_021FCE00((char *)p,0x41)==1) *state=2;
  if(func_0203D1B4()<=1 || func_0200FB24()!=0) *state=10;
  break;
 case 2:
  if(((struct Obj08173 *)p)->f8==0) {func_0203CEAC(0);return 1;}
  if(func_0203D378()==0) {
   if(func_0203D3A8(func_020399A8(),1,0,0)==1) return 1;
  } else if(func_0203D1B4()<=1) {func_0203CEAC(0);return 1;}
  if(func_0200FB24()!=0) *state=10;
  break;
 case 10:
  if(func_0200FB24()!=0) func_02012124(*(struct Ctx * *)&((struct Obj08173 *)p)->f54,1);
  func_0203CEAC(0);return 1;
 }
 return 0;
}

int func_021FC7DC(int unused,int unused1,void *p) { if(func_0203CDBC()==1) {func_020307B0(p);return 1;} return 0; }

void func_021FC7F8(int unused,int unused1,char *p) { func_021FCAA8(p); }

void func_021FC804(char *p) { if(func_0203D378()==1) ((struct Obj14125 *)p)->f48=1; else ((struct Obj14125 *)p)->f48=2; }

void func_021FC81C(char *p) { func_0203A574(0x1100,(u32)d_021FDC38,9,(u32)p); if(func_0203D378()==1) ((struct Obj14126 *)p)->f48=1; else ((struct Obj14126 *)p)->f48=2; }

static inline void clear8(void *dest,u32 size)
{
 func_02082BCC(dest,0,size);
}

/*
 * 02012F44 returns the live pointer from its forwarding target 020071CC;
 * its matched void prototype discards that result.
 * Lever: row is block-local; the final fill has a per-entry pointer.
 * The SDK MI_CpuClear8 inline spelling restores both fill-call setup orders
 * (direct MI_CpuFill8 leaves 15 bytes; data/size signedness changes are flat).
 */
void func_021FC848(u8 *p,void *a,void *b,int unused,void *d,u16 heap)
{
 void *data;
 u32 size1,size2;
 u8 i,j;
 data=func_02012F44(P(p,0x58));
 ((struct Obj02195 *)p)->f0=heap;
 for(i=0;i<4;i++) {
  u8 *row;
  row=p+i*0x30;
  W(row,0x60)=0;
  row[0x72]=i;
  W(row,0x78)=0;
  W(row,0x64)=0;W(row,0x68)=0;W(row,0x6C)=0;
  row[0x70]=10;row[0x71]=10;
  P(row,0x7C)=func_02030734(((struct Obj02195 *)p)->f0,func_020173EC()+0x7C,0,d_021FDE5C,0x20E);
  size1=func_02008468();
  P(row,0x8C)=func_02030734(((struct Obj02195 *)p)->f0,(size1+4)+func_020173E8(),0,d_021FDE5C,0x20F);
  clear8(P(row,0x7C),func_020173EC()+0x7C);
  size2=func_02008468();
  clear8(P(row,0x8C),(size2+4)+func_020173E8());
  P(row,0x80)=P(row,0x8C);
  P(row,0x84)=P(row,0x8C)+4;
  P(row,0x88)=P(row,0x8C)+4+func_02008468();
  for(j=0;j<2;j++) row[0x73+j]=0xFF;
 }
 ((struct Obj02195 *)p)->f12C=func_0200A81C(data);
 ((struct Obj02195 *)p)->f130=a;((struct Obj02195 *)p)->f134=b;
 W(p,0x138)=0;W(p,0x124)=0;
 P(p,0x128)=func_02030734(((struct Obj02195 *)p)->f0,(func_020173EC()+0x7C)*4,0,d_021FDE5C,0x221);
 size1=func_02008468();
 P(p,0x13C)=func_02030734(((struct Obj02195 *)p)->f0,((size1+4)+func_020173E8())*4,0,d_021FDE5C,0x222);
 p[0x1C]=0;W(p,0x14)=0;W(p,0x18)=0;
 p[0x14C]=0;W(p,0x150)=0;
 W(p,0x158)=0;W(p,0x15C)=0;W(p,0x160)=0;W(p,0x164)=0;
 W(p,0x168)=0;W(p,0x170)=0;W(p,0x174)=0;W(p,0x17C)=0;
 W(p,0x184)=0;W(p,0x188)=0;
 p[0x180]=4;
 W(p,8)=1;
 for(j=0;j<8;j++) {
  u8 *entry=p+j*4;
  W(entry,0x18C)=0xFFFF;
 }
 ((struct Obj02195 *)p)->f140=d;
 W(p,0x4C)=1;
}

void func_021FCA38(char *p)
{
    u8 i;
    char *q;
    for(i=0;i<4;i++) {
        q=p+i*0x30;
        if(((struct Obj10565 *)q)->f7C) {
            func_020307B0(((struct Obj10565 *)q)->f8C);
            func_020307B0(((struct Obj10565 *)q)->f7C);
        }
    }
    if(((struct Obj03291 *)p)->f124) func_020307B0(((struct Obj03291 *)p)->f124);
    if(((struct Obj03291 *)p)->f138) func_020307B0(((struct Obj03291 *)p)->f138);
    if(((struct Obj03291 *)p)->f128) func_020307B0(((struct Obj03291 *)p)->f128);
    if(((struct Obj03291 *)p)->f13C) func_020307B0(((struct Obj03291 *)p)->f13C);
}

void func_021FCAA0(char *p)
{
    ((struct Obj23271 *)p)->f10=1;
}
