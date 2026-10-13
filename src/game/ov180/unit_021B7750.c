/*
 * file:     unit_021B7750.c
 * unit:     yes
 * function: func_021B7750, func_021B7798, func_021B77C4, func_021B77DC, func_021B7814, func_021B78E0, func_021B79F4, func_021B7C08, func_021B7C78, func_021B7CF0, func_021B7D44, func_021B7D5C, func_021B7D80, func_021B7F0C, func_021B7F30
 * address:  0x021B7750
 * region:   ov180
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049F78 0x02049F78 arm
 *   func_0204ADEC 0x0204ADEC arm
 *   func_020307B0 0x020307B0 arm
 *   func_02049238 0x02049238 arm
 *   d_021B82D4 0x021B82D4 data a4
 *   func_0202570C 0x0202570C thumb
 *   func_020437AC 0x020437AC arm
 *   func_0201C7D0 0x0201C7D0 thumb
 *   func_020257D0 0x020257D0 thumb
 *   func_02043678 0x02043678 arm
 *   func_020255A0 0x020255A0 thumb
 *   func_02043B5C 0x02043B5C arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045808 0x02045808 arm
 *   func_020185F0 0x020185F0 thumb
 *   func_02017DBC 0x02017DBC thumb
 *   func_02017DE4 0x02017DE4 thumb
 *   func_02017E88 0x02017E88 thumb
 *   func_0201EF14 0x0201EF14 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201D304 0x0201D304 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_02025774 0x02025774 thumb
 *   func_0201F02C 0x0201F02C thumb
 *   func_02008534 0x02008534 thumb
 *   func_0200864C 0x0200864C thumb
 *   func_02008650 0x02008650 thumb
 *   func_021B7408 0x021B7408 thumb ov180
 *   func_0202590C 0x0202590C thumb
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_0204ACEC 0x0204ACEC arm
 *   func_021B75A4 0x021B75A4 thumb ov180
 *   func_021B746C 0x021B746C thumb ov180
 *   d_021B81BC 0x021B81BC data a4
 *   d_021B81D4 0x021B81D4 data a4
 *   d_021B81A4 0x021B81A4 data a4
 *   func_021B7604  0x021B7604  thumb  ov180
 *   func_021B756C  0x021B756C  thumb  ov180
 *   func_0204EA38 0x0204EA38 arm
 *   func_020434DC 0x020434DC arm
 *   func_021B73B0 0x021B73B0 thumb ov180
 *   func_0204B034 0x0204B034 arm
 *   func_0204B0F4 0x0204B0F4 arm
 *   func_0204B258 0x0204B258 arm
 *   func_02008550 0x02008550 thumb
 *   func_0202DA04 0x0202DA04 thumb
 *   func_0202DA48 0x0202DA48 thumb
 *   func_0202DA18 0x0202DA18 thumb
 *   func_0202DA6C 0x0202DA6C thumb
 *   d_021B82B4 0x021B82B4 data a4
 *   d_021B8204 0x021B8204 data a4
 *   d_021B81EC 0x021B81EC data a4
 *   d_021B824C 0x021B824C data a4
 *   d_021B8264 0x021B8264 data a4
 *   func_0204B084 0x0204B084 arm
 */
#include "../../matched/include/Obj00547.h"
#include "../../matched/include/Obj01273.h"
#include "../../matched/include/Obj00350.h"
#include "../../matched/include/Obj24494.h"
#include "../../matched/include/Obj24495.h"
#include "../../matched/include/Obj24496.h"
#include "../../matched/include/Obj24497.h"
#include "../../matched/include/Obj14405.h"
#include "../../matched/include/G_021B81EC.h"
#include "../../matched/include/Obj04569.h"

struct Grid;
struct Obj020437AC;
struct Obj;
struct Bmp;
struct Sys;
struct CharBuf;
struct MsgBank;
struct U16Vec;
struct Param;
struct Sav;
struct WordSet;
struct StrObj;
struct Player;
struct PlayTime;
struct Sub0200852CObj;
struct Actor;
struct Bank;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char u8;

typedef short s16_021B7798;

typedef short s16_021B77DC;

typedef signed short s16_021B7814;

typedef struct { void *bmp; s16_021B7814 x,y; u32 f8,fc; u8 f10,f11; u16 f12; u32 f14; } Param;

typedef struct { struct Grid *grid; struct Bmp *bmp; } Holder;

typedef signed short s16_021B78E0;

typedef signed short s16_021B79F4;

typedef signed short   s16_021B7C08;

typedef signed int     s32;

typedef struct { unsigned short a, b; unsigned c; int d, e, f; unsigned short g, h; } S24;

typedef short s16_021B7D5C;

typedef struct { u32 w[8]; } Setup;

typedef short s16_021B7F0C;

extern void *func_020490F4(u32 id, u32 heap);
extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);
extern void func_0204ADEC(int,void *,int);
extern u32 func_020307B0(void *p);
extern void func_02049238(unsigned char *);
extern void func_0202570C(struct Grid *);
extern void func_020437AC(struct Obj020437AC *);
extern void func_0201C7D0(void *,s16_021B77DC,s16_021B77DC,void *,void *,u16);
extern void func_020257D0(struct Obj *);
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u16 heap);
extern struct Grid *func_020255A0(struct Sys *sys, const struct Param *param);
extern void func_02043B5C(struct CharBuf *,u8);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045808(struct U16Vec *);
extern struct Sav *func_020185F0(struct Sav *);
extern u32 func_02017DBC(struct Sav *),func_02017DE4(struct Sav *,u32);
extern u32 func_02017E88(void *,u32,u32);
extern void func_0201EF14(struct WordSet *,u32,void *);
extern void func_0201F250(struct WordSet *,void *,void *);
extern u32 func_0201D304(struct StrObj *,u32,u32);
extern void func_0201EFA4(struct WordSet *,u32,u32,u32,u32,u32);
extern void func_02025774(u8 *,u32);
extern void func_0201F02C(struct WordSet *,u32,void *);
extern u16 func_02008534(const struct Sub0200852CObj *obj);
extern u16 func_0200864C(const struct PlayTime *);
extern u8 func_02008650(const struct PlayTime *);
extern void func_021B7408(u8 *p, int n, signed short *x, signed short *y);
extern void func_0202590C(struct Grid *g, s16_021B7C08 x, s16_021B7C08 y);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204ABF0(void *a, u32 b, u32 c, u32 d, u16 g);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern int func_0204ACEC(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern struct Obj *func_021B75A4(char *p, const char *q);
extern void func_021B746C(int *, int, int);
extern void func_021B7604(int *);
extern void func_021B756C(char *p);
extern u32 func_0204EA38(void);
extern void func_020434DC(u32,u32);
extern void func_021B73B0(char *p);
extern struct Obj *func_0204B034(u8 *a0, u32 a1, u32 heap);
extern void func_0204B0F4(struct Actor *a0, int a1);
extern void func_0204B258(struct Bank *,void *);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern int func_0202DA04(int);
extern u32 func_0202DA48(u32,u32,u32,u32);
extern s32 func_0202DA18(u32 a, u32 b, u32 c, u32 d, u16 e);
extern int func_0202DA6C(int a0, int a1, int a2, unsigned short a3);
extern void func_0204B084(void *);
void func_021B7750(char *p);
void func_021B7798(int *p, int n);
void func_021B77C4(int *p);
void func_021B77DC(u8 *p,int n,void *w,void *s,int x,int y);
void func_021B7814(char *p);
void func_021B78E0(char *p);
void func_021B79F4(char *p);
void func_021B7C08(char *p);
void func_021B7C60(char *p,int index,unsigned value);
void func_021B7C78(char *p);
void func_021B7CF0(char *p);
void func_021B7D44(int *p);
void func_021B7D5C(void *p);
void func_021B7D80(char *p);
void func_021B7F0C(int *p);
void func_021B7F30(void *p);
extern unsigned d_021B82D4[];
extern S24 d_021B81BC, d_021B81D4, d_021B81A4;
extern const Setup d_021B82B4;
extern struct G_021B81EC d_021B81EC;
extern const char d_021B8204[], d_021B824C[], d_021B8264[];

void func_021B7750(char *p) {
    void *out;
    unsigned char *bank;
    void *buffer;
    bank=func_020490F4(216,0x808d);
    buffer=func_02049F78(bank,d_021B82D4[((struct Obj00547 *)p)->f915A],(u32)(&out),141);
    func_0204ADEC(*(int *)&((struct Obj00547 *)p)->f90EC,out,1);
    func_020307B0(buffer);
    func_02049238(bank);
}

void func_021B7798(int *p, int n) { if(*(void **)((u32)p+0x9120+(u32)n*8)) { func_0202570C(*(struct Grid **)((u32)p+0x9120+(u32)n*8)); func_020437AC(*(struct Obj020437AC **)((u32)p+0x9124+(u32)n*8)); *(u32 *)((u32)p+0x9120+(u32)n*8)=0; } }


void func_021B77C4(int *p)
{
    unsigned int i;

    for (i = 0; i < 4; i++)
        func_021B7798(p, i);
}

/*
 * Add the far offset before the index; see the far-offset-before-the-index idiom.
 */
void func_021B77DC(u8 *p,int n,void *w,void *s,int x,int y) { func_0201C7D0(*(void **)((u32)p+0x9124+(u32)n*8),x,y,s,w,0x3c40); func_020257D0(*(struct Obj **)((u32)p+0x9120+(u32)n*8)); }

/*
 * lever: paired Grid/Bmp holder pointer formed before allocation preserves
 *   the destination across the call; direct raw stores were eight bytes short.
 */
void func_021B7814(char *p) {
    Param d;
    struct U16Vec *s;
    Holder *h;
    d.f8=*(u32 *)&((struct Obj00547 *)p)->f90F0; d.fc=0;
    d.f10=4; d.f11=0; d.f12=0xffff; d.f14=0;
    h=(Holder *)(p+0x9120);
    h->bmp=func_02043678(22,2,32,141);
    d.bmp=h->bmp; d.x=-184; d.y=16;
    *(struct Grid * *)&((struct Obj00547 *)p)->f9120=func_020255A0(*(struct Sys * *)&((struct Obj00547 *)p)->f911C,(const struct Param *)(&d));
    func_02043B5C(*(struct CharBuf * *)&((struct Obj00547 *)p)->f9124,0);
    s=func_02045EC0(*(struct MsgBank * *)&((struct Obj00547 *)p)->f9038,0);
    func_021B77DC((u8 *)p,0,((struct Obj00547 *)p)->f9030,s,12,0);
    func_02045808(s);
    h=(Holder *)(p+0x9128);
    h->bmp=func_02043678(22,2,32,141);
    d.bmp=h->bmp; d.x=264; d.y=160;
    *(struct Grid * *)&((struct Obj00547 *)p)->f9128=func_020255A0(*(struct Sys * *)&((struct Obj00547 *)p)->f911C,(const struct Param *)(&d));
}

void func_021B78E0(char *p) {
    struct Sav *mon;
    u32 lock,width;
    struct StrObj *str;
    mon=func_020185F0(*(struct Sav **)((u32)p+((struct Obj01273 *)p)->f915D*4+0x9140));
    lock=func_02017DBC(mon);
    func_02043B5C(*(struct CharBuf * *)&((struct Obj01273 *)p)->f912C,0);
    str=func_02045EC0(*(struct MsgBank * *)&((struct Obj01273 *)p)->f9038,1);
    func_0201EF14(*(struct WordSet * *)&((struct Obj01273 *)p)->f903C,0,mon);
    func_0201F250(*(struct WordSet * *)&((struct Obj01273 *)p)->f903C,((struct Obj01273 *)p)->f9040,str);
    func_021B77DC((u8 *)p,1,((struct Obj01273 *)p)->f9030,*(struct StrObj * *)&((struct Obj01273 *)p)->f9040,8,0);
    func_02045808((struct U16Vec *)str);
    str=func_02045EC0(*(struct MsgBank * *)&((struct Obj01273 *)p)->f9038,2);
    width=func_0201D304(str,*(u32 *)&((struct Obj01273 *)p)->f9030,0);
    func_021B77DC((u8 *)p,1,((struct Obj01273 *)p)->f9030,str,112,0);
    func_02045808((struct U16Vec *)str);
    str=func_02045EC0(*(struct MsgBank * *)&((struct Obj01273 *)p)->f9038,3);
    func_0201EFA4(*(struct WordSet * *)&((struct Obj01273 *)p)->f903C,0,func_02017E88(mon,158,0),3,0,1);
    func_0201F250(*(struct WordSet * *)&((struct Obj01273 *)p)->f903C,((struct Obj01273 *)p)->f9040,str);
    func_021B77DC((u8 *)p,1,((struct Obj01273 *)p)->f9030,*(struct StrObj * *)&((struct Obj01273 *)p)->f9040,width+112,0);
    func_02045808((struct U16Vec *)str);
    func_02017DE4(mon,lock);
}

void func_021B79F4(char *p) {
    Param d;
    Holder *h;
    struct StrObj *str;
    u32 width;
    d.f8=((struct Obj00350 *)p)->f90F0; d.fc=0; d.f10=4; d.f11=0; d.f12=0xffff;
    h=(Holder *)(p+0x9130); d.f14=0;
    h->bmp=func_02043678(32,2,32,141);
    d.bmp=h->bmp; d.x=0; d.y=16;
    *(struct Grid * *)&((struct Obj00350 *)p)->f9130=func_020255A0(*(struct Sys * *)&((struct Obj00350 *)p)->f911C,(const struct Param *)(&d));
    func_02025774(*(u8 **)(p+0x9130),0);
    func_02043B5C(*(struct CharBuf * *)&((struct Obj00350 *)p)->f9134,0);
    str=func_02045EC0(*(struct MsgBank * *)&((struct Obj00350 *)p)->f9038,4);
    width=func_0201D304(str,*(u32 *)&((struct Obj00350 *)p)->f9030,0);
    func_021B77DC((u8 *)p,2,((struct Obj00350 *)p)->f9030,str,(256-width)/2,0);
    func_02045808((struct U16Vec *)str);
    h=(Holder *)(p+0x9138);
    h->bmp=func_02043678(32,2,32,141);
    d.bmp=h->bmp; d.x=0; d.y=160;
    *(struct Grid * *)&((struct Obj00350 *)p)->f9138=func_020255A0(*(struct Sys **)(p+0x911c),(const struct Param *)(&d));
    func_02025774(*(u8 **)(p+0x9138),0);
    func_02043B5C(*(struct CharBuf * *)&((struct Obj00350 *)p)->f913C,0);
    str=func_02045EC0(*(struct MsgBank **)(p+0x9038),5);
    func_0201F02C(*(struct WordSet * *)&((struct Obj00350 *)p)->f903C,0,((struct Obj24494 *)(*(char * *)&((struct Obj00350 *)p)->f0))->f4);
    func_0201F250(*(struct WordSet **)(p+0x903c),((struct Obj00350 *)p)->f9040,str);
    func_021B77DC((u8 *)p,3,((struct Obj00350 *)p)->f9030,*(struct StrObj * *)&((struct Obj00350 *)p)->f9040,8,0);
    func_02045808((struct U16Vec *)str);
    str=func_02045EC0(*(struct MsgBank **)(p+0x9038),6);
    func_0201EFA4(*(struct WordSet **)(p+0x903c),0,func_02008534((const struct Sub0200852CObj *)(*(struct Player * *)&((struct Obj24495 *)(*(char * *)&((struct Obj00350 *)p)->f0))->f4)),5,2,1);
    func_0201F250(*(struct WordSet **)(p+0x903c),((struct Obj00350 *)p)->f9040,str);
    func_021B77DC((u8 *)p,3,((struct Obj00350 *)p)->f9030,*(struct StrObj **)(p+0x9040),92,0);
    func_02045808((struct U16Vec *)str);
    str=func_02045EC0(*(struct MsgBank **)(p+0x9038),7);
    func_0201EFA4(*(struct WordSet **)(p+0x903c),0,func_0200864C(*(struct PlayTime * *)&((struct Obj24496 *)(*(char * *)&((struct Obj00350 *)p)->f0))->f8),3,0,1);
    func_0201EFA4(*(struct WordSet **)(p+0x903c),1,func_02008650(*(struct PlayTime * *)&((struct Obj24497 *)(*(char * *)&((struct Obj00350 *)p)->f0))->f8),2,2,1);
    func_0201F250(*(struct WordSet **)(p+0x903c),((struct Obj00350 *)p)->f9040,str);
    func_021B77DC((u8 *)p,3,((struct Obj00350 *)p)->f9030,*(struct StrObj **)(p+0x9040),200,0);
    func_02045808((struct U16Vec *)str);
}

void func_021B7C08(char *p) {
    short x,y;
    func_021B7408((u8 *)p,2,&x,&y);
    func_0202590C((struct Grid *)(((struct Obj14405 *)p)->f9120),x-176,y-8);
    func_021B7408((u8 *)p,3,&x,&y);
    func_0202590C((struct Grid *)(((struct Obj14405 *)p)->f9128),x,y-8);
}

/*
 * follower: 0x021B7C60 tail-call stub included in this verified unit.
 */
void func_021B7C60(char *p,int index,unsigned value) {
    func_02025774(*(unsigned char **)(p+0x9120+index*8),value);
}

void func_021B7C78(char *p)
{
    void *h = func_020490F4(0xD8, 0x808D);
    ((struct Obj00547 *)p)->f90D4 = (void *)func_0204A6C8(h, 0x18, 0, 0, 0x8D);
    ((struct Obj00547 *)p)->f90EC = (void *)func_0204ABF0(h, 3, 0, 0, 0x8D);
    ((struct Obj00547 *)p)->f9108 = (void *)func_0204AF28(h, 0x1A, 0x20, 0x8D);
    func_02049238(h);
    h = func_020490F4(0x17, 0x808D);
    ((struct Obj00547 *)p)->f90F0 = (void *)func_0204ACEC(h, 5, 0, 0xA0, 0x8D);
    func_02049238(h);
}

void func_021B7CF0(char *p)
{
    func_021B7C78(p);
    func_021B7750(p);
    ((struct Obj00547 *)p)->f9050 = (int)func_021B75A4(p, (const char *)(&d_021B81BC));
    ((struct Obj00547 *)p)->f9054 = (int)func_021B75A4(p, (const char *)(&d_021B81D4));
    ((struct Obj00547 *)p)->f9058 = (int)func_021B75A4(p, (const char *)(&d_021B81A4));
    func_021B746C((int *)p, 4, 0);
    func_021B7814(p);
}


void func_021B7D44(int *p)
{
    func_021B77C4(p);
    func_021B7604(p);
    func_021B756C((char *)p);
}

/*
 * EXACT* tail: two zero alignment bytes after the function.
 */
void func_021B7D5C(void *p) { if(func_0204EA38()==1) func_020434DC(16,0); else func_020434DC(16,1); func_021B73B0(p); }

/*
 *   src/matched/arm9/unit_0204B22C.c defines sub_0204B258 but its function:
 *   line lists only sub_0204B22C. the integrator must add the missing unit entry.
 *   Scratch one --arm, dsi/1.1p1 -O4,p -lang c99: EXACT, 24 bytes, no sites.
 *   Verified C:
 *   typedef unsigned char u8;
 *   typedef unsigned int u32;
 *   struct Bank {
 *       u8 pad00[8]; void *f8; u8 pad0c[2];
 *       u8 source:4; u8 mode:4; u8 pad0f[9];
 *   };
 *   void func_0204B258(struct Bank *bank,void *p) {
 *       bank->f8=p;
 *       bank->source=1;
 *   }
 * arity: caller consumes live r0 after void 75A4/2DA48/2DA18;
 *   B0F4 forwards caller-loaded object and flag to BE38; 2DA04's unused
 *   trailing parameters are neither supplied nor read/forwarded in its body.
 */
void func_021B7D80(char *p) {
    Setup s;
    u8 *h;
    int mode;
    func_021B7C78(p);
    s=d_021B82B4;
    *(struct Actor **)(p+0x9118)=(struct Actor *)func_0204B034((u8 *)&s,2,141);
    func_0204B0F4(*(struct Actor **)(p+0x9118),1);
    func_0204B258(*(struct Bank **)(p+0x9044),*(void **)(p+0x9118));
    *(u32 *)(p+0x9064)=(u32)func_021B75A4(p,d_021B8204);
    *(u32 *)(p+0x9068)=(u32)func_021B75A4(p,((char *)&d_021B81EC));
    func_021B746C((int *)p,7,0); func_021B746C((int *)p,8,0);
    h=func_020490F4(216,0x808d);
    *(int *)(p+0x90e0)=func_0204A6C8(h,25,0,1,141);
    *(u32 *)(p+0x90fc)=func_0204ABF0(h,3,1,0,141);
    *(int *)(p+0x9114)=func_0204AF28(h,27,33,141);
    func_02049238(h);
    mode=1;
    if(!func_02008550((const struct Sub0200852CObj *)(*(struct Player **)(*(char **)p+4)))) mode=0;
    h=(u8 *)func_0202DA04(0x808d);
    *(u32 *)(p+0x90d8)=func_0202DA48((u32)h,mode,0,141);
    *(u32 *)(p+0x90f4)=func_0202DA18((u32)h,mode,0,192,141);
    *(int *)(p+0x910c)=func_0202DA6C(mode,2,0,141);
    *(u32 *)(p+0x90dc)=func_0202DA48((u32)h,mode,1,141);
    *(u32 *)(p+0x90f8)=func_0202DA18((u32)h,mode,1,96,141);
    *(int *)(p+0x9110)=func_0202DA6C(mode,0,1,141);
    func_02049238(h);
    *(u32 *)(p+0x905c)=(u32)func_021B75A4(p,d_021B824C);
    *(u32 *)(p+0x9060)=(u32)func_021B75A4(p,d_021B8264);
    func_021B79F4(p);
}

void func_021B7F0C(int *p) { func_021B77C4(p); func_021B7604(p); func_0204B084(((struct Obj04569 *)p)->f9118); func_021B756C((char *)p); }

void func_021B7F30(void *p) { func_021B73B0(p); }
