/*
 * file:     compatible_irc_sys.c
 * unit:     yes
 * function: func_021B6100, func_021B6148, func_021B6150, func_021B61E8, func_021B6254, func_021B62AC, func_021B62FC, func_021B630C, func_021B63BC, func_021B63C4, func_021B63CC, func_021B63D0, func_021B6424, func_021B6480, func_021B6494, func_021B64B8, func_021B64F0, func_021B6508, func_021B6518, func_021B652C, func_021B6540, func_021B6554, func_021B6568, func_021B657C, func_021B658C, func_021B6634, func_021B6670, func_021B667C, func_021B66A4, func_021B66B8, func_021B66E0, func_021B6760, func_021B678C, func_021B67B0, func_021B67C4, func_021B67E4, func_021B67F8, func_021B685C, func_021B6874, func_021B68A0, func_021B68C0, func_021B68E0, func_021B6920, func_021B6938, func_021B69C4, func_021B69F8, func_021B6A3C, func_021B6A44, func_021B6A4C, func_021B6A60, func_021B6A7C, func_021B6AD8, func_021B6BA8, func_021B6BE4, func_021B6BFC, func_021B6C08, func_021B6C20, func_021B6CA0, func_021B6D04, func_021B6D5C, func_021B6D90, func_021B6DAC, func_021B6E84, func_021B6E8C, func_021B6EBC, func_021B6ECC, func_021B6F9C, func_021B7090, func_021B70A8
 * address:  0x021B6100
 * region:   ov101
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
 *   func_02082BCC 0x02082BCC arm
 *   d_021B7524 0x021B7524 data a1
 *   func_0203CD98 0x0203CD98 arm
 *   func_0203CBAC 0x0203CBAC arm
 *   d_021B743C 0x021B743C data a4
 *   func_0203CEAC  0x0203CEAC  arm
 *   func_0203D0DC 0x0203D0DC arm
 *   func_020399A8 0x020399A8 arm
 *   func_02039C68 0x02039C68 arm
 *   func_02039CB4 0x02039CB4 arm
 *   func_0203D378 0x0203D378 arm
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_02039468 0x02039468 arm
 *   func_0203D3A8 0x0203D3A8 arm
 *   func_0203D3F8 0x0203D3F8 arm
 *   func_0203A574 0x0203A574 arm
 *   func_0203A5E4 0x0203A5E4 arm
 *   func_02087C88 0x02087C88 arm
 *   func_020120F4 0x020120F4 thumb
 *   func_02012944 0x02012944 thumb
 *   func_02008494 0x02008494 thumb
 *   func_02012934 0x02012934 thumb
 *   func_0201AB28 0x0201AB28 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   func_0203F4E4 0x0203F4E4 arm
 *   func_02080D24 0x02080D24 arm
 *   func_02082D44 0x02082D44 arm
 *   func_02039338 0x02039338 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02012950 0x02012950 thumb
 *   func_02008468 0x02008468 thumb
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02005DE4 0x02005DE4 thumb
 *   func_02005E64 0x02005E64 thumb
 *   d_021B753C 0x021B753C data a1
 *   func_02005E9C 0x02005E9C thumb
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02005E50 0x02005E50 thumb
 *   func_02031324 0x02031324 arm
 *   func_0203133C 0x0203133C arm
 *   d_021B74B8 0x021B74B8 data a4
 *   func_02031348 0x02031348 arm
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200A8A0 0x0200A8A0 thumb
 *   func_02008530 0x02008530 thumb
 *   func_0200A9D4 0x0200A9D4 thumb
 *   _u32_div_f 0x0209C2B0 arm
 *   func_020084F4 0x020084F4 thumb
 *   _ffltu 0x0209BE04 arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   func_02045A98 0x02045A98 arm
 *   func_0200AA00 0x0200AA00 thumb
 */
#include "../../matched/include/Obj06362.h"
#include "../../matched/include/Obj22090.h"
#include "../../matched/include/Obj22091.h"
#include "../../matched/include/Obj22092.h"
#include "../../matched/include/Obj22093.h"
#include "../../matched/include/Obj22094.h"
#include "../../matched/include/Obj22095.h"
#include "../../matched/include/Obj22096.h"
#include "../../matched/include/Obj22097.h"
#include "../../matched/include/Obj04420.h"
#include "../../matched/include/Obj22106.h"
#include "../../matched/include/Obj22107.h"
#include "../../matched/include/Obj22108.h"
#include "../../matched/include/Obj13716.h"
#include "../../matched/include/Obj04421.h"
#include "../../matched/include/Obj13717.h"
#include "../../matched/include/Obj13718.h"
#include "../../matched/include/Obj22109.h"
#include "../../matched/include/Obj22111.h"
#include "../../matched/include/Obj02808.h"
#include "../../matched/include/Obj22112.h"
#include "../../matched/include/Obj22113.h"
#include "../../matched/include/Obj22114.h"
#include "../../matched/include/Obj05268.h"
#include "../../matched/include/Obj22115.h"
#include "../../matched/include/Obj22116.h"
#include "../../matched/include/Obj07969.h"
#include "../../matched/include/Obj07970.h"
#include "../../matched/include/Obj10226.h"
#include "../../matched/include/Obj10227.h"
#include "../../matched/include/Obj10228.h"
#include "../../matched/include/Obj10229.h"
#include "../../matched/include/Obj10230.h"
#include "../../matched/include/Obj10231.h"
#include "../../matched/include/Obj01387.h"
#include "../../matched/include/Obj07971.h"
#include "../../matched/include/Obj22124.h"
#include "../../matched/include/Obj22125.h"
#include "../../matched/include/Obj22127.h"

struct Req;
struct Entry;
struct Link;
struct OSOwnerInfo;
struct RtcDate;
struct BigObj;
struct Ctx;
struct Data;
struct Rec44;
struct Sub24;
struct Obj0203159C;
struct S020315D4;
struct S020314B8;
struct Big;
struct T0200A9A4;
struct Sub0200852CObj;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef short s16;

typedef signed char s8;

typedef int s32;

struct Config { int words[26]; int context; int tail; };

struct Obj_021B6150 { int first; int data[15]; int context; unsigned state; int rest[11]; int ready; int done; int spare[3]; u16 heap; };

typedef struct Obj_021B61E8 {
    int f00;
    unsigned char sub[0x40];
    int state;
    unsigned char pad48[0xC];
    int done;
    unsigned char pad58[0x1C];
    int pending;
    int busy;
} Obj_021B61E8;

typedef struct Obj_021B63D0 { unsigned char pad[0x78]; int busy; unsigned char pad7c[6]; u16 counter; } Obj_021B63D0;

typedef struct R { int words[11]; } R;

typedef struct Data { u32 f00; u8 f04,f05; u16 f06; u8 f08,f09,f0a; unsigned char low:4; unsigned char high:4; u8 tail[32]; } Data;

typedef struct Config_021B652C { u8 bytes[0x54]; } Config_021B652C;

typedef struct Four { int a,b,c,d; } Four;

typedef struct Row { int a,b; int (*create)(int,int); void (*destroy)(int,int); } Row;

struct Date { unsigned a,b,c,d; };

extern void *func_02030734(u32,u32,int,const char *,u16);
extern void func_02082BCC(void *,int,u32);
extern u32 func_020307B0(void *p);
extern int func_0203CD98(void);
extern void func_0203CBAC(struct Req *req, u32 a2, u32 a3);
extern int func_0203CEAC(int a0);
extern int func_0203D0DC(int);
extern struct Entry *func_020399A8(void);
extern void func_02039C68(struct Link *,unsigned int,unsigned int);
extern unsigned int func_02039CB4(struct Link *,unsigned int,unsigned int);
extern u32 func_0203D378(void);
extern u32 func_0203D1A4(struct Link *p);
extern int func_02039468(u32,u32);
extern int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
extern u32 func_0203D3F8(u32,u32,u32,u32,u32,u32,u32,u32);
extern void func_0203A574(u32,u32,u32,u32);
extern void func_0203A5E4(u32);
extern void func_02087C88(struct OSOwnerInfo *info);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012944(void *p);
extern void func_02008494(void *,void *);
extern void *func_02012934(const struct BigObj *p);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void func_0203F4E4(struct RtcDate *date);
extern u32 func_02080D24(u32);
extern void func_02082D44(void *,const void *,unsigned);
extern unsigned short func_02039338(void);
extern struct Rec44 *func_02012950(struct Sub24 *p, u32 i);
extern int func_02008468(void);
extern void func_0203064C(u32,u32,u32);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02005DE4(void *p);
extern int func_02005E64(void);
extern int func_02005E9C(void);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(u32 heap);
extern int func_02005E50(void);
extern void *func_02031324(int);
extern unsigned int func_02031330(void *);
extern void func_0203133C(struct S020314B8 *p);
extern void func_02031348(int,int,int,int);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200A8A0(void *);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern int func_0200A9D4(struct T0200A9A4 *o, u32 v);
extern u16 *func_020084F4(void *);
extern u16 func_02045A98(void);
extern unsigned char func_0200AA00(unsigned,unsigned,struct Date *);
void *func_021B6100(int a,int b,int c,int d);
void func_021B6148(void *a0);
int func_021B6150(struct Obj_021B6150 *p);
int func_021B61E8(Obj_021B61E8 *o);
int func_021B6254(int *p);
int func_021B62AC(int *p);
int func_021B62FC(int *p);
int func_021B630C(int *p,int value);
void func_021B63BC(int *p);
void func_021B63C4(int *p);
void func_021B63CC(int *p,int n);
int func_021B63D0(Obj_021B63D0 *p);
int func_021B6424(int p);
int func_021B6480(int *p);
int func_021B6494(u32 p,u32 a,u32 b,u32 c);
u32 func_021B64B8(u32 p,u32 a,u32 b,u32 c,u8 d,u32 e,u32 f,u32 g);
void func_021B64F0(u32 p,u32 a,u32 b,u32 c,u32 d);
void func_021B6508(u32 p,u32 a);
int func_021B6518(u32 p,u32 a,u32 b);
int func_021B652C(u32 p);
int func_021B6540(u32 p);
int func_021B6554(int *p);
int func_021B6568(int *p,int resource);
void func_021B657C(int *p,R *out);
void func_021B658C(void *p,Data *out);
void func_021B6634(u32 *p, int i);
int func_021B6650(void);
int func_021B6658(void);
int func_021B665C(int a, int b);
void func_021B6668(int *p);
void func_021B6670(void);
void func_021B6674(int *p);
void func_021B667C(unsigned a,int b,void *c,unsigned char *d);
void func_021B66A4(int a,int b,int c,int *d,unsigned e);
void func_021B66B8(unsigned a,int b,void *c,unsigned char *d,unsigned e);
void func_021B66E0(int a, int b, int c);
void func_021B6760(int *p);
int func_021B678C(int *p,int a,int b);
int func_021B67B0(int *p);
int func_021B67C4(int *p);
int func_021B67E4(int *p);
int func_021B67F8(int *p,int resource);
void func_021B685C(int *p,R *out);
void func_021B6874(u32 a,int b,void *c,u8 *d,void *e);
void func_021B68A0(u32 a,int b,int c,u8 *d,void *e);
void func_021B68C0(u32 a,int b,int c,u8 *d,void *e);
void func_021B68E0(u32 a, int b, int c, int *d, u32 e);
u32 func_021B6920(u32 a,u8 *p);
int func_021B6938(struct Obj0203159C *a,int b,int c);
int func_021B69C4(int a,int b,int c,u8 *d);
int func_021B69F8(void *task, u32 *state, void *unused, u8 *p);
void func_021B6A3C(u8 *p, u32 v);
void func_021B6A44(u8 *p);
void func_021B6A4C(u8 *p,u16 *state);
void func_021B6A60(u8 *p,u16 *state);
void func_021B6A7C(u8 *p,u16 *state);
void func_021B6AD8(u8 *p,u16 *state);
void func_021B6BA8(u8 *p,u16 *state);
void func_021B6BE4(u8 *p,int heap);
unsigned int func_021B6BFC(u8 *p);
void func_021B6C08(u8 *p);
int func_021B6C20(int *p,int index,int heap,int arg);
int func_021B6CA0(unsigned a,int *p);
void func_021B6CF8(int p,int q);
int func_021B6D04(unsigned a,int p);
void func_021B6D3C(int p,int q);
int func_021B6D5C(unsigned a,int p);
void func_021B6D90(int p,int q);
void *func_021B6DAC(u32 heap,char *p);
void func_021B6E84(void *p);
void *func_021B6E8C(u32 heap,u8 *p);
void func_021B6EBC(void *q,u8 *p);
int func_021B6ECC(u32 a, u32 b, int c, int d, char *x, char *y, int flag, u32 id, int a8);
u32 func_021B6F9C(u16 *p, u16 *q);
unsigned func_021B7090(unsigned bits, unsigned n);
unsigned char func_021B70A8(unsigned char *p,unsigned x);
extern const char d_021B7524[];
extern const struct Config d_021B743C;
extern const char d_021B753C[];
extern const Row d_021B74B8[];




void *func_021B6100(int a,int b,int c,int d) {
 char *p;
 p=func_02030734(c,0x8c,0,d_021B7524,0x113);
 func_02082BCC((void *)p,0,0x8c);
 ((struct Obj06362 *)p)->f40=a;
 ((struct Obj06362 *)p)->f88=c;
 ((struct Obj06362 *)p)->f74=0;
 ((struct Obj06362 *)p)->f78=d;
 ((struct Obj06362 *)p)->f0=b;
 return p;
}




void func_021B6148(void *a0) { func_020307B0(a0); }




int func_021B6150(struct Obj_021B6150 *p) {
 struct Config config;
 if(p->done!=0) return 1;
 switch(p->state) {
 case 0:
  if(func_0203CD98()!=0) { p->state=2; }
  else {
   config=d_021B743C;
   config.context=p->context;
   func_0203CBAC((struct Req *)(&config),(u32)func_021B6670,(int)p);
  }
  p->state=1;
  break;
 case 1:
  if(func_0203CD98()!=0) p->state=2;
  break;
 case 2:
  func_021B66E0((int)p+4,(int)p,p->heap);
  p->ready=1;
  p->state=3;
  break;
 case 3:
  p->state=0;
  return 1;
 }
 return 0;
}





int func_021B61E8(Obj_021B61E8 *o)
{
    if (o->busy != 0)
        return 1;
    switch (o->state) {
    case 0:
        if (o->pending != 0) {
            func_021B6760((int *)o->sub);
            o->pending = 0;
        }
        o->done = 0;
        o->state = 1;
        break;
    case 1:
        if (func_0203CEAC((int)func_021B6674) != 0)
            o->state = 2;
        else
            o->state = 3;
        break;
    case 2:
        if (o->done != 0)
            o->state = 3;
        break;
    case 3:
        o->state = 0;
        return 1;
    }
    return 0;
}




int func_021B6254(int *p)
{
    if (p[30] != 0) return 1;
    switch(p[17]) {
    case 0:
        func_0203D0DC(0);
        p[17] = 1;
        p[33] = 1;
        p[20] = 0;
        p[19] = 0;
        break;
    case 1:
        if(p[20] != 0) {
            p[33] = 0;
            p[17] = 2;
        }
        break;
    case 2:
        p[17] = 0;
        return 1;
    }
    return 0;
}




int func_021B62AC(int *p)
{
    if(p[30]) return 1;
    switch(p[17]) {
    case 0:
        func_02039C68((struct Link *)func_020399A8(),14,13);
        p[17]=1;
        break;
    case 1:
        if(func_02039CB4((struct Link *)func_020399A8(),14,13)) p[17]=2;
        break;
    case 2:
        p[17]=0;
        return 1;
    }
    return 0;
}




int func_021B62FC(int *p) { if(p[30]) return 1; return p[20]; }




int func_021B630C(int *p,int value)
{
    int i;
    if(p[30]) return 1;
    switch(p[17]) {
    case 0:
        p[28]=0;
        if(func_021B6494((unsigned int)p,0xD00,4,(unsigned int)(&value))) p[17]=1;
        break;
    case 1:
        if(func_0203D378()) {
            for(i=0;i<2;i++) { if(value != p[26+i]) break; }
            if(i == 2) p[17]=2;
        } else p[17]=3;
        break;
    case 2:
        if(func_021B6494((unsigned int)p,0xD01,4,(unsigned int)(&value))) p[17]=4;
        break;
    case 3:
        if(p[28]) p[17]=4;
        break;
    case 4:
        p[17]=0;
        return 1;
    }
    return 0;
}




void func_021B63BC(int *p) { p[17]=0; }




void func_021B63C4(int *p) { p[15]=0; p[14]=0; }




void func_021B63CC(int *p,int n) { p[14]=n; }




int func_021B63D0(Obj_021B63D0 *p)
{
    u16 old;
    if (p->busy) return 1;
    old = p->counter;
    p->counter += 1;
    if (old > 180) {
        p->counter = 0;
        if (!func_02039468(0xD02,func_0203D1A4((void *)func_020399A8())))
            return func_021B6424((int)p);
    }
    return 0;
}




int func_021B6424(int p)
{
    unsigned int id;
    u8 other;
    if(((struct Obj22090 *)p)->f78) return 1;
    id=func_0203D1A4((void *)func_020399A8());
    other=(id == 0);
    if(func_02039468(0xD02,id) == 0) {
        return func_021B64B8(p,0xD02,4,p+0x38,other,0,0,1);
    } else {
        return 0;
    }
}




int func_021B6480(int *p) { if(p[30]) return 0; return p[14]-p[15]; }




/*
 * note: trailing two zero alignment bytes. Extern b/c widened because
 *       caller forwards full words without callee's u16 truncation pairs.
 */
int func_021B6494(u32 p,u32 a,u32 b,u32 c) {
    if(((struct Obj22091 *)p)->f78!=0) return 1;
    return func_0203D3A8((struct Entry *)func_020399A8(),a,b,c);
}




u32 func_021B64B8(u32 p,u32 a,u32 b,u32 c,u8 d,u32 e,u32 f,u32 g) {
    if(((struct Obj22092 *)p)->f78!=0) return 1;
    return func_0203D3F8((u32)func_020399A8(),d,a,b,c,e,f,g);
}




/*
 * note: trailing two zero alignment bytes.
 */
void func_021B64F0(u32 p,u32 a,u32 b,u32 c,u32 d) {
    if(((struct Obj22093 *)p)->f78==0) func_0203A574(a,b,c,d);
}




void func_021B6508(u32 p,u32 a) {
    if(((struct Obj22094 *)p)->f78==0) func_0203A5E4(a);
}




int func_021B6518(u32 p,u32 a,u32 b) {
    if(((struct Obj22095 *)p)->f78!=0) return 1;
    return func_021B678C((int *)(p+4),a,b);
}













int func_021B652C(u32 p) {
    if(((struct Obj22096 *)p)->f78!=0) return 1;
    return func_021B67B0((int *)(p+4));
}













int func_021B6540(u32 p) {
    if(((struct Obj22097 *)p)->f78!=0) return 1;
    return func_021B67C4((int *)(p+4));
}













int func_021B6554(int *p) { if(p[30]) return 1; return func_021B67E4(p+1); }













int func_021B6568(int *p,int resource) { if(p[30]) return 1; return func_021B67F8(p+1,resource); }













void func_021B657C(int *p,R *out) { if(!p[30]) func_021B685C(p+1,out); }













/*
 * lever: pack the words with unsigned left/right shift pairs; u8 casts
 *   keep separate truncation shifts and add eight bytes.
 */
void func_021B658C(void *p,Data *out)
{
    Config_021B652C config;
    Four four;
    void *sub;
    void *record;
    int flag;
    func_02087C88((struct OSOwnerInfo *)(&config));
    sub=func_020120F4(p);
    p=func_02012944(sub);
    out->f04=config.bytes[2];
    out->f05=config.bytes[3];
    func_02008494(p,out->tail);
    record=func_0201AB28(func_02012934(sub),0);
    flag=0;
    out->f06=func_02017E1C(record,5,0);
    out->f08=func_02017E1C(record,111,0);
    out->f09=func_02017E1C(record,110,0);
    out->f0a=func_02017E1C(record,76,0);
    func_0203F4E4((struct RtcDate *)(&four));
    if(four.c == 14) flag=1;
    out->low=(u8)flag;
    out->f00=((u32)four.a << 24) | (((u32)four.b << 24) >> 8) | (((u32)four.c << 24) >> 16) | four.d;
}













void func_021B6634(u32 *p, int i)
{
    p[19] |= 1 << i;
    if (func_02080D24(p[19]) >= 2)
        p[20] = 1;
}













int func_021B6650(void) { return 0x021B7520; }













int func_021B6658(void) { return 4; }













int func_021B665C(int a, int b) { return a == b ? 1 : 0; }













void func_021B6668(int *p) { p[20] = 0; }













void func_021B6670(void) { }













void func_021B6674(int *p) { p[21] = 1; }













void func_021B667C(unsigned a,int b,void *c,unsigned char *d) { unsigned v; if(func_0203D378()) { func_02082D44(c,&v,4); *(unsigned *)(d+0x68+a*4)=v; } }













void func_021B66A4(int a,int b,int c,int *d,unsigned e) { if(e==(unsigned)func_020399A8()) d[28]=1; }













void func_021B66B8(unsigned a,int b,void *c,unsigned char *d,unsigned e) { if(e==(unsigned)func_020399A8()) { if(a!=func_02039338()) func_02082D44(c,d+0x3c,4); } }












void func_021B66E0(int a, int b, int c)
{
    int r7;

    func_02082BCC((void *)a, 0, 0x34);
    r7 = 0x57b;
    ((struct Obj04420 *)a)->f0 = b;
    ((struct Obj04420 *)a)->f28 = (int)func_02030734(c, 0x2c, 0, (const char *)0x021B7524, r7);
    func_02082BCC((void *)((struct Obj04420 *)a)->f28, 0, 0x2c);
    ((struct Obj04420 *)a)->f2C = (int)func_02030734(c, 0x2c, 0, (const char *)0x021B7524, r7 + 2);
    func_02082BCC((void *)((struct Obj04420 *)a)->f2C, 0, 0x2c);
    ((struct Obj04420 *)a)->f30 = (int)func_02030734(c, 0x2c, 0, (const char *)0x021B7524, r7 + 4);
    func_02082BCC((void *)((struct Obj04420 *)a)->f30, 0, 0x2c);
    func_021B64F0(b, 0x1000, 0x021B741C, 4, a);
}










void func_021B6760(int *p) { func_021B6508((u32)((int *)p[0]),0x1000); func_020307B0((void *)p[10]); func_020307B0((void *)p[11]); func_020307B0((void *)p[12]); func_02082BCC(p, 0, 0x34); }










int func_021B678C(int *p,int a,int b) { p[5]=a; p[4]=b; return func_021B6494((u32)((int *)p[0]),0x1000,8,(u32)(p+4))!=0; }










int func_021B67B0(int *p) { if(p[6]==1) { p[6]=0; return 1; } return 0; }










int func_021B67C4(int *p) { int value; return func_021B6494((u32)((int *)p[0]),0x1001,4,(u32)(&value))!=0; }










int func_021B67E4(int *p) { if(p[7]==1) { p[7]=0; return 1; } return 0; }









int func_021B67F8(int *p,int resource)
{
    switch(p[1]) {
    case 0:
        if(resource) func_021B658C((void *)resource, (Data *)((struct Data *)p[10])); else return 1;
        if(func_021B64B8(p[0],0x1003,44,p[10],255,0,0,1)) p[1]=1;
        break;
    case 1:
        if(p[9]) { p[9]=0; p[1]=0; return 1; }
        break;
    }
    return 0;
}









void func_021B685C(int *p,R *out) { *out=*(R *)p[12]; }









void func_021B6874(u32 a,int b,void *c,u8 *d,void *e) {
 if(e==func_020399A8()) { if(a!=func_02039338()) { func_02082D44(c,d+8,8); ((struct Obj22106 *)d)->f18=1; } }
}









void func_021B68A0(u32 a,int b,int c,u8 *d,void *e) {
 if(e==func_020399A8()) { if(a!=func_02039338()) ((struct Obj22107 *)d)->f1C=1; }
}









void func_021B68C0(u32 a,int b,int c,u8 *d,void *e) {
 if(e==func_020399A8()) { if(a!=func_02039338()) ((struct Obj22108 *)d)->f20=1; }
}









void func_021B68E0(u32 a, int b, int c, int *d, u32 e)
{
    void *p;
    if (*(int *)d[0] != 0) {
        p = func_02012950((void *)*(int *)d[0], a);
        func_02082D44((void *)(c + 12), p, func_02008468());
    }
    if (e == (u32)func_020399A8()) {
        if (a != func_02039338())
            d[9] = 1;
    }
}









u32 func_021B6920(u32 a,u8 *p) {
 if(a==func_02039338()) return ((struct Obj13716 *)p)->f2C;
 return ((struct Obj13716 *)p)->f30;
}









int func_021B6938(struct Obj0203159C *a,int b,int c)
{
    u8 *p;
    int handle;
    func_0203064C(1,58,0x8000);
    p=func_0203159C(a,64,58);
    func_02082BCC(p, 0, 64);
    handle=0;
    ((struct Obj04421 *)p)->f10=c;
    ((struct Obj04421 *)p)->f3C=func_02030734(58,44,0,d_021B753C,0x119);
    func_02082BCC((void *)(((struct Obj04421 *)p)->f3C), 0, 44);
    func_021B6BE4(p+4,58);
    if(*(int *)((struct Obj04421 *)p)->f10) handle=(int)func_020120F4((const struct Ctx *)(*(int *)((struct Obj04421 *)p)->f10));
    ((struct Obj04421 *)p)->f0=func_021B6100(-1,handle,58,0);
    ((struct Obj04421 *)p)->f34=1;
    func_021B6A3C(p,(u32)func_021B6A4C);
    func_02005DE4((void *)1);
    func_02005E64();
    return 1;
}









int func_021B69C4(int a,int b,int c,u8 *d) {
 func_02005E9C(); func_02005DE4(0); func_021B6148(((struct Obj13717 *)d)->f0); func_021B6C08(d+4); func_020307B0(((struct Obj13717 *)d)->f3C); func_020315D4((void *)a); func_020306F0(58); return 1;
}









int func_021B69F8(void *task, u32 *state, void *unused, u8 *p) {
    switch (*state) {
    case 0:
        if (!func_02005E50()) *state += 1;
        break;
    case 1:
        if (func_021B6BFC(p + 4) == 0)
            (*(void (**)(u8 *, u8 *))(p + 20))(p, p + 24);
        if (*(u32 *)(p + 28)) return 1;
        break;
    }
    return 0;
}










void func_021B6A3C(u8 *p, u32 v) { ((struct Obj13718 *)p)->f14 = v; ((struct Obj13718 *)p)->f18 = 0; }










void func_021B6A44(u8 *p) { ((struct Obj22109 *)p)->f1C = 1; }









void func_021B6A4C(u8 *p,u16 *state) { if(*state==0) func_021B6A3C(p,(u32)func_021B6A7C); }









void func_021B6A60(u8 *p,u16 *state) { switch(*state) { case 0: *state=1; break; case 1: func_021B6A44(p); break; } }









void func_021B6A7C(u8 *p,u16 *state)
{
    switch(*state) {
    case 0:
        if(func_021B6C20((int *)(p+4),0,58,(int)p)) *state=1;
        break;
    case 1:
        switch(((struct Obj22111 *)p)->f20) {
        case 0: func_021B6A3C(p,(u32)func_021B6AD8); break;
        case 1: func_021B6A3C(p,(u32)func_021B6BA8); break;
        case 2: func_021B6A3C(p,(u32)func_021B6A60); break;
        }
        break;
    }
}








void func_021B6AD8(u8 *p,u16 *state)
{
    switch(*state) {
    case 0:
        p[0x2e]=0;
        p[0x2c]=0;
        *state=1;
        break;
    case 1:
        if(func_021B6C20((int *)(p+4),2,0x3a,(int)p)) *state=2;
        break;
    case 2:
        if(((struct Obj02808 *)p)->f28==0) *state=3;
        else if(((struct Obj02808 *)p)->f28==2) {
            p[0x2e]=0;
            p[0x2c]=0;
            *state=5;
        } else *state=6;
        break;
    case 3:
        if(func_021B6C20((int *)(p+4),1,0x3a,(int)p)) *state=4;
        break;
    case 4:
        if(((struct Obj02808 *)p)->f24==0) *state=5;
        else if(((struct Obj02808 *)p)->f24==2) {
            p[0x2e]=0;
            p[0x2c]=0;
            *state=5;
        } else *state=6;
        break;
    case 5:
        if(func_021B6C20((int *)(p+4),3,0x3a,(int)p)) *state=6;
        break;
    case 6:
        func_021B6A3C(p,(u32)func_021B6A7C);
        break;
    }
}








void func_021B6BA8(u8 *p,u16 *state) { switch(*state) { case 0: *state=1; break; case 1: if(func_021B6C20((int *)(p+4),4,58,(int)p)) *state=2; break; case 2: func_021B6A3C(p,(u32)func_021B6A7C); break; } }








void func_021B6BE4(u8 *p,int heap) { func_02082BCC(p, 0, 12); ((struct Obj22112 *)p)->f0=func_02031324(heap); }








unsigned int func_021B6BFC(u8 *p) { return func_02031330((void *)((struct Obj22113 *)p)->f0); }







void func_021B6C08(u8 *p) { func_0203133C(((struct Obj22114 *)p)->f0); func_02082BCC(p, 0, 12); }







int func_021B6C20(int *p,int index,int heap,int arg)
{
    int result;
    switch(p[1]) {
    case 0:
        if(d_021B74B8[index].create) result=d_021B74B8[index].create(heap,arg);
        else result=0;
        p[2]=result;
        p[1]=1;
        break;
    case 1:
        func_02031348(p[0],d_021B74B8[index].a,d_021B74B8[index].b,p[2]);
        p[1]=2;
        break;
    case 2:
        if(d_021B74B8[index].destroy) d_021B74B8[index].destroy(p[2],arg);
        p[1]=3;
        break;
    case 3:
        p[1]=0;
        return 1;
    }
    return 0;
}






/*
 * func_02030734 0x02030734 arm
 * func_020307B0 0x020307B0 arm
 * func_02082BCC 0x02082BCC arm
 * d_021B753C 0x021B753C data a1
 */
int func_021B6CA0(unsigned a,int *p) {
 int q;
 q=(int)func_02030734(a,0x14,0,d_021B753C,0x36e);
 func_02082BCC((void *)q,0,0x14);
 ((struct Obj05268 *)q)->f0=*(int *)p[4];
 ((struct Obj05268 *)q)->f4=p[0];
 ((struct Obj05268 *)q)->f10=p[15];
 if(p[13]==1) {
  ((struct Obj05268 *)q)->f8=0;
  p[13]=0;
 } else {
  if(p[14]!=0) {
   p[14]=0;
   ((struct Obj05268 *)q)->f8=2;
  } else ((struct Obj05268 *)q)->f8=1;
 }
 return q;
}






void func_021B6CF8(int p,int q) {
 ((struct Obj22116 *)q)->f20=((struct Obj22115 *)p)->fC;
 func_020307B0((void *)p);
}






int func_021B6D04(unsigned a,int p) {
 int q;
 q=(int)func_02030734(a,0x14,0,d_021B753C,0x3af);
 func_02082BCC((void *)q,0,0x14);
 ((struct Obj10227 *)q)->f0=**(int * *)&((struct Obj10226 *)p)->f10;
 ((struct Obj10227 *)q)->f4=((struct Obj10226 *)p)->f0;
 ((struct Obj10227 *)q)->f8=((struct Obj10226 *)p)->f3C;
 return q;
}






void func_021B6D3C(int p,int q) {
 ((struct Obj07970 *)q)->f24=((struct Obj07969 *)p)->fC;
 ((struct Obj07970 *)q)->f2E=((struct Obj07969 *)p)->f10;
 ((struct Obj07970 *)q)->f2F=((struct Obj07969 *)p)->f11;
 ((struct Obj07970 *)q)->f30=((struct Obj07969 *)p)->f12;
 func_020307B0((void *)p);
}




int func_021B6D5C(unsigned a,int p) {
 int q;
 q=(int)func_02030734(a,0x18,0,d_021B753C,0x3e4);
 func_02082BCC((void *)q,0,0x18);
 ((struct Obj10229 *)q)->f0=**(int * *)&((struct Obj10228 *)p)->f10;
 ((struct Obj10229 *)q)->f4=((struct Obj10228 *)p)->f0;
 ((struct Obj10229 *)q)->f8=((struct Obj10228 *)p)->f3C;
 return q;
}




void func_021B6D90(int p,int q) {
 ((struct Obj10231 *)q)->f28=((struct Obj10230 *)p)->fC;
 ((struct Obj10231 *)q)->f2C=((struct Obj10230 *)p)->f10;
 ((struct Obj10231 *)q)->f2D=((struct Obj10230 *)p)->f14;
 func_020307B0((void *)p);
}


/*
 * lever: reversed flag/both declarations preserve saved-register allocation.
 * trailing: 6E84..6E8C is Thumb free veneer; odd callback at 74F4 is code-start proof.
 * prototype: 6ECC reads eight arguments, but original caller explicitly supplies ninth 58; preserve it.
 * func_02030734 0x02030734 arm
 * func_020307B0 0x020307B0 arm
 * func_02082BCC 0x02082BCC arm
 * func_020120F4 0x020120F4 thumb
 * func_02012EBC 0x02012EBC thumb
 * func_0200A8A0 0x0200A8A0 thumb
 * func_02008530 0x02008530 thumb
 * func_0200A9D4 0x0200A9D4 thumb
 * func_021B658C 0x021B658C thumb ov101
 * func_0203D378 0x0203D378 arm
 * func_021B6ECC 0x021B6ECC thumb ov101
 * d_021B753C 0x021B753C data a1
 */
void *func_021B6DAC(u32 heap,char *p)
{
    Data data;
    void *token;
    char *out,*name;
    int both,flag=0;
    u32 id;
    out=func_02030734(heap,16,0,d_021B753C,0x418);
    func_02082BCC(out,0,16);
    ((struct Obj07971 *)out)->f0=**(u32 * *)&((struct Obj01387 *)p)->f10;
    ((struct Obj07971 *)out)->f4=((struct Obj01387 *)p)->f0;
    ((struct Obj07971 *)out)->f8=*(u32 *)&((struct Obj01387 *)p)->f3C;
    if(((struct Obj01387 *)p)->f2C && ((struct Obj01387 *)p)->f2E) {
        name=*(char * *)&((struct Obj01387 *)p)->f3C+12;
        func_020120F4(**(void ** *)&((struct Obj01387 *)p)->f10);
        token=func_0200A8A0(func_02012EBC(func_020120F4(**(void ** *)&((struct Obj01387 *)p)->f10)));
        if(func_0200A9D4(token,func_02008530((const struct Sub0200852CObj *)name))==0) flag=1;
        both=0;
        if(((struct Obj01387 *)p)->f30 && flag) both=1;
        func_021B658C(**(void ** *)&((struct Obj01387 *)p)->f10,&data);
        if(func_0203D378()) id=data.f00;
        else id=**(u32 * *)&((struct Obj01387 *)p)->f3C;
        ((struct Obj07971 *)out)->fC=func_021B6ECC(((struct Obj01387 *)p)->f2C,((struct Obj01387 *)p)->f2E,((struct Obj01387 *)p)->f2D,((struct Obj01387 *)p)->f2F,(char *)(&data),((struct Obj01387 *)p)->f3C,both,id,58);
    }
    return out;
}


void func_021B6E84(void *p)
{
    func_020307B0(p);
}



void *func_021B6E8C(u32 heap,u8 *p) { void *q; q=func_02030734(heap,4,0,d_021B753C,0x49b); func_02082BCC(q,0,4); ((struct Obj22125 *)q)->f0=**(u32 * *)&((struct Obj22124 *)p)->f10; return q; }



void func_021B6EBC(void *q,u8 *p) { func_020307B0(q); ((struct Obj22127 *)p)->f38=1; }



int func_021B6ECC(u32 a, u32 b, int c, int d, char *x, char *y, int flag, u32 id, int a8)
{
    int base, rate, result;
    u32 sim;
    u16 *first;
    float f;
    base = ((((u32)func_021B70A8((unsigned char *)x, id) + (u32)func_021B70A8((unsigned char *)y, id)) >> 1) * 10) / 100;
    a = a * 50 / 100;
    b = b * 40 / 100;
    base += a + b;
    first = func_020084F4(x + 12);
    sim = func_021B6F9C(first, func_020084F4(y + 12));
    if (sim) f = 0.5f + (float)(sim << 12);
    else f = (float)(sim << 12) - 0.5f;
    rate = (int)f / 150;
    if (flag) rate = 0xccd;
    else {
        if (rate > 0x1000) rate = 0x1000;
        else if (rate < 0x800) rate = 0x800;
    }
    result = base + (((100 - base) * rate) >> 12) - (d + c);
    if (result > 100) return 100;
    if (result < 0) result = 0;
    return result;
}



/*
 * lever: equal declared before count fixes the two spilled counter slots; literal double assignments reproduce the lower-bound stores.
 * note 2026-10-05 (wave D9r lane 131): removed the 2 dead first assignments
 * (`lower1 = 0x30f4;` before `lower1 = 0x30a1;`; `lower2 = 0x30f4;` before
 * `lower2 = 0x30a1;`). Game code has no line table, so these were stand-ins.
 * The plain single assignment gives EXACT in --lang c99 and --lang c: the
 * output bytes do not change. Older text in this header that asks for the
 * double assignment is superseded.
 */
u32 func_021B6F9C(u16 *p, u16 *q)
{
    u32 a, b, bits1, bits2;
    u32 equal, count, lower1, lower2;
    a = *p;
    b = *q;
    if (a >= 0x30a1 && a <= 0x30f4) a -= 0x60;
    if (b >= 0x30a1 && b <= 0x30f4) b -= 0x60;
    bits1 = func_021B7090(a, 8);
    bits2 = func_021B7090(b, 8);
    count = 0;
    equal = 0;
    lower1 = 0x30a1;
    lower2 = 0x30a1;
    for (;;) {
        if (bits1 == 0) {
            a = *++p;
            if (a == func_02045A98()) break;
            if (a >= lower1 && a <= 0x30f4) a -= 0x60;
            bits1 = func_021B7090(a, 8);
        }
        if (bits2 == 0) {
            b = *++q;
            if (b == func_02045A98()) break;
            if (b >= lower2 && b <= 0x30f4) b -= 0x60;
            bits2 = func_021B7090(b, 8);
        }
        if (bits1 == 0 || bits2 == 0) continue;
        if (((a >> bits1) & 1) == ((b >> bits2) & 1)) ++equal;
        ++count;
        --bits1;
        --bits2;
    }
    return equal * 100 / count;
}



unsigned func_021B7090(unsigned bits, unsigned n) { unsigned i = n - 1; while (i) { if ((bits >> i) & 1) break; i--; } return i; }



unsigned char func_021B70A8(unsigned char *p,unsigned x) { struct Date d; d.a=(unsigned char)(x>>24); d.b=(unsigned char)(x>>16); d.c=(unsigned char)(x>>8); d.d=(unsigned char)x; return func_0200AA00(p[4],p[5],&d); }
